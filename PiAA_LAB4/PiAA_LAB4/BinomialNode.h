#pragma once
#include<iostream>
using namespace std;
class BinomialNode
{
public:
	int value;
	BinomialNode* sibling;
	BinomialNode* leftChild;
	BinomialNode* parent;
	int degree;

public:
	BinomialNode();
	BinomialNode(int val);
	BinomialNode(int val, BinomialNode* sib, BinomialNode* child, BinomialNode* parent, int degree);
	int getDegree();
};

