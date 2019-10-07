

/********************************************************
 *                                                      *
 *                        robot1.c                      *
 *                                                      *
 ********************************************************/

/* Instance modeling lab: Robot from unit square.
   Wrong way to do it.
*/

#include <GL/glut.h>
#include <stdio.h>

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

void drawHead()
{
    glTranslatef(5.0, 5.0, 0.0);
	glLoadIdentity();
	glTranslatef(4.0, 26.0, 0.0);   //head  
	glScalef(6.0, 6.0, 1.0);
	unitSquare();
	glLoadIdentity();
	glTranslatef(5.0, 27.0, 0.0);   //mouth  
	glScalef(4.0, 1.0, 1.0);
	unitSquare();
	glLoadIdentity();
	glTranslatef(5.0, 30.0, 0.0);   //left eye
	unitSquare();
	glLoadIdentity();
	glTranslatef(8.0, 30.0, 0.0);   //right eye
	unitSquare();
	glLoadIdentity();
	glTranslatef(5.0, 27.0, 0.0);   //mouth  
	glScalef(4.0, 1.0, 1.0);
	unitSquare();
}

void drawBody()
{
	glLoadIdentity();
	glTranslatef(3.0, 0.0, 0.0);    //left leg  
	glScalef(2.0, 10.0, 1.0);
	unitSquare();
	glLoadIdentity();
	glTranslatef(9.0, 0.0, 0.0);   //right leg  
	glScalef(2.0, 10.0, 1.0);
	unitSquare();
	glLoadIdentity();
	glTranslatef(3.0, 10.0, 0.0);   //body 
	glScalef(8.0, 16.0, 1.0);
	unitSquare();
	glLoadIdentity();
	glTranslatef(1.0, 16.0, 0.0);   //left arm  
	glScalef(2.0, 10.0, 1.0);
	unitSquare();
	glLoadIdentity();
	glTranslatef(11.0, 16.0, 0.0);  //right arm  
	glScalef(2.0, 10.0, 1.0);
	unitSquare();
}

void drawRobot ()
{
	drawHead();
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
        //call to glTranslate
	glLoadIdentity ();
	glColor3f(1.0, 0.0, 0.0);
	drawRobot();
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
