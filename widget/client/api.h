#ifndef API_H
#define API_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
// #include <QEventLoop>
#include <QUrlQuery>
// #include <QTimer>
#include <QUrl>
#include <QJsonArray>
#include <QProgressDialog>
#include "../tools/dialog.h"
// #include <QPainter>
class Api : public QObject
{
    Q_OBJECT

public:
    explicit Api(QObject *parent = nullptr);
    void SendData(QJsonArray accArray,QString ChannelID,QString Paste,int sleep, bool sub, bool split);
    void SendDataWithDialog(QJsonArray accArray,QString ChannelID,QString Paste,int sleep, bool sub, bool split);
    void onDataFetched(QNetworkReply *reply);
    void GetChannelID(QString channelName);
    void GetChannelIDwithDialog(QString channelName);

    void GetData();
    void sendPostRequest(const QJsonObject &data);
    void serverShutdown();
    QNetworkReply *mainReply;
    QJsonObject  jsonAnswer;
    void onError();

private:
    QString data =NULL;
    QNetworkAccessManager *manager;

    QProgressDialog *asd;
    void delay(int milliseconds);

};

#endif // API_H
