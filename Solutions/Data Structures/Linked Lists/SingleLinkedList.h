#pragma once
#include <cassert>
#include <iostream>
#include "SingleLinkedListNode.h"
using namespace std;

template <class T>
class SingleLinkedList
{
protected:
	SingleLinkedListNode<T>* head;
	SingleLinkedListNode<T>* tail;
	int count;

	// Helpers
	void Initialize(const T& val)
	{
		DestroyList();
		head = tail = new SingleLinkedListNode<T>(val);
		count = 1;
	}

	void DestroyList()
	{
		if (count == 0)
			return;

		SingleLinkedListNode<T>* temp = head;

		while (temp != nullptr)
		{
			head = temp->next;
			delete(temp);
			temp = head;
		}

		tail = nullptr;
		count = 0;
	}

	SingleLinkedListNode<T>* GotoIndex(int index)
	{
		assert(index > -1 && index < count);

		SingleLinkedListNode<T>* temp = head;

		for (int i = 0; i < index; ++i)
			temp = temp->next;

		return temp;
	}

public:
	// Default Constructor
	SingleLinkedList() : head(nullptr), tail(nullptr), count(0)
	{

	}

	// Parametrized Constructor
	SingleLinkedList(const T* arr, int len) : count(len)
	{
		assert(len >= 0);
		if (len == 0)
		{
			SingleLinkedList();
			return;
		}

		head = tail = new SingleLinkedListNode<T>(arr[0]);

		for (int i = 1; i < len; ++i)
		{
			tail->next = new SingleLinkedListNode<T>(arr[i]);
			tail = tail->next;
		}
	}
	
	// Copy Constrcutor
	SingleLinkedList(const SingleLinkedList<T>& oldList) :count(oldList.count)
	{
		SingleLinkedList();

		if (oldList.count == 0)
			return;

		SingleLinkedListNode<T>* temp = oldList.head;
		Initialize(temp->data);

		while (temp->next != nullptr)
		{
			temp = temp->next;
			AddAtLast(temp->data);
		}

		tail = temp;
	}

	// Returns Head
	SingleLinkedListNode<T>* First() const
	{
		return head;
	}

	// Returns Tail
	SingleLinkedListNode<T>* Last() const
	{
		return tail;
	}

	// Returns Count
	int Length()
	{
		return count;
	}

	bool IsEmpty() const
	{
		return count == 0;
	}
	

	// Insert Operations
	SingleLinkedList<T>* AddAtFirst(const T& val)
	{
		if (head == nullptr)
		{
			Initialize(val);
			return this;
		}

		SingleLinkedListNode<T>* node = new SingleLinkedListNode<T>(val);
		node->next = head;
		head = node;

		++count;
		return this;
	}

	SingleLinkedList<T>* AddAfterIndex(const T& val, int index)
	{
		if (index == count - 1)
			return AddAtLast(val);
		SingleLinkedListNode<T>* temp = GotoIndex(index);
		SingleLinkedListNode<T>* node = new SingleLinkedListNode<T>(val);
		node->next = temp->next;
		temp->next = node;

		++count;

		return this;
	}

	SingleLinkedList<T>* AddBeforeIndex(const T& val, int index)
	{
		if (index == 0)
			return AddAtFirst(val);

		return AddAfterIndex(val, index - 1);
	}

	SingleLinkedList<T>* AddAtLast(const T& val)
	{
		if (head == nullptr)
		{
			Initialize(val);
			return this;
		}


		SingleLinkedListNode<T>* node = new SingleLinkedListNode<T>(val);
		tail->next = node;
		tail = node;
		++count;
		return this;
	}


	// Remove Operations
	SingleLinkedList<T>* DeleteAtFirst()
	{
		assert(head != nullptr);

		if (head == tail)
		{
			delete head;
			tail = head = nullptr;
			count = 0;
			return this;
		}

		SingleLinkedListNode<T>* temp = head;
		head = head->next;
		delete temp;
		
		--count;

		return this;
	}

	SingleLinkedList<T>* DeleteAtIndex(int index)
	{
		if (index == 0)
			return DeleteAtFirst();

		if (index == count - 1)
			return DeleteAtLast();

		SingleLinkedListNode<T>* node1 = GotoIndex(index - 1);
		SingleLinkedListNode<T>* node2 = node1->next->next;

		delete node1->next;
		node1->next = node2;
		--count;
	}

	SingleLinkedList<T>* DeleteAtLast()
	{
		assert(head != nullptr);

		if (head == tail)
		{
			delete head;
			head = tail = nullptr;
			count = 0;
			return this;
		}

		SingleLinkedListNode<T>* temp = GotoIndex(count - 2);
		delete tail;
		tail = temp;

		if (head == tail)
			head->next = nullptr;

		count--;

		return this;
	}

	// Destructor
	~SingleLinkedList()
	{
		DestroyList();
	}
	

	// Additional Functions
	T* ToArray() const
	{
		T* arr = new T[count];

		SingleLinkedListNode<T>* temp = head;

		for (int i = 0; i < count; ++i)
		{
			arr[i] = temp->data;
			temp = temp->next;
		}

		return arr;
	}

	T* ToReverseArray() const
	{
		if (head == nullptr)
			return nullptr;

		T* arr = new T[count];

		SingleLinkedListNode<T>* temp = head;

		for (int i = 0; i < count; ++i)
		{
			arr[count - i - 1] = temp->data;
			temp = temp->next;
		}

		return arr;
	}

	void Print(const char* separator = " ") const
	{
		if (head == nullptr)
			return;

		SingleLinkedListNode<T>* temp = head;

		while (temp->next != nullptr)
		{
			cout << temp->data << separator;
			temp = temp->next;
		}
		cout << temp->data;
	}
};