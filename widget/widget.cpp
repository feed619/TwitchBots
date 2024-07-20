#include "widget.h"
#include "./ui_widget.h"


void showApp(Dialog* dialogBar)
{
    dialogBar->exec();
}
bool barUpdate(Dialog* dialogBar,int Wait, QJsonObject* asd,QNetworkReply* reply) {
    int sec = 0;

    qDebug() <<*asd;
    while(asd->empty())
    // while(sec<5)
    {
        dialogBar->setBar(sec);
        qDebug() <<"жду" << *asd;
        if (sec > Wait)
        {
            dialogBar->setBar(Wait);
            QThread::sleep(1);
            dialogBar->close();
            return true;
        }
        QThread::sleep(1);
        sec++;
    }

    dialogBar->setBar(Wait);
    QThread::sleep(1);
    dialogBar->close();
    return false;
}


widget::widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::widget)
{
    ui->setupUi(this);
    ui->checkBoxSub->setToolTip("подписаться на канал, если требуется подписка для отправки сообщений");
    ui->checkBoxSplit->setToolTip("разбить сообщения знаком '^'");
    ui->addSybSplit->setToolTip("добавить знак '^'");

    ui->spinBoxSleep->setToolTip("время между сообщениями");
    ui->ButtonSend->setToolTip("отправить сообщения");

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
    api.serverShutdown();
    QThread::sleep(3);

    delete qlistJsonAcc;
    delete qlistJsonChannel;
    delete qlistJsonPaste;

    delete ui;
}

void widget::on_ButtonClear_clicked()
{
    ui->messageText->clear();
}
void widget::on_ButtonSend_clicked()
{
    if(!ui->treeWidgetAcc->topLevelItemCount())
    {
        QMessageBox::warning(this, "Ошибка отправки", "Список акааунтов ПУСТ!");
    }
    else if(!ui->treeWidgetChanel->topLevelItemCount())
    {
        QMessageBox::warning(this, "Ошибка отправки", "Добавьте канал!");
    }
    else if(!ui->messageText->toPlainText().size())
    {
        QMessageBox::warning(this, "Ошибка отправки", "Поле сообщения ПУСТ!");
    }
    else if(ui->messageText->toPlainText().size() > 500)
    {
        QMessageBox::warning(this, "Ошибка отправки", "Сообщение превышает 500 символов!");
    }
    else
    {
        int count_acc = 0;
        QJsonArray jsonArray;
        for (JsonKeyValue* json : *qlistJsonAcc)
        {
            QJsonObject Json;
            Json["name"] = json->getKey();
            Json["token"] = json->getValue();
            jsonArray.append(Json);
            count_acc++;

        }
        QString channelId = Data::getCurrentData(qlistJsonChannel,ui->BoxChannel->currentText());
        QString paste = ui->messageText->toPlainText();
        int sleep = ui->spinBoxSleep->text().toInt();
        int sec = count_acc*sleep + 1 ;
        bool sub = ui->checkBoxSub->checkState();
        bool split = ui->checkBoxSplit->checkState();


        // Dialog* dialogBar = new Dialog("Подождите","идет отправка сообщений",sec);
        // dialogBar->deleteLater();


                // api.SendData(jsonArray,channelId,paste,sleep,sub,split);

        // std::thread tr2(showApp, dialogBar);
        // std::thread tr(barUpdate, dialogBar,sec,&api.jsonAnswer,api.mainReply);
        api.SendDataWithDialog(jsonArray,channelId,paste,sleep,sub,split);

        // dialogBar->exec();

        // tr2.join();
        // tr.join();
        // delete dialogBar;

        QString textToShow="";
        if (api.jsonAnswer.isEmpty())
            qDebug() << "Не удалось отправить сообщения";
        else
        {
            QJsonArray arrayAnswer = api.jsonAnswer["message"].toArray();
            for (const QJsonValue &value : arrayAnswer) {
                if (value.isObject()) {
                    QJsonObject obj = value.toObject();
                    QString name = obj["name"].toString();
                    QJsonValue statusCodeValue = obj["status_code"];
                    // qDebug() << "Name:" << name;
                    if (statusCodeValue.isNull()) {
                        textToShow = textToShow+"\n"+name+" Сообщение отправлено успешно";
                    }
                    else if (statusCodeValue.toString() == "R9K_MODE"){
                        textToShow = textToShow+"\n"+name+" Не удалось отправить. Нужно подписаться на канал";
                    }
                    else if (statusCodeValue.toString() == "R9K_DONE"){
                        textToShow = textToShow+"\n"+name+" Не удалось отправить. Нужно подписаться на канал, теперь подписан";
                    }
                    else{
                        textToShow = textToShow+"\n"+name+" Ошибка отправки сообщения";
                    }
                }
            }
            QMessageBox::warning(this, "Отправка сообщений!", textToShow);
            api.jsonAnswer = QJsonObject();
        }
    }

}

void widget::on_ButtonAddAcc_clicked()
{
    QString key;
    QString value;

    Dialog dialog("Добавить Аккаунт","Название","auth-token",this);
    if (dialog.exec() == QDialog::Accepted)
    {
        key = dialog.getTitle();
        value = dialog.getText();
    }
    if(key.size()>0 and value.size()>0)
        if(Data::AddDataTreeWidget(ui->treeWidgetAcc,qlistJsonAcc,key,value))
            QMessageBox::warning(this, "Повторение!", "Такой шаблон есть, выберите другое имя");
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
        api.GetChannelIDwithDialog(key);

        // Dialog* dialogBar = new Dialog("Подождите","Идет поиск ID канала",secWait);
        // dialogBar->deleteLater();
        // std::thread tr(barUpdate, dialogBar,70,&api.jsonAnswer,api.mainReply);

        // dialogBar->exec();
        // tr.join();
        // delete dialogBar;

        // qDebug() << api.jsonAnswer.empty();
        if (api.jsonAnswer.isEmpty())
        {
             QMessageBox::warning(this, "Ошибка!", "Ошибка при получении ID канала");
        }
        else
        {
            QJsonValue answerValue = api.jsonAnswer.take("channel_id");
            if(answerValue.isNull())
            {
                QMessageBox::warning(this, "Ошибка!", "Не удалось найти канал "+key);
            }
            else if(answerValue.toString().length()>0)
            {
                value = answerValue.toString();
                if (Data::AddDataTreeWidget(ui->treeWidgetChanel,qlistJsonChannel,key,value,ui->BoxChannel))
                    QMessageBox::warning(this, "Повторение!", "Такой канал есть");
            }
            api.jsonAnswer = QJsonObject();
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
    }
}
void widget::on_ButtonDeleteChannel_clicked()
{
    QTreeWidgetItem *item = ui->treeWidgetChanel->currentItem();
    if(item)
    {
        Data::DeleteDataTreeWidget(item,qlistJsonChannel,ui->BoxChannel);
    }
}
void widget::on_ButtonDeletePaste_clicked()
{
    QTreeWidgetItem *item = ui->treeWidgetPaste->currentItem();
    if(item)
    {
        Data::DeleteDataTreeWidget(item,qlistJsonPaste,ui->BoxPaste);
    }
}


void widget::on_addPaste_clicked()
{
    QString text = ui->messageText->toPlainText();
    ui->messageText->setPlainText(text+Data::getCurrentData(qlistJsonPaste,ui->BoxPaste->currentText()));
}


void widget::on_messageText_textChanged()
{

    int size = ui->messageText->toPlainText().size();
    ui->sizeText->setText("символов "+QString::number(size));
}


void widget::on_addSybSplit_clicked()
{
    ui->messageText->setText(ui->messageText->toPlainText()+"^");
    if(!ui->checkBoxSplit->checkState())
        ui->checkBoxSplit->click();
    ui->messageText->setFocus();
    ui->messageText->moveCursor(QTextCursor::End);
}

