#include "gerenciamentousuarios.h"
#include "ui_gerenciamentousuarios.h"
#include <QtSql>
#include <QMessageBox>

gerenciamentousuarios::gerenciamentousuarios(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::gerenciamentousuarios)
{
    ui->setupUi(this);

    QSqlQuery query;
    query.prepare("SELECT * FROM Usuarios");
    if (query.exec()) {
        int cont = 0;
        ui->tw_usuarios->setColumnCount(5); // 5 colunas
        while (query.next()) {
            ui->tw_usuarios->insertRow(cont);
            ui->tw_usuarios->setItem(cont, 0, new QTableWidgetItem(query.value("cpf").toString()));
            ui->tw_usuarios->setItem(cont, 1, new QTableWidgetItem(query.value("nome").toString()));
            ui->tw_usuarios->setItem(cont, 2, new QTableWidgetItem(query.value("endereco").toString()));
            ui->tw_usuarios->setItem(cont, 3, new QTableWidgetItem(query.value("telefone").toString()));
            ui->tw_usuarios->setItem(cont, 4, new QTableWidgetItem("******")); // Mostra "******" para senha por segurança
            ui->tw_usuarios->setRowHeight(cont, 20);
            cont++;
        }
        ui->tw_usuarios->setColumnWidth(0, 150);
        ui->tw_usuarios->setColumnWidth(1, 200);
        ui->tw_usuarios->setColumnWidth(2, 200);
        ui->tw_usuarios->setColumnWidth(3, 150);
        ui->tw_usuarios->setColumnWidth(4, 100);

        QStringList cabecalhos = {"CPF", "Nome", "Endereço", "Telefone", "Senha"};
        ui->tw_usuarios->setHorizontalHeaderLabels(cabecalhos);
        ui->tw_usuarios->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tw_usuarios->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tw_usuarios->setStyleSheet("QTableView {selection-background-color:blue}");
    } else {
        QMessageBox::warning(this, "Erro", "Erro ao carregar a tabela: " + query.lastError().text());
    }
}

gerenciamentousuarios::~gerenciamentousuarios()
{
    delete ui;
}


void gerenciamentousuarios::atualizarTabela()
{
    qDebug() << "Atualizando a tabela...";

    // Limpa todas as linhas existentes na tabela
    ui->tw_usuarios->setRowCount(0);

    // Executa a query para buscar os dados
    QSqlQuery query;
    query.prepare("SELECT * FROM Usuarios");

    if (query.exec()) {
        int cont = 0;

        while (query.next()) {
            qDebug() << "CPF:" << query.value("cpf").toString(); // Depuração

            ui->tw_usuarios->insertRow(cont); // Adiciona uma nova linha
            ui->tw_usuarios->setItem(cont, 0, new QTableWidgetItem(query.value("cpf").toString()));
            ui->tw_usuarios->setItem(cont, 1, new QTableWidgetItem(query.value("nome").toString()));
            ui->tw_usuarios->setItem(cont, 2, new QTableWidgetItem(query.value("endereco").toString()));
            ui->tw_usuarios->setItem(cont, 3, new QTableWidgetItem(query.value("telefone").toString()));
            ui->tw_usuarios->setItem(cont, 4, new QTableWidgetItem(query.value("senha").toString()));
            ui->tw_usuarios->setRowHeight(cont, 20);
            cont++;
        }
    } else {
        QMessageBox::warning(this, "Erro", "Erro ao carregar a tabela: " + query.lastError().text());
    }
}

void gerenciamentousuarios::on_btn_excluir_user_clicked()
{
    int linha = ui->tw_usuarios->currentRow(); // Obtém a linha selecionada

    if (linha == -1) {
        QMessageBox::warning(this, "Atenção", "Por favor, selecione um usuário para excluir.");
        return;
    }

    // Obtém o valor da coluna "Título" (coluna 0 na tabela)
    QString cpf = ui->tw_usuarios->item(linha, 0)->text();

    // Verifica se o título está vazio (evita consultas inválidas)
    if (cpf.isEmpty()) {
        QMessageBox::warning(this, "Erro", "Não foi possível identificar o cpf do usuário selecionado.");
        return;
    }

    QSqlQuery query;
    QString comando = "DELETE FROM Usuarios WHERE cpf = '" + cpf + "'";

    // Executa o comando SQL
    if (query.exec(comando)) {
        // Remove a linha da tabela
        ui->tw_usuarios->removeRow(linha);
        QMessageBox::information(this, "Sucesso", "Usuário excluído com sucesso.");
    } else {
        QMessageBox::warning(this, "Erro", "Erro ao excluir usuário. Verifique o banco de dados.");
    }
}


void gerenciamentousuarios::on_btn_editar_user_clicked()
{
    // Obtém a linha selecionada
    int linha = ui->tw_usuarios->currentRow();

    // Verifica se uma linha foi selecionada
    if (linha == -1) {
        QMessageBox::warning(this, "Atenção", "Por favor, selecione um usuário para editar.");
        return;
    }

    // Obtém o ISBN da coluna correspondente
    QString var_cpf = ui->tw_usuarios->item(linha, 0)->text(); // Armazena como QString
    qDebug() << "Valor de var_isbn:" << var_cpf;

    if (var_cpf.isEmpty()) {
        QMessageBox::warning(this, "Erro", "ISBN inválido. Por favor, tente novamente.");
        return;
    }
    // Abre a janela de edição passando o ISBN
    FmEditarUsuario editarUser(this, var_cpf);
    editarUser.exec();

    // Atualiza a linha editada na tabela
    atualizarTabela(); // Reutiliza o método para atualizar toda a tabela
}


void gerenciamentousuarios::on_btn_atualizar_user_clicked()
{
    // Limpa todos os itens da tabela para evitar duplicação
    ui->tw_usuarios->setRowCount(0);

    // Consulta ao banco de dados
    QSqlQuery query;
    query.prepare("SELECT * FROM Usuarios");

    if (query.exec()) {
        int linha = 0; // Índice da linha na tabela

        while (query.next()) {
            // Adiciona uma nova linha na tabela
            ui->tw_usuarios->insertRow(linha);

            // Preenche os dados na tabela
            ui->tw_usuarios->setItem(linha, 0, new QTableWidgetItem(query.value(0).toString()));
            ui->tw_usuarios->setItem(linha, 1, new QTableWidgetItem(query.value(1).toString()));
            ui->tw_usuarios->setItem(linha, 2, new QTableWidgetItem(query.value(2).toString()));
            ui->tw_usuarios->setItem(linha, 3, new QTableWidgetItem(query.value(3).toString()));
            ui->tw_usuarios->setItem(linha, 4, new QTableWidgetItem(query.value(4).toString()));


            linha++; // Incrementa a linha
        }
    } else {
        QMessageBox::warning(this, "Erro", "Erro ao consultar o banco de dados.");
        qDebug() << "Erro no query.exec(): " << query.lastError().text(); // Log para depuração
    }
}


void gerenciamentousuarios::on_btn_pesquisar_user_clicked()
{
    // Obtém o texto do lineEdit
    QString nomeUser = ui->lineEdit_pesquisar_user->text().trimmed();

    if (nomeUser.isEmpty()) {
        // Se o campo de pesquisa estiver vazio, atualiza a tabela inteira
        QMessageBox::warning(this, "Aviso", "Digite o nome do usuário para pesquisa.");
        atualizarTabela();
        return;
    }

    // Limpa a tabela antes de exibir os novos resultados
    ui->tw_usuarios->setRowCount(0);

    // Executa a consulta para buscar o usuário com o nome correspondente
    QSqlQuery query;
    query.prepare("SELECT cpf, nome, endereco, telefone, senha FROM Usuarios WHERE nome LIKE :nomeUser");
    query.bindValue(":nomeUser", "%" + nomeUser + "%");

    if (query.exec()) {
        int cont = 0;

        while (query.next()) {
            ui->tw_usuarios->insertRow(cont);
            ui->tw_usuarios->setItem(cont, 0, new QTableWidgetItem(query.value("cpf").toString()));       // CPF
            ui->tw_usuarios->setItem(cont, 1, new QTableWidgetItem(query.value("nome").toString()));      // Nome
            ui->tw_usuarios->setItem(cont, 2, new QTableWidgetItem(query.value("endereco").toString()));  // Endereço
            ui->tw_usuarios->setItem(cont, 3, new QTableWidgetItem(query.value("telefone").toString()));  // Telefone
            ui->tw_usuarios->setItem(cont, 4, new QTableWidgetItem("******"));                           // Senha (escondida por segurança)
            ui->tw_usuarios->setRowHeight(cont, 20);
            cont++;
        }

        // Caso não encontre nenhum usuário, exibe uma mensagem
        if (cont == 0) {
            QMessageBox::information(this, "Resultado", "Nenhum usuário encontrado com o nome \"" + nomeUser + "\".");
        }
    } else {
        QMessageBox::warning(this, "Erro", "Erro ao realizar a pesquisa: " + query.lastError().text());
        qDebug() << "Erro ao executar query:" << query.lastError().text();
    }
}

