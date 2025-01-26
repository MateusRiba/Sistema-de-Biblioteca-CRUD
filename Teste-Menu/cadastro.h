#ifndef CADASTRO_H
#define CADASTRO_H

#include <QDialog>
#include <QtSql>
#include "login.h"

namespace Ui {
class Cadastro;
}

class Cadastro : public QDialog
{
    Q_OBJECT

public:
    explicit Cadastro(QWidget *parent = nullptr);
    ~Cadastro();

private slots:
    void on_btnCadastro_clicked();

    void on_btn_cancelar_clicked();

private:
    Ui::Cadastro *ui;
    Login *login;
};

#endif // CADASTRO_H
