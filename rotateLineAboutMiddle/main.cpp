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

int main() {

    initwindow(600, 600);
    p1.x = 150;p1.y = 300;
    p2.x = 450;p2.y = 300;

    rotateLine();

    getch();
    return 0;
}
