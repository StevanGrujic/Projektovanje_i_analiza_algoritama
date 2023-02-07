#include "Edge.h"
#include"Node.h"
Edge::Edge()
{
	this->dest = NULL;
	this->link = NULL;
	this->weight = INT32_MAX;
	this->source = NULL;
}
Edge::Edge(Edge* e, Node* n, int w)
{
	this->link = e;
	this->dest = n;
	this->weight = w;
	this->source = NULL;
}