#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "menuleitorlogado.h"
#include "menuadministradorlogado.h"
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_btnEntrar_clicked();

private:
    Ui::Login *ui;
    MenuLeitorLogado *menuLeitor;
    MenuAdministradorLogado *menuAdm;
};

#endif // LOGIN_H
