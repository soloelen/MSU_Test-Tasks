#include <iostream>
using namespace std;


class B;


class A
{
public:
	A() {}
	int operator [](B const &b) {return 75;}
	int operator ()() {return 50;}
	int operator ()(B const & b) {return 100;}
	int operator ()(B const &a, B const &b) {return 150;}
	void operator ()(A const &a, A const &b, A const & c) {throw A();}
	int operator --(int a) {return 501;}
	int operator --() {return 500;}
};


class B
{
public:
	B() {}
	int operator [](A const &a) {return 75;}
	int operator ()(A const &a) {return 200;}

};


int main()
{
	try{
		A a;
		B b;
		cout << "ok\n";
		cout << a[b] << "   " << b[a] << endl;
		cout << "ok\n";
		cout << a() << "   " << a(b) << endl;
		cout << "ok\n";
		cout << a(b, b) << "   " << b(a) << endl;
		cout << "ok\n";
		cout << --a << "   " << a-- << endl;
		a(a, a, a);
		cout << "ok\n";
	}
	catch (A) {cout << "error\n";}
	return 0;
}
