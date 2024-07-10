#ifndef _SOURCE_
#define _SOURCE_

#include <QApplication>
#include <QWidget>

class Source
{
private:
    QApplication *app;
    QWidget *window;

    int width;
    int height;
    window.resize(600, 800);
    window.setWindowTitle("Simple example");
    window.show();

public:
    Source(/* args */);
    ~Source();
};

#endif