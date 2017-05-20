#include <iostream>
#include "tmatrix.h"

int main()
{
	//bool s;
	int a = 2, m = 0;
	TVector <float> V (5,1), B (5,3), C;
	TMatrix <float> R(3), G(3), H;
	TMatrix <float> P(3);
	P[0][0] = 1; P[0][1] = 2; P[0][2] = 3;
	P[1][1] = 1; P[1][2] = 2;
	P[2][2] = 1;
	cout << P <<'\n';
	R[0][0] = 2; R[0][1] = 8; R[0][2] = 3;
	R[1][1] = 1; R[1][2] = 7;
	R[2][2] = -2;
	cout << R <<'\n';
	H = P / R;
	cout << H <<'\n';
	P = H * R;
	cout << P <<'\n';
	//H = R.Reverse ();
    //cout << H <<'\n';
	//G[0][0] = 3; G[0][1] = 5; G[0][2] = 9;
	//G[1][1] = -6; G[1][2] = 8;
	//G[2][2] = -4;
	//cout << G <<'\n';
	//H = R + G;
	//cout << H <<'\n';
	//H = R - G;
	//cout << H <<'\n';
	//C = H[0] + H[1] + H[2];
	//cout << C <<'\n';
	//V[1] = 1; V[2] = 3; V[3] = 1; V[4] = 2;
	//B[3] = 1; B[4] = 2;
	//cout << V <<'\n';
	//cout << B <<'\n';
	//C = V + B;
	//cout << C <<'\n';
	//C = V - B;
	//cout << C <<'\n';
	//C = V * a;
	//cout << C <<'\n';
	//m = V * B;
	//cout << m <<'\n';
	//s = V==B;
	//cout << s <<'\n';
	//s = V!=B;
	//cout << s <<'\n';


	return 0;
}