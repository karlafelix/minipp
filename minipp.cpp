#include <iostream>

using namespace std;

#define INFINITY 999

template <typename N>
class Node
{
  private:
    int item;
    int weight;
    string color;
    int position, positionFather;
    Node<N> *next;
    Node<N> *previous;

  public:
    Node();
    N getItem();
    int getWeight();
    void setItem(N item);
    void setWeight(int weight);
    void setColor(string color);
    void setPosition(int position);
    string getColor();
    Node<N> *getNext();
    Node<N> *getPrevious();
    int getPosition();
    int getPositionFather();
    void setPositionFather(int positionFather);
    void setNext(Node<N> *next);
    void setPrevious(Node<N> *previous);
};

template <typename N>
Node<N>::Node()
{
    setNext(NULL);
    setPrevious(NULL);
    color = "Branco";
    weight = 0;
}

template <typename N>
N Node<N>::getItem()
{ 
    return item;
}

template <typename N>
int Node<N>::getWeight()
{ 
    return weight;
}

template <typename N>
string Node<N>::getColor()
{ 
    return color;
}

template <typename N>
int Node<N>::getPosition()
{ 
    return position;
}

template <typename N>
int Node<N>::getPositionFather()
{ 
    return positionFather;
}

template <typename N>
Node<N> *Node<N>::getNext()
{ 
    return next;
}

template <typename N>
Node<N> *Node<N>::getPrevious()
{ 
    return previous;
}

template <typename N>
void Node<N>::setItem(N item)
{ 
    this->item = item;
}

template <typename N>
void Node<N>::setWeight(int weight)
{ 
    this->weight = weight;
}

template <typename N>
void Node<N>::setColor(string color)
{ 
    this->color = color;
}

template <typename N>
void Node<N>::setPosition(int position)
{ 
    this->position = position;
}

template <typename N>
void Node<N>::setPositionFather(int positionFather)
{ 
    this->positionFather = positionFather;
}

template <typename N>
void Node<N>::setNext(Node<N> *next)
{ 
    this->next = next;
}

template <typename N>
void Node<N>::setPrevious(Node<N> *previous)
{ 
    this->previous = previous;
}

template <typename L>
class List
{
  private:
    Node<L> *first;
    Node<L> *last;
    int order;

  public:
    List();
    List(int n);
    List(List<L> *base);
    void inicializa();
    void setLast(Node<L> *last);
    Node<L> *getFirst();
    Node<L> *getLast();
    int getOrder();
    Node<L> *insert();
    Node<L> *insert(string color);
    void insert(Node<L> *v);
    bool vazia();
    Node<L> *search(int position, bool initialPosition);
    int search(Node<L> *n);

};

template <typename L>
List<L>::List()
{ 
    inicializa();
}

template <typename L>
List<L>::List(int n)
{
    inicializa();
    for (int i = 0; i < n; i++)
        insert();
}

template <typename L>
List<L>::List(List<L> *base)
{
    inicializa();
    Node<L> *auxiliar = base->getFirst()->getNext();
    for (int i = 0; i < base->getOrder(); i++)
    {
        insert(auxiliar);
        auxiliar = auxiliar->getNext();
    }
}

template <typename L>
void List<L>::inicializa()
{
    first = new Node<L>();
    last = first;
    order = 0;
}

template <typename L>
Node<L> *List<L>::insert(string color)
{
    Node<L> *auxiliar = insert();
    auxiliar->setColor(color);
    return auxiliar;
}

template <typename L>
void List<L>::setLast(Node<L> *last)
{ 
    this->last = last;
}

template <typename L>
Node<L> *List<L>::getLast()
{
    return last;
}

template <typename L>
int List<L>::getOrder()
{ 
    return order;
}

template <typename L>
Node<L> *List<L>::insert()
{
    Node<L> *n = new Node<L>();
    last->setNext(n);
    n->setPrevious(last);
    n->setPosition(++order);
    last = n;
    return n;
}
template <typename L>
Node<L> *List<L>::getFirst()
{ 
    return first;
}

template <typename L>
bool List<L>::vazia()
{ 
    return first == last;
}

template <typename L>
void List<L>::insert(Node<L> *v)
{
    Node<L> *auxiliar = insert(v->getColor());
    auxiliar->setWeight(v->getWeight());
    auxiliar->setItem(v->getItem());
}

template <typename L>
Node<L> *List<L>::search(int position, bool initialPosition)
{
    Node<L> *auxiliar = first->getNext();
    if (initialPosition)
    {
        while (auxiliar->getPosition() != position)
            auxiliar = auxiliar->getNext();
    }
    else
    {
        for (int i = 1; i < position; i++)
        {
            auxiliar = auxiliar->getNext();
        }
    }
    return auxiliar;
}

template <typename L>
int List<L>::search(Node<L> *n)
{
    Node<L> *auxiliar = first;
    int position = 1;
    while (auxiliar->getPosition() != n->getPosition())
    {
        if (position <= order)
        {
            auxiliar = auxiliar->getNext();
            position++;
        }
    }
    return position;
}

template <typename G>
class Graph
{
  private:
    List<G> *vertex;
    int **matrix;
    int n, size;

  public:
    Graph(int n);
    Graph(int n, int size);
    void initialize();
    List<G> *getVertex();
    void setVertex(List<G> *l);
    void insertEdge(int u, int v, int weight);
    int getN();
    int getSize();
    int **getMat();
};

template <typename G>
Graph<G>::Graph(int n)
{
    this->n = n;
    initialize();
}

template <typename G>
Graph<G>::Graph(int n, int size)
{
    this->n = n;
    this->size = size;
    initialize();
}

template <typename G>
void Graph<G>::initialize()
{  
    vertex = new List<G>(n);

    matrix = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        matrix[i] = new int[n + 1];
        //cout << n << endl;
        for (int j = 0; j <= n; j++)
            matrix[i][j] = 0;
    }
}

template <typename G>
List<G> *Graph<G>::getVertex()
{ 
    return vertex;
}

template <typename G>
void Graph<G>::setVertex(List<G> *l)
{
    this->vertex = l; 
}

template <typename G>
int **Graph<G>::getMat()
{ 
    return matrix;
}

template <typename G>
void Graph<G>::insertEdge(int u, int v, int weight)
{
    matrix[u][v] = weight;
    //cout<<"matrix ["<<u<<"] ["<<v<<"] = "<<weight<<endl;
    matrix[v][u] = weight;
    size++;
}

template <typename G>
int Graph<G>::getN()
{ 
    return n;
}

template <typename G>
int Graph<G>::getSize()
{ 
    return size;
}

template<typename H>
class Heapsort{
private:
	List<H> *A;
	int size, sizeHeap;
public:

	Heapsort(List<H> *base);	
	int father(int i);
	int left(int i);
	int right(int i);
	void heapfica(int i, int tamRestante);
	void swap(Node<H> *a, Node<H> *b);
	void buildHeap();
	void rebuildHeap(int size);

};

template<typename H>
Heapsort<H>::Heapsort(List<H> *base)
{
	A = base;
	size = base->getOrder();
	buildHeap();
	for (int i = size; i > 1; i--)
    {
		sizeHeap--;
		heapfica(i, sizeHeap);
	}
}

template<typename H>
int Heapsort<H>::father(int i)
{ 
    return i/2; 
}

template<typename H>
int Heapsort<H>::left(int i)
{ 
    return 2*i;
}

template<typename H>
int Heapsort<H>::right(int i)
{ 
    return 2*i + 1; 
}

template<typename H>
void Heapsort<H>::heapfica(int i, int tamRestante)
{
	int l = left(i), r = right(i), menor = i;
	Node<H> *x, *y;
	if(l <= tamRestante)
    {
		x = A->search(l, false);
		y = A->search(i, false);
		if(x->getWeight() < y->getWeight())
        {
			menor = l;
		}
	}
	if(r <= tamRestante)
    {
		x = A->search(r, false);
		y = A->search(menor, false);	
		if(x->getWeight() < y->getWeight())
        {
			menor = r;
		}
	}
	if (menor != i)
    {
		swap(A->search(menor, false), A->search(i, false));
		heapfica(menor, tamRestante);
	}
}

template <typename H>
void Heapsort<H>::buildHeap()
{
    sizeHeap = size;
    for (int i = size / 2; i > 0; i--)
    {
        heapfica(i, sizeHeap);
    }
}

template<typename H>
void Heapsort<H>::swap(Node<H> *a, Node<H> *b)
{
	Node<H> *proxA = a->getNext();
	Node<H> *antB = b->getPrevious();
	Node<H> *auxiliar;

	auxiliar = b->getNext();
	a->setNext(auxiliar);
	if (auxiliar != NULL)
    {
        auxiliar->setPrevious(a);
    }

	b->setNext(proxA);

	if (proxA != NULL)
    {
        proxA->setPrevious(b);
    }
	else
    {
        A->setLast(b);
    }

	auxiliar = a->getPrevious();
	b->setPrevious(auxiliar);
	if (auxiliar != NULL)
    {
        auxiliar->setNext(b);
    } 

	a->setPrevious(antB);
	if (antB != NULL)
    {
        antB->setNext(a);
    } 
	else
    {
        A->getFirst()->setNext(a);
    } 
}

template<typename H>
void Heapsort<H>::rebuildHeap(int size)
{
	this->size = size;
	buildHeap();
} 

template<typename D>
class Djikstra
{
private:
	Graph<D> *tree, *result;
	List<D> *referenceList, *queue, *newList;
	Node<D> *referenceNode, *u, *v;
	int n, positionU, fatherPosition, extracted, nResult, tamResult;
	int **adj;
	Heapsort<D> *heapificador;
public:
	Djikstra(Graph<D> *base, int begin, int end);
	void inicializa(Node<D> *s);
	Graph<D> *getResult();
	Node<D> *extraeMin(List<D> *L);
	void relaxa(Node<D> *u, Node<D> *v, int weight);
};

template<typename D>
Djikstra<D>::Djikstra(Graph<D> *base, int begin, int end)
{
	adj = base->getMat();//matrix de adjacencia
	referenceList = base->getVertex();//List de vertex	
	n = referenceList->getOrder();//order do grafo
	referenceNode = referenceList->getFirst()->getNext();//primeiro Node da List de vertex

	inicializa(referenceList->search(begin, false));

	tree = new Graph<D>(n, base->getSize());//base é o grafo recebido
	tree->setVertex(referenceList);

	queue = new List<D>(referenceList); 
	heapificador = new Heapsort<D>(queue);
    //queue->show(false, true);
    
    extracted = 0;
    do
	{
		u = extraeMin(queue);
        //cout << "peguei o u, o weight atual dele eh: " << u->getWeight() << endl;
        positionU = u->getPosition();
		adj[positionU][0] = positionU;
		fatherPosition = u->getPositionFather();

		tree->insertEdge(positionU, fatherPosition, adj[positionU][fatherPosition]);
		for (int i = 1; i <= n; i++) {
			if(adj[positionU][i] != 0) {
				referenceNode = referenceList->search(i, true);
				if (adj[i][0] != i) v = queue->search(i, true);
				else v = NULL;
				relaxa(u, v, adj[positionU][i]);
                //cout << " u v e adj[positionU][i] " << u <<" "<< v <<" "<< adj[positionU][i]<<endl;
            }
		}
     }while (n - extracted);

    newList = new List<D>();

    positionU = end;
    do
    {
         referenceNode = referenceList->search(positionU, true);
         newList->insert(referenceNode);
         positionU = referenceNode->getPositionFather();
    }while (positionU != 0);
        nResult = newList->getOrder();
	tamResult = nResult-1;
	result = new Graph<D>(nResult, tamResult);
	result->setVertex(newList);	

	positionU = end;
	int i = 1;
	do
    {
		referenceNode = referenceList->search(positionU, true);
		fatherPosition = referenceNode->getPositionFather();
        //cout<<"positionU ["<<positionU<<"] fatherPosition["<<fatherPosition<<"] "<<endl;
        //cout<<"weight DO VERTICE SENDO ADD "<<adj[positionU][fatherPosition]<<endl;
		result->insertEdge(i, i+1, adj[positionU][fatherPosition]);
        //result->print();
		i++;
		positionU = fatherPosition;
    }while (positionU != begin);
}

template<typename D>
void Djikstra<D>::inicializa(Node<D> *s) {
	while(referenceNode != NULL) 
    {
		referenceNode->setWeight(INFINITY); 
		referenceNode = referenceNode->getNext();
	}
	s->setWeight(0);
	s->setPositionFather(0);
}

template<typename D>
Graph<D> *Djikstra<D>::getResult() { return result; };

template<typename D>
Node<D> *Djikstra<D>::extraeMin(List<D> *L)
{
	Node<D> *auxiliar, *min, *nextMin, *previousAuxiliar, *first;

	heapificador->rebuildHeap(n - ++extracted);
	first = L->getFirst();

	min = first->getNext(); 
	nextMin = min->getNext();
	auxiliar = L->getLast();	
	previousAuxiliar = auxiliar->getPrevious();
	
	auxiliar->setPrevious(NULL);
	if (previousAuxiliar != NULL) 			
		previousAuxiliar->setNext(NULL);  	
	if (previousAuxiliar != min)
		L->setLast(previousAuxiliar);			

	min->setNext(NULL);
	if (auxiliar != min) first->setNext(auxiliar);	
	else first->setNext(NULL);

	if (auxiliar != nextMin) 
    {
		auxiliar->setNext(nextMin);
		if(nextMin != NULL)
        {
			nextMin->setPrevious(auxiliar);
        }
	}
    //cout<<" minnimo "<<min->getWeight()<<endl;
	return min;
}

template<typename D>
void Djikstra<D>::relaxa(Node<D> *u, Node<D> *v, int weight) 
{
	if (v != NULL) {
		if (v->getWeight() > u->getWeight() + weight) 
        {

			v->setWeight(	u->getWeight() + weight);
			v->setPositionFather(u->getPosition());
		}
	}
	if (referenceNode != NULL)
    {
		if (referenceNode->getWeight() > u->getWeight() + weight) 
        {
			referenceNode->setWeight(u->getWeight() +  weight);
			referenceNode->setPositionFather(u->getPosition());
		}
	}
}

int percorreGrafo(Graph<int> *auxiliar)
{
    int acumulador = 0;
    int **matrix;
    matrix = auxiliar->getMat();
    for (int i = 1; i <= auxiliar->getSize() ; i++)
    {
        for (int j = i; j <= auxiliar->getSize(); j++)
        {
            if(matrix[i][j] !=  0){
                acumulador+=matrix[i][j];
            }
        }
    }
    //    cout<<"valor do weight do auxiliar "<<auxiliar->getWeight()<<" item do auxiliar "<<auxiliar->getItem()<<endl;
    return acumulador;
}

int main()
{
    int order, n, begin;
    int maior_dentre_menores = 0; 
    Node<int> *auxiliar = new Node<int>();

    cin >> order;
    
    Graph<int> *grafo = new Graph<int>(order);

    for (int i = 1; i <= order ; i++)
    {
        for (int j = 1; j <=order; j++)
        {
            cin>>n;
            grafo->insertEdge(i, j, n);
        }
    }
    cin >> begin;
    
    begin++;
    
    Djikstra<int> *minimalPath = new Djikstra<int>(grafo, begin, 2);
    
    delete minimalPath;

    auxiliar = grafo->getVertex()->getFirst()->getNext();

    while (auxiliar != NULL)
    {
        if (auxiliar->getWeight() > maior_dentre_menores)
        {
            maior_dentre_menores = auxiliar->getWeight();
        }
        auxiliar = auxiliar->getNext();
    }

    cout<<maior_dentre_menores<<endl;

}