#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 600
#define HEIGHT 600

// #include <GLUT/glut.h>
#include "GL/freeglut.h"
#include "GL/gl.h"
float arr[5000][2];

int z=0;

// Our Global Stuff
float currentColor[] = {0, 0, 0};

float r_arr[5000][2]; int r_len;
float b_arr[5000][2]; int g_len;
float g_arr[5000][2]; int b_len;

float allColor[4][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

void drawQuad1(GLfloat x, GLfloat y, GLfloat radius)
{
    int i, lineAmount = 200;
    GLfloat twicePi = M_PI/ 2.0f;
    
    glColor3f(allColor[0][0], allColor[0][1], allColor[0][2]);    //glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for(i = 0; i <= lineAmount; i++)
    {
        glVertex2f(
            x + (radius * cos ( i * twicePi / lineAmount)),
            y + (radius * sin( i * twicePi / lineAmount))
        );
    }
    glVertex3f(x, y, 0);
    glVertex3f(x, y + radius, 0);
    glVertex3f(x, y, 0);
    glVertex3f(x + radius, y, 0);

    glEnd();
}

void drawQuad2(GLfloat x, GLfloat y, GLfloat radius)
{
    int i, lineAmount = 200;
    GLfloat twicePi = M_PI/ 2.0f;
    
    glColor3f(allColor[1][0], allColor[1][1], allColor[1][2]);
    glBegin(GL_POLYGON);
    for(i = lineAmount; i <= lineAmount * 2; i++)
    {
        glVertex2f(
                   x + (radius * cos ( i * twicePi / lineAmount)),
                   y + (radius * sin( i * twicePi / lineAmount))
                   );
    }
    glVertex3f(x, y, 0);
    glVertex3f(x, y - radius, 0);
    glVertex3f(x, y, 0);
    glVertex3f(x - radius, y, 0);
    
    glEnd();
}

void drawQuad3(GLfloat x, GLfloat y, GLfloat radius)
{
    int i, lineAmount = 200;
    GLfloat twicePi = M_PI/ 2.0f;
    
    glColor3f(allColor[2][0], allColor[2][1], allColor[2][2]);
    glBegin(GL_POLYGON);
    for(i = lineAmount * 2; i <= lineAmount * 3; i++)
    {
        glVertex2f(
                   x + (radius * cos ( i * twicePi / lineAmount)),
                   y + (radius * sin( i * twicePi / lineAmount))
                   );
    }
    glVertex3f(x, y, 0);
    glVertex3f(x, y - radius, 0);
    glVertex3f(x, y, 0);
    glVertex3f(x - radius, y, 0);
    
    glEnd();
}

void drawQuad4(GLfloat x, GLfloat y, GLfloat radius)
{
    int i, lineAmount = 200;
    GLfloat twicePi = M_PI/ 2.0f;
    
    glColor3f(allColor[3][0], allColor[3][1], allColor[3][2]);
    glBegin(GL_POLYGON);
    for(i = lineAmount * 3; i <= lineAmount * 4; i++)
    {
        glVertex2f(
                   x + (radius * cos ( i * twicePi / lineAmount)),
                   y + (radius * sin( i * twicePi / lineAmount))
                   );
    }
    glVertex3f(x, y, 0);
    glVertex3f(x, y - radius, 0);
    glVertex3f(x, y, 0);
    glVertex3f(x + radius, y, 0);
    
    glEnd();
}

void drawColorBoxes()
{
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(15, 15, 0);
    glVertex3f(30, 15, 0);
    glVertex3f(30, 30, 0);
    glVertex3f(15, 30, 0);
    glEnd();
    
    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);
    glVertex3f(35, 15, 0);
    glVertex3f(50, 15, 0);
    glVertex3f(50, 30, 0);
    glVertex3f(35, 30, 0);
    glEnd();
    
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex3f(55, 15, 0);
    glVertex3f(70, 15, 0);
    glVertex3f(70, 30, 0);
    glVertex3f(55, 30, 0);
    glEnd();
    
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex3f(75, 15, 0);
    glVertex3f(90, 15, 0);
    glVertex3f(90, 30, 0);
    glVertex3f(75, 30, 0);
    glEnd();
}

void drawCurrentColorBox(float color[])
{
    glColor3f(color[0], color[1], color[2]);
    
    glBegin(GL_POLYGON);
    glVertex3f(550, 10, 0);
    glVertex3f(580, 10, 0);
    glVertex3f(580, 35, 0);
    glVertex3f(550, 35, 0);
    glEnd();    
}

//INITIALISATION
void init()
{
    glClearColor(1.0, 1.0, 1.0, 0.3);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,WIDTH,0.0,HEIGHT);
    memset(arr,0,5000);
    glPointSize(20.0);
}

//Reseting the Function
void resetAll()
{
    memset(arr, 0, 5000);
    z = 0;
}

//Rest of the glut based special functions and their definition
void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    drawColorBoxes();
    drawCurrentColorBox(currentColor);
    
    drawQuad1(300, 300, 100);
    drawQuad2(300, 300, 100);
    drawQuad3(300, 300, 100);
    drawQuad4(300, 300, 100);
    
    glutSwapBuffers();
    glutPostRedisplay();
    glFlush();
}

void mouseDown(int button, int state, int x, int y)
{
    double r = 0.0, g = 0.0, b = 0.0;
    double real_x = x / (double) WIDTH * (WIDTH);
    double real_y = (1 - y / (double) HEIGHT) * HEIGHT;
    
    if(button==GLUT_LEFT_BUTTON) {
        
        if (real_y > 15 && real_y < 30) {
            
            if (real_x > 15 && real_x < 30){
                r = 1.0;
            }
            
            if (real_x > 35 && real_x < 50){
                g = 1.0;                
            }
            
            if (real_x > 55 && real_x < 70){
                b = 1.0;
            }
            
            if (real_x > 75 && real_x < 90){
                r = 1.0;
                g = 1.0;
            }

            // Update global color and draw box
            currentColor[0] = r;
            currentColor[1] = g;
            currentColor[2] = b;
        }
        
        if(real_y > 300 && real_y < 400){
            
            if(real_x > 300 && real_x <400){
                
                allColor[0][0] = currentColor[0];
                allColor[0][1] = currentColor[1];
                allColor[0][2] = currentColor[2];
            }
            else if(real_x > 200 && real_x <300){
                allColor[1][0] = currentColor[0];
                allColor[1][1] = currentColor[1];
                allColor[1][2] = currentColor[2];
            }

        }
        
        else if(real_y > 200 && real_y < 300){
            
            if(real_x > 200 && real_x <300){
                
                allColor[2][0] = currentColor[0];
                allColor[2][1] = currentColor[1];
                allColor[2][2] = currentColor[2];
            }
            else if(real_x > 300 && real_x <400){
                
                allColor[3][0] = currentColor[0];
                allColor[3][1] = currentColor[1];
                allColor[3][2] = currentColor[2];
            }
            
        }
        
        
        glutPostRedisplay();
    }
}

// TODO: Add values to different arrays
void mouseMove(int x, int y)
{
    if (currentColor[0] == 1.0) {
        r_arr[r_len][0] = x / (double) WIDTH * (WIDTH);
        r_arr[r_len][1] = (1 - y / (double) HEIGHT) * HEIGHT;
        r_len++;
    }
    
    if (currentColor[1] == 1.0) {
        g_arr[g_len][0] = x / (double) WIDTH * (WIDTH);
        g_arr[g_len][1] = (1 - y / (double) HEIGHT) * HEIGHT;
        g_len++;
    }
    
    if (currentColor[2] == 1.0) {
        b_arr[b_len][0] = x / (double) WIDTH * (WIDTH);
        b_arr[b_len][1] = (1 - y / (double) HEIGHT) * HEIGHT;
        b_len++;
    }
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
    
    glutMouseFunc(mouseDown);
    glutMotionFunc(mouseMove);
    
    glutMainLoop();
    return 0;
}