#include<graphics.h>
#include<cmath>


void m_line(int x1, int y1, int x2, int y2) {
    float dx = x2 - x1, dy = y2 - y1;
    float x = x1, y = y1, m = dy/dx;
    //printit
    putpixel(x, y, WHITE);
    if(m >= 1) {
        y++;
        while(y <= y2) {
                x = x + 1/m;
                //round(y);
                putpixel(round(x), y, WHITE);
            // printit
                y++;
        }
    }
    else {
        x++;
        while(x <= x2) {
                y = y + m;
                //round(y);
                putpixel(x, round(y), WHITE);
            // printit
                x++;
        }
    }

}

void m_line_s(int x1, int y1, int x2, int y2) {
    float dx = x2 - x1, dy = y2 - y1;
    float x = x1, y = y1, m = dy/dx;
    //printit
    putpixel(x, y, WHITE);

        x++;
        while(x <= x2) {
                y = y + m;
                //round(y);
                putpixel(x, round(y), WHITE);
            // printit
                x++;
        }

}

int main()
{
    initwindow(500,500);
    m_line(10,10,90,60);
    m_line(10,10,90,180);
    line(10,90,90,260);
    m_line_s(410,10,490,180);
    getch();
    return 0;
}
