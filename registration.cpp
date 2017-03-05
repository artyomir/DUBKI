#include "registration.h"
#include "ui_registration.h"

Registration::Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registration)
{
    setStyleSheet("background: green;");
    ui->setupUi(this);
    setWindowTitle("Registration");
}

Registration::~Registration()
{
    delete ui;
}
