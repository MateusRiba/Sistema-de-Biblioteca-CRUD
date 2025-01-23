#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login.h"
#include "cadastro.h"
#include <QtSql>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnLoginUser_clicked();

    void on_btnCadastroUser_clicked();

    void on_btnLoginAdm_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase bancoDeDados;
    Login *login;
    Cadastro *cadastro;
};
#endif // MAINWINDOW_H
