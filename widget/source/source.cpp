#include "Source.h"

Source::Source(/* args */)
{

    this->window = new QWidget();
    this->window->resize(this->width, this->height);
    this->window->setWindowTitle("Simple example");
    this->window->setAutoFillBackground(true);
    this->window->show();

    // create_buttons();
}

Source::~Source()
{
    delete this->window;
}
void Source::create_buttons()
{
    this->vbox = new QVBoxLayout();
    QPushButton *btn1 = new QPushButton("Свернуть");
    // QPushButton *btnMax = new QPushButton("Развернуть");
    // QPushButton *btnFull = new QPushButton("Полный экран");
    // QPushButton *btnNormal = new QPushButton("Нормальный размер");
    vbox->addWidget(btn1);

    // vbox->addWidget(btnMax);
    // vbox->addWidget(btnFull);
    // vbox->addWidget(btnNormal);
    this->window->setLayout(vbox);
}
