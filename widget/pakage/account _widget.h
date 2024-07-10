#ifndef _ACC_WIDGET_
#define _ACC_WIDGET_

#include <QPushButton>
#include <QVBoxLayout>
class Widget : public QWidget
{

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void on_btn1_clicked();

private:
    QPushButton *btn1;
    QVBoxLayout *vbox;
};
#endif // WIDGET_H