#ifndef DUBKI_H
#define DUBKI_H

#include <QDialog>
#include "registration.h"
#include "dubkimap.h"

namespace Ui {
class Dubki;
}

class Dubki : public QDialog
{
    Q_OBJECT

public:
    explicit Dubki(QWidget *parent = 0);
    ~Dubki();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dubki *ui;
};

#endif // DUBKI_H
