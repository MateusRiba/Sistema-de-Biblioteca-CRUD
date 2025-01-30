#ifndef GERENCIAMENTOUSUARIOS_H
#define GERENCIAMENTOUSUARIOS_H

#include <QDialog>
#include "fmeditarusuario.h"

namespace Ui {
class gerenciamentousuarios;
}

class gerenciamentousuarios : public QDialog
{
    Q_OBJECT

public:
    explicit gerenciamentousuarios(QWidget *parent = nullptr);
    ~gerenciamentousuarios();

    void atualizarTabela();

private slots:
    void on_btn_excluir_user_clicked();

    void on_btn_editar_user_clicked();

    void on_btn_atualizar_user_clicked();

    void on_btn_pesquisar_user_clicked();

private:
    Ui::gerenciamentousuarios *ui;
    FmEditarUsuario *editarUser;
};

#endif // GERENCIAMENTOUSUARIOS_H
