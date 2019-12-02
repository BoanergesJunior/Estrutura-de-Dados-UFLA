#include <iostream>
#define cout Serial.print
class noh{
  friend class ABB;
  public:
    noh(String dB){this->dB = dB; esq = NULL; dir = NULL, pai = NULL;}
  private:
    String dB; //qualidade do pacote
//  String local;
    
    noh* esq;
    noh* dir;
    noh* pai;
};

class ABB{
  public:
    ABB(){raiz = NULL;}
    ~ABB(){D(raiz);}
    void D(noh* atual);
    void insere(String dB);
    /*METODOS PARA GARANTIR REMOCAO!
    void ordem(){ordemAux(raiz);}
    void ordemAux(noh* atual);
    void preOrdem(){preOrdemAux(raiz);}
    void preOrdemAux(noh* atual);
    void remove(int dB);
    void transplanta(noh *antigo,noh* novo);
    noh* minimoAux(noh* atual);
    int nivel(int dB);*/
    noh* getRaiz(){return raiz;};
    void ordem(){ordemAux(raiz);}
    void ordemAux(noh* atual);
  private:
    //noh* busca(noh* aux);
    noh* raiz;
};

void ABB::D(noh* atual){
  if(atual != NULL){
    D(atual->esq);
    D(atual->dir);
    delete atual;
  }
}

void ABB::insere(String dB){
  noh* novo = new noh(dB); // cria um novo no
  noh* aux = raiz; 
  noh* anterior = NULL;
  //insere em arvore vazia
  if(raiz == NULL)
    raiz = novo; 
  else{
  //se nao procura proxima posicao disponivel
    while(aux != NULL){
      anterior = aux;
      if(aux->dB > dB)
        aux = aux->esq;
      else
        aux = aux->dir;
    }
    //novo.pai = novo.anterior
    novo->pai = anterior;
    if(anterior->dB > novo->dB)
      anterior->esq = novo;
    else
      anterior->dir = novo;
  }
  if(raiz == NULL){Serial.println("raiz nula");}
}


void ABB::ordemAux(noh* atual){
  if(atual != NULL){
    ordemAux(atual->esq);
    cout(atual->dB + "|");
    ordemAux(atual->dir);
  }
}
/*###################################################################################
METODOS PARA GARANTIR REMOCAO!

int ABB::nivel(int dB){
  noh* aux = raiz;
  int i = 0;
  if(raiz->dB == dB)
    return 0;
  else{
    while(aux->dB != dB){
      if(aux->dB > dB)
        aux = aux->esq;
      else
        aux = aux->dir;
      i++;
    }
  }
  return i;
}
*/
/*noh* ABB::minimoAux(noh* atual){
  while(atual->esq != NULL)
    atual = atual->esq;
  return atual;
}

noh* ABB::busca(noh* aux){
  noh* atual = raiz;
  while(atual != NULL){
    if(atual->dB == aux->dB)
      return atual;
    else if(atual->dB > aux->dB)
      atual = atual->esq;
    else
      atual = atual->dir;
  }
  return atual;
}

void ABB::remove(int dB){
  noh* aux = new noh(dB);
  noh* remover = busca(aux);
  if(remover == NULL)
    cout << "ERRO";
  else{
    if(remover->esq == NULL)
      transplanta(remover, remover->dir);
    else if(remover->dir == NULL)
      transplanta(remover, remover->esq);
    else{
      noh* sucessor = minimoAux(remover->dir);
      if(sucessor->pai != remover){
        transplanta(sucessor, sucessor->dir);
        sucessor->dir = remover->dir;
        sucessor->dir->pai = sucessor;
      }
      transplanta(remover, sucessor);
      sucessor->esq = remover->esq;
      sucessor->esq->pai = sucessor;
    }
    delete remover;
  }
}

void ABB::transplanta(noh* antigo, noh* novo){
  if(raiz == antigo)
    raiz = novo;
  else if(antigo == antigo->pai->esq)
    antigo->pai->esq = novo;
  else
    antigo->pai->dir = novo;
  if(novo != NULL)
    novo->pai = antigo->pai;
}
void ABB::ordemAux(noh* atual){
  if(atual != NULL){
    ordemAux(atual->esq);
    int altura = nivel(atual->dB);
    cout << atual->dB << "/" << altura << " ";
    ordemAux(atual->dir);
  }
}

void ABB::preOrdemAux(noh* atual){
  if(atual != NULL){
    int altura = nivel(atual->dB);
    cout << atual->dB << "/" << altura << " ";
    preOrdemAux(atual->esq);
    preOrdemAux(atual->dir);
  }
}*/
