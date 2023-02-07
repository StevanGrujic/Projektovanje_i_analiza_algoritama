#pragma once
#include "FibonacciNode.h"
#include<iostream>
using namespace std;
class FibonacciHeap
{
public:
	FibonacciNode* start;
	int size;

public:
	FibonacciHeap()
	{
		start = nullptr;
		size = 0;
	}
	void Insert(int val);
	FibonacciNode* Union(FibonacciNode* node1, FibonacciNode* node2);
	FibonacciNode* Union(FibonacciNode* node2);
	void ExtractMin();
	void Link(FibonacciNode* p1, FibonacciNode* p2);
	void Consolidate();
	void PrintRootNodes();
	bool uslov(FibonacciNode** niz, int n, FibonacciNode* str)
	{
		FibonacciNode* p = str;
		int k = 0;
		int broj = 1;
		while (p != str->left)
		{
			broj++;
			for (int i = 0; i < n; i++)
			{
				if (niz[i] == p)
				{
					k++;
					break;
				}
			}
			p = p->right;
		}
		for (int i = 0; i < n; i++)
		{
			if (niz[i] == p)
			{
				k++;
				break;
			}
		}
		if (k == broj)
			return false;
		return true;
	}
	void DecreaseKey(int staro, int novo);
	FibonacciNode* SearchNode(FibonacciNode* H,int k)
	{
		FibonacciNode* x = H;
		x->C = 'Y';
		FibonacciNode* p = NULL;
		if (x->value == k)
		{
			p = x;
			x->C = 'N';
			return p;
		}
		if (p == NULL)
		{
			if (x->child != NULL)
				p = SearchNode(x->child, k);
			if ((x->right)->C != 'Y')
				p = SearchNode(x->right, k);
		}
		x->C = 'N';

		return p;
	}
	void DeleteNode(int val)
	{
		if (start == NULL)
			return;
		FibonacciNode* p = SearchNode(start, val);
		if (p == NULL)
		{
			return;
		}
		DecreaseKey(p->value, INT32_MIN);
		start = p;
		ExtractMin();
	}

};

