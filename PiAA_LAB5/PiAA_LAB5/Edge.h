#pragma once
class Node;
class Edge
{
public:
	Edge* link;
	Node* source;
	Node* dest;
	int weight;
	int status; //0 neobradjena, 1 obradjena
public:
	Edge();
	Edge(Edge* e, Node* source, Node* dest, int w);
};

