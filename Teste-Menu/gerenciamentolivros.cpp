#include "gerenciamentolivros.h"
#include "ui_gerenciamentolivros.h"
#include <QtSql>
#include <QMessageBox>

GerenciamentoLivros::GerenciamentoLivros(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GerenciamentoLivros)
{
    ui->setupUi(this);

    QSqlQuery query;
    query.prepare("select * from LivrosDigitais");
    if(query.exec()){
        int cont=0;
        ui->tw_livros->setColumnCount(6);
        while(query.next()){
            ui->tw_livros->insertRow(cont);
            ui->tw_livros->setItem(cont,0,new QTableWidgetItem(query.value(0).toString()));
            ui->tw_livros->setItem(cont,1,new QTableWidgetItem(query.value(1).toString()));
            ui->tw_livros->setItem(cont,2,new QTableWidgetItem(query.value(2).toString()));
            ui->tw_livros->setItem(cont,3,new QTableWidgetItem(query.value(3).toString()));
            ui->tw_livros->setItem(cont,3,new QTableWidgetItem(query.value(4).toString()));
            ui->tw_livros->setItem(cont,3,new QTableWidgetItem(query.value(5).toString()));
            ui->tw_livros->setRowHeight(cont,20);
            cont++;
        }
        ui->tw_livros->setColumnWidth(0, 200);
        ui->tw_livros->setColumnWidth(1, 150);
        ui->tw_livros->setColumnWidth(2, 100);
        ui->tw_livros->setColumnWidth(3, 150);
        ui->tw_livros->setColumnWidth(4, 100);
        ui->tw_livros->setColumnWidth(5,50);

        QStringList cabecalhos = {"Título","Autor","ISBN","Editora","Ano de Publicação","Valor Diária"};
        ui->tw_livros->setHorizontalHeaderLabels(cabecalhos);
        ui->tw_livros->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tw_livros->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tw_livros->setStyleSheet("QTableView {selection-background-color:blue}");
    }else{
        QMessageBox::warning(this,"Error","Erro ao pesquisar");
    }
}

GerenciamentoLivros::~GerenciamentoLivros()
{
    delete ui;
}

void GerenciamentoLivros::on_btn_excluir_clicked()
{
    int linha = ui->tw_livros->currentRow(); // Obtém a linha selecionada

    if (linha == -1) {
        QMessageBox::warning(this, "Atenção", "Por favor, selecione um livro para excluir.");
        return;
    }

    // Obtém o valor da coluna "Título" (coluna 0 na tabela)
    QString titulo = ui->tw_livros->item(linha, 0)->text();

    // Verifica se o título está vazio (evita consultas inválidas)
    if (titulo.isEmpty()) {
        QMessageBox::warning(this, "Erro", "Não foi possível identificar o título do livro selecionado.");
        return;
    }

    QSqlQuery query;
    QString comando = "DELETE FROM LivrosDigitais WHERE Título = '" + titulo + "'";

    // Executa o comando SQL
    if (query.exec(comando)) {
        // Remove a linha da tabela
        ui->tw_livros->removeRow(linha);
        QMessageBox::information(this, "Sucesso", "Livro excluído com sucesso.");
    } else {
        QMessageBox::warning(this, "Erro", "Erro ao excluir livro. Verifique o banco de dados.");
    }
}


void GerenciamentoLivros::on_btn_adicionar_clicked()
{
    this->close();
    FmAdicionarLivros fmAddLivros;
    fmAddLivros.exec();
}

