#pragma once
#include <stdexcept>
template <class T>
struct TLink
{
	T val;
	TLink* pNext;
};
template <class T>
class TQueue 
{
	TLink<T>* pFirst;
	TLink<T>* pLast;
public:
	TQueue()
	{
		pFirst=pLast=NULL;
	}
	void Push (T elem)
	{
		if(IsFull())
			throw logic_eror("Queue is Full");
		TLink<T>* tmp = new TLink<T>;
		tmp->val=elem;
		tmp->pNext=NULL;
		if(pFirst == NULL)
			pFirst=pLast=tmp;
		else
			pLast->pNext=tmp;
		pLast=tmp;
	}
	T Pop(void)
	{
		if (IsEmpty())
			throw logic_eror("Queue is Empty");
		T buf = pFirst->val;
		TLink<T>* tmp = pFirst;
		if(pFirst == pLast)
		{
			pFirst=pLast=NULL;
		    delete tmp;
		}
		else 
	    {
		pFirst=pFirst->Next;
		delete tmp;
		}
		return buf;
	}
	bool IsFull()
	{
		TLink<T>* tmp=new TLink<T>;
		if(tmp==NULL)
			return true;
		else
		{
			delete tmp;
			return false;
		}
	}
	bool IsEmpty()
	{
		if(pFirst==pLast==NULL)
			return true;
		else 
			return false;
	}
	~TQueue()
	{
		TLink<T>* tmp=pFirst;
		while(pFirst!=NULL)
		{
			tmp=pFirst->pNext;
			delete pFirst;
			pFirst = tmp;
		}
	}
};
	
