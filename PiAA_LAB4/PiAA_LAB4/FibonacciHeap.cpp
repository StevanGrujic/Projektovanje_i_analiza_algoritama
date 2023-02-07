#include "FibonacciHeap.h"
void FibonacciHeap::Insert(int val)
{
	if (start == nullptr)
		start = new FibonacciNode(val);
	else
	{
		FibonacciNode* node = new FibonacciNode(val);
		node->C = 'N';
		node->left = node;
		node->right = node;
		(start->left)->right = node;
		node->right = start;
		node->left = start->left;
		start->left = node;
		if (node->value < start->value)
			start = node;
	}
	size++;
}

FibonacciNode* FibonacciHeap::Union(FibonacciNode* H1, FibonacciNode* H2)
{
	FibonacciNode* np;
	FibonacciNode* H = new FibonacciNode();
	H = H1;
	(H->left)->right = H2;
	(H2->left)->right = H;
	np = H->left;
	H->left = H2->left;
	H2->left = np;

	return H;
}

FibonacciNode* FibonacciHeap::Union(FibonacciNode* H2)
{
	FibonacciNode* np;
	FibonacciNode* H = new FibonacciNode();
	H = start;
	(H->left)->right = H2;
	(H2->left)->right = H;
	np = H->left;
	H->left = H2->left;
	H2->left = np;
	if (start->value > H2->value)
		start = H2;
	return start;
}

void FibonacciHeap::ExtractMin()
{
	if (start == NULL)
		cout << "Heap je prazan" << endl;
	else {
		FibonacciNode* temp = start;
		FibonacciNode* ptr;
		ptr = temp;
		FibonacciNode* x = NULL;
		if (temp->child != NULL) {

			x = temp->child;
			do {
				ptr = x->right;
				(start->left)->right = x;
				x->right = start;
				x->left = start->left;
				start->left = x;
				if (x->value < start->value)
					start = x;
				x->parent = NULL;
				x = ptr;
			} while (ptr != temp->child);
		}
		(temp->left)->right = temp->right;
		(temp->right)->left = temp->left;
		start = temp->right;
		size--;
		if (temp == temp->right && temp->child == NULL)
			start = NULL;
		else {
			start = temp->right;
			Consolidate();
		}
	}
}

void FibonacciHeap::Link(FibonacciNode* p2, FibonacciNode* p1)
{
	(p2->left)->right = p2->right;
	(p2->right)->left = p2->left;
	if (p1->right == p1)
		start = p1;
	if (p2 == start)
		start = start->right;
	p2->left = p2;
	p2->right = p2;
	p2->parent = p1;
	if (p1->child == NULL)
		p1->child = p2;
	p2->right = p1->child;
	p2->left = (p1->child)->left;
	((p1->child)->left)->right = p2;
	(p1->child)->left = p2;
	if (p2->value < (p1->child)->value)
		p1->child = p2;
	p1->degree++;
}

void FibonacciHeap::Consolidate()
{
	int temp1;
	float temp2 = (log(size)) / (log(2));
	int temp3 = temp2;
	FibonacciNode** niz = new FibonacciNode*[temp3+1];
	for (int i = 0; i <= temp3; i++)
	{
		niz[i] = NULL;
	}

	FibonacciNode* ptr1 = start;
	FibonacciNode* ptr2;
	FibonacciNode* ptr3;
	FibonacciNode* ptr4 = ptr1;
	FibonacciNode* ptr5 = start;
	int k = 0;
	if (ptr1 == NULL)
		return;
	/*do {
		temp1 = ptr1->degree;
		while (niz[ptr1->degree] != NULL)
		{
			ptr2 = niz[temp1];
			if (ptr1->value > ptr2->value)
			{
				ptr3 = ptr1;
				ptr1 = ptr2;
				ptr2 = ptr3;
			}
			if (ptr2 == start)
				start = ptr1;
			Link(ptr2, ptr1);
			if (ptr1->right == ptr1)
				start = ptr1;
			niz[temp1] = NULL;
			temp1++;
		}
		//ptr1 = ptr1->right;
		if(niz[ptr1->degree == NULL])
		niz[ptr1->degree] = ptr1;
		ptr1 = ptr1->right;
	} while (ptr1 != start);

	for (int j = 0; j <= temp3; j++) {
		if (niz[j] != NULL) {
			niz[j]->left = niz[j];
			niz[j]->right = niz[j];
			if (start != NULL) {
				(start->left)->right = niz[j];
				niz[j]->right = start;
				niz[j]->left = start->left;
				start->left = niz[j];
				if (niz[j]->value < start->value)
					start = niz[j];
			}
			else {
				start = niz[j];
			}
			if (start == NULL)
				start = niz[j];
			else if (niz[j]->value < start->value)
				start = niz[j];
		}
	}*/
	do {
		if (niz[ptr1->degree] == NULL)
		{
			niz[ptr1->degree] = ptr1;
			ptr1 = ptr1->right;
		}
		else
		{
			while (niz[ptr1->degree] != NULL /*&& niz[ptr1->degree]!=ptr1*/)
			{
				if (niz[ptr1->degree] == ptr1)
				{
					ptr1 = ptr1->right;
					break;
				}
				ptr2 = niz[ptr1->degree];
				ptr4 = ptr1;
				if (ptr1->value > ptr2->value)
				{
					niz[ptr1->degree] = NULL;
					Link(ptr1, ptr2);
					ptr1 = ptr2;
				}
				else
				{
					niz[ptr1->degree] = NULL;
					Link(ptr2, ptr1);
				}
			}
		}
	} while (ptr1->degree!=temp3/*uslov(niz,temp3+1,start)*//*ptr1->right!=start->right*/);
	niz[ptr1->degree] = ptr1;
	niz[ptr1->right->degree] = ptr1->right;
	/*while (ptr1 != start->left)
	{
		niz[ptr1->degree] = ptr1;
		ptr1 = ptr1->right;
	}
	niz[ptr1->degree] = ptr1;*/
	int temp = start->value;
	for (int i = 0; i <= temp3; i++)
	{
		if (niz[i] != NULL)
		{
			if (niz[i]->value < temp)
			{
				temp = niz[i]->value;
				start = niz[i];
			}
		}
	}
}

void FibonacciHeap::PrintRootNodes()
{
	FibonacciNode* p = start;
	if (p == nullptr)
	{
		cout << "The Heap is Empty" << endl;
		return;
	}
	cout << "The root nodes of Heap are: " << endl;
	do
	{
		cout << p->value;
		p = p->right;
		if (p != start)
		{
			cout << "-->";
		}
	}
	while (p != start && p->right != NULL);
	cout << endl;
}

void FibonacciHeap::DecreaseKey(int staro, int novo)
{
	int temp;
	FibonacciNode* p;
	FibonacciNode* y;
	FibonacciNode* z;
	p = SearchNode(start,staro);
	if (p == NULL)
	{
		//cout << "Ne postoji kljuc sa prosledjenom vrednosti" << endl;
		return ;
	}
	if (novo > p->value)
	{
		//cout << "Vrednost novog kljuca je veca od vrednosti starog" << endl;
		return ;
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
		if (z == start)
			start = y;
		z = z->parent;
	}
}
