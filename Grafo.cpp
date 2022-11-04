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

    for(int i = 0; i < nos.size(); i++)
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
    for (int i = 0; i < this->nos.size(); i++){
        cout << " #" << this->nos.at(i)->getId() << " ";
        cout << this->nos.at(i)->getEstado() << " - arestas com os nos: ";
        for (int j = 0; j < this->nos.at(i)->getArestas().size(); j++){
            cout << this->nos.at(i)->getArestas().at(j)->getDestinoId();
            cout << " (custo: " << this->nos.at(i)->getArestas().at(j)->getCusto() << ") ";
        }
        cout << endl;
    }
    
}

void bubble_sort (vector<No*> &abertos, vector<int> &abertos_custo) {
    int auxCusto;
    No* auxNo;

    for (int k = abertos_custo.size() - 1; k > 0; k--) {

        for (int j = 0; j < k; j++) {

            if (abertos_custo[j] > abertos_custo[j + 1]) {
                auxCusto = abertos_custo[j];
                abertos_custo[j] = abertos_custo[j + 1];
                abertos_custo[j + 1] = auxCusto;

                auxNo = abertos[j];
                abertos[j] = abertos[j + 1];
                abertos[j + 1] = auxNo;
            }
        }
    }
}

int findIndex(const vector<No*> &arr, No* item) {

    for (auto i = 0; i < arr.size(); ++i) {
        if (arr[i] == item)
            return i;
    }

    return -1;
}

void Grafo::buscaOrdenada(){

    vector<No*> abertos;
    vector<int> abertos_custo;
    vector<No*> fechados;
    int custo_atual;
    
    No* atual = this->nos.at(0);

    abertos.push_back(this->nos.at(0));
    abertos_custo.push_back(0);

    while(atual->getEstado() != "Z"){

        atual = abertos.at(0);
        custo_atual = abertos_custo.at(0);

        abertos.erase(abertos.begin());
        abertos_custo.erase(abertos_custo.begin());

        cout << "Estado atual: " << atual->getEstado() << "(" << custo_atual << ")" << endl;

        if(atual->getEstado() == "Z")
            break;

        for (int i = 0; i < atual->getArestas().size(); i++){
            No* destino = getNo(atual->getArestas().at(i)->getDestinoId());

            if(find(fechados.begin(), fechados.end(), destino) != fechados.end()){
                //Descarta ciclos
            }else if(find(abertos.begin(), abertos.end(), destino) != abertos.end()){

                //Elemento já está na lista de abertos
                auto pos = findIndex(abertos, destino);
                if(pos != -1){
                    if(abertos_custo.at(pos) > atual->getArestas().at(i)->getCusto() + custo_atual){
                        cout << "Poda do estado " << destino->getEstado() << "(" << abertos_custo[pos] << ")" << endl;
                        abertos_custo[pos] = atual->getArestas().at(i)->getCusto() + custo_atual;
                        destino->setPai(atual);
                        abertos[pos] = destino;
                    }else{
                        cout << "Poda do estado " << destino->getEstado() << "(" << atual->getArestas().at(i)->getCusto() + custo_atual << ")" << endl;
                    }
                }

            }else{
                destino->setPai(atual);
                abertos.push_back(destino);
                abertos_custo.push_back(atual->getArestas().at(i)->getCusto() + custo_atual);
            }
        }

        fechados.push_back(atual);

        //ordena lista de abertos
        bubble_sort(abertos, abertos_custo);

        cout << "Lista de abertos: ";
        for (int i = 0; i < abertos.size(); i++){
            cout << abertos.at(i)->getEstado() << "(";
            cout << abertos_custo.at(i) << ") ";
        }

        cout << endl << "________________________________________________" << endl;
    }

    cout << "O algoritmo chegou ao estado solucao Z com custo " << custo_atual << endl;
    cout << "Caminho solução: Z ->";
    while(atual->getPai() != nullptr){
        cout << atual->getPai()->getEstado() << " -> ";
        atual = atual->getPai();
    } 
}