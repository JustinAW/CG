#include <GL/glut.h>

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);
	glShadeModel (GL_SMOOTH);
}

void unit_square (void)
{
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2s(0, 0);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2s(1, 0);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2s(1, 1);
        glColor3f(0.0, 1.0, 1.0);
        glVertex2s(0, 1);
    glEnd();
}

void unit_triangle (void)
{
    glBegin(GL_TRIANGLES);
        glVertex2s(0, 0);
        glVertex2s(1, 0);
        glVertex2s(1, 1);
    glEnd();
}

void display (void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
    
    glPushMatrix();
        glTranslatef(200.0, 200.0, 0.0);
        glScalef(100.0, 100.0, 1.0);
        unit_square();
    glPopMatrix();

	glFlush ();
}

int main (int argc, char** argv)
{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize (400, 400);
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc (display);
	glViewport (0, 0, (GLsizei) 400, (GLsizei) 400);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D (0.0, (GLdouble) 400, 0.0, (GLdouble) 400);
	glutMainLoop ();
	return 0;
}
