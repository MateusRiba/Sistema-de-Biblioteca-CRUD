#ifndef REMOVERUSUARIOCPF_H
#define REMOVERUSUARIOCPF_H

#include <QDialog>
#include <QTableWidget>
#include <QString>

namespace Ui {
class RemoverUsuarioCPF;
}

class RemoverUsuarioCPF : public QDialog
{
    Q_OBJECT

public:
    explicit RemoverUsuarioCPF(QWidget *parent = nullptr);
    ~RemoverUsuarioCPF();
    void carregarUsuarios();

private slots:
    void on_tableWidget_cellClicked(int row, int column);


    void on_btnRemover_clicked();

private:
    Ui::RemoverUsuarioCPF *ui;
    QString cpfParaRemover;
};

#endif // REMOVERUSUARIOCPF_H

