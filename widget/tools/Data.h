#ifndef DATA_H
#define DATA_H

#include <QTreeWidget>
#include <QComboBox>
// #include <QFile>
#include <QDir>
#include "JsonKeyValue.h"


class Data
{
public:
    Data();

    static void  LoadDataTreeWidget(QTreeWidget* tree,QList<JsonKeyValue*>* qlist,QString fileName,QComboBox* box=nullptr);
    static void  SaveDataTreeWidget(QList<JsonKeyValue*>* json,QString fileName);

    static bool  AddDataTreeWidget(QTreeWidget* tree,QList<JsonKeyValue*>* qlist,QString key,QString value,QComboBox* box=nullptr);
    static void  DeleteDataTreeWidget(QTreeWidgetItem *item,QList<JsonKeyValue*>* qlist,QComboBox* box=nullptr);

    static QString getCurrentData(QList<JsonKeyValue*>* qlist,QString key);

};

#endif // DATA_H
