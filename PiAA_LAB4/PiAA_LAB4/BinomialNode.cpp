#include "BinomialNode.h"

BinomialNode::BinomialNode()
{
	this->leftChild = NULL;
	this->parent = NULL;
	this->sibling = NULL;
	this->value = 0;
	this->degree = 0;
}

BinomialNode::BinomialNode(int val)
{
	this->leftChild = NULL;
	this->parent = NULL;
	this->degree = 0;
	this->sibling = NULL;
	this->value = val;
}

BinomialNode::BinomialNode(int val, BinomialNode* sib, BinomialNode* child, BinomialNode* parent, int deg)
{
	this->leftChild = child;
	this->parent = parent;
	this->sibling = sib;
	this->value = val;
	this->degree = deg;
}

int BinomialNode::getDegree()
{
	return this->degree;
}
