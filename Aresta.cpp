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
 *       Implementação dos métodos da classe Aresta        *
 ***********************************************************/

#include "Aresta.h"

/**
 * Construtor do objeto aresta
 * @param origemId
 * @param destinoId
 * @param custo
 * @param regra
 * 
 * @author Mara de Lemos Gomes
 */
Aresta::Aresta(int origemId, int destinoId, int custo, int regra) {
    this->origemId = origemId;
    this->destinoId = destinoId;
    this->custo = custo;
    this->regra = regra;
}

/**
 * Destrutor do objeto aresta
 * 
 * @author Mara de Lemos Gomes
 */
Aresta::~Aresta() {
}

/**
 * Obter o identificador do nó origem
 * @return int
 * 
 * @author Mara de Lemos Gomes
 */
int Aresta::getOrigemId() {
    return this->origemId;
}

/**
 * Obter o identificador do nó destino
 * @return int
 * 
 * @author Mara de Lemos Gomes
 */
int Aresta::getDestinoId() {
    return this->destinoId;
}

/**
 * Obter o custo da aresta
 * @return int
 * 
 * @author Mara de Lemos Gomes
 */
int Aresta::getCusto() {
    return this->custo;
}

/**
 * Obter a regra de transição associada a aresta
 * @return int
 * 
 * @author Mara de Lemos Gomes
 */
int Aresta::getRegra() {
    return this->regra;
}