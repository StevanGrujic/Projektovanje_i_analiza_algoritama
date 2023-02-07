#pragma once
class Node;
class Edge
{
public:
	Edge* link;
	Node* dest;
	int weight;
	Node* source;
public:
	Edge();
	Edge(Edge* e, Node* n, int weight);
};

