#include <iostream>
#include <graphics.h>
#include <math.h>

using namespace std;

class point {
    public:
    int x;
    int y;
    point() {
        x = 0;
        y = 0;
    }
    point(int a, int b) {
        x = a;
        y = b;
    }
} p1, p2, p3, p4;

point findPointAtT(float t) {
    point p;
    p.x = (1-t)*(1-t)*(1-t)*p1.x + 3*t*(1-t)*(1-t)*p2.x + 3*t*t*(1-t)*p3.x + t*t*t*p4.x;
    p.y = (1-t)*(1-t)*(1-t)*p1.y + 3*t*(1-t)*(1-t)*p2.y + 3*t*t*(1-t)*p3.y + t*t*t*p4.y;
    return p;
}

void makeBezierCurve() {
    float t;
    for(t=0; t<1; t+=0.001) {
        point p = findPointAtT(t);
        putpixel(p.x,p.y,WHITE);
    }
}

int main() {

    initwindow(600, 600);
    int sc = 40;
    p1.x = 2*sc;p1.y = 3*sc;
    p2.x = 3*sc;p2.y = 10*sc;
    p3.x = 7*sc;p3.y = 11*sc;
    p4.x = 8*sc;p4.y = 1*sc;

    /*putpixel(p1.x,p1.y,GREEN);
    putpixel(p2.x,p2.y,GREEN);
    putpixel(p3.x,p3.y,GREEN);
    putpixel(p4.x,p4.y,GREEN);*/

    setcolor(YELLOW);
    circle(p1.x,p1.y,5);
    circle(p2.x,p2.y,5);
    circle(p3.x,p3.y,5);
    circle(p4.x,p4.y,5);
    makeBezierCurve();

    getch();
    return 0;
}
