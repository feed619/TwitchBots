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
#include "source/api.h"


int main(int argc, char *argv[])
{
    Api ap;
    QApplication app(argc, argv);
    Widget window;
    window.setWindowTitle("TwitchBots");
    window.resize(600, 800);
    window.show();
    return app.exec();
}
