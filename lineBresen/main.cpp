#include <iostream>
#include <graphics.h>

using namespace std;

void drawLine(int x1, int y1, int x2, int y2) {
    int xoff = 300, yoff = 300;
    if(x1 > x2) {
        swap(x1, x2);
        swap(y1, y2);
    }

    int b = x2-x1, a = y1-y2, c = x1*(y2-y1)-y1*(x2-x1);
    int dx = x2-x1, dy = y2-y1;

    int xp = x1, yp = y1;
    float m = (1.0*dy)/dx;
    cout << "m is : " << m << endl;
    if(m >= 0) {
        if(dy <= dx) {
                cout << "Im here\n";
            int p = -b-2*a;
            while(xp <= x2) {
                putpixel(xp+xoff, -yp+yoff, WHITE);
                if(p >= 0) {
                    p += -2*a-2*b;
                    yp++;
                }
                else {
                    p += -2*a;
                }
                xp++;
            }
        }
        else if(dy > dx) {
            int p = a+2*b;
            while(yp <= y2) {
                putpixel(xp+xoff, -yp+yoff, WHITE);
                if(p >= 0) {
                    p += 2*b;
                }
                else {
                    xp++;
                    p += 2*b+2*a;
                }
                yp++;
            }
        }
    }
    else {
        if(m >= -1) {
            int p = b-2*a;
            while(xp <= x2) {
                putpixel(xp+xoff, -yp+yoff, WHITE);
                if(p >= 0) {
                    p += -2*a;
                }
                else {
                    yp--;
                    p += -2*a+2*b;
                }
                xp++;
            }
        }
        else {
            int p = a-2*b;
            while(yp >= y2) {
                putpixel(xp+xoff, -yp+yoff, WHITE);
                if(p >= 0) {
                    p += -2*b;
                }
                else {
                    xp++;
                    p += -2*b+2*a;
                }
                yp--;
            }
        }
    }

}

int main()
{
    initwindow(600, 600);
    int x1 = -70, y1 = -30, x2 = 120, y2 = 140;
    int x11 = -250, y11 = 60, x21 = 120, y21 = -140;
    line(0,300,600,300);
    line(300,0,300,600);
    drawLine(x1,y1,x2,y2);
    drawLine(x11,y11,x21,y21);
    getch();
    return 0;
}

