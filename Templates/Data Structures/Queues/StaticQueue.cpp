template <class T>
class StaticQueue
{
private:
	T* stack;
	int size;
public:
	StaticQueue(int size)
	{
		stack = new T[size];
		this->size = size;
	}

	void Clear()
	{
		
	}

	StaticQueue<T>* Enqueue(const T& val)
	{
		
	}

	StaticQueue<T>* Dequeue()
	{
		
	}

	T& Front() const
	{
		
	}

	T& Rear() const
	{
		
	}

	bool IsEmpty() const
	{
		
	}
};