#include "fmgerenciaremprestimos.h"
#include "ui_fmgerenciaremprestimos.h"
#include <QtSql>
#include <QMessageBox>

FmGerenciarEmprestimos::FmGerenciarEmprestimos(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FmGerenciarEmprestimos)
{
    ui->setupUi(this);
    // Configura a tabela de empréstimos
    ui->tw_emprestimos->setColumnCount(8); // 8 colunas na tabela
    QStringList cabecalhos = {"ID Empréstimo", "CPF Usuário", "Nome Usuário", "ISBN Livro",
                              "Título Livro", "Data Empréstimo", "Data Devolução", "Status"};
    ui->tw_emprestimos->setHorizontalHeaderLabels(cabecalhos);
    ui->tw_emprestimos->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tw_emprestimos->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tw_emprestimos->setStyleSheet("QTableView {selection-background-color:blue}");
    ui->tw_emprestimos->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    on_btn_atualizar_emprestimos_clicked();

}

FmGerenciarEmprestimos::~FmGerenciarEmprestimos()
{
    delete ui;
}

void FmGerenciarEmprestimos::on_btn_add_emprestimos_clicked()
{
    FmAdicionarEmprestimo fmAddEmprestimo(this);
    fmAddEmprestimo.exec();

}


void FmGerenciarEmprestimos::on_btn_excluir_emprestimos_clicked()
{
    int linha = ui->tw_emprestimos->currentRow(); // Obtém a linha selecionada

    if (linha == -1) {
        QMessageBox::warning(this, "Atenção", "Por favor, selecione um usuário para excluir.");
        return;
    }

    // Obtém o valor da coluna "Título" (coluna 0 na tabela)
    QString id_emprestimo = ui->tw_emprestimos->item(linha, 0)->text();

    // Verifica se o título está vazio (evita consultas inválidas)
    if (id_emprestimo.isEmpty()) {
        QMessageBox::warning(this, "Erro", "Não foi possível identificar o id do empréstimo selecionado.");
        return;
    }

    QSqlQuery query;
    QString comando = "DELETE FROM Usuarios WHERE cpf = '" + id_emprestimo + "'";

    // Executa o comando SQL
    if (query.exec(comando)) {
        // Remove a linha da tabela
        ui->tw_emprestimos->removeRow(linha);
        QMessageBox::information(this, "Sucesso", "Empréstimo excluído com sucesso.");
    } else {
        QMessageBox::warning(this, "Erro", "Erro ao excluir empréstimo. Verifique o banco de dados.");
    }
}


void FmGerenciarEmprestimos::on_btn_editar_emprestimos_clicked()
{
    // Obtém a linha selecionada
    int linha = ui->tw_emprestimos->currentRow();

    // Verifica se uma linha foi selecionada
    if (linha == -1) {
        QMessageBox::warning(this, "Atenção", "Por favor, selecione um empréstimo para editar.");
        return;
    }

    // Obtém o ID do empréstimo da primeira coluna
    QString idEmprestimoStr = ui->tw_emprestimos->item(linha, 0)->text();

    // Converte para inteiro (caso necessário)
    int idEmprestimo = idEmprestimoStr.toInt();

    // Abre a janela de edição, passando o ID do empréstimo como parâmetro
    FmEditarEmprestimo fmEditarEmprestimo(this, idEmprestimo);
    fmEditarEmprestimo.exec();

    // Atualiza a tabela após a edição
    on_btn_atualizar_emprestimos_clicked();
}


void FmGerenciarEmprestimos::on_btn_atualizar_emprestimos_clicked()
{
    qDebug() << "Atualizando a tabela de empréstimos...";

    // Limpa todas as linhas existentes na tabela
    ui->tw_emprestimos->setRowCount(0);

    // Consulta ao banco de dados para obter os empréstimos
    QSqlQuery query;
    query.prepare(
        "SELECT e.id_emprestimo, u.cpf, u.nome, e.isbn_livro, "
        "COALESCE(ld.titulo, lf.titulo_livro) AS titulo, "
        "e.data_emprestimo, e.data_devolucao, e.status "
        "FROM Emprestimos e "
        "JOIN Usuarios u ON e.cpf_usuario = u.cpf "
        "LEFT JOIN LivrosDigitais ld ON e.isbn_livro = ld.isbn "
        "LEFT JOIN LivrosFisicos lf ON e.isbn_livro = lf.isbn");

    if (query.exec()) {
        int linha = 0;

        // Preenche os dados na tabela
        while (query.next()) {
            ui->tw_emprestimos->insertRow(linha);
            ui->tw_emprestimos->setItem(linha, 0, new QTableWidgetItem(query.value("id_emprestimo").toString())); // ID do Empréstimo
            ui->tw_emprestimos->setItem(linha, 1, new QTableWidgetItem(query.value("cpf").toString()));          // CPF do Usuário
            ui->tw_emprestimos->setItem(linha, 2, new QTableWidgetItem(query.value("nome").toString()));         // Nome do Usuário
            ui->tw_emprestimos->setItem(linha, 3, new QTableWidgetItem(query.value("isbn_livro").toString()));   // ISBN do Livro
            ui->tw_emprestimos->setItem(linha, 4, new QTableWidgetItem(query.value("titulo").toString()));       // Título do Livro
            ui->tw_emprestimos->setItem(linha, 5, new QTableWidgetItem(query.value("data_emprestimo").toString())); // Data de Empréstimo
            ui->tw_emprestimos->setItem(linha, 6, new QTableWidgetItem(query.value("data_devolucao").toString()));  // Data de Devolução
            ui->tw_emprestimos->setItem(linha, 7, new QTableWidgetItem(query.value("status").toString()));       // Status do Empréstimo
            ui->tw_emprestimos->setRowHeight(linha, 20);
            linha++;
        }

        // Log de sucesso
        qDebug() << "Tabela de empréstimos atualizada com sucesso.";
    } else {
        QMessageBox::warning(this, "Erro", "Erro ao atualizar a tabela de empréstimos: " + query.lastError().text());
        qDebug() << "Erro ao executar query:" << query.lastError().text();
    }
}



void FmGerenciarEmprestimos::on_btn_pesquisar_emprestimo_clicked()
{
    // Obtém o texto do campo de pesquisa
    QString pesquisa = ui->lineEdit_pesquisar_emprestimo->text().trimmed();

    // Verifica se o campo está vazio
    if (pesquisa.isEmpty()) {
        QMessageBox::warning(this, "Aviso", "Digite um critério para pesquisa.");
        return;
    }

    // Limpa a tabela antes de exibir os novos resultados
    ui->tw_emprestimos->setRowCount(0);

    // Consulta SQL para buscar empréstimos com base na pesquisa
    QSqlQuery query;
    query.prepare("SELECT e.id_emprestimo, u.cpf, u.nome, l.isbn, l.titulo, "
                  "e.data_emprestimo, e.data_devolucao, e.status "
                  "FROM Emprestimos e "
                  "JOIN Usuarios u ON e.cpf_usuario = u.cpf "
                  "JOIN Livros l ON e.isbn_livro = l.isbn "
                  "WHERE e.id_emprestimo LIKE :pesquisa "
                  "OR u.cpf LIKE :pesquisa "
                  "OR l.isbn LIKE :pesquisa "
                  "OR l.titulo LIKE :pesquisa");
    query.bindValue(":pesquisa", "%" + pesquisa + "%");

    // Executa a consulta e preenche a tabela
    if (query.exec()) {
        int linha = 0;

        while (query.next()) {
            ui->tw_emprestimos->insertRow(linha);
            ui->tw_emprestimos->setItem(linha, 0, new QTableWidgetItem(query.value("id_emprestimo").toString())); // ID do Empréstimo
            ui->tw_emprestimos->setItem(linha, 1, new QTableWidgetItem(query.value("cpf").toString()));          // CPF do Usuário
            ui->tw_emprestimos->setItem(linha, 2, new QTableWidgetItem(query.value("nome").toString()));         // Nome do Usuário
            ui->tw_emprestimos->setItem(linha, 3, new QTableWidgetItem(query.value("isbn").toString()));         // ISBN do Livro
            ui->tw_emprestimos->setItem(linha, 4, new QTableWidgetItem(query.value("titulo").toString()));       // Título do Livro
            ui->tw_emprestimos->setItem(linha, 5, new QTableWidgetItem(query.value("data_emprestimo").toString())); // Data de Empréstimo
            ui->tw_emprestimos->setItem(linha, 6, new QTableWidgetItem(query.value("data_devolucao").toString()));  // Data de Devolução
            ui->tw_emprestimos->setItem(linha, 7, new QTableWidgetItem(query.value("status").toString()));       // Status do Empréstimo
            ui->tw_emprestimos->setRowHeight(linha, 20);
            linha++;
        }

        // Verifica se nenhum resultado foi encontrado
        if (linha == 0) {
            QMessageBox::information(this, "Resultado", "Nenhum empréstimo encontrado para \"" + pesquisa + "\".");
        }
    } else {
        QMessageBox::warning(this, "Erro", "Erro ao realizar a pesquisa: " + query.lastError().text());
        qDebug() << "Erro na query:" << query.lastError().text();
    }
}


void FmGerenciarEmprestimos::on_comboBox_emprestimo_currentIndexChanged()
{
    // Obtém o texto selecionado no ComboBox
    QString statusSelecionado = ui->comboBox_emprestimo->currentText();

    // Limpa a tabela antes de exibir os novos resultados
    ui->tw_emprestimos->setRowCount(0);

    // Query SQL com base no status selecionado
    QSqlQuery query;

    if (statusSelecionado == "Todos") {
        // Mostra todos os empréstimos
        query.prepare("SELECT e.id_emprestimo, u.cpf, u.nome, l.isbn, l.titulo, e.data_emprestimo, e.data_devolucao, e.status "
                      "FROM Emprestimos e "
                      "JOIN Usuarios u ON e.cpf_usuario = u.cpf "
                      "JOIN LivrosDigitais l ON e.isbn_livro = l.isbn");
    } else {
        // Filtra com base no status
        query.prepare("SELECT e.id_emprestimo, u.cpf, u.nome, l.isbn, l.titulo, e.data_emprestimo, e.data_devolucao, e.status "
                      "FROM Emprestimos e "
                      "JOIN Usuarios u ON e.cpf_usuario = u.cpf "
                      "JOIN LivrosDigitais l ON e.isbn_livro = l.isbn "
                      "WHERE e.status = :status");
        query.bindValue(":status", statusSelecionado);
    }

    // Executa a query e atualiza a tabela
    if (query.exec()) {
        int cont = 0;

        while (query.next()) {
            ui->tw_emprestimos->insertRow(cont);
            ui->tw_emprestimos->setItem(cont, 0, new QTableWidgetItem(query.value("id_emprestimo").toString()));
            ui->tw_emprestimos->setItem(cont, 1, new QTableWidgetItem(query.value("cpf").toString()));
            ui->tw_emprestimos->setItem(cont, 2, new QTableWidgetItem(query.value("nome").toString()));
            ui->tw_emprestimos->setItem(cont, 3, new QTableWidgetItem(query.value("isbn").toString()));
            ui->tw_emprestimos->setItem(cont, 4, new QTableWidgetItem(query.value("titulo").toString()));
            ui->tw_emprestimos->setItem(cont, 5, new QTableWidgetItem(query.value("data_emprestimo").toString()));
            ui->tw_emprestimos->setItem(cont, 6, new QTableWidgetItem(query.value("data_devolucao").toString()));
            ui->tw_emprestimos->setItem(cont, 7, new QTableWidgetItem(query.value("status").toString()));
            ui->tw_emprestimos->setRowHeight(cont, 20);
            cont++;
        }
    } else {
        QMessageBox::warning(this, "Erro", "Erro ao filtrar empréstimos: " + query.lastError().text());
    }
}

