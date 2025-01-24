#ifndef LISTAGEMLIVROSFISICOS_H
#define LISTAGEMLIVROSFISICOS_H

#include <QDialog>
#include <QtSql>
#include <QMessageBox>

namespace Ui {
class ListagemLivrosFisicos;
}

class ListagemLivrosFisicos : public QDialog
{
    Q_OBJECT

public:
    explicit ListagemLivrosFisicos(QWidget *parent = nullptr);
    ~ListagemLivrosFisicos();
    void listarlivros();
private:
    Ui::ListagemLivrosFisicos *ui;
};

#endif // LISTAGEMLIVROSFISICOS_H
