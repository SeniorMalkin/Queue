#pragma once
#include <stdexcept>
template <class T>
class queue_class
{
	int first,last;
	T* arr;
	int maxsize,size;
public:
	queue_class(int _maxsize_=10)
	{
		arr = new T(_maxsize_);
		maxsize=_maxsize_;
		first=1;
		last=0;
		size=0;
	}
	queue_class(const queue_class& qu)
	{
		first=qu.first;
		last=qu.last;
		maxsize=qu.maxsize;
		arr= new T(maxsize);
		size=qu.size;
		for(int i=0;i!=size;i++)
			arr[i]=qu.arr[i];
	}
	bool IsEmpty()
	{
		return(size==0);
	}
	bool IsFull()
	{
		return(size==maxsize);
	}
	void Push(T el)
	{
		if (IsFull())
			throw logic_eror("Queue is Full");
		if(last==maxsize-1)
			last=0;
		else
			last++;
		arr[last]=el;
		size++;
	}

	T Pop()
	{
		if (IsEmpty())
			throw logic_eror("Queue is Empty");
		T tmp =arr[first];
		if (first == maxsize -1;)
			first=0;
		else
			first++;
		size--;
		return tmp;

	}
	T First()
	{
		return arr[first];
	}


	T Last()
	{
		return arr[last];
	}
	~queue_class(void)
	{
		delete[] arr;
	}
};

