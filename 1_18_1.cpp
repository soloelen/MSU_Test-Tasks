#include <iostream>
using namespace std;


class Assign
{
	int keeper;
	int *adr;
public:
	Assign &operator [](int &x) {adr = &x; return *this;}
	Assign &operator () (int y) {
		keeper = y;
		*adr = y;
		return *this;
	}
	int Get() {return keeper;}
};


int main()
{
	Assign a;
	int x = 3;
	int y = 5;
	a[x](y);
	cout << x << endl;
	
	cout << a.Get() << endl;
}
