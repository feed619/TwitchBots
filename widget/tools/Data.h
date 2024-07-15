#ifndef DATA_H
#define DATA_H

#include <QTreeWidget>
#include <QFile>
#include <QDir>
#include "JsonKeyValue.h"


class Data
{
public:
    Data();

    static void  LoadDataTreeWidget(QTreeWidget* tree,QList<JsonKeyValue*>* qlist,QString fileName);
    static void  SaveDataTreeWidget(QList<JsonKeyValue*>* json,QString fileName);

    static bool  AddDataTreeWidget(QTreeWidget* tree,QList<JsonKeyValue*>* qlist,QString key,QString value);
    static void  DeleteDataTreeWidget(QTreeWidgetItem *item,QList<JsonKeyValue*>* qlist);

};

#endif // DATA_H
