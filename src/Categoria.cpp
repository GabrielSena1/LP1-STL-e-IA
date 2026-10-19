#include "Categoria.hpp"

Categoria::Categoria()
    : nome_(""), limite_(0.0) {
}

Categoria::Categoria(const std::string& nome, double limite)
    : nome_(nome), limite_(limite) {
}

std::string Categoria::getNome() const {
    return nome_;
}

double Categoria::getLimite() const {
    return limite_;
}

void Categoria::setLimite(double limite) {
    limite_ = limite;
}
