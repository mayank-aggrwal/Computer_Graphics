#include <iostream>
#include <graphics.h>
using namespace std;

void drawPixel(int x, int y, int xoff, int yoff) {
    putpixel(x+xoff, y+yoff, WHITE);
    putpixel(x+xoff, -y+yoff, WHITE);
    putpixel(-x+xoff, y+yoff, WHITE);
    putpixel(-x+xoff, -y+yoff, WHITE);

    putpixel(y+xoff, x+yoff, WHITE);
    putpixel(y+xoff, -x+yoff, WHITE);
    putpixel(-y+xoff, x+yoff, WHITE);
    putpixel(-y+xoff, -x+yoff, WHITE);
}

void drawCircle(int r) {

    int xp = 0, yp = r;
    float p = 2*r-3;
    float de = -6-4*xp, dse;

    while(xp <= yp) {
        drawPixel(xp, yp, 300, 300);
        if(p < 0) {
            yp--;
            dse = -10-4*xp+4*yp;
            p += dse;
        }
        else {
            de = -6-4*xp;
            p += de;
        }

        xp++;
    }
    /*/ m > 1
    p = 3-2*r;
    float dn,dnw;
    xp = r;
    yp = 0;
    while(xp > yp) {
        drawPixel(xp, yp, 300, 300);
        if(p > 0) {
            xp--;
            dnw = 10+4*yp-4*xp;
            p += dnw;
        }
        else {
            dn = 6+4*yp;
            p += dn;
        }

        yp++;
    }
    */
}

void drawCircleanyCentre(int r, int xcenter, int ycenter) {

    int xp = 0, yp = r;
    float p = 2*r-3;
    float de = -6-4*xp, dse;

    while(xp <= yp) {
        drawPixel(xp, yp, 300+xcenter, 300-ycenter);
        if(p < 0) {
            yp--;
            dse = -10-4*xp+4*yp;
            p += dse;
        }
        else {
            de = -6-4*xp;
            p += de;
        }

        xp++;
    }
    /*/ m > 1
    p = 3-2*r;
    float dn,dnw;
    xp = r;
    yp = 0;
    while(xp > yp) {
        drawPixel(xp, yp, 300+xcenter, 300-ycenter);
        if(p > 0) {
            xp--;
            dnw = 10+4*yp-4*xp;
            p += dnw;
        }
        else {
            dn = 6+4*yp;
            p += dn;
        }

        yp++;
    }
    */
}

int main()
{
    initwindow(600, 600);

    //drawCircle(90);
    line(300,0,300,600);
    line(0,300,600,300);
    drawCircleanyCentre(90,-150,150);
    drawCircleanyCentre(90,-150,-150);
    drawCircleanyCentre(90,130,150);
    drawCircleanyCentre(90,150,-120);
    getch();
    return 0;
}
