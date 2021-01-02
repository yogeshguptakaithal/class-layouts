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

template <class T>
class DoubleLinkedList
{
protected:
	DoubleLinkedListNode<T>* head;
	DoubleLinkedListNode<T>* tail;
	int count;

	void InitializeList(const T& val)
	{
		
	}

	void DestroyList()
	{
		
	}

	DoubleLinkedListNode<T>* GotoIndex(int index)
	{
		
	}

	inline void Join(DoubleLinkedListNode<T>* lhs, DoubleLinkedListNode<T>* rhs)
	{
		
	}

	inline void Join(DoubleLinkedListNode<T>* lhs, DoubleLinkedListNode<T>* middle, DoubleLinkedListNode<T>* rhs)
	{
		
	}

public:
	// Default Constructor
	DoubleLinkedList() : head(nullptr), tail(nullptr), count(0)
	{

	}

	// Parametrized Constructor
	DoubleLinkedList(const T* arr, int len) : count(len)
	{
		
	}

	// Copy Constructor
	DoubleLinkedList(const DoubleLinkedList<T>& oldList) : count(oldList.count)
	{
		
	}

	// Returns Head
	DoubleLinkedListNode<T>* First() const
	{
		
	}

	// Returns Tail
	DoubleLinkedListNode<T>* Last() const
	{
		
	}
	
	// Returns Count
	int Length() const
	{
		
	}


	// Insert Operations
	DoubleLinkedList<T>* AddAtFirst(const T& val)
	{
		
	}

	DoubleLinkedList<T>* AddAfterIndex(const T& val, int index)
	{
		
	}

	DoubleLinkedList<T>* AddBeforeIndex(const T& val, int index)
	{
		
	}

	DoubleLinkedList<T>* AddAtLast(const T& val)
	{
		
	}


	// Remove Operations
	DoubleLinkedList<T>* DeleteAtFirst()
	{
		
	}

	DoubleLinkedList<T>* DeleteAtIndex(int index)
	{
		
	}

	DoubleLinkedList<T>* DeleteAtLast()
	{
		
	}


	// Additional Functions
	T* ToArray() const
	{
		
	}

	T* ToReverseArray() const
	{
		
	}

	bool IsEmpty() const
	{
		
	}

	DoubleLinkedListNode<T>* FindFirstOccurence(const T& value) const
	{
		
	}

	void Print(const char* separator = " ") const
	{
		
	}

	// Destructor
	~DoubleLinkedList()
	{
		
	}
};