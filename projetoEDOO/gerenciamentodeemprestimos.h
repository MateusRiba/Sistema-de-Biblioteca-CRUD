#ifndef GERENCIAMENTODEEMPRESTIMOS_H
#define GERENCIAMENTODEEMPRESTIMOS_H

#include <QDialog>

namespace Ui {
class GerenciamentodeEmprestimos;
}

class GerenciamentodeEmprestimos : public QDialog
{
    Q_OBJECT

public:
    explicit GerenciamentodeEmprestimos(QWidget *parent = nullptr);
    ~GerenciamentodeEmprestimos();

private:
    Ui::GerenciamentodeEmprestimos *ui;
};

#endif // GERENCIAMENTODEEMPRESTIMOS_H
