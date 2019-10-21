
/* Draws an arrow canted at 45 degrees
*/



#include <GL/glut.h>


void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);
	glShadeModel (GL_FLAT);
}

void arrow ()
{

	glBegin(GL_LINE_LOOP);
		glVertex2i(8, 2);
		glVertex2i(32, 26);
		glVertex2i(38, 20);
		glVertex2i(38, 38);
		glVertex2i(20, 38);
		glVertex2i(26, 32);
		glVertex2i(2, 8);
	glEnd();
}



void display (void)
{

	glClear (GL_COLOR_BUFFER_BIT);
	glLineWidth(3);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f (1.0, 0.0, 0.0);


    for (int i = 0; i < 4; i++)
    {
        glMatrixMode (GL_PROJECTION);
        glLoadIdentity ();
        if (i == 0)
            gluOrtho2D (0.0, 40.0, 0.0, 40.0);
        if (i == 1)
            gluOrtho2D (40.0, 0.0, 0.0, 40.0);
        if (i == 2)
            gluOrtho2D (0.0, 40.0, 40.0, 0.0);
        if (i == 3)
            gluOrtho2D (40.0, 0.0, 40.0, 0.0);

        glViewport(i*50, 0, i*50 + 50, 50);
        arrow();
    }

   	glFlush ();
}

int main (int argc, char** argv)
{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize (400, 400);
	glutInitWindowPosition (0, 0);
	glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc (display);
	glutMainLoop ();
	return 0;
}