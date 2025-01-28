#ifndef GERENCIAMENTOLIVROSFISICOS_H
#define GERENCIAMENTOLIVROSFISICOS_H

#include <QDialog>
#include <QtSql>
#include <QMessageBox>
#include "fmeditarlivrosfisicos.h"
#include "fmadicionarlivrosfisicos.h"


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
    void on_btn_pesquisar_clicked();

    void on_btn_adicionar_clicked();

    void on_btn_editar_clicked();

    void on_pushButton_atualizar_clicked();

    void on_btn_excluir_clicked();

private:
    Ui::GerenciamentoLivrosFisicos *ui;
    FmEditarLivrosFisicos *editarLivrosFisicos;
    FmAdicionarLivrosFisicos *addLivrosFisicos;
};

#endif // GERENCIAMENTOLIVROSFISICOS_H
