#include <iostream>
#include <graphics.h>


using namespace std;

void LineBresenham(int x1, int y1, int x2, int y2) {

    if(x1 > x2) {
        swap(x1, x2);
        swap(y1, y2);
    }

    float dy = y2 - y1, dx = x2 - x1;
    float m = dy/dx;

    if(m >= 1) {
        int xp = x1, yp = y1;
        int d = 2*(y2-y1)*xp-2*(x2-x1)*yp+2*(x2-x1)*c+(y2-y1)-2*(x2-x1);
        while(yp < y2) {
            putpixel(xp, yp, WHITE);

        }
    }
    else if(m>0 && m < 1) {

    }
    else if(m < -1) {

    }
    else {

    }

}

int main()
{
    initwindow(600,500);

    LineBresenham(20,20,50,75);

    getch();
    return 0;
}
// putpixel()
