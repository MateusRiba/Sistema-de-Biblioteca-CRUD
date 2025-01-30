#ifndef FMEDITAREMPRESTIMO_H
#define FMEDITAREMPRESTIMO_H

#include <QDialog>

namespace Ui {
class FmEditarEmprestimo;
}

class FmEditarEmprestimo : public QDialog
{
    Q_OBJECT

public:
    explicit FmEditarEmprestimo(QWidget *parent = nullptr, int idEmprestimo = -1);
    ~FmEditarEmprestimo();

private slots:

    void on_btnSalvarEmprestimo_clicked();

    void on_btnCancelarEmprestimo_clicked();

private:
    Ui::FmEditarEmprestimo *ui;
    int id_emprestimo; // ID do empréstimo a ser editado
    void carregarDadosEmprestimo(); // Método para carregar os dados do empréstimo
};

#endif // FMEDITAREMPRESTIMO_H
