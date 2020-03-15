#include <graphics.h>

using namespace std;

void m_line(int x1, int y1, int x2, int y2) {
    int x = x1, y = y1;
    putpixel(x, y, WHITE);
    float dx = x2 - x1, dy = y2 - y1;
    float m = dy/dx;
    float twody = 2 * dy, twodx = 2 * dx;
    float p = twody - dx;
    while(x <= x2) {
        if(p < 0) {
            p += twody;
        }
        else {
            y++;
            p += twody - twodx;
        }
        putpixel(x, y, WHITE);
        x++;
    }
}

int main()
{
    initwindow(500,500);
    m_line(10,10,170,50);
    line(10,50,170,90);
    getch();
    return 0;
}
