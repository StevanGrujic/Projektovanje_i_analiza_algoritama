#pragma once
#include"Node.h"
#include"Edge.h"
class Graph
{
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
	long Dijkstra(int a);
	void Bellman_Ford(int a);

};

