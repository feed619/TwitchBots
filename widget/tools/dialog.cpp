#include "dialog.h"

Dialog::Dialog(QString dialogName,QString fLebelName,QString Str1LebelName,QString Str2LebelName,QString Str3LebelName,QWidget *parent)

{
    setWindowTitle(dialogName);

    titleField = new QLineEdit(this);
    titleField->setGeometry(QRect(QPoint(50, 50), QSize(200, 30)));
    titleField->setPlaceholderText(fLebelName);


    textField = new QLineEdit(this);
    textField->setGeometry(QRect(QPoint(50, 100), QSize(200, 30)));
    textField->setPlaceholderText(Str1LebelName);

    textField2 = new QLineEdit(this);
    textField2->setGeometry(QRect(QPoint(50, 150), QSize(200, 30)));
    textField2->setPlaceholderText(Str2LebelName);

    textField3 = new QLineEdit(this);
    textField3->setGeometry(QRect(QPoint(50, 200), QSize(200, 30)));
    textField3->setPlaceholderText(Str3LebelName);

    okButton = new QPushButton("OK", this);
    okButton->setGeometry(QRect(QPoint(100, 250), QSize(100, 30)));

    connect(okButton, &QPushButton::clicked, this, &Dialog::accept);

}
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
Dialog::Dialog(QString dialogName,QString lebelName,int barSize,QWidget *parent)
{
    setWindowTitle(dialogName);


    connect(okButton, &QPushButton::clicked, this, &Dialog::accept);

    layout = new QVBoxLayout(this);
    label = new QLabel(lebelName, this);
    progressBar = new QProgressBar(this);
    progressBar->setRange(0, barSize);
    layout->addWidget(label);
    layout->addWidget(progressBar);
    setLayout(layout);

}


Dialog::~Dialog() {
  if (titleField)
    delete titleField;
  if (textField)
    delete textField;
  if (textField2)
      delete textField2;
  if (textField3)
      delete textField3;
  if (okButton)
    delete okButton;
  if (layout)
    delete layout;
  if (label)
    delete label;
  if (progressBar)
    delete progressBar;
}

void Dialog::accept()
{
    QDialog::accept();
}
