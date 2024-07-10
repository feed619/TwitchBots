#ifndef _SOURCE_
#define _SOURCE_

#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QVBoxLayout>
#include <QApplication>
class Source
{

    // private:
public:
    // QApplication *app;
    QWidget *window;
    QVBoxLayout *vbox;

    int width = 800;
    int height = 600;

    void create_buttons();

public:
    Source(/* args */);
    ~Source();
};

#endif