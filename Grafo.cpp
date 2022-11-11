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
    // std::find(this->nos.begin(), this->nos.end(), id) != this->nos.end() ? true : false;

    for(size_t i = 0; i < nos.size(); i++)
        if(nos[i]->getId() == id)
            return true;

    return false;
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
void Grafo::insereAresta(int origemId, int destinoId, int custo, int regra){
    if(existeNo(origemId) && existeNo(destinoId)){
        No* no = this->nos.at(origemId);
        no->insereAresta(destinoId, custo, regra);
        no = this->nos.at(destinoId);
        switch (regra)
        {
        case 0: regra = 2; break;
        case 1: regra = 4; break;
        case 2: regra = 0; break;
        case 3: regra = 5; break;
        case 4: regra = 1; break;
        case 5: regra = 3; break;
        default: break;
        }
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
        vector<Aresta*> arestas = getNo(id)->getArestas();
        for(size_t i = 0; i < arestas.size(); i++)
            removeAresta(id, arestas.at(i)->getDestinoId());
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

/**
 * Imprime o Grafo
 * 
 * @author Mara de Lemos Gomes
 */
void Grafo::imprime(){
    for (size_t i = 0; i < this->nos.size(); i++){
        cout << " #" << this->nos.at(i)->getId() << " ";
        cout << this->nos.at(i)->getEstado() << " - arestas com os nos: ";
        for (size_t j = 0; j < this->nos.at(i)->getArestas().size(); j++){
            cout << this->nos.at(i)->getArestas().at(j)->getDestinoId();
            cout << " (custo: " << this->nos.at(i)->getArestas().at(j)->getCusto() << ") ";
        }
        cout << endl;
    }
    
}

struct No_busca_ordenada{
    No* no;
    int custo;
    No_busca_ordenada* pai;
};

/**
 * Função aux de buscaOrdenada
 * Verifica se estado pode ser inserido na arvore caso não provoque ciclos
 * @param novo
 * @param arvore
 * 
 * @author Mara de Lemos Gomes
 */
bool existeCiclo(No* novo, No_busca_ordenada* arvore){
    
    while (arvore != nullptr){
        if (arvore->no == novo){
            return true;
        }
        arvore = arvore->pai;
    }
    return false;
}

/**
 * Algoritmo de busca ordenada
 * @param estado_solucao
 * 
 * @author Mara de Lemos Gomes
 */
void Grafo::buscaOrdenada(string estado_solucao){

    ofstream saida;
    saida.open("output\\buscaOrdenada.txt", ios::trunc);

    vector<No_busca_ordenada*> abertos;
    vector<No_busca_ordenada*> fechados;
    
    No_busca_ordenada* atual = new No_busca_ordenada();
    atual->no = this->nos.at(0);
    atual->pai = nullptr;
    atual->custo = 0;

    abertos.push_back(atual);

    do{

        atual = abertos.at(0);
        abertos.erase(abertos.begin());

        if(saida.is_open())
            saida << "Estado atual: " << atual->no->getEstado() << "(" << atual->custo << ")" << endl;

        for (size_t i = 0; i < atual->no->getArestas().size(); i++){
            
            No* novo_estado = getNo(atual->no->getArestas().at(i)->getDestinoId());

            if(!existeCiclo(novo_estado, atual)){

                No_busca_ordenada* novo = new No_busca_ordenada();
                novo->no = novo_estado;
                novo->pai = atual;
                novo->custo = atual->no->getArestas().at(i)->getCusto() + atual->custo;

                size_t j = 0;
                for(; j < abertos.size(); j++){
                    if(abertos.at(j)->no == novo_estado){ //Verifica se no já está na lista de abertos
                        if (abertos.at(j)->custo > novo->custo){ //Verifica qual nó tem o menor custo, poda o de maior custo
                            if(saida.is_open())
                                saida << "Poda do estado " << abertos.at(j)->no->getEstado() << "(" << abertos.at(j)->custo << ")" << endl;
                            abertos.at(j) = novo;
                        }else{
                            if(saida.is_open())
                                saida << "Poda do estado " << novo->no->getEstado() << "(" << novo->custo << ")" << endl;
                        }
                        break;
                    }
                }
                if(j == abertos.size()) //Se nó não está na lista de abertos
                    abertos.push_back(novo);
            }
        }

        //Fecha estado com os nós filhos já vizitados
        fechados.push_back(atual);

        //ordena lista de abertos
        sort(abertos.begin(),abertos.end(), [](No_busca_ordenada* a, No_busca_ordenada* b){ return a->custo <  b->custo; });

        //Escrita no arquivo de saida
        if(saida.is_open()){
            saida << "Lista de estados abertos: ";
            for (size_t i = 0; i < abertos.size(); i++){
                saida << abertos.at(i)->no->getEstado() << "(";
                saida << abertos.at(i)->custo << ") ";
            }
            saida << endl;
            saida << "Lista de estados fechados: ";
            for (size_t i = 0; i < fechados.size(); i++){
                saida << fechados.at(i)->no->getEstado() << "(";
                saida << fechados.at(i)->custo << ") ";
            }
            saida << endl << "________________________________________________" << endl;
        }

    }while(atual->no->getEstado() != estado_solucao);

    //Escrita no arquivo de saida
    if(saida.is_open()){
        saida << "O algoritmo chegou ao estado solucao " << estado_solucao << " com custo " << atual->custo << endl;
        saida << "Caminho solucao: ";

        vector<string> resultado;
        while(atual->pai != nullptr){
            resultado.push_back(atual->pai->no->getEstado());
            atual = atual->pai;
        }
        for (int i = resultado.size() - 1; i >= 0 ; i--){
            saida << resultado[i] << " -> ";
        }
        saida << estado_solucao << endl;
        cout << "Resultados no arquivo output/buscaOrdenada.txt" << endl;
    }
}