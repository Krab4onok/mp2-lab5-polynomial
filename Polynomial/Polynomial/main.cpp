#include"Polynomial.h"
using namespace std;

int main()
{
	int m[][2] = { {10,321},{9,241},{11,159},{23,124} };
	TPolinom p(m, 4);
	TMonom a;
	a.coef = 8;
	a.px = 4;
	a.py = 2;
	a.pz = 1;
	p.AddMonom(a);
	int k;
	k = 4;
	//p*k;
	//p += p;
	cout << p;
	TPolinom pl;
	cin >> pl;
	cout << pl;
}