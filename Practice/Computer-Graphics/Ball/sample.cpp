#include "GL/freeglut.h"
#include "GL/gl.h"
#include <math.h>
#include <iostream>
using namespace std;

#define WIDTH 600
#define HEIGHT 600

GLfloat cx = 300.0, cy = 300.0, r = 40.0;
int segs = 100;
void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glShadeModel(GL_FLAT);
}
void drawcircle()
{
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < segs; ++i)
	{
		float thet = 2.0f * 3.14159f * float(i) / float(segs);
		float x = r * cosf(thet);
		float y = r * sinf(thet);
		glVertex2f(cx + x, cy + y);
	}
	glEnd();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	// draw objs
	drawcircle();
	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,WIDTH,0.0,HEIGHT);
	glMatrixMode(GL_MODELVIEW);
}

void mouse(int button, int state, int x, int y)
{

}

void keyb(unsigned char key, int x, int y)
{
	if (key == '1')
		cx += 10.0;
	else
		cy += 2.0;
	cout << key;
	glutPostRedisplay();
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Testing");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyb);
	glutMainLoop();
	return 0;
}