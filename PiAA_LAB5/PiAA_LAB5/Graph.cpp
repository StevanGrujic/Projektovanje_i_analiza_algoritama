#include "Graph.h"
#include<stack>
#include<queue>
Graph::Graph()
{
	this->numberOfNodes = 0;
	this->start = NULL;
}
Graph::~Graph()
{
	/*Node* ptr = start;
	Node* p = ptr->next;
	while (ptr != NULL)
	{
		delete ptr;
		ptr = p;
		if (p != NULL)
			p = p->next;
	}*/
}
void Graph::addNode(int a)
{
	if (start == NULL)
	{
		start = new Node(a, NULL, NULL, 0);
		numberOfNodes++;
	}
	else
	{
		Node* ptr = start;
		start = new Node(a, ptr, NULL, 0);
		numberOfNodes++;
	}
}
Node* Graph::findNode(int a)
{
	Node* ptr = start;
	while (ptr != NULL && ptr->node != a)
	{
		ptr = ptr->next;
	}
	return ptr;
}
void Graph::addEdge(int a, int b, int w)
{
	Node* pa = findNode(a);
	Node* pb = findNode(b);
	if (pa == NULL || pb == NULL)
		throw "Nepostojeci cvorovi!";
	Edge* ptr1 = pa->adj;
	Edge* ptr2 = pb->adj;
	pa->adj = new Edge(ptr1, pa, pb, w);
	pb->adj = new Edge(ptr2, pb, pa, w);
	if (pa->minEdge == NULL || w < pa->minEdge->weight)
		pa->minEdge = pa->adj;
	if (pb->minEdge == NULL || w < pb->minEdge->weight)
		pb->minEdge = pb->adj;
}
Edge* Graph::findEdge(int a, int b)
{
	Node* pa = findNode(a);
	Node* pb = findNode(b);
	if (pa == NULL || pb == NULL)
		throw "Nepostojeci cvorovi!";
	Edge* ptr = pa->adj;
	while (ptr != NULL && ptr->dest != pb)
	{
		ptr = ptr->link;
	}
	return ptr;
}
void Graph::print()
{
	Node* ptr = start;
	if (start == NULL)
		throw "Graf ne postoji!";
	while (ptr != NULL)
	{
		cout << ptr->node << "-->";
		Edge* p = ptr->adj;
		while (p != NULL)
		{
			cout << p->dest->node << "|";
			p = p->link;
		}
		cout << endl;
		ptr = ptr->next;
	}
}
/*void Graph::primovAlgoritam()
{
	if (start == NULL)
		throw "Graf ne postoji";
	Node* ptr = start;
	while (ptr != NULL)
	{
		ptr->status = 0;
		Edge* p = ptr->adj;
		while (p != NULL)
		{
			p->status = 0;
			p = p->link;
		}
		ptr = ptr->next;
	}

	//int min = start->minEdge->weight;
	int min = INT32_MAX;
	//ptr = start->next;
	ptr = start;
	Node* p = start;
	Edge* e = start->minEdge;
	while (ptr != NULL) // trazenje najmanje grane
	{
		if(ptr->minEdge!=NULL)
		if (ptr->minEdge->weight < min)
		{
			p = ptr;
			min = ptr->minEdge->weight;
			e = ptr->minEdge;
		}
		ptr = ptr->next;
	}
	if (e != NULL)
	{
		e->status = 1; // obradjena
		e->dest->status = 1;
		Edge* ed = e->dest->adj;
		while (ed != NULL)
		{
			if (ed->dest == e->source)
				ed->status = 1;
			ed = ed->link;
		}
	}
	p->status = 1; //obradjen cvor
	list<Node*> lCvorova; //lista obradjenih cvorova
	list<Edge*> lGrana;
	lCvorova.push_back(p);
	if(e!=NULL)
	lCvorova.push_back(e->dest);
	ptr = start;
	if(start->minEdge!=NULL)
	min = start->minEdge->weight;
	for (int i = 0; i < this->numberOfNodes - 2; i++)
	{
		for (Node* el : lCvorova)
		{
			Edge* e1 = el->adj;
			Edge* pom=nullptr;
			int min2 = INT32_MAX;
			while (e1 != NULL)
			{
				if (e1->status == 0 && e1->dest->status == 0 && e1->weight < min2)
				{
					min2 = e1->weight;
					pom = e1;
				}
				e1 = e1->link;
			}
			if (pom != nullptr)
			{
				lGrana.push_back(pom);
			}
		}
		int min3 = INT32_MAX;
		Edge* pom2 = nullptr;
		for (Edge* el : lGrana)
		{
			if (el->weight < min3)
			{
				min3 = el->weight;
				pom2 = el;
			}
		}
		lGrana.clear();
		if (pom2 != nullptr)
		{
			pom2->status = 1;
			Edge* ed = pom2->dest->adj;
			while (ed != NULL)
			{
				if (ed->dest == pom2->source)
					ed->status = 1;
				ed = ed->link;
			}
			pom2->dest->status = 1;
			lCvorova.push_back(pom2->dest);
		}

	}
	ptr = start;
	while (ptr != NULL)
	{
		cout << ptr->node << "-->";
		Edge* p = ptr->adj;
		while (p != NULL)
		{
			if (p->status == 1)
				cout << p->dest->node << "|";
			p = p->link;
		}
		cout << endl;
		ptr = ptr->next;
	}
}*/
void Graph::boruvkinAlgoritam()
{
	Node* ptr = start;
	while (ptr != NULL)
	{
		ptr->status = 0;
		Edge* p = ptr->adj;
		while (p != NULL)
		{
			p->status = 0;
			p = p->link;
		}
		ptr = ptr->next;
	}
	ptr = start;
	list<Node*> listaParenta;
	while (ptr != NULL)
	{
		ptr->parent = NULL;
		ptr = ptr->next;
	}
	ptr = start;
	while (ptr != NULL)
	{
		Edge* e = ptr->minEdge;
		if (e == NULL)
		{
			ptr = ptr->next;
		}
		else
		{
			if (ptr->parent == NULL)
			{
				if (e->dest->parent == NULL)
				{
					ptr->parent = ptr;
					listaParenta.push_back(ptr);
				}
				else
					ptr->parent = e->dest->parent;
			}
			if (e->dest->parent == NULL)
				e->dest->parent = ptr->parent;
			e->status = 1;
			Edge* ed = e->dest->adj;
			while (ed != NULL)
			{
				if (ed->dest == e->source)
				{
					ed->status = 1;
					break;
				}
				ed = ed->link;
			}
			ptr = ptr->next;
		}
	}
	ptr = start;
	int min = INT32_MAX;
	Edge* e1 = nullptr;
	Edge* pom = nullptr;
	Node* ptr2 = start;
	while (listaParenta.size() > 1)
	{
		while (ptr != NULL)
		{
			if (ptr->parent == listaParenta.front())
			{
				e1 = ptr->adj;
				while (e1 != NULL)
				{
					if (e1->weight < min && e1->status == 0)
					{
						min = e1->weight;
						pom = e1;
					}
					e1 = e1->link;
				}
			}
			ptr = ptr->next;
		}
		if (pom != NULL)
		{
			pom->status = 1;
			Edge* ed = pom->dest->adj;
			while (ed != NULL)
			{
				if (ed->dest == pom->source)
				{
					ed->status = 1;
					break;
				}
				ed = ed->link;
			}
		}
		if (pom != NULL)
			listaParenta.remove(pom->dest->parent);
		ptr2 = start;
		while (ptr2 != NULL)
		{
			if(pom != NULL)
			if (ptr2->parent == pom->dest->parent)
				ptr2->parent = listaParenta.front();
			ptr2 = ptr2->next;
		}
		ptr = start;
		min = INT32_MAX;
	}
	ptr = start;
	/*while (ptr != NULL)
	{
		cout << ptr->node << "-->";
		Edge* p = ptr->adj;
		while (p != NULL)
		{
			if (p->status == 1)
				cout << p->dest->node << "|";
			p = p->link;
		}
		cout << endl;
		ptr = ptr->next;
	}*/
}
void Graph::primAlgoritam()
{
	if (start == NULL)
		return;
	list<Node*> listaCvorova;
	Node* ptr = start;
	while (ptr != NULL)
	{
		ptr->distance = INT32_MAX;
		listaCvorova.push_back(ptr);
		ptr->parent = NULL;
		ptr = ptr->next;
	}
	ptr = start;
	ptr->distance = 0;
	Node* pom = nullptr;
	while (!listaCvorova.empty())
	{
		int min = INT32_MAX;
		Node* pom = nullptr;
		for (Node* el : listaCvorova)
		{
			if (el->distance < min)
			{
				min = el->distance;
				pom = el;
			}
		}
		listaCvorova.remove(pom);
		if (pom == NULL)
			break;
		Edge* e = pom->adj;
		while (e != NULL)
		{
			if (sadrzi(listaCvorova, e->dest) && e->weight < e->dest->distance)
			{
				e->dest->parent = pom;
				e->dest->distance = e->weight;
			}
			e = e->link;
		}
	}
	/*ptr = start;
	while (ptr != NULL)
	{
		if (ptr->parent != NULL)
			cout << "Cvor " << ptr->node << " i njegov roditelj " << ptr->parent->node << endl;
		ptr = ptr->next;
	}*/
}
bool Graph::sadrzi(list<Node*> listaCvorova, Node* ptr)
{
	for (Node* el : listaCvorova)
		if (el == ptr)
			return true;
	return false;
}

