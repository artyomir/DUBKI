#include "maindubkiwindow.h"
#include "ui_maindubkiwindow.h"

MainDubkiWindow::MainDubkiWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainDubkiWindow)
{
    setStyleSheet("background: green;");
    ui->setupUi(this);
}

MainDubkiWindow::~MainDubkiWindow()
{
    delete ui;
}

void MainDubkiWindow::on_pushButton_3_clicked()
{
    DubkiMap w;
    w.show();
    w.exec();
}

void MainDubkiWindow::on_pushButton_4_clicked()
{
    Registration w;
    w.show();
    w.exec();
}
