template <class T>
class StaticStack
{
private:
	T* stack;
	int size;
public:
	StaticStack(int size)
	{
		stack = new T[size];
		this->size = size;
	}

	bool IsEmpty() const
	{
		
	}

	void Clear()
	{
		
	}

	StaticStack<T>* Push(const T& val)
	{
		
	}

	StaticStack<T>* Pop()
	{
		
	}

	T& Peek() const
	{
		
	}

	~StaticStack()
	{
		
	}
};


/*******Test Code*******/
int main()
{
	StaticStack<int> stack;
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	cout << stack.Peek() << endl;
	stack.Pop()->Pop();
	cout << stack.Peek() << endl;
	stack.Clear();
	cout << stack.Peek() << endl;
}