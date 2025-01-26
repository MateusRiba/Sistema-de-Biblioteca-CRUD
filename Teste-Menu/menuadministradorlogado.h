#ifndef MENUADMINISTRADORLOGADO_H
#define MENUADMINISTRADORLOGADO_H

#include <QDialog>
#include "gerenciamentolivros.h"
#include "gerenciamentousuarios.h"
#include "fmgerenciaremprestimos.h"

namespace Ui {
class MenuAdministradorLogado;
}

class MenuAdministradorLogado : public QDialog
{
    Q_OBJECT

public:
    explicit MenuAdministradorLogado(QWidget *parent = nullptr);
    ~MenuAdministradorLogado();

private slots:
    void on_pushButton_3_clicked();
    void on_btn_user_menu_clicked();

    void on_btn_Emprestimos_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MenuAdministradorLogado *ui;
    GerenciamentoLivros *gerenciamentoLivros;
    gerenciamentousuarios *gerenciamentoUsers;
    FmGerenciarEmprestimos *fmGerenciarEmprestimo;
};

#endif // MENUADMINISTRADORLOGADO_H
