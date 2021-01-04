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
		
	}

	void Clear()
	{
		
	}

	DynamicStack<T>* Push(const T& val)
	{
		
	}

	DynamicStack<T>* Pop()
	{
		
	}

	T& Peek() const
	{
		
	}

	~DynamicStack()
	{
		
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