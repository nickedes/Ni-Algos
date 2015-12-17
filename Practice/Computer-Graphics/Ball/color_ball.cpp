// sphere with moving up
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <math.h>
#include <iostream>
using namespace std;

#define WIDTH 600
#define HEIGHT 600
GLfloat xRotated, yRotated, zRotated;
GLdouble radius=1;
GLfloat y = 0.0;
void init(void)
{
	// all 1 -> white
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glShadeModel(GL_FLAT);
}

void drawCurrentColor(void)
{
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
    glVertex3f(50, 10, 0);
    glVertex3f(80, 10, 0);
    glVertex3f(80, 35, 0);
    glVertex3f(50, 35, 0);
    glEnd();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	// draw sphere
	drawCurrentColor();
	//DrawSphere();
	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); 
	// glOrtho(-100.0,100.0,-100.0,100.0,-1.0,1.0);
	gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
    glMatrixMode(GL_MODELVIEW);
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		glutIdleFunc(NULL);
	else if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
		glutIdleFunc(NULL);
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Sphere");

	init();
	xRotated = yRotated = zRotated = 30.0;
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	// for handling mouse events
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}