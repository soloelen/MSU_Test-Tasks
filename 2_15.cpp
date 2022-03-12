#include <iostream>
using namespace std;

/*Опишите класс Flag, объект которого может находиться в одном из двух состояний —
«взведен» (on) и «сброшен» (off). Предусмотрите методы SetOn и SetOff, устанавливающие
флаг в соответствующее положение, а также метод IsOn, возвращающий логическое значение
(истина, если объект находится в состоянии «взведен», ложь в противном случае),
который должен допускать работу для константных объектов.*/

class Flag
{
	bool fl;
public:
	Flag(): fl(0) {}
	void SetOn() {fl = true;}
	void SetOff() {fl = false;}
	bool IsOn() const {return fl;}
};

int main()
{
	Flag f;
	f.SetOn();
	cout << f.IsOn() << "\n";
	f.SetOff();
	cout << f.IsOn() << "\n";
	f.SetOff();
	cout << f.IsOn() << "\n";
	
	return 0;
}
