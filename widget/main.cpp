#include "source/Source.cpp"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Source source;
    return app.exec();
}
