#pragma once
#include"BinomialNode.h"
class BinomialHeap
{
	public:
	BinomialNode* startNode;
	BinomialNode* tail;
	int count;

public:
	BinomialHeap();
	BinomialHeap(BinomialNode* start);
	BinomialNode* Union(BinomialNode* start1, BinomialNode* start2);
	void Binomial_Link(BinomialNode* a, BinomialNode* b);
	BinomialNode* Insert(BinomialNode* x);
	BinomialNode* CreateNode(int a);
	void PrintRootNodes();
	BinomialNode* ExtractMin(BinomialNode* H1);
	BinomialNode* OkreniListu(BinomialNode* head);
	void Revert_list(BinomialNode* y)
	{
		if (y->sibling != NULL)
		{
			Revert_list(y->sibling);
			(y->sibling)->sibling = y;
		}
		else
		{
			tail = y;
		}
	}
	BinomialNode* SearchNode(BinomialNode* H, int k)
	{
		BinomialNode* x = H;
		BinomialNode* p = NULL;
		if (x->value == k)
		{
			p = x;
			return p;
		}
		if (x->leftChild != NULL && p == NULL)
			p = SearchNode(x->leftChild, k);
		if (x->sibling != NULL && p == NULL)
			p = SearchNode(x->sibling, k);
		return p;
	}
	int DecreaseKey(BinomialNode* H, int staro, int novo)
	{
		int temp;
		BinomialNode* p;
		BinomialNode* y;
		BinomialNode* z;
		p = SearchNode(H, staro);
		if (p == NULL)
		{
			//cout << "Ne postoji kljuc sa prosledjenom vrednosti" << endl;
			return 0;
		}
		if (novo > p->value)
		{
			//cout << "Vrednost novog kljuca je veca od vrednosti starog" << endl;
			return 0;
		}
		p->value = novo;
		y = p;
		z = p->parent;
		while (z != NULL && y->value < z->value)
		{
			temp = y->value;
			y->value = z->value;
			z->value = temp;
			y = z;
			z = z->parent;
		}
	}
	int DeleteNode(BinomialNode* H,int key);
	void DeleteNode(int key);
	void PrintHeap(BinomialNode* start);
	void PrintMin()
	{
		BinomialNode* p = startNode;
		if (p == NULL)
		{
			cout << "NULL";
			return;
		}
		int min = p->value;
		while (p != NULL)
		{
			if (p->value < min)
				min = p->value;
			p = p->sibling;
		}
		cout << min << endl;
	}
	BinomialNode* Merge(BinomialNode* x, BinomialNode* y)
	{
		BinomialNode* start;
		if (x != NULL)
		{
			if (y != NULL)
			{
				if (x->degree <= y->degree)
				{
					start = x;
				}
				else 
				{
					start = y;
				}
			}
			else
			{
				start = x;
				return start;
			}
		}
		else
		{
			start = y;
			return start;
		}
		BinomialNode* p = start;
		BinomialNode* pre = nullptr;
		BinomialNode* pa = nullptr;
		if (y->sibling == NULL && start == x)
		{
			while (p != NULL && p->degree <= y->degree)
			{
				pre = p;
				p = p->sibling;
			}
			pa = pre->sibling;
			pre->sibling = y;
			y->sibling = pa;
			return start;
		}
		if (x->sibling == NULL && start == y)
		{
			while (p != NULL && p->degree <= y->degree)
			{
				pre = p;
				p = p->sibling;
			}
			pa = pre->sibling;
			pre->sibling = x;
			x->sibling = pa;
			return start;
		}
		BinomialNode* p1;
		BinomialNode* p2;
		if (start == x)
		{
			p1 = x->sibling;
			p2 = y;
		}
		else
		{
			p1 = x;
			p2 = y->sibling;
		}
		while (p1!= NULL && p2 != NULL)
		{
			if (p1->degree <= p2->degree)
			{
				p->sibling = p1;
				p = p->sibling;
				p1 = p1->sibling;
			}
			else
			{
				p->sibling = p2;
				p = p->sibling;
				p2 = p2->sibling;
			}
		}
		if (p1 != NULL)
			p->sibling = p1;
		if (p2 != NULL)
			p->sibling = p2;
		return start;
	}
};

