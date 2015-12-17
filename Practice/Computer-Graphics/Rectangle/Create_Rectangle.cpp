/*
Creates a rectangle.
 */
#include "GL/freeglut.h"
#include "GL/gl.h"

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_FLAT);
}

void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glRectf(-25.0, -25.0, 25.0, 25.0);
	glPopMatrix();
	glutSwapBuffers();
}	

void reshape(int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0); // last 2 params (-1.0, 1.0) bring (0, 0) in the centre of screen
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("learn");
	
	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}