#pragma once
#include<iostream>
using namespace std;
template <class T>
struct TNode
{
	T val;
	TNode <T>* pNext;
};
struct TMonom
{
	double coef;
	int px, py, pz;
public:
	bool operator == (const TMonom& a)
	{
		//if (*this == a) return true;
		if ( px == a.px && py == a.py && pz == a.pz) return true;
		else return false;
	}
	bool operator != (const TMonom& a)
	{
		if (*this == a) return false;
		else return true;
	}
	bool operator >(const TMonom& a)
	{
		if (px > a.px) {
			return true;
		}
		else if (py > a.py) return true;
		else if (pz > a.pz) return true;
		return false;
	}
	bool operator < (const TMonom& a)
	{
		if (*this == a) return false;
		if (*this > a) return false;
		else return true;
	}
	bool operator >=(const TMonom& a)
	{
		if (*this > a || *this == a)return true;
		else return false;
	}
	bool operator <=(const TMonom& a)
	{
		if (*this < a || *this == a)return true;
		else return false;
	}
	friend ostream& operator <<(ostream& os,  TMonom& a)
	{
		os << a.coef << "x^(" << a.px << ")" << "y^(" << a.py << ")" << "z^(" << a.pz << ")" << endl;
		return os;
	}
	friend istream& operator >>(istream& is,  TMonom& a)
	{
		double k;
		int j;
		cout << "enter coeff: ";
		is >> k;
		a.coef = k;
		cout << "enter power x: ";
		is >> j;
		a.px = j;
		cout << "enter power y: ";
		is >> j;
		a.py = j;
		cout << "enter power z: ";
		is >>j;
		a.pz = j;
		return is;
	}
	TMonom(double coef1, int px1, int py1, int pz1)
	{
		coef = coef1;
		px = px1;
		py = py1;
		pz = pz1;
	}
	TMonom() {};
};
template <class T>
class TList
{
public:
	TNode <T>* pFirst;
	TNode <T>* pLast;
	TNode <T>*pCurr;
	TNode <T>*pPrev;
	TNode <T>* pStop;
	int pos, len;
public:
	TList()
	{
		pFirst = pLast = pCurr = pPrev = pStop = NULL;
		len = 0;
		pos = -1;
	}
	~TList()
	{
		TNode <T>* tmp = pFirst;
		while (pFirst != NULL)
		{
			pFirst = pFirst->pNext;
			delete tmp;
			tmp = pFirst;
		}
	}
	TList(const TList& a)
	{
		TNode <T>* tmp = new TNode<T>;
		tmp = pFirst;
		a.pFirst = tmp;
		do 
		{
			a.pCurr= tmp;
			tmp = tmp->pNext;


		} while (tmp != pLast);
	}
	void InsFirst(T a)
	{
		TNode<T>* tmp = new TNode<T>;
		tmp->pNext = pFirst;
		tmp->val = a;
		pFirst = tmp;
		if (pPrev == NULL) pPrev = pFirst;
		len++;
	}
	void InsLast(T elem)
	{
		TNode<T>* tmp = new TNode <T>;
		tmp->val = elem;
		tmp->pNext = NULL;
		if (pLast == NULL)
		{
			pPrev = pCurr = pFirst = pLast = tmp;
		}
		else
		{
			pLast->pNext = tmp;
			pLast = tmp;
		}
		len++;
	}
	void DelFirst()
	{
		if (len == 0)throw - 1;
		len--;
		TNode<T>* tmp = new TNode<T>;
		tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
	}
	void InsCurr(T elem)
	{
		if (pCurr == pFirst) InsFirst(elem);
		else
		{
			TNode <T>* tmp;
			tmp = new TNode<T>;
			tmp->val = elem;
			pPrev->pNext = tmp;
			tmp->pNext = pCurr;
			pCurr = tmp;
			len++;
		}
		if (pCurr == pStop)throw - 1;
	}
	void DelCurr()
	{
		if (pCurr == NULL)throw - 1;
		if (pCurr == pStop)throw - 1;
		if (pCurr == pFirst) DelFirst();
		else
		{
			TNode <T>* tmp;
			tmp = new TNode<T>;
			tmp = pCurr;
			pPrev->pNext = pCurr->pNext;
			pCurr = pCurr->pNext;
			delete tmp;
			len--;
		}
	}
	void Reset()
	{
		pCurr = pFirst;
		pPrev = NULL;
		pos = 0;
	}
	void GoNext()
	{
		if (pos > len)throw - 1;
		pPrev = pCurr;
		
		pCurr = pCurr->pNext;
		pos++;
	}
	bool IsEnd()
	{
		return pCurr ==NULL;
	}
};
template <class T>
class THeadList: public TList<T>
{
protected:
	TNode<T>* pHead;
public:

	THeadList() :TList<T>()
	{
		pHead = new TNode<T>;
		pHead->pNext = pHead;
		TList<T>::pStop = pHead;
	};
	THeadList(const THeadList& a) :TList<T>()
	{
		a.pHead = pHead;
	}
	~THeadList()
	{
		delete pHead;
		TNode <T>* tmp = TList<T>::pFirst;
		while (TList<T>::pFirst != NULL)
		{
			TList<T>::pFirst = TList<T>::pFirst->pNext;
			delete tmp;
			tmp = TList<T>::pFirst;
		}
	};
	void InsFirst(T elem)
	{
		TList::InsFirst(elem);
		pHead->pNext = TList<T>::pFirst;
	};
	void DelFirst()
	{
		TList::DelFirst();
		pHead->pNext = TList<T>::pFirst;
	};
};
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//////////////////////// À¿—— œŒÀ»ÕŒÃ/////////////////////////////
class TPolinom : public THeadList<TMonom>
{
	public:
		
		TPolinom() : THeadList<TMonom>()
		{
			pHead->val.coef = 0;
			pHead->val.px = 0;
			pHead->val.py = 0;
			pHead->val.pz = -1;
		}
		TPolinom(int monoms[][2], int n): THeadList<TMonom>()
		{
			pHead->val.coef = 0;
			pHead->val.px = 0;
			pHead->val.py = 0;
			pHead->val.pz = -1;
			TMonom M;
			for (int i = 0; i < n; i++)
			{
				M.coef = monoms[i][0];
				M.pz = monoms[i][1] % 10;
				M.px = monoms[i][1] / 100;
				M.py = (monoms[i][1] - (monoms[i][1] / 100) * 100 - monoms[i][1] % 10)/10;
				InsLast(M);
			}
		}
		TPolinom( TPolinom &a): THeadList<TMonom>()
		{
			pHead->val.coef = 0;
			pHead->val.px = 0;
			pHead->val.py = 0;
			pHead->val.pz = -1;
			TMonom M;
			for (a.Reset(); !a.IsEnd(); a.GoNext())
			{
				M = a.pCurr->val;
				InsLast(M);
			}
		}
		void AddMonom(const TMonom& m)
		{
			for (Reset(); !IsEnd(); GoNext())
			{
				if (pCurr->val == m)
				{
					pCurr->val.coef += m.coef;

					if (pCurr->val.coef == 0)
					{
						DelCurr();
					}
					break;
				}
				else
				{
					if (pCurr->val < m)
					{
						InsCurr(m);
						break;
					}
				}
			}
				if (IsEnd())InsLast(m);
		}
		TPolinom operator* (double a)
		{
			for (Reset(); !IsEnd(); GoNext())
			{
				pCurr->val.coef *= a;

			}
			return *this;
		}
		TPolinom operator * (TMonom m)
		{
			for (Reset(); !IsEnd(); GoNext())
			{
				pCurr->val.coef *= m.coef;
				pCurr->val.px += m.px;
				pCurr->val.py += m.py;
				pCurr->val.pz += m.pz;
			}
			return *this;
		}
		friend ostream& operator<<(ostream& os,  TPolinom& a)
		{
		
				for (a.Reset(); !a.IsEnd(); a.GoNext())
				{
					os << a.pCurr->val;
				}
			
			return os;
		}
		friend istream& operator>>(istream& is,  TPolinom& a)
		{
			if (a.pCurr == NULL) {
				int n;
				cout << "enter lenght: ";
				cin >> n;
				TMonom pm;
				for (int i = 0; i < n; i++)
				{
					is>> pm;
					a.AddMonom(pm);
				}
			}
			else {
				for (a.Reset(); !a.IsEnd(); a.GoNext())
				{
					is >> a.pCurr->val;
				}
			}
			a.Reset();
			return is;
		}
		void operator +=(TPolinom& a)
		{
			TMonom pm, qm, rm;
			Reset();
			a.Reset();
			while (!a.IsEnd())
			{
				pm = pCurr->val;
				qm = a.pCurr->val;
				if (pm > qm)GoNext();
				else 
					if (pm < qm)
					{
						InsCurr(qm);
						a.GoNext();
					}
				else
				{
					rm = pm;
					rm.coef += qm.coef;
					if (rm.coef == 0)
					{
						DelCurr();
						a.GoNext();
					}
					else
					{
						pCurr->val = rm;
						a.GoNext();
					}
				}
			}
		}
		
};