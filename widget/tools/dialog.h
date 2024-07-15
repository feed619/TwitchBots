#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QString dialogName,QString fLebelName,QString sLebelName,QWidget *parent = nullptr);
    Dialog(QString dialogName,QString fLebelName,QWidget *parent = nullptr);
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
