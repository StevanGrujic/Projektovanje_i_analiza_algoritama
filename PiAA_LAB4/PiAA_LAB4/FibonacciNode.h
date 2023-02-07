#pragma once
class FibonacciNode
{
public:
	int value;
	int degree;
	FibonacciNode* right;
	FibonacciNode* left;
	FibonacciNode* child;
	FibonacciNode* parent;
	char C;

public:
	FibonacciNode()
	{
		this->right = nullptr;
		left = nullptr;
		child = nullptr;
		parent = nullptr;
		value = 0;
		degree = 0;
		C = 'N';

	}
	FibonacciNode(int val)
	{
		this->right = this;
		left = this;
		child = nullptr;
		parent = nullptr;
		value = val;
		degree = 0;
		C = 'N';
	}
};

