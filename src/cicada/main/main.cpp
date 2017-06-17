#include <QApplication>
#include "cicadamainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CicadaMainWindow w;
    w.show();
    
    return a.exec();
}
