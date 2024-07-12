#include "widget.h"
#include "./ui_widget.h"
#include <QFile>
widget::widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::widget)
{
    ui->setupUi(this);
    ui->comboBox->addItem("asd");

    qlistJsonAcc = new QList<JsonKeyValue*>;
    qlistJsonChannel = new QList<JsonKeyValue*>;
    qlistJsonPaste = new QList<JsonKeyValue*>;


}
widget::~widget()
{
    delete ui;
}

void widget::addItems_comboBox()
{
    ui->treeWidgetPaste->selectedItems()[0];
}
void widget::ConnectAllButtons()
{
    connect(ui->ButtonClear, SIGNAL(clicked()),
            this, SLOT(on_ButtonClear_clicked()));

}

void widget::fillAllTree()
{}
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
    AddDataTreeWidget(ui->treeWidgetAcc,qlistJsonAcc,key,value);
}

void widget::on_ButtonAdd_Channel_clicked()
{
    QString key = "golovach";
    QString value = "pastaaasdasda sdasdasd";
    AddDataTreeWidget(ui->treeWidgetChanel,qlistJsonChannel,key,value);
}
void widget::on_ButtonAddPaste_clicked()
{
    QString key = "golovach";
    QString value = "👆Попадаю в модера - получаю пермач. На мужика 👇";
    AddDataTreeWidget(ui->treeWidgetPaste,qlistJsonPaste,key,value);
}


void widget::on_ButtonDeleteAcc_clicked()
{
    QTreeWidgetItem *item = ui->treeWidgetAcc->currentItem();
    if(item)
    {
        DeleteDataTreeWidget(item,qlistJsonAcc);
        qDebug()<< "Удалил ключ "<<item->text(0);
    }
    else qDebug() <<"Выберите что удалить";
}


void widget::on_ButtonDeleteChannel_clicked()
{
    QTreeWidgetItem *item = ui->treeWidgetChanel->currentItem();
    if(item)
    {
        DeleteDataTreeWidget(item,qlistJsonChannel);
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
        DeleteDataTreeWidget(item,qlistJsonPaste);
        qDebug()<< "Удалил ключ "<<item->text(0);
    }
    else qDebug() <<"Выберите что удалить";
}


void widget::LoadDataTreeWidget(QString fileName)
{

}

void widget::AddDataTreeWidget(QTreeWidget* tree,QList<JsonKeyValue*>* qlist,QString key,QString value)
{

    for(JsonKeyValue* json:*qlist)
    {
        qDebug() <<json->getKey();
        if(json->getKey() == key)
        {
            QMessageBox::warning(this, "Повторение!", "Такой шаблон есть, выберите другое имя");
            return;
        }
    }
    qlist->append(new JsonKeyValue(key,value));
    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0,key);
    item->setText(1,value);
    tree->addTopLevelItem(item);
}

void widget::DeleteDataTreeWidget(QTreeWidgetItem *item,QList<JsonKeyValue*>* qlist)
{
    int x =0;
    QList<JsonKeyValue*>::iterator it;
    for (it = qlist->begin(); it != qlist->end(); ++it)
    {
        if((*it)->getKey() == item->text(0))
        {
            qlist->removeAt(x);
            delete item;
            return;
        }
        x++;
    }
}

