#include "widget.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    btn1 = new QPushButton("Нажми меня");
    btn2 = new QPushButton("Блокировать");
    btn3 = new QPushButton("Разблокировать");
    btn4 = new QPushButton("Удалить обработчик");
    btn3->setEnabled(false);
    vbox = new QVBoxLayout();
    vbox->addWidget(btn1);
    vbox->addWidget(btn2);
    vbox->addWidget(btn3);
    vbox->addWidget(btn4);
    setLayout(vbox);
    connect(btn1, SIGNAL(clicked()),
            this, SLOT(on_btn1_clicked()));
    connect(btn2, SIGNAL(clicked()),
            this, SLOT(on_btn2_clicked()));
    connect(btn3, SIGNAL(clicked()),
            this, SLOT(on_btn3_clicked()));
    connect(btn4, SIGNAL(clicked()),
            this, SLOT(on_btn4_clicked()));
}
void Widget::on_btn1_clicked()
{
    qDebug() << "Нажата кнопка 1";
}
void Widget::on_btn2_clicked()
{
    btn1->blockSignals(true);
    btn2->setEnabled(false);
    btn3->setEnabled(true);
}
void Widget::on_btn3_clicked()
{
    btn1->blockSignals(false);
    btn2->setEnabled(true);
    btn3->setEnabled(false);
}
void Widget::on_btn4_clicked()
{
    disconnect(btn1, SIGNAL(clicked()),
               this, SLOT(on_btn1_clicked()));
    btn2->setEnabled(false);
    btn3->setEnabled(false);
    btn4->setEnabled(false);
}
Widget::~Widget() {}