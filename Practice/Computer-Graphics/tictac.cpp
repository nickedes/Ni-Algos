#include "GL/freeglut.h"
#include "GL/gl.h"
#include <stdio.h>    // standard (I/O library)
#include <stdlib.h>   // standard library (set of standard C functions
#include <math.h>     // Math library (Higher math functions )
#include <string>

using namespace std;

// lighting
GLfloat LightAmbient[]= { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat LightDiffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat LightPosition[]= { 5.0f, 25.0f, 5.0f, 1.0f };
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };

// mouse variables: Win = windows size, mouse = mouse position
int mouse_x, mouse_y, Win_x, Win_y, object_select, turn = 0;

// state variables for Orho/Perspective view, lighting on/off
static int view_state = 1, light_state = 0;

// Use to spin X's and O's
int spin, spinboxes;

// Win = 1 player wins, -1 computer wins, 2 tie.
// player or computer; 1 = X, -1 = O
// start_game indicates that game is in play.
int player, computer, win, start_game;


// alingment of boxes in which one can win
// We have 8 posiblities, 3 accross, 3 down and 2 diagnally
//
// 0 | 1 | 2
// 3 | 4 | 5
// 6 | 7 | 8
//
// row, colunm, diagnal information

static int box[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6},
    {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

// Storage for our game board
// 1 = X's, -1 = O's, 0 = open space

int box_map[9];
// center x,y location for each box
int object_map[9][2] = {{-6,6},{0,6},{6,6},{-6,0},{0,0},{6,0},{-6,-6},{0,-6},{6,-6}};

// quadric pointer for build our X
GLUquadricObj *Cylinder;

//Timer
int ctimer = 9;
int ctflag = 0;

string time_string(int num){
	string tvals = "0123456789";
	string x = "";
	x += tvals[num];
	return x;
}

// I use this to put text on the screen
void Sprint( int x, int y, string st)
{
	int l,i;
    glColor3f(0, 0, 0.8);
	glRasterPos2i( x, y); // location to start printing text
	for( i=0; i < st.length(); i++)  // loop until i is greater then l
    {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, st[i]); // Print a character on the screen
	}
    
}

// Begin game routine
void init_game(void)
{
    int i;
    
    // Clear map for new game
    for( i = 0; i < 9; i++)
	{
        box_map[i] = 0;
    }
    
    // Set 0 for no winner
    win = 0;
    start_game = 1;
}



void init() {
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,1000,0.0,800,50.0,-50.0);

	start_game = 0;
    win = 0;

    // Create a new quadric
    Cylinder = gluNewQuadric();
    gluQuadricDrawStyle( Cylinder, GLU_FILL );
    gluQuadricNormals( Cylinder, GLU_SMOOTH );
    gluQuadricOrientation( Cylinder, GLU_OUTSIDE );

    glutPostRedisplay();
}


// Setup our Opengl world, called once at startup.
void init1(void)
{
    glClearColor (1.0, 1.0, 1.0, 0.0);  // When screen cleared, use black.
    glShadeModel (GL_SMOOTH);  // How the object color will be rendered smooth or flat
    glEnable(GL_DEPTH_TEST);   // Check depth when rendering
    // Lighting is added to scene
    glLightfv(GL_LIGHT1 ,GL_AMBIENT, LightAmbient);
    glLightfv(GL_LIGHT1 ,GL_DIFFUSE, LightDiffuse);
    glLightfv(GL_LIGHT1 ,GL_POSITION, LightPosition);
    glEnable(GL_LIGHTING);  // Turn on lighting
    glEnable(GL_LIGHT1);    // Turn on light 1
    
    start_game = 0;
    win = 0;
    
    // Create a new quadric
    Cylinder = gluNewQuadric();
    gluQuadricDrawStyle( Cylinder, GLU_FILL );
    gluQuadricNormals( Cylinder, GLU_SMOOTH );
    gluQuadricOrientation( Cylinder, GLU_OUTSIDE );
}

// Check for three in a row/colunm/diagnal
// returns 1 if there is a winner
int check_move( void )
{
    
    int i, t = 0;
    
    //Check for three in a row
    for( i = 0; i < 8; i++)
	{
        t = box_map[box[i][0]] + box_map[box[i][1]] + box_map[box[i][2]];
        if ( (t == 3) || ( t == -3) )
        {
            gluCylinder( Cylinder, 0.5, 0.5, box_map[box[i][0]], box_map[box[i][1]], box_map[box[i][2]]);
            spinboxes = i;
            return( 1 );
        }
    }
    t = 0;
    // check for tie
    for( i = 0; i < 8; i++)
	{
        t = t + abs(box_map[box[i][0]]) + abs( box_map[box[i][1]]) + abs( box_map[box[i][2]]);
    }
    
    if ( t == 24 ) return( 2 );
    
    return( 0 );
}

// Do we need to block other player?
int blocking_win(void)
{
    int i, t;
    for( i = 0; i < 8; i++)
	{
        t = box_map[box[i][0]] + box_map[box[i][1]] + box_map[box[i][2]];
        if ( (t == 2) || ( t == -2) )
        {
            // Find empty
            if (box_map[box[i][0]] == 0) box_map[box[i][0]] = computer;
            if (box_map[box[i][1]] == 0) box_map[box[i][1]] = computer;
            if (box_map[box[i][2]] == 0) box_map[box[i][2]] = computer;
            return( 1 );
        }
    }
    return( 0 );
}

// check for a free space in corner
int check_corner(void)
{
    int i;
    
    if ( box_map[0] == 0)
	{
        box_map[0] = computer;
        i = 1;
        return( 1 );
    }
    
    if ( box_map[2] == 0)
	{
        box_map[2] = computer;
        i = 1;
        return( 1 );
    }
    
    if ( box_map[6] == 0)
	{
        box_map[6] = computer;
        i = 1;
        return( 1 );
    }
    
    if ( box_map[8] == 0)
	{
        box_map[8] = computer;
        i = 1;
        return( 1 );
    }
    
    return( 0 );
}

// Check for free space in row
int check_row(void)
{
    
    if ( box_map[4] == 0)
	{
        box_map[4] = computer;
        return( 1 );
    }
    
    if ( box_map[1] == 0)
	{
        box_map[1] = computer;
        return( 1 );
    }
    
    if ( box_map[3] == 0)
	{
        box_map[3] = computer;
        return( 1 );
    }
    if ( box_map[5] == 0)
	{
        box_map[5] = computer;
        return( 1 );
    }
    if ( box_map[7] == 0)
	{
        box_map[7] = computer;
        return( 1 );
    }
    
    return( 0 );
}

// logic for computer's turn
int computer_move()
{
    if ( blocking_win() == 1) return( 1 );
    if ( check_corner() == 1) return( 1 );
    if ( check_row() == 1) return( 1 );
    
    return( 0 );
}




// This creates the spinning of the cube.
static void TimeEvent(int te)
{
    
    spin++;  // increase cube rotation by 1
	if (spin > 360) spin = 0; // if over 360 degress, start back at zero.
	glutPostRedisplay();  // Update screen with new rotation data
	glutTimerFunc( 10, TimeEvent, 1);  // Reset our timmer.
}




void Draw_O(int x, int y, int z, int a)
{
    glColor3f(1, 0, 0);
    glPushMatrix();
    glTranslatef(x, y, z);
    //glRotatef(a, 1, 0, 0);
    glColor3f(1, 0, 0);
    glutSolidTorus(0.5, 2.0, 8, 16);
    glPopMatrix();
    
}


void Draw_X(int x, int y, int z, int a)
{
    
    glPushMatrix();
    glColor3f(0, 1, 0);
    glTranslatef(x, y, z);
    glPushMatrix();
    glColor3f(0, 1, 0);
    //glRotatef(a, 1, 0, 0);
    glRotatef(90, 0, 1, 0);
    glRotatef(45, 1, 0, 0);
    glTranslatef( 0, 0, -3);
    gluCylinder( Cylinder, 0.5, 0.5, 6, 16, 16);
    //glutSolidCone( 2.5, 3.0, 16, 8 );
    glPopMatrix();
    glPushMatrix();
    //glRotatef(a, 1, 0, 0);
    glRotatef(90, 0, 1, 0);
    glRotatef(315, 1, 0, 0);
    glTranslatef( 0, 0, -3);
    gluCylinder( Cylinder, 0.5, 0.5, 6, 16, 16);
    //glutSolidCone( 2.5, 3.0, 16, 8 );
    glPopMatrix();
    glPopMatrix();
    
}
int new_g = 0;
// Draw our world
void display(void)
{
    int ix, iy;
    int i;
    int j;
    
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  //Clear the screen
    
    glMatrixMode (GL_PROJECTION);  // Tell opengl that we are doing project matrix work
    glLoadIdentity();  // Clear the matrix
    glOrtho(-9.0, 9.0, -9.0, 9.0, 0.0, 30.0);  // Setup an Ortho view
    glMatrixMode(GL_MODELVIEW);  // Tell opengl that we are doing model matrix work. (drawing)
    glLoadIdentity(); // Clear the model matrix
    
    glDisable(GL_COLOR_MATERIAL);
    glDisable(GL_LIGHTING);
    glColor3f(0.0, 0.0, 1.0);
    
    glColor3f(1, 0, 0);
    
    Sprint(3,8,"TIMER: ");
    // printf("%s %d\n", time_string(ctimer).c_str(), ctimer);
    Sprint(5,8,time_string(ctimer));
    ctflag++;
    if(ctflag == 50) {
    	ctimer--;
    	if(ctimer == -1) {
            new_g = 1;
            start_game = 0;
            if(turn == 1)
            {
                win = 1;
            }
            else if(turn == 0)
            {
                win = -1;
            }
    		ctimer = 9;
    	}
    	ctflag = 0;
    }
	if(ctimer <= 2) {
            Sprint(-3,8,"Remaining seconds 2");
    }

    if (win == 1) Sprint( 0, 8, "X wins");
    if (win == -1) Sprint( -3, 8, "O wins");
    if (win == 2) Sprint( -3, 8, "Tie");
    
    if(new_g == 1)
    {
        // for(int j = 0; j < 1000000000; j++);
        // printf("lolo");
        new_g = 0;
        for( i = 0; i < 9; i++)
        {
            box_map[i] = 0;
        }
    }
 // Setup view, and print view state on screen
    if (view_state == 1)
	{
        glColor3f( 1.0, 0.0, 0.0);
        //Sprint(-3, 8, "Perspective view");
        glMatrixMode (GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(60, 1, 1, 30);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }
    
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    
    //glColor3f( 1.0, 0.0, 0.0);
    gluLookAt( 0, 0, 20, 0, 0, 0, 0, 1, 0);
    
    
    // Draw Grid
    for( ix = 0; ix < 4; ix++)
	{
        glPushMatrix();
        glColor3f(1,1,1);
        glBegin(GL_LINES);
        glVertex2i(-9 , -9 + ix * 6);
        glVertex2i(9 , -9 + ix * 6 );
        glEnd();
        glPopMatrix();
	}
	for( iy = 0; iy < 4; iy++ )
    {
        glPushMatrix();
        glColor3f(1,1,1);
        glBegin(GL_LINES);
        glVertex2i(-9 + iy * 6, 9 );
        glVertex2i(-9 + iy * 6, -9 );
        glEnd();
        glPopMatrix();
    }
    
    glColorMaterial(GL_FRONT, GL_AMBIENT);
    glColor4f(0.5, 0.5, 0.5, 1.0);
    glColorMaterial(GL_FRONT, GL_EMISSION);
    glColor4f(0.0, 0.0, 0.0, 1.0 );
    glColorMaterial(GL_FRONT, GL_SPECULAR);
    glColor4f(0.35, 0.35, 0.35, 1.0);
    glColorMaterial(GL_FRONT, GL_DIFFUSE);
    glColor4f(0.69, 0.69, 0.69, 1.0);
    //glDisable(GL_COLOR_MATERIAL);
    glColor3f( 0, 1, 0);  // Cube color
    //glEnable(GL_COLOR_MATERIAL);
    // Draw object in box's
    
    for( i = 0; i < 9; i++)
    {

        if(box_map[i] == 1) 
            Draw_X( object_map[i][0], object_map[i][1], -1, 0);
        
        if(box_map[i] == -1) 
            Draw_O( object_map[i][0], object_map[i][1], -1, 0);
    }
    
    //glDisable(GL_COLOR_MATERIAL);
    
    glutSwapBuffers();
}

// This is called when the window has been resized.
void reshape (int w, int h)
{
    Win_x = w;
    Win_y = h;
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
}

void mouse(int button, int state, int x, int y)
{
    // We convert windows mouse coords to out openGL coords
    mouse_x =  (18 * (float) ((float)x/(float)Win_x))/6;
    mouse_y =  (18 * (float) ((float)y/(float)Win_y))/6;

    ctimer = 9;
    ctflag = 0;
  
    // What square have they clicked in?
    object_select = mouse_x + mouse_y * 3;
    
    if ( start_game == 0)
	{
        /*if ((button == GLUT_RIGHT_BUTTON) && (state == GLUT_DOWN))
        {
            player = 1;
            computer = -1;
            init_game();
            return;
        }*/
        
        if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
        {
            //Sprint(-3, 8, "Player 1 - X");
            //Sprint(-3, 8, "Player 2 - O");
            player = -1;
            computer = 1;
            init_game();
            start_game = 1;
            
        }
        //start_game = 1;
    }
    
    if ( start_game == 1)
	{
        if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
        {
            if (win == 0)
            {
                if (box_map[ object_select ] == 0)
                {
                    if(turn == 1)
                    {
                        box_map[ object_select ] = player;
                        win = check_move();
                        if (win == 1)
                        {
                            win = -1;
                            start_game = 0;
                            return;
                        }
                        turn = 0;
                    }
                    else
                    {
                        box_map[ object_select ] = computer;
                        win = check_move();
                        if (win == 1)
                        {
                            start_game = 0;
                            return;
                        }
                        turn = 1;
                    }
                    
                    //computer_move();
                    /*win = check_move();
                    if (win == 1)
                    {
                        win = -1;
                        start_game = 0;
                    }*/
                }
            }
        }
    }
    
    if ( win == 2 )start_game = 0;
    
}

// Main program
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (1000, 600);
    glutInitWindowPosition (10, 10);
    glutCreateWindow (argv[0]);
    glutSetWindowTitle("Tic Tac Toe Game");
    init ();
    //glutCreateMenu(options);
    glutAddMenuEntry("Play with X",1);
    glutAddMenuEntry("Play with O",2);
    glutAddMenuEntry("Quit",3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    //glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutTimerFunc( 10, TimeEvent, 1);
    glutMainLoop();
    return 0;
}