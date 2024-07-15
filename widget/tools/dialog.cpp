#include "dialog.h"

Dialog::Dialog(QString dialogName,QString fLebelName,QString sLebelName,QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(dialogName);

    titleField = new QLineEdit(this);
    titleField->setGeometry(QRect(QPoint(50, 50), QSize(200, 30)));
    titleField->setPlaceholderText(fLebelName);

    if(sLebelName.size())
    {

    textField = new QLineEdit(this);
    textField->setGeometry(QRect(QPoint(50, 100), QSize(200, 30)));
    textField->setPlaceholderText(sLebelName);
    }
    okButton = new QPushButton("OK", this);
    okButton->setGeometry(QRect(QPoint(100, 150), QSize(100, 30)));

    connect(okButton, &QPushButton::clicked, this, &Dialog::accept);
}
Dialog::Dialog(QString dialogName,QString fLebelName,QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(dialogName);

    titleField = new QLineEdit(this);
    titleField->setGeometry(QRect(QPoint(50, 50), QSize(200, 30)));
    titleField->setPlaceholderText(fLebelName);

    okButton = new QPushButton("OK", this);
    okButton->setGeometry(QRect(QPoint(100, 150), QSize(100, 30)));

    connect(okButton, &QPushButton::clicked, this, &Dialog::accept);
}
QString Dialog::getTitle() const
{
    return titleField->text();
}

QString Dialog::getText() const
{
    return textField->text();
}

void Dialog::accept()
{
    QDialog::accept();
}
