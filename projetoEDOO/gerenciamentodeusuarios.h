#ifndef GERENCIAMENTODEUSUARIOS_H
#define GERENCIAMENTODEUSUARIOS_H

#include <QDialog>

namespace Ui {
class GerenciamentoDeUsuarios;
}

class GerenciamentoDeUsuarios : public QDialog
{
    Q_OBJECT

public:
    explicit GerenciamentoDeUsuarios(QWidget *parent = nullptr);
    ~GerenciamentoDeUsuarios();

private:
    Ui::GerenciamentoDeUsuarios *ui;
};

#endif // GERENCIAMENTODEUSUARIOS_H
