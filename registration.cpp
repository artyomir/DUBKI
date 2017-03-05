#include "registration.h"
#include "ui_registration.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

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

void Registration::on_pushButton_clicked()
{
    QFile mFile("C:/Users/Artyom Mirabyan/Desktop/text.txt");
    if(!mFile.open(QFile::WriteOnly | QFile::Append | QFile::Text)){
        return;
    }
    QTextStream stream(&mFile);

    stream << ':' + ui->login->text() + '*' + ui->passw->text() + '\0';
    mFile.close();
    close();
}
