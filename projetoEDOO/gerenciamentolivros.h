#ifndef GERENCIAMENTOLIVROS_H
#define GERENCIAMENTOLIVROS_H

#include <QDialog>

namespace Ui {
class GerenciamentoLivros;
}

class GerenciamentoLivros : public QDialog
{
    Q_OBJECT

public:
    explicit GerenciamentoLivros(QWidget *parent = nullptr);
    ~GerenciamentoLivros();

private:
    Ui::GerenciamentoLivros *ui;
};

#endif // GERENCIAMENTOLIVROS_H
