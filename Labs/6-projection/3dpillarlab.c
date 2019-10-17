

/********************************************************
 *                                                      *
 *                     3D Pillar.c                      *
 *                                                      *
 ********************************************************/

/* Example of using instance 3D modeling.  

  Creates a cylinder with a sphere resting on it.

  All wireframes.  See pillar.c for original.
*/

#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

const GLfloat CYLHT = 80.0;
const GLfloat CYLR = 5.0;
const GLfloat PLATHT = 1.0;
const GLfloat PLATL = 20.0;
const GLfloat BASEHT = 2.0;
const GLfloat BASEL = 20.0;
const GLfloat SPHR = 5.0;
const float TWOPI = 2 * 3.1415926535897932384626433832795f;

void CreateCylinder (GLfloat, GLfloat, GLint);
void init (void);
void reshape (int, int);
void display (void);
void mouse (int, int, int, int);

int main (int argc, char** argv)
{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize (400, 400);
	glutInitWindowPosition (0, 0);
	glutCreateWindow (argv[0]);
	glutReshapeFunc(reshape);
	init ();
	glutDisplayFunc (display);
    glutMouseFunc(mouse);
	glutMainLoop ();
	return 0;
}

void mouse (int button, int state, int x, int y)
{
    switch(button)
    {
        case GLUT_LEFT_BUTTON:
            if(state == GLUT_DOWN)
            {
                glutPostRedisplay();
            }
            break;
        default:
            break;
    }
}

// Creates a wireframe cylinder centered on origin and Z axis.  Ends not capped.
void CreateCylinder (GLfloat R, GLfloat L, GLint S)
{
	int i;
	double Increment = TWOPI / S;
	double Angle, X1, Y1, X2, Y2, HalfHt;

	HalfHt = L / 2.0;
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	X1 = R;
	Y1 = 0.0;
	for (i = 1; i < S - 1; i++) {
		Angle = i * Increment;
		X2 = R * cos(Angle); 
		Y2 = R * sin(Angle);
		glBegin(GL_POLYGON);
		glVertex3f(X1, Y1, HalfHt);
		glVertex3f(X2, Y2, HalfHt);
		glVertex3f(X2, Y2, -HalfHt);
		glVertex3f(X1, Y1, -HalfHt);
		glEnd();
		X1 = X2;
		Y1 = Y2;
	}
	X2 = R;
	Y2 = 0.0;
	glBegin(GL_POLYGON);
	glVertex3f(X1, Y1, HalfHt);
	glVertex3f(X2, Y2, HalfHt);
	glVertex3f(X2, Y2, -HalfHt);
	glVertex3f(X1, Y1, -HalfHt);
	glEnd();
	
}

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);
	glShadeModel(GL_FLAT);
}

void reshape (int w, int h)
{
    if (w > h)
        glViewport (0, 0, (GLsizei) h, (GLsizei) h);
    else
        glViewport (0, 0, (GLsizei) w, (GLsizei) w);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();

    //projection calls go here.  Be sure that view volume encompasses
    //scene.  View plane 5 units in front of camera
    //glOrtho (-50.0, 50.0, -50.0, 50.0, 5.0, 30.0);
    glFrustum (-50.0, 50.0, -50.0, 50.0, 5.0, 130.0);

    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity ();
}

void display (void)
{
    glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f (1.0, 0.0, 0.0);
    //Needs to be modified as move away from scene
    //Looking at the center of the pillar from 15 units in front of pillar
    //(20 units from its axis)
    // (eyex, eyey, eyez, centerx, centery, centerz, upx, upy, upz)
    glLoadIdentity();
//    gluLookAt(50.0, 46.0, 50.0, 0.0, 46.0, 0.0, 0.0, 1.0, 0.0);
    
    glRotatef (-45, 0.0, 1.0, 0.0);
    glTranslatef (-50.0, -46.0, -50.0);

    glTranslatef (0.0, 0.5 * BASEHT, 0.0);
    glPushMatrix ();
        glScalef (BASEL, BASEHT, BASEL);
        glutWireCube (1.0);
    glPopMatrix();
    glTranslatef (0.0, 0.5 * BASEHT + CYLHT / 2.0, 0.0);
    glPushMatrix();
        glRotatef(90.0, 1.0, 0.0, 0.0);
        CreateCylinder(CYLR, CYLHT, 10);
    glPopMatrix();
    glTranslatef (0.0, 0.5 * PLATHT + 0.5 * CYLHT, 0.0);
    glPushMatrix();
        glScalef (PLATL, PLATHT, PLATL);
        glutWireCube (1.0);
    glPopMatrix();
    glTranslatef(0.0, 0.5 * PLATHT + SPHR, 0.0);
    glRotatef(90, 1.0, 0.0, 0.0);
    glutWireSphere(SPHR, 10, 10);
    glFlush ();
}
