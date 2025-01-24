#ifndef DIGITALBOOKSLIST_H
#define DIGITALBOOKSLIST_H
#include <QtSql>
#include <QWidget>
#include <QMessageBox>
namespace Ui {
class DigitalBooksList;
}

class DigitalBooksList : public QWidget
{
    Q_OBJECT

public:
    explicit DigitalBooksList(QWidget *parent = nullptr);
    ~DigitalBooksList();
    void carregarlivros();

private slots:

private:
    Ui::DigitalBooksList *ui;
};

#endif // DIGITALBOOKSLIST_H
