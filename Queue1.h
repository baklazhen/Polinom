#ifndef _QUEUE1_H_
#define _QUEUE1_H_
using namespace std;





template <class T>
class TQueue

{	
	
	
protected:
	struct Node
	{
		T val;
		Node *Next;
		Node ():val(0), Next(0){}
		
	};
	
	Node *Head,*Tail;
public:
	
     TQueue():Head(0),Tail(0){};
     ~TQueue();
     void Push (const T &v);
	 void Pop ();
     
};

template <class T>
TQueue<T>::~TQueue()
{
	Node *temp = Head;
	 while (temp!=0) 
	 {
		  temp = Head->Next;
		  delete Head;
		  Head=temp;
	 }
}

template <class T>
void TQueue<T>::Push(const T &v)
{
	Node *temp=new Node;
	temp->val=v;
	temp->Next=0;
	 if (Head!=0)
	 {
        Tail->Next=temp;
        Tail=temp; 
	 }
         else Head=Tail=temp;
}

template <class T>
void TQueue<T>::Pop()
{
	if (Head==0)
		cout <<"Warning: Queue is empty!"<< '\n';

	Node *temp=Head;
    if (Head!=Tail) 
    {
       
        Head=Head->Next;
        delete temp;
    }
	else 
	{
		Head = Tail = 0;
		delete temp;
	}
}




template <class T>
class TStack

{
	protected:
	struct Node
	{
		T val;
		Node *Next;
		Node ():val(0), Next(0){}
		
	};
	
	Node *Head,*Tail;
	

public:
     TStack():Head(0), Tail(0){};
     ~TStack();
     void Push (const T &v);
	 void Pop ();
     
};


template <class T>
TStack <T>::~TStack()
{
}

template <class T>
void TStack<T>::Push(const T &v)
{
	Node *temp=new Node;
	if (Head!=0)
	{
		temp->val=v;
		temp->Next=Head;
		Head = temp;
	}
	else Head=Tail=temp;
		
	
	
}

template <class T>
void TStack<T>::Pop()
{
	if (Head==0)
		cout <<"Warning: Stack is empty!"<< '\n';
	Node *temp = Head;
	if (Head!=Tail) 
    {
		Head=Head->Next;
		delete temp;
    }
	else
	{
		Head = Tail = 0;
		delete temp;
	}

	
}

#endif

 

