/************************************************************
 * Universidade Federal de Juiz de Fora - UFJF              *
 * Instituto de Ciências Exatas                             *
 * Departamento de Ciência da Computação                    *
 * Disciplina: DCC014 – Inteligência Artificial - 2022.3    *
 * Professora: Luciana Conceição Dias Campos                *
 * Aluno(s): Gabriel Pereira Senra Soares                   *
 *           Ketleen Anne Faria                             *
 *           Lucia Helena da Silva Pereira                  *
 *           Mara de Lemos Gomes                            *
 *           Maria Eduarda Ribeiro Facio                    *
 *           Mariana Richa Ferreira                         *
 *           Rosa Maria Ottoni Fernandes                    *
 * Versão: 1.0.0                                            *
 *       TRABALHO PRÁTICO - GRUPO 2 - TORRE DE HANÓI        *
 ************************************************************/

/***********************************************************
 *                      Arquivo principal                  *
 ***********************************************************/

#include "Grafo.h"

using namespace std;

void funcionalidades(char opc);
void testarNovamente(char s_n);

void print_menu()
{
    cout << "----------------------------------------- MENU -----------------------------------------" << endl
         << endl;
    cout << "a) Busca Backtracking" << endl
         << endl;
    cout << "b) Busca em Largura" << endl
         << endl;
    cout << "c) Busca em Profundidade" << endl
         << endl;
    cout << "d) Busca Ordenada" << endl
         << endl;
    cout << "e) Busca Gulosa" << endl
         << endl;
    cout << "f) Busca A*" << endl
         << endl;

    cout << "Digite a opção da funcionalidade que deseja testar: ";
    char opc;
    cin >> opc;
    funcionalidades(opc);
}

void funcionalidades(char opc)
{
    switch (opc)
    {
    case 'a':
        // TODO: @0ket - chamar busca backtracking
        break;
    case 'b':
        // TODO: @mariana - chamar busca em largura
        break;
    case 'c':
        // TODO: @Gabreu20 - chamar busca em profundidade
        break;
    case 'd':
        // TODO: @MaraLemos - chamar busca ordenada
        break;
    case 'e':
        // TODO: @RosaOttoni - chamar busca gulosa
        break;
    case 'f':
        // TODO: @LuciaPereira - chamar busca A*
        break;
    default:
        cout << "Opção inválida. Tente novamente, digitando uma opção válida (a, b, c, d, e ou f): ";
        cin >> opc;
        funcionalidades(opc);
        break;
    }

    cout << endl
         << "Deseja testar outra funcionalidade? (s/n)" << endl;
    char s_n;
    cin >> s_n;
    testarNovamente(s_n);
}

void testarNovamente(char s_n)
{
    switch (s_n)
    {
    case 's':
        print_menu();
        break;

    case 'n':
        exit(0);
        break;

    default:
        std::cout << "Opção inválida. Tente novamente, digitando uma opção válida (s ou n): ";
        std::cin >> s_n;
        testarNovamente(s_n);
        break;
    }
}

void teste(){

    Grafo *grafo_th = new Grafo();
    grafo_th->insereNo(0,"A",0);
    grafo_th->insereNo(1,"N",0);
    grafo_th->insereNo(2,"M",0);
    grafo_th->insereNo(3,"X",0);
    grafo_th->insereNo(4,"R",0);
    grafo_th->insereNo(5,"Z",0);
    grafo_th->insereAresta(0,1,5,0);
    grafo_th->insereAresta(0,2,10,0);
    grafo_th->insereAresta(0,3,7,0);
    grafo_th->insereAresta(1,2,2,0);
    grafo_th->insereAresta(2,3,9,0);
    grafo_th->insereAresta(2,5,4,0);
    grafo_th->insereAresta(3,4,1,0);
    grafo_th->insereAresta(4,5,9,0);
    //grafo_th->imprime();
    grafo_th->buscaOrdenada();
}

int main(int argc, char const *argv[]){
    teste();
} 
/**
 * Função principal da aplicação
 * @param argc
 * @param argv
 * @return int
 *
 * @author Maria Eduarda Ribeiro Facio
 */
/*int main(int argc, char const *argv[])
{
    Grafo *grafo_th = new Grafo();

    // LEITURA DO ARQUIVO:

    string nomeArquivo = "./input/grafo.csv";
    // Abertura do arquivo:
    fstream arq;
    arq.open(nomeArquivo, ios::in);
    if (!arq.is_open()){
        std::cout << "FALHA AO ABRIR O ARQUIVO" << endl;
        exit(0);
    }

    string line;
    getline(arq, line);
    // A primeira linha do arquivo é o numero de nós/estados:
    int n = stoi(line);

    // cout para conferência da leitura:
    // cout << n << endl;

    // Leitura das "n" linhas com: id do nó;estado do nó;custo do nó
    for(int i = 0; i < n; i++)
    {
        // Separa a linha:
        getline(arq, line);
        stringstream ss(line);
        string aux;
        vector<string> vet;
        while (getline(ss, aux, ';')) 
            vet.push_back(aux);

        // Resgata nó:
        int id = stoi(vet[0]); 
        string estado = vet[1];
        int custo = stoi(vet[2]);

        // cout para conferência da leitura:
        // cout << id << ";" << estado << ";" << custo << endl;

        // Insere nó no grafo:
        grafo_th->insereNo(id, estado, custo);
    }

    // Leitura das linhas com: id do nó de saida;id do nó de chegada;custo da aresta;regra associada
    // Enquanto ainda houverem linhas a serem lidas:
    while (getline(arq, line))
    {
        // Separa a linha:
        stringstream ss(line);
        string aux;
        vector<int> vet_;
        while (getline(ss, aux, ';')) 
            vet_.push_back(stoi(aux));

        // Resgata aresta:
        int origemId = vet_[0];
        int destinoId = vet_[1];
        int custo = vet_[2];
        int regra = vet_[3];

        // cout para conferência da leitura:
        // cout << origemId << ";" << destinoId << ";" << custo << ";" << regra << endl;

        // Insere aresta no grafo:
        grafo_th->insereAresta(origemId, destinoId, custo, regra);
    }


    // MENUS DE APLICAÇÃO:
    cout << "------------------------------ PROBLEMA 2: TORRE DE HANOI ------------------------------" << endl
         << endl;
    cout << "O problema das Torres De Hanói é um quebra-cabeça criado pelo matemático francês Edourd Lucas em 1883.";
    cout << " Esse quebra-cabeça consiste de 3 hastes e \"n\" discos (vamos usar 4), inicialmente dispostos em ordem decrescente de tamanho na haste esquerda (A).";
    cout << " O objetivo desse jogo é transferir os \"n\" discos da haste inicial para a haste mais à direita (C).";
    cout << " Cada movimento consiste em retirar um disco do topo de uma haste e passar para o topo de outra haste, seguindo as regras:" << endl;
    cout << "   -Os discos devem ser movidos um de cada vez." << endl;
    cout << "   -Um disco maior NÃO pode ficar por cima de um disco menor." << endl
         << endl;
    cout << "As regras de transição de estado para esse problema são:" << endl;
    cout << "   R1: A -> B" << endl;
    cout << "   R2: A -> C" << endl;
    cout << "   R3: B -> A" << endl;
    cout << "   R4: B -> C" << endl;
    cout << "   R5: C -> A" << endl;
    cout << "   R6: C -> B" << endl
         << endl;

    print_menu();

    arq.close();
    grafo_th->~Grafo();
    return 0;
}*/
