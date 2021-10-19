#include "biskuvisatis.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BiskuviSatis w;
    w.show();

    return a.exec();
}
