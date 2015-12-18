// sphere with moving up
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <math.h>
#include <iostream>
using namespace std;

#define WIDTH 600
#define HEIGHT 600
GLfloat cx = 300.0, cy = 300.0, r = 100.0;
int num_segments = 1000;
GLdouble radius=1;
GLfloat y = 0.0;

float color[3] = {0.0, 0.0, 0.0};
void init(void)
{
	// all 1 -> white
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glShadeModel(GL_FLAT);
}

void DrawCircle(int index) 
{ 
	glColor3f(color[0], color[1], color[2]);
	glBegin(GL_LINE_LOOP); 
	for(int ii = 0; ii < num_segments; ii++) 
	{ 
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 

		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 

		glVertex2f(x + cx, y + cy);//output vertex 

	} 
	glEnd(); 
}

void drawCurrentColor(void)
{
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
    glVertex3f(550, 10, 0);
    glVertex3f(580, 10, 0);
    glVertex3f(580, 35, 0);
    glVertex3f(550, 35, 0);
    glEnd();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	// draw sphere
	drawCurrentColor();
	DrawCircle(1);
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
	// xRotated = yRotated = zRotated = 30.0;
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	// for handling mouse events
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}