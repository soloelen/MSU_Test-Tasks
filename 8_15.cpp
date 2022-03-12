#include <iostream>
using namespace std;

/*
Опишите класс IntQueue, представляющий понятие «очереди целых чисел», реализованный 
через односвязный список с указателями на начало и конец (возможности стандартной 
бибилиотеки C++ не использовать!). Предусмотрите операции <<= (левый операнд — 
объект вашего класса, правый — целочисленное выражение, операция добавляет элемент 
в конец очереди) и >>= (правый операнд — переменная типа int, операция извлекает элемент
из начала очереди; если извлекать нечего, то бросьте исключение класса  QueueEmpty, 
который опишите сами). Предусмотрите метод Amount, возвращающий текущее количество 
элементов в очереди. Вся выделенная динамическая память должна быть корректно освобождена — 
память от извлекаемых элементов освобождается при их извлечении, память от всего 
остального освобождается при уничтожении объекта очереди.

Модифицируйте класс IntQueue, снабдив его виртуальной функцией Check, принимающей параметр
типа int и возвращающей логическое значение; функция должна допускать работу для константных 
объектов. В классе IntQueue функция Check должна всегда возвращать «истину», но предполагается, 
что классы-наследники могут заменить эту функцию свое версией. При добавлении нового числа в 
очередь это число должно проверяться вызовом функции Check, и если функция вернула истину, 
то число должно помещаться в очередь, в противном случае — игнорироваться. Унаследуйте от класса 
IntQueue класс EvenFilter, принимающий для помещения в очередь только четные числа. Этот класс 
должен отличаться от базового только функцией Check. Учтите, что в ходе тестирования от этих 
классов будут наследоваться также другие потомки.
*/

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

