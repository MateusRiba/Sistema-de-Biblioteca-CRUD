#ifndef GERENCIAMENTOUSUARIOS_H
#define GERENCIAMENTOUSUARIOS_H

#include <QDialog>

namespace Ui {
class gerenciamentousuarios;
}

class gerenciamentousuarios : public QDialog
{
    Q_OBJECT

public:
    explicit gerenciamentousuarios(QWidget *parent = nullptr);
    ~gerenciamentousuarios();

private:
    Ui::gerenciamentousuarios *ui;
};

#endif // GERENCIAMENTOUSUARIOS_H
