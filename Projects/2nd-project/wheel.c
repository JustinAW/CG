

/********************************************************
 *                                                      *
 *                       wheel.c                        *
 *                                                      *
 ********************************************************/

/* Instance modeling lab: Robot from unit square.
   Right way to do it.
*/

#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

const int sides = 40;

void unitCircle (void)
{
    glBegin(GL_LINE_LOOP);
        double heading;
        for (int i = 0; i < 360; i += 360 / sides)
        {
            heading = i * 3.1415926535897932384626433832795 / 180;
            glVertex2d(cos(heading), sin(heading));
            //glVertex2d(cos(heading) * radius, sin(heading) * radius);
        }
    glEnd();
}

void drawSpoke (void)
{
    glBegin(GL_LINES);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0, 1.0);
    glEnd();
}

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);
}

void drawSpokes()
{
    for (float i = 0; i < 360; i += 45)
    {
        glPushMatrix();
            glRotatef(i, 0.0, 0.0, 1.0);
            glTranslatef(0.0, 1.0, 0.0);
            glScalef(1.0, 7.0, 0.0);
            drawSpoke();
        glPopMatrix();
    }
}

void drawCircles()
{
    glPushMatrix();
        glScalef(10.0, 10.0, 1.0);
        unitCircle();
    glPopMatrix();
    glPushMatrix();
        glScalef(8.0, 8.0, 1.0);
        unitCircle();
    glPopMatrix();
    glPushMatrix();
        glScalef(1.0, 1.0, 1.0);
        unitCircle();
    glPopMatrix();
}

void drawWheel ()
{
    drawCircles();
    drawSpokes();
}

void reshape (int w, int h)
{
	if (w > h)
	  glViewport (0, 0, (GLsizei) h, (GLsizei) h);
	else
	  glViewport (0, 0, (GLsizei) w, (GLsizei) w);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D (0.0, 50.0, 0.0, 50.0);
}

void display (void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();
	glColor3f(1.0, 0.0, 0.0);
    glTranslatef(22.0, 22.0, 0.0);
    glScalef(2.0, 2.0, 1.0);
    glLineWidth(2.0);
    drawWheel();
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
