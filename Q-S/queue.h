#ifndef QUEUE_H_
#define QUEUE_H_
#include <iostream>
using namespace std;

template<typename T>
class Queue
{
protected: 
	T * mas;
	int count;
	int size;
	int top;
	int end;
		
public:
	Queue (int s=1);
	Queue (const Queue<T> &a);
	~Queue ();
	void Add(T a);
	T Get();
	void printQueue ();
	void resize ();
	T * saveTomas();
	 
};

template <typename T>
Queue<T>::Queue (int s)
{
	size = s;
	count = 0;
	top = 0;
	end = 0;
	mas = new T [size];
	for (int i=0; i<size; i++)
		mas [i] = 0;
}

template <typename T>
Queue<T>::Queue (const Queue<T> &a)
{
	size = a.size;
	count = a.count;
	top=a.top;
	end=a.end;
	mas = new T [size];
	for (int i=0; i<size; i++)
		mas [i] = a.mas [i];
}

template <typename T>
Queue<T>::~Queue()
{
    delete [] mas;
}

template <typename T>
void Queue<T>::Add(T a)
{
	if (count==size)
		resize ();
	mas [end] = a;
	end++;
	count ++;
	
	if (end==size)
		end=0;
	
}

template <typename T>
T Queue<T>::Get()
{
	if (count==0)
		cout <<"Warning: Queue is empty!"<< '\n';
	T a = mas [top];
	top++;
	count--;
	if (top==size)
		top=0;
	return a;

}

template <typename T>
void Queue<T>::printQueue()
{
	if (count == 0)
		cout <<"Warning: Queue is empty!"<< '\n';

	if (top<end)
	{
		for (int i = top; i < end; i++)
        cout << mas[i] << '\n' << endl;
	}

	if (top>=end && count !=0)
	{
		for (int i = top; i < size; i++)
        cout << mas[i] << endl;
		for (int j = 0; j < end; j++)
        cout << mas[j] << endl;
	}

	
}


template <typename T>
T * Queue<T>::saveTomas()
{
	T * res;
	res = new T [count];
	
	if (top<end)
	{
		int j = top;
		for (int i = 0; i < end - top; i++)
		{
			res [i] = mas[j];
			j++;
		}
	}

	if (top>=end && count !=0)
	{
		int j = top;
		for (int i = 0; i < size - top; i++)
		{
			res [i] = mas[j];
			j++;
		}
		for (int i = 0; i < end; i++)
        res [size - top + i] = mas[i];
	}
		return res;
   
}


template <typename T>
void Queue<T>::resize()
{
	int * tmp;
	tmp = saveTomas();
	delete [] mas;
	size = size*2;
	mas = new T [size];
	for (int i=0; i<count; i++)
		mas [i] = tmp [i];

	
}


#endif