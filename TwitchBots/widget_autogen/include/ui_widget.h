/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widget
{
public:
    QTabWidget *tabWidget;
    QWidget *Message;
    QTextEdit *messageText;
    QPushButton *ButtonSend;
    QPushButton *ButtonClear;
    QWidget *widgetSelectChannel;
    QLabel *labelNameAddPaste;
    QComboBox *BoxPaste;
    QPushButton *addPaste;
    QWidget *widgetSleep;
    QSpinBox *spinBoxSleep;
    QLabel *labelSleep;
    QWidget *widgetAddPaste;
    QLabel *labelNameSelectChannel;
    QComboBox *BoxChannel;
    QLabel *sizeText;
    QCheckBox *checkBoxSplit;
    QPushButton *addSybSplit;
    QWidget *options;
    QWidget *widgetAccount;
    QTreeWidget *treeWidgetAcc;
    QPushButton *ButtonAddAcc;
    QPushButton *ButtonDeleteAcc;
    QLabel *labelNameAcc;
    QWidget *widgetChannel;
    QTreeWidget *treeWidgetChanel;
    QPushButton *ButtonAdd_Channel;
    QPushButton *ButtonDeleteChannel;
    QLabel *labelNameChannel;
    QWidget *widgetPaste;
    QTreeWidget *treeWidgetPaste;
    QPushButton *ButtonAddPaste;
    QPushButton *ButtonDeletePaste;
    QLabel *labelNamePaste;

    void setupUi(QWidget *widget)
    {
        if (widget->objectName().isEmpty())
            widget->setObjectName("widget");
        widget->resize(900, 600);
        tabWidget = new QTabWidget(widget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 900, 600));
        Message = new QWidget();
        Message->setObjectName("Message");
        messageText = new QTextEdit(Message);
        messageText->setObjectName("messageText");
        messageText->setGeometry(QRect(20, 20, 651, 491));
        QFont font;
        font.setPointSize(14);
        messageText->setFont(font);
        ButtonSend = new QPushButton(Message);
        ButtonSend->setObjectName("ButtonSend");
        ButtonSend->setGeometry(QRect(560, 520, 111, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(12);
        font1.setBold(true);
        ButtonSend->setFont(font1);
        ButtonClear = new QPushButton(Message);
        ButtonClear->setObjectName("ButtonClear");
        ButtonClear->setGeometry(QRect(20, 520, 111, 41));
        ButtonClear->setFont(font1);
        ButtonClear->setFlat(false);
        widgetSelectChannel = new QWidget(Message);
        widgetSelectChannel->setObjectName("widgetSelectChannel");
        widgetSelectChannel->setGeometry(QRect(680, 430, 211, 81));
        labelNameAddPaste = new QLabel(widgetSelectChannel);
        labelNameAddPaste->setObjectName("labelNameAddPaste");
        labelNameAddPaste->setGeometry(QRect(0, 0, 211, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Marker Felt")});
        font2.setPointSize(20);
        font2.setBold(true);
        labelNameAddPaste->setFont(font2);
        labelNameAddPaste->setTextFormat(Qt::AutoText);
        labelNameAddPaste->setScaledContents(false);
        BoxPaste = new QComboBox(widgetSelectChannel);
        BoxPaste->setObjectName("BoxPaste");
        BoxPaste->setGeometry(QRect(0, 30, 121, 31));
        addPaste = new QPushButton(widgetSelectChannel);
        addPaste->setObjectName("addPaste");
        addPaste->setGeometry(QRect(120, 30, 81, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Segoe UI")});
        font3.setPointSize(11);
        font3.setBold(true);
        addPaste->setFont(font3);
        widgetSleep = new QWidget(Message);
        widgetSleep->setObjectName("widgetSleep");
        widgetSleep->setGeometry(QRect(680, 70, 191, 81));
        spinBoxSleep = new QSpinBox(widgetSleep);
        spinBoxSleep->setObjectName("spinBoxSleep");
        spinBoxSleep->setGeometry(QRect(0, 20, 51, 41));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Impact")});
        font4.setPointSize(14);
        spinBoxSleep->setFont(font4);
        spinBoxSleep->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        labelSleep = new QLabel(widgetSleep);
        labelSleep->setObjectName("labelSleep");
        labelSleep->setGeometry(QRect(60, 20, 121, 41));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Marker Felt")});
        font5.setPointSize(22);
        font5.setBold(true);
        labelSleep->setFont(font5);
        labelSleep->setTextFormat(Qt::AutoText);
        labelSleep->setScaledContents(false);
        widgetAddPaste = new QWidget(Message);
        widgetAddPaste->setObjectName("widgetAddPaste");
        widgetAddPaste->setGeometry(QRect(680, 340, 211, 81));
        labelNameSelectChannel = new QLabel(widgetAddPaste);
        labelNameSelectChannel->setObjectName("labelNameSelectChannel");
        labelNameSelectChannel->setGeometry(QRect(0, 0, 211, 31));
        labelNameSelectChannel->setFont(font2);
        labelNameSelectChannel->setTextFormat(Qt::AutoText);
        labelNameSelectChannel->setScaledContents(false);
        BoxChannel = new QComboBox(widgetAddPaste);
        BoxChannel->setObjectName("BoxChannel");
        BoxChannel->setGeometry(QRect(0, 30, 201, 31));
        sizeText = new QLabel(Message);
        sizeText->setObjectName("sizeText");
        sizeText->setGeometry(QRect(30, 480, 91, 21));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Segoe UI")});
        font6.setPointSize(10);
        sizeText->setFont(font6);
        checkBoxSplit = new QCheckBox(Message);
        checkBoxSplit->setObjectName("checkBoxSplit");
        checkBoxSplit->setGeometry(QRect(680, 20, 211, 51));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(checkBoxSplit->sizePolicy().hasHeightForWidth());
        checkBoxSplit->setSizePolicy(sizePolicy);
        checkBoxSplit->setMinimumSize(QSize(0, 0));
        checkBoxSplit->setSizeIncrement(QSize(0, 0));
        checkBoxSplit->setBaseSize(QSize(0, 0));
        checkBoxSplit->setFont(font5);
        checkBoxSplit->setMouseTracking(true);
        checkBoxSplit->setContextMenuPolicy(Qt::DefaultContextMenu);
        checkBoxSplit->setAutoFillBackground(false);
        checkBoxSplit->setInputMethodHints(Qt::ImhNone);
        checkBoxSplit->setIconSize(QSize(30, 30));
        checkBoxSplit->setCheckable(true);
        checkBoxSplit->setAutoRepeat(false);
        checkBoxSplit->setTristate(false);
        addSybSplit = new QPushButton(Message);
        addSybSplit->setObjectName("addSybSplit");
        addSybSplit->setGeometry(QRect(830, 30, 41, 31));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Segoe UI")});
        font7.setPointSize(18);
        font7.setBold(true);
        addSybSplit->setFont(font7);
        tabWidget->addTab(Message, QString());
        options = new QWidget();
        options->setObjectName("options");
        widgetAccount = new QWidget(options);
        widgetAccount->setObjectName("widgetAccount");
        widgetAccount->setGeometry(QRect(0, 0, 301, 571));
        treeWidgetAcc = new QTreeWidget(widgetAccount);
        QFont font8;
        font8.setBold(true);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setFont(1, font8);
        __qtreewidgetitem->setFont(0, font8);
        treeWidgetAcc->setHeaderItem(__qtreewidgetitem);
        treeWidgetAcc->setObjectName("treeWidgetAcc");
        treeWidgetAcc->setGeometry(QRect(0, 40, 291, 481));
        QFont font9;
        font9.setFamilies({QString::fromUtf8("Segoe UI")});
        font9.setPointSize(10);
        font9.setBold(false);
        treeWidgetAcc->setFont(font9);
        ButtonAddAcc = new QPushButton(widgetAccount);
        ButtonAddAcc->setObjectName("ButtonAddAcc");
        ButtonAddAcc->setGeometry(QRect(180, 520, 111, 41));
        QFont font10;
        font10.setFamilies({QString::fromUtf8("Segoe UI")});
        font10.setPointSize(12);
        font10.setBold(false);
        ButtonAddAcc->setFont(font10);
        ButtonDeleteAcc = new QPushButton(widgetAccount);
        ButtonDeleteAcc->setObjectName("ButtonDeleteAcc");
        ButtonDeleteAcc->setGeometry(QRect(0, 520, 111, 41));
        ButtonDeleteAcc->setFont(font10);
        labelNameAcc = new QLabel(widgetAccount);
        labelNameAcc->setObjectName("labelNameAcc");
        labelNameAcc->setGeometry(QRect(80, 0, 141, 41));
        labelNameAcc->setFont(font2);
        widgetChannel = new QWidget(options);
        widgetChannel->setObjectName("widgetChannel");
        widgetChannel->setGeometry(QRect(300, 0, 301, 571));
        treeWidgetChanel = new QTreeWidget(widgetChannel);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setFont(1, font8);
        __qtreewidgetitem1->setFont(0, font8);
        treeWidgetChanel->setHeaderItem(__qtreewidgetitem1);
        treeWidgetChanel->setObjectName("treeWidgetChanel");
        treeWidgetChanel->setGeometry(QRect(0, 40, 291, 481));
        treeWidgetChanel->setFont(font9);
        ButtonAdd_Channel = new QPushButton(widgetChannel);
        ButtonAdd_Channel->setObjectName("ButtonAdd_Channel");
        ButtonAdd_Channel->setGeometry(QRect(180, 520, 111, 41));
        ButtonAdd_Channel->setFont(font10);
        ButtonDeleteChannel = new QPushButton(widgetChannel);
        ButtonDeleteChannel->setObjectName("ButtonDeleteChannel");
        ButtonDeleteChannel->setGeometry(QRect(0, 520, 111, 41));
        ButtonDeleteChannel->setFont(font10);
        labelNameChannel = new QLabel(widgetChannel);
        labelNameChannel->setObjectName("labelNameChannel");
        labelNameChannel->setGeometry(QRect(90, 0, 141, 41));
        labelNameChannel->setFont(font2);
        widgetPaste = new QWidget(options);
        widgetPaste->setObjectName("widgetPaste");
        widgetPaste->setGeometry(QRect(600, 0, 301, 571));
        treeWidgetPaste = new QTreeWidget(widgetPaste);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem();
        __qtreewidgetitem2->setFont(1, font8);
        __qtreewidgetitem2->setFont(0, font8);
        treeWidgetPaste->setHeaderItem(__qtreewidgetitem2);
        treeWidgetPaste->setObjectName("treeWidgetPaste");
        treeWidgetPaste->setGeometry(QRect(0, 40, 291, 481));
        treeWidgetPaste->setFont(font9);
        ButtonAddPaste = new QPushButton(widgetPaste);
        ButtonAddPaste->setObjectName("ButtonAddPaste");
        ButtonAddPaste->setGeometry(QRect(180, 520, 111, 41));
        ButtonAddPaste->setFont(font10);
        ButtonDeletePaste = new QPushButton(widgetPaste);
        ButtonDeletePaste->setObjectName("ButtonDeletePaste");
        ButtonDeletePaste->setGeometry(QRect(0, 520, 111, 41));
        ButtonDeletePaste->setFont(font10);
        labelNamePaste = new QLabel(widgetPaste);
        labelNamePaste->setObjectName("labelNamePaste");
        labelNamePaste->setGeometry(QRect(80, 0, 141, 41));
        labelNamePaste->setFont(font2);
        tabWidget->addTab(options, QString());

        retranslateUi(widget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(widget);
    } // setupUi

    void retranslateUi(QWidget *widget)
    {
        widget->setWindowTitle(QCoreApplication::translate("widget", "widget", nullptr));
        ButtonSend->setText(QCoreApplication::translate("widget", "send", nullptr));
        ButtonClear->setText(QCoreApplication::translate("widget", "clear", nullptr));
        labelNameAddPaste->setText(QCoreApplication::translate("widget", "          paste", nullptr));
        addPaste->setText(QCoreApplication::translate("widget", "add", nullptr));
        labelSleep->setText(QCoreApplication::translate("widget", "sleep", nullptr));
        labelNameSelectChannel->setText(QCoreApplication::translate("widget", "   select channel", nullptr));
        sizeText->setText(QCoreApplication::translate("widget", "symbols  0", nullptr));
        checkBoxSplit->setText(QCoreApplication::translate("widget", "      split", nullptr));
        addSybSplit->setText(QCoreApplication::translate("widget", "^", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Message), QCoreApplication::translate("widget", "Message", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidgetAcc->headerItem();
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("widget", "auth-token", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("widget", "Nickname", nullptr));
        ButtonAddAcc->setText(QCoreApplication::translate("widget", "add", nullptr));
        ButtonDeleteAcc->setText(QCoreApplication::translate("widget", "delete", nullptr));
        labelNameAcc->setText(QCoreApplication::translate("widget", "Accounts", nullptr));
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidgetChanel->headerItem();
        ___qtreewidgetitem1->setText(1, QCoreApplication::translate("widget", "id channel", nullptr));
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("widget", "Name", nullptr));
        ButtonAdd_Channel->setText(QCoreApplication::translate("widget", "add", nullptr));
        ButtonDeleteChannel->setText(QCoreApplication::translate("widget", "delete", nullptr));
        labelNameChannel->setText(QCoreApplication::translate("widget", "Channels", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidgetPaste->headerItem();
        ___qtreewidgetitem2->setText(1, QCoreApplication::translate("widget", "Paste", nullptr));
        ___qtreewidgetitem2->setText(0, QCoreApplication::translate("widget", "Name", nullptr));
        ButtonAddPaste->setText(QCoreApplication::translate("widget", "add", nullptr));
        ButtonDeletePaste->setText(QCoreApplication::translate("widget", "delete", nullptr));
        labelNamePaste->setText(QCoreApplication::translate("widget", "  Paste", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(options), QCoreApplication::translate("widget", "Options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class widget: public Ui_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
