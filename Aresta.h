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
 *                 Definição da Classe Aresta              *
 ***********************************************************/

#ifndef ARESTA_H
#define ARESTA_H
using namespace std;

class Aresta {
private:
    int origemId;
    int destinoId;
    int custo;
    int regra; //Cada aresta possui uma regra de transição associada.
    /* Regras de transição
    0: A->B
    1: A->C
    2: B->A
    3: B->C
    4: C->A
    5: C->B */

public:
    //Constructor
    Aresta(int origemId, int destinoId, int custo, int regra);
    //Destructor
    ~Aresta();
    //Getters
    int getOrigemId();
    int getDestinoId();
    int getCusto();
    int getRegra();
};

#endif //ARESTA_H
