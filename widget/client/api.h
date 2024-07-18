#ifndef API_H
#define API_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QEventLoop>
#include <QUrlQuery>
#include <QTimer>
#include <QUrl>
#include <QJsonArray>

class Api : public QObject
{
    Q_OBJECT

public:
    explicit Api(QObject *parent = nullptr);
    void SendData(QJsonArray accArray,QString ChannelID,QString Paste,int sleep);
    void GetData();
    void onDataFetched(QNetworkReply *reply);
    QString* GetChannelID(QString channelName);
    void sendPostRequest(const QJsonObject &data);
private:
    QString data;
    QNetworkAccessManager *manager;

    void delay(int milliseconds);
};

#endif // API_H
