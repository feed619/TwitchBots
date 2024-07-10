#include "account _widget.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    btn1 = new QPushButton("Открыть модальное окно");
    vbox = new QVBoxLayout();
    vbox->addWidget(btn1);
    setLayout(vbox);
    // connect(btn1, SIGNAL(clicked()),
    //         this, SLOT(on_btn1_clicked()));
}
void Widget::on_btn1_clicked()
{
    QWidget *w = new QWidget(this, Qt::Window);
    w->setWindowTitle("Модальное окно");
    w->resize(300, 50);
    w->setWindowModality(Qt::WindowModal);
    w->setAttribute(Qt::WA_DeleteOnClose, true);
    w->move(frameGeometry().center() - w->rect().center());
    w->show();
}
Widget::~Widget() {}