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
#include <QThread>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QString dialogName,QString fLebelName,QString sLebelName,QWidget *parent = nullptr);
    Dialog(QString dialogName,QString fLebelName,QWidget *parent = nullptr);
    Dialog(QString dialogName,QString lebelName,int barSize,QWidget *parent = nullptr);


    ~Dialog();
    QString getTitle() const{return titleField->text();}
    QString getText() const {return textField->text();}
    void setBar(int value){progressBar->setValue(value);}



private slots:
    void accept();
public slots:
    void doWork(){qDebug() <<"asd";}
signals:
    void workFinished();
private:
    QLineEdit *titleField = nullptr;
    QLineEdit *textField = nullptr;
    QPushButton *okButton = nullptr;
    QVBoxLayout *layout = nullptr;
    QLabel *label = nullptr;
public:
    QProgressBar* progressBar = nullptr;

};

#endif // DIALOG_H
