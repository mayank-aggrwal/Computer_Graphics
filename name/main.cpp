#include <graphics.h>

using namespace std;

void printM(int x, int y, int w,int size =50, int dec=3) {
    line(x%w,y+dec,x%w,y+size-dec);
    line(x%w,y+size+dec,x%w,y+2*size-dec);
    line((x+dec),y,(x+size-dec),y);
    line((x+size)%w,y+dec,(x+size)%w,y+size-dec);
    line((x+size+dec),y,(x+2*size-dec),y);
    line((x+2*size)%w,y+dec,(x+2*size)%w,y+size-dec);
    line((x+2*size)%w,y+size+dec,(x+2*size)%w,y+2*size-dec);
}
void printA(int x, int y, int w,int size =50, int dec=3) {
    line(x,y+dec,x,y+size-dec);
    line(x,y+size+dec,x,y+2*size-dec);
    line(x+dec,y,x+size-dec,y);
    line(x+size,y+dec,x+size,y+size-dec);
    line(x+size,y+size+dec,x+size,y+2*size-dec);
    line(x+dec,y+size,x+size-dec,y+size);

}
void printY(int x, int y, int w,int size =50, int dec=3) {
    line(x+dec,y+size,x+size-dec,y+size);
    line(x,y+dec,x,y+size-dec);
    line(x+size,y+dec,x+size,y+size-dec);
    line(x+size,y+size+dec,x+size,y+2*size-dec);
    line(x+dec,y+2*size,x+size-dec,y+2*size);
}
void printN(int x, int y, int w,int size =50, int dec=3) {
    line(x,y+dec,x,y+size-dec);
    line(x,y+size+dec,x,y+2*size-dec);
    line(x+size,y+dec,x+size,y+size-dec);
    line(x+size,y+size+dec,x+size,y+2*size-dec);
    line(x+2*size,y+dec,x+2*size,y+size-dec);
    line(x+2*size,y+size+dec,x+2*size,y+2*size-dec);
    line(x+dec,y,x+size-dec,y);
    line(x+size+dec,y+2*size,x+2*size-dec,y+2*size);
}
void printK(int x, int y, int w,int size =50, int dec=3) {
    line(x,y+dec,x,y+size-dec);
    line(x,y+size+dec,x,y+2*size-dec);
    line(x+dec,y+size,x+size-dec,y+size);
    line(x+size,y+dec,x+size,y+size-dec);
    line(x+size,y+size+dec,x+size,y+2*size-dec);
}

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
    ////////////////////////////////////////////////////////////////////////
        //outtextxy(100,450,"hello");
        int x1, y1;
        while(!ismouseclick(WM_LBUTTONDOWN)) {
            ;
        }
        //outtextxy(100,350,"hello");
        //char *ch = "you clicked";
        getmouseclick(WM_LBUTTONDOWN, x1, y1);

        //outtextxy(100,450,ch);


    w -= 50;
    for(int i = 0; ;) {

        x = x + 4;
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
        while(ismouseclick(WM_LBUTTONDBLCLK)) {
            closegraph();
            return 0;
        }
        
        
    }

    //getch();
    closegraph();
}
