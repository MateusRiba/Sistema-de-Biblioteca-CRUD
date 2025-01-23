#ifndef CADASTROUSUARIOADM_H
#define CADASTROUSUARIOADM_H

#include <QDialog>

namespace Ui {
class CadastroUsuarioadm;
}

class CadastroUsuarioadm : public QDialog
{
    Q_OBJECT

public:
    explicit CadastroUsuarioadm(QWidget *parent = nullptr);
    ~CadastroUsuarioadm();

private slots:
    void on_btn_cadastrar_clicked();

private:
    Ui::CadastroUsuarioadm *ui;
};

#endif // CADASTROUSUARIOADM_H
