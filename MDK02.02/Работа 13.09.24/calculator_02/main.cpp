#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("calculator");
    w.resize(300,500);
    w.setFixedSize(430,200);
    w.show();
    return a.exec();
}
