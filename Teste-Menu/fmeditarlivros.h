#ifndef FMEDITARLIVROS_H
#define FMEDITARLIVROS_H

#include <QDialog>

namespace Ui {
class FmEditarLivros;
}

class FmEditarLivros : public QDialog
{
    Q_OBJECT

public:
    explicit FmEditarLivros(QWidget *parent = nullptr, int isbn=0);
    ~FmEditarLivros();

private slots:
    void on_btnCadastroLivro_clicked();

private:
    Ui::FmEditarLivros *ui;
};

#endif // FMEDITARLIVROS_H
