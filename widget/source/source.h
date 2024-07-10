#ifndef _SOURCE_
#define _SOURCE_

#include <QWidget>
#include <QPalette>
// #include <QApplication>
class Source
{
    // private:
public:
    // QApplication *app;
    QWidget *window;
    QPalette *palette;

    int width = 800;
    int height = 600;

public:
    Source(/* args */);
    ~Source();
};

#endif