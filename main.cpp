#include "maindubkiwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainDubkiWindow w;
    w.show();

    return a.exec();
}
