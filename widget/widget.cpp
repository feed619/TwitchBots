#include "widget.h"
#include "./ui_widget.h"
void barUpdate(Dialog* dialogBar,int secWait, QString* value) {
    int sec = 0;

    while(!value->size())
    // while(sec<5)
    {
        dialogBar->setBar(sec);
        qDebug() <<"жду";
        if (sec > secWait)
        {
            qDebug() <<"Истекло время ожидания";
            break;
        }
        QThread::sleep(1);
        sec++;
    }
    dialogBar->close();
}


widget::widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::widget)
{
    ui->setupUi(this);

    qlistJsonAcc = new QList<JsonKeyValue*>;
    qlistJsonChannel = new QList<JsonKeyValue*>;
    qlistJsonPaste = new QList<JsonKeyValue*>;

    Data::LoadDataTreeWidget(ui->treeWidgetAcc,qlistJsonAcc,F_ACC);
    Data::LoadDataTreeWidget(ui->treeWidgetChanel,qlistJsonChannel,F_CHANNEL,ui->BoxChannel);
    Data::LoadDataTreeWidget(ui->treeWidgetPaste,qlistJsonPaste,F_PASTE,ui->BoxPaste);
}
widget::~widget()
{
    Data::SaveDataTreeWidget(qlistJsonAcc,F_ACC);
    Data::SaveDataTreeWidget(qlistJsonChannel,F_CHANNEL);
    Data::SaveDataTreeWidget(qlistJsonPaste,F_PASTE);

    delete ui;
}

void widget::on_ButtonClear_clicked()
{
    ui->messageText->clear();
    qDebug() << "поле очищено";

}
void widget::on_ButtonSend_clicked()
{
    api.GetData();
    sleep = ui->spinBoxSleep->text().toInt();
    QString text = ui->messageText->toPlainText();
    // qDebug() << "Вы поставили время ожидания "<< sleep;
    qDebug() << "сообщение "<<text<<" отправлено время ожидания"<<sleep<<"антибот"<<AntiBot;
}
void widget::on_checkBoxAntiBot_clicked()
{
    AntiBot = ui->checkBoxAntiBot->checkState();
    if(AntiBot)
    qDebug() << "вы активировали антибот"<< AntiBot;
    else    qDebug() << "вы диактивировали антибот"<< AntiBot;
}

void widget::on_ButtonAddAcc_clicked()
{
    QString key;
    QString value;

    Dialog dialog("Добавить Аккаунт","Логин","Пороль",this);
    if (dialog.exec() == QDialog::Accepted)
    {
        key = dialog.getTitle();
        value = dialog.getText();
    }
    if(key.size()>0 and value.size()>0)
        if(Data::AddDataTreeWidget(ui->treeWidgetAcc,qlistJsonAcc,key,value))
            QMessageBox::warning(this, "Повторение!", "Такой шаблон есть, выберите другое имя");
}
void widget::onTimeout() {
    int sec=0;
    while(sec<10)
    {
        qDebug() <<"жду";
        if (sec > 70)
        {
            qDebug() <<"Истекло время ожидания";
            break;
        }
        QEventLoop loop;
        QTimer::singleShot(1000, &loop, &QEventLoop::quit);
        loop.exec();
        sec++;
    }

}

void widget::on_ButtonAdd_Channel_clicked()
{
    QString key;
    QString value;

    Dialog dialog("Добавить Канал","Название канала",this);
    if (dialog.exec() == QDialog::Accepted)
    {
        key = dialog.getTitle();
    }
    if(key.size()>0)
    {
        // QThread *workerThread = new QThread;

        // connect(workerThread, &QThread::started, Dialog("Добавить Канал","pokdsf"), &Dialog::doWork);
        // Worker *worker = new Worker;
        // Dialog* dialogBar = new Dialog("Добавить Канал","pokdsf");
        // QThread *workerThread = new QThread;

        // dialogBar->moveToThread(workerThread);
        // connect(workerThread, &QThread::started, dialogBar, &Dialog::doWork);
        // connect(dialogBar, &Dialog::workFinished, workerThread, &QThread::quit);
        // dialogBar->exec();

        // QTimer *timer = new QTimer(this);
        // connect(timer, &QTimer::timeout, this, widget::onTimeout);
        // timer->setSingleShot(true);
        // timer->start();  // Выполнять каждую секунду

        // QString* pvalue;



        QString* pvalue = api.GetChannelID(key);
        Dialog* dialogBar = new Dialog("Добавить Канал",secWait,pvalue);
        std::thread tr(barUpdate, dialogBar,secWait,pvalue);

        dialogBar->exec();
        tr.join();



        // QThread* thread = new QThread();
        //  Dialog* dialogBar = new Dialog("Добавить Канал",pvalue);

        // dialogBar->moveToThread(thread);

        // QObject::connect(thread, &QThread::started, dialogBar, &Dialog::doWork);
        // QObject::connect(thread, &QThread::finished, dialogBar, &QObject::deleteLater);

        // thread->start();

        // dialogBar->exec();

        // dialogBar->show();
        // dialogBar->exec();

        // int sec=0;
        // // while(!pvalue->size())
        // while(sec<5)
        // {
        //     dialogBar->show();
        //     qDebug() <<"жду";
        //     if (sec > 70)
        //     {
        //         qDebug() <<"Истекло время ожидания";
        //         break;
        //     }
        //     QThread::sleep(1);
        //     sec++;
        // }


        if(pvalue->size() and *pvalue!="none")
        {
            if (Data::AddDataTreeWidget(ui->treeWidgetChanel,qlistJsonChannel,key,*pvalue,ui->BoxChannel))
                QMessageBox::warning(this, "Повторение!", "Такой шаблон есть, выберите другое имя");
        }
    }
}
void widget::on_ButtonAddPaste_clicked()
{
    QString key;
    QString value;

    Dialog dialog("Добавить Пасту","Название","Текст пасты",this);
    if (dialog.exec() == QDialog::Accepted)
    {
        key = dialog.getTitle();
        value = dialog.getText();
    }
    if(key.size()>0 and value.size()>0)
        if (Data::AddDataTreeWidget(ui->treeWidgetPaste,qlistJsonPaste,key,value,ui->BoxPaste))
            QMessageBox::warning(this, "Повторение!", "Такой шаблон есть, выберите другое имя");
}


void widget::on_ButtonDeleteAcc_clicked()
{
    QTreeWidgetItem *item = ui->treeWidgetAcc->currentItem();
    if(item)
    {
        Data::DeleteDataTreeWidget(item,qlistJsonAcc);
        qDebug()<< "Удалил ключ "<<item->text(0);
    }
    else qDebug() <<"Выберите что удалить";
}
void widget::on_ButtonDeleteChannel_clicked()
{
    QTreeWidgetItem *item = ui->treeWidgetChanel->currentItem();
    if(item)
    {
        Data::DeleteDataTreeWidget(item,qlistJsonChannel,ui->BoxChannel);
        qDebug()<< "Удалил ключ "<<item->text(0);
    }
    else qDebug() <<"Выберите что удалить";
}
void widget::on_ButtonDeletePaste_clicked()
{
    QTreeWidgetItem *item = ui->treeWidgetPaste->currentItem();
    if(item)
    {
        QString st =  "вы хотите удалить "+item->text(1);
        QMessageBox::warning(this, "Повторение!", st);
        Data::DeleteDataTreeWidget(item,qlistJsonPaste,ui->BoxPaste);
        qDebug()<< "Удалил ключ "<<item->text(0);
    }
    else qDebug() <<"Выберите что удалить";
}

void widget::delay(int milliseconds) {
    QEventLoop loop;
    QTimer::singleShot(milliseconds, &loop, &QEventLoop::quit);
    loop.exec();
}

