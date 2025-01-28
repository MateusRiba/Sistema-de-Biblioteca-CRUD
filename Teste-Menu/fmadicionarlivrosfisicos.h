#ifndef FMADICIONARLIVROSFISICOS_H
#define FMADICIONARLIVROSFISICOS_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class FmAdicionarLivrosFisicos;
}

class FmAdicionarLivrosFisicos : public QDialog
{
    Q_OBJECT

public:
    explicit FmAdicionarLivrosFisicos(QWidget *parent = nullptr);
    ~FmAdicionarLivrosFisicos();

private slots:
    void on_btnCadastroLivro_2_clicked();

private:
    Ui::FmAdicionarLivrosFisicos *ui;
};

#endif // FMADICIONARLIVROSFISICOS_H
