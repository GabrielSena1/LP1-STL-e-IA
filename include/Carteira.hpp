#pragma once

#include <list>
#include <map>
#include <string>
#include <vector>

#include "Gasto.hpp"
#include "Categoria.hpp"

enum class ResultadoGasto {
    OK,
    VALOR_INVALIDO,
    DATA_INVALIDA,
    CATEGORIA_INEXISTENTE
};

class Carteira {
public:
    bool cadastrarCategoria(const std::string& nome, double limite);
    bool categoriaExiste(const std::string& nome) const;

    ResultadoGasto registrarGasto(double valor, const std::string& data, const std::string& categoria, const std::string& descricao);

    double totalPorCategoria(const std::string& categoria) const;
    double totalPorCategoriaNoMes(const std::string& categoria, const std::string& mesAno) const;
    std::map<std::string, double> totalPorCategoriaTodas() const;

    std::vector<Gasto> maioresGastosDoMes(const std::string& mesAno, std::size_t quantidade) const;
    std::vector<std::string> categoriasAcimaDoLimite(const std::string& mesAno) const;

    const std::list<Gasto>& getGastos() const;
    const std::map<std::string, Categoria>& getCategorias() const;

private:
    static bool dataValida(const std::string& data);

    std::list<Gasto> gastos_;
    std::map<std::string, Categoria> categorias_;
};
