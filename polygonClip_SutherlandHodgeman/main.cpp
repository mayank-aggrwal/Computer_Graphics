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

    // EDGE AB
    int cnt = q.size();
    q.push(p1);
    point curr1 = q.front(), curr2;
    q.pop();
    while(cnt--) {
        curr2 = q.front();q.pop();
        helper(curr1, curr2, q, a, b);
        curr1 = curr2;
    }

    // EDGE BC
    cnt = q.size();
    q.push(q.front());
    curr1 = q.front();
    q.pop();
    while(cnt--) {
        curr2 = q.front();q.pop();
        helper(curr1, curr2, q, b, c);
        curr1 = curr2;
    }

    // EDGE CA
    cnt = q.size();
    q.push(q.front());
    curr1 = q.front();
    q.pop();
    while(cnt--) {
        curr2 = q.front();q.pop();
        helper(curr1, curr2, q, c, a);
        curr1 = curr2;
    }

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

