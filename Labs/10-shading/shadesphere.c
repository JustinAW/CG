
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include<GL/glut.h>

#define W 0.816497
#define X 0.942809
#define Y 0.471405
#define Z 0.333333

int RECUR = 5;

GLdouble vdata[4][3] = {{0.0, 0.0, 1.0}, {0.0, X, -Z},{-W, -Y, -Z},{W, -Y,  -Z}};
GLuint tindices[4][3] = {{0, 1, 2}, {3, 2, 1}, {0, 3, 1}, {0, 2, 3}};

void init (void)
{
	//Put arrays for the sphere's properties here
	
	//Put arrays for the light's properties here

	glClearColor (1.0, 1.0, 1.0, 0.0);
	glShadeModel (GL_FLAT);
        glEnable(GL_DEPTH_TEST);

	//enable lighting factors here

	//Set light properties here

	//Set sphere properties here

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

}
	

void reshape (int w, int h)
{
	if (w > h)
		glViewport (0, 0, h, h);
	else
		glViewport (0, 0, w, w);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	glFrustum (-25.0, 25.0, -25.0, 25.0, 95.0, 200.0);
}

void DrawTriangle (GLdouble *v1, GLdouble *v2, GLdouble *v3)
{
	glBegin(GL_TRIANGLES);
  	  glVertex3dv(v1);
	  glVertex3dv(v2);
	  glVertex3dv(v3);
	glEnd();
}

void normalize (GLdouble *v)
{
	GLdouble d = sqrt (v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
	
	v[0] /= d;
	v[1] /= d;
	v[2] /= d;
}

void subdivide (GLdouble *v1, GLdouble *v2, GLdouble *v3, long depth)
{
	GLdouble v12[3], v23[3], v31[3];
	GLint i;

	if (depth ==0) {
		DrawTriangle(v1, v2, v3);
		return;
	}
	else {
		for (i = 0; i < 3; i++){
			v12[i] = v1[i] + v2[i];
			v23[i] = v2[i] + v3[i];
			v31[i] = v3[i] + v1[i];
		}
		normalize (v12);
		normalize (v23);
		normalize (v31);
		subdivide (v1, v12, v31, depth - 1);
		subdivide (v2, v23, v12, depth - 1);
		subdivide (v3, v31, v23, depth - 1);
		subdivide (v12, v23, v31, depth - 1);
	}
}

void display (void)
{
	int i;

	glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();
	gluLookAt(0.0, 0.0, 125.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glScalef(25.0, 25.0, 25.0);
/*  Use this code for a self-generated sphere
	for (i = 0; i < 4; i++) {
		subdivide (&vdata[tindices[i][0]][0],
		           &vdata[tindices[i][1]][0],
		           &vdata[tindices[i][2]][0], RECUR);
	}

    OR

    Place a call to glutSolidSphere for a glut-generated sphere

*/
    glutSolidSphere(1, 20, 20);  //NOTE: scaling this instead of passing 25 as 1st parameter
	glFlush();
}

int main (int argc, char** argv)
{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize (400, 400);
	glutInitWindowPosition (100, 10);
	glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc (display);
	glutReshapeFunc(reshape);
	glutMainLoop ();
	return 0;
}
