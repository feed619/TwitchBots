#include "newwindow.h"
#include "ui_newwindow.h"

NewWindow::NewWindow(QWidget *parent) :

{
    // QWidget(parent),
    ui = new NewWindow;
    ui->setupUi(this);
}

NewWindow::~NewWindow()
{
    delete ui;
}
