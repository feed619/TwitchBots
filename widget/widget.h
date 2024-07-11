#ifndef WIDGET_H
#define WIDGET_H
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include "source/api.h"
class Widget : public QWidget
{
    Q_OBJECT
public:
    Api api_net;
    Widget(QWidget *parent=nullptr);
    ~Widget();
private slots:
    void on_btn1_clicked();
    void on_btn2_clicked();

private:
    QPushButton *btn1;
    QPushButton *btn2;
    QVBoxLayout *vbox;
};
#endif
