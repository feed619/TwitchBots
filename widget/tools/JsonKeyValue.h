#ifndef JSONKEYVALUE_H
#define JSONKEYVALUE_H

#include <QString>

class JsonKeyValue
{
public:
    JsonKeyValue(QString key,QString value);
    ~JsonKeyValue();
    QString *key;
    QString *value;

    QString getKey();
    QString getValue();
};

#endif // JSONKEYVALUE_H
