#include <iostream>

using namespace std;

#define INF 65535

template <typename I>
class Item
{
  private:
    I item;

  public:
    Item();
    I getItem();
    void setItem(I item);
};

template <typename I>
Item<I>::Item() {}

template <typename I>
I Item<I>::getItem() { return item; }

template <typename I>
void Item<I>::setItem(I item) { this->item = item; }

template <typename N>
class No
{
  private:
    Item<N> item;
    Item<int> custo;
    Item<string> cor;
    int pos, posPai;
    No<N> *prox;
    No<N> *ant;

  public:
    No();
    N getItem();
    int getCusto();
    string getCor();
    int getPos();
    int getPosPai();
    No<N> *getProx();
    No<N> *getAnt();
    void setItem(N item);
    void setCusto(int custo);
    void setCor(string cor);
    void setPos(int pos);
    void setPosPai(int posPai);
    void setProx(No<N> *prox);
    void setAnt(No<N> *ant);
};

template <typename N>
No<N>::No()
{
    setProx(NULL);
    setAnt(NULL);
    cor.setItem("Branco");
    custo.setItem(0);
}

template <typename N>
N No<N>::getItem() { return item.getItem(); }

template <typename N>
int No<N>::getCusto() { return custo.getItem(); }

template <typename N>
string No<N>::getCor() { return cor.getItem(); }

template <typename N>
int No<N>::getPos() { return pos; }

template <typename N>
int No<N>::getPosPai() { return posPai; }

template <typename N>
No<N> *No<N>::getProx() { return prox; }

template <typename N>
No<N> *No<N>::getAnt() { return ant; }

template <typename N>
void No<N>::setItem(N item) { this->item.setItem(item); }

template <typename N>
void No<N>::setCusto(int custo) { this->custo.setItem(custo); }

template <typename N>
void No<N>::setCor(string cor) { this->cor.setItem(cor); }

template <typename N>
void No<N>::setPos(int pos) { this->pos = pos; }

template <typename N>
void No<N>::setPosPai(int posPai) { this->posPai = posPai; }

template <typename N>
void No<N>::setProx(No<N> *prox) { this->prox = prox; }

template <typename N>
void No<N>::setAnt(No<N> *ant) { this->ant = ant; }

template <typename L>
class Lista
{
  private:
    No<L> *prim;
    No<L> *ult;
    int ordem;

  public:
    Lista();
    Lista(int n);
    Lista(Lista<L> *base);
    void inicializa();
    void setUlt(No<L> *ult);
    No<L> *getPrim();
    No<L> *getUlt();
    int getOrdem();
    No<L> *insere();
    No<L> *insere(string cor);
    void insere(No<L> *v);
    bool vazia();
    No<L> *busca(int pos, bool posInicial);
    int busca(No<L> *n);
    void show(bool corFlag, bool custoFlag);
};

template <typename L>
Lista<L>::Lista() { inicializa(); }

template <typename L>
Lista<L>::Lista(int n)
{
    inicializa();
    for (int i = 0; i < n; i++)
        insere();
}

template <typename L>
Lista<L>::Lista(Lista<L> *base)
{
    inicializa();
    No<L> *aux = base->getPrim()->getProx();
    for (int i = 0; i < base->getOrdem(); i++)
    {
        insere(aux);
        aux = aux->getProx();
    }
}

template <typename L>
void Lista<L>::inicializa()
{
    prim = new No<L>();
    ult = prim;
    ordem = 0;
}

template <typename L>
void Lista<L>::setUlt(No<L> *ult) { this->ult = ult; }

template <typename L>
No<L> *Lista<L>::getPrim() { return prim; }

template <typename L>
No<L> *Lista<L>::getUlt() { return ult; }

template <typename L>
int Lista<L>::getOrdem() { return ordem; }

template <typename L>
No<L> *Lista<L>::insere()
{
    No<L> *n = new No<L>();
    ult->setProx(n);
    n->setAnt(ult);
    n->setPos(++ordem);
    ult = n;
    return n;
}

template <typename L>
No<L> *Lista<L>::insere(string cor)
{
    No<L> *aux = insere();
    aux->setCor(cor);
    return aux;
}

template <typename L>
void Lista<L>::insere(No<L> *v)
{
    No<L> *aux = insere(v->getCor());
    aux->setCusto(v->getCusto());
    aux->setItem(v->getItem());
}

template <typename L>
bool Lista<L>::vazia() { return prim == ult; }

template <typename L>
No<L> *Lista<L>::busca(int pos, bool posInicial)
{
    No<L> *aux = prim->getProx();
    if (posInicial)
    {
        while (aux->getPos() != pos)
            aux = aux->getProx();
    }
    else
    {
        for (int i = 1; i < pos; i++)
        {
            aux = aux->getProx();
        }
    }
    return aux;
}

template <typename L>
int Lista<L>::busca(No<L> *n)
{
    No<L> *aux = prim;
    int pos = 1;
    while (aux->getPos() != n->getPos())
    {
        if (pos <= ordem)
        {
            aux = aux->getProx();
            pos++;
        }
    }
    return pos;
}

template <typename L>
void Lista<L>::show(bool corFlag, bool custoFlag)
{
    No<L> *aux = prim->getProx();
    while (aux != NULL)
    {
        if (corFlag)
            cout << aux->getCor() << ":";
        if (custoFlag)
            cout << aux->getCusto() << " -> ";
        aux = aux->getProx();
    }
    cout << endl;
}

template <typename G>
class Graph
{
  private:
    Lista<G> *vertices;
    int **mat;
    int n, tam;

  public:
    Graph();
    Graph(int n);
    Graph(int n, int tam);
    void initialize();
    Lista<G> *getVertices();
    void setVertices(Lista<G> *l);
    int **getAdj();
    void insertEdge(int u, int v, int custo);
    void removeEdge(int u, int v);
    void desconectNode(int u);
    void print();
    int getN();
    int getTam();
    int **getMat();
};

template <typename G>
Graph<G>::Graph()
{
    this->n = 0;
    initialize();
}

template <typename G>
Graph<G>::Graph(int n)
{
    this->n = n;
    initialize();
}

template <typename G>
Graph<G>::Graph(int n, int tam)
{
    this->n = n;
    this->tam = tam;
    initialize();
}

template <typename G>
void Graph<G>::initialize()
{  
    vertices = new Lista<G>(n);

    mat = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        mat[i] = new int[n + 1];
        //cout << n << endl;
        for (int j = 0; j <= n; j++)
            mat[i][j] = 0;
    }
}

template <typename G>
int **Graph<G>::getMat() { return mat; }

template <typename G>
Lista<G> *Graph<G>::getVertices() { return vertices; }

template <typename G>
void Graph<G>::setVertices(Lista<G> *l) { this->vertices = l; }

template <typename G>
int **Graph<G>::getAdj() { return mat; }

template <typename G>
void Graph<G>::insertEdge(int u, int v, int custo)
{
    mat[u][v] = custo;
    //cout<<"MAT ["<<u<<"] ["<<v<<"] = "<<custo<<endl;
    mat[v][u] = custo;
    tam++;
}

template <typename G>
int Graph<G>::getN() { return n; }

template <typename G>
int Graph<G>::getTam() { return tam; }

template <typename G>
void Graph<G>::removeEdge(int u, int v)
{
    mat[u][v] = 0;
    mat[v][v] = 0;
}

template <typename G>
void Graph<G>::desconectNode(int u)
{
    for (int i = 0; i < n; i++)
        removeEdge(u, i);
}

template <typename G>
void Graph<G>::print()
{
    int i, j;
    int v;
    cout << "Graph em matriz de adj:" << endl;
    for (i = 1; i <= n; ++i)
    {
        cout << "| ";
        for (j = 1; j <= n; ++j)
        {
            v = mat[i][j];
            if (mat[i][j] >= 0)
                cout << v;
            else
                cout << -1;
            cout << ((v < 10 || v < 0) ? " |" : "|");
        }
        cout << endl;
    }
}

template<typename H>
class Heapsort{
private:
	Lista<H> *A;
	int tamanho, tamHeap;
public:
	Heapsort();
	Heapsort(Lista<H> *base);	
	int PAI(int i);
	int ESQ(int i);
	int DIR(int i);
	void heapfica(int i, int tamRestante);
	void troca(No<H> *a, No<H> *b);
	void constroiHeap();
	void reconstroiHeap(int tam);
	Lista<H> *getHeap();
};

template<typename H>
Heapsort<H>::Heapsort() {}

template<typename H>
Heapsort<H>::Heapsort(Lista<H> *base) {
	A = base;
	tamanho = base->getOrdem();
	constroiHeap();
	for (int i = tamanho; i > 1; i--) {
		tamHeap--;
		heapfica(i, tamHeap);
	}
}

template<typename H>
int Heapsort<H>::PAI(int i) { return i/2; }

template<typename H>
int Heapsort<H>::ESQ(int i) { return 2*i; }

template<typename H>
int Heapsort<H>::DIR(int i) { return 2*i + 1; }

template<typename H>
void Heapsort<H>::heapfica(int i, int tamRestante) {
	int l = ESQ(i), r = DIR(i), menor = i;
	No<H> *x, *y;
	if(l <= tamRestante) {
		x = A->busca(l, false);
		y = A->busca(i, false);
		if(x->getCusto() < y->getCusto()) {
			menor = l;
		}
	}
	if(r <= tamRestante) {
		x = A->busca(r, false);
		y = A->busca(menor, false);	
		if(x->getCusto() < y->getCusto()) {
			menor = r;
		}
	}
	if (menor != i) {
		troca(A->busca(menor, false), A->busca(i, false));
		heapfica(menor, tamRestante);
	}
}

template<typename H>
void Heapsort<H>::troca(No<H> *a, No<H> *b) {
	No<H> *proxA = a->getProx();
	No<H> *antB = b->getAnt();
	No<H> *aux;

	aux = b->getProx();
	a->setProx(aux);
	if (aux != NULL) aux->setAnt(a);

	b->setProx(proxA);
	if (proxA != NULL) proxA->setAnt(b);
	else A->setUlt(b);

	aux = a->getAnt();
	b->setAnt(aux);
	if (aux != NULL) aux->setProx(b);

	a->setAnt(antB);
	if (antB != NULL) antB->setProx(a);
	else A->getPrim()->setProx(a);
}


template<typename H>
void Heapsort<H>::constroiHeap() {
	tamHeap = tamanho;
	for (int i = tamanho/2; i > 0; i--) {
		heapfica(i, tamHeap);
	}
}

template<typename H>
void Heapsort<H>::reconstroiHeap(int tam) {
	tamanho = tam;
	constroiHeap();
} 

template<typename H>
Lista<H> *Heapsort<H>::getHeap() { return A; }

template<typename D>
class Djikstra{
private:
	Graph<D> *arvore, *result;
	Lista<D> *refLista, *Q, *novaLista;
	No<D> *refNo, *u, *v;
	int n, posiU, posiPai, extraidos, nResult, tamResult;
	int **adj;
	Heapsort<D> *heapificador;
public:
	Djikstra();
	Djikstra(Graph<D> *base, int inicio, int fim);
	void inicializa(No<D> *s);
	Graph<D> *getResult();
	No<D> *extraeMin(Lista<D> *L);
	void relaxa(No<D> *u, No<D> *v, int w);
};

template<typename D>
Djikstra<D>::Djikstra() {}

template<typename D>
Djikstra<D>::Djikstra(Graph<D> *base, int inicio, int fim) {
	adj = base->getAdj();//matriz de adjacencia
	refLista = base->getVertices();//lista de vertices	
	n = refLista->getOrdem();//ordem do grafo
	refNo = refLista->getPrim()->getProx();//primeiro no da lista de vertices

	inicializa(refLista->busca(inicio, false));

	arvore = new Graph<D>(n, base->getTam());//base é o grafo recebido
	arvore->setVertices(refLista);

	Q = new Lista<D>(refLista); 
	heapificador = new Heapsort<D>(Q);
    //Q->show(false, true);
    
    extraidos = 0;
	while(n - extraidos) {
		u = extraeMin(Q);
        //cout << "peguei o u, o custo atual dele eh: " << u->getCusto() << endl;
        posiU = u->getPos();
		adj[posiU][0] = posiU;
		posiPai = u->getPosPai();

		arvore->insertEdge(posiU, posiPai, adj[posiU][posiPai]);
		for (int i = 1; i <= n; i++) {
			if(adj[posiU][i] != 0) {
				refNo = refLista->busca(i, true);
				if (adj[i][0] != i) v = Q->busca(i, true);
				else v = NULL;
				relaxa(u, v, adj[posiU][i]);
                //cout << " u v e adj[posiU][i] " << u <<" "<< v <<" "<< adj[posiU][i]<<endl;
            }
		}
	}

	novaLista = new Lista<D>();

	posiU = fim;
	while(posiU != 0) {
		refNo = refLista->busca(posiU, true);
		novaLista->insere(refNo);
		posiU = refNo->getPosPai();
	}
	nResult = novaLista->getOrdem();
	tamResult = nResult-1;
	result = new Graph<D>(nResult, tamResult);
	result->setVertices(novaLista);	

	posiU = fim;
	int i = 1;
	while(posiU != inicio) {
		refNo = refLista->busca(posiU, true);
		posiPai = refNo->getPosPai();
        //cout<<"PosiU ["<<posiU<<"] PosiPai["<<posiPai<<"] "<<endl;
        //cout<<"CUSTO DO VERTICE SENDO ADD "<<adj[posiU][posiPai]<<endl;
		result->insertEdge(i, i+1, adj[posiU][posiPai]);
        //result->print();
		i++;
		posiU = posiPai;
	}

}

template<typename D>
void Djikstra<D>::inicializa(No<D> *s) {
	while(refNo != NULL) {
		refNo->setCusto(INF); 
		refNo = refNo->getProx();
	}
	s->setCusto(0);
	s->setPosPai(0);
}

template<typename D>
Graph<D> *Djikstra<D>::getResult() { return result; };

template<typename D>
No<D> *Djikstra<D>::extraeMin(Lista<D> *L) {
	No<D> *aux, *min, *proxMin, *antAux, *prim;

	heapificador->reconstroiHeap(n - ++extraidos);
	prim = L->getPrim();

	min = prim->getProx(); 
	proxMin = min->getProx();
	aux = L->getUlt();	
	antAux = aux->getAnt();
	
	aux->setAnt(NULL);
	if (antAux != NULL) 			
		antAux->setProx(NULL);  	
	if (antAux != min)
		L->setUlt(antAux);			

	min->setProx(NULL);
	if (aux != min) prim->setProx(aux);	
	else prim->setProx(NULL);

	if (aux != proxMin) {
		aux->setProx(proxMin);
		if(proxMin != NULL) 
			proxMin->setAnt(aux);
	}
    //cout<<" minnimo "<<min->getCusto()<<endl;
	return min;
}

template<typename D>
void Djikstra<D>::relaxa(No<D> *u, No<D> *v, int w) {
	if (v != NULL) {
		if (v->getCusto() > u->getCusto() + w) {
			v->setCusto(	u->getCusto() + w);
			v->setPosPai(u->getPos());
		}
	}
	if (refNo != NULL) {
		if (refNo->getCusto() > u->getCusto() + w) {
			refNo->setCusto(u->getCusto() +  w);
			refNo->setPosPai(u->getPos());
		}
	}
}


int percorreGrafo(Graph<int> *aux){
    int acumulador = 0;
    int **mat;
    mat = aux->getMat();
    for (int i = 1; i <= aux->getTam() ; i++)
    {
        for (int j = i; j <= aux->getTam(); j++)
        {
            if(mat[i][j] !=  0){
                acumulador+=mat[i][j];
            }
        }
    }
    //    cout<<"valor do custo do aux "<<aux->getCusto()<<" item do aux "<<aux->getItem()<<endl;
    return acumulador;
}

int main()
{
    int ordem, n, inicio;
    int maior_dentre_menores = 0; 
    No<int> *aux = new No<int>();

    cin >> ordem;
    
    Graph<int> *grafo = new Graph<int>(ordem);

    for (int i = 1; i <= ordem ; i++)
    {
        for (int j = 1; j <=ordem; j++)
        {
            cin>>n;
            grafo->insertEdge(i, j, n);
        }
    }
    cin >> inicio;
    
    inicio++;
    
    Djikstra<int> *caminhoMinimo = new Djikstra<int>(grafo, inicio, 2);
    
    delete caminhoMinimo;
    aux = grafo->getVertices()->getPrim()->getProx();

    while (aux != NULL)
    {
        if (aux->getCusto() > maior_dentre_menores)
        {
            maior_dentre_menores = aux->getCusto();
        }
        aux = aux->getProx();
    }

    cout<<maior_dentre_menores<<endl;

}