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
    setProx(nullptr);
    setAnt(nullptr);
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
    while (aux != nullptr)
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
    cout<<"MAT ["<<u<<"] ["<<v<<"] = "<<custo<<endl;
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
            if (mat[i][j] < 0)
                cout << v;
            else
                cout << -1;
            cout << ((v < 10 || v < 0) ? " |" : "|");
        }
        cout << endl;
    }
}

template <typename H>
class Heapsort
{
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

template <typename H>
Heapsort<H>::Heapsort() {}

template <typename H>
Heapsort<H>::Heapsort(Lista<H> *base)
{
    A = base;
    tamanho = base->getOrdem();
    constroiHeap();
    for (int i = tamanho; i > 1; i--)
    {
        tamHeap--;
        heapfica(i, tamHeap);
    }
}

template <typename H>
int Heapsort<H>::PAI(int i) { return i / 2; }

template <typename H>
int Heapsort<H>::ESQ(int i) { return 2 * i; }

template <typename H>
int Heapsort<H>::DIR(int i) { return 2 * i + 1; }

template <typename H>
void Heapsort<H>::heapfica(int i, int tamRestante)
{
    int l = ESQ(i), r = DIR(i), maior = i;
    No<H> *x, *y;
    if (l <= tamRestante)
    {
        x = A->busca(l, false);
        y = A->busca(i, false);
        if (x->getCusto() > y->getCusto())
        {
            maior = l;
        }
    }
    if (r <= tamRestante)
    {
        x = A->busca(r, false);
        y = A->busca(maior, false);
        if (x->getCusto() > y->getCusto())
        {
           maior = r;
        }
    }
    if (maior != i)
    {
        troca(A->busca(maior, false), A->busca(i, false));
        heapfica(maior, tamRestante);
    }
}

template <typename H>
void Heapsort<H>::troca(No<H> *a, No<H> *b)
{
    No<H> *proxA = a->getProx();
    No<H> *antB = b->getAnt();
    No<H> *aux;

    aux = b->getProx();
    a->setProx(aux);
    if (aux != nullptr)
        aux->setAnt(a);

    b->setProx(proxA);
    if (proxA != nullptr)
        proxA->setAnt(b);
    else
        A->setUlt(b);

    aux = a->getAnt();
    b->setAnt(aux);
    if (aux != nullptr)
        aux->setProx(b);

    a->setAnt(antB);
    if (antB != nullptr)
        antB->setProx(a);
    else
        A->getPrim()->setProx(a);
}

template <typename H>
void Heapsort<H>::constroiHeap()
{
    tamHeap = tamanho;
    for (int i = tamanho / 2; i > 0; i--)
    {
        heapfica(i, tamHeap);
    }
}

template <typename H>
void Heapsort<H>::reconstroiHeap(int tam)
{
    tamanho = tam;
    constroiHeap();
}

template <typename H>
Lista<H> *Heapsort<H>::getHeap() { return A; }

template <typename D>
class Djikstra
{
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
    No<D> *extraeMax(Lista<D> *L);
    void relaxa(No<D> *u, No<D> *v, int w);
};

template <typename D>
Djikstra<D>::Djikstra() {}

template <typename D>
Djikstra<D>::Djikstra(Graph<D> *base, int inicio, int fim)
{
    adj = base->getAdj();
    refLista = base->getVertices();
    n = refLista->getOrdem();
    refNo = refLista->getPrim()->getProx();

    inicializa(refLista->busca(inicio, false));

    arvore = new Graph<D>(n, base->getTam());
    arvore->setVertices(refLista);

    Q = new Lista<D>(refLista);
    heapificador = new Heapsort<D>(Q);
    extraidos = 0;
    while (n - extraidos)
    {
        u = extraeMin(Q);
        posiU = u->getPos();
        adj[posiU][0] = posiU;
        posiPai = u->getPosPai();

        arvore->insertEdge(posiU, posiPai, adj[posiU][posiPai]);
        for (int i = 1; i <= n; i++)
        {
            if (adj[posiU][i] != -99)
            {
                refNo = refLista->busca(i, true);
                if (adj[i][0] != i)
                    v = Q->busca(i, true);
                else
                    v = nullptr;
                relaxa(u, v, adj[posiU][i]);
            }
        }
    }

    novaLista = new Lista<D>();

    posiU = fim;
    while (posiU != 0)
    {
        refNo = refLista->busca(posiU, true);
        novaLista->insere(refNo);
        posiU = refNo->getPosPai();
    }
    nResult = novaLista->getOrdem();
    tamResult = nResult - 1;
    result = new Graph<D>(nResult, tamResult);
    result->setVertices(novaLista);

    posiU = fim;
    int i = 1;
    while (posiU != inicio)
    {
        refNo = refLista->busca(posiU, true);
        posiPai = refNo->getPosPai();
        result->insertEdge(i, i + 1, adj[posiU][posiPai]);
        i++;
        posiU = posiPai;
    }
}

template <typename D>
void Djikstra<D>::inicializa(No<D> *s)
{
    while (refNo != nullptr)
    {
        refNo->setCusto(INF);
        refNo = refNo->getProx();
    }
    s->setCusto(0);
    s->setPosPai(0);
}
template <typename D>
Graph<D> *Djikstra<D>::getResult() { return result; };

template <typename D>
No<D> *Djikstra<D>::extraeMax(Lista<D> *L)
{
    No<D> *aux, *max, *proxMax, *antAux, *prim;

    heapificador->reconstroiHeap(n - ++extraidos);
    prim = L->getPrim();

    max = prim->getProx();
    proxMax = max->getProx();
    aux = L->getUlt();
    antAux = aux->getAnt();

    aux->setAnt(nullptr);
    if (antAux != nullptr)
        antAux->setProx(nullptr);
    if (antAux != max)
        L->setUlt(antAux);

    max->setProx(nullptr);
    if (aux != max)
        prim->setProx(aux);
    else
        prim->setProx(nullptr);

    if (aux != proxMax)
    {
        aux->setProx(proxMax);
        if (proxMax != nullptr)
            proxMax->setAnt(aux);
    }
    return max;
}

template <typename D>
void Djikstra<D>::relaxa(No<D> *u, No<D> *v, int w)
{
    if (v != nullptr)
    {
        if (v->getCusto() > u->getCusto() + w)
        {
            v->setCusto(u->getCusto() + w);
            v->setPosPai(u->getPos());
        }
    }
    if (refNo != nullptr)
    {
        if (refNo->getCusto() > u->getCusto() + w)
        {
            refNo->setCusto(u->getCusto() + w);
            refNo->setPosPai(u->getPos());
        }
    }
}

int main()
{
    int ordem, n;

    cin >> ordem;
    
    Graph<int> grafo(ordem);

    for (int i = 1; i <= ordem ; i++)
    {
        for (int j = 1; j <= ordem; j++)
        {
            cin>>n;
            grafo.insertEdge(i, j, n);
        }
    }

    grafo.print();
}