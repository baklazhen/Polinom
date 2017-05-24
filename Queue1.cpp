#include <iostream>
#include <stdlib.h>
#include "Queue1.h"

int main()
{
	TQueue <int> A;
	TStack <int> B;
	A.Push (1);
	A.Push (2);
	A.Push (3);
	A.Push (4);
	A.Input();
	

	B.Push (1);
	B.Push (2);
	B.Push (3);
	B.Pop ();
	B.Push (4);
	B.Push (5);
	B.Push (6);
	B.Push (7);
	B.Print();
	
	




return 1;

}


      