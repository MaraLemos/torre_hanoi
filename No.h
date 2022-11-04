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
 *                 Definição da Classe Nó                  *
 ***********************************************************/

#ifndef NO_H
#define NO_H

#include <vector>
#include <string>
#include "Aresta.h"

using namespace std;

class No {
private:
    int id;
    string estado; //Exemplo AAAA, BAAA
    int custo; //Custo associado a heurística
    vector <Aresta*> arestas;

    No* pai;

public:
    //Constructor
    No(int id, string estado, int custo);
    //Destructor
    ~No();
    //Getters
    int getId();
    int getCusto();
    string getEstado();
    vector <Aresta*> getArestas();
    //Other methods
    void insereAresta(int destinoId, int custo, int regra);
    void removeAresta(int destinoId);

    No* getPai();
    void setPai(No* pai);
};
#endif //NO_H
