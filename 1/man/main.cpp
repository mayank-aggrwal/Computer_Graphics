#include <graphics.h>
#include<iostream>
using namespace std;

void man() {
    circle(50,300,17);
    line(50,320,50,360);
    line(50,360,30,390);
    line(50,360,70,390);
    line(50,332,80,315);
    line(50,336,80,323);
    //setcolor(WHITE);
    rectangle(78,270,82,331);
    setfillstyle(HATCH_FILL, RED);
    floodfill(79,272,WHITE);

}

void floor() {

}
void cloud() {
}

int main()
{
    initwindow(500,500);
    floor();
    cloud();
    man();
    cin.get();
    //getch();
    return 0;
}
