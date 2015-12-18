#include "GL/freeglut.h"
#include "GL/gl.h"
#include <iostream>
using namespace std;

/* initial triangle */

GLfloat v[3][2]={{-1.0, -0.58}, 
    {1.0, -0.58}, {0.0, 1.15}};
int n; /* number of recursive steps */
int input;
int flag=0;
double rotate_x=1;

void keyPress(int key,int x,int y)
{
    
if(key>=48&&key<=57)
{
    flag=0;   
input=key-48;
}
if(key==GLUT_KEY_UP)
{
    
rotate_x*=2;
    flag=1;}
if(key==GLUT_KEY_DOWN)
{rotate_x*=0.5;flag=1;}
   glutPostRedisplay();
}

void triangle( GLfloat *a, GLfloat *b, GLfloat *c)
/* display one triangle */
{
    glVertex2fv(a); 
    glVertex2fv(b); 
    glVertex2fv(c);
}


void divide_triangle(GLfloat *a, GLfloat *b, GLfloat *c, int m,bool type)
{
    /* triangle subdivision using vertex numbers */
    GLfloat v0[2], v1[2], v2[2];
    int j;
    if(m>0)
    {
        for(j=0; j<2; j++) v0[j]=(a[j]+b[j])/2;
        for(j=0; j<2; j++) v1[j]=(a[j]+c[j])/2;
        for(j=0; j<2; j++) v2[j]=(b[j]+c[j])/2;
        divide_triangle(a, v0, v1, m-1,type);
        divide_triangle(c, v1, v2, m-1,type);
        divide_triangle(b, v2, v0, m-1,type);
        divide_triangle(v0, v2, v1, m-1,!type);
    }
    else
    {    
        if(type)
            glColor3f(0.0,0.0,1.0);
        else
            glColor3f(1.0,0.0,0.0);  
        triangle(a,b,c);
    }    
    /* draw triangle at end of recursion */
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    for(int i=0;flag&&i<2;i++)
    {
    v[0][i]/=rotate_x;
        v[1][i]/=rotate_x;
        v[2][i]/=rotate_x;
    }
    divide_triangle(v[0], v[1], v[2], input-1,true);
    glEnd();
    glFlush();
}
void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
    glMatrixMode(GL_MODELVIEW);
    //glClearColor (1.0, 0.0, 1.0,1.0);
    glColor3f(0.0,1.0,0.0);
}


int main(int argc, char **argv)
{
    n=4;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("2D Gasket");
    glutDisplayFunc(display);
    glutSpecialFunc(keyPress);
    myinit();
    glutMainLoop();
    
    return 0;
}
