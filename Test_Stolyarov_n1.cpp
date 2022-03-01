#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

class FloatPair
{
    float x, y;
    public:
        void setter(float x1, float y1) {x = x1; y = y1;}
        float getterX() {return x;}
        float getterY() {return y;}
        FloatPair(float x1, float y1) {x = x1; y = y1;} 
        virtual ~FloatPair() {} 
        virtual float Measure() = 0;
};



class BadAddition 
{
    float x, y, p, q;
    public:

        BadAddition(float x1, float y1, float x2, float y2) {x = x1; y = y1; p = x2; q = y2;}
        const float GetA1() const {return x;};
        const float GetB1() const {return y;};
        const float GetA2() const {return p;};
        const float GetB2() const {return q;};
};



class BadSegment {}; 


class Segment : public FloatPair
{
    public:
        Segment(float x1, float y1) : FloatPair(x1,y1) {if (y1 < x1) throw BadSegment();}
        virtual float Measure() {return (getterY() - getterX());}
};


Segment operator + (Segment f1, Segment f2)
{
    float finalX, finalY;
    if (((f2.getterX() <= f1.getterY()) && (f2.getterX() >= f1.getterX())) || ((f1.getterX() <= f2.getterY()) && (f1.getterX() >= f2.getterX()))) {
        if (f1.getterX() > f2.getterX()) {
            finalX = f2.getterX();
        }
        if (f1.getterY() < f2.getterY()) {
            finalY = f2.getterY();
        }
    } else {
        throw BadAddition(f1.getterX(), f1.getterY(), f2.getterX(), f2.getterY());
    }
    Segment returnval(finalX, finalY);
    return returnval;
}




int main() {
    try {
        Segment f(1, 2), g(0.5, 5), h(2.5, 6.5);
        printf("%3.3f, %3.3f, %3.3f\n",
            (f+g).Measure(), (g+h).Measure(), (f+g+h).Measure());
        printf("%3.3f\n", (f+h).Measure());
    }
    catch(const BadAddition &bad) {
        printf("Bad addition: [%3.3f; %3.3f] + [%3.3f; %3.3f]\n",
            bad.GetA1(), bad.GetB1(), bad.GetA2(), bad.GetB2());
    }
    catch(BadSegment b) {
        printf("Bad segment\n");}
    return 0;
}

