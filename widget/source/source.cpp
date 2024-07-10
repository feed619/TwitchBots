#include "Source.h"

Source::Source(/* args */)
{

    this->window = new QWidget();
    this->window->resize(this->width, this->height);
    this->window->setWindowTitle("Simple example");
    this->window->setAutoFillBackground(true);

    this->palette = new QPalette();
    this->palette->setColor(QPalette::Shadow, Qt::lightGray); // Устанавливаем цвет фона
    this->window->setPalette(*this->palette);
    this->window->show();
}

Source::~Source()
{
    delete this->window;
}