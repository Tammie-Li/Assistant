#include "framelesswidget/framelesswidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FramelessWidget w;
    w.setWindowTitle("脑电实验助手");
    w.resize(1080, 400);
    w.show();
    w.move ((1920 - w.width())/2,(1080 - w.height())/2);
    return a.exec();
}
