#include "dubki.h"
#include "ui_dubki.h"

Dubki::Dubki(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dubki)
{
    ui->setupUi(this);
    setWindowTitle("DUBKI");
}

Dubki::~Dubki()
{
    delete ui;
}

void Dubki::on_pushButton_clicked()
{
    Registration w;
    w.show();
    w.exec();
}

void Dubki::on_pushButton_2_clicked()
{
    DubkiMap w;
    w.show();
    w.exec();
}
