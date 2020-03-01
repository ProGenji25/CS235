#pragma once
#include "AVLInterface.h"
#include "Node.h"


class AVL : public AVLInterface
{
public:
	AVL();
	~AVL();

	NodeInterface * getRootNode() const;
	bool find(int data) const;
	bool recursFind(int data, Node* local_root) const;
	bool add(int data);
	bool recursAdd(int data, Node*& local_root);
	bool remove(int data);
	bool recursRemove(int data, Node*& local_root);
	int getDiff(Node *local_root);
	void rotateLeftLeft(Node*& local_root);
	void rotateRightRight(Node*& local_root);
	void rotateRightLeft(Node*& local_root);
	void rotateLeftRight(Node*& local_root);
	void delete_tree(Node* local_root);
	void rebalance(Node*& local_root);
	void replace(Node*& old_root, Node*& local_root);
	void rebalancePath(Node*& local_root);
	void clear();

protected:
	Node *root = nullptr;

};

