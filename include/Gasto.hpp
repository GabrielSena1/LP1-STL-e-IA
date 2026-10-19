#pragma once

#include <string>

class Gasto {
public:
    Gasto();
    Gasto(double valor, const std::string& data, const std::string& categoria, const std::string& descricao);

    double getValor() const;
    std::string getData() const;
    std::string getCategoria() const;
    std::string getDescricao() const;
    std::string getMesAno() const;

    bool operator<(const Gasto& outro) const;

private:
    double valor_;
    std::string data_;
    std::string categoria_;
    std::string descricao_;
};
