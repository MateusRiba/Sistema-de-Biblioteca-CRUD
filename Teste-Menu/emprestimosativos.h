#ifndef EMPRESTIMOSATIVOS_H
#define EMPRESTIMOSATIVOS_H
#include <QtSql>
#include <QDialog>
#include <QMessageBox>

namespace Ui {
class EmprestimosAtivos;
}

class EmprestimosAtivos : public QDialog
{
    Q_OBJECT

public:
    explicit EmprestimosAtivos(QWidget *parent = nullptr);
    ~EmprestimosAtivos();
    void listarEmprestimosAtivos();

private:
    Ui::EmprestimosAtivos *ui;
};

#endif // EMPRESTIMOSATIVOS_H
