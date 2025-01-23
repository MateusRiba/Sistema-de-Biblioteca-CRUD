#ifndef DIGITALBOOKSLIST_H
#define DIGITALBOOKSLIST_H

#include <QWidget>

namespace Ui {
class DigitalBooksList;
}

class DigitalBooksList : public QWidget
{
    Q_OBJECT

public:
    explicit DigitalBooksList(QWidget *parent = nullptr);
    ~DigitalBooksList();

private:
    Ui::DigitalBooksList *ui;
};

#endif // DIGITALBOOKSLIST_H
