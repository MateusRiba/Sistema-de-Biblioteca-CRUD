#ifndef EMPRESTIMOSFINALIZADOS_H
#define EMPRESTIMOSFINALIZADOS_H

#include <QDialog>
#include <QtSql>
#include <QMessageBox>

namespace Ui {
class EmprestimosFinalizados;
}

class EmprestimosFinalizados : public QDialog
{
    Q_OBJECT

public:
    explicit EmprestimosFinalizados(QWidget *parent = nullptr);
    ~EmprestimosFinalizados();
    void listarEmprestimosFinalizados();

private:
    Ui::EmprestimosFinalizados *ui;
};

#endif // EMPRESTIMOSFINALIZADOS_H
