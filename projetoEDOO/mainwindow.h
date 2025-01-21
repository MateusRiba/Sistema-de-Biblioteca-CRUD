#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gerenciamentodeusuarios.h"
#include "gerenciamentodeemprestimos.h"
#include "gerenciamentolivros.h"


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
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    GerenciamentoDeUsuarios *userG;
    GerenciamentoLivros *livrosG;
    GerenciamentodeEmprestimos *emprestG;
};
#endif // MAINWINDOW_H
