#ifndef API_H
#define API_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

class Api : public QObject
{
    Q_OBJECT

public:
    explicit Api(QObject *parent = nullptr);
    void SendData();
    void GetData();
    void onDataFetched(QNetworkReply *reply);

private:
    QNetworkAccessManager *manager;
};

#endif // API_H
