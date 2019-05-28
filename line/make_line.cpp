#include<graphics.h>
using namespace std;

void makeLine(int x1, int y1, int x2, int y2) {

}

int main() {
    initwindow(1000,600);
    int x1 = 50, y1 = 50, x2 = 100, y2 = 100;
    makeLine(x1,y1,x2,y2);
    getch();
    closegraph();
}
