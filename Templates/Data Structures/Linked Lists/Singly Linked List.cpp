// layout for linked list

// Don't change this
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

// Add code here

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
		
	}

	void DestroyList()
	{
		
	}

	SingleLinkedListNode<T>* GotoIndex(int index)
	{
		
	}

public:
	// Default Constructor
	SingleLinkedList()
	{

	}

	// Parametrized Constructor
	SingleLinkedList(const T* arr, int len)
	{
		
	}
	
	// Copy Constrcutor
	SingleLinkedList(const SingleLinkedList<T>& oldList)
	{
		
	}

	// Returns Head
	SingleLinkedListNode<T>* First() const
	{
		
	}

	// Returns Tail
	SingleLinkedListNode<T>* Last() const
	{
		
	}

	// Returns Count
	int Length() const
	{
		
	}

	bool IsEmpty() const
	{
		
	}
	

	// Insert Operations
	SingleLinkedList<T>* AddAtFirst(const T& val)
	{
		
	}

	SingleLinkedList<T>* AddAfterIndex(const T& val, int index)
	{
		
	}

	SingleLinkedList<T>* AddBeforeIndex(const T& val, int index)
	{
		
	}

	SingleLinkedList<T>* AddAtLast(const T& val)
	{
		
	}


	// Remove Operations
	SingleLinkedList<T>* DeleteAtFirst()
	{
		
	}

	SingleLinkedList<T>* DeleteAtIndex(int index)
	{
		
	}

	SingleLinkedList<T>* DeleteAtLast()
	{
		
	}

	// Destructor
	~SingleLinkedList()
	{
		
	}
	

	// Additional Functions
	T* ToArray() const
	{
		
	}

	T* ToReverseArray() const
	{
		
	}

	void Print(const char* separator = " ") const
	{
		
	}
};