#include "AVL.h"

AVL::AVL()
{
	root = nullptr;
}

AVL::~AVL()
{
	clear();
}

NodeInterface * AVL::getRootNode() const
{
	if (root != nullptr)
	{
		return root;
	}
	else { return nullptr; }
}

bool AVL::find(int data) const
{
	return recursFind(data, root);
}

bool AVL::recursFind(int data, Node * local_root) const
{
	if (local_root == nullptr)
	{
		return false;
	}
	if (data < local_root->data)
	{
		return recursFind(data, local_root->left);
	}
	else if (data > local_root->data)
	{
		return recursFind(data, local_root->right);
	}
	else if (data == local_root->data)
	{
		return true;
	}
	else
		return false;
}

void AVL::rotateRightRight(Node *& local_root)
{
	Node* temp = local_root->right;
	local_root->right = temp->left;
	temp->left = local_root;
	local_root->getHeight();
	local_root = temp;
	temp->getHeight();
}

void AVL::rotateLeftLeft(Node *& local_root)
{
	Node* temp = local_root->left;
	local_root->left = temp->right;
	temp->right = local_root;
	local_root->getHeight();
	local_root = temp;
	temp->getHeight();
}

void AVL::rotateRightLeft(Node *& local_root)
{
	rotateLeftLeft(local_root->right);
	rotateRightRight(local_root);
}

void AVL::rotateLeftRight(Node *& local_root)
{
	rotateRightRight(local_root->left);
	rotateLeftLeft(local_root);
}

bool AVL::add(int data)
{
	if (find(data) == true)
	{
		return false;
	}
	else if (find(data) != true)
	{
		return recursAdd(data, root);
	}
}

bool AVL::recursAdd(int data, Node*& local_root)
{
	bool return_value;
	if (local_root == NULL)
	{
		local_root = new Node(data);
		local_root->getHeight();
		rebalance(local_root);
		return true;
	}
	else if (data < local_root->data)
	{
		return_value = recursAdd(data, local_root->left);
		local_root->getHeight();
		rebalance(local_root);
		return return_value;
	}
	else if (data > local_root->data)
	{
		return_value = recursAdd(data, local_root->right);
		local_root->getHeight();
		rebalance(local_root);
		return return_value;
	}
	else
	{
		return false;
	}
}

bool AVL::remove(int data)
{
	if (find(data) != true)
	{
		return false;
	}
	else if (find(data) == true)
	{
		return recursRemove(data, root);
	}
}

bool AVL::recursRemove(int data, Node*& local_root)
{
	bool return_value;
	if (local_root == NULL)
	{
		return false;
	}
	if (data < local_root->data)
	{
		return_value = recursRemove(data, local_root->left);
		local_root->getHeight();
		rebalance(local_root);
		return return_value;
	}
	else if (data > local_root->data)
	{
		return_value = recursRemove(data, local_root->right);
		local_root->getHeight();
		rebalance(local_root);
		return return_value;
	}
	else if (data == local_root->data)
	{
		Node *old_root = local_root;
		if (local_root->left == NULL)
		{
			local_root = local_root->right;
		}
		else if (local_root->right == NULL)
		{
			local_root = local_root->left;
		}
		else if (local_root->left != NULL && local_root->right != NULL)
		{
			replace(old_root, old_root->left);
			rebalancePath(local_root->left);
			local_root->getHeight();
			rebalance(local_root);
		}
		delete old_root;
		return true;
	}
}

int AVL::getDiff(Node* local_root)
{
	int lHeight = 0;
	int rHeight = 0;
	if (local_root->left != nullptr)
	{
		lHeight = local_root->left->height;
	}
	if (local_root->right != nullptr)
	{
		rHeight = local_root->right->height;
	}
	return lHeight - rHeight;
}

void AVL::delete_tree(Node *local_root)
{
	if (local_root != nullptr)
	{
		delete_tree(local_root->left);
		delete_tree(local_root->right);
		delete local_root;
	}
}

void AVL::rebalance(Node*& local_root)
{
	int hDiff = getDiff(local_root);
	if (hDiff > 1)
	{
		if (getDiff(local_root->left) >= 0)
		{
			rotateLeftLeft(local_root);
		}
		else
		{
			rotateLeftRight(local_root);
		}
	}
	else if (hDiff < -1)
	{
		if (getDiff(local_root->right) > 0)
		{
			rotateRightLeft(local_root);
		}
		else
		{
			rotateRightRight(local_root);
		}
	}
}

void AVL::replace(Node *& old_root, Node *& local_root)
{
	if (local_root->right != nullptr)
	{
		replace(old_root, local_root->right);
		local_root->getHeight();
		rebalance(local_root);
	}
	else
	{
		old_root->data = local_root->data;
		old_root = local_root;
		local_root = local_root->left;
	}
}

void AVL::rebalancePath(Node *& local_root)
{
	if (local_root == nullptr)
	{
		return;
	}
	else if (local_root->right != nullptr)
	{
		rebalancePath(local_root->right);
		local_root->getHeight();
		rebalance(local_root);
	}
}

void AVL::clear()
{
	if (root == nullptr) { return; }
	else
	{
		delete_tree(root);
		root = nullptr;
		return;
	}
}
