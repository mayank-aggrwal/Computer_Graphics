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

void makeWindow() {
    a.x = 40;a.y = 200;
    b.x = 300;b.y = 240;
    c.x = 140;c.y = 40;
}

// FIND INTERSECTION POINTS OF THE LINES GIVEN BY TWO CONSECUTIVE POINTS
point findIntersection(point c, point d, point a, point b) {
    int a1 = c.y-d.y, b1 = d.x-c.x, c1 = c.x*(d.y-c.y)-c.y*(d.x-c.x);
    int a2 = a.y-b.y, b2 = b.x-a.x, c2 = a.x*(b.y-a.y)-a.y*(b.x-a.x);

    float x = (1.0*(b1*c2 - b2*c1))/(a1*b2 - a2*b1);
    float y = (1.0*(c1*a2 - a1*c2))/(a1*b2 - a2*b1);

    //cout << "Inside Intersection " << cnt << ": p.x: " << x << " p.y: " << y << endl;


    point ans(round(x),round(y));
    //cout << "Inside Intersection after roundoff " << cnt << ": p.x: " << ans.x << " p.y: " << ans.y << endl;
    return ans;
}

// CHECKING FOR I->O, O->I, O->O, I->I CASES
void helper(point curr1, point curr2, queue<point> &q, point a, point b) {
    int d1 = curr1.x*(a.y-b.y)+curr1.y*(b.x-a.x)+a.x*(b.y-a.y)-a.y*(b.x-a.x);
    int d2 = curr2.x*(a.y-b.y)+curr2.y*(b.x-a.x)+a.x*(b.y-a.y)-a.y*(b.x-a.x);
    // I->I
    if(d1 < 0 && d2 < 0) {
        q.push(curr2);
    }
    // I->O
    else if(d1 < 0 && d2 > 0) {
        point tmp = findIntersection(curr1,curr2,a,b);
        q.push(tmp);
    }
    // O->I
    else if(d1 > 0 && d2 < 0) {
        point tmp = findIntersection(curr1,curr2,a,b);
        q.push(tmp);
        q.push(curr2);
    }

}

void clipPolygon() {

    queue<point> q;
    q.push(p1);
    q.push(p2);
    q.push(p3);

    // CLIPPING ALONG EDGE AB
    int cnt = q.size();
    q.push(p1);
    point curr1 = q.front(), curr2;
    q.pop();
    while(cnt--) {
        curr2 = q.front();q.pop();
        helper(curr1, curr2, q, a, b);
        curr1 = curr2;
    }

    // CLIPPING ALONG EDGE BC
    cnt = q.size();
    q.push(q.front());
    curr1 = q.front();
    q.pop();
    while(cnt--) {
        curr2 = q.front();q.pop();
        helper(curr1, curr2, q, b, c);
        curr1 = curr2;
    }

    // CLIPPING ALONG EDGE CA
    cnt = q.size();
    q.push(q.front());
    curr1 = q.front();
    q.pop();
    while(cnt--) {
        curr2 = q.front();q.pop();
        helper(curr1, curr2, q, c, a);
        curr1 = curr2;
    }

    // DRAW THE CLIPPED POLYGON USING THE VERTICES
    q.push(q.front());
    curr1 = q.front();
    q.pop();
    while(!q.empty()) {
        curr2 = q.front();q.pop();
        setcolor(YELLOW);
        line(curr1.x, curr1.y, curr2.x,  curr2.y);
        curr1 = curr2;
    }

}

// MAIN DRIVER FUNCTION
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

    // CLIP THE POLYGON USING THIS FUNCTION
    clipPolygon();
    getch();
    return 0;
}

