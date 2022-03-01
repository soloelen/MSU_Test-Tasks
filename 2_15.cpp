#include <iostream>
using namespace std;


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
