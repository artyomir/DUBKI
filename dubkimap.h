#ifndef DUBKIMAP_H
#define DUBKIMAP_H

#include <QDialog>
#include <QPixmap>

namespace Ui {
class DubkiMap;
}

class DubkiMap : public QDialog
{
    Q_OBJECT

public:
    explicit DubkiMap(QWidget *parent = 0);
    ~DubkiMap();

private:
    Ui::DubkiMap *ui;
};

#endif // DUBKIMAP_H
