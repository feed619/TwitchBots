#ifndef WIDGET_H
#define WIDGET_H

#include <QTreeWidget>
#include <QMessageBox>
#include <QWidget>
#include <QList>
#include <QFile>
#include <QDir>
#include <QThread>

#include "tools/JsonKeyValue.h"
#include "tools/Data.h"
#include "tools/dialog.h"
#include "client/api.h"

#define F_ACC "treeAcc"
#define F_CHANNEL "treeChannel"
#define F_PASTE "treePaste"
QT_BEGIN_NAMESPACE
namespace Ui { class widget; }
QT_END_NAMESPACE

class widget : public QWidget
{
    Q_OBJECT

public:
    widget(QWidget *parent = nullptr);
    ~widget();
private slots:

    void on_ButtonSend_clicked();
    void on_ButtonClear_clicked();
    void on_checkBoxAntiBot_clicked();

    void on_ButtonAdd_Channel_clicked();
    void on_ButtonAddAcc_clicked();
    void on_ButtonAddPaste_clicked();

    void on_ButtonDeleteChannel_clicked();
    void on_ButtonDeleteAcc_clicked();
    void on_ButtonDeletePaste_clicked();

private:
    bool AntiBot = true;
    int sleep = 0;
    int secWait = 70;

    Api api;
    Ui::widget *ui;
    Dialog*  dialogBar;

    QList<JsonKeyValue*>* qlistJsonAcc;
    QList<JsonKeyValue*>* qlistJsonChannel;
    QList<JsonKeyValue*>* qlistJsonPaste;
    void onTimeout();
    void delay(int milliseconds);
};
#endif // WIDGET_H


