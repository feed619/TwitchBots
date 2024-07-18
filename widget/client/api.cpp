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
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
        QJsonObject jsonObj = jsonDoc.object();
        data=jsonObj["message"].toString();
    } else {
        qDebug() << "Error fetching data";
    }
    reply->deleteLater();
}

QString* Api::GetChannelID(QString channelName)
{
    QUrlQuery queryParams;
    queryParams.addQueryItem("channel_name", channelName);

    QUrl qurl("http://127.0.0.1:5000/api/get_id");
    qurl.setQuery(queryParams);
    qDebug() << qurl;
    connect(manager, &QNetworkAccessManager::finished, this, [this](QNetworkReply *reply) {
        this->onDataFetched(reply);
        disconnect(manager, &QNetworkAccessManager::finished, this, nullptr);
    });

    QNetworkRequest request(qurl);
    manager->get(request);


    return &data;
}


void Api::SendData(QJsonArray accArray,QString channelID,QString paste,int sleep)
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

    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    manager->post(request, data);

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

void Api::delay(int milliseconds) {
    QEventLoop loop;
    QTimer::singleShot(milliseconds, &loop, &QEventLoop::quit);
    loop.exec();
}
