#pragma once
#include "BSTInterface.h"
#include "Node.h"

class BST : public BSTInterface
{
public:
	BST();
	~BST();

	NodeInterface * getRootNode() const;
	bool add(int data);
	bool recursAdd(int data, Node*& local_root);
	bool remove(int data);
	bool recursRemove(int data, Node*& local_root);
	void delete_tree(Node* local_root);
	void replace(Node*& old_root, Node*& local_root);
	void clear();

protected:
	Node *root = NULL;
};
