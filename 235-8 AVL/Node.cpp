#include "Node.h"

Node::Node(int x)
{
	data = x;
	left = right = nullptr;
	height = 0;
}

Node::~Node()
{
}

int Node::getData() const
{
	return data;
}

NodeInterface * Node::getLeftChild() const
{
	if (left != nullptr)
	{
		return left;
	}
	return nullptr;
}

NodeInterface * Node::getRightChild() const
{
	if (right != nullptr)
	{
		return right;
	}
	return nullptr;
}

int Node::getHeight()
{
	int lHeight = 0;
	int rHeight = 0;
	if (left != nullptr) {
		lHeight = left->height;
	}
	if (right != nullptr) {
		rHeight = right->height;
	}
	height = max(lHeight, rHeight) + 1;
	return height;
}