#ifndef FMEDITARLIVROSFISICOS_H
#define FMEDITARLIVROSFISICOS_H

#include <QDialog>

namespace Ui {
class FmEditarLivrosFisicos;
}

class FmEditarLivrosFisicos : public QDialog
{
    Q_OBJECT

public:
    explicit FmEditarLivrosFisicos(QWidget *parent = nullptr, QString isbn=0);
    ~FmEditarLivrosFisicos();

private slots:
    void on_btnCadastroLivro_clicked();

private:
    Ui::FmEditarLivrosFisicos *ui;
};

#endif // FMEDITARLIVROSFISICOS_H
