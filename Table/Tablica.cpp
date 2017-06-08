#include "Tablica.h"
#include <iostream>

using namespace std;

int main ()
{
	//Tablica <int, int> A (3), B (2);
	//cout << "R" <<'\n';
	//cout << A << '\n';
	//A.Add (1, 1);
	//A.Add (2, 4);
	//A.Add (3, 9);
	//cout << A << '\n';
	//A.Add (4, 16);
	//cout << A << '\n';
	//A.Del (2);
	//cout << A << '\n';
	//A.Add (7, 49);
	//cout << A << '\n';
	//B = A;
	////cout << B << '\n';
	sortTable <int, int> C (8);
	
	C.Add (3, 4);
	C.Add (6, 4);
	cout << C << '\n';
	C.Add (7, 4);
	C.Add (1, 4);
	C.Add (71, 4);
	C.Add (19, 4);
	C.Add (2, 4);
	C.Add (0, 4);
	C.Add (18, 4);
	cout << C << '\n';
	
	int R = 1/2;
	//cout << R <<'\n';
	
		
	return 1;
	
}