#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "drawfunctions.h"

// Hash table
static ht_t *HT;

// Animation
static clock_t TIME, RESET_TIME, ANIM_TIME = 0;
static GLfloat SPEED = -1.0;
static GLfloat FPS = 30.0;
static GLint RUN_ANIMATION = 0;
static GLfloat INTAKE_X = 198.0;
static GLfloat EXHAUST_X = 198.0;
static GLfloat ECC_SHFT_I = 0.0;
static GLfloat ECC_SHFT_HEADING;
static GLfloat ROTOR_ROTATION = -3.0 * 4.0;
static GLint ROTATION_SPEED = 3;

// Interaction
static GLint SLIDER_X = 300;
static GLint SLIDER_G = 363;
static GLint SLIDER_Y = 426;
static GLint SLIDER_O = 489;
static GLint SLIDER_TOGGLE = 0;
static GLint INTAKE_EXHAUST_SPEED = 2;

static GLfloat MAX_REV_LIM_TIME = 10.0;
static GLint BANG_TOGGLE = 1;


void init (void)
{
    glEnableClientState(GL_VERTEX_ARRAY);
    //glEnableClientState(GL_COLOR_ARRAY);

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
	glColor3f(1.0, 0.0, 0.0);

	glDrawBuffer(GL_BACK);
	glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0);
    slider(SLIDER_X, 1);

    if (SLIDER_X < SLIDER_G)
        glColor3f(0.0, 1.0, 0.0);
    else if (SLIDER_X < SLIDER_Y)
        glColor3f(0.9, 0.9, 0.0);
    else if (SLIDER_X < SLIDER_O)
        glColor3f(1.0, 0.5, 0.0);
    else
        glColor3f(1.0, 0.0, 0.0);
    slider(SLIDER_X, 2);

    glPushMatrix();
        glColor3f(0.88, 0.88, 1.0);
        glTranslatef(INTAKE_X, 494.0, 0.0);
        intake_exhaust();
    glPopMatrix();

    glPushMatrix();
        glColor3f(1.0, 0.88, 0.88);
        glTranslatef(EXHAUST_X, 341.0, 0.0);
        intake_exhaust();
    glPopMatrix();

    //glColor3f(0.5, 0.5, 1.0);
    //chambers();

    ECC_SHFT_HEADING = -ECC_SHFT_I * 3.1415926535897932384626433832795 / 180.0;
    glPushMatrix();
        glColor3f(0.0, 0.88, 0.88);
        glTranslatef((cos(ECC_SHFT_HEADING) * 26) + 405, (sin(ECC_SHFT_HEADING) * 26) + 417, 0.0);
        glRotatef(-ROTOR_ROTATION, 0.0, 0.0, 1.0);
        rotor();
    glPopMatrix();

    glColor3f(0.0, 0.0, 0.0);
    housing();

    /*
    glPushMatrix();
        glTranslatef(40.0, 40.0, 0.0);
        glScalef(0.9, 0.9, 1.0);
        housing();
    glPopMatrix();
    */

    glutSwapBuffers();
   	glFlush ();

    // AUX0 BUFFER picking
	glDrawBuffer (GL_AUX0);
	glClear (GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.00);
    slider(SLIDER_X, 2);

    glPushMatrix();
        glColor3f(0.0, 0.0, 0.01);
        glTranslatef(INTAKE_X, 494.0, 0.0);
        intake_exhaust();
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.0, 0.0, 0.02);
        glTranslatef(EXHAUST_X, 341.0, 0.0);
        intake_exhaust();
    glPopMatrix();

    glColor3f(0.0, 0.0, 0.03);
    chambers();

    ECC_SHFT_HEADING = -ECC_SHFT_I * 3.1415926535897932384626433832795 / 180.0;
    glPushMatrix();
        glColor3f(0.0, 0.0, 0.04);
        glTranslatef((cos(ECC_SHFT_HEADING) * 28) + 403, (sin(ECC_SHFT_HEADING) * 28) + 416, 0.0);
        glRotatef(-ROTOR_ROTATION, 0.0, 0.0, 1.0);
        rotor();
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

    char *picked_color = ht_get(HT, rounded);
    
    return picked_color;
}


void mouse (int button, int state, GLint x, GLint y)
{
	GLint wHt;
	wHt = glutGet(GLUT_WINDOW_HEIGHT);
	y = wHt - y;

	glReadBuffer(GL_AUX0);

    switch (button)
    {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN)
            {
                char *picked_color = check_pixel(x, y);
                if (picked_color != NULL)
                {
                    if (strcmp(picked_color, "Slider") == 0)
                    {
                        printf("Name of clicked object: %s\n", picked_color);
                        SLIDER_TOGGLE = 1;
                    }
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
                    // the screen with a short description
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
            INTAKE_EXHAUST_SPEED = (int)(SLIDER_X / 50 + 0.2 - 4);

            if (x >= 495)
                ROTATION_SPEED = 13;
            else if (x > 430)
                FPS = 60;
            else if (x > 400)
            {
                ROTATION_SPEED = 8;
            }
            else if (x > 320)
            {
                FPS = 30;
                ROTATION_SPEED = 6;
            }
            else if (x < 320)
                ROTATION_SPEED = 3;

            glutPostRedisplay();
        }
        if (x >= 495)
        {
            TIME = clock();
        }
    }
}


void idle (void)
{
    if (RUN_ANIMATION == 1)
    {
        ANIM_TIME = clock();
        if (ANIM_TIME > RESET_TIME)
        {
            RESET_TIME = RESET_TIME + (1.0/FPS) * CLOCKS_PER_SEC;
            if (INTAKE_X > 230)
                INTAKE_X = 198;
            INTAKE_X += INTAKE_EXHAUST_SPEED;
            if (EXHAUST_X < 166)
                EXHAUST_X = 198;
            EXHAUST_X -= INTAKE_EXHAUST_SPEED;
            ECC_SHFT_I += (ROTATION_SPEED * 3);
            if (ECC_SHFT_I > (360 - ROTATION_SPEED * 3))
                ECC_SHFT_I = 0;
            ROTOR_ROTATION += ROTATION_SPEED;
            if (ROTOR_ROTATION > (360 - ROTATION_SPEED))
            {
                ROTOR_ROTATION = 0;
            }
            glutPostRedisplay();
        }
    }
    if (SLIDER_X == 490)
    {
        clock_t time_diff = clock() - TIME;
        double seconds_passed = ((double)time_diff)/CLOCKS_PER_SEC;
        if (seconds_passed > MAX_REV_LIM_TIME)
        {
            if (BANG_TOGGLE == 1)
            {
                RUN_ANIMATION = 0;
                printf("BANG\n");
                BANG_TOGGLE = 0;
            }
        }
    }
}


void menu_choice (int selection)
{
    if (selection == 1)
    {
        FPS = 30.0;
        RUN_ANIMATION = 0;
        SLIDER_X = 300;
        INTAKE_X = 198.0;
        EXHAUST_X = 198.0;
        INTAKE_EXHAUST_SPEED = 2;
        BANG_TOGGLE = 1;
        ECC_SHFT_I = 0;
        ROTOR_ROTATION = -3.0 * 4.0;
        ROTATION_SPEED = 3;
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


/*
 * Draws a given string starting at coords x,y using font
 */
void renderBitmapString(float x, float y, void *font, const char *string)
{
    const char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

// Set the font for drawing the title
const void *font = GLUT_BITMAP_TIMES_ROMAN_24;

/*
 * Draws ASKING ALEXANDRIA, the album title
 */
void draw_title()
{
    //renderBitmapString(290, 845, (void *)font, "A        S        K        I        N        G");
}


int main (int argc, char** argv)
{
    TIME, RESET_TIME, ANIM_TIME = clock();

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

    ht_dump(HT);

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
