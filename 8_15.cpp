#include <iostream>
using namespace std;


class ListEmpty{};


class IntQueue
{
	struct list
	{
		int data;
		struct list *next;
	};
	int count;
	struct list *first, *last;
public:
	IntQueue(): count(0), first(NULL), last(NULL) {}
	int operator <<= (int x);
	int operator >>= (int &k);
	int Amount() {return count;}
	virtual bool Check(int u) {return true;}
};


int IntQueue:: operator <<=(int x)
{
	if (Check(x)) {
		struct list *tmp = new struct list;
		tmp->data = x;
		count++;
		if (first == NULL) {
			first = tmp;
			first->next = NULL;
			last = first;
			cout << "first = " << first->data << endl;
		} else {
			last->next = tmp;
			last = tmp;
			cout << "last = " << last->data << endl;
		}
	}
	return 1;
}

int IntQueue:: operator >>=(int &k)
{
	if (first == NULL) {throw ListEmpty();}
	struct list *p = first;
	int d = p->data;
	if (first->next != NULL) {
		first = first->next;
	}
	delete p;
	count--;
	//u = d;
	k = d;
	return k;
	
}


class EvenFIlter: public IntQueue
{
public:
	virtual bool Check(int x) {
		if (x % 2 != 0) {return false;}
		//cout << "true here\n";
		return true;
	}
	
	
};


int main()
{
	EvenFIlter a;
	
	a <<= 3;
	a <<= 10;
	a <<= 6;
	int k = 0;
	//int n;
	//a>>=n
	cout << (a>>=k) << " " << (a>>=k) << endl;
	cout << a.Amount() << endl;
	
	
	
	return 0;
}

