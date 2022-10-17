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

/**
 * Função principal da aplicação
 * @param argc
 * @param argv
 * @return int
 *
 * @author Mara de Lemos Gomes
 */
int main(int argc, char const *argv[])
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

        // Insere aresta no grafo:
        grafo_th->insereAresta(origemId, destinoId, custo, regra);
    }

    arq.close();

    return 0;
}
