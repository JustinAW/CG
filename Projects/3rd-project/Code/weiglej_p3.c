/****************************************************
 *                  Project 3                       *
 ****************************************************
 *  Author:     Justin Weigle                       *
 *  Edited:     05 Nov 2019                         *
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
static GLfloat INTAKE_X = -223.0;
static GLfloat EXHAUST_X = -203.0;
static GLfloat ECC_SHFT_I = 0.0;
static GLfloat ECC_SHFT_HEADING;
static GLint ROTATION_SPEED = 3;
static GLint INTAKE_EXHAUST_SPEED = 1;

// Interaction
static GLint RUN_ANIMATION = 0;

// Camera
static GLfloat CAM_X = 0;
static GLfloat CAM_Y = 0;
static GLfloat CAM_Z = 450;
static GLfloat ZOOM = 25;
static GLfloat DISTANCE;
static GLfloat CAM_HEADING;
static GLfloat CAM_I = 0.0;

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

    gluPerspective(75.0, 1.0, 5.0, 1000000000.0);

    glMatrixMode (GL_MODELVIEW);

    glLoadIdentity();
}


void draw_wankel (void)
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glLineWidth(2.0);
    glColor3f(0.0, 0.0, 0.0);

// BACK BUFFER drawing ========================================================
    glDrawBuffer(GL_BACK);
    glClear(GL_COLOR_BUFFER_BIT);

    // INTAKE
    glPushMatrix();
        glTranslatef(INTAKE_X, 77.0, 0.0);
        intake_exhaust();
    glPopMatrix();

    // EXHAUST
    glPushMatrix();
        glTranslatef(EXHAUST_X, -76.0, 0.0);
        intake_exhaust();
    glPopMatrix();

    // ROTOR
    ECC_SHFT_HEADING = -ECC_SHFT_I * 3.1415926535897932384626433832795 / 180.0;
    glPushMatrix();
        glTranslatef((cos(ECC_SHFT_HEADING) * 26), (sin(ECC_SHFT_HEADING) * 26), 0.0);
        glRotatef((-ECC_SHFT_I/3) + 30, 0.0, 0.0, 1.0);
        glScalef(1.65, 1.65, 1.0);
        rotor();
    glPopMatrix();

    // ECCENTRIC SHAFT
    glPushMatrix();
        glTranslatef((cos(ECC_SHFT_HEADING) * 26), (sin(ECC_SHFT_HEADING) * 26), 0.0);
        glScalef(52.0, 52.0, 1.0);
        glRotatef(-ECC_SHFT_I, 0.0, 0.0, 1.0);
        //eccentric_shaft();
    glPopMatrix();

    // PINION
    glPushMatrix();
        glScalef(30.0, 30.0, 1.0);
        outer_gear_outline(0.0);
        outer_gear_outline(-20.0);
        gear_teeth_outline(10, 0.0);
        gear_teeth_outline(10, -20.0);
    glPopMatrix();

    // CROWN GEAR
    glPushMatrix();
        glTranslatef((cos(ECC_SHFT_HEADING) * 26), (sin(ECC_SHFT_HEADING) * 26), 0.0);
        glRotatef((-ECC_SHFT_I/3), 0.0, 0.0, 1.0);
        glScalef(60.0, 60.0, 1.0);
        inner_gear_outline(0.0);
        inner_gear_outline(-20.0);
        gear_teeth_outline(5, 0.0);
        gear_teeth_outline(5, -20.0);
    glPopMatrix();

    // HOUSING
    housing();

    // SPARK PLUGS
    glPushMatrix();
        glTranslatef(129.0, 28.0, 0.0);
        spark_plug();
        if (RUN_ANIMATION == 1)
            if (0 < ECC_SHFT_I/3 && ECC_SHFT_I/3 < 10)
            {
                sparks();
            }
        glTranslatef(0.0, -64.0, 0.0);
        spark_plug();
        if (RUN_ANIMATION == 1)
            if (0 < ECC_SHFT_I/3 && ECC_SHFT_I/3 < 10)
            {
                sparks();
            }
    glPopMatrix();
}


void display (void)
{
    glPushMatrix();
        //gluLookAt(CAM_X - 300, CAM_Y, CAM_Z - 750, 450.0, 450.0, 0.0, 0.0, 1.0, 0.0);
        gluLookAt(CAM_X, CAM_Y, CAM_Z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
        draw_wankel();
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
            if (INTAKE_X > -191)
                INTAKE_X = -223;

            // EXHAUST
            EXHAUST_X -= INTAKE_EXHAUST_SPEED;
            if (EXHAUST_X < -235)
                EXHAUST_X = -203;

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
        INTAKE_X = -223.0;
        EXHAUST_X = -203.0;
        ECC_SHFT_I = 0;
        CAM_X = 0;
        CAM_Y = 0;
        CAM_Z = 450;
        CAM_I = 0.0;
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


void keyboard (unsigned char key, int x, int y)
{
    switch (key)
    {
        // ZOOM IN
        case 'E': case 'e':
            if ((CAM_X == 0.0) && (CAM_Y == 0.0) && (CAM_Z == 0.0))
            {
                printf("Camera is at center of model, zoom out\n");
            }
            else
            {
                if (CAM_X == 0.0)
                    NULL;
                else if (CAM_X < 0.0)
                    CAM_X += ZOOM;
                else if (CAM_X > 0.0)
                    CAM_X -= ZOOM;

                if (CAM_Y == 0.0)
                    NULL;
                else if (CAM_Y < 0.0)
                    CAM_Y += ZOOM;
                else if (CAM_Y > 450.0)
                    CAM_Y -= ZOOM;

                if (CAM_Z == 0.0)
                    NULL;
                else if (CAM_Z < 0.0)
                    CAM_Z += ZOOM;
                else if (CAM_Z > 0.0)
                    CAM_Z -= ZOOM;
            }
            glutPostRedisplay();
            break;
        // ZOOM OUT
        case 'Q': case 'q':
            if ((CAM_X == 0.0) && (CAM_Y == 0.0) && (CAM_Z == 0.0))
            {
                CAM_Z += ZOOM;
            }
            else
            {
                if (CAM_X == 0.0)
                    NULL;
                else if (CAM_X > 0.0)
                    CAM_X += ZOOM;
                else if (CAM_X < 0.0)
                    CAM_X -= ZOOM;

                if (CAM_Y == 0.0)
                    NULL;
                else if (CAM_Y > 0.0)
                    CAM_Y += ZOOM;
                else if (CAM_Y < 0.0)
                    CAM_Y -= ZOOM;

                if (CAM_Z == 0.0)
                    NULL;
                else if (CAM_Z >= 0.0)
                    CAM_Z += ZOOM;
                else if (CAM_Z < 0.0)
                    CAM_Z -= ZOOM;
            }
            glutPostRedisplay();
            break;
        // ROTATE CAMERA LEFT
        case 'A': case 'a':
            DISTANCE = sqrt(
                      pow((CAM_X - 0.0), 2)
                    + pow((CAM_Z - 0.0), 2)
                    );
            CAM_I += 15;
            if (CAM_I >= 360)
                CAM_I = 0;
            CAM_HEADING = CAM_I * M_PI / 180;
            CAM_X = cos(CAM_HEADING) * DISTANCE;
            CAM_Z = sin(CAM_HEADING) * DISTANCE;
            glutPostRedisplay();
            break;
        // ROTATE CAMERA RIGHT
        case 'D': case 'd':
            DISTANCE = sqrt(
                      pow((CAM_X - 0.0), 2)
                    + pow((CAM_Z - 0.0), 2)
                    );
            CAM_I -= 15;
            if (CAM_I <= 0)
                CAM_I = 360;
            CAM_HEADING = CAM_I * M_PI / 180;
            CAM_X = cos(CAM_HEADING) * DISTANCE;
            CAM_Z = sin(CAM_HEADING) * DISTANCE;
            glutPostRedisplay();
            break;
        // ROTATE CAMERA AROUND X CLOCKWISE
        case 'W': case 'w':
            DISTANCE = sqrt(
                      pow((CAM_Y - 0.0), 2)
                    + pow((CAM_Z - 0.0), 2)
                    );
            CAM_I -= 15;
            if (CAM_I <= 0)
                CAM_I = 360;
            CAM_HEADING = CAM_I * M_PI / 180;
            CAM_Y = cos(CAM_HEADING) * DISTANCE;
            CAM_Z = sin(CAM_HEADING) * DISTANCE;
            glutPostRedisplay();
            break;
        // ROTATE CAMERA AROUND X COUNTER CLOCKWISE
        case 'S': case 's':
            DISTANCE = sqrt(
                      pow((CAM_Y - 0.0), 2)
                    + pow((CAM_Z - 0.0), 2)
                    );
            CAM_I += 15;
            if (CAM_I >= 360)
                CAM_I = 0;
            CAM_HEADING = CAM_I * M_PI / 180;
            CAM_Y = cos(CAM_HEADING) * DISTANCE;
            CAM_Z = sin(CAM_HEADING) * DISTANCE;
            glutPostRedisplay();
            break;
        default:
            break;
    }
}


int main (int argc, char** argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
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
    glutKeyboardFunc (keyboard);
    glutIdleFunc(idle);
    glutMainLoop ();
    return 0;
}
