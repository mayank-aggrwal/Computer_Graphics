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

int forEAB(point p) {
    return ((a.y-b.y)*p.x + (b.x-a.x)*p.y + a.x*(b.y-a.y) - a.y*(b.x-a.x));
}
int forEBC(point p) {
    return ((b.y-c.y)*p.x + (c.x-b.x)*p.y + b.x*(c.y-b.y) - b.y*(c.x-b.x));
}
int forECD(point p) {
    return ((c.y-d.y)*p.x + (d.x-c.x)*p.y + c.x*(d.y-c.y) - c.y*(d.x-c.x));
}
int forEDA(point p) {
    return ((d.y-a.y)*p.x + (a.x-d.x)*p.y + d.x*(a.y-d.y) - d.y*(a.x-d.x));
}

int genCode(point p) {
    int code = 0;
    if(forEAB(p) > 0) {
        code |= edgeAB;
    }
    if(forEBC(p) > 0) {
        code |= edgeBC;
    }
    if(forECD(p) > 0) {
        code |= edgeCD;
    }
    if(forEDA(p) > 0) {
        code |= edgeDA;
    }
    return code;
}


void clipLine() {

    int codep1 = genCode(p1);
    int codep2 = genCode(p2);
    cout << 1 << endl;

    // TOTALLY VISIBLE LINE
    if(codep1 == 0 && codep2 == 0) {
        line(p1.x,p1.y,p2.x,p2.y);
        return ;
    }

    // TOTALLY INVISIBLE LINE
    else if((codep1 & codep2) != 0) {
        return ;
    }
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
