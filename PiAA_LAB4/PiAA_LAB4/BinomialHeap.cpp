#include "BinomialHeap.h"

BinomialHeap::BinomialHeap()
{
	startNode = nullptr;
	tail = nullptr;
	count = 0;
}

BinomialHeap::BinomialHeap(BinomialNode* start)
{
	this->startNode = start;
	this->tail = start;
	count = 0;
}

BinomialNode* BinomialHeap::Union(BinomialNode* start1, BinomialNode* start2)
{
	BinomialNode* start=nullptr;
	start = Merge(start1, start2);
	if (start == NULL)
		return nullptr;

	BinomialNode* prev = NULL;
	BinomialNode* x = start;
	BinomialNode* next = x->sibling;

	while (next != NULL)
	{
		if(x->degree != next->degree || ((next->sibling!=NULL) && (next->sibling)->degree==x->degree))
		{
			prev = x;
			x = next;
		}
		else
		{
			if (x->value <= next->value)
			{
				x->sibling = next->sibling;
				Binomial_Link(next, x);
			}
			else
			{
				if (prev == NULL)
				{
					start = next;
				}
				else
				prev->sibling = next;
				Binomial_Link(x, next);
				x = next;
			}
		}

		next = x->sibling;
	}
	return start;
}

void BinomialHeap::Binomial_Link(BinomialNode* x, BinomialNode* y)
{
	x->parent = y;
	x->sibling = y->leftChild;
	y->leftChild = x;
	y->degree++;

}

BinomialNode* BinomialHeap::Insert(BinomialNode* x)
{
	if (this->startNode == nullptr)
	{
		this->startNode = x;
	}
	else
	{
		startNode = Union(x, startNode);
		count++;
	}
	return startNode;
}

BinomialNode* BinomialHeap::CreateNode(int a)
{
	return new BinomialNode(a);

}

void BinomialHeap::PrintRootNodes()
{
	if (startNode == NULL)
	{
		cout << "Heap je prazan" << endl;
		return;
	}
	cout << "The root nodes are: " << endl;
	BinomialNode* p;
	p = startNode;
	while (p != NULL)
	{
		cout << p->value;
		if (p->sibling != NULL)
			cout << "-->";
		p = p->sibling;
	}
	cout << endl;
}

BinomialNode* BinomialHeap::ExtractMin(BinomialNode* H1)
{
	tail = NULL;
	BinomialNode* t = NULL;
	BinomialNode* x = H1;
	if (x == NULL)
	{
		cout << "Nothing to Extract" << endl;
		return x;
	}
	int min = x->value;
	BinomialNode* p = x;
	while (p->sibling != NULL)
	{
		if ((p->sibling)->value < min)
		{
			min = (p->sibling)->value;
			t = p;
			x = p->sibling;
		}
		p = p->sibling;
	}
	if (t == NULL && x->sibling == NULL)
		H1 = NULL;
	else if (t == NULL)
		H1 = x->sibling;
	else if (t->sibling == NULL)
		t = NULL;
	else
		t->sibling = x->sibling;
	if (x->leftChild != NULL)
	{
		Revert_list(x->leftChild);
		(x->leftChild)->sibling = NULL;
	}
	startNode = Union(H1, tail);
	return x;

}

BinomialNode* BinomialHeap::OkreniListu(BinomialNode* head)
{
	if (head == NULL || head->sibling == NULL)
		return head;

	BinomialNode* rest = OkreniListu(head->sibling);
	head->sibling->sibling = head;
	head->sibling = NULL;
	return rest;
}

int BinomialHeap::DeleteNode(BinomialNode* H, int k)
{
	if (H == NULL)
	{
		cout << "\nHEAP EMPTY!!!!!";
		return 0;
	}
	if(DecreaseKey(H, k, INT32_MIN)==0)
		return 0;
	BinomialNode* np = ExtractMin(H);
	if (np != NULL)
		//cout << "Izbrisano" << endl;
		return 1;
}

void BinomialHeap::DeleteNode(int key)
{
	DeleteNode(startNode,key);
}

void BinomialHeap::PrintHeap(BinomialNode* start)
{
	BinomialNode* x = start;
	if (x == NULL)
	{
		return;
	}
	cout <<  x->value;
	if (x->leftChild != NULL)
	{
		cout << " | ";
		PrintHeap(x->leftChild);
	}
	if (x->sibling != NULL)
	{
		cout << " --> ";
		PrintHeap(x->sibling);
	}

}
