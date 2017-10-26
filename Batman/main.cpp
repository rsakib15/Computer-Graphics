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


void Draw(int x,int y,int w,int h){
    glBegin(GL_POLYGON);
        glVertex2i(x,y);
        glVertex2i(x+w,y);
        glVertex2i(x+w,y+h);
        glVertex2i(x,y+h);
    glEnd();
}

void DrawLine(int x,int y,int w,int h){
    for(int i=0;i<7;i++){
        Draw(x,y,w,h);
        y+=20;
    }
}

void DrawCornerPositive(int x,int y,int w,int h){
    for(int i=0;i<6;i++){
        Draw(x,y,w,h);
        x+=20;
        y+=20;
    }
}

void DrawCornerNegative(int x,int y,int w,int h){
    for(int i=0;i<6;i++){
        Draw(x,y,w,h);
        x-=20;
        y+=20;
    }
}

void DrawVertLine(int x,int y,int w,int h){
    for(int i=0;i<17;i++){
        Draw(x,y,w,h);
        x+=20;
    }
}


void DrawHorizontalRectangle(int x,int y,int w,int h){
    int temp_x=x;
    for(int j=0;j<5;j++){
        x=temp_x;
        for(int i=0;i<27;i++){
            Draw(x,y,w,h);
            x+=20;
        }
        y+=20;
    }
}


void DrawVerticalRectangle(int x,int y,int w,int h){
    int temp_y=y;
    for(int j=0;j<5;j++){
        y=temp_y;
        for(int i=0;i<13;i++){
            Draw(x,y,w,h);
            y+=20;
        }
        x+=20;
    }
}

void DrawLower(int x,int y,int w,int h,int n){
    for(int i=0;i<n;i++){
        Draw(x,y,w,h);
            x+=20;
    }
    y+=20;
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
    DrawVerticalRectangle(280,180,w,h);

    x=60,y=220;

    DrawLower(x+20,y,w,h,25);

    DrawLower(x+40,y-20,w,h,23);

    DrawLower(x+60,y-40,w,h,7);
    DrawLower(x+340,y-40,w,h,7);

    DrawLower(x+80,y-60,w,h,5);
    DrawLower(x+240,y-60,w,h,3);
    DrawLower(x+360,y-60,w,h,5);

    DrawLower(x+100,y-80,w,h,3);
    DrawLower(x+240,y-80,w,h,3);
    DrawLower(x+380,y-80,w,h,3);

    DrawLower(x+140,y-100,w,h,1);
    DrawLower(x+260,y-100,w,h,1);
    DrawLower(x+380,y-100,w,h,1);

    x= 60,y=340;
    DrawLower(x+20,y,w,h,7);
    DrawLower(x+200,y,w,h,1);
    DrawLower(x+320,y,w,h,1);
    DrawLower(x+380,y,w,h,7);


    DrawLower(x+40,y+20,w,h,5);
    DrawLower(x+400,y+20,w,h,5);

    DrawLower(x+60,y+40,w,h,4);
    DrawLower(x+400,y+40,w,h,4);


    DrawLower(x+80,y+60,w,h,3);
    DrawLower(x+400,y+60,w,h,3);

    DrawLower(x+100,y+80,w,h,3);
    DrawLower(x+380,y+80,w,h,3);

    DrawLower(x+220,y+100,w,h,1);
    DrawLower(x+300,y+100,w,h,1);

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


