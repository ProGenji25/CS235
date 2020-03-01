#pragma once
#include "NodeInterface.h"
#include <algorithm>

class Node : public NodeInterface
{
	friend class AVL;

protected:
	int data;
	Node *left, *right;
	int height;

public:
	Node(int x);
	~Node();
	int getData() const;
	NodeInterface * getLeftChild() const;
	NodeInterface * getRightChild() const;
	int getHeight();
};
