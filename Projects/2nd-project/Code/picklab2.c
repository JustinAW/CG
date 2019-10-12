
/********************************************************
 *                                                      *
 *                         pick 2                       *
 *                                                      *
 ********************************************************/

/* Picking based on colors using back plane
*/


#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

static ht_t *ht;

static GLint SLIDER_X = 300;
int SLIDER_TOGGLE = 0;

struct {
    GLfloat pixel[4];
    char * name;
    GLint vertices[4][2];
}squares[3];

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);
	glShadeModel (GL_FLAT);
}

void reshape (int w, int h)
{
	if ( w > h)
      glViewport (0, 0, (GLfloat) h, (GLfloat) h);
	else
      glViewport (0, 0, (GLfloat) w, (GLfloat) w);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D (0.0, 600.0, 0.0, 600.0);
}

void mouse (int button, int state, GLint x, GLint y)
{
	GLfloat pixel[4];
	GLfloat r, g, b;
	GLint wHt;

	wHt = glutGet(GLUT_WINDOW_HEIGHT);
	y = wHt - y;
	glReadBuffer(GL_AUX1);
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)) 
    {
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
        if (picked_color != NULL)
        {
            printf("Name of clicked square: %s\n", picked_color);
            if (strcmp(picked_color, "Slider") == 0)
            {
                SLIDER_TOGGLE = 1;
            }
        }

	}
    if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_UP))
    {
        SLIDER_TOGGLE = 0;
    }
}

void display (void)
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f (1.0, 0.0, 0.0);

	glDrawBuffer (GL_FRONT);
	glClear (GL_COLOR_BUFFER_BIT);
	glBegin (GL_POLYGON);
        glVertex2s (10, 10);
        glVertex2s (20, 10);
        glVertex2s (20, 20);
        glVertex2s (10, 20);
	glEnd ();

	glBegin (GL_POLYGON);
        glVertex2s (80, 80);
        glVertex2s (110, 80);
        glVertex2s (110, 110);
        glVertex2s (80, 110);
	glEnd ();

    glColor3f (1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex2s (90, 90);
        glVertex2s (100, 90);
        glVertex2s (100, 100);
        glVertex2s (90, 100);
    glEnd();
    
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

   	glFlush ();

	glDrawBuffer (GL_AUX1);
	glClear (GL_COLOR_BUFFER_BIT);

	glColor3f (0.0, 0.0, 0.01);
	glBegin (GL_POLYGON);
        glVertex2s (10, 10);
        glVertex2s (20, 10);
        glVertex2s (20, 20);
        glVertex2s (10, 20);
	glEnd ();

	glColor3f (0.0, 0.0, 0.02);
	glBegin (GL_POLYGON);
        glVertex2s (80, 80);
        glVertex2s (110, 80);
        glVertex2s (110, 110);
        glVertex2s (80, 110);
	glEnd ();

    glColor3f (0.0, 0.0, 0.03);
    glBegin(GL_POLYGON);
        glVertex2s (90, 90);
        glVertex2s (100, 90);
        glVertex2s (100, 100);
        glVertex2s (90, 100);
    glEnd();

    glColor3f (0.0, 0.0, 0.04);
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

void mouse_motion (int x, int y)
{
    if (SLIDER_TOGGLE == 1)
    {
        if (x >= 305 && x <= 495)
        {
            SLIDER_X = x - 5;
            glutPostRedisplay();
        }
    }
}

int main (int argc, char** argv)
{
    ht = ht_create();

    ht_set(ht, (GLfloat)0.01, "Left");
    ht_set(ht, (GLfloat)0.02, "Right");
    ht_set(ht, (GLfloat)0.03, "Small");
    ht_set(ht, (GLfloat)0.04, "Slider");

    ht_dump(ht);

    glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize (600, 600);
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]);
	init ();

	glutReshapeFunc (reshape);
	glutMouseFunc (mouse);
	glutDisplayFunc (display);
    glutMotionFunc(mouse_motion);
	glutMainLoop ();
	return 0;
}
