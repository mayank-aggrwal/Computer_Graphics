#include <iostream>
#include <graphics.h>
#include <queue>
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
} a, b, c, p1,p2,p3;


int main()
{
    initwindow(600, 600);
    makeWindow();

    p1.x = 40;p1.y = 40;
    p2.x = 160;p2.y = 280;
    p3.x = 280;p3.y = 120;

    line(p1.x,p1.y,p2.x,p2.y);
    line(p2.x,p2.y,p3.x,p3.y);
    line(p3.x,p3.y,p1.x,p1.y);

    line(a.x,a.y,b.x,b.y);
    line(b.x,b.y,c.x,c.y);
    line(c.x,c.y,a.x,a.y);

    clipPolygon();
    getch();
    return 0;
}

