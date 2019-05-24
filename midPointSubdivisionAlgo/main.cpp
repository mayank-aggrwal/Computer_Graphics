#include <iostream>
#include <graphics.h>
#include <math.h>

using namespace std;

#define edgeAB 0x1
#define edgeBC 0x2
#define edgeCD 0x4
#define edgeDA 0x8

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
} a, b, c, d, p1, p2;

int sc = 40;

void makeWindow() {
    a.x = 5*sc;a.y = 0*sc;
    b.x = 3*sc;b.y = 2*sc;
    c.x = 5*sc;c.y = 6*sc;
    d.x = 7*sc;d.y = 4*sc;
    line(a.x,a.y,b.x,b.y);
    line(b.x,b.y,c.x,c.y);
    line(c.x,c.y,d.x,d.y);
    line(d.x,d.y,a.x,a.y);
}

int main()
{
    initwindow(600, 600);
    makeWindow();

    p1.x = 2*sc;p1.y = 4*sc;
    //p2.x = 8*sc;p2.y = 7*sc;
    p2.x = 7*sc;p2.y = 3*sc;

    //line(p1.x,p1.y,p2.x,p2.y);
    clipLine();

    getch();
    return 0;
}
