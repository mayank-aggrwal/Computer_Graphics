#include <iostream>
#include <graphics.h>

using namespace std;

void drawParabola(int x1, int y1) {
    int xoff = 200, yoff = 300;
    putpixel(x1+xoff, y1+yoff, WHITE);
    putpixel(x1+xoff, -y1+yoff, WHITE);
}

void printParabola(int a) {

    int xp = 0, yp = 0;
    float p = 4*a-2;
    while(yp >= -2*a) {
        drawParabola(xp, yp);
        if(p>0) {
            p += -6+4*yp;
        }
        else{
            xp++;
            p += -6+4*yp+8*a;
        }
        yp--;
    }

    p = 2*yp*yp-2*yp-8*a*xp-8*a+1;
    while(xp<=300) {
        drawParabola(xp, yp);
        if(p>0) {
            p += -8*a;
        }
        else {
            yp--;
            p += -8*a+4-4*yp;
        }
        xp++;
    }

}

int main()
{
    initwindow(600, 600);
    printParabola(20);
    getch();
    return 0;
}
