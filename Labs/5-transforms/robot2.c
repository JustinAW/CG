

/********************************************************
 *                                                      *
 *                        robot2.c                      *
 *                                                      *
 ********************************************************/

/* Instance modeling lab: Robot from unit square.
   Right way to do it.
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
	glPushMatrix();
 	  glScalef(6.0, 6.0, 1.0);        //head; scale only affects head
	  unitSquare();
	glPopMatrix();
	glPushMatrix();
	  glTranslatef(1.0, 1.0, 0.0);    //mouth; remember position
	  glPushMatrix();
	    glScalef(4.0, 1.0, 1.0);      //scale only affects mouth
	    unitSquare();
	  glPopMatrix();
	  glTranslatef(0.0, 3.0, 0.0);    //left eye; translate relative to mouth
	  unitSquare();
	  glTranslatef(3.0, 0.0, 0.0);    //right eye; translate relative to left eye
	  unitSquare();
	glPopMatrix();

}

void drawBody()
{
	glPushMatrix();
	  glTranslatef(2.0, 0.0, 0.0);    //left leg  
	  glPushMatrix();
	    glScalef(2.0, 10.0, 1.0);   //only affects leg  
	    unitSquare();
	  glPopMatrix();
	  glPushMatrix();
	    glTranslatef(6.0, 0.0, 0.0);  //right leg; translate relative to left leg 
	    glScalef(2.0, 10.0, 1.0);     
	    unitSquare();
	  glPopMatrix();
	  glTranslatef(0.0, 10.0, 0.0);   //body; translate relative to left leg 
	  glPushMatrix();
	    glScalef(8.0, 16.0, 1.0);     //only affects body     
	    unitSquare();
      glPopMatrix();
	  glTranslatef(0.0, 6.0, 0.0);    //translate both arms up relative to body  
	  glPushMatrix();
	    glTranslatef(-2.0, 0.0, 0.0); //left arm; translate left relative to body  
	    glScalef(2.0, 10.0, 1.0);
	    unitSquare();
      glPopMatrix();
	  glPushMatrix();
	    glTranslatef(8.0, 0.0, 0.0); //right arm; translate right relative to body  
	    glScalef(2.0, 10.0, 1.0);
	    unitSquare();
      glPopMatrix();
    glPopMatrix();
}

void drawRobot ()
{
	glPushMatrix();
	glTranslatef(3.0, 26.0, 0.0);
	  drawHead();
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
    glTranslatef(5.0, 3.0, 0.0);
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
