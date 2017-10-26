#include <GL/gl.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

void DrawGrid(){
    int x=0,y=0;
    glColor3f(1.0,1.0,1.0);
    for(int x=0;x<600;x+=20){
        for(int y=0;y<600;y+=20){
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

void myInit(){
    glClearColor(1.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,600.0,0.0,600.0);
}

void CallFunctions(){
    glClear(GL_COLOR_BUFFER_BIT);
    DrawGrid();
}

int main(int argv,char** argc){
    glutInit(&argv,argc);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(400,80);
    glutCreateWindow("Batman");
    glutDisplayFunc(CallFunctions);
    myInit();
    glutMainLoop();
    return 0;
}


