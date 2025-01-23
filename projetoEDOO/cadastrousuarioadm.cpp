#include "cadastrousuarioadm.h"
#include "ui_cadastrousuarioadm.h"
#include <Qfile>
#include <QTextStream>
#include <QMessageBox>

CadastroUsuarioadm::CadastroUsuarioadm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CadastroUsuarioadm)
{
    ui->setupUi(this);
}

CadastroUsuarioadm::~CadastroUsuarioadm()
{
    delete ui;
}

void CadastroUsuarioadm::on_btn_cadastrar_clicked()
{
    QString nome = ui->txt_nome->text();
    QString cpf = ui->txt_cpf->text();
    QString endereco = ui->txt_endereco->text();
    QString telefone = ui->txt_telefone->text();
    QString senha = ui->txt_senha->text();

    QFile file("C:\\Users\\parac\\OneDrive\\Documentos\\Projetos\\Sistema-de-Informa-o-Bibliotec-rio\\data\\usuarios.csv");
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::warning(this, "Erro", "Não foi possível abrir o arquivo!");
        return;
    }

    // Escrever os dados no arquivo
    QTextStream out(&file);
    out << "LeitorComum;" << nome << ";" << cpf << ";" << endereco << ";"
        << telefone << ";" << senha << "\n";

    file.close();

    QMessageBox::information(this, "Sucesso", "Usuário cadastrado com sucesso!");

}

