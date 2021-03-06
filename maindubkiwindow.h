#ifndef MAINDUBKIWINDOW_H
#define MAINDUBKIWINDOW_H

#include <QMainWindow>
#include "registration.h"
#include "dubkimap.h"

namespace Ui {
class MainDubkiWindow;
}

class MainDubkiWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainDubkiWindow(QWidget *parent = 0);
    ~MainDubkiWindow();

    bool CheckValid();

private slots:
    void on_buttonEnt_clicked();

    void on_buttonReg_clicked();

    void VhodEnabled();

private:
    Ui::MainDubkiWindow *ui;
};

#endif // MAINDUBKIWINDOW_H
