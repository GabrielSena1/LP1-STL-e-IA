Este e o projeto de um estudante de C++ que esta aprendendo STL. Responda em portugues,
de forma curta e didatica. Quando explicar um conceito, use um exemplo pequeno.

O sistema esta descrito em DESCRICAO.md, escrito pelo estudante. O plano de implementacao
fica em PLANO.md. Leia os dois antes de propor ou alterar codigo. Se a descricao for ambigua,
pergunte em vez de supor.

Use C++11 e somente a biblioteca padrao. Nao instale nada e nao acesse a rede.

Prefira guardar objetos diretamente nos containers da STL. Nao use new nem delete, a nao
ser que o estudante peca heranca com metodo virtual; nesse caso, explique quem libera a
memoria.

Evite recursos que o estudante ainda nao viu, como lambda e unordered_map, a nao ser que
ele peca. Se achar que um deles ajuda, sugira e explique antes de usar.

Uma classe por par de arquivos: include/Nome.hpp e src/Nome.cpp.

As classes do sistema nao usam cin nem cout. Elas recebem dados por parametro e devolvem
resultados. Toda leitura e escrita na tela fica na interface, em arquivos proprios.

Faca somente o que foi pedido na mensagem, ou a etapa do PLANO.md que o estudante
indicou. Nao acrescente funcionalidades que nao foram pedidas.

Quando o estudante pedir um plano, nao edite: diga quais arquivos e quais metodos voce
criaria ou alteraria, e por que.

Depois de editar, compile com o comando do README.md e rode os arquivos de exemplos/,
se existirem. Mostre o resultado real. Se criar um arquivo novo, atualize o comando de
compilacao no README.md.

Nao altere DESCRICAO.md, nem as secoes "Onde uso a STL" e "Como usei a IA" do README.md.
Essas partes sao escritas pelo estudante. Se achar que a descricao precisa mudar, sugira
a mudanca.

Nao faca commit e nao mexa no historico do Git.

Comando de compilacao: make (ou g++ -std=c++11 -Wall -Wextra -Iinclude src/*.cpp -o sistema).
