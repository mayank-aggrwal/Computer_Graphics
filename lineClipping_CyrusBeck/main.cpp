#include <iostream>
#include <math.h>
#include <graphics.h>
using namespace std;

class point{
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
} a, b, c, p1, p2;

class complexx{
    public:
    int r;
    int c;
    complexx() {
        r = 0;
        c = 0;
    }
    complexx(int a, int b) {
        r = a;
        c = b;
    }
} AB, BC, CA, normalAB, normalBC, normalCA;



int main()
{
    initwindow(600, 600);

    makeWindow();

    // LINE END POINTS
    p1.x = 60;p1.y = 280;
    p2.x = 100;p2.y = 40;

    //line(p1.x,p1.y,p2.x,p2.y);
    line(a.x,a.y,b.x,b.y);
    line(b.x,b.y,c.x,c.y);
    line(c.x,c.y,a.x,a.y);

    clipLine();

    getch();
    return 0;
}
