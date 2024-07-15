#include "Data.h"

Data::Data() {}
void Data::LoadDataTreeWidget(QTreeWidget* tree,QList<JsonKeyValue*>* qlist,QString fileName,QComboBox* box)
{
    QString data;
    QString dirParh = QDir::currentPath();
    QString path = dirParh+"/../widget/data/"+fileName;
    QFile file(path);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cannot open file for reading:" << file.errorString();
        return;
    }
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line.size())
        {
            for(int index = 0;index<line.size();index++)
            {
                if(line[index] == '\t')
                {
                    QString key = line.mid(0,index);
                    QString value = line.mid(index+1,line.size());
                    AddDataTreeWidget(tree,qlist,key,value,box);
                }
            }
        }
    }
}
void Data::SaveDataTreeWidget(QList<JsonKeyValue*>* json,QString fileName)
{

    QString dataTree;

    for (JsonKeyValue* jsonData:*json)
    {
        dataTree+=jsonData->getKey()+"\t"+jsonData->getValue()+"\n";
    }

    QString dirParh = QDir::currentPath();
    QString path = dirParh+"/../widget/data/"+fileName;
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Не смог открыть";
        // QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }
    QTextStream out(&file);
    out << dataTree;
    file.close();
}


bool Data::AddDataTreeWidget(QTreeWidget* tree,QList<JsonKeyValue*>* qlist,QString key,QString value,QComboBox* box)
{

    for(JsonKeyValue* json:*qlist)
    {
        if(json->getKey() == key)
        {
            qDebug() << "Такой шаблон есть, выберите другое имя";
            // QMessageBox::warning(this, "Повторение!", "Такой шаблон есть, выберите другое имя");
            return true;
        }
    }
    qlist->append(new JsonKeyValue(key,value));
    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0,key);
    item->setText(1,value);
    tree->addTopLevelItem(item);

    if(box)
        box->addItem(key);

    return false;
}

void Data::DeleteDataTreeWidget(QTreeWidgetItem *item,QList<JsonKeyValue*>* qlist,QComboBox* box)
{
    int x =0;
    QList<JsonKeyValue*>::iterator it;
    for (it = qlist->begin(); it != qlist->end(); ++it)
    {
        if((*it)->getKey() == item->text(0))
        {
            qlist->removeAt(x);
            delete item;

            if(box)
                box->removeItem(x);

            return;
        }
        x++;
    }
}
