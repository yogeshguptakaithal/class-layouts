#pragma once

template <class T>
class DoubleLinkedListNode
{
public:
	T data;
	DoubleLinkedListNode<T>* next;
	DoubleLinkedListNode<T>* previous;

	DoubleLinkedListNode() : next(nullptr), previous(nullptr)
	{

	}

	DoubleLinkedListNode(T val) : DoubleLinkedListNode()
	{
		data = val;
	}
};