
#include<iostream>

#include <graphics.h>
int main()
{
    initwindow(400, 400);
    line(50, 50, 100, 100);
    putpixel(60,61,YELLOW);
    putpixel(60,80,GREEN);
    outtext("Hello Mayank");
    outtextxy(100,100,"Nimish");
    //getmous
    getch();
    closegraph();
    return 0;
}
