
/********************************************************
 *                                                      *
 *                       Viewport1.c                    *
 *                                                      *
 ********************************************************/

/* Using default viewport.  Window has same proportions as 
   projection plane 
*/

#include <GL\glut.h>

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);
	glShadeModel (GL_FLAT);
}

void display (void)
{
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D (0.0, 100.0, 0.0, 100.0);

	glClear (GL_COLOR_BUFFER_BIT);

	//viewport here
	//objects and attributes here


	glFlush ();
}

int main (int argc, char** argv)
{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize (200, 200);
	glutInitWindowPosition (300, 200);
	glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc (display);
	glutMainLoop ();
	return 0;
}
