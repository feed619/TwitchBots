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
        qDebug() <<"1";
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

    // this->exec();



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


    qDebug() <<"2";
    // this->close();
}
Dialog::Dialog(QString dialogName,int barSize,QString* data,QWidget *parent)
{
    setWindowTitle(dialogName);



    okButton = new QPushButton("OK", this);
    okButton->setGeometry(QRect(QPoint(100, 150), QSize(100, 30)));

    connect(okButton, &QPushButton::clicked, this, &Dialog::accept);
    qDebug() <<"3";


    layout = new QVBoxLayout(this);
    label = new QLabel("Please wait...", this);
    progressBar = new QProgressBar(this);
    progressBar->setRange(0, barSize);
    layout->addWidget(label);
    layout->addWidget(progressBar);
    setLayout(layout);


    // QThread *workerThread = new QThread;

    // this->moveToThread(workerThread);
    // connect(workerThread, &QThread::started, this, &Dialog::doWork);
    //     connect(this, &Dialog::workFinished, workerThread, &QThread::quit);
    //     this->exec();


    //     progressBar->setValue(99);
    // int sec=0;
    // while(!pvalue->size())

    // while(sec<5)
    // {
    //     QEventLoop en(this);
    //     en.wakeUp();
    //     this->update();
    //     this->show();
    //     progressBar->setValue(sec);
    //     qDebug() <<"жду";
    //     if (sec > 70)
    //     {
    //         qDebug() <<"Истекло время ожидания";
    //         break;
    //     }
    //     QThread::sleep(1);
    //     sec++;
    // }

}

Dialog::~Dialog() {
  if (titleField)
    delete titleField;
  if (textField)
    delete textField;
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
