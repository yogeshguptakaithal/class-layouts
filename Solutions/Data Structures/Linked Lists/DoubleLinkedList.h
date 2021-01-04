#pragma once
#include <cassert>
#include "DoubleLinkedListNode.h"
#include <iostream>

using namespace std;

template <class T>
class DoubleLinkedList
{
protected:
	DoubleLinkedListNode<T>* head;
	DoubleLinkedListNode<T>* tail;
	int count;

	void InitializeList(const T& val)
	{
		DestroyList();
		head = tail = new DoubleLinkedListNode<T>(val);
		count = 1;
	}

	void DestroyList()
	{
		if (count == 0)
			return;

		DoubleLinkedListNode<T>* temp = head;
		while (temp != nullptr)
		{
			head = temp->next;
			delete temp;
			temp = head;
		}

		tail = nullptr;
		count = 0;
	}

	DoubleLinkedListNode<T>* GotoIndex(int index)
	{
		assert(index >= 0 && index < count);

		DoubleLinkedListNode<T>* temp = head;
		for (int i = 0; i < index; ++i)
			temp = temp->next;

		return temp;
	}

	inline void Join(DoubleLinkedListNode<T>* lhs, DoubleLinkedListNode<T>* rhs)
	{
		lhs->next = rhs;
		rhs->previous = lhs;
	}

	inline void Join(DoubleLinkedListNode<T>* lhs, DoubleLinkedListNode<T>* middle, DoubleLinkedListNode<T>* rhs)
	{
		Join(lhs, middle);
		Join(middle, rhs);
	}

public:
	// Default Constructor
	DoubleLinkedList() : head(nullptr), tail(nullptr), count(0)
	{

	}

	// Parametrized Constructor
	DoubleLinkedList(const T* arr, int len) : count(len)
	{
		assert(len >= 0);
		if (len == 0)
		{
			DoubleLinkedList();
			return;
		}

		head = tail = new DoubleLinkedListNode<T>(arr[0]);

		for (int i = 1; i < len; ++i)
		{
			tail->next = new DoubleLinkedListNode<T>(arr[i]);
			tail->next->previous = tail;
			tail = tail->next;
		}
	}

	// Copy Constructor
	DoubleLinkedList(const DoubleLinkedList<T>& oldList) : count(oldList.count)
	{
		DoubleLinkedList();

		DoubleLinkedListNode<T>* temp = oldList.head;
		Initialize(temp->data);

		while (temp->next != nullptr)
		{
			temp = temp->next;
			AddAtLast(temp->data);
		}

		tail = temp;
	}

	// Returns Head
	DoubleLinkedListNode<T>* First() const
	{
		return head;
	}

	// Returns Tail
	DoubleLinkedListNode<T>* Last() const
	{
		return tail;
	}
	
	// Returns Count
	int Length() const
	{
		return count;
	}


	// Insert Operations
	DoubleLinkedList<T>* AddAtFirst(const T& val)
	{
		if (head == nullptr)
		{
			InitializeList(val);
			return this;
		}

		DoubleLinkedListNode<T>* temp = new DoubleLinkedListNode<T>(val);
		Join(temp, head);
		head = temp;

		++count;
		return this;
	}

	DoubleLinkedList<T>* AddAfterIndex(const T& val, int index)
	{
		if (index == count - 1)
			return AddAtLast(val);

		DoubleLinkedListNode<T>* temp = GotoIndex(index);
		DoubleLinkedListNode<T>* node = new DoubleLinkedListNode<T>(val);
		Join(temp, node, temp->next);
		++count;

		return this;
	}

	DoubleLinkedList<T>* AddBeforeIndex(const T& val, int index)
	{
		if (index == 0)
			return AddAtFirst(val);

		return AddAfterIndex(val, index - 1);
	}

	DoubleLinkedList<T>* AddAtLast(const T& val)
	{
		if (head == nullptr)
		{
			InitializeList(val);
			return this;
		}

		DoubleLinkedListNode<T>* temp = new DoubleLinkedListNode<T>(val);
		Join(tail, temp);
		tail = temp;

		++count;
		return this;
	}


	// Remove Operations
	DoubleLinkedList<T>* DeleteAtFirst()
	{
		assert(head != nullptr);

		if (head == tail)
		{
			delete(head);
			head = tail = nullptr;
			count = 0;
			return this;
		}

		DoubleLinkedListNode<T>* temp = head;
		head = head->next;
		delete temp;
		head->previous = nullptr;
		
		--count;

		return this;
	}

	DoubleLinkedList<T>* DeleteAtIndex(int index)
	{
		if (index == 0)
			return DeleteAtFirst();

		if (index == count - 1)
			return DeleteAtLast();

		DoubleLinkedListNode<T>* nodetodelete = GotoIndex(index);
		DoubleLinkedListNode<T>* lhs = nodetodelete->previous;
		DoubleLinkedListNode<T>* rhs = nodetodelete->next;

		delete(nodetodelete);
		Join(lhs, rhs);
		--count;

		return this;
	}

	DoubleLinkedList<T>* DeleteAtLast()
	{
		assert(head != nullptr);

		if (head == tail)
		{
			delete head;
			head = tail = nullptr;
			count = 0;

			return this;
		}

		DoubleLinkedListNode<T>* temp = tail->previous;
		delete tail;
		temp->next = nullptr;

		tail = temp;
		count--;

		return this;
	}


	// Additional Functions
	T* ToArray() const
	{
		T* arr = new T[count];

		DoubleLinkedListNode<T>* temp = head;

		for (int i = 0; i < count; ++i)
		{
			arr[i] = temp->data;
			temp = temp->next;
		}

		return arr;
	}

	T* ToReverseArray() const
	{
		T* arr = new T[count];

		DoubleLinkedListNode<T>* temp = tail;

		for (int i = 0; i < count; ++i)
		{
			arr[i] = temp->data;
			temp = temp->previous;
		}

		return arr;
	}

	bool IsEmpty() const
	{
		return count == 0;
	}

	DoubleLinkedListNode<T>* FindFirstOccurence(const T& value) const
	{
		if (head == nullptr)
			return nullptr;

		DoubleLinkedListNode<T>* temp = head;

		while (temp != nullptr)
		{
			if (temp->data = value)
				return temp;
			temp = temp->next;
		}

		return nullptr;
	}

	void Print(const char* separator = " ") const
	{
		if (head == nullptr)
			return;

		DoubleLinkedListNode<T>* temp = head;

		while (temp->next != nullptr)
		{
			cout << temp->data << separator;
			temp = temp->next;
		}

		cout << temp->data;
	}

	// Destructor
	~DoubleLinkedList()
	{
		DestroyList();
	}
};