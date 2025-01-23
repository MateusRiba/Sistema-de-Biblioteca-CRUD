#include "../include/LivroDigital.h"

// Implementação do método exibir
void LivroDigital::exibir() const {
    std::cout << "Título: " << titulo << "\n"
              << "Autor: " << autor << "\n"
              << "ISBN: " << isbn << "\n"
              << "Ano de Publicação: " << anoPublicacao << "\n"
              << "Editora: " << editora << "\n"
              << "Valor Diário: " << valorDiaria << "\n"
              << "Tamanho do Arquivo (KB): " << tamanhoArquivoKB << "\n"
              << "Formato do Arquivo: " << formatoArquivo << "\n"
              << "Licença Digital: " << licensaDigital << "\n";
}

// Sets e Gets

// TamanhoArquivoKB
void LivroDigital::setTamanhoArquivoKB(int ta) {
    tamanhoArquivoKB = ta;
}

int LivroDigital::getTamanhoArquivoKB() const {
    return tamanhoArquivoKB;
}

// FormatoArquivo
void LivroDigital::setFormatoArquivo(const std::string& f) {
    formatoArquivo = f;
}

std::string LivroDigital::getFormatoArquivo() const {
    return formatoArquivo;
}

// LicensaDigital
void LivroDigital::setLicensaDigital(int l) {
    licensaDigital = l;
}

int LivroDigital::getLicensaDigital() const {
    return licensaDigital;
}
