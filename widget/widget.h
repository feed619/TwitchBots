#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class widget; }
QT_END_NAMESPACE

class widget : public QWidget
{
    Q_OBJECT

public:
    widget(QWidget *parent = nullptr);
    ~widget();
private slots:

    void on_ButtonSend_clicked();
    void on_ButtonClear_clicked();
    void on_checkBoxAntiBot_clicked();

private:
    bool AntiBot = true;
    int sleep = 0;
    Ui::widget *ui;


    void ConnectAllButtons();
    void addItems_comboBox();
};
#endif // WIDGET_H
