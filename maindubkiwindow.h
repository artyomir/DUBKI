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

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainDubkiWindow *ui;
};

#endif // MAINDUBKIWINDOW_H
