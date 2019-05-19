#include <iostream>
#include <graphics.h>
#include <math.h>

using namespace std;
#define edgeAB 0x1
#define edgeBC 0x2
#define edgeCA 0x4

class point{
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
} a, b, c, p1, p2;
// HERE a,b,c ARE THE VERTICES OF CLIPPING POLYGON, p1,p2 ARE TWO END POINTS OF LINE 
// TO BE CLIPPED

// FUNCTION TO INITIALISE THE CLIPPING WINDOW
void makeWindow() {
    a.x = 40;a.y = 40;
    b.x = 360;b.y = 280;
    c.x = 280;c.y = 120;
    line(a.x, a.y, b.x, b.y);
    line(b.x, b.y, c.x, c.y);
    line(c.x, c.y, a.x, a.y);
}

// FUNCTION TO GENERATE CODE FOR A POINT
int genCode(point p) {

    int code = 0;
    int d = p.y*(b.x-a.x) - p.x*(b.y-a.y) + a.x*(b.y-a.y) - a.y*(b.x-a.x);
    int e = p.y*(c.x-b.x) - p.x*(c.y-b.y) + b.x*(c.y-b.y) - b.y*(c.x-b.x);
    int f = p.y*(a.x-c.x) - p.x*(a.y-c.y) + c.x*(a.y-c.y) - c.y*(a.x-c.x);

    // IF POINT P LIES OUTSIDE OF EDGE AB OF CLIPPING POLYGON, THEN ADD THIS INFO. TO CODE
    if(d > 0) {
        code |= edgeAB;
    }

    // IF POINT P LIES OUTSIDE OF EDGE BC OF CLIPPING POLYGON, THEN ADD THIS INFO. TO CODE
    if(e > 0) {
        code |= edgeBC;
    }

    // IF POINT P LIES OUTSIDE OF EDGE CA OF CLIPPING POLYGON, THEN ADD THIS INFO. TO CODE
    if(f > 0) {
        code |= edgeCA;
    }
    return code;
}

int cnt = 0;

// FUNCTION TO RETURN INTERSECTION POINT OF TWO GIVEN LINES
point intersection(point &pm, point &pn) {
    cnt++;
    int a1 = pm.y-pn.y, b1 = pn.x-pm.x, c1 = pm.x*(pn.y-pm.y)-pm.y*(pn.x-pm.x);
    int a2 = p1.y-p2.y, b2 = p2.x-p1.x, c2 = p1.x*(p2.y-p1.y)-p1.y*(p2.x-p1.x);

    float x = (1.0*(b1*c2 - b2*c1))/(a1*b2 - a2*b1);
    float y = (1.0*(c1*a2 - a1*c2))/(a1*b2 - a2*b1);

    //cout << "Inside Intersection " << cnt << ": p.x: " << x << " p.y: " << y << endl;

    point ans(round(x),round(y));
    //cout << "Inside Intersection after roundoff " << cnt << ": p.x: " << ans.x << " p.y: " << ans.y << endl;
    return ans;
}

// FUNCTION TO CLIP LINE WHEN SOME PART IS OUTSIDE AND SOME INSIDE
void clipLine(int codep1, int codep2) {

    if((codep1 & edgeAB) != 0) {
        //cout << p1.x << " p1.y: " << p1.y << endl;
        p1 = intersection(a,b);
        //cout << p1.x << " p1.y: " << p1.y << endl;
    }
    if((codep1 & edgeBC) != 0) {
        p1 = intersection(b,c);
    }
    if((codep1 & edgeCA) != 0) {
        p1 = intersection(c,a);
    }
    if((codep2 & edgeAB) != 0) {
        p2 = intersection(a,b);
    }
    if((codep2 & edgeBC) != 0) {
        cout << p2.x << " p2.y: " << p2.y << endl;
        p2 = intersection(b,c);
        cout << p2.x << " p2.y: " << p2.y << endl;
    }
    if((codep2 & edgeCA) != 0) {
        p2 = intersection(c,a);
    }


}

// FUNCTION TO CHECK THE POSITION OF LINE , WHETHER VISIBLE OR NOT
void lineClipping() {
        int codep1 = genCode(p1);
        int codep2 = genCode(p2);
        if(((codep1 & codep2) == 0) && ((codep1 | codep2) == 0)) {
            setcolor(RED);
            line(p1.x, p1.y, p2.x, p2.y);
            break;
        }
        else if(((codep1 & codep2) == 0) && ((codep1 | codep2) != 0)) {
            clipLine(codep1,codep2);
            setcolor(RED);
            line(p1.x, p1.y, p2.x, p2.y);
            break;
        }
        else if((codep1 & codep2) != 0) {
        }
}

// MAIN DRIVER FUNCTION
int main()
{
    // INITIALISE THE GRAPHICS WINDOW
    initwindow(600, 600);

    // CLIPPING WINDOW
    makeWindow();

    //point p1(40,160);
    p1.x = 40;p1.y = 160;
    //point p2(470,240);
    p2.x = 470;p2.y = 240;
    //p2.x = 360;p2.y = 260;
    //point p1(140,90);
    //point p2(320,240);
    //setcolor(YELLOW);

    // LINE TO BE CLIPPED
    line(p1.x, p1.y, p2.x, p2.y);

    lineClipping();

    getch();
    return 0;
}

