#pragma once
#include "NodeInterface.h"

class Node : public NodeInterface
{
	friend class BST;

private:
	int data;
	Node *left, *right;

public:
	Node(int x);
	~Node();
	int getData() const;
	NodeInterface * getLeftChild() const;
	NodeInterface * getRightChild() const;
};
