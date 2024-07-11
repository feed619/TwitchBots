#include "widget.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    btn1 = new QPushButton("Получить");
    btn2 = new QPushButton("Отправить");

    lineEdit = new QLineEdit(this);/*
    lineEdit->setGeometry(QRect(QPoint(10, 10), QSize(580, 200)));*/



    vbox = new QVBoxLayout();
    vbox->addWidget(btn2);
    vbox->addWidget(btn1);

    setLayout(vbox);
    connect(btn1, SIGNAL(clicked()),
            this, SLOT(on_btn1_clicked()));
    connect(btn2, SIGNAL(clicked()),
            this, SLOT(on_btn2_clicked()));

}

void Widget::setText(const QString &text)
{
    qDebug() << "Text changed:" << text;
}

void Widget::on_btn1_clicked()
{
    api_net.GetData();
    qDebug() << "Нажата кнопка 1";
}
void Widget::on_btn2_clicked()
{
    api_net.SendData();
    qDebug() << "Нажата кнопка 2";
}

Widget::~Widget() {}
