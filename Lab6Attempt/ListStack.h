#ifndef LIST_m_stackHPP
#define LIST_m_stackHPP

//#include "Stack.h"
#include "LinkedList.h"
#include "Istack.h"
#include "Exception.h"

namespace data_structures
{
	template <class T>
	class ListStack final : public IStack<T>
	{
		
	public:
		ListStack() = default;
		ListStack(const ListStack& copy);
		ListStack& operator=(const ListStack& rhs);
		ListStack(ListStack&& copy) noexcept;
		ListStack& operator=(ListStack&& rhs) noexcept;
		~ListStack() = default; 
		bool isEmptyQueue() const noexcept override;
		bool Size() override;
		 void addQueue(const T& newElement);
		T initializeQueue();
		//Function to initialize the queue to an empty state.
		//Postcondition: The queue is empty.
		//T& front() override;
		//T back() const override;
		void deleteQueue();
	//	T front() const override;
		T Peek() override;





	private:
		//nodeType<Type>* queueFront; //pointer to the front of the queue
		//nodeType<Type>* queueRear; //pointer to the rear of the queue
		LinkedList<T>* queueFront;
		LinkedList<T>* queueRear;

		//how do I implement them like m_stack?\
		//HELLLLP
	};
	};

	template <class T>
	ListStack<T>::ListStack(const ListStack& copy)
	{
		*this = copy;
	}
	template <class T>
	ListStack<T>& ListStack<T>::operator=(const ListStack& rhs)
	{
		if (this != &rhs)
		{
			m_stack = rhs.m_stack;
		}
		return *this;
	}

	template <class T>
	ListStack<T>::ListStack(ListStack&& copy) noexcept
	{
		*this = std::move(copy);
	}

	template <class T>
	ListStack<T>& ListStack<T>::operator=(ListStack&& rhs) noexcept
	{
		if (this != &rhs)
		{
			m_stack = std::move(rhs.m_stack);
		}
		return *this;
	}

	/*template<class T>
	inline data_structures::ListStack<T>::isEmptyQueue()
	{
			return(queueFront == NULL);
	}

	template<class T>
	inline data_structures::ListStack<T>::isFullQueue()
	{
		return false;
	}*/

	template<class T>
	T ListStack<T>::initializeQueue()
	{
		nodeType<Type>* temp;
		while (queueFront != NULL) //while there are elements left
		//in the queue
		{
			temp = queueFront; //set temp to point to the current node
			queueFront = queueFront->link; //advance first to
			//the next node
			delete temp; //deallocate memory occupied by temp
		}
		queueRear = NULL; //set rear to NULL
	}
	template <class T>
	void ListStack<T>::addQueue(const T& newElement)
		
	{
		nodeType<Type>* newNode;
		newNode = new nodeType<Type>; //create the node
		newNode->info = newElement; //store the info
		newNode->link = NULL; //initialize the link field to NULL
		if (queueFront == NULL) //if initially the queue is empty
		{
			queueFront = newNode;
			queueRear = newNode;
		}
		else //add newNode at the end
		{
			queueRear->link = newNode;
			queueRear = queueRear->link;
		}
	}//end addQueue
	//template <class T>
	//T& ListStack<T>::front()
	//{
	//	assert(queueFront != NULL);
	//	return queueFront->info;
	//} //end front
	//template <class T>
	//T ListStack<T>::back() const
	//{
	//	assert(queueRear != NULL);
	//	return queueRear->info;
	//} //end back

	template <class T>
	void ListStack<T>::deleteQueue()
	{
		nodeType<Type>* temp;
		if (!isEmptyQueue())
		{
			temp = queueFront; //make temp point to the first node
			queueFront = queueFront->link; //advance queueFront
			delete temp; //delete the first node
			if (queueFront == NULL) //if after deletion the
			//queue is empty
				queueRear = NULL; //set queueRear to NULL
		}
		else
			cout << "Cannot remove from an empty queue" << endl;
	}//end deleteQueue

	template<class T>
	ListStack<T>::ListStack()
	{
		queueFront = NULL; //set front to null
		queueRear = NULL; //set rear to null
	} //end default constructor


	template <class T>
	T ListStack<T>::Peek()
	{
		
		return m_stack.Last();
	}


	


#endif