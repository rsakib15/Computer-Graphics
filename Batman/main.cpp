#include <GL/gl.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;


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


void DrawLine(int x,int y,int w,int h){
    for(int i=0;i<7;i++){
        glBegin(GL_POLYGON);
            glVertex2i(x,y);
            glVertex2i(x+w,y);
            glVertex2i(x+w,y+h);
            glVertex2i(x,y+h);
        glEnd();
        y+=20;
    }
}

void DrawCornerPositive(int x,int y,int w,int h){
    for(int i=0;i<6;i++){
        glBegin(GL_POLYGON);
            glVertex2i(x,y);
            glVertex2i(x+w,y);
            glVertex2i(x+w,y+h);
            glVertex2i(x,y+h);
        glEnd();
        x+=20;
        y+=20;
    }
}

void DrawCornerNegative(int x,int y,int w,int h){
    for(int i=0;i<6;i++){
        glBegin(GL_POLYGON);
            glVertex2i(x,y);
            glVertex2i(x+w,y);
            glVertex2i(x+w,y+h);
            glVertex2i(x,y+h);
        glEnd();
        x-=20;
        y+=20;
    }
}

void DrawVertLine(int x,int y,int w,int h){
    for(int i=0;i<17;i++){
        glBegin(GL_POLYGON);
            glVertex2i(x,y);
            glVertex2i(x+w,y);
            glVertex2i(x+w,y+h);
            glVertex2i(x,y+h);
        glEnd();
        x+=20;
    }
}


void DrawHorizontalRectangle(int x,int y,int w,int h){
    int temp_x=x;
    for(int j=0;j<5;j++){
        x=temp_x;
        for(int i=0;i<27;i++){
            glBegin(GL_POLYGON);
                glVertex2i(x,y);
                glVertex2i(x+w,y);
                glVertex2i(x+w,y+h);
                glVertex2i(x,y+h);
            glEnd();
            x+=20;
        }
        y+=20;
    }
}

void DrawBatman(){
    glColor3f(0,0,0);

    int x = 20, w = 20, h = 20, y = 220;
    DrawLine(x,y,w,h);
    DrawLine(660-2*x,y,w,h);

    x = 160,y = 80;
    DrawVertLine(x,y,w,h);
    DrawVertLine(x,480,w,h);

    x=40,y=360;
    DrawCornerPositive(x,y,w,h);
    DrawCornerPositive(500,100,w,h);

    x=140,y=100;
    DrawCornerNegative(x,y,w,h);
    DrawCornerNegative(600,360,w,h);

    x=60,y=240;
    DrawHorizontalRectangle(x,y,w,h);

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


