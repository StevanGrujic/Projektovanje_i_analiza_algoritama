#pragma once
#include"Node.h"
#include"Edge.h"
#include<list>
class Graph
{
public:
	Node* start;
	unsigned int numberOfNodes;
public:
	Graph();
	~Graph();
	void addNode(int a);
	Node* findNode(int a);
	void addEdge(int a, int b, int w);
	Edge* findEdge(int a, int b);
	void print();
	//void primovAlgoritam();
	void boruvkinAlgoritam();
	void primAlgoritam();
	bool sadrzi(list<Node*> listaCvorova, Node* ptr);
};

