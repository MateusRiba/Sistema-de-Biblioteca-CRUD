#include "gerenciamentolivros.h"
#include "ui_gerenciamentolivros.h"
#include "fmeditarlivros.h"
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
            ui->tw_livros->setItem(cont,4,new QTableWidgetItem(query.value(4).toString()));
            ui->tw_livros->setItem(cont,5,new QTableWidgetItem(query.value(5).toString()));
            ui->tw_livros->setRowHeight(cont,20);
            cont++;
        }
        ui->tw_livros->setColumnWidth(0, 200);
        ui->tw_livros->setColumnWidth(1, 150);
        ui->tw_livros->setColumnWidth(2, 100);
        ui->tw_livros->setColumnWidth(3, 150);
        ui->tw_livros->setColumnWidth(4, 150);
        ui->tw_livros->setColumnWidth(5,150);

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

void GerenciamentoLivros::atualizarTabela()
{
    qDebug() << "Atualizando a tabela...";

    // Limpa todas as linhas existentes na tabela
    ui->tw_livros->setRowCount(0);

    // Executa a query para buscar os dados
    QSqlQuery query;
    query.prepare("SELECT * FROM LivrosDigitais");

    if (query.exec()) {
        int cont = 0;

        while (query.next()) {
            qDebug() << "Título:" << query.value("titulo").toString(); // Depuração

            ui->tw_livros->insertRow(cont); // Adiciona uma nova linha
            ui->tw_livros->setItem(cont, 0, new QTableWidgetItem(query.value("titulo").toString()));
            ui->tw_livros->setItem(cont, 1, new QTableWidgetItem(query.value("autor").toString()));
            ui->tw_livros->setItem(cont, 2, new QTableWidgetItem(query.value("isbn").toString()));
            ui->tw_livros->setItem(cont, 3, new QTableWidgetItem(query.value("editora").toString()));
            ui->tw_livros->setItem(cont, 4, new QTableWidgetItem(query.value("ano_publicacao").toString()));
            ui->tw_livros->setItem(cont, 5, new QTableWidgetItem(query.value("valor_diaria").toString()));
            ui->tw_livros->setRowHeight(cont, 20);
            cont++;
        }
    } else {
        QMessageBox::warning(this, "Erro", "Erro ao carregar a tabela: " + query.lastError().text());
    }
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
    QString comando = "DELETE FROM LivrosDigitais WHERE titulo = '" + titulo + "'";

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
    FmAdicionarLivros fmAddLivros(this);
    fmAddLivros.exec();
}


void GerenciamentoLivros::on_btn_editar_clicked()
{
    // Obtém a linha selecionada
    int linha = ui->tw_livros->currentRow();

    // Verifica se uma linha foi selecionada
    if (linha == -1) {
        QMessageBox::warning(this, "Atenção", "Por favor, selecione um livro para editar.");
        return;
    }

    int var_isbn = ui->tw_livros->item(linha, 2)->text().toInt();
    qDebug() << "Valor de var_isbn:" << var_isbn;

    // Abre a janela de edição passando o ISBN
    FmEditarLivros editarLivros(this, var_isbn);
    editarLivros.exec();

    // Atualiza a linha editada na tabela
    QSqlQuery query;
    query.prepare("SELECT * FROM LivrosDigitais WHERE isbn ="+QString::number(var_isbn));

    if (query.exec()) {
        query.first();
        ui->tw_livros->setItem(linha, 0, new QTableWidgetItem(query.value(0).toString())); // Título
        ui->tw_livros->setItem(linha, 1, new QTableWidgetItem(query.value(1).toString())); // Autor
        ui->tw_livros->setItem(linha, 3, new QTableWidgetItem(query.value(3).toString())); // Editora
        ui->tw_livros->setItem(linha, 4, new QTableWidgetItem(query.value(4).toString())); // Ano de publicação
        ui->tw_livros->setItem(linha, 5, new QTableWidgetItem(query.value(5).toString())); // Valor diária
    } else {
        QMessageBox::warning(this, "Erro", "Erro ao consultar o banco de dados para atualizar o livro.");
    }
}


void GerenciamentoLivros::on_btn_pesquisar_clicked()
{
    // Obtém o texto do lineEdit
    QString nomeLivro = ui->lineEdit_pesquisar->text().trimmed();

    if (nomeLivro.isEmpty()) {
        // Se o campo de pesquisa estiver vazio, mostrar todos os livros
        QMessageBox::warning(this, "Aviso", "Digite o nome do livro para pesquisa.");
        atualizarTabela();
        return;
    }

    // Limpa a tabela antes de exibir os novos resultados
    ui->tw_livros->setRowCount(0);

    // Executa a consulta para buscar o livro com o nome correspondente
    QSqlQuery query;
    query.prepare("SELECT * FROM LivrosDigitais WHERE titulo LIKE :titulo");
    query.bindValue(":titulo", "%" + nomeLivro + "%");

    if (query.exec()) {
        int cont = 0;
        while (query.next()) {
            ui->tw_livros->insertRow(cont);
            ui->tw_livros->setItem(cont, 0, new QTableWidgetItem(query.value(0).toString())); // Título
            ui->tw_livros->setItem(cont, 1, new QTableWidgetItem(query.value(1).toString())); // Autor
            ui->tw_livros->setItem(cont, 2, new QTableWidgetItem(query.value(2).toString())); // ISBN
            ui->tw_livros->setItem(cont, 3, new QTableWidgetItem(query.value(3).toString())); // Editora
            ui->tw_livros->setItem(cont, 4, new QTableWidgetItem(query.value(4).toString())); // Ano de publicação
            ui->tw_livros->setItem(cont, 5, new QTableWidgetItem(query.value(5).toString())); // Valor diária
            ui->tw_livros->setRowHeight(cont, 20);
            cont++;
        }
        // Caso não encontre nenhum livro, exibe uma mensagem
        if (cont == 0) {
            QMessageBox::information(this, "Resultado", "Nenhum livro encontrado com o nome \"" + nomeLivro + "\".");
        }
    } else {
        QMessageBox::warning(this, "Erro", "Erro ao realizar a pesquisa: " + query.lastError().text());
    }
}



void GerenciamentoLivros::on_pushButton_atualizar_clicked()
{
    // Limpa todos os itens da tabela para evitar duplicação
    ui->tw_livros->setRowCount(0);

    // Consulta ao banco de dados
    QSqlQuery query;
    query.prepare("SELECT * FROM LivrosDigitais");

    if (query.exec()) {
        int linha = 0; // Índice da linha na tabela

        while (query.next()) {
            // Adiciona uma nova linha na tabela
            ui->tw_livros->insertRow(linha);

            // Preenche os dados na tabela
            ui->tw_livros->setItem(linha, 0, new QTableWidgetItem(query.value(0).toString())); // Título
            ui->tw_livros->setItem(linha, 1, new QTableWidgetItem(query.value(1).toString())); // Autor
            ui->tw_livros->setItem(linha, 2, new QTableWidgetItem(query.value(2).toString())); // ISBN
            ui->tw_livros->setItem(linha, 3, new QTableWidgetItem(query.value(3).toString())); // Editora
            ui->tw_livros->setItem(linha, 4, new QTableWidgetItem(query.value(4).toString())); // Ano de publicação
            ui->tw_livros->setItem(linha, 5, new QTableWidgetItem(query.value(5).toString())); // Valor diária

            linha++; // Incrementa a linha
        }
    } else {
        QMessageBox::warning(this, "Erro", "Erro ao consultar o banco de dados.");
        qDebug() << "Erro no query.exec(): " << query.lastError().text(); // Log para depuração
    }
}


