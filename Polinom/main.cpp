#include <iostream>
#include "Monom.h"
#include "Polinom.h"
using namespace std;

int main ()
{
	Polinom <int, int> C;
	Polinom <int, int> V;
	Polinom <int, int> Z;
	Monom <int, int> A (8, 2);
	Monom <int, int> B (2, 2);
	Monom <int, int> T (5, 1);
	Monom <int, int> J;
	Monom <int, int> E (3, 2);
	Monom <int, int> D (4, 2);
	A.InputMonom();
	T.InputMonom();
	J = A * T;
	B.InputMonom();
	E.InputMonom();
	D.InputMonom();
	C.Add (A);
	C.Add (B);
	//V = C + E;
	V.Add (E);
	V.Add (D);
	//C.PrintPolinom();
	//V = C;
	//V.PrintPolinom();
	//J = A + B;
	
	Z = C + V;
	Z.PrintPolinom();
	J.PrintMonom();

	return 1;
}
