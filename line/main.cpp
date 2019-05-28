#include <graphics.h>

using namespace std;

int main()
{
    initwindow(1000, 600);
    /*
    line(400, 50, 100, 100);
    putpixel(60,61,YELLOW);
    putpixel(60,80,GREEN);
    outtext("Hello Mayank");
    outtextxy(100,100,"Nimish");
    */

    while(true) {
        int x1, y1;
        while(!ismouseclick(WM_LBUTTONDOWN)) {
            ;
        }
        getmouseclick(WM_LBUTTONDOWN, x1, y1);
        
    }

    getch();
    closegraph();
    return 0;
}
