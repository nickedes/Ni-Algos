#include "GL/freeglut.h"
#include "GL/gl.h"
#include <math.h>
#include <iostream>
using namespace std;

#define WIDTH 600
#define HEIGHT 600

GLfloat cx = 100.0, cy = 300.0, r = 50.0;
int segs = 100;

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glShadeModel(GL_FLAT);
}

void drawline()
{
	glLineWidth(5.0);
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(100.0, 300.0);
	glVertex2f(500.0, 300.0);
	glEnd();
}

void drawCircle()
{
	glColor3f(1.0,0.0,1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < segs; ++i)
	{
		float theta = 2.0f * 3.14159f * float(i) / float(segs);
		float x = r * cosf(theta);
		float y = r * sinf(theta);
		glVertex2f(x+cx, y+cy);
	}
	glEnd();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	// draw
	drawline();
	drawCircle();
	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
	glMatrixMode(GL_MODELVIEW);
}

void moveback()
{
	
}

void moveforward()
{

}
void keyb(unsigned char key, int x, int y)
{
	if(key == 'a')
	{
		glutIdleFunc(moveback);
		cout << "a";
	}	
	else if(key == 'd')
	{
		glutIdleFunc(moveforward);
		cout << "d";
	}
	else
		cout << "w";
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("ball");

	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyb);
	glutMainLoop();
	return 0;
}