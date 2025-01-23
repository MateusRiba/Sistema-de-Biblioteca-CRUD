#ifndef GERENCIAMENTODEUSUARIOS_H
#define GERENCIAMENTODEUSUARIOS_H

#include <QDialog>
#include "cadastrousuarioadm.h"
#include "removerusuariocpf.h"
namespace Ui {
class GerenciamentoDeUsuarios;
}

class GerenciamentoDeUsuarios : public QDialog
{
    Q_OBJECT

public:
    explicit GerenciamentoDeUsuarios(QWidget *parent = nullptr);
    ~GerenciamentoDeUsuarios();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::GerenciamentoDeUsuarios *ui;
    CadastroUsuarioadm *cadastroU;
    RemoverUsuarioCPF *removerU;
};

#endif // GERENCIAMENTODEUSUARIOS_H
