#include "Edge.h"
#include"Node.h"
Edge::Edge()
{
	this->dest = NULL;
	this->link = NULL;
	this->weight = INT32_MIN;
	this->source = NULL;
	this->status = 0;
}
Edge::Edge(Edge* e, Node* source, Node* dest, int w)
{
	this->link = e;
	this->source = source;
	this->dest = dest;
	this->weight = w;
	this->status = 0;
}