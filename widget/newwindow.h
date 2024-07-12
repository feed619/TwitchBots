#ifndef NEWWINDOW_H
#define NEWWINDOW_H

#include <QWidget>


class NewWindow : public QWidget
{
    Q_OBJECT

public:
    explicit NewWindow(QWidget *parent = nullptr);
    ~NewWindow();

private:
    NewWindow *ui;
};

#endif // NEWWINDOW_H
