#ifndef STACK_H_
#define STACK_H_
#include <iostream>
using namespace std;

template<typename T>
class Stack
{
protected: 
	T * mas;
	int count;
	int size;
public:
	Stack (int s=1);
	Stack (const Stack<T> &a);
	~Stack ();
	void Add (T a);
    T Get ();
	void printStack ();
	T * saveTomas ();
	 
};

template <typename T>
Stack<T>::Stack (int s)
{
	size = s;
	count = 0;
	mas = new T [size];
	for (int i=0; i<size; i++)
		mas [i] = 0;
}

template <typename T>
Stack<T>::Stack (const Stack<T> &a)
{
	size = a.size;
	count = a.count;
	mas = new T [size];
	for (int i=0; i<size; i++)
		mas [i] = a.mas [i];
}

template <typename T>
Stack<T>::~Stack()
{
    delete [] mas;
}

template <typename T>
void Stack<T>::Add(T a)
{
	if (count>=size)
		cout <<"Warning: Stack is full!"<< '\n';
	mas [count] = a;
	count ++;
}

template <typename T>
T Stack<T>::Get()
{
	if (count==0)
		cout <<"Warning: Stack is empty!"<< '\n';
	count--;
	return mas [count];
}

template <typename T>
void Stack<T>::printStack()
{
    for (int i = count - 1; i>= 0; i--)
        cout << mas[i] << '\n' << endl;
}

template <typename T>
T * Stack<T>::saveTomas()
{
	T * res;
	res = new T [count];
	for (int i = 0; i < count; i++)
		res[i] = mas [i];
	
		return res;
   
}


#endif
