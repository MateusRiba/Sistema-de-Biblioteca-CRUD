#ifndef MENULEITORLOGADO_H
#define MENULEITORLOGADO_H

#include <QDialog>
#include "menulivros.h"

namespace Ui {
class MenuLeitorLogado;
}

class MenuLeitorLogado : public QDialog
{
    Q_OBJECT

public:
    explicit MenuLeitorLogado(QWidget *parent = nullptr);
    ~MenuLeitorLogado();

private slots:
    void on_btnVisualizarLivros_clicked();

private:
    Ui::MenuLeitorLogado *ui;
    MenuLivros *menuLivros;
};

#endif // MENULEITORLOGADO_H
