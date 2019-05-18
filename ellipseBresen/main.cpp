#include <iostream>
#include <graphics.h>

using namespace std;

void drawPixel(int x, int y) {

    int xoff = 300, yoff = 300;
    putpixel(x+xoff, y+yoff, WHITE);
    putpixel(-x+xoff, y+yoff, WHITE);
    putpixel(x+xoff, -y+yoff, WHITE);
    putpixel(-x+xoff, -y+yoff, WHITE);

}

void drawEllipse(int a, int b) {

    int xp = 0, yp = b;
    float p = 2*a*a*b-a*a-2*b*b;
    while(b*b*xp <= a*a*yp) {
        drawPixel(xp, yp);
        if(p > 0) {
            p += -6*b*b-4*b*b*xp;
        }
        else {
            p += -6*b*b-4*b*b*xp-4*a*a+4*a*a*yp;
            yp--;
        }
        xp++;
    }

    xp = a;
    yp = 0;
    p = -2*b*b*a+b*b+2*a*a;
    while(b*b*xp > a*a*yp) {
        drawPixel(xp, yp);
        if(p > 0) {
            xp--;
            p += 4*b*b-4*b*b*xp+6*a*a+4*a*a*yp;
        }
        else{
            p += 6*a*a+4*a*a*yp;
        }
        yp++;
    }

}

int main()
{
    initwindow(600,600);
    int a = 250, b = 100;
    drawEllipse(a, b);
    getch();
    return 0;
}
