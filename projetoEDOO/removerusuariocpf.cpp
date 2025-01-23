#include "removerusuariocpf.h"
#include "ui_removerusuariocpf.h"
#include <Qfile>
#include <QMessageBox>

RemoverUsuarioCPF::RemoverUsuarioCPF(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RemoverUsuarioCPF)
{
    ui->setupUi(this);
    connect(ui->tableWidget, &QTableWidget::cellClicked, this, &RemoverUsuarioCPF::on_tableWidget_cellClicked);
    carregarUsuarios();
}

RemoverUsuarioCPF::~RemoverUsuarioCPF()
{
    delete ui;
}

void RemoverUsuarioCPF::carregarUsuarios() {
    QFile file("C:\\Users\\parac\\OneDrive\\Documentos\\Projetos\\Sistema-de-Informa-o-Bibliotec-rio\\data\\usuarios.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Erro", "Não foi possível abrir o arquivo!");
        return;
    }

    QTextStream in(&file);

    // Configurar cabeçalhos do QTableWidget (você pode ajustar os nomes das colunas)
    QStringList headers = {"Tipo", "Nome", "CPF", "Endereço", "Telefone", "Senha"};
    ui->tableWidget->setColumnCount(headers.size());
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    // Limpar as linhas existentes no QTableWidget
    ui->tableWidget->setRowCount(0);

    int row = 0;

    // Ler o arquivo linha por linha e adicionar ao QTableWidget
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList dados = line.split(";"); // Dividir a linha em colunas pelo delimitador ";"

        if (dados.size() >= headers.size()) { // Verificar se a linha tem todas as colunas
            ui->tableWidget->insertRow(row); // Adicionar uma nova linha

            // Preencher cada célula da linha com os dados do arquivo
            for (int col = 0; col < headers.size(); ++col) {
                ui->tableWidget->setItem(row, col, new QTableWidgetItem(dados[col]));
            }
            row++;
        }
    }

    file.close();
}


void RemoverUsuarioCPF::on_tableWidget_cellClicked(int row, int) {
    QString cpfSelecionado = ui->tableWidget->item(row, 2)->text(); // Assumindo que o CPF está na coluna 2
    QMessageBox::information(this, "CPF Selecionado", "CPF: " + cpfSelecionado);

    // Salvar o CPF selecionado na variável da classe
    cpfParaRemover = cpfSelecionado;
}


