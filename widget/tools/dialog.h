#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>
#include <QVBoxLayout>
#include <QEventLoop>
#include <QTimer>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QString dialogName,QString fLebelName,QString sLebelName,QWidget *parent = nullptr);
    Dialog(QString dialogName,QString fLebelName,QWidget *parent = nullptr);
    Dialog(QString dialogName,QWidget *parent = nullptr);
    QString getTitle() const;
    QString getText() const;

private slots:
    void accept();

private:
    QLineEdit *titleField;
    QLineEdit *textField;
    QPushButton *okButton;
};

#endif // DIALOG_H
