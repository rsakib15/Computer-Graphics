#include <GL/gl.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

const int w=20,h= 20;

void DrawGrid(){
    int x=0,y=0;
    glColor3f(1.0,1.0,1.0);
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

void SelectPixel(int x,int y,int n){
    for(int i=0;i<n;i++){
        Draw(x,y);
        x+=20;
    }

}

void DrawMario(){
    glColor3f(0,0,0);
    int x=200;
    int y = 140;

    for(int i=0;i<16;i++){
        if(i==0){
            glColor3f(0.31,0.17,0.08);
            SelectPixel(x,y,4);
            x+=160;
            SelectPixel(x,y,4);
            x=220;
        }
        else if(i==1){
            glColor3f(0.31,0.17,0.08);
            SelectPixel(x,y,3);
            x+=140;
            SelectPixel(x,y,3);
            x=240;
        }
        else if(i==2){
            glColor3f(1.0,0.0,0.0);
            SelectPixel(x,y,3);
            x+=100;
            SelectPixel(x,y,3);
            x=200;
        }
        else if(i==3){
            glColor3f(1.0,0.7,0.5);
            SelectPixel(x,y,2);
            x+=40;
            glColor3f(1.0,0.0,0.0);
            SelectPixel(x,y,8);
            x+=160;
            glColor3f(1.0,0.7,0.5);
            SelectPixel(x,y,2);
            x=200;
        }
        else if(i==4){
            glColor3f(1.0,0.7,0.5);
            SelectPixel(x,y,3);
            x+=60;
            glColor3f(1.0,0.0,0.0);
            SelectPixel(x,y,1);
            x+=20;
            glColor3f(1.0,1.0,0.0);
            SelectPixel(x,y,1);
            x+=20;
            glColor3f(1.0,0.0,0.0);
            SelectPixel(x,y,2);
            x+=40;
            glColor3f(1.0,1.0,0.0);
            SelectPixel(x,y,1);
            x+=20;
            glColor3f(1.0,0.0,0.0);
            SelectPixel(x,y,1);
            x+=20;
            glColor3f(1.0,0.7,0.5);
            SelectPixel(x,y,3);

            x=200;
        }

        else if(i==5){
            glColor3f(1.0,0.7,0.5);
            SelectPixel(x,y,2);
            x+=40;
            glColor3f(0.0,0.0,1.0);
            SelectPixel(x,y,2);
            x+=40;
            glColor3f(1.0,0.0,0.0);
            SelectPixel(x,y,4);
            x+=80;
            glColor3f(0.0,0.0,1.0);
            SelectPixel(x,y,2);
            x+=40;
            glColor3f(1.0,0.7,0.5);
            SelectPixel(x,y,2);

            x=200;
        }
        else if(i==6){
            glColor3f(0.0,0.0,1.0);
            SelectPixel(x,y,4);
            x+=80;
            glColor3f(1.0,0.0,0.0);
            SelectPixel(x,y,1);
            x+=20;
            glColor3f(0.0,0.0,1.0);
            SelectPixel(x,y,2);
            x+=40;
            glColor3f(1.0,0.0,0.0);
            SelectPixel(x,y,1);
            x+=20;
            glColor3f(0.0,0.0,1.0);
            SelectPixel(x,y,4);

            x=220;
        }
        else if(i==7){
            glColor3f(0.0,0.0,1.0);
            SelectPixel(x,y,3);
            x+=60;
            glColor3f(1.0,0.0,0.0);
            SelectPixel(x,y,1);
            x+=20;
            glColor3f(0.0,0.0,1.0);
            SelectPixel(x,y,2);
            x+=40;
            glColor3f(1.0,0.0,0.0);
            SelectPixel(x,y,1);
            x+=20;
            glColor3f(0.0,0.0,1.0);
            SelectPixel(x,y,3);

            x=240;

        }
        else if(i==8){
            glColor3f(0.0,0.0,1.0);
            SelectPixel(x,y,2);
            x+=40;
            glColor3f(1.0,0.0,0.0);
            SelectPixel(x,y,1);
            x+=20;
            glColor3f(0.0,0.0,1.0);
            SelectPixel(x,y,3);

            x=260;
        }
        else if(i==9){
            glColor3f(1.0,0.7,0.5);
            SelectPixel(x,y,7);
            x=220;
        }
        else if(i==10){
            glColor3f(0.0,0.0,0.0);
            SelectPixel(x,y,2);
            x+=40;
            glColor3f(1.0,0.7,0.5);
            SelectPixel(x,y,4);
            x+=80;
            glColor3f(0.0,0.0,0.0);
            SelectPixel(x,y,4);

            x=220;
        }
        else if(i==11){
            glColor3f(0.0,0.0,0.0);
            SelectPixel(x,y,1);
            x+=20;
            glColor3f(1.0,0.7,0.5);
            SelectPixel(x,y,1);
            x+=20;
            glColor3f(0.0,0.0,0.0);
            SelectPixel(x,y,2);
            x+=40;
            glColor3f(1.0,0.7,0.5);
            SelectPixel(x,y,3);
            x+=60;
            glColor3f(0.0,0.0,0.0);
            SelectPixel(x,y,1);
            x+=20;
            glColor3f(1.0,0.7,0.5);
            SelectPixel(x,y,3);

            x=220;
        }
        else if(i==12){
            glColor3f(0.0,0.0,0.0);
            SelectPixel(x,y,1);
            x+=20;
            glColor3f(1.0,0.7,0.5);
            SelectPixel(x,y,1);
            x+=20;
            glColor3f(0.0,0.0,0.0);
            SelectPixel(x,y,1);
            x+=20;
            glColor3f(1.0,0.7,0.5);
            SelectPixel(x,y,3);
            x += 60;
            glColor3f(0.0,0.0,0.0);
            SelectPixel(x,y,1);
            x+=20;
            glColor3f(1.0,0.7,0.5);
            SelectPixel(x,y,3);
            x = 240;

        }
        else if(i==13){
            glColor3f(0.0,0.0,0.0);
            SelectPixel(x,y,3);
            x+=60;
            glColor3f(1.0,0.7,0.5);
            SelectPixel(x,y,2);
            x+=40;
            glColor3f(0.0,0.0,0.0);
            SelectPixel(x,y,1);
            x+=20;
            glColor3f(1.0,0.7,0.5);
            SelectPixel(x,y,1);
            x = 240;
        }
        else if(i==14){
            glColor3f(1.0,0.0,0.0);
            SelectPixel(x,y,9);
            x = 260;
        }
        else if(i==15){
            glColor3f(1.0,0.0,0.0);
            SelectPixel(x,y,5);
        }
        y+=20;
    }
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
    DrawMario();
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


