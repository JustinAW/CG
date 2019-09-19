
/********************************************************
 *            OpenGL Vertex Arrays Lab                  *
 *                      Lab 2                           *
 * Author: Justin Weigle                                *
 * Edited: 19 Sep, 2019                                 *
 * Submitted:                                           *
 ********************************************************/

/* Creates a six-sided cylinder using quads and hexagons
*/


#include <GL/glut.h>
#include <stdio.h>

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);
	glShadeModel (GL_SMOOTH);
}

//All drawing starts on positive X-axis
void display (void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glEnableClientState(GL_VERTEX_ARRAY);
    vertices = glVertexPointer()

	//Draw panel1 (cw)
	glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 0.0);
	glVertex2f(100.0f, 150.0f);
        glColor3f(0.0, 1.0, 0.0);
	glVertex2f(100.0f, 50.0f);
        glColor3f(1.0, 0.0, 0.0);
	glVertex2f(50.0f, 50.0f);
        glColor3f(0.0, 0.0, 1.0);
	glVertex2f(50.0f, 150.0f);
	glEnd ();

	//Draw panel2 (ccw)
	glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 0.0);
	glVertex2f(100.0f, 150.0f);
        glColor3f(0.0, 1.0, 0.0);
	glVertex2f(100.0f, 50.0f);
        glColor3f(1.0, 0.0, 0.0);
	glVertex2f(150.0f, 50.0f);
        glColor3f(0.0, 0.0, 1.0);
	glVertex2f(150.0f, 150.0f);
	glEnd ();

	//Draw panel3 (cw)
	glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 0.0);
	glVertex2f(200.0f, 150.0f);
        glColor3f(0.0, 1.0, 0.0);
	glVertex2f(200.0f, 50.0f);
        glColor3f(1.0, 0.0, 0.0);
	glVertex2f(150.0f, 50.0f);
        glColor3f(0.0, 0.0, 1.0);
	glVertex2f(150.0f, 150.0f);
	glEnd ();

	//Draw panel4 (ccw)
	glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 0.0);
	glVertex2f(200.0f, 150.0f);
        glColor3f(0.0, 1.0, 0.0);
	glVertex2f(200.0f, 50.0f);
        glColor3f(1.0, 0.0, 0.0);
	glVertex2f(250.0f, 50.0f);
        glColor3f(0.0, 0.0, 1.0);
	glVertex2f(250.0f, 150.0f);
	glEnd ();
	
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
	gluOrtho2D (0.0, (GLdouble) 300, 0.0, (GLdouble) 200);
	glutMainLoop ();
	return 0;
}
