#ifndef MENULEITORLOGADO_H
#define MENULEITORLOGADO_H

#include <QDialog>
#include "menulivros.h"
#include "emprestimosativos.h"
#include "emprestimosfinalizados.h"
#include "listagememprestimos.h"

namespace Ui {
class MenuLeitorLogado;
}

class MenuLeitorLogado : public QDialog
{
    Q_OBJECT

public:
    explicit MenuLeitorLogado(QWidget *parent = nullptr);
    ~MenuLeitorLogado();

private slots:
    void on_btnVisualizarLivros_clicked();

    void on_pushButton_clicked();

    void on_btnSair_clicked();

private:
    Ui::MenuLeitorLogado *ui;
    MenuLivros *menuLivros;
    EmprestimosAtivos *emprestimosA;
    EmprestimosFinalizados *emprestimosF;
    ListagemEmprestimos *emprestimos;
};

#endif // MENULEITORLOGADO_H
