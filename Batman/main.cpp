#include <GL/gl.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

const int w=20,h= 20;

void DrawGrid(){
    int x=0,y=0;
    glColor3f(1.0,1.0,0.0);
    for(int x=0;x<660;x+=20){
        for(int y=0;y<660;y+=20){
            glBegin(GL_POLYGON);
                glVertex2i(x,y);
                glVertex2i(x+19,y);
                glVertex2i(x+19,y+19);
                glVertex2i(x,y+19);
            glEnd();
        }
    }
    glFlush();
}

void Draw(int x,int y){
    glBegin(GL_POLYGON);
        glVertex2i(x,y);
        glVertex2i(x+w,y);
        glVertex2i(x+w,y+h);
        glVertex2i(x,y+h);
    glEnd();
}

void DrawHorizontalLine(int x,int y){
    for(int i=0;i<7;i++){
        Draw(x,y);
        y+=20;
    }
}

void DrawVerticalLine(int x,int y){
    for(int i=0;i<17;i++){
        Draw(x,y);
        x+=20;
    }
}

void DrawCornerPositive(int x,int y){
    for(int i=0;i<6;i++){
        Draw(x,y);
        x+=20;
        y+=20;
    }
}

void DrawCornerNegative(int x,int y){
    for(int i=0;i<6;i++){
        Draw(x,y);
        x-=20;
        y+=20;
    }
}

void DrawHorizontalRectangle(int x,int y){
    int temp_x=x;
    for(int j=0;j<5;j++){
        x=temp_x;
        for(int i=0;i<27;i++){
            Draw(x,y);
            x+=20;
        }
        y+=20;
    }
}

void DrawVerticalRectangle(int x,int y){
    int temp_y=y;
    for(int j=0;j<5;j++){
        y=temp_y;
        for(int i=0;i<13;i++){
            Draw(x,y);
            y+=20;
        }
        x+=20;
    }
}

void DrawOuter(int x,int y,int n){
    for(int i=0;i<n;i++){
        Draw(x,y);
            x+=20;
    }
    y+=20;
}

void DrawBatman(){
    glColor3f(0,0,0);
    int x = 20, y = 220;
    int DisplayWidth = 660;

    DrawHorizontalLine(x,y);
    DrawHorizontalLine(DisplayWidth-2*x,y);

    x = 160,y = 80;

    DrawVerticalLine(x,y);
    DrawVerticalLine(x,480);

    x=40,y=360;

    DrawCornerPositive(x,y);
    DrawCornerPositive(500,100);

    x=140,y=100;

    DrawCornerNegative(x,y);
    DrawCornerNegative(600,360);

    x=60,y=240;

    DrawHorizontalRectangle(x,y);
    DrawVerticalRectangle(280,180);

    x=60,y=220;

    DrawOuter(x+20,y,25);
    DrawOuter(x+40,y-20,23);

    DrawOuter(x+60,y-40,7);
    DrawOuter(x+340,y-40,7);

    DrawOuter(x+80,y-60,5);
    DrawOuter(x+240,y-60,3);
    DrawOuter(x+360,y-60,5);

    DrawOuter(x+100,y-80,3);
    DrawOuter(x+240,y-80,3);
    DrawOuter(x+380,y-80,3);

    DrawOuter(x+140,y-100,1);
    DrawOuter(x+260,y-100,1);
    DrawOuter(x+380,y-100,1);

    x= 60,y=340;
    DrawOuter(x+20,y,7);
    DrawOuter(x+200,y,1);
    DrawOuter(x+320,y,1);
    DrawOuter(x+380,y,7);

    DrawOuter(x+40,y+20,5);
    DrawOuter(x+400,y+20,5);

    DrawOuter(x+60,y+40,4);
    DrawOuter(x+400,y+40,4);

    DrawOuter(x+80,y+60,3);
    DrawOuter(x+400,y+60,3);

    DrawOuter(x+100,y+80,3);
    DrawOuter(x+380,y+80,3);

    DrawOuter(x+220,y+100,1);
    DrawOuter(x+300,y+100,1);

    glFlush();
}

void myInit(){
    glClearColor(1.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,660.0,0.0,600.0);
}

void CallFunctions(){
    glClear(GL_COLOR_BUFFER_BIT);
    DrawGrid();
    DrawBatman();
}

int main(int argv,char** argc){
    glutInit(&argv,argc);
    glutInitWindowSize(660,660);
    glutInitWindowPosition(400,80);
    glutCreateWindow("Batman");
    glutDisplayFunc(CallFunctions);
    myInit();
    glutMainLoop();
    return 0;
}


