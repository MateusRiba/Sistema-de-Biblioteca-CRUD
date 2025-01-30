#ifndef FMADICIONAREMPRESTIMO_H
#define FMADICIONAREMPRESTIMO_H

#include <QDialog>

namespace Ui {
class FmAdicionarEmprestimo;
}

class FmAdicionarEmprestimo : public QDialog
{
    Q_OBJECT

public:
    explicit FmAdicionarEmprestimo(QWidget *parent = nullptr);
    ~FmAdicionarEmprestimo();

private slots:
    void on_btnSalvar_clicked();

    void on_btnCancelar_clicked();

private:
    Ui::FmAdicionarEmprestimo *ui;
};

#endif // FMADICIONAREMPRESTIMO_H
