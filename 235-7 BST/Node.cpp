#include "Node.h"

Node::Node(int x)
{
	data = x;
	left = right = NULL;
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
	if (left != NULL)
	{
		return left;
	}
	return NULL;
}

NodeInterface * Node::getRightChild() const
{
	if (right != NULL)
	{
		return right;
	}
	return NULL;
}
