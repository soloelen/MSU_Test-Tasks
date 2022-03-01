#include <iostream>
using namespace std;


class RealFunction
{
	double f0;
public:
	RealFunction(double x): f0(x) {}
	virtual double FuncComp(double x) = 0;
	double operator () (double x) {return FuncComp(x) + f0;}
};


class Linear: public RealFunction
{
	double a;
public:
	Linear(double aa, double bb): RealFunction(bb), a(aa) {}
	virtual double FuncComp(double x) {return a * x;}
	
};

int main()
{
	Linear l(1.5, 2.3);
	
	cout << l(1.0) << endl;
	
	return 0;
}
