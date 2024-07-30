#include "widget.h"
#include <QApplication>
#include <QIcon>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    widget w;
    QString dirParh = QDir::currentPath();
    QString path = dirParh+"/../widget/image/logo_tb.ico";

    QIcon appIcon(path);

    w.setWindowIcon(appIcon);
    w.setFixedSize(900, 600);
    w.show();
    return a.exec();
}
