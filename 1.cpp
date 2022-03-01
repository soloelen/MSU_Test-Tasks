#include <iostream>
using namespace std;


class A
{
	int x;
public:
	A(): x(5) {}
	friend int operator +(A a, A b);
	friend ostream &operator <<(ostream &out, const A &b);
	int operator *(A b) {return x*b.x;}
	int operator *(int c) {return x*c;}
	friend int operator *(int y, A b);
};


ostream &operator <<(ostream &out, const A &b)
{
	out << b.x << endl;
	return out;
}


int operator +(A a, A b) {return a.x+b.x;}

int operator *(int y, A b) {return y+b.x;}

int main()
{
	A a, b;
	
	cout << a << endl;
	cout << a*10 << endl;
	cout << 100*a << endl;
	return 0;
}
