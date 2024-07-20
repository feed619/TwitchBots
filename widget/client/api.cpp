#include "api.h"

Api::Api(QObject *parent) : QObject(parent), manager(new QNetworkAccessManager(this)) {}

void Api::GetData() {
    connect(manager, &QNetworkAccessManager::finished, this, [this](QNetworkReply *reply) {
        this->onDataFetched(reply);
        disconnect(manager, &QNetworkAccessManager::finished, this, nullptr);
    });

    QNetworkRequest request(QUrl("http://127.0.0.1:5000/api/get_data"));
    manager->get(request);

}


void Api::onDataFetched(QNetworkReply *reply) {
    mainReply = reply;
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
        QJsonObject jsonObj = jsonDoc.object();
        jsonAnswer=jsonObj;
        // data=jsonObj["message"].toString();
    } else {
        qDebug() << "Error fetching data";
    }
    reply->deleteLater();
}
void Api::onError()
{
    mainReply->deleteLater();
    mainReply = nullptr;
}
void Api::GetChannelID(QString channelName)
{
    QUrlQuery queryParams;
    queryParams.addQueryItem("channel_name", channelName);
    QUrl qurl("http://127.0.0.1:5000/api/get_id");
    qurl.setQuery(queryParams);
    // qDebug() << qurl;
    connect(manager, &QNetworkAccessManager::finished, this, [this](QNetworkReply *reply) {
        this->onDataFetched(reply);
        disconnect(manager, &QNetworkAccessManager::finished, this, nullptr);
    });

    QNetworkRequest request(qurl);
    manager->get(request);

}

void Api::GetChannelIDwithDialog(QString channelName)
{

    QUrlQuery queryParams;
    queryParams.addQueryItem("channel_name", channelName);


    QUrl qurl("http://127.0.0.1:5000/api/get_id");
    qurl.setQuery(queryParams);

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QProgressDialog progressDialog("Подождите","скрыть",0,0);
    progressDialog.setWindowModality(Qt::WindowModal);
    progressDialog.setMinimumDuration(3);
    // progressDialog.setValue(2);
    // QUrl url("http://127.0.0.1:5000/api/get_id");
    QNetworkRequest request(qurl);

    // request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = manager->get(request);

    connect(reply, &QNetworkReply::finished, &progressDialog, &QProgressDialog::reset);
    connect(&progressDialog, &QProgressDialog::canceled, reply, &QNetworkReply::abort);

    progressDialog.exec();

    if (reply->error() == QNetworkReply::NoError) {
        // Обработка успешного запроса
        // QString response = reply->readAll();
        QByteArray responseData = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
        QJsonObject jsonObj = jsonDoc.object();
        jsonAnswer=jsonObj;
        qDebug() <<jsonAnswer;
    } else {
    }

    reply->deleteLater();


}

void Api::SendData(QJsonArray accArray,QString channelID,QString paste,int sleep,bool sub,bool split)
{
    QUrl url("http://127.0.0.1:5000/api/sent_data");
    connect(manager, &QNetworkAccessManager::finished, this, [this](QNetworkReply *reply) {
        this->onDataFetched(reply);
        disconnect(manager, &QNetworkAccessManager::finished, this, nullptr);
    });

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
    json["accounts"] = accArray;
    json["channel_id"] = channelID;
    json["paste"] = paste;
    json["sleep"] = sleep;
    json["sub"] = sub;
    json["split"] = split;

    QJsonDocument doc(json);
    QByteArray jsonData = doc.toJson();

    manager->post(request, jsonData);
}


void Api::SendDataWithDialog(QJsonArray accArray,QString channelID,QString paste,int sleep,bool sub,bool split)
{

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    QProgressDialog progressDialog("Отправка сообщений","отмена",0,0);
    progressDialog.setWindowModality(Qt::WindowModal);
    progressDialog.setMinimumDuration(3);
    progressDialog.setValue(2);
    QUrl url("http://127.0.0.1:5000/api/sent_data");
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
    json["accounts"] = accArray;
    json["channel_id"] = channelID;
    json["paste"] = paste;
    json["sleep"] = sleep;
    json["sub"] = sub;
    json["split"] = split;


    QJsonDocument jsonDoc(json);
    QByteArray jsonData = jsonDoc.toJson();

    QNetworkReply *reply = manager->post(request, jsonData);

    connect(reply, &QNetworkReply::finished, &progressDialog, &QProgressDialog::reset);
    connect(&progressDialog, &QProgressDialog::canceled, reply, &QNetworkReply::abort);

    progressDialog.exec();

    if (reply->error() == QNetworkReply::NoError) {
        // Обработка успешного запроса
        // QString response = reply->readAll();
            QByteArray responseData = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
        QJsonObject jsonObj = jsonDoc.object();
        jsonAnswer=jsonObj;
        qDebug() <<jsonAnswer;
    } else {
    }

    reply->deleteLater();


    // QProgressDialog *progressDialog = new QProgressDialog("Waiting for server response...", "Cancel", 0, 0);
    // progressDialog->setWindowModality(Qt::WindowModal);
    // progressDialog->setMinimumDuration(0);

    // QTimer *timer = new QTimer(progressDialog);
    // connect(timer, &QTimer::timeout, [=]() {
    //     static int count = 0;
    //     progressDialog->setLabelText(QString("Waiting for server response... %1 seconds").arg(++count));
    // });
    // timer->start(1000);

    // QJsonObject json;
    // json["accounts"] = accArray;
    // json["channel_id"] = channelID;
    // json["paste"] = paste;
    // json["sleep"] = sleep;
    // json["sub"] = sub;
    // json["split"] = split;


    // QJsonDocument jsonDoc(json);
    // QByteArray jsonData = jsonDoc.toJson();


    // QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    // QNetworkRequest request(QUrl("http://127.0.0.1:5000/api/sent_data"));
    // QNetworkReply *reply = manager->post(request, jsonData);

    // connect(reply, &QNetworkReply::finished, [=]() {
    //     timer->stop();
    //     progressDialog->reset();
    //     if (reply->error() == QNetworkReply::NoError) {
    //         // Обработка успешного запроса
    //         QString response = reply->readAll();
    //         qDebug() << "Response: " << response;
    //     } else {
    //         // Обработка ошибки запроса
    //         qDebug() << "Error: " << reply->errorString();
    //     }
    //     reply->deleteLater();
    //     progressDialog->deleteLater();
    // });

    // connect(progressDialog, &QProgressDialog::canceled, [=]() {
    //     timer->stop();
    //     reply->abort();
    //     progressDialog->deleteLater();
    // });

    // progressDialog->exec();
}


void Api::sendPostRequest( const QJsonObject &data)
{
       QUrl url("http://127.0.0.1:5000/api/get_id");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonDocument doc(data);
    QByteArray jsonData = doc.toJson();

    manager->post(request, jsonData);
}


void Api::serverShutdown()
{
    // qDebug() << "поле очищено";

    QUrl url("http://127.0.0.1:5000/shutdown");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    manager->get(request);
}

void Api::delay(int milliseconds) {
    QEventLoop loop;
    QTimer::singleShot(milliseconds, &loop, &QEventLoop::quit);
    loop.exec();
}
