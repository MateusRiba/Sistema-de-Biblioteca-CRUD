#ifndef LISTAGEMEMPRESTIMOS_H
#define LISTAGEMEMPRESTIMOS_H

#include <QDialog>

namespace Ui {
class ListagemEmprestimos;
}

class ListagemEmprestimos : public QDialog
{
    Q_OBJECT

public:
    explicit ListagemEmprestimos(QWidget *parent = nullptr);
    ~ListagemEmprestimos();

private:
    Ui::ListagemEmprestimos *ui;
    void carregarEmprestimos(); // Método para carregar os empréstimos do usuário logado
};

#endif // LISTAGEMEMPRESTIMOS_H
