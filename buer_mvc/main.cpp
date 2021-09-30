#include "buer_mvc.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    buer_mvc w;

    w.resize(960, 640);
    w.setWindowTitle(QString::fromUtf8("Qt/C++架构工程demo版本V1.0.0"));
    w.setStyleSheet("font: bold 12px;");

    w.show();
    return a.exec();
}
