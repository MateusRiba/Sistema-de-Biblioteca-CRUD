#include "digitalbookslist.h"
#include "ui_digitalbookslist.h"

DigitalBooksList::DigitalBooksList(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DigitalBooksList)
{
    ui->setupUi(this);
}

DigitalBooksList::~DigitalBooksList()
{
    delete ui;
}
