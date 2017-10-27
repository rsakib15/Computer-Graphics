#include <GL/gl.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

void DrawGrid(){
    int x=0,y=0;
    glColor3f(0.0,1.0,1.0);
    for(int x=0;x<600;x+=20){
        for(int y=0;y<600;y+=20){
            glBegin(GL_POLYGON);
                glVertex2i(x,y);
                glVertex2i(x+18,y);
                glVertex2i(x+18,y+18);
                glVertex2i(x,y+18);
            glEnd();
        }
    }
    glFlush();
}

void myInit(){
    glClearColor(1.0,0.0,0.0,0.0);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,600.0,0.0,600.0);
}

void DrawLine(int x,int y){
    //cout<<"X: "<<x <<" Y: " <<y<<endl;
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POINTS);
        glVertex2i(x,y);
    glEnd();
    glFlush();
}

void incrementalLine(int x1,int y1,int xn,int yn){
    float   x, y;
    float dy = yn-y1;
    float dx = xn-x1;
    float m  = dy/dx;

    y=y1;

    for (x = x1; x < xn; ++x) {
        DrawLine(x,floor(y+0.5));
        y = y + m;
    }
}

void CallFunctions(){
    glClear(GL_COLOR_BUFFER_BIT);
    DrawGrid();
    incrementalLine(10,20, 200, 300);
    incrementalLine(100, 300, 300, 20);
}

int main(int argv,char** argc){
    glutInit(&argv,argc);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(400,80);
    glutCreateWindow("Chess Board");
    glutDisplayFunc(CallFunctions);
    myInit();
    glutMainLoop();
    return 0;
}
