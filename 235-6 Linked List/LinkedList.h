#pragma once
#include "LinkedListInterface.h"
#include <sstream>

template<typename T>
class LinkedList : public LinkedListInterface<T>
{
	struct node
	{
		T data;
		node* next;
	};

public:
	LinkedList()
	{
		head = NULL;
	};
	~LinkedList() 
	{
		clear();
	};

	bool find(T value)
	{
		node *temp = head;
		while (temp != NULL)
		{
			if (temp->data == value)
			{
				return true;
			}
			temp = temp->next;
		}
		return false;
	}

	void insertHead(T value)
	{
		if (find(value) == false)
		{
			node *temp = new node;
			temp->data = value;
			temp->next = head;
			head = temp;
			length++;
		}
	}

	void insertTail(T value)
	{
		if (find(value) == false)
		{
			node *last = new node;
			last->data = value;
			last->next = NULL;
			if (head == NULL)
			{
				head = last;
			}
			else
			{
				node *temp = head;
				while (temp->next != NULL)
				{
					temp = temp->next;
				}
				temp->next = last;
			}
			length++;
		}
	}

	void insertAfter(T value, T insertionNode)
	{
		if (find(value) == false && find(insertionNode) == true)
		{
			node *temp = new node;
			node *current = head;
			temp->data = value;
			temp->next = NULL;
			for (current = head; current->next != NULL; current = current->next)
			{
				if (insertionNode == current->data)
				{
					temp->next = current->next;
					current->next = temp;
					length++;
					return;
				}
			}
			if (insertionNode == current->data)
			{
				temp->next = current->next;
				current->next = temp;
				length++;
				return;
			}
		}
	}

	void remove(T value)
	{
		if (find(value) == true)
		{
			node *current = head;
			node *previous = NULL;
			if (value == head->data)
			{
				head = head->next;
				delete current;
				length--;
				return;
			}
			while (current->data != value && current->next != NULL)
			{
				previous = current;
				current = current->next;
			}
			previous->next = current->next;
			delete current;
			length--;
			return;
		}
	}

	void clear()
	{
		node *temp = head;
		while (head != NULL)
		{
			temp = head->next;
			delete head;
			head = temp;
		}
		delete temp;
		length = 0;
	}

	T at(int index)
	{
		if (index >= length || index < 0)
		{ 
			throw out_of_range("out");
		}
		node *temp = head;
		int count = 0;
		while (count != index && temp != NULL)
		{
			temp = temp->next;
			count++;
		}
		return temp->data;
	}

	int size()
	{
		return length;
	}

	string toString()
	{
		string s = "";
		stringstream ss;
		node *temp = head;
		for (int i = 1; i <= length; i++)
		{
			ss << temp->data << " ";
			temp = temp->next;
		}
		s = ss.str();
		s = s.substr(0, s.size() - 1);
		return s;
	}

protected:
	node *head = NULL;
	int length = 0;
};
