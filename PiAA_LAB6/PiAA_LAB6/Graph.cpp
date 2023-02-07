#include "Graph.h"
#include<stack>
#include<queue>
#include<list>
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
	Edge* ptr = pa->adj;
	pa->adj = new Edge(ptr, pb, w);
	pa->adj->source = pa;
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

long Graph::Dijkstra(int a)
{
	long retVal = 0;
	Node* ptr = start;
	while (ptr != nullptr)
	{
		ptr->status = 1;
		ptr->prev = nullptr;
		ptr->distance = INT32_MAX;
		ptr = ptr->next;
	}
	ptr = findNode(a); 
	if (ptr == nullptr) 
		return 0;

	priority_queue<Node*> priorityQueue;
	ptr->distance = 0;
	priorityQueue.push(ptr);
	ptr->status = 2;
	while (!priorityQueue.empty())
	{
		ptr = priorityQueue.top();
		priorityQueue.pop();
		ptr->status = 3;
		retVal += 1;

		Edge* pot = ptr->adj;
		while (pot != nullptr)
		{
			if (pot->dest->status == 1)
			{ 
				pot->dest->distance = ptr->distance + pot->weight; 
				pot->dest->status = 2; 
				pot->dest->prev = ptr; 
				priorityQueue.push(pot->dest);
			} 
			else if (pot->dest->status == 2)
				if (pot->dest->distance > ptr->distance + pot->weight)
				{
					int newDistance = ptr->distance + pot->weight; 
					pot->dest->prev = ptr;
					pot->dest->distance = newDistance;
				}
			pot = pot->link;
		}
	}
	return retVal;
}

void Graph::Bellman_Ford(int a)
{
	Node* ptr = start;
	Edge* e = nullptr;
	list<Edge*> listOfEdges;
	while (ptr != nullptr)
	{
		ptr->prev = nullptr;
		ptr->distance = INT32_MAX;
		e = ptr->adj;
		while (e != nullptr)
		{
			listOfEdges.push_back(e);
			e = e->link;
		}
		ptr = ptr->next;
	}
	ptr = findNode(a);
	if (ptr == nullptr)
		return;

	ptr->distance = 0;

	for (int i = 0; i < this->numberOfNodes - 1; i++)
	{
		for (Edge* e : listOfEdges)
		{
			if((e->source->distance + e->weight) >= 0)
			if (e->dest->distance > (e->source->distance + e->weight))
			{
				e->dest->distance = e->source->distance + e->weight;
				e->dest->prev = e->source;
			}
		}
	}

	/*ptr = start;
	if (start == NULL)
		throw "Graf ne postoji!";
	while (ptr != NULL)
	{
		cout << ptr->node << "-->";
		if (ptr->prev != NULL)
			cout << ptr->prev->node << endl;
		else
			cout << endl;
		ptr = ptr->next;
	}*/
}

