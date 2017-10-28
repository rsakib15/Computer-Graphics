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
    cout<<"X: "<<x <<" Y: " <<y<<endl;
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POINTS);
        glVertex2i(x,y);
    glEnd();
    glFlush();
}


void DDA(double x1,double y1,double x2,double y2){
    double dx = x2-x1;
    double dy = y2-y1;
    double len=abs(x2-x1);

    if(abs(y2-y1)>len){
        len = abs(y2-y1);
    }

    double Xinc = dx / (double)len;
    double Yinc = dy / (double)len;

    double X = x1;
    double Y = y1;

    for(int i = 0; i <= len; i++){
        DrawLine(X,Y);
        X += Xinc;
        Y += Yinc;
    }
    glFlush();
}

void Bresenham(int x0,int y0,int x1,int y1) {
	int x=x0,y=y0;
	int dx=x1-x0;
	int dy=y1-y0;
	int d=2*dy-dx;
	int dE=2*dy;
	int dNE=2*(dy-dx);
	DrawLine(x,y);

	while(x<x1) {
		if(d<0) {
			d+=dE;
		}
		else {
			d+=dNE;
			y++;
		}
		x++;
		DrawLine(x,y);
	}
}


void LinesDot(int x0,int y0,int x1,int y1) {
	int x=x0,y=y0;
	int dx=x1-x0;
	int dy=y1-y0;
	int d=2*dy-dx;
	int dE=2*dy;
	int dNE=2*(dy-dx);
	DrawLine(x,y);
	int cnt=0;

	while(x<x1) {

            if(d<0) {
                d+=dE;
            }
            else {
                d+=dNE;
                y++;
            }
            x++;
            if(cnt<4){
                cnt++;
            }
            else{
                DrawLine(x,y);
                cnt=0;
            }

	}
}

void CallFunctions(){
    glClear(GL_COLOR_BUFFER_BIT);
    DrawGrid();
    DDA(40,120,400,380);
    Bresenham(40,80,400,340);
    LinesDot(40,40,400,300);
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
