#pragma once

template <class T>
class SingleLinkedListNode
{
public:
	T data;
	SingleLinkedListNode<T>* next;

	SingleLinkedListNode() : next(nullptr)
	{

	}

	SingleLinkedListNode(const T& value) : SingleLinkedListNode()
	{
		data = value;
	}
};