#include "pch.h"
#include <iostream>

TEST(TPolinom, CAN_CREATE_POLINOM)
{
	ASSERT_NO_THROW(TPolinom a);
};
TEST(TPolinom, CAN_CREATE_POLINOM_WITH_ARRAY)
{
	int m[][2] = { { 10,321 }, { 9,241 }, { 11,159 }, { 23,124 } };
	ASSERT_NO_THROW(TPolinom a(m, 4));
};
TEST(TPolinom, CAN_CREATE_COPIED_POLINOM)
{
	TPolinom a;
	ASSERT_NO_THROW(TPolinom b(a));
}
TEST(TPolinom, COPIED_POLINOM_IS_EQUAL_TO_ORIGIN)
{
	int m[][2] = { { 10,321 }, { 9,241 }, { 11,159 }, { 23,124 } };
	TPolinom a(m,4);
	TPolinom b(a);
	cout << a << endl << b<< endl;
	int T = 0 ;
	a.Reset();
	b.Reset();
	while (!a.IsEnd())
	{
		if (a.pCurr->val == b.pCurr->val)
		{
			T = 1;
		}
		else T = 0;
		a.GoNext();
		b.GoNext();
	}
	EXPECT_EQ(T, 1);
}
TEST(TPolinom, COPIED_POLINOM_HAS_OWN_MEMORY)
{
	int m[][2] = { { 10,321 }, { 9,241 }, { 11,159 }, { 23,124 } };
	TPolinom a(m, 4);
	TPolinom b(a);
	TMonom k(3,2,1,3);
	ASSERT_NO_THROW(b.AddMonom(k));
	int T;
	while (!a.IsEnd())
	{
		if (a.pCurr->val == b.pCurr->val)
		{
			T = 1;
		}
		else T = 0;
		a.GoNext();
		b.GoNext();
	}
	EXPECT_NE(T, 1);
}
TEST(TPolinom, CAN_MULTIPLY_POLINOM_TO_CONST)
{
	int m[][2] = { { 10,321 }, { 9,241 }, { 11,159 }, { 23,124 } };
	TPolinom a(m, 4);
	int c = 10;
	ASSERT_NO_THROW(a * c);
}
TEST(TPolinom, CAN_MULTIPLY_POLINOM_TO_MONOM)
{
	int m[][2] = { { 10,321 }, { 9,241 }, { 11,159 }, { 23,124 } };
	TPolinom a(m, 4);
	TMonom k(3, 2, 1, 3);
	ASSERT_NO_THROW(a * k);
}
TEST(TPolinom, CAN_ADD_MONOM_TO_POLINOM)
{
	int m[][2] = { { 10,321 }, { 9,241 }, { 11,159 }, { 23,124 } };
	TPolinom a(m, 4);
	TMonom k(3, 2, 1, 3);
	ASSERT_NO_THROW(a.AddMonom(k));
}
TEST(TPolinom, CAN_ADD_POLINOM_TO_POLINOM)
{
	int m[][2] = { { 10,321 }, { 9,241 }, { 11,159 }, { 23,124 } };
	TPolinom a(m, 4);
	ASSERT_NO_THROW(a += a);
}