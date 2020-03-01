#include "BST.h"

BST::BST()
{
	root = NULL;
}

BST::~BST()
{
	clear();
}

NodeInterface * BST::getRootNode() const
{
	if (root != NULL)
	{
		return root;
	}
	else { return nullptr; }
}

bool BST::add(int data)
{
	return recursAdd(data, root);
}

bool BST::recursAdd(int data, Node*& local_root)
{
	if (local_root == NULL)
	{
		local_root = new Node(data);
		return true;
	}
	else if (data < local_root->data) 
	{
		return recursAdd(data, local_root->left);
	}
	else if (data > local_root->data)
	{
		return recursAdd(data, local_root->right);
	}
	else if (data == local_root->data)
		return false;
}

bool BST::remove(int data)
{
	return recursRemove(data, root);
}

bool BST::recursRemove(int data, Node*& local_root)
{
	if (local_root == NULL)
	{
		return false;
	}
	else
	{
		if (data < local_root->data)
		{
			return recursRemove(data, local_root->left);
		}
		else if (data > local_root->data)
		{
			return recursRemove(data, local_root->right);
		}
		else if (data == local_root->data)
		{
			Node *old_root = local_root;
			{
				if (local_root->left == NULL)
				{
					local_root = local_root->right;
				}
				else if (local_root->right == NULL)
				{
					local_root = local_root->left;
				}
				else 
				{
					replace(old_root, old_root->left);
				}
				delete old_root;
				return true;
			}
		}
	}
}

void BST::delete_tree(Node *local_root)
{
	if (local_root != NULL)
	{
		delete_tree(local_root->left);
		delete_tree(local_root->right);
		delete local_root;
	}
}

void BST::replace(Node *& old_root, Node *& local_root)
{
	if (local_root->right != NULL)
	{
		replace(old_root, local_root->right);
	}
	else
	{
		old_root->data = local_root->data;
		old_root = local_root;
		local_root = local_root->left;
	}
}

void BST::clear()
{
	if (root == NULL) { return; }
	else
	{
		delete_tree(root);
		root = NULL;
		return;
	}
}
