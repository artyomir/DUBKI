#include "registration.h"
#include "ui_registration.h"
#include <QFile>
#include <QTextStream>
#include <QDir>

Registration::Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
    setWindowTitle("Registration");
}

Registration::~Registration()
{
    delete ui;
}

bool Registration::CheckLog(){
    QFile mFile("C:/Users/Artyom Mirabyan/Desktop/text.txt");
    if(!mFile.open(QFile::ReadOnly | QFile::Text)){
        ui->ErrorInf->setText("<font color=red>Ошибка регистрации.</font>");
        return false;
    }
    QTextStream stream(&mFile);
    QString students = stream.readAll();
    mFile.flush();
    mFile.close();

    for (int i = 0; i < students.size(); ++i){
        if (students[i] == ':'){
            ++i; QString chlog; int j = 0;
            while (students[i] != '*'){
                chlog[j] = students[i];
                ++j;
                ++i;
            }
            if (ui->login->text() == chlog){
                ui->ErrorInf->setText("<font color=red>Пользователь с таким логином уже существует!</font>");
                return false;
            }
        }
    }
    return true;
}

void Registration::on_pushButton_clicked()
{
    if (CheckLog()){
    QFile mFile("C:/Users/Artyom Mirabyan/Desktop/text.txt");
    if(!mFile.open(QFile::WriteOnly | QFile::Append | QFile::Text)){
        ui->ErrorInf->setText("<font color=red>Ошибка регистрации.</font>");
        return;
    }
    QTextStream stream(&mFile);
    ui->ErrorInf->setText("<font color=green>Регистрация прошла успешно!</font>");
    stream << ':' + ui->login->text() + '*' + ui->passw->text() + '\n';
    ui->pushButton->setEnabled(0);
    mFile.close();
    }
}
