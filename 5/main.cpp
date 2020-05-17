#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle("Пирамида изображений.");
    w.resize(500,350);
    w.show();

    return a.exec();
}
