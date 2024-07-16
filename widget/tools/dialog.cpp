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




    // int sec=0;
    // // while(!pvalue->size())
    // while(sec<10)
    // {
    //     qDebug() <<"жду";
    //     if (sec > 10)
    //     {
    //         qDebug() <<"Истекло время ожидания";
    //         break;
    //     }
    //     QEventLoop loop;
    //     QTimer::singleShot(1000, &loop, &QEventLoop::quit);
    //     loop.exec();
    //     sec++;
    // }



    // this->close();
}
Dialog::Dialog(QString dialogName,QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(dialogName);


    // QVBoxLayout *layout = new QVBoxLayout(this);
    // QLabel *label = new QLabel("Please wait...", this);
    // QProgressBar* progressBar = new QProgressBar(this);
    // progressBar->setRange(0, 100);
    // layout->addWidget(label);
    // layout->addWidget(progressBar);
    // setLayout(layout);
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
