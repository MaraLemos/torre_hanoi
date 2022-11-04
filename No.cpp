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
 *         Implementação dos métodos da classe No          * 
 ***********************************************************/
#include "No.h"

/**
 * Constrututor do objeto No
 * @param estado
 * @param custo
 * 
 * @author Mara de Lemos Gomes
 */
No::No(int id, string estado, int custo) {
    this->id = id;
    this->estado = estado;
    this->custo = custo;
    this->pai = nullptr;
}

/**
 * Destrutor do objeto No
 * 
 * @author Mara de Lemos Gomes
 */
No::~No() {
    this->arestas.clear();
}

/**
 * Obter o identificador do No
 * @return int
 * 
 * @author Mara de Lemos Gomes
 */
int No::getId() {
    return this->id;
}

/**
 * Obter o custo do No
 * @return int
 * 
 * @author Mara de Lemos Gomes
 */
int No::getCusto(){
    return this->custo;
}

/**
 * Obter o estado do No
 * @return string
 * 
 * @author Mara de Lemos Gomes
 */
string No::getEstado(){
    return this->estado;
}

/**
 * Obter arestas do No
 * @return vector <Aresta*>
 * 
 * @author Mara de Lemos Gomes
 */
vector <Aresta*> No::getArestas(){
    return this->arestas;
}

/**
 * Insere aresta associada ao No
 * @param destinoId
 * @param custo
 * 
 * @author Mara de Lemos Gomes
 */
void No::insereAresta(int destinoId, int custo, int regra){
    Aresta* aresta = new Aresta(this->getId(), destinoId, custo, regra);
    this->arestas.push_back(aresta);
}

/**
 * Remove aresta associada ao No
 * @param destinoId
 * 
 * @author Mara de Lemos Gomes
 */
void No::removeAresta(int destinoId){
    for(int i=0; i < this->arestas.size(); i++){
        Aresta* aresta = this->arestas.at(i);
        if(aresta->getDestinoId() == destinoId)
            this->arestas.erase(this->arestas.begin() + i);
    }
}

No* No::getPai(){
    return this->pai;
}

void No::setPai(No* no){
    this->pai = no;
}