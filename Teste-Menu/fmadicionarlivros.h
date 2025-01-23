#ifndef FMADICIONARLIVROS_H
#define FMADICIONARLIVROS_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class FmAdicionarLivros;
}

class FmAdicionarLivros : public QDialog
{
    Q_OBJECT

public:
    explicit FmAdicionarLivros(QWidget *parent = nullptr);
    ~FmAdicionarLivros();

private slots:
    void on_commandLinkButton_clicked();

    void on_btnCadastroLivro_clicked();

private:
    Ui::FmAdicionarLivros *ui;
};

#endif // FMADICIONARLIVROS_H
