/****************************************************
 *                  Project 2                       *
 ****************************************************
 *  Author:     Justin Weigle                       *
 *  Edited:     20 Oct 2019                         *
 *  Submitted:  20 Oct 2019                         *
 ****************************************************
 * Draws the animation of a Wankel rotary engine.   *
 * Allows adjustment of the animation speed and     *
 * information about the parts to be displayed.     *
 ****************************************************/

#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "drawfunctions.h"
#include "showinfo.h"

// Hash table
static ht_t *HT;

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
static GLint SLIDER_X = 300;
static GLint SLIDER_G = 363;
static GLint SLIDER_Y = 426;
static GLint SLIDER_O = 489;
static GLint SLIDER_TOGGLE = 0;
static GLint INFO_SELECTION = 0;

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

    // SLIDER LINE
    glColor3f(0.0, 0.0, 0.0);
    slider(SLIDER_X, 1);

    // SLIDER
    if (SLIDER_X < SLIDER_G)
        glColor3f(0.0, 1.0, 0.0);
    else if (SLIDER_X < SLIDER_Y)
        glColor3f(0.9, 0.9, 0.0);
    else if (SLIDER_X < SLIDER_O)
        glColor3f(1.0, 0.5, 0.0);
    else
        glColor3f(1.0, 0.0, 0.0);
    slider(SLIDER_X, 2);

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

    // INFO DRAWING
    if (INFO_SELECTION != 0)
    {
        glColor3f(0.0, 0.0, 0.0);
        draw_info(INFO_SELECTION);
    }

    glutSwapBuffers();


// AUX0 BUFFER picking ========================================================
	glDrawBuffer (GL_AUX0);
	glClear (GL_COLOR_BUFFER_BIT);

    // SLIDER
    glColor3f(0.0, 0.0, 0.00);
    slider(SLIDER_X, 2);

    // INTAKE
    glPushMatrix();
        glColor3f(0.0, 0.0, 0.01);
        glTranslatef(INTAKE_X, 494.0, 0.0);
        intake_exhaust();
    glPopMatrix();

    // EXHAUST
    glPushMatrix();
        glColor3f(0.0, 0.0, 0.02);
        glTranslatef(EXHAUST_X, 341.0, 0.0);
        intake_exhaust();
    glPopMatrix();

    // CHAMBERS
    glColor3f(0.0, 0.0, 0.03);
    chambers();

    // ROTOR
    ECC_SHFT_HEADING = -ECC_SHFT_I * 3.1415926535897932384626433832795 / 180.0;
    glPushMatrix();
        glColor3f(0.0, 0.0, 0.04);
        glTranslatef((cos(ECC_SHFT_HEADING) * 26) + 401, (sin(ECC_SHFT_HEADING) * 26) + 417, 0.0);
        glRotatef((-ECC_SHFT_I/3) + 30, 0.0, 0.0, 1.0);
        glScalef(1.65, 1.65, 1.0);
        rotor();
    glPopMatrix();

    // ECCENTRIC SHAFT
    glPushMatrix();
        glColor3f(0.0, 0.0, 0.05);
        glTranslatef((cos(ECC_SHFT_HEADING) * 26) + 401, (sin(ECC_SHFT_HEADING) * 26) + 417, 0.0);
        glScalef(52.0, 52.0, 1.0);
        eccentric_shaft_fill(0);
    glPopMatrix();

    // PINION
    glLineWidth(2.0);
    glPushMatrix();
        glColor3f(0.0, 0.0, 0.06);
        glTranslatef(401, 417, 0.0);
        glScalef(30.0, 30.0, 1.0);
        outer_gear(10);
    glPopMatrix();

    // CROWN GEAR
    glPushMatrix();
        glColor3f(0.0, 0.0, 0.07);
        glTranslatef((cos(ECC_SHFT_HEADING) * 26) + 401, (sin(ECC_SHFT_HEADING) * 26) + 417, 0.0);
        glRotatef((-ECC_SHFT_I/3), 0.0, 0.0, 1.0);
        glScalef(60.0, 60.0, 1.0);
        inner_gear(5);
    glPopMatrix();
    glLineWidth(1.0);

    // HOUSING
    glColor3f(0.0, 0.0, 0.08);
    housing();

    // SPARK PLUGS
    glPushMatrix();
        glColor3f(0.0, 0.0, 0.09);
        glTranslatef(530.0, 445.0, 0.0);
        spark_plug(0);
        glColor3f(0.0, 0.0, 0.09);
        glTranslatef(0.0, -64.0, 0.0);
        spark_plug(0);
    glPopMatrix();

   	glFlush ();
}


/****************************************************
 *                  check_pixel                     *
 ****************************************************
 * Uses the pixel colors gotten to query a hash     *
 * table to determine the name of the clicked       *
 * object                                           *
 * - returns: pointer to character string in hash   *
 *   table at given pixel, or NULL                  *
 ****************************************************/
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

    char *picked_color = ht_get(HT, rounded);
    
    return picked_color;
}


/****************************************************
 *                     mouse                        *
 ****************************************************
 * Used for aux buffer picking                      *
 ****************************************************/
void mouse (int button, int state, GLint x, GLint y)
{
	GLint wHt;
	wHt = glutGet(GLUT_WINDOW_HEIGHT);
	y = wHt - y;

	glReadBuffer(GL_AUX0);

    switch (button)
    {
        // SLIDER CONTROL
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN)
            {
                char *picked_color = check_pixel(x, y);
                if (picked_color != NULL)
                {
                    if (strcmp(picked_color, "Slider") == 0)
                    {
                        //printf("Name of clicked object: %s\n", picked_color);
                        SLIDER_TOGGLE = 1;
                    }
                }
            }
            if (state == GLUT_UP)
            {
                SLIDER_TOGGLE = 0;
            }
            break;
        // INFO SELECTION
        case GLUT_MIDDLE_BUTTON:
            if (state == GLUT_DOWN)
            {
                char *picked_color = check_pixel(x, y);
                if (picked_color != NULL)
                {
                    //printf("Name of clicked object: %s\n", picked_color);
                    if (strcmp(picked_color, "Intake") == 0)
                        INFO_SELECTION = 1;
                    if (strcmp(picked_color, "Exhaust") == 0)
                        INFO_SELECTION = 2;
                    if (strcmp(picked_color, "Chamber") == 0)
                        INFO_SELECTION = 3;
                    if (strcmp(picked_color, "Rotor") == 0)
                        INFO_SELECTION = 4;
                    if (strcmp(picked_color, "Eccentric Shaft") == 0)
                        INFO_SELECTION = 5;
                    if (strcmp(picked_color, "Pinion") == 0)
                        INFO_SELECTION = 6;
                    if (strcmp(picked_color, "Crown Gear") == 0)
                        INFO_SELECTION = 7;
                    if (strcmp(picked_color, "Stator Housing") == 0)
                        INFO_SELECTION = 8;
                    if (strcmp(picked_color, "Spark Plug") == 0)
                        INFO_SELECTION = 9;
                    glutPostRedisplay();
                }
                else
                {
                    INFO_SELECTION = 0;
                    glutPostRedisplay();
                }

            }
            break;
        default:
            break;
    }
}


/****************************************************
 *                  mouse_motion                    *
 ****************************************************
 * Allows the control of the animation speed        *
 ****************************************************/
void mouse_motion (int x, int y)
{
    if (SLIDER_TOGGLE == 1)
    {
        if (x >= 305 && x <= 495)
        {
            SLIDER_X = x - 5;
            
            // EXHAUST ANIMATION SPEED CONTROL
            INTAKE_EXHAUST_SPEED = (int)(SLIDER_X / 50 + 0.2 - 5);

            // ALL ROTATIONAL OBJECTS SPEED CONTROL
            if (x >= 495)
                ROTATION_SPEED = 21;
            else if (x > 475)
                ROTATION_SPEED = 18;
            else if (x > 450)
                ROTATION_SPEED = 15;
            else if (x > 425)
                ROTATION_SPEED = 12;
            else if (x > 400)
                ROTATION_SPEED = 9;
            else if (x > 375)
                ROTATION_SPEED = 6;
            else if (x > 350)
                ROTATION_SPEED = 5;
            else if (x > 325)
                ROTATION_SPEED = 4;
            else if (x < 325)
                ROTATION_SPEED = 3;

            glutPostRedisplay();
        }
        if (x > 495)
            SLIDER_X = 495;
        if (x < 305)
            SLIDER_X = 300;
    }
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
        SLIDER_X = 300;
        INTAKE_X = 178.0;
        EXHAUST_X = 198.0;
        INTAKE_EXHAUST_SPEED = 2;
        ECC_SHFT_I = 0;
        ROTATION_SPEED = 3;
        INFO_SELECTION = 0;
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
    // HASH TABLE GENERATION
    HT = ht_create();
    ht_set(HT, (GLfloat)0.00, "Slider");
    ht_set(HT, (GLfloat)0.01, "Intake");
    ht_set(HT, (GLfloat)0.02, "Exhaust");
    ht_set(HT, (GLfloat)0.03, "Chamber");
    ht_set(HT, (GLfloat)0.04, "Rotor");
    ht_set(HT, (GLfloat)0.05, "Eccentric Shaft");
    ht_set(HT, (GLfloat)0.06, "Pinion");
    ht_set(HT, (GLfloat)0.07, "Crown Gear");
    ht_set(HT, (GLfloat)0.08, "Stator Housing");
    ht_set(HT, (GLfloat)0.09, "Spark Plug");
    // output everything in hash table
    ht_dump(HT);

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
	glutMouseFunc (mouse);
	glutDisplayFunc (display);
    glutMotionFunc(mouse_motion);
    glutIdleFunc(idle);
	glutMainLoop ();
	return 0;
}
