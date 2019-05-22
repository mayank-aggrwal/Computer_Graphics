#include <iostream>
#include <graphics.h>
#include <math.h>

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
} p1, p2;

void rotateLine() {
    int midx = (p1.x+p2.x)/2;
    int midy = (p1.y+p2.y)/2;
    float i = 3;
    while(1) {
        p1 = rotByI(p1,i,midx,midy);
        p2 = rotByI(p2,i,midx,midy);
        cleardevice();
        line(p1.x,p1.y,p2.x,p2.y);
        delay(1);

    }

}

int main() {

    initwindow(600, 600);
    p1.x = 150;p1.y = 300;
    p2.x = 450;p2.y = 300;

    rotateLine();

    getch();
    return 0;
}
