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


void DrawBatman(){
    glColor3f(0,0,0);


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
    glutCreateWindow("Mario");
    glutDisplayFunc(CallFunctions);
    myInit();
    glutMainLoop();
    return 0;
}


