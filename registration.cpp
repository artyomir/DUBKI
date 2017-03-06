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
    ui->pushButton->setEnabled(false);
    QRegExp exp("[a-zA-Z]{3,5}");
    ui->login->setValidator(new QRegExpValidator(exp, this));
    ui->passw->setValidator(new QRegExpValidator(exp, this));
    ui->name->setValidator(new QRegExpValidator(exp, this));
    ui->secname->setValidator(new QRegExpValidator(exp, this));
    ui->passw2->setValidator(new QRegExpValidator(exp, this));
    connect(ui->name, SIGNAL(textChanged(QString)), this, SLOT(RegEnabled()));
    connect(ui->secname, SIGNAL(textChanged(QString)), this, SLOT(RegEnabled()));
    connect(ui->login, SIGNAL(textChanged(QString)), this, SLOT(RegEnabled()));
    connect(ui->passw, SIGNAL(textChanged(QString)), this, SLOT(RegEnabled()));
    connect(ui->passw2, SIGNAL(textChanged(QString)), this, SLOT(RegEnabled()));
}

Registration::~Registration()
{
    delete ui;
}

void Registration::RegEnabled(){
    ui->pushButton->setEnabled(CheckValid());
}

bool Registration::CheckValid(){
    if (ui->login->hasAcceptableInput() && ui->passw->hasAcceptableInput() && ui->passw2->hasAcceptableInput()){
        if (ui->secname->hasAcceptableInput() && ui->name->hasAcceptableInput()){
            return true;
        } else return false;
    } else return false;
}

bool Registration::CheckLog(){
    if (ui->passw2->text() == ui->passw->text()){
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
    } else{
        ui->ErrorInf->setText("<font color=red>Ошибка с вводом пароля.</font>");
        return false;
    }
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
    ui->pushButton->setEnabled(false);
    mFile.close();
    }
}
