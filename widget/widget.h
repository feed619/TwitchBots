#ifndef WIDGET_H
#define WIDGET_H
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent=nullptr);
    ~Widget();
private slots:
    void on_btn1_clicked();
    void on_btn2_clicked();
    void on_btn3_clicked();
    void on_btn4_clicked();
private:
    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
    QPushButton *btn4;
    QVBoxLayout *vbox;
};
#endif
