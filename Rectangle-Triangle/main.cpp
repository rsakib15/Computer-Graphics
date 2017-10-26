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

void DrawTrianglePolyGon(){
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2i(220,60);
        glVertex2i(380,60);
        glVertex2i(220,180);
    glEnd();
    glFlush();
}

void DrawTriangleLine(){
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
        glVertex2i(20,60);
        glVertex2i(20,180);

        glVertex2i(20,60);
        glVertex2i(180,60);

        glVertex2i(180,60);
        glVertex2i(20,180);
    glEnd();
    glFlush();
}

void DrawTriangleQuad(){
glColor3f(0.0,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex2i(420,60);
        glVertex2i(420,180);

        glVertex2i(420,180);
        glVertex2i(580,60);
    glEnd();
    glFlush();
}


void DrawRectangleQuad(){
glColor3f(0.0,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex2i(420,240);
        glVertex2i(420,400);

        glVertex2i(420,400);
        glVertex2i(580,400);

        glVertex2i(580,400);
        glVertex2i(580,240);

        glVertex2i(580,240);
        glVertex2i(420,240);
    glEnd();
    glFlush();
}

void DrawRectanglePolyGon(){
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2i(220,400);
        glVertex2i(380,400);
        glVertex2i(380,240);
        glVertex2i(220,240);
    glEnd();
    glFlush();
}

void DrawRectangleLine(){
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
        glVertex2i(20,240);
        glVertex2i(20,400);

        glVertex2i(20,400);
        glVertex2i(180,400);

        glVertex2i(180,400);
        glVertex2i(180,240);

        glVertex2i(180,240);
        glVertex2i(20,240);
    glEnd();
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
    DrawTriangleLine();
    DrawTrianglePolyGon();
    DrawTriangleQuad();

    DrawRectanglePolyGon();
    DrawRectangleQuad();
    DrawRectangleLine();
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


