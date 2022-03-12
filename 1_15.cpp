#include <iostream>
using namespace std;

/*Опишите функцию set_min, которая принимает два параметра — переменные типа int,
определяет в какой из двух переменных значение меньше, и заносит это значение в обе переменные.
Вызов функции будет выполняться с указанием параметров — имен переменных без каких-либо
дополнительных операций (взятие адреса и т. п.)*/

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
