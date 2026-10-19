# Controle de Gastos

Sistema em C++ com STL, atividade da Unidade 2 de Linguagem de Programação I.

## Como compilar
make
ou diretamente:
g++ -std=c++11 -Wall -Wextra -Iinclude src/main.cpp src/Gasto.cpp src/Categoria.cpp src/Carteira.cpp -o sistema

## Como rodar
./sistema
Ou rodar um cenário de exemplo:

./sistema < exemplos/cenario1.txt

## Ferramenta de IA usada

OpenCode com Big Pickle 1.19.3.

## Onde uso a STL

- std::list<Gasto> guarda todos os gastos registrados, em Carteira. Usei list porque só
  preciso inserir no fim e percorrer do início ao fim; não preciso de acesso por índice
  nem de busca por posição, então não precisava das garantias (nem do custo) de um
  vector.
- std::map<std::string, Categoria> guarda as categorias, com o nome como chave. O map
  resolve sozinho duas coisas: impedir categoria duplicada (insiro pela chave e confiro
  antes) e buscar uma categoria pelo nome em tempo logarítmico, sem percorrer tudo.
- std::vector<Gasto> aparece como retorno temporário em maioresGastosDoMes: copio da
  list os gastos do mês pedido para um vector porque std::sort precisa de acesso
  aleatório, que a list não oferece.
- std::sort, em maioresGastosDoMes, ordena esse vector usando o operator< que defini em
  Gasto (compara por valor). É o requisito de "sort com operator< definido na classe".
- std::map<std::string, double>, em totalPorCategoriaTodas, guarda o total gasto em cada
  categoria, casando nome com valor, para a opção 3 do menu.

## Como usei a IA

Descrevi o sistema em DESCRICAO.md antes de pedir qualquer código. Pedi um plano
(PLANO.md) com as classes, os containers escolhidos e o porquê de cada um, e só depois
pedi a implementação. Revisei cada arquivo gerado, compilei com -Wall -Wextra e rodei os
cenários de exemplos/ para conferir o comportamento, inclusive os casos de entrada
inválida (data errada, valor negativo, texto no lugar de número, categoria inexistente).
