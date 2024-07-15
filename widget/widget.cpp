#include "widget.h"
#include "./ui_widget.h"

widget::widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::widget)
{
    ui->setupUi(this);
    ui->comboBox->addItem("asd");

    qlistJsonAcc = new QList<JsonKeyValue*>;
    qlistJsonChannel = new QList<JsonKeyValue*>;
    qlistJsonPaste = new QList<JsonKeyValue*>;

    Data::LoadDataTreeWidget(ui->treeWidgetAcc,qlistJsonAcc,F_ACC);
    Data::LoadDataTreeWidget(ui->treeWidgetChanel,qlistJsonChannel,F_CHANNEL);
    Data::LoadDataTreeWidget(ui->treeWidgetPaste,qlistJsonPaste,F_PASTE);
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
    // api_net.GetData();
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
    QString key = "popop";
    QString value = "чтотото";
    if(Data::AddDataTreeWidget(ui->treeWidgetAcc,qlistJsonAcc,key,value))
        QMessageBox::warning(this, "Повторение!", "Такой шаблон есть, выберите другое имя");
}

void widget::on_ButtonAdd_Channel_clicked()
{
    QString key = "golovach";
    QString value = "pastaaasdasda sdasdasd";
    if (Data::AddDataTreeWidget(ui->treeWidgetChanel,qlistJsonChannel,key,value))
        QMessageBox::warning(this, "Повторение!", "Такой шаблон есть, выберите другое имя");
}
void widget::on_ButtonAddPaste_clicked()
{
    QString key = "golovach";
    QString value = "👆Попадаю в модера - получаю пермач. На мужика 👇";
    if (Data::AddDataTreeWidget(ui->treeWidgetPaste,qlistJsonPaste,key,value))
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
        Data::DeleteDataTreeWidget(item,qlistJsonChannel);
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
        Data::DeleteDataTreeWidget(item,qlistJsonPaste);
        qDebug()<< "Удалил ключ "<<item->text(0);
    }
    else qDebug() <<"Выберите что удалить";
}


