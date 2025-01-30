#include "listagemlivrosfisicos.h"
#include "ui_listagemlivrosfisicos.h"

ListagemLivrosFisicos::ListagemLivrosFisicos(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ListagemLivrosFisicos)
{
    ui->setupUi(this);
    listarlivros();
}

void ListagemLivrosFisicos::listarlivros(){

    QSqlQuery query;
    query.prepare("SELECT Titulo, Autor FROM LivrosFisicos");

    if (!query.exec()) {
        qDebug() << "Erro ao executar a consulta:" << query.lastError().text();
        QMessageBox::critical(this, "Erro", "Erro ao consultar o banco de dados: " + query.lastError().text());
        return;
    }

    // Verificar se o banco de dados está aberto
    if (!QSqlDatabase::database().isOpen()) {
        qDebug() << "Banco de dados não está aberto!";
        QMessageBox::critical(this, "Erro", "Banco de dados não conectado.");
        return;
    }

    // Configurar o QTableWidget
    ui->tableWidget->setRowCount(0); // Limpa as linhas existentes
    ui->tableWidget->setColumnCount(2); // Ajustado para duas colunas
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Titulo" << "Autor");

    int row = 0;

    // Preencher os dados no QTableWidget
    while (query.next()) {
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value("Titulo").toString()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value("Autor").toString()));
        row++;
    }

    if (row == 0) {
        QMessageBox::information(this, "Informação", "Nenhum livro encontrado.");
    }
}

ListagemLivrosFisicos::~ListagemLivrosFisicos()
{
    delete ui;
}
