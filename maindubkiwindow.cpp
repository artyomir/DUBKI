#include "maindubkiwindow.h"
#include "ui_maindubkiwindow.h"
#include <QString>
#include <QLineEdit>

MainDubkiWindow::MainDubkiWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainDubkiWindow)
{
    //setStyleSheet("background: green;");
    ui->setupUi(this);
    ui->buttonEnt->setEnabled(0);
    QRegExp exp("[a-zA-z]{1,40}[0-9]{0,10}");
    ui->login->setValidator(new QRegExpValidator(exp, this));
    ui->password->setValidator(new QRegExpValidator(exp, this));
    connect(ui->login, SIGNAL(textChanged(QString)),this, SLOT(VhodEnabled()));
    setWindowTitle("DUBKI");
}

MainDubkiWindow::~MainDubkiWindow()
{
    delete ui;
}

void MainDubkiWindow::on_buttonEnt_clicked()
{
    DubkiMap w;
    w.show();
    w.exec();
}

void MainDubkiWindow::VhodEnabled(){
    ui->buttonEnt->setEnabled(ui->login->hasAcceptableInput());
}

void MainDubkiWindow::on_buttonReg_clicked()
{
    Registration w;
    w.show();
    w.exec();
}
