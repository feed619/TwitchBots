#include "widget.h"
#include "./ui_widget.h"

widget::widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::widget)
{
    ui->setupUi(this);
    ui->comboBox->addItem("asd");
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
void widget::on_ButtonClear_clicked()
{
    ui->messageText->clear();
    qDebug() << "поле очищено";
    qDebug() <<ui->treeWidgetPaste->currentColumn();
    qDebug() <<ui->treeWidgetPaste->selectedItems();
    qDebug() <<ui->treeWidgetPaste->currentItem();
    qDebug() <<ui->treeWidgetPaste->currentItem();
    qDebug() <<ui->treeWidgetPaste->currentItem();
    qDebug() <<ui->treeWidgetPaste->currentItem();

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
