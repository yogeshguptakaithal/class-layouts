template <class T>
class DynamicStack
{
private:
	SingleLinkedList<T>* stack;

public:
	DynamicStack()
	{
		stack = new SingleLinkedList<T>();
	}

	bool IsEmpty() const
	{
		return stack->IsEmpty();
	}

	void Clear()
	{
		while (!IsEmpty())
			stack->DeleteAtFirst();
	}

	DynamicStack<T>* Push(const T& val)
	{
		stack->AddAtLast(val);
		return this;
	}

	DynamicStack<T>* Pop()
	{
		assert(!this->IsEmpty());

		stack->DeleteAtLast();

		return this;
	}

	T& Peek() const
	{
		assert(!this->IsEmpty());
		return stack->Last()->data;
	}

	~DynamicStack()
	{
		Clear();
		delete stack;
	}
};


/*******Test Code*******/
int main()
{
	DynamicStack<int> stack;
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	cout << stack.Peek() << endl;
	stack.Pop()->Pop();
	cout << stack.Peek() << endl;
	stack.Clear();
	cout << stack.Peek() << endl;
}