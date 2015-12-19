//#include<stdio.h>
//#include <GLUT/GLUT.h>
//#include <string.h>
#include <math.h>
#define WIDTH 600
#define HEIGHT 600

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include<Windows.h>
#include "GL/freeglut.h"
#include "GL/gl.h"

using namespace std;

float arr[5000][2];
int z=0;
int flag=0;
float radius=15.0;
int ptr=0;
float color[3][3]={{1.0,0.0,0.0},{1.0,1.0,0.0},{0.0,1.0,0.0}};


//ALL THE DRAWING FUNCTIONS//

//Draw A ball to Follow the path
void drawBall(float x,float y)
{
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.2,2.0,1.2);
	glVertex2d(x,y);
	for(int i=0;i<=100;i++)
	{
		float const t = 2*3.14*(float)i/100.0;
		glVertex2d(x+sin(t)*radius,y+cos(t)*radius);
	}
	glEnd();
}


//Draw Path
void drawLines()
{
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0,0.0,1.0);
	for(int i=0;i<z;i++)
	{
		glVertex2f(arr[i][0],arr[i][1]);
	}
	glEnd();
}



//INITIALISATION
void init()
{
	glClearColor( 1.0, 1.0, 1.0, 0.3);
	glMatrixMode( GL_PROJECTION);
	gluOrtho2D(0.0,WIDTH,0.0,HEIGHT);
	memset(arr,0,5000);
	glPointSize(20.0);
}


//Reseting the Function
void resetAll()
{
	memset(arr,0,5000);
	z=0;
}

///OPENGL MAPPING///
float getOpenGLX(int x)
{
	double ox = x/ (double)WIDTH*(WIDTH);
	return ox;
}

float getOpenGLY(int y)
{
	double oy = (1 - y/ (double) HEIGHT)*HEIGHT;
	return oy;
}



//Insert Mouse coordinate to an array after mapping
void addValue(int x,int y)
{
	arr[z][0]=getOpenGLX(x);
	arr[z++][1]=getOpenGLY(y);
}



//Rest of the glut based special functions and their definition
void myDisplay()
{
	glClear( GL_COLOR_BUFFER_BIT);
	if(!flag)
	{
		drawLines();

		drawBall(arr[ptr][0],arr[ptr][1]);
	}


	glutSwapBuffers();
	glutPostRedisplay();
	glFlush();
}


void myMouseStat(int button,int state,int x, int y)
{
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		if(!flag)
		{
			resetAll();
			flag=1;
		}
	}
	else if(button==GLUT_LEFT_BUTTON && state==GLUT_UP)
	{
		if(flag)
		{
			ptr=0;
			flag=0;
		}
	}
}


void myPressedMove(int x,int y)
{
	if(flag)
	{
		addValue(x,y);
	}
}



void myTimer(int t)
{
	if(ptr!=z)
	{
		ptr++;
	}
	else
	{
		ptr=0;
	}
	glutTimerFunc(100,myTimer,0);
}

int main( int argc, char ** argv)
{
	glutInit( &argc, argv);
	glutInitDisplayMode( GLUT_DOUBLE| GLUT_RGB);
	glutInitWindowPosition( 100, 100);
	glutInitWindowSize(WIDTH,HEIGHT);
	glutCreateWindow( "Testing");
	init();
	glutDisplayFunc(myDisplay);
	glutMouseFunc(myMouseStat);
	glutMotionFunc(myPressedMove);
	glutTimerFunc(100,myTimer,0);
	glutMainLoop();
	return 0;
}