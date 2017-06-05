#include <iostream>
#include <stdlib.h>
#include "List.h"

int main()
{
	List <int> A;
	A.AddFirst (7);
	A.AddFirst (6);
	A.AddFirst (3);
	A.AddLast (1);
	A.AddFirst (8);
	A.AddFirst (4);
	A.PrintList();
	A.DelFirst ();
	A.DelLast ();
	A.PrintList();
	return 1;
}
	