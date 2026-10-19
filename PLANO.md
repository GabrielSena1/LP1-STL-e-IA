# Plano - Controle de Gastos

## Classes

- Categoria (include/Categoria.hpp, src/Categoria.cpp): guarda nome e limite mensal de uma
  categoria. Sem cin/cout.
- Gasto (include/Gasto.hpp, src/Gasto.cpp): guarda valor, data, categoria e descricao de um
  gasto. Define operator< comparando por valor, usado no sort dos maiores gastos do mes.
- Carteira (include/Carteira.hpp, src/Carteira.cpp): guarda a lista de gastos e o mapa de
  categorias, e contem toda a logica (cadastrar categoria, registrar gasto, calcular totais,
  achar maiores gastos, achar categorias acima do limite). Sem cin/cout.

## Containers da STL e por que

- std::list<Gasto> para os gastos: insercao no fim e simples, nao precisa de acesso aleatorio
  nem de posicao para os gastos armazenados.
- std::map<std::string, Categoria> para as categorias: busca por nome em O(log n), impede
  duplicata pela propria chave, e mantem as categorias ordenadas alfabeticamente ao listar.
- std::vector<Gasto> como retorno temporario de maioresGastosDoMes, porque sort precisa de
  acesso aleatorio; o vector e preenchido a partir da list e ordenado com std::sort usando
  o operator< de Gasto.
- std::map<std::string, double> como retorno de totalPorCategoriaTodas, para casar nome de
  categoria com o total gasto nela.

## Etapas

1. Criar Categoria (hpp/cpp) e Gasto (hpp/cpp) com os getters e o operator< de Gasto.
   Compila sozinho, sem interface ainda.
2. Criar Carteira: cadastrarCategoria, categoriaExiste, registrarGasto com as validacoes
   (valor > 0, data no formato dd/mm/aaaa, categoria existente). Compila, ainda sem main.
3. Adicionar a Carteira: totalPorCategoria, totalPorCategoriaNoMes, totalPorCategoriaTodas,
   maioresGastosDoMes (usa sort), categoriasAcimaDoLimite.
4. Criar main.cpp com o menu em modo texto, chamando so os metodos da Carteira. Tratar
   entrada invalida (cin.fail()) em todas as leituras numericas.
5. Criar os arquivos em exemplos/ e rodar `./sistema < exemplos/cenario1.txt` conferindo a
   saida a mao.
