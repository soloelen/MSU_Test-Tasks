#include <iostream>
using namespace std;


void setmin(int &x, int &y)
{
	if (x < y)
		y = x;
	else
		x = y;
}


int main()
{
	int x = 30, y = 15;
	setmin(x, y);
	cout << x << "\n" << y << "\n";
	return 0;
}
