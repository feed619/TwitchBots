#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QList>
#include "tools/JsonKeyValue.h"
#include <QTreeWidget>
#include <QMessageBox>
#include <QFile>
#include <QDir>

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

    // void on_ButtonAdd_Channel_clicked();


    void on_ButtonAdd_Channel_clicked();
    void on_ButtonDeleteChannel_clicked();

    void on_ButtonAddAcc_clicked();

    void on_ButtonDeleteAcc_clicked();

    void on_ButtonDeletePaste_clicked();

    void on_ButtonAddPaste_clicked();

private:
    bool AntiBot = true;
    int sleep = 0;
    Ui::widget *ui;
    void fillAllTree();
    void ConnectAllButtons();
    void addItems_comboBox();

    void AddDataTreeWidget(QTreeWidget* tree,QList<JsonKeyValue*>* qlist,QString key,QString value);
    void DeleteDataTreeWidget(QTreeWidgetItem *item,QList<JsonKeyValue*>* qlist);

    void LoadDataTreeWidget(QTreeWidget* tree,QList<JsonKeyValue*>* qlist,QString fileName);
    void SaveDataTreeWidget(QList<JsonKeyValue*>* json,QString fileName);
    QList<JsonKeyValue*>* qlistJsonAcc;
    QList<JsonKeyValue*>* qlistJsonChannel;
    QList<JsonKeyValue*>* qlistJsonPaste;
};
#endif // WIDGET_H
