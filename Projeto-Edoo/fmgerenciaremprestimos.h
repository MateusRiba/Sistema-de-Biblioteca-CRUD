#ifndef FMGERENCIAREMPRESTIMOS_H
#define FMGERENCIAREMPRESTIMOS_H

#include <QDialog>
#include "fmadicionaremprestimo.h"
#include "fmeditaremprestimo.h"

namespace Ui {
class FmGerenciarEmprestimos;
}

class FmGerenciarEmprestimos : public QDialog
{
    Q_OBJECT

public:
    explicit FmGerenciarEmprestimos(QWidget *parent = nullptr);
    ~FmGerenciarEmprestimos();

private slots:
    void on_btn_add_emprestimos_clicked();

    void on_btn_excluir_emprestimos_clicked();

    void on_btn_editar_emprestimos_clicked();

    void on_btn_atualizar_emprestimos_clicked();

    void on_btn_pesquisar_emprestimo_clicked();

    void on_comboBox_emprestimo_currentIndexChanged();

private:
    Ui::FmGerenciarEmprestimos *ui;
    FmAdicionarEmprestimo *fmAddEmprestimo;
    FmEditarEmprestimo *fmEditarEmprestimo;
};

#endif // FMGERENCIAREMPRESTIMOS_H
