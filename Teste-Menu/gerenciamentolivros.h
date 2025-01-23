#ifndef GERENCIAMENTOLIVROS_H
#define GERENCIAMENTOLIVROS_H

#include <QDialog>
#include "fmadicionarlivros.h"


namespace Ui {
class GerenciamentoLivros;
}

class GerenciamentoLivros : public QDialog
{
    Q_OBJECT

public:
    explicit GerenciamentoLivros(QWidget *parent = nullptr);
    ~GerenciamentoLivros();

private slots:
    void on_btn_excluir_clicked();

    void on_btn_adicionar_clicked();

private:
    Ui::GerenciamentoLivros *ui;
    FmAdicionarLivros *fmAddLivros;
};

#endif // GERENCIAMENTOLIVROS_H
