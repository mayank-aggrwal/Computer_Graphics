#include <graphics.h>

using namespace std;

int main()
{
    int w = 500, h = 500;
    initwindow(w,h);
    int x = 100, y = 100;
    int siz =30;
    float space = 0.4 * siz;
    //int t = x;
    //   STATTIC   /////////////////////////////////////////////////////////////////////

        //x = x + 4;
        int t = x;
        printM(t%w,y,INT_MAX,siz);
        t = t+2*siz+space;
        printA(t%w,y,w,siz);
        t = t+siz+space;
        printY(t%w,y,w,siz);
        t = t+siz+space;
        printA(t%w,y,w,siz);
        t = t+siz+space;
        printN(t%w,y,w,siz);
        t = t+2*siz+space;
        printK(t%w,y,w,siz);

    closegraph();
}
