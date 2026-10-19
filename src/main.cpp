#include <iostream>
#include <limits>
#include <string>

#include "Carteira.hpp"

static void limparEntrada() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

static bool lerDouble(double& valor) {
    std::cin >> valor;
    if (std::cin.fail()) {
        limparEntrada();
        return false;
    }
    limparEntrada();
    return true;
}

static bool lerInt(int& valor) {
    std::cin >> valor;
    if (std::cin.fail()) {
        limparEntrada();
        return false;
    }
    limparEntrada();
    return true;
}

static void mostrarMenu() {
    std::cout << "\n--- Controle de Gastos ---\n";
    std::cout << "1 - Cadastrar categoria\n";
    std::cout << "2 - Registrar gasto\n";
    std::cout << "3 - Total por categoria\n";
    std::cout << "4 - Maiores gastos do mes\n";
    std::cout << "5 - Categorias acima do limite no mes\n";
    std::cout << "6 - Listar todos os gastos\n";
    std::cout << "0 - Sair\n";
    std::cout << "Escolha: ";
}

static void cadastrarCategoria(Carteira& carteira) {
    std::string nome;
    double limite;
    std::cout << "Nome da categoria: ";
    std::getline(std::cin, nome);
    std::cout << "Limite mensal: ";
    if (!lerDouble(limite)) {
        std::cout << "Limite invalido.\n";
        return;
    }
    if (!carteira.cadastrarCategoria(nome, limite)) {
        std::cout << "Categoria ja existe ou dados invalidos.\n";
        return;
    }
    std::cout << "Categoria cadastrada.\n";
}

static void registrarGasto(Carteira& carteira) {
    if (carteira.getCategorias().empty()) {
        std::cout << "Cadastre uma categoria antes.\n";
        return;
    }
    double valor;
    std::string data;
    std::string categoria;
    std::string descricao;

    std::cout << "Valor: ";
    if (!lerDouble(valor)) {
        std::cout << "Valor invalido.\n";
        return;
    }
    std::cout << "Data (dd/mm/aaaa): ";
    std::getline(std::cin, data);
    std::cout << "Categoria: ";
    std::getline(std::cin, categoria);
    std::cout << "Descricao: ";
    std::getline(std::cin, descricao);

    ResultadoGasto resultado = carteira.registrarGasto(valor, data, categoria, descricao);
    switch (resultado) {
        case ResultadoGasto::OK:
            std::cout << "Gasto registrado.\n";
            break;
        case ResultadoGasto::VALOR_INVALIDO:
            std::cout << "Valor deve ser maior que zero.\n";
            break;
        case ResultadoGasto::DATA_INVALIDA:
            std::cout << "Data invalida, use dd/mm/aaaa.\n";
            break;
        case ResultadoGasto::CATEGORIA_INEXISTENTE:
            std::cout << "Categoria nao cadastrada.\n";
            break;
    }
}

static void totalPorCategoria(const Carteira& carteira) {
    std::map<std::string, double> totais = carteira.totalPorCategoriaTodas();
    if (totais.empty()) {
        std::cout << "Nenhuma categoria cadastrada.\n";
        return;
    }
    for (std::map<std::string, double>::const_iterator it = totais.begin(); it != totais.end(); ++it) {
        std::cout << it->first << ": " << it->second << "\n";
    }
}

static void maioresGastosDoMes(const Carteira& carteira) {
    std::string mesAno;
    int quantidade;
    std::cout << "Mes/ano (mm/aaaa): ";
    std::getline(std::cin, mesAno);
    std::cout << "Quantos mostrar: ";
    if (!lerInt(quantidade) || quantidade <= 0) {
        std::cout << "Quantidade invalida.\n";
        return;
    }
    std::vector<Gasto> gastos = carteira.maioresGastosDoMes(mesAno, static_cast<std::size_t>(quantidade));
    if (gastos.empty()) {
        std::cout << "Nenhum gasto nesse mes.\n";
        return;
    }
    for (std::size_t i = 0; i < gastos.size(); ++i) {
        std::cout << gastos[i].getData() << " " << gastos[i].getCategoria() << " "
                   << gastos[i].getValor() << " " << gastos[i].getDescricao() << "\n";
    }
}

static void categoriasAcimaDoLimite(const Carteira& carteira) {
    std::string mesAno;
    std::cout << "Mes/ano (mm/aaaa): ";
    std::getline(std::cin, mesAno);
    std::vector<std::string> acima = carteira.categoriasAcimaDoLimite(mesAno);
    if (acima.empty()) {
        std::cout << "Nenhuma categoria passou do limite nesse mes.\n";
        return;
    }
    for (std::size_t i = 0; i < acima.size(); ++i) {
        std::cout << acima[i] << "\n";
    }
}

static void listarGastos(const Carteira& carteira) {
    const std::list<Gasto>& gastos = carteira.getGastos();
    if (gastos.empty()) {
        std::cout << "Nenhum gasto registrado.\n";
        return;
    }
    for (std::list<Gasto>::const_iterator it = gastos.begin(); it != gastos.end(); ++it) {
        std::cout << it->getData() << " " << it->getCategoria() << " "
                   << it->getValor() << " " << it->getDescricao() << "\n";
    }
}

int main() {
    Carteira carteira;
    int opcao = -1;

    while (opcao != 0) {
        mostrarMenu();
        if (!lerInt(opcao)) {
            std::cout << "Opcao invalida.\n";
            continue;
        }
        switch (opcao) {
            case 1:
                cadastrarCategoria(carteira);
                break;
            case 2:
                registrarGasto(carteira);
                break;
            case 3:
                totalPorCategoria(carteira);
                break;
            case 4:
                maioresGastosDoMes(carteira);
                break;
            case 5:
                categoriasAcimaDoLimite(carteira);
                break;
            case 6:
                listarGastos(carteira);
                break;
            case 0:
                std::cout << "Ate mais.\n";
                break;
            default:
                std::cout << "Opcao invalida.\n";
                break;
        }
    }

    return 0;
}
