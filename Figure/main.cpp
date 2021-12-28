#include "QtWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtWindow Window;
    Window.show();
    return a.exec();
}
