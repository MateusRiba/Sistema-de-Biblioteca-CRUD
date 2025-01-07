#include <iostream>
#include "Livro.h"
#include "LivroFisico.h"
#include "LivroDigital.h"

using namespace std;

int main(){

LivroDigital HumanidadeD("Humanidade","Mateus","X4X8-345-YX8", 2024,"Digital.LTD",1, 400, "PNG", 45);
LivroFisico HumanidadeF("Humanidade", "Mateus", "X4X8-345-YX8", 2024, "Caçula.LTD", 2, 1,"Dura", 3);

cout << "Nome: " << HumanidadeF.getTitulo() << endl;
cout << "Autor: " << HumanidadeF.getAutor() << endl;
cout << "Numero de Serie: " << HumanidadeF.getISBN() << endl;
cout << "Ano de Publicacao: " << HumanidadeF.getAnoPublicacao() << endl;
cout << "Editora: " << HumanidadeF.getEditora() << endl;
cout << "Valor da Diaria: " << HumanidadeF.getValorDiaria() << endl;
cout << "Peso em Kg: " << HumanidadeF.getPesoGrama() << endl;
cout << "Tipo de Capa: " << HumanidadeF.getTipoCapa() << endl;
cout << "Quantidade em Estoque: " << HumanidadeF.getQuantidadeEstoque() << endl;


HumanidadeD.setAutor("Marie Lu");
HumanidadeF.setAutor("Ariano Suassuna");

cout << "Novo Autor Fisico: " << HumanidadeF.getAutor() <<endl;
cout << "Novo Autor Digital: " << HumanidadeD.getAutor() <<endl;

cout << "Hello World!" << endl;
std::cin.get();
return 0;

};