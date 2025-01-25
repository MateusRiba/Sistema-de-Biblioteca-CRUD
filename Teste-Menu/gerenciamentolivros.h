#ifndef GERENCIAMENTOLIVROS_H
#define GERENCIAMENTOLIVROS_H

#include <QDialog>
#include "fmadicionarlivros.h"
#include "fmeditarlivros.h"


namespace Ui {
class GerenciamentoLivros;
}

class GerenciamentoLivros : public QDialog
{
    Q_OBJECT

public:
    explicit GerenciamentoLivros(QWidget *parent = nullptr);
    ~GerenciamentoLivros();

    void atualizarTabela();

private slots:
    void on_btn_excluir_clicked();

    void on_btn_adicionar_clicked();

    void on_btn_editar_clicked();

    void on_btn_pesquisar_clicked();


    void on_pushButton_atualizar_clicked();

private:
    Ui::GerenciamentoLivros *ui;
    FmAdicionarLivros *fmAddLivros;
    FmEditarLivros *editarLivros;


};

#endif // GERENCIAMENTOLIVROS_H
