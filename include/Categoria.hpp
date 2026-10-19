#pragma once

#include <string>

class Categoria {
public:
    Categoria();
    Categoria(const std::string& nome, double limite);

    std::string getNome() const;
    double getLimite() const;
    void setLimite(double limite);

private:
    std::string nome_;
    double limite_;
};
