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

void drawHyperbola(int a, int b) {

    int xp = a, yp = 0;
    float p = b*b-2*a*a+2*b*b*a;
    while(b*b*xp >= a*a*yp) {
        drawPixel(xp, yp);
        if(p > 0) {
            p += -6*a*a-4*a*a*yp;
        }
        else {
            p += -6*a*a-4*a*a*yp+4*b*b+4*b*b*xp;
            xp++;
        }
        yp++;
    }

    p = 2*a*a*yp*yp+a*a+2*a*a*yp+2*a*a*b*b-2*b*b*xp*xp-2*b*b-4*b*b*xp;
    while(xp <= 60) {
        drawPixel(xp, yp);
        if(p > 0) {
            xp--;
            p += -6*b*b-4*b*b*xp;
        }
        else{
            yp++;
            p += -6*b*b-4*b*b*xp+4*a*a+4*a*a*yp;
        }
        xp++;
    }

}

int main()
{
    initwindow(600,600);
    int a = 80, b = 70;
    drawHyperbola(a, b);
    getch();
    return 0;
}
