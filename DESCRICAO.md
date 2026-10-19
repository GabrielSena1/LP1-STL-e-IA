# Descrição do sistema 

# Nome e ideia 
Controle de Gastos é um sistema de linha de comando para registrar gastos pessoais
organizados por categoria, com um limite mensal por categoria. Serve para quem quer
acompanhar em quais categorias está gastando mais e ser avisado quando passou do
orçamento combinado para o mês.
# O que o sistema guarda
Categoria: nome (único) e limite mensal de gasto.
Gasto: valor, data (dd/mm/aaaa), categoria a que pertence e uma descrição curta.

## O que dá para fazer
- Cadastrar categoria: pede nome e limite mensal.

- Registrar gasto: pede valor, data, categoria e descrição; o gasto só é aceito se a
categoria já existir.

- Total por categoria: mostra, para cada categoria cadastrada, a soma de todos os
gastos registrados nela.

- Maiores gastos do mês: pede um mês/ano (mm/aaaa) e uma quantidade N, mostra os N
gastos de maior valor naquele mês, do maior para o menor.

- Categorias acima do limite no mês: pede um mês/ano e lista as categorias cujo total
gasto naquele mês passou do limite cadastrado.

- Listar todos os gastos: mostra todos os gastos registrados, na ordem em que foram
cadastrados.

## Regras
- Não pode haver duas categorias com o mesmo nome.
- Um gasto só pode ser registrado numa categoria que já existe.
- O valor de um gasto tem que ser maior que zero.
- A data tem que estar no formato dd/mm/aaaa, com dia entre 1 e 31 e mês entre 1 e 12.
- O limite de uma categoria não pode ser negativo.

## Quando algo dá errado
- Cadastrar categoria com nome repetido: o sistema avisa que já existe e não cadastra
  de novo.
- Registrar gasto numa categoria que não existe: o sistema avisa e não registra o gasto.
- Registrar gasto com valor zero, negativo ou com data fora do formato: o sistema avisa
  qual foi o problema e não registra.
- Consultar totais, maiores gastos ou categorias acima do limite sem nenhum dado
  cadastrado: o sistema avisa que não há nada para mostrar, em vez de mostrar uma lista
  vazia sem explicação.
- Digitar texto onde era esperado um número (valor, limite, quantidade, opção do menu):
  o sistema avisa que a entrada é inválida e não derruba o programa.

## Classes que eu imagino
- Categoria: guarda nome e limite mensal de uma categoria.
- Gasto: guarda valor, data, categoria e descrição de um gasto.
- Carteira: guarda a lista de gastos e o mapa de categorias, e é responsável por toda a
  lógica (cadastrar, registrar, calcular totais, achar maiores gastos, achar categorias
  acima do limite). Não lê nem escreve nada na tela.

## Exemplo de uso
Escolha: 1
Nome da categoria: Alimentacao
Limite mensal: 800

Escolha: 2
Valor: 45.90
Data (dd/mm/aaaa): 10/10/2026
Categoria: Alimentacao
Descricao: Mercado
Gasto registrado.

Escolha: 3
Alimentacao: 45.9