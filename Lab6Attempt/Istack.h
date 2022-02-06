#ifndef ISTACK_HPP
#define ISTACK_HPP

namespace  data_structures
{
    template <class T>
    class IStack
    {
	public:
		virtual bool isEmptyQueue() const noexcept = 0;
		virtual bool Size() const noexcept = 0;
	
		virtual void initializeQueue() = 0;
	//	virtual T& front() = 0;
	//	virtual T back() const = 0;
		virtual void addQueue(const T& newElement) = 0;
		virtual void deleteQueue() = 0;
		
	};
    };

#endif