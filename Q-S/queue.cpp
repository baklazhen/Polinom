#include "queue.h"
#include <iostream>
using namespace std;

int main()
{

    Queue<int> queueS(5);
	int * mas;
	int a = 1, b = 2, c = 6, d = 3, e = 5;
	queueS.Add(a);
    queueS.Add(b);
	queueS.Add(c);
	queueS.Add(d);
    queueS.Add(e);
	queueS.Get();
	queueS.Add(7);
	queueS.Get();
	queueS.Add(8);
	queueS.printQueue();
	mas = queueS.saveTomas();
	queueS.Add(8);
	queueS.printQueue();
	

	
	//queueS.Add(d);
	//queueS.printQueue();
	//queueS.Get();
	//queueS.Get();
	//queueS.Get();
	//queueS.Get();
	
	

	return 0;
}