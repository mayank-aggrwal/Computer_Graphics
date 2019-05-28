#include <graphics.h>
#include<iostream>
using namespace std;

void cycle(int x, int y, int r = 24) {
    circle(x,y,24);
    circle(x+90,y,24);
    line(x+60,y-50,x+90,y);
    line(x+55,y-50,x+60,y-50);
    line(x,y,x+50,y);
    line(x+24,y-30,x,y);
    line(x+24,y-30,x+71,y-30);
    line(x+50,y,x+71,y-30);
    line(x+27,y-34,x+27,y-30);
    line(x+23,y-34,x+31,y-34);
}

void floor(int maxx, int maxy, int y, int r) {
    line(4,y+r+1,maxx-4,y+r+1);
}

int main()
{
    initwindow(500,500);
    int r = 24, x = 40, y = 350;
    cycle(x,y,r);
    floor(getmaxx(),getmaxy(),y,r);

    while(!ismouseclick(WM_LBUTTONDOWN)){
        ;
    }
    int a, b;
    getmouseclick(WM_LBUTTONDOWN, a, b);
    a = getmaxx();
    b = getmaxy();
    for(int i = 0; 1; ++i) {
        delay(10);
        cleardevice();
        cycle((x+i)%a,y,r);
        floor(a, b, y, r);
    }


    //cin.get();
    getch();
    return 0;
}
