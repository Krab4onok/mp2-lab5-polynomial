#include"Polynomial.h"
using namespace std;

int main()
{
	int m[][2] = { {10,321},{9,241},{11,159},{23,124} };
	TPolinom p(m, 4);
	TMonom a;
	a.coef = 9;
	a.px = 3;
	a.py = 2;
	a.pz = 1;
	p.AddMonom(a);
	cout << p;
}