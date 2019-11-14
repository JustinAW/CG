
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include<GL/glut.h>


/*******************************************************************
 *                                                                 *
 *                               FOG                               *
 *                                                                 *
 *******************************************************************/


void init (void);
void reshape (int, int);
void display(void);

GLfloat L0posn[] = {100.0, 100.0, 100.0, 1.0};

GLfloat LMAmb[3] = {0.0f, 0.0f, 0.0f};

GLfloat L0Amb[3] = {0.8f, 0.8f, 0.8f};
GLfloat L0Dif[3] = {0.8f, 0.8f, 0.8f};
GLfloat L0Spc[3] = {0.7f, 0.7f, 0.7f};

GLfloat M1Amb[3] = {0.3f, 0.5f, 0.7f};
GLfloat M1Dif[3] = {0.3f, 0.5f, 0.7f};
GLfloat M1Spc[3] = {0.9f, 0.1f, 0.1f};

GLfloat M2Amb[3] = {0.3f, 0.1f, 0.1f};
GLfloat M2Dif[3] = {0.3f, 0.1f, 0.1f};
GLfloat M2Spc[3] = {0.9f, 0.3f, 0.4f};

GLfloat M3Amb[3] = {0.3f, 0.3f, 0.3f};
GLfloat M3Dif[3] = {0.6f, 0.4f, 0.4f};
GLfloat M3Spc[3] = {0.3f, 0.5f, 0.2f};

int main (int argc, char** argv)
{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize (600, 400);
	glutInitWindowPosition (10, 10);
	glutCreateWindow ("Fog");
	init ();
	glutDisplayFunc (display);
	glutReshapeFunc(reshape);
	glutMainLoop ();
	return 0;
}

void init (void)
{

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, LMAmb);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);

	glLightfv(GL_LIGHT0, GL_AMBIENT, L0Amb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, L0Dif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, L0Spc);
	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.0);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.0);

	glClearColor (1.0, 1.0, 1.0, 0.0);
	glShadeModel (GL_SMOOTH);
	glPolygonMode(GL_FRONT, GL_FILL);
	glEnable(GL_NORMALIZE);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

}
	
void reshape (int w, int h)
{
	if (w > h)
		glViewport (0, 0, h, h);
	else
		glViewport (0, 0, w, w);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	glFrustum (-100.0, 100.0, -100.0, 100.0, 75.0, 400.0);
	//glMatrixMode (GL_MODELVIEW);
	//glLoadIdentity ();
	//gluLookAt(0.0, 0.0, 125.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void display (void)
{
	glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();
	gluLookAt(100.0, 100.0, 100.0, 20.0, 0.0, -100.0, 0.0, 1.0, 0.0);

	glLightfv(GL_LIGHT0, GL_POSITION, L0posn);
	glPushMatrix();
	glTranslatef(25.0, 0.0, 0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, M1Amb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, M1Dif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, M1Spc);
	glMaterialf(GL_FRONT, GL_SHININESS, 50);
	glutSolidSphere(40.0, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 50.0, -75.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, M2Amb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, M2Dif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, M2Spc);
	glMaterialf(GL_FRONT, GL_SHININESS, 200);
	glutSolidSphere(40.0, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(40.0, 20.0, -150.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, M3Amb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, M3Dif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, M3Spc);
	glMaterialf(GL_FRONT, GL_SHININESS, 100);
	glutSolidSphere(40.0, 25, 25);
	glPopMatrix();

	glFlush();
	glutSwapBuffers();
}

