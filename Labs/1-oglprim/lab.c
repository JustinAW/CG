
/********************************************************
 *              OpenGL Primitives Lab                   *
 * Author: Justin Weigle                                *
 * Edited: 10 Sep, 2019                                 *
 ********************************************************/

#include <GL/glut.h>
//#include <GL/freeglut.h>

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
    glPointSize (4.25);

    glBegin(GL_POINTS);
        glVertex3s (3, 3, 1);
        glVertex3s (5, 5, 1);
        glVertex3s (5, 3, 1);
    glEnd();


    glBegin(GL_LINES);
        glVertex3s (91, 70, 1);
        glVertex3s (53, 42, 1);
        glVertex3s (25, 34, 1);
        glVertex3s (47, 76, 1);
        glVertex3s (39, 58, 1);
        glVertex3s (62, 81, 1);
        glVertex3s (191, 70, 1);
    glEnd();

    glBegin(GL_LINE_STRIP);
        glVertex3s (191, 70, 1);
        glVertex3s (153, 42, 1);
        glVertex3s (125, 34, 1);
        glVertex3s (147, 76, 1);
        glVertex3s (139, 58, 1);
        glVertex3s (162, 81, 1);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex3s (291, 70, 1);
        glVertex3s (253, 42, 1);
        glVertex3s (225, 34, 1);
        glVertex3s (247, 76, 1);
        glVertex3s (239, 58, 1);
        glVertex3s (262, 81, 1);
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
