# Torre de Hanói

Implementação de Algoritmos de Busca para o problema da Torre de Hanói.

## O Problema

O problema das Torres De Hanói é um quebra-cabeça criado pelo matemático francês Edourd Lucas em 1883.

Esse quebra-cabeça consiste de 3 hastes e N discos (vamos usar 4), inicialmente dispostos em ordem decrescente de tamanho na haste esquerda (A).

O objetivo desse jogo é transferir os N discos da haste inicial para a haste mais à direita (C).

Cada movimento consiste em retirar um disco do topo de uma haste e passar para o topo de outra haste, seguindo as regras:

- Os discos devem ser movidos um de cada vez.
- Um disco maior NÃO pode ficar por cima de um disco menor.

As regras de transição de estado para esse problema são:

1. A -> B
2. A -> C
3. B -> A
4. B -> C
5. C -> A
6. C -> B

## Buscas

### Busca Backtracking

O algoritmo de busca backtracking aplica uma regra de transição em um nó, apartir do nó inicial, até que se encontre o nó solução.

Caso a busca chegue a um nó folha que não é o nó solução (estado de impasse), a busca backtracking força um retrocesso da busca, que é um retorno ao nó pai do estado de impasse, forçando com que ele faça uma nova escolha de filho (aplicação de uma outra regra de transição).

A busca backtracking só termina em FRACASSO quando acontecer de retroceder ao nó raiz após ter escohido TODAS as regras de transição de estado.

Portanto, se o problema tiver uma solução a busca backtracking SEMPRE vai encontrá-la.

### Busca em Profundidade

O algoritmo de busca em profundidade realiza uma busca não-informada que progride através da expansão do primeiro nó filho da árvore de busca, e se aprofunda cada vez mais, até que o alvo da busca seja encontrado ou até que ele se depare com um nó que não possui filhos (nó folha).

### Busca em Largura

O algoritmo de busca em largura funciona da seguinte forma: começa pelo nó raiz e explora todos os nós vizinhos. Então, para cada um desses nós mais próximos, explora os seus nós vizinhos inexplorados e assim por diante, até que ele encontre o alvo da busca.

## Compilação e execução

Abra o terminal e realize os seguintes passos:
  
    g++ *.cpp -o hanoi.exe  

Em seguida: 

    ./hanoi

[Repositório do Github](https://github.com/MaraLemos/torre_hanoi)
