#ifndef MENULIVROS_H
#define MENULIVROS_H

#include <QDialog>
#include <QWidget>
#include "digitalbookslist.h"

namespace Ui {
class MenuLivros;
}

class MenuLivros : public QDialog
{
    Q_OBJECT

public:
    explicit MenuLivros(QWidget *parent = nullptr);
    ~MenuLivros();

private slots:
    void on_btnVisualizarLivros_clicked();

private:
    Ui::MenuLivros *ui;
    DigitalBooksList *digitalBooks;
};

#endif // MENULIVROS_H
