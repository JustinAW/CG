

/********************************************************
 *                                                      *
 *                      pyramid.c                       *
 *                                                      *
 ********************************************************/

/* Instance modeling lab: Robot from unit square.
   Right way to do it.
*/

#include <GL/glut.h>
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
}

void drawCap()
{
    glPushMatrix();
        glScalef(2.0, 2.0, 1.0);
        unitTriangle();
    glPopMatrix();
}

void drawBody()
{
	glPushMatrix();
        glTranslatef(5.0, 5.0, 0.0);    //move base over and up a bit
        glPushMatrix();
            glScalef(20.0, 2.0, 1.0);
            unitSquare();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(2.0, 2.0, 0.0);    // next tier, translate from base
            glPushMatrix();
                glScalef(16.0, 2.0, 1.0);
                unitSquare();
            glPopMatrix();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(4.0, 4.0, 0.0);    // next tier
            glPushMatrix();
                glScalef(12.0, 2.0, 1.0);
                unitSquare();
            glPopMatrix();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(6.0, 6.0, 0.0);    // next tier
            glPushMatrix();
                glScalef(8.0, 2.0, 1.0);
                unitSquare();
            glPopMatrix();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(8.0, 8.0, 0.0);    // next tier
            glPushMatrix();
                glScalef(4.0, 2.0, 1.0);
                unitSquare();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

void drawPyramid ()
{
    glPushMatrix();
        glTranslatef(14.0, 15.0, 0.0);
        drawCap();
    glPopMatrix();
    drawBody();
}

void reshape (int w, int h)
{
	if (w > h)
	  glViewport (0, 0, (GLsizei) h, (GLsizei) h);
	else
	  glViewport (0, 0, (GLsizei) w, (GLsizei) w);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D (0.0, 50.0, 0.0, 40.0);
}

void display (void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();
	glColor3f(1.0, 0.0, 0.0);
	drawPyramid();
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
