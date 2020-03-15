#include <iostream>
#include <graphics.h>
#include <math.h>
#include "point.h"
using namespace std;
#define PI 3.14159265

class point {
public:
    int x, y;
    point() {
        x = 0;
        y = 0;
    }
    point(int a, int b) {
        x = a;
        y = b;
    }
} c, t1, t2, t3, s1, s2, s3, s4, e, z1, z2, z3, z4;

int mx = c.x, my = c.y, xtrans = 2;



point rotByI(point p, int i, int mx, int my) {
    float c = cos(i*(PI/180));
    float s = sin(i*(PI/180));
    float x = p.x*c - p.y*s + mx + my*s - mx*c + xtrans;
    float y = p.x*s + p.y*c + my - my*c - mx*s;
    return point(round(x), round(y));
}
/*
void rotateLine() {
    while(1) {
        cleardevice();
        line(p1.x,p1.y,p2.x,p2.y);
        delay(1);

    }

}
*/
int xrad = 60, yrad = 40;

void makeView() {
    circle(c.x,c.y,160);
    //putpixel(170, 300, YELLOW);

    line(s1.x,s1.y,s2.x,s2.y);
    line(s2.x,s2.y,s3.x,s3.y);
    line(s3.x,s3.y,s4.x,s4.y);
    line(s4.x,s4.y,s1.x,s1.y);

    line(z1.x,z1.y,z2.x,z2.y);
    line(z2.x,z2.y,z3.x,z3.y);
    line(z3.x,z3.y,z4.x,z4.y);
    line(z4.x,z4.y,z1.x,z1.y);

    line(t1.x,t1.y,t2.x,t2.y);
    line(t2.x,t2.y,t3.x,t3.y);
    line(t3.x,t3.y,t1.x,t1.y);

    ellipse(e.x,e.y,0,360,xrad,yrad);
}


void showRollNum() {
    point p1(600,250), p2(600,350);
    line(p1.x,p1.y,p2.x,p2.y);
    point p3(660,250), p4(620,250),p5(620,300), p6(660,300),p7(660,350), p8(620,350);
    line(p3.x,p3.y,p4.x,p4.y);
    //point p1(600,250), p2(600,350);
    line(p4.x,p4.y,p5.x,p5.y);
    //point p1(600,250), p2(600,350);
    line(p5.x,p5.y,p6.x,p6.y);
    //point p1(600,250), p2(600,350);
    line(p6.x,p6.y,p7.x,p7.y);
    line(p7.x,p7.y,p8.x,p8.y);

    point p9(680,250), p10(680,350);
    line(p9.x,p9.y,p10.x,p10.y);



    point p11(700,250), p12(740,250),p13(740,300), p14(740,350),p15(700,350), p16(700,300);
    line(p11.x,p11.y,p12.x,p12.y);
    //point p1(600,250), p2(600,350);
    line(p12.x,p12.y,p13.x,p13.y);
    //point p1(600,250), p2(600,350);
    line(p13.x,p13.y,p14.x,p14.y);
    //point p1(600,250), p2(600,350);
    line(p14.x,p14.y,p15.x,p15.y);
    line(p16.x,p16.y,p13.x,p13.y);




}


void rotatePoints() {
    //c, t1, t2, t3, s1, s2, s3, s4, e, z1, z2, z3, z4
    float i = 3;
    while(1) {
            /*p1 = rotByI(p1,i,midx,midy);
        p2 = rotByI(p2,i,midx,midy);
        cleardevice();
        line(p1.x,p1.y,p2.x,p2.y);
        sleep(1);*/
        //c = rotByI(c,i,mx,my);
        mx = c.x;my = c.y;
        t1 = rotByI(t1,i,mx,my);
        t2= rotByI(t2,i,mx,my);
        t3 = rotByI(t3,i,mx,my);
        s1 = rotByI(s1,i,mx,my);
        s2 = rotByI(s2,i,mx,my);
        s3 = rotByI(s3,i,mx,my);
        s4 = rotByI(s4,i,mx,my);
        e = rotByI(e,i,mx,my);
        z1 = rotByI(z1,i,mx,my);
        z2 = rotByI(z2,i,mx,my);
        z3 = rotByI(z3,i,mx,my);
        z4 = rotByI(z4,i,mx,my);
        //sleep(100);
        cleardevice();
        showRollNum();
        makeView();
        sleep(30);
    }
}

int main() {
    initwindow(800, 600);

    c.x = 170;c.y = 300;

    t1.x = 170;t1.y = 170;
    t2.x = 120;t2.y = 250;
    t3.x = 220;t3.y = 250;
    s1.x = 50;s1.y = 275;
    s2.x = 100;s2.y = 275;
    s3.x = 100;s3.y = 325;
    s4.x = 50;s4.y = 325;

    z1.x = 280;z1.y = 220;
    z2.x = 200;z2.y = 280;
    z3.x = 220;z3.y = 320;
    z4.x = 280;z4.y = 360;

    e.x = 170;e.y = 380;

    circle(c.x,c.y,160);
    putpixel(170, 300, YELLOW);

    line(s1.x,s1.y,s2.x,s2.y);
    line(s2.x,s2.y,s3.x,s3.y);
    line(s3.x,s3.y,s4.x,s4.y);
    line(s4.x,s4.y,s1.x,s1.y);

    line(z1.x,z1.y,z2.x,z2.y);
    line(z2.x,z2.y,z3.x,z3.y);
    line(z3.x,z3.y,z4.x,z4.y);
    line(z4.x,z4.y,z1.x,z1.y);

    line(t1.x,t1.y,t2.x,t2.y);
    line(t2.x,t2.y,t3.x,t3.y);
    line(t3.x,t3.y,t1.x,t1.y);

    ellipse(e.x,e.y,0,360,xrad,yrad);

    rotatePoints();

    getch();

    return 0;
}
