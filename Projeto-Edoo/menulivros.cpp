#include "menulivros.h"
#include "ui_menulivros.h"

MenuLivros::MenuLivros(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MenuLivros)
{
    ui->setupUi(this);


}

MenuLivros::~MenuLivros()
{
    delete ui;
}

void MenuLivros::on_btnVisualizarLivros_clicked()
{
    // Limpa todas as linhas existentes na tabela
        ui->tw_visualizar_livros->setRowCount(0);

    // Consulta ao banco de dados para buscar os livros
        QSqlQuery query;
        query.prepare("select * from LivrosDigitais");
        if(query.exec()){
            int cont=0;
            ui->tw_visualizar_livros->setColumnCount(6);
            while(query.next()){
                ui->tw_visualizar_livros->insertRow(cont);
                ui->tw_visualizar_livros->setItem(cont,0,new QTableWidgetItem(query.value(0).toString()));
                ui->tw_visualizar_livros->setItem(cont,1,new QTableWidgetItem(query.value(1).toString()));
                ui->tw_visualizar_livros->setItem(cont,2,new QTableWidgetItem(query.value(2).toString()));
                ui->tw_visualizar_livros->setItem(cont,3,new QTableWidgetItem(query.value(3).toString()));
                ui->tw_visualizar_livros->setItem(cont,4,new QTableWidgetItem(query.value(4).toString()));
                ui->tw_visualizar_livros->setItem(cont,5,new QTableWidgetItem(query.value(5).toString()));
                ui->tw_visualizar_livros->setRowHeight(cont,20);
                cont++;
            }
            ui->tw_visualizar_livros->setColumnWidth(0, 200);
            ui->tw_visualizar_livros->setColumnWidth(1, 150);
            ui->tw_visualizar_livros->setColumnWidth(2, 100);
            ui->tw_visualizar_livros->setColumnWidth(3, 150);
            ui->tw_visualizar_livros->setColumnWidth(4, 150);
            ui->tw_visualizar_livros->setColumnWidth(5,150);

            QStringList cabecalhos = {"Título","Autor","ISBN","Editora","Ano de Publicação","Valor Diária"};
            ui->tw_visualizar_livros->setHorizontalHeaderLabels(cabecalhos);
            ui->tw_visualizar_livros->setEditTriggers(QAbstractItemView::NoEditTriggers);
            ui->tw_visualizar_livros->setSelectionBehavior(QAbstractItemView::SelectRows);
            ui->tw_visualizar_livros->setStyleSheet("QTableView {selection-background-color:blue}");
        }

}

void MenuLivros::on_btnVisualizarFisicos_clicked()
{
    // Limpa todas as linhas existentes na tabela
    ui->tw_visualizar_livros->setRowCount(0);

    // Consulta ao banco de dados para buscar os livros
    QSqlQuery query;
    query.prepare("select * from LivrosFisicos");
    if(query.exec()){
        int cont=0;
        ui->tw_visualizar_livros->setColumnCount(9);
        while(query.next()){
            ui->tw_visualizar_livros->insertRow(cont);
            ui->tw_visualizar_livros->setItem(cont,0,new QTableWidgetItem(query.value(0).toString()));
            ui->tw_visualizar_livros->setItem(cont,1,new QTableWidgetItem(query.value(1).toString()));
            ui->tw_visualizar_livros->setItem(cont,2,new QTableWidgetItem(query.value(2).toString()));
            ui->tw_visualizar_livros->setItem(cont,3,new QTableWidgetItem(query.value(3).toString()));
            ui->tw_visualizar_livros->setItem(cont,4,new QTableWidgetItem(query.value(4).toString()));
            ui->tw_visualizar_livros->setItem(cont,5,new QTableWidgetItem(query.value(5).toString()));
            ui->tw_visualizar_livros->setItem(cont,6,new QTableWidgetItem(query.value(6).toString()));
            ui->tw_visualizar_livros->setItem(cont,7,new QTableWidgetItem(query.value(7).toString()));
            ui->tw_visualizar_livros->setItem(cont,8,new QTableWidgetItem(query.value(8).toString()));
            ui->tw_visualizar_livros->setRowHeight(cont,20);
            cont++;
        }
        ui->tw_visualizar_livros->setColumnWidth(0, 200);
        ui->tw_visualizar_livros->setColumnWidth(1, 150);
        ui->tw_visualizar_livros->setColumnWidth(2, 100);
        ui->tw_visualizar_livros->setColumnWidth(3, 150);
        ui->tw_visualizar_livros->setColumnWidth(4, 150);
        ui->tw_visualizar_livros->setColumnWidth(5,150);
        ui->tw_visualizar_livros->setColumnWidth(6, 150);
        ui->tw_visualizar_livros->setColumnWidth(7, 150);
        ui->tw_visualizar_livros->setColumnWidth(8,150);
        ui->tw_visualizar_livros->setColumnWidth(9,150);

        QStringList cabecalhos = {"Título","Autor","ISBN","Editora","Ano de Publicação","Quantidade Disponível","Valor Diária", "Peso", "Tipo de Capa"};
        ui->tw_visualizar_livros->setHorizontalHeaderLabels(cabecalhos);
        ui->tw_visualizar_livros->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tw_visualizar_livros->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tw_visualizar_livros->setStyleSheet("QTableView {selection-background-color:blue}");
    }
}


void MenuLivros::on_btnSair_clicked()
{

}

