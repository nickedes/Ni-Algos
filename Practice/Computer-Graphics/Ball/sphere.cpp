// sphere with moving up
#include "GL/freeglut.h"
#include "GL/gl.h"
#include <math.h>
#include <iostream>
using namespace std;

GLfloat xRotated, yRotated, zRotated;
GLdouble radius=1;
GLfloat y = 0.0;
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	// glShadeModel(GL_FLAT);
}

void DrawSphere()
{
	// traslate the draw by z = -4.0
    // Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
    glTranslatef(0.0,y,-10.0);
    // Red color used to draw.
    glColor3f(1.0, 0.0, 1.0); 
    // changing in transformation matrix.
    // rotation about X axis
    // glRotatef(xRotated,1.0,0.0,0.0);
    // rotation about Y axis
    // glRotatef(yRotated,0.0,1.0,0.0);
    // rotation about Z axis
    // glRotatef(zRotated,0.0,0.0,1.0);
    // scaling transfomation 
    // glScalef(1.0,1.0,1.0);
    // built-in (glut library) function , draw you a sphere.
    glutSolidSphere(radius,100,100);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	// draw sphere
	DrawSphere();
	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); 
    gluPerspective(39.0,(GLdouble)w/(GLdouble)h,0.6,21.0);
    glMatrixMode(GL_MODELVIEW);
 //    glViewport(0,0,w,h);  //Use the whole window for rendering
}

void show()
{
	y += 0.05;
	if( y > 5.0)
		y = -5.0;
	cout << y << endl;
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		glutIdleFunc(show);
	else if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
		glutIdleFunc(NULL);
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
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