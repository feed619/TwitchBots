#include "api.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QUrl>

Api::Api(QObject *parent) : QObject(parent), manager(new QNetworkAccessManager(this)) {}

void Api::GetData() {
    connect(manager, &QNetworkAccessManager::finished, this, [this](QNetworkReply *reply) {
        this->onDataFetched(reply);
        // Разрываем соединение после первого вызова
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
        qDebug() << jsonObj["message"].toString();
    } else {
        qDebug() << "Error fetching data";
    }
    reply->deleteLater();
}

void Api::SendData()
{
    // Устанавливаем URL
    QUrl url("http://127.0.0.1:5000/api/sent_data");


    connect(manager, &QNetworkAccessManager::finished, this, [this](QNetworkReply *reply) {
        this->onDataFetched(reply);
        // Разрываем соединение после первого вызова
        disconnect(manager, &QNetworkAccessManager::finished, this, nullptr);
    });
    // Создаем запрос
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // Создаем JSON-объект для тела запроса
    QJsonObject json;
    json["data"] = "Golovach top data Golovach top";


    // Преобразуем JSON-объект в QJsonDocument и затем в QByteArray
    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    // Делаем POST-запрос
    manager->post(request, data);

}
