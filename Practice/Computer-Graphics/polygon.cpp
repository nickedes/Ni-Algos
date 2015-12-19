// Creates a rectangular polygon
#include "GL/freeglut.h"
#include "GL/gl.h"

#define WIDTH 600
#define HEIGHT 6009

// #include <GL/glut.h>

static float zoom_factor = 0.5;

float ver[8][3] = 
{
    {-0.5 , -0.5 , 0.5}  ,
    {-0.5 , 0.5  , 0.5}  ,
    {0.5  , 0.5  , 0.5}  ,
    {0.5  , -0.5 , 0.5}  ,
    {-0.5 , -0.5 , -0.5} ,
    {-0.5 , 0.5  , -0.5} ,
    {0.5  , 0.5  , -0.5} ,
    {0.5  , -0.5 , -0.5} ,
};

GLfloat color[8][3] = 
{
    {0.1 , 0.1  , 0.1} ,
    {0.2 , 0.2  , 0.2} ,
    {0.3 , 0.3  , 0.3} ,
    {0.4 , 0.4  , 0.4} ,
    {0.5 , 0.5  , 0.5} ,
    {0.6 , 0.6  , 0.6} ,
    {0.7 , 0.7  , 0.7} ,
    {0.8 , 0.8  , 0.8} ,
};

void mouse_events(int button, int state, int x, int y)
{
   // Wheel reports as button 3(scroll up) and button 4(scroll down)
   if ((button == 3) || (button == 4)) // It's a wheel event
   {
       // Each wheel event reports like a button click, GLUT_DOWN then GLUT_UP
       // if (state == GLUT_UP) return; // Disregard redundant GLUT_UP events
 
        zoom_factor += 0.5;

       // printf("Scroll %s At %d %d\n", (button == 3) ? "Up" : "Down", x, y);
   }
   // else{  // normal button event
   //      zoom_factor -= 0.5;
   //     // printf("Button %s At %d %d\n", (state == GLUT_DOWN) ? "Down" : "Up", x, y);
   // }
}

void quad(int a,int b,int c,int d)
{
    glBegin(GL_QUADS);

    glColor3fv(color[a]); glVertex3fv(ver[a]);
    glColor3fv(color[b]); glVertex3fv(ver[b]);
    glColor3fv(color[c]); glVertex3fv(ver[c]);
    glColor3fv(color[d]); glVertex3fv(ver[d]);

    glEnd();
}

void colorcube()
{
    quad(0 , 3 , 2 , 1);
    quad(2 , 3 , 7 , 6);
    quad(0 , 4 , 7 , 3);
    quad(1 , 2 , 6 , 5);
    quad(4 , 5 , 6 , 7);
    quad(0 , 1 , 5 , 4);
}

double rotate_y = 0; 
double rotate_x = 0;
void key_events( int key, int x, int y ) 
{
    if (key == GLUT_KEY_UP)
        zoom_factor += 0.5;

    else if (key == GLUT_KEY_DOWN)
        zoom_factor -= 0.5;

    else if (key == GLUT_KEY_RIGHT)
        rotate_x += 5;

    else if (key == GLUT_KEY_LEFT)
        rotate_y += 5;

    glutPostRedisplay();
}

void display()
{
    glClearColor( 0, 0, 0, 1 );
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    int w = glutGet( GLUT_WINDOW_WIDTH );
    int h = glutGet( GLUT_WINDOW_HEIGHT );

    gluPerspective(3.0*zoom_factor, w / h, 0.1, 500 );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt
        ( 
            3, 3, 3, 
            0, 0, 0,
            0, 0, 1
        );

    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );

    colorcube();

    glutSwapBuffers();
}

int main( int argc, char **argv )
{
    glutInit( &argc, argv );
    
    glutInitDisplayMode( GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE );
    
    glutInitWindowSize( 1024, 768 );
    glutCreateWindow( "Cube Fun" );
    
    glutDisplayFunc( display );

    glutSpecialFunc( key_events );
    glutMouseFunc( mouse_events );
    
    glEnable( GL_DEPTH_TEST );
    
    glutMainLoop();
    return 0;
}