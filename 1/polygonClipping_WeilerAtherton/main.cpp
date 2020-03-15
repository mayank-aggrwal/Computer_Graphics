#include <iostream>
#include <graphics.h>
#include <vector>

using namespace std;

class point {
public:
    int x, y;
    point() {
        x = 0;
        y = 0;
    }
    point(int a, int b) {
        x = a;
        y = b;
    }
} a, b, c;

class bigPoint {
public:
    point p;
    int label;
    bigPoint(point p, int a) {
        this -> p = p;
        label = a;
    }
};

void makeWindow() {
}
int main(){
    initwindow(600, 600);
    makeWindow();

    point p1(), p2(), p3();

    vector<bigPoint> subPoly, clipPoly;



    getch();
    return 0;
}
