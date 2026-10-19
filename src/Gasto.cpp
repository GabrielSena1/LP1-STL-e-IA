#include "Gasto.hpp"

Gasto::Gasto()
    : valor_(0.0), data_(""), categoria_(""), descricao_("") {
}

Gasto::Gasto(double valor, const std::string& data, const std::string& categoria, const std::string& descricao)
    : valor_(valor), data_(data), categoria_(categoria), descricao_(descricao) {
}

double Gasto::getValor() const {
    return valor_;
}

std::string Gasto::getData() const {
    return data_;
}

std::string Gasto::getCategoria() const {
    return categoria_;
}

std::string Gasto::getDescricao() const {
    return descricao_;
}

std::string Gasto::getMesAno() const {
    if (data_.size() != 10) {
        return "";
    }
    return data_.substr(3, 7);
}

bool Gasto::operator<(const Gasto& outro) const {
    return valor_ < outro.valor_;
}
