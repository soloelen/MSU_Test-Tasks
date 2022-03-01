#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
using namespace std;


class BadAddition 
{
    public:
        int x, y, p, q;
        BadAddition(int x1, int y1, int x2, int y2) {x = x1; y = y1; p = x2; q = y2;}
        const int GetX1() const {return x;};
        const int GetY1() const {return y;};
        const int GetX2() const {return p;};
        const int GetY2() const {return q;};
};


class BadSegment {}; 



class IntPair
{
    int x, y;
    public:
        void setter(int x1, int y1) {x = x1; y = y1;};
        int getterX() {return x;}
        int getterY() {return y;}
        IntPair(int x1, int y1) {x = x1; y = y1;};
        IntPair() {x = 0; y = 0;}
        virtual int Measure() = 0;
        virtual ~IntPair() {};
};


class IntRectangle  : public IntPair
{
    public:
        IntRectangle() : IntPair(){}
        IntRectangle(int x1, int y1) : IntPair(x1,y1) {}
        virtual int Measure() {return (getterX() * getterY());}    
};


IntRectangle operator + (IntRectangle f1, IntRectangle f2)
{
    int finalX = 0, finalY = 0;
    if (((f1.getterX() == f2.getterX()) && (f1.getterY() == f2.getterY())) || ((f1.getterX() == f2.getterY()) && (f1.getterY() == f2.getterX()))) {
        if (f1.getterX() > f1.getterY()) {
            finalY = f1.getterY() + f1.getterY();
            finalX = f1.getterX();
        }
        else {
            finalX = f1.getterX() + f1.getterX();
            finalY = f1.getterY();
        }
    }
    else if (f1.getterX() == f2.getterX()) {
        finalY = f1.getterY() +  f2.getterY();
        finalX = f1.getterX();
    }
    else if (f1.getterY() == f2.getterY()) {
        finalX = f1.getterX() + f2.getterX();
        finalY = f1.getterY();
    }
    else if (f1.getterX() == f2.getterY()) {
        finalY = f1.getterY() + f2.getterX();
        finalX = f1.getterX();
    }
    else if (f2.getterX() == f1.getterY()) {
        finalX = f1.getterX() + f2.getterY();
        finalY = f1.getterY();
    }
    
    else {
        throw BadAddition(f1.getterX(), f1.getterY(), f2.getterX(), f2.getterY());
    }
    IntRectangle returnval(finalX, finalY);
    //cout << finalX << "    " << finalY << "\n";
    return returnval;

}


int main()
{
    try {
        IntRectangle a(3, 5), b(5, 7), c(11, 4), d(6, 11);
        IntRectangle p, q;
        p = a + b;
        //cout << "p -- " << p.getterX() << "   " << p.getterY() << "\n";
        //cout << "p.measure -- " << p.Measure() << "\n";

        q = c + d;
        printf("%d\n", (p + q).Measure());
        printf("%d\n", (q + a).Measure());
    }
    catch(const BadAddition &bad) {
        printf("Bad addition: (%dx%d)+(%dx%d)\n",
            bad.GetX1(), bad.GetY1(), bad.GetX2(), bad.GetY2());
    }
    return 0;

}