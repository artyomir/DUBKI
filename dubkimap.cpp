#include "dubkimap.h"
#include "ui_dubkimap.h"
#include <QPixmap>

DubkiMap::DubkiMap(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DubkiMap)
{
    ui->setupUi(this);
    QPixmap pixmap;
    pixmap.load("C:/dubki_.png");
    ui->mapix->setPixmap(pixmap);
    setWindowTitle("Map");
}

DubkiMap::~DubkiMap()
{
    delete ui;
}
