
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

struct {
    GLfloat pixel[4];
    char * name;
    GLint vertices[4][2];
}squares[3];

void init (void)
{
    glDisable(GL_LIGHTING);
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
	gluOrtho2D (0.0, 10.0, 0.0, 10.0);
}

void mouse (int button, int state, GLint x, GLint y)
{
	GLfloat pixel[4];
	GLfloat r, g, b;
	int wHt;

	wHt = glutGet(GLUT_WINDOW_HEIGHT);
	y = wHt - y;
	glReadBuffer(GL_BACK);
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
        }
	}
}

void display (void)
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f (1.0, 0.0, 0.0);

	glDrawBuffer (GL_FRONT);
	glClear (GL_COLOR_BUFFER_BIT);
	glBegin (GL_POLYGON);
	glVertex2s (1, 1);
	glVertex2s (2, 1);
	glVertex2s (2, 2);
	glVertex2s (1, 2);
	glEnd ();

	glBegin (GL_POLYGON);
	glVertex2s (8, 8);
	glVertex2s (9, 8);
	glVertex2s (9, 9);
	glVertex2s (8, 9);
	glEnd ();
   	glFlush ();

	glDrawBuffer (GL_BACK);
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.01);
	glBegin (GL_POLYGON);
	glVertex2s (1, 1);
	glVertex2s (2, 1);
	glVertex2s (2, 2);
	glVertex2s (1, 2);
	glEnd ();

	glColor3f (0.0, 0.0, 0.02);
	glBegin (GL_POLYGON);
	glVertex2s (8, 8);
	glVertex2s (9, 8);
	glVertex2s (9, 9);
	glVertex2s (8, 9);
	glEnd ();

   	glFlush ();
}

int main (int argc, char** argv)
{
    ht = ht_create();

    ht_set(ht, (GLfloat)0.01, "Left");
    ht_set(ht, (GLfloat)0.02, "Right");

    ht_dump(ht);

    glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize (200, 200);
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]);
	init ();

	glutReshapeFunc (reshape);
	glutMouseFunc (mouse);
	glutDisplayFunc (display);
	glutMainLoop ();
	return 0;
}
