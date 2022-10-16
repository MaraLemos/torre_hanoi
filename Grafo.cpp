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
 *       Implementação dos métodos da classe Grafo         *
 ***********************************************************/

#include "Grafo.h"

/**
 * Construtor do objeto grafo
 *
 * @author Mara de Lemos Gomes
 */
Grafo::Grafo() {
    this->totalArestas = 0;
}

/**
 * Destrutor do objeto grafo
 *
 * @author Mara de Lemos Gomes
 */
Grafo::~Grafo() {
    this->nos.clear();
}

/**
 * Verifica se nó pertence ao grafo
 * @param id
 * @return bool
 * 
 * @author Mara de Lemos Gomes
 */
bool Grafo::existeNo(int id){
    std::find(this->nos.begin(), this->nos.end(), id) != this->nos.end() ? true : false;
}

/**
 * Obter um nó do grafo, retorna nulo caso o nó não pertença ao grafo
 * @param id
 * @return No*
 *
 * @author Mara de Lemos Gomes
 */
No* Grafo::getNo(int id){
    if(existeNo(id)) {
        return this->nos.at(id);
    } else {
        return nullptr;
    }
}

/**
 * Retorna a quantidade de arestas do Grafo
 * @return int
 * 
 * @author Mara de Lemos Gomes
 */
int Grafo::getTotalArestas(){
    return this->totalArestas;
}

/**
 * Insere novo nó ao Grafo
 * @param id
 * @param estado
 * @param custo
 * 
 * @author Mara de Lemos Gomes
 */
void Grafo::insereNo(int id, string estado, int custo){
    No* no = new No(id, estado, custo);
    this->nos.push_back(no);
}

/**
 * Insere nova aresta ao Grafo
 * @param origemid
 * @param destinoId
 * @param custo
 * @param regra
 * 
 * @author Mara de Lemos Gomes
 */
void Grafo::insereAresta(int origemId, int destinoId, float custo, int regra){
    if(existeNo(origemId) && existeNo(destinoId)){
        No* no = this->nos.at(origemId);
        no->insereAresta(destinoId, custo, regra);
        no = this->nos.at(destinoId);
        no->insereAresta(origemId, custo, regra);
        this->totalArestas++;
    }
}

/**
 * Remove nó do Grafo
 * @param id
 * 
 * @author Mara de Lemos Gomes
 */
bool Grafo::removeNo(int id){
    if(existeNo(id)){
        this->nos.erase(this->nos.begin() + id);
        return true;
    }
    return false;
}

/**
 * Remove aresta do Grafo
 * @param origemid
 * @param destinoId
 * 
 * @author Mara de Lemos Gomes
 */
bool Grafo::removeAresta(int origemId, int destinoId){
    if(existeNo(origemId) && existeNo(destinoId)){
        No* no = this->nos.at(origemId);
        no->removeAresta(destinoId);
        no = this->nos.at(destinoId);
        no->removeAresta(origemId);
        this->totalArestas--;
        return true;
    }
    return false;
}

void Grafo::imprime(){

}