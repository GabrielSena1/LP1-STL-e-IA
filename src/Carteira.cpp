#include "Carteira.hpp"

#include <algorithm>
#include <cctype>

bool Carteira::dataValida(const std::string& data) {
    if (data.size() != 10) {
        return false;
    }
    if (data[2] != '/' || data[5] != '/') {
        return false;
    }
    for (std::size_t i = 0; i < data.size(); ++i) {
        if (i == 2 || i == 5) {
            continue;
        }
        if (!std::isdigit(static_cast<unsigned char>(data[i]))) {
            return false;
        }
    }
    int dia = std::stoi(data.substr(0, 2));
    int mes = std::stoi(data.substr(3, 2));
    if (dia < 1 || dia > 31) {
        return false;
    }
    if (mes < 1 || mes > 12) {
        return false;
    }
    return true;
}

bool Carteira::cadastrarCategoria(const std::string& nome, double limite) {
    if (nome.empty() || limite < 0.0) {
        return false;
    }
    if (categoriaExiste(nome)) {
        return false;
    }
    categorias_[nome] = Categoria(nome, limite);
    return true;
}

bool Carteira::categoriaExiste(const std::string& nome) const {
    return categorias_.find(nome) != categorias_.end();
}

ResultadoGasto Carteira::registrarGasto(double valor, const std::string& data, const std::string& categoria, const std::string& descricao) {
    if (valor <= 0.0) {
        return ResultadoGasto::VALOR_INVALIDO;
    }
    if (!dataValida(data)) {
        return ResultadoGasto::DATA_INVALIDA;
    }
    if (!categoriaExiste(categoria)) {
        return ResultadoGasto::CATEGORIA_INEXISTENTE;
    }
    gastos_.push_back(Gasto(valor, data, categoria, descricao));
    return ResultadoGasto::OK;
}

double Carteira::totalPorCategoria(const std::string& categoria) const {
    double total = 0.0;
    for (std::list<Gasto>::const_iterator it = gastos_.begin(); it != gastos_.end(); ++it) {
        if (it->getCategoria() == categoria) {
            total += it->getValor();
        }
    }
    return total;
}

double Carteira::totalPorCategoriaNoMes(const std::string& categoria, const std::string& mesAno) const {
    double total = 0.0;
    for (std::list<Gasto>::const_iterator it = gastos_.begin(); it != gastos_.end(); ++it) {
        if (it->getCategoria() == categoria && it->getMesAno() == mesAno) {
            total += it->getValor();
        }
    }
    return total;
}

std::map<std::string, double> Carteira::totalPorCategoriaTodas() const {
    std::map<std::string, double> totais;
    for (std::map<std::string, Categoria>::const_iterator it = categorias_.begin(); it != categorias_.end(); ++it) {
        totais[it->first] = totalPorCategoria(it->first);
    }
    return totais;
}

static bool maiorPrimeiro(const Gasto& a, const Gasto& b) {
    return b < a;
}

std::vector<Gasto> Carteira::maioresGastosDoMes(const std::string& mesAno, std::size_t quantidade) const {
    std::vector<Gasto> doMes;
    for (std::list<Gasto>::const_iterator it = gastos_.begin(); it != gastos_.end(); ++it) {
        if (it->getMesAno() == mesAno) {
            doMes.push_back(*it);
        }
    }
    std::sort(doMes.begin(), doMes.end(), maiorPrimeiro);
    if (doMes.size() > quantidade) {
        doMes.resize(quantidade);
    }
    return doMes;
}

std::vector<std::string> Carteira::categoriasAcimaDoLimite(const std::string& mesAno) const {
    std::vector<std::string> acima;
    for (std::map<std::string, Categoria>::const_iterator it = categorias_.begin(); it != categorias_.end(); ++it) {
        double gasto = totalPorCategoriaNoMes(it->first, mesAno);
        if (gasto > it->second.getLimite()) {
            acima.push_back(it->first);
        }
    }
    return acima;
}

const std::list<Gasto>& Carteira::getGastos() const {
    return gastos_;
}

const std::map<std::string, Categoria>& Carteira::getCategorias() const {
    return categorias_;
}
