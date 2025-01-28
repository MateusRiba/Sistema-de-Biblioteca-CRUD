#ifndef MENUADMINISTRADORLOGADO_H
#define MENUADMINISTRADORLOGADO_H

#include <QDialog>
#include "gerenciamentolivros.h"
#include "gerenciamentolivrosfisicos.h"

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
    void on_pushButton_5_clicked();

private:
    Ui::MenuAdministradorLogado *ui;
    GerenciamentoLivros *gerenciamentoLivros;
    GerenciamentoLivrosFisicos *gerenciamentoFisicos;
};

#endif // MENUADMINISTRADORLOGADO_H
