#include "GL/freeglut.h"
#include "GL/gl.h"
#include <iostream>
using namespace std;

#define WIDTH 600
#define HEIGHT 600

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glShadeModel(GL_FLAT);
}

void drawline()
{
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(100.0, 200.0);
	glVertex2f(300.0, 200.0);
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	// draw
	drawline();
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

	glutMainLoop();
	return 0;
}