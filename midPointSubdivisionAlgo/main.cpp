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
