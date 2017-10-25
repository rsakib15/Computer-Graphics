#include <GL/gl.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

void ChessBoard(){
    int x=0,y=0;
    bool white = false;
    for(int i=0;i<8;i++){
        y=0;
        if(i%2==0){
            white = true;
        }
        else{
            white = false;

        }
        for(int j=0;j<8;j++){
            if(white){
                glColor3f(0.0,0.0,0.0);
                white = false;
            }
            else{
                glColor3f(1.0,1.0,1.0);
                white = true;
            }
            glBegin(GL_POLYGON);
                glVertex2i(x,y);
                glVertex2i(x+80,y);
                glVertex2i(x+80,y+80);
                glVertex2i(x,y+80);
            glEnd();
            y+=80;
        }
        x+=80;
    }
    glFlush();
}

void myInit(){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,640.0,0.0,640.0);
}

void CallFunctions(){
    glClear(GL_COLOR_BUFFER_BIT);
    ChessBoard();
}

int main(int argv,char** argc){
    glutInit(&argv,argc);
    glutInitWindowSize(640,640);
    glutInitWindowPosition(400,80);
    glutCreateWindow("Chess Board");
    glutDisplayFunc(CallFunctions);
    myInit();
    glutMainLoop();
    return 0;
}


