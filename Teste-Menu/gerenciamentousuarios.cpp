#include "gerenciamentousuarios.h"
#include "ui_gerenciamentousuarios.h"

gerenciamentousuarios::gerenciamentousuarios(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::gerenciamentousuarios)
{
    ui->setupUi(this);
}

gerenciamentousuarios::~gerenciamentousuarios()
{
    delete ui;
}
