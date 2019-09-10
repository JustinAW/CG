
/********************************************************
 *              OpenGL Primitives Lab                   *
 * Author: Justin Weigle                                *
 * Edited: 10 Sep, 2019                                 *
 ********************************************************/

#include <GL/glut.h>
#include <GL/freeglut.h>

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);
	glShadeModel (GL_FLAT);
}

void display (void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
    
    glColor3f (1.0, 0.0, 0.0);
    glPointSize (10.25);

    glBegin(GL_POINTS);
        glVertex3s (30, 30, 1);
        glVertex3s (50, 50, 1);
        glVertex3s (50, 30, 1);
    glEnd();

	glFlush ();
}

int main (int argc, char** argv)
{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize (450, 250);
	glutInitWindowPosition (0, 0);
	glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc (display);
	glViewport (0, 0, (GLsizei) 450, (GLsizei) 250);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D (0.0, (GLdouble) 450, 0.0, (GLdouble) 250);
	glutMainLoop ();
	return 0;
}

/* Code for CONCAVE FROM CONVEX part of lab:

	glBegin (GL_POLYGON);
	glVertex2s (0, 60);
	glVertex2s (26, 41);
	glVertex2s (32, 60);
	glEnd ();
	glBegin (GL_POLYGON);
	glVertex2s (16, 10);
	glVertex2s (42, 29);
	glVertex2s (26, 41);
	glEnd ();
	glBegin (GL_POLYGON);
	glVertex2s (68, 10);
	glVertex2s (59, 41);
	glVertex2s (42, 29);
	glEnd ();
	glBegin (GL_POLYGON);
	glVertex2s (84, 60);
	glVertex2s (52, 60);
	glVertex2s (59, 41);
	glEnd ();
	glBegin (GL_POLYGON);
	glVertex2s (42, 90);
	glVertex2s (32, 60);
	glVertex2s (52, 60);
	glEnd ();
*/
