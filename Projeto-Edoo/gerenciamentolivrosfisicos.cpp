#include "gerenciamentolivrosfisicos.h"
#include "ui_gerenciamentolivrosfisicos.h"
#include "fmeditarlivrosfisicos.h"
#include <QtSql>
#include <QMessageBox>

GerenciamentoLivrosFisicos::GerenciamentoLivrosFisicos(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GerenciamentoLivrosFisicos)
{
    ui->setupUi(this);
    QSqlQuery query;
    query.prepare("select * from LivrosFisicos");
    if(query.exec()){
        int cont=0;
        ui->tw_livros_fisicos->setColumnCount(9);
        while(query.next()){
            ui->tw_livros_fisicos->insertRow(cont);
            ui->tw_livros_fisicos->setItem(cont,0,new QTableWidgetItem(query.value(0).toString()));
            ui->tw_livros_fisicos->setItem(cont,1,new QTableWidgetItem(query.value(1).toString()));
            ui->tw_livros_fisicos->setItem(cont,2,new QTableWidgetItem(query.value(2).toString()));
            ui->tw_livros_fisicos->setItem(cont,3,new QTableWidgetItem(query.value(3).toString()));
            ui->tw_livros_fisicos->setItem(cont,4,new QTableWidgetItem(query.value(4).toString()));
            ui->tw_livros_fisicos->setItem(cont,5,new QTableWidgetItem(query.value(5).toString()));
            ui->tw_livros_fisicos->setItem(cont,6,new QTableWidgetItem(query.value(6).toString()));
            ui->tw_livros_fisicos->setItem(cont,7,new QTableWidgetItem(query.value(7).toString()));
            ui->tw_livros_fisicos->setItem(cont,8,new QTableWidgetItem(query.value(8).toString()));
            ui->tw_livros_fisicos->setRowHeight(cont,20);
            cont++;
        }
        ui->tw_livros_fisicos->setColumnWidth(0, 200);
        ui->tw_livros_fisicos->setColumnWidth(1, 150);
        ui->tw_livros_fisicos->setColumnWidth(2, 100);
        ui->tw_livros_fisicos->setColumnWidth(3, 150);
        ui->tw_livros_fisicos->setColumnWidth(4, 150);
        ui->tw_livros_fisicos->setColumnWidth(5,150);
        ui->tw_livros_fisicos->setColumnWidth(6, 150);
        ui->tw_livros_fisicos->setColumnWidth(7, 150);
        ui->tw_livros_fisicos->setColumnWidth(8, 150);

        QStringList cabecalhos = {"Título","Autor","ISBN","Editora","Ano de Publicação", "Estoque","Valor Diária", "Peso", "Tipo de Capa"};
        ui->tw_livros_fisicos->setHorizontalHeaderLabels(cabecalhos);
        ui->tw_livros_fisicos->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tw_livros_fisicos->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tw_livros_fisicos->setStyleSheet("QTableView {selection-background-color:blue}");

    }else{
        QMessageBox::warning(this,"Error","Erro ao pesquisar");
    }
}

GerenciamentoLivrosFisicos::~GerenciamentoLivrosFisicos()
{
    delete ui;
}

void GerenciamentoLivrosFisicos::atualizarTabela()
{
    qDebug() << "Atualizando a tabela...";

    // Limpa todas as linhas existentes na tabela
    ui->tw_livros_fisicos->setRowCount(0);

    // Executa a query para buscar os dados
    QSqlQuery query;
    query.prepare("SELECT * FROM LivrosFisicos");

    if (query.exec()) {
        int cont = 0;

        while (query.next()) {
            qDebug() << "Título:" << query.value("titulo_livro").toString(); // Depuração

            ui->tw_livros_fisicos->insertRow(cont); // Adiciona uma nova linha
            ui->tw_livros_fisicos->setItem(cont, 0, new QTableWidgetItem(query.value("titulo_livro").toString()));
            ui->tw_livros_fisicos->setItem(cont, 1, new QTableWidgetItem(query.value("autor_livro").toString()));
            ui->tw_livros_fisicos->setItem(cont, 2, new QTableWidgetItem(query.value("isbn").toString()));
            ui->tw_livros_fisicos->setItem(cont, 3, new QTableWidgetItem(query.value("editora").toString()));
            ui->tw_livros_fisicos->setItem(cont, 4, new QTableWidgetItem(query.value("ano_publicacao").toString()));
            ui->tw_livros_fisicos->setItem(cont, 5, new QTableWidgetItem(query.value("qt_disponivel").toString()));
            ui->tw_livros_fisicos->setItem(cont, 6, new QTableWidgetItem(query.value("valor_diaria").toString()));
            ui->tw_livros_fisicos->setItem(cont, 7, new QTableWidgetItem(query.value("peso").toString()));
            ui->tw_livros_fisicos->setItem(cont, 8, new QTableWidgetItem(query.value("tipo_capa").toString()));
            ui->tw_livros_fisicos->setRowHeight(cont, 20);
            cont++;
        }
    } else {
        QMessageBox::warning(this, "Erro", "Erro ao carregar a tabela: " + query.lastError().text());
    }
}

void GerenciamentoLivrosFisicos::on_btn_adicionar_lf_clicked()
{
    FmAdicionarLivrosFisicos fmAddFisicos;
    fmAddFisicos.exec();
}


void GerenciamentoLivrosFisicos::on_btn_excluir_lf_clicked()
{
    int linha = ui->tw_livros_fisicos->currentRow(); // Obtém a linha selecionada

    if (linha == -1) {
        QMessageBox::warning(this, "Atenção", "Por favor, selecione um livro para excluir.");
        return;
    }

    // Obtém o valor da coluna "Título" (coluna 0 na tabela)
    QString isbn = ui->tw_livros_fisicos->item(linha, 2)->text();

    // Verifica se o título está vazio (evita consultas inválidas)
    if (isbn.isEmpty()) {
        QMessageBox::warning(this, "Erro", "Não foi possível identificar o título do livro selecionado.");
        return;
    }

    QSqlQuery query;
    QString comando = "DELETE FROM LivrosFisicos WHERE isbn = '" + isbn + "'";

    // Executa o comando SQL
    if (query.exec(comando)) {
        // Remove a linha da tabela
        ui->tw_livros_fisicos->removeRow(linha);
        QMessageBox::information(this, "Sucesso", "Livro excluído com sucesso.");
    } else {
        QMessageBox::warning(this, "Erro", "Erro ao excluir livro. Verifique o banco de dados.");
    }
}


void GerenciamentoLivrosFisicos::on_btn_editar_lf_clicked()
{
    // Obtém a linha selecionada
    int linha = ui->tw_livros_fisicos->currentRow();

    // Verifica se uma linha foi selecionada
    if (linha == -1) {
        QMessageBox::warning(this, "Atenção", "Por favor, selecione um livro para editar.");
        return;
    }

    // Obtém o ISBN da coluna correspondente
    QString var_isbn_fisico = ui->tw_livros_fisicos->item(linha, 2)->text(); // Armazena como QString
    qDebug() << "Valor de var_isbn:" << var_isbn_fisico;

    if (var_isbn_fisico.isEmpty()) {
        QMessageBox::warning(this, "Erro", "ISBN inválido. Por favor, tente novamente.");
        return;
    }

    FmEditarLivrosFisicos fmEditarFisicos(this, var_isbn_fisico);
    fmEditarFisicos.exec();

    atualizarTabela();
}


void GerenciamentoLivrosFisicos::on_pushButton_atualizar_lf_clicked()
{
    qDebug() << "Atualizando a tabela...";

    // Limpa todas as linhas existentes na tabela
    ui->tw_livros_fisicos->setRowCount(0);

    // Executa a query para buscar os dados
    QSqlQuery query;
    query.prepare("SELECT * FROM LivrosFisicos");

    if (query.exec()) {
        int cont = 0;

        while (query.next()) {
            qDebug() << "Título:" << query.value("titulo_livro").toString(); // Depuração

            ui->tw_livros_fisicos->insertRow(cont); // Adiciona uma nova linha
            ui->tw_livros_fisicos->setItem(cont, 0, new QTableWidgetItem(query.value("titulo_livro").toString()));
            ui->tw_livros_fisicos->setItem(cont, 1, new QTableWidgetItem(query.value("autor_livro").toString()));
            ui->tw_livros_fisicos->setItem(cont, 2, new QTableWidgetItem(query.value("isbn").toString()));
            ui->tw_livros_fisicos->setItem(cont, 3, new QTableWidgetItem(query.value("editora").toString()));
            ui->tw_livros_fisicos->setItem(cont, 4, new QTableWidgetItem(query.value("ano_publicacao").toString()));
            ui->tw_livros_fisicos->setItem(cont, 5, new QTableWidgetItem(query.value("qt_disponivel").toString()));
            ui->tw_livros_fisicos->setItem(cont, 6, new QTableWidgetItem(query.value("valor_diaria").toString()));
            ui->tw_livros_fisicos->setItem(cont, 7, new QTableWidgetItem(query.value("peso").toString()));
            ui->tw_livros_fisicos->setItem(cont, 8, new QTableWidgetItem(query.value("tipo_capa").toString()));
            ui->tw_livros_fisicos->setRowHeight(cont, 20);
            cont++;
        }
    } else {
        QMessageBox::warning(this, "Erro", "Erro ao carregar a tabela: " + query.lastError().text());
    }
}


void GerenciamentoLivrosFisicos::on_btn_pesquisar_lf_clicked()
{
    // Obtém o texto do lineEdit
    QString nomeLivro = ui->lineEdit_pesquisar_lf->text().trimmed();

    if (nomeLivro.isEmpty()) {
        // Se o campo de pesquisa estiver vazio, mostrar todos os livros
        QMessageBox::warning(this, "Aviso", "Digite o nome do livro para pesquisa.");
        atualizarTabela();
        return;
    }

    // Limpa a tabela antes de exibir os novos resultados
    ui->tw_livros_fisicos->setRowCount(0);

    // Executa a consulta para buscar o livro com o nome correspondente
    QSqlQuery query;
    query.prepare("SELECT titulo_livro, autor_livro, isbn, editora, ano_publicacao, qt_disponivel, valor_diaria, peso, tipo_capa FROM LivrosFisicos WHERE titulo_livro LIKE :titulo");
    query.bindValue(":titulo", "%" + nomeLivro + "%");

    if (query.exec()) {
        int cont = 0;
        while (query.next()) {
            ui->tw_livros_fisicos->insertRow(cont); // Adiciona uma nova linha
            ui->tw_livros_fisicos->setItem(cont, 0, new QTableWidgetItem(query.value(0).toString()));
            ui->tw_livros_fisicos->setItem(cont, 1, new QTableWidgetItem(query.value(1).toString()));
            ui->tw_livros_fisicos->setItem(cont, 2, new QTableWidgetItem(query.value(2).toString()));
            ui->tw_livros_fisicos->setItem(cont, 3, new QTableWidgetItem(query.value(3).toString()));
            ui->tw_livros_fisicos->setItem(cont, 4, new QTableWidgetItem(query.value(4).toString()));
            ui->tw_livros_fisicos->setItem(cont, 5, new QTableWidgetItem(query.value(5).toString()));
            ui->tw_livros_fisicos->setItem(cont, 6, new QTableWidgetItem(query.value(6).toString()));
            ui->tw_livros_fisicos->setItem(cont, 7, new QTableWidgetItem(query.value(7).toString()));
            ui->tw_livros_fisicos->setItem(cont, 8, new QTableWidgetItem(query.value(8).toString()));
            ui->tw_livros_fisicos->setRowHeight(cont, 20);
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
