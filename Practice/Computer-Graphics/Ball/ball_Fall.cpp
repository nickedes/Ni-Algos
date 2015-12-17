#include "GL/freeglut.h"
#include "GL/gl.h"
#include <math.h>
#include <iostream>
using namespace std;

static GLfloat cx = 1.0;
static GLfloat cy = 1.0;
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void DrawCircle(float cx, float cy, float r, int num_segments) 
{ 
	glColor3f(1.0, 0.0, 1.0);
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

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	DrawCircle(cx, cy, 5.0, 1000);
	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void show_spin(void)
{
	// handling translations
	cy -= 0.2;
	if(cy < -60)
		cy = 60.0;
	cout << cy << endl;
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		glutIdleFunc(show_spin);
	else if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
		glutIdleFunc(NULL);
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Various");

	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	// for handling mouse events
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}