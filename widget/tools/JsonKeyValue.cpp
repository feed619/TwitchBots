#include "JsonKeyValue.h"

JsonKeyValue::JsonKeyValue(QString skey,QString svalue) {
    key = new QString(skey);
    value = new QString(svalue);
}
JsonKeyValue::~JsonKeyValue() {
    delete key ;
    delete value;
}

QString JsonKeyValue::getKey()
{
    return *key;
}

QString JsonKeyValue::getValue()
{
    return *value;
}
