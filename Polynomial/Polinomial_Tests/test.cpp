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
	int m1[][2] = { { 100,321 }, { 90,241 }, { 110,159 }, { 230,124 } };
	TPolinom a(m, 4);
	TPolinom r(m1, 4);
	int c = 10;
	ASSERT_NO_THROW(a * c);
	r.Reset();
	a.Reset();
	int f;
	while (!r.IsEnd())
	{
		if (r.pCurr->val == a.pCurr->val)
		{
			f = 1;
			r.GoNext();
			a.GoNext();
		}
		else
		{
			f = 0;
			r.GoNext();
			a.GoNext();
		}
	}
	EXPECT_EQ(f, 1);

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
	int m1[][2] = { { 10,321 }, { 9,241 },{3,213}, { 11,159 }, { 23,124 } };
	TPolinom a(m, 4);
	TMonom k(3, 2, 1, 3);
	TPolinom r(m1, 5);
	ASSERT_NO_THROW(a.AddMonom(k));
	r.Reset();
	a.Reset();
	int f;
	while (!r.IsEnd())
	{
		if (r.pCurr->val == a.pCurr->val)
		{
			f = 1;
			r.GoNext();
			a.GoNext();
		}
		else
		{
			f = 0;
			r.GoNext();
			a.GoNext();
		}
	}
	EXPECT_EQ(f, 1);

}
TEST(TPolinom, CAN_ADD_POLINOM_TO_POLINOM)//+=
{
	int m[][2] = { { 10,321 }, { 9,241 }, { 11,159 }, { 23,124 } };
	TPolinom a(m, 4);
	ASSERT_NO_THROW(a += a);
}
TEST(TPolinom, CAN_ADD_POLINOMS)//+
{
	int m[][2] = { { 10,321 }, { 9,241 }, { 11,159 }, { 23,124 } };
	int m1[][2] = { { 20,321 }, { 18,241 }, { 22,159 }, { 46,124 } };
	int f;
	TPolinom a(m, 4);
	TPolinom p(m, 4);
	ASSERT_NO_THROW(a + p);
	TPolinom r(a);
	TPolinom ch(m1, 4);
	r.Reset();
	ch.Reset();
     while(!r.IsEnd())
	{
		if (r.pCurr->val == ch.pCurr->val)
		{
			f = 1;
			r.GoNext();
			ch.GoNext();
		}
		else
		{
			f = 0;
			r.GoNext();
			ch.GoNext();
		}
	}
	EXPECT_EQ(f, 1);
}
TEST(TPolinom, CAN_ASSIGN_POLINOMS)
{
	int m[][2] = { { 10,321 }, { 9,241 }, { 11,159 }, { 23,124 } };
	TPolinom a(m, 4);
	TPolinom r;
	ASSERT_NO_THROW(r = a);
}
TEST(TPolinom, ASSIGNED_POLINOMS_ARE_EQUAL)
{
	int m[][2] = { { 10,321 }, { 9,241 }, { 11,159 }, { 23,124 } };
	TPolinom a(m, 4);
	TPolinom r;
	int f;
	ASSERT_NO_THROW(r = a);
	r.Reset();
	a.Reset();
	while (!r.IsEnd())
	{
		if (r.pCurr->val == a.pCurr->val)
		{
			f = 1;
			r.GoNext();
			a.GoNext();
		}
		else
		{
			f = 0;
			r.GoNext();
			a.GoNext();
		}
	}
	EXPECT_EQ(f, 1);
}
TEST(TPolinom, ASSIGNED_POLINOM_HAS_OWN_MEMORY)
{
	int m[][2] = { { 10,321 }, { 9,241 }, { 11,159 }, { 23,124 } };
	TPolinom a(m, 4);
	TPolinom r;
	int f;
	ASSERT_NO_THROW(r = a);
	TMonom k(3, 2, 1, 3);
	r.AddMonom(k);
	r.Reset();
	a.Reset();
	while (!r.IsEnd())
	{
		if (r.pCurr->val == a.pCurr->val)
		{
			f = 1;
			r.GoNext();
			a.GoNext();
		}
		else
		{
			f = 0;
			r.GoNext();
			a.GoNext();
		}
	}
	EXPECT_NE(f, 1);
}
TEST(TPolinom, CAN_MULTIPY_TO_ZERO_AND_THIS_POLINOM_WILL_BE_EMPTY)
{

	int m[][2] = { { 10,321 }, { 9,241 }, { 11,159 }, { 23,124 } };
	TPolinom a(m, 4);
	ASSERT_NO_THROW(a * 0);
	int f = 0;
	for (a.Reset(); !a.IsEnd(); a.GoNext())
	{
		f++;
	}
	EXPECT_EQ(f, 0);
}
