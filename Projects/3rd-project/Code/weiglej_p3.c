/****************************************************
 *                  Project 3                       *
 ****************************************************
 *  Author:     Justin Weigle                       *
 *  Edited:     29 Oct 2019                         *
 ****************************************************
 * Draws the animation of a Wankel rotary engine.   *
 * Allows viewing from all different directions.    *
 ****************************************************/

#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "drawfunctions.h"

// Animation
static clock_t RESET_TIME, ANIM_TIME = 0;
static GLfloat FPS = 60.0;
static GLfloat INTAKE_X = 178.0;
static GLfloat EXHAUST_X = 198.0;
static GLfloat ECC_SHFT_I = 0.0;
static GLfloat ECC_SHFT_HEADING;
static GLint ROTATION_SPEED = 3;
static GLint INTAKE_EXHAUST_SPEED = 1;

// Interaction
static GLint RUN_ANIMATION = 0;

void init (void)
{
    glEnableClientState(GL_VERTEX_ARRAY);
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

// BACK BUFFER drawing ========================================================
	glDrawBuffer(GL_BACK);
	glClear(GL_COLOR_BUFFER_BIT);

    // INTAKE
    glPushMatrix();
        glColor3f(0.88, 0.88, 1.0);
        glTranslatef(INTAKE_X, 494.0, 0.0);
        intake_exhaust();
    glPopMatrix();

    // EXHAUST
    glPushMatrix();
        glColor3f(1.0, 0.88, 0.88);
        glTranslatef(EXHAUST_X, 341.0, 0.0);
        intake_exhaust();
    glPopMatrix();

    // ROTOR
    ECC_SHFT_HEADING = -ECC_SHFT_I * 3.1415926535897932384626433832795 / 180.0;
    glPushMatrix();
        glColor3f(0.0, 0.88, 0.88);
        glTranslatef((cos(ECC_SHFT_HEADING) * 26) + 401, (sin(ECC_SHFT_HEADING) * 26) + 417, 0.0);
        glRotatef((-ECC_SHFT_I/3) + 30, 0.0, 0.0, 1.0);
        glScalef(1.65, 1.65, 1.0);
        rotor();
    glPopMatrix();

    // ECCENTRIC SHAFT
    glPushMatrix();
        glTranslatef((cos(ECC_SHFT_HEADING) * 26) + 401, (sin(ECC_SHFT_HEADING) * 26) + 417, 0.0);
        glScalef(52.0, 52.0, 1.0);
        glRotatef(-ECC_SHFT_I, 0.0, 0.0, 1.0);
        glColor3f(0.79, 0.79, 0.79);
        eccentric_shaft_fill(180);
        glColor3f(0.0, 0.0, 0.0);
        eccentric_shaft();
    glPopMatrix();

    // PINION
    glLineWidth(2.0);
    glPushMatrix();
        glColor3f(0.87, 0.0, 0.0);
        glTranslatef(401, 417, 0.0);
        glScalef(30.0, 30.0, 1.0);
        outer_gear(10);
        glColor3f(0.0, 0.0, 0.0);
        outer_gear_outline();
        gear_teeth_outline(10);
    glPopMatrix();

    // CROWN GEAR
    glPushMatrix();
        glColor3f(0.0, 0.88, 0.0);
        glTranslatef((cos(ECC_SHFT_HEADING) * 26) + 401, (sin(ECC_SHFT_HEADING) * 26) + 417, 0.0);
        glRotatef((-ECC_SHFT_I/3), 0.0, 0.0, 1.0);
        glScalef(60.0, 60.0, 1.0);
        inner_gear(5);
        glColor3f(0.0, 0.0, 0.0);
        inner_gear_outline();
        gear_teeth_outline(5);
    glPopMatrix();
    glLineWidth(1.0);

    // HOUSING
    glColor3f(0.88, 0.88, 0.48);
    housing();

    // SPARK PLUGS
    glPushMatrix();
        glTranslatef(530.0, 445.0, 0.0);
        spark_plug(1);
        if (RUN_ANIMATION == 1)
            if (0 < ECC_SHFT_I/3 && ECC_SHFT_I/3 < 10)
            {
                glColor3f(1.0, 0.89, 0.19);
                sparks();
            }
        glTranslatef(0.0, -64.0, 0.0);
        spark_plug(1);
        if (RUN_ANIMATION == 1)
            if (0 < ECC_SHFT_I/3 && ECC_SHFT_I/3 < 10)
            {
                glColor3f(1.0, 0.89, 0.19);
                sparks();
            }
    glPopMatrix();

    glutSwapBuffers();
}


/****************************************************
 *                    idle                          *
 ****************************************************
 * Used for non-blocking animation                  *
 ****************************************************/
void idle (void)
{
    if (RUN_ANIMATION == 1)
    {
        ANIM_TIME = clock();
        if (ANIM_TIME > RESET_TIME)
        {
            RESET_TIME = RESET_TIME + (1.0/FPS) * CLOCKS_PER_SEC;

            // INTAKE
            INTAKE_X += INTAKE_EXHAUST_SPEED;
            if (INTAKE_X > 210)
                INTAKE_X = 178;

            // EXHAUST
            EXHAUST_X -= INTAKE_EXHAUST_SPEED;
            if (EXHAUST_X < 166)
                EXHAUST_X = 198;

            // ROTOR, CROWN GEAR, ECCENTRIC SHAFT, SPARK
            ECC_SHFT_I += (ROTATION_SPEED * 3);
            if (ECC_SHFT_I > (360 - ROTATION_SPEED * 3))
                ECC_SHFT_I = 0;

            glutPostRedisplay();
        }
    }
}


/****************************************************
 *                  menu_choice                     *
 ****************************************************
 * Menu options to reset or exit the program        *
 ****************************************************/
void menu_choice (int selection)
{
    // RESET
    if (selection == 1)
    {
        RUN_ANIMATION = 0;
        INTAKE_X = 178.0;
        EXHAUST_X = 198.0;
        ECC_SHFT_I = 0;
        glutPostRedisplay();
    }
    // EXIT
    if (selection == 2)
    {
        exit(0);
    }
}


/****************************************************
 *              toggle_animation                    *
 ****************************************************
 * Submenu options for turning animation on and off *
 ****************************************************/
void toggle_animation (int selection)
{
    // START ANIMATION
    if (selection == 1)
    {
        RUN_ANIMATION = 1;
    }
    // STOP ANIMATION
    if (selection == 2)
    {
        RUN_ANIMATION = 0;
        glutPostRedisplay();
    }
}


int main (int argc, char** argv)
{
    glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize (900, 900);
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]);
	init ();

    // make cursor visible during recording
    glutSetCursor(GLUT_CURSOR_LEFT_ARROW);

    // MENU CREATION
    int submenu = glutCreateMenu(toggle_animation);
    glutAddMenuEntry("Start Animation", 1);
    glutAddMenuEntry("Stop Animation", 2);
    glutCreateMenu(menu_choice);
    glutAddSubMenu("Toggle Animation", submenu);
    glutAddMenuEntry("Reset", 1);
    glutAddMenuEntry("Exit", 2);
    glutAttachMenu (GLUT_RIGHT_BUTTON);

	glutReshapeFunc (reshape);
	glutDisplayFunc (display);
    glutIdleFunc(idle);
	glutMainLoop ();
	return 0;
}
