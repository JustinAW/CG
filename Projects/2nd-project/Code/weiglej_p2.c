#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "drawfunctions.h"

// Hash table
static ht_t *ht;

// Animation Globals
clock_t Time, ResetTime = 0;
float SPEED = -1.0;
float FPS = 30.0;
int RUN_ANIMATION = 0;

// Interaction Globals
static GLint SLIDER_X = 300;
int SLIDER_TOGGLE = 0;

long MAX_REV_LIM_TIME = 10.0;
int BANG_TOGGLE = 1;


void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);
	glShadeModel (GL_FLAT);
}


void reshape (int w, int h)
{
	if (w > h)
      glViewport (0, 0, (GLfloat) h, (GLfloat) h);
	else
      glViewport (0, 0, (GLfloat) w, (GLfloat) w);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D (0.0, 900.0, 0.0, 900.0);
}


void display (void)
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    // BACK BUFFER drawing
	glColor3f (1.0, 0.0, 0.0);

	glDrawBuffer (GL_BACK);
	glClear (GL_COLOR_BUFFER_BIT);

    glColor3f (0.0, 0.0, 0.0);
    glPushMatrix();
        glLineWidth(3.0);
        glBegin(GL_LINES);
            glVertex2s (300, 30);
            glVertex2s (500, 30);
        glEnd();
    glPopMatrix();

    glColor3f (0.0, 1.0, 0.0);
    glPushMatrix();
        glBegin(GL_POLYGON);
            glVertex2s (SLIDER_X, 20);
            glVertex2s (SLIDER_X+10, 20);
            glVertex2s (SLIDER_X+10, 40);
            glVertex2s (SLIDER_X, 40);
        glEnd();
    glPopMatrix();

    glutSwapBuffers();
   	glFlush ();

    // AUX1 BUFFER picking
	glDrawBuffer (GL_AUX1);
	glClear (GL_COLOR_BUFFER_BIT);

    glColor3f (0.0, 0.0, 0.0);
    glPushMatrix();
        glBegin(GL_POLYGON);
            glVertex2s (SLIDER_X, 20);
            glVertex2s (SLIDER_X+10, 20);
            glVertex2s (SLIDER_X+10, 40);
            glVertex2s (SLIDER_X, 40);
        glEnd();
    glPopMatrix();

   	glFlush ();
}


char *check_pixel (GLint x, GLint y)
{
	GLfloat pixel[4];
	GLfloat r, g, b;

    glReadPixels(x, y, 1.0, 1.0, GL_RGBA, GL_FLOAT, &pixel);
    r = pixel[0]; g = pixel[1]; b = pixel[2];

    // combine pixel values to get single value for hash function
    GLfloat combined = r + g + b;

    // account for integer division inaccuracy of:
    // int output = pixel_value * 255 
    // float (r|g|b) = output / 255
    int rounded_i = (int)(combined * 100 + 0.5);
    GLfloat rounded = (float)rounded_i / 100;

    char *picked_color = ht_get(ht, rounded);
    
    return picked_color;
}


void mouse (int button, int state, GLint x, GLint y)
{
	GLint wHt;
	wHt = glutGet(GLUT_WINDOW_HEIGHT);
	y = wHt - y;

	glReadBuffer(GL_AUX1);

    switch (button)
    {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN)
            {
                char *picked_color = check_pixel(x, y);
                if (picked_color != NULL)
                {
                    printf("Name of clicked object: %s\n", picked_color);
                    if (strcmp(picked_color, "Slider") == 0)
                        SLIDER_TOGGLE = 1;
                }
            }
            if (state == GLUT_UP)
            {
                SLIDER_TOGGLE = 0;
            }
            break;
        case GLUT_MIDDLE_BUTTON:
            if (state == GLUT_DOWN)
            {
                char *picked_color = check_pixel(x, y);
                if (picked_color != NULL)
                {
                    printf("Name of clicked object: %s\n", picked_color);
                    //TODO make function that will write name of object to
                    // the screen at the location of the mouse at the time
                    // of clicking
                }
            }
            break;
        default:
            break;
    }
}


void mouse_motion (int x, int y)
{
    if (SLIDER_TOGGLE == 1)
    {
        if (x >= 305 && x <= 495)
        {
            SLIDER_X = x - 5;
            glutPostRedisplay();
        }
        if (x >= 495)
        {
            Time = clock();
        }
    }
}


void idle (void)
{
    if (RUN_ANIMATION == 1)
    {
        Time = clock();
        if (Time > ResetTime)
        {
            /*
            ResetTime = ResetTime + (1.0/FPS) * CLOCKS_PER_SEC;
            glClear (GL_COLOR_BUFFER_BIT);
            glRotatef(SPEED, 0.0, 0.0, 1.0);
            drawWheel();
            glFlush();
            */
        }
    }
    if (SLIDER_X == 490)
    {
        //long time = clock();
        clock_t time_diff = clock() - Time;
        double seconds_passed = ((double)time_diff)/CLOCKS_PER_SEC;
        //printf("time_diff %ld\n", time_diff);
        if (seconds_passed > MAX_REV_LIM_TIME)
        {
            if (BANG_TOGGLE == 1)
            {
                printf("BANGALANGA\n");
                BANG_TOGGLE = 0;
            }
        }
    }
}


void menu_choice (int selection)
{
    if (selection == 1)
    {
        RUN_ANIMATION = 0;
        SLIDER_X = 300;
        BANG_TOGGLE = 1;
        glutPostRedisplay();
    }
    if (selection == 2)
    {
        exit(0);
    }
}


void toggle_animation (int selection)
{
    if (selection == 1)
    {
        RUN_ANIMATION = 1;
    }
    if (selection == 2)
    {
        RUN_ANIMATION = 0;
        glutPostRedisplay();
    }
}


int main (int argc, char** argv)
{
    ht = ht_create();

    ht_set(ht, (GLfloat)0.00, "Slider");
    ht_set(ht, (GLfloat)0.01, "Intake");
    ht_set(ht, (GLfloat)0.02, "Exhaust");
    ht_set(ht, (GLfloat)0.03, "Stator Housing");
    ht_set(ht, (GLfloat)0.04, "Chamber");
    ht_set(ht, (GLfloat)0.05, "Chamber");
    ht_set(ht, (GLfloat)0.06, "Chamber");
    ht_set(ht, (GLfloat)0.07, "Pinion");
    ht_set(ht, (GLfloat)0.08, "Rotor");
    ht_set(ht, (GLfloat)0.09, "Crown Gear");
    ht_set(ht, (GLfloat)0.10, "Eccentric Shaft");
    ht_set(ht, (GLfloat)0.11, "Spark Plug");
    ht_set(ht, (GLfloat)0.12, "Spark Plug");

    ht_dump(ht);

    glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize (900, 900);
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]);
	init ();

    int submenu = glutCreateMenu(toggle_animation);
    glutAddMenuEntry("Start Animation", 1);
    glutAddMenuEntry("Stop Animation", 2);

    glutCreateMenu(menu_choice);
    glutAddSubMenu("Toggle Animation", submenu);
    glutAddMenuEntry("Reset", 1);
    glutAddMenuEntry("Exit", 2);
    glutAttachMenu (GLUT_RIGHT_BUTTON);

	glutReshapeFunc (reshape);
	glutMouseFunc (mouse);
	glutDisplayFunc (display);
    glutMotionFunc(mouse_motion);
    glutIdleFunc(idle);
	glutMainLoop ();
	return 0;
}
