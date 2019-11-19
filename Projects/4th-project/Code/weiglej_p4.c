/****************************************************
 *                  Project 4                       *
 ****************************************************
 *  Author:     Justin Weigle                       *
 *  Edited:     18 Nov 2019                         *
 ****************************************************
 * Draws the 3d animation of a Wankel rotary engine *
 * as well as a scene for the engine to be in.      *
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
static GLfloat ECC_SHFT_I = 0.0;
static GLfloat ECC_SHFT_HEADING;
static GLint ROTATION_SPEED = 3;

// Interaction
static GLint RUN_ANIMATION = 0;

// Camera
static GLfloat CAM_X = 0;
static GLfloat CAM_Y = 0;
static GLfloat CAM_Z = 500;
static GLfloat ZOOM = 25;
static GLfloat DISTANCE;
static GLfloat CAM_HEADING;
static GLfloat CAM_I = 90.0;

// Lights
//static GLfloat light0_position[] = {0, 0, 300, 1};
static GLfloat light0_position[] = {300.0, 0.0, 300.0, 1.0};
//static GLfloat light0_direction[] = {0, 0, -1};
static GLfloat light0_direction[] = {-1.0, 0.0, -1.0};

void init (void)
{
    glLoadIdentity();

    // Light Property Arrays
    GLfloat global_ambient[] = {0.2, 0.2, 0.2, 1.0};
        // LIGHT0 (Overhead light)
    GLfloat light0_ambient[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat light0_diffuse[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light0_specular[] = {0.3, 0.3, 0.3, 1.0};

    // Light Property Settings
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
        // LIGHT0 (Overhead light)
    glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);

    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_LIGHT0);

    glEnableClientState(GL_VERTEX_ARRAY);
    glClearColor(0.5, 0.5, 0.5, 0.0);
    glShadeModel(GL_SMOOTH);
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


/****************************************************
 *                  draw_wankel                     *
 ****************************************************
 * Draws the wankel engine internals in 3d with     *
 * animation                                        *
 ****************************************************/
void draw_wankel (void)
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glColor3f(0.0, 0.0, 0.0);

// BACK BUFFER drawing ========================================================
    glDrawBuffer(GL_BACK);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    // LIGHTS
    glPushMatrix();
        glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
        glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light0_direction);
        glLighti(GL_LIGHT0, GL_SPOT_EXPONENT, 10.0);
        glLighti(GL_LIGHT0, GL_SPOT_CUTOFF, 50.0);
    glPopMatrix();

    //light fixture
    glPushMatrix();
        glTranslatef(0, 300, 0);
        glScalef(20, 20, 20);
        unit_circle(0);
        x_unit_circle(0);
    glPopMatrix();

    // INTAKE
    glPushMatrix();
        glTranslatef(-160, 77.0, -30.0);
        intake_exhaust();
    glPopMatrix();

    // EXHAUST
    glPushMatrix();
        glTranslatef(-160, -77.0, -30.0);
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
        eccentric_shaft(ECC_SHFT_HEADING, ECC_SHFT_I);
    glPopMatrix();

    // PINION
    glPushMatrix();
        glScalef(30.0, 30.0, 1.0);
        x_disk_surface(30.0, 0.0, -20.0, 0.9);
        outer_gear_surface(0.0, 10);
        outer_gear_surface(-20.0, 10);
        gear_teeth_outline(10, 0);
    glPopMatrix();

    // CROWN GEAR
    glPushMatrix();
        glTranslatef((cos(ECC_SHFT_HEADING) * 26), (sin(ECC_SHFT_HEADING) * 26), 0.0);
        glRotatef((-ECC_SHFT_I/3), 0.0, 0.0, 1.0);
        glScalef(60.0, 60.0, 1.0);
        x_disk_surface(60.0, 0.0, -20.0, 1.3);
        inner_gear_surface(0.0, 5);
        inner_gear_surface(-20.0, 5);
        gear_teeth_outline(5, 1);
    glPopMatrix();

    // HOUSING
    housing();

    // SPARK PLUGS
    glPushMatrix();
        // top plug
        glTranslatef(129.0, 28.0, -30.0);
        spark_plug();
        if (RUN_ANIMATION == 1)
            if (0 < ECC_SHFT_I/3 && ECC_SHFT_I/3 < 10)
            {
                sparks();
            }

        // bottom plug
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
        ECC_SHFT_I = 0;
        CAM_X = 0;
        CAM_Y = 0;
        CAM_Z = 500;
        CAM_I = 90.0;
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


void light_control (int selection)
{
    // LIGHT 0
    if (selection == 1)
    {
        if(glIsEnabled(GL_LIGHT0))
            glDisable(GL_LIGHT0);
        else
            glEnable(GL_LIGHT0);
        glutPostRedisplay();
    }
}


GLfloat get_magnitude_cam (void)
{
    GLfloat m = sqrt(sq(CAM_X) + sq(CAM_Y) + sq(CAM_Z));
    return m;
}


/****************************************************
 *                  keyboard                        *
 ****************************************************
 * Used to control the camera                       *
 ****************************************************/
void keyboard (unsigned char key, int x, int y)
{
    GLfloat m = get_magnitude_cam();
    switch (key)
    {
        // ZOOM IN
        case 'E': case 'e':
            if ((CAM_X == 0.0) && (CAM_Y == 0.0) && (CAM_Z == 0.0))
            {
                printf("Camera is at center of model, zoom out\n");
                glutPostRedisplay();
                break;
            }
            CAM_X -= (CAM_X / m) * ZOOM;
            CAM_Y -= (CAM_Y / m) * ZOOM;
            CAM_Z -= (CAM_Z / m) * ZOOM;
            glutPostRedisplay();
            break;
        // ZOOM OUT
        case 'Q': case 'q':
            if ((CAM_X == 0.0) && (CAM_Y == 0.0) && (CAM_Z == 0.0))
            {
                CAM_X = 0.0;
                CAM_Y = 0.0;
                CAM_Z = 50.0;
                glutPostRedisplay();
                break;
            }
            CAM_X += (CAM_X / m) * ZOOM;
            CAM_Y += (CAM_Y / m) * ZOOM;
            CAM_Z += (CAM_Z / m) * ZOOM;
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

//    printf("OpenGL version: %s\n", glGetString(GL_VERSION));
    // make cursor visible during recording
    glutSetCursor(GLUT_CURSOR_LEFT_ARROW);

    // MENU CREATION
    int submenu = glutCreateMenu(toggle_animation);
    glutAddMenuEntry("Start Animation", 1);
    glutAddMenuEntry("Stop Animation", 2);
    int lightmenu = glutCreateMenu(light_control);
    glutAddMenuEntry("Toggle Light 0 (overhead)", 1);
    glutCreateMenu(menu_choice);
    glutAddSubMenu("Toggle Animation", submenu);
    glutAddSubMenu("Light Control", lightmenu);
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
