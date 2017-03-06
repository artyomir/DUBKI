#include "maindubkiwindow.h"
#include "ui_maindubkiwindow.h"
#include <QString>
#include <QLineEdit>
#include <QFile>
#include <QTextStream>
#include <QDir>

MainDubkiWindow::MainDubkiWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainDubkiWindow)
{
    //setStyleSheet("background: green;");
    ui->setupUi(this);
    ui->buttonEnt->setEnabled(false);
    QRegExp exp("[a-zA-Z]{3,5}");
    ui->login->setValidator(new QRegExpValidator(exp, this));
    ui->password->setValidator(new QRegExpValidator(exp, this));
    connect(ui->login, SIGNAL(textChanged(QString)),this, SLOT(VhodEnabled()));
    connect(ui->password, SIGNAL(textChanged(QString)),this, SLOT(VhodEnabled()));
    setWindowTitle("DUBKI");
}

bool MainDubkiWindow::CheckValid(){
    if (ui->login->hasAcceptableInput() && ui->password->hasAcceptableInput()){
        return true;
    } else return false;
}

MainDubkiWindow::~MainDubkiWindow()
{
    delete ui;
}

void MainDubkiWindow::on_buttonEnt_clicked()
{
    QFile mFile("C:/Users/Artyom Mirabyan/Desktop/text.txt");
    if(!mFile.open(QFile::ReadOnly | QFile::Text)){
        ui->info->setText("<font color=red>Ошибка, попробуйте позже.</font>");
        return;
    }
    QTextStream stream(&mFile);
    QString students = stream.readAll();
    mFile.flush();
    mFile.close();
    int i = 0;
    while (i < students.size()){
        if(students[i] == ':'){
            QString stnick; int j = 0; ++i;
            while (students[i] != '*'){
                stnick[j] = students[i];
                ++j; ++i;}
            if (stnick == ui->login->text()){
                ++i; int j = 0; QString stpass;
                while(students[i] != '\n'){
                    stpass[j] = students[i];
                    ++j; ++i;
                }
                if (stpass == ui->password->text()){
                    DubkiMap w;
                    w.show();
                    w.exec();
                } else {
                    ui->info->setText("<font color=red>Неправильно введен логин или пароль.</font>");
                    return;}
            }
        }
        i++;
    }
    ui->info->setText("<font color=red>Неправильно введен логин или пароль.</font>");
    return;
}

void MainDubkiWindow::VhodEnabled(){
    ui->buttonEnt->setEnabled(CheckValid());
}

void MainDubkiWindow::on_buttonReg_clicked()
{
    Registration w;
    w.show();
    w.exec();
}
