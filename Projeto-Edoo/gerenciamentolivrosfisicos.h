#ifndef GERENCIAMENTOLIVROSFISICOS_H
#define GERENCIAMENTOLIVROSFISICOS_H

#include <QDialog>
#include "fmadicionarlivrosfisicos.h"
#include "fmeditarlivrosfisicos.h"
namespace Ui {
class GerenciamentoLivrosFisicos;
}

class GerenciamentoLivrosFisicos : public QDialog
{
    Q_OBJECT

public:
    explicit GerenciamentoLivrosFisicos(QWidget *parent = nullptr);
    ~GerenciamentoLivrosFisicos();

    void atualizarTabela();

private slots:
    void on_btn_adicionar_lf_clicked();

    void on_btn_excluir_lf_clicked();

    void on_btn_editar_lf_clicked();

    void on_pushButton_atualizar_lf_clicked();

    void on_btn_pesquisar_lf_clicked();

private:
    Ui::GerenciamentoLivrosFisicos *ui;
    FmAdicionarLivrosFisicos *fmAddFisicos;
    FmEditarLivrosFisicos *fmEditarFisicos;
};

#endif // GERENCIAMENTOLIVROSFISICOS_H
