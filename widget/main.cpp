// #include <QApplication>
// #include "source/Source.cpp"
// #include "pakage/functions.cpp"
// #include "pakage/account _widget.cpp"

// int main(int argc, char *argv[])
// {
//     QApplication app(argc, argv);
//     Source source;
//     Widget window;
//     window.setWindowTitle("Обычное окно");
//     window.resize(350, 100);
//     window.show();

//     return app.exec();
// }

#include "widget.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Widget window;
    window.setWindowTitle("Блокировка и удаление обработчика");
    window.resize(350, 150);
    window.show();
    return app.exec();
}
