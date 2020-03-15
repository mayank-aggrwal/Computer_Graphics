#include <iostream>
#include <graphics.h>
#include <math.h>
#include <vector>

using namespace std;
#define PI 3.14159265

class point {
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
} a, b, c, d, e;

vector<point> v;

class edge {
public:
    int ymax, x;
    float slope;
    edge(int a, int b, float c) {
        ymax = a;
        x = b;
        slope = c;
    }
};

class GETnode {
public:
    int y;
    edge *next;
    GETnode(int y) {
        this -> y = y;
        next = NULL;
    }
};

vector<point> sortVertices() {
}

GETnode **head;

vector<point> getConnectedPoints(int y) {
}

bool visited(point p1, point p2) {
}

void scanLinePolyFill() {

    vector<point> sortedPoints = sortVertices();
    int totalPoints = sortedPoints.size();

    int ymin = sortedPoints[0].y, ymax = sortedPoints[totalPoints-1].y;
    head = new GETnode*[ymax-ymin+1];
    for(int i=ymin; i<=ymax; i++) {
        head[i] = new GETnode(i);
    }

    for(int i=0; i<totalPoints; i++) {
        int index = sortedPoints[i].y;
        // add Connected Edges
        vector<point> cp = getConnectedPoints(sortedPoints[i].y);
        for(int j=0; j<cp.size(); j++) {
            if(!visited(sortedPoints[i], cp[i])) {
                float m = (cp[i].y - sortedPoints[i].y)/(cp[i].x - sortedPoints[i].x);
                head[index].next = new edge(cp[i].y, sortedPoints[i].x, 1.0/m);
            }
        }
    }

    // TRAVERSE GET

}


int main() {

    initwindow(600, 600);
    a.x = 5;a.y = 1;v.push_back(a);
    b.x = 12;b.y = 4;v.push_back(b);
    c.x = 9;c.y = 9;v.push_back(c);
    d.x = 6;d.y = 8;v.push_back(d);
    e.x = 3;e.y = 6;v.push_back(e);

    scanLinePolyFill();

    getch();
    return 0;
}
