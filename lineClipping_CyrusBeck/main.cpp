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

point findPointFromT(float t) {
    int x = p1.x + (p2.x - p1.x)*t;
    int y = p1.y + (p2.y - p1.y)*t;
    point ans(round(x), round(y));
    return ans;
}

void clipLine() {

    formEdgeVectors();
    printE();
    formNormalVectors();
    printN();

    float minT = 1, maxT = 0;
    float t = -1;
    // FOR EDGE AB
    int den = dotProd(normalAB, p2, p1);
    int num = dotProd(normalAB, p1, a);
    t = (1.0*num)/(-1*den);
    cout << "AB t:" << t << endl;
    if(t>=0 && t<=1) {
        if(den > 0) {
            if(minT > t) {
                minT = t;
            }
        }
        else {
            if(maxT < t) {
                maxT = t;
            }
        }
    }

    // FOR EDGE BC
    den = dotProd(normalBC, p2, p1);
    num = dotProd(normalBC, p1, b);
    t = (1.0*num)/(-1*den);
    cout << "BC t:" << t << endl;
    if(t>=0 && t<=1) {
        if(den > 0) {
            if(minT > t) {
                minT = t;
            }
        }
        else {
            if(maxT < t) {
                maxT = t;
            }
        }
    }

    // FOR EDGE CA
    den = dotProd(normalCA, p2, p1);
    num = dotProd(normalCA, p1, c);
    t = (1.0*num)/(-1*den);
    cout << "CA t:" << t << endl;
    if(t>=0 && t<=1) {
        if(den > 0) {
            if(minT > t) {
                minT = t;
            }
        }
        else {
            if(maxT < t) {
                maxT = t;
            }
        }
    }

    cout << "maxt:" << maxT << " mint:" << minT << endl;
    point tmp = findPointFromT(maxT);
    p2 = findPointFromT(minT);
    p1 = tmp;

    setcolor(YELLOW);
    line(p1.x, p1.y, p2.x, p2.y);


}

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
