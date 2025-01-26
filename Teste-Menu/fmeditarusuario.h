#ifndef FMEDITARUSUARIO_H
#define FMEDITARUSUARIO_H

#include <QDialog>

namespace Ui {
class FmEditarUsuario;
}

class FmEditarUsuario : public QDialog
{
    Q_OBJECT

public:
    explicit FmEditarUsuario(QWidget *parent = nullptr, QString cpf=0);
    ~FmEditarUsuario();

private slots:
    void on_btnCadastroLivro_clicked();

private:
    Ui::FmEditarUsuario *ui;
};

#endif // FMEDITARUSUARIO_H
