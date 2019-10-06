

/********************************************************
 *                                                      *
 *                         push.c                       *
 *                                                      *
 ********************************************************/

/* Instance modeling lab: Push and Pop.
*/

#include <GL\glut.h>
#include <stdio.h>

void unitTriangle ()
{
	glBegin(GL_POLYGON);
		glVertex2f(0.0, 0.0);
		glVertex2f(1.0, 0.0);
		glVertex2f(0.5, 0.866f);
	glEnd();
}

void unitSquare ()
{
	glBegin(GL_POLYGON);
		glVertex2f(0.0, 0.0);
		glVertex2f(1.0, 0.0);
		glVertex2f(1.0, 1.0);
		glVertex2f(0.0, 1.0);
	glEnd();
}

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D (0.0, 10.0, 0.0, 10.0);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();

}

void reshape (int w, int h)
{
	if (w > h)
	  glViewport (0, 0, (GLsizei) h, (GLsizei) h);
	else
	  glViewport (0, 0, (GLsizei) w, (GLsizei) w);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D (0.0, 10.0, 0.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void display (void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glColor3f (1.0, 0.0, 0.0);  //red square
	unitSquare();
	//glPushMatrix();
	glTranslatef (3.0, 2.0, 0.0);
	glColor3f (0.0, 1.0, 0.0);  //green triangle
	unitTriangle();
	glTranslatef (3.0, 2.0, 0.0);
	//glPopMatrix();
	glColor3f (0.0, 0.0, 1.0);  //blue square
	glScalef(0.5, 0.5, 1.0);
	unitSquare ();
	glFlush ();
}

int main (int argc, char** argv)
{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize (400, 400);
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]);
	glutReshapeFunc(reshape);
	init ();
	glutDisplayFunc (display);
	glutMainLoop ();
	return 0;
}
