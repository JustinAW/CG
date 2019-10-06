
/********************************************************
 *                                                      *
 *                         pick 2                       *
 *                                                      *
 ********************************************************/

/* Picking based on colors using back plane
*/


#include <GL/glut.h>
#include <stdio.h>

struct {
    GLfloat pixel[4];
    char * name;
    GLint vertices[4][2];
}squares[3];

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);
	glShadeModel (GL_FLAT);
}

void reshape (int w, int h)
{
	if ( w > h)
      glViewport (0, 0, (GLfloat) h, (GLfloat) h);
	else
      glViewport (0, 0, (GLfloat) w, (GLfloat) w);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D (0.0, 10.0, 0.0, 10.0);
}

void mouse (int button, int state, GLint x, GLint y)
{
	GLfloat pixel[4];
	GLfloat r, g, b;
	int wHt;

	wHt = glutGet(GLUT_WINDOW_HEIGHT);
	y = wHt - y;
	glReadBuffer(GL_BACK);
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)) 
    {
		glReadPixels(x, y, 1.0, 1.0, GL_RGBA, GL_FLOAT, &pixel);
		r = pixel[0]; g = pixel[1]; b = pixel[2];

        for(int sq = 0; sq < 3; sq++)
        {
            if (squares[sq].pixel[0] == r
                && squares[sq].pixel[1] == g
                && squares[sq].pixel[2] == b)
            {
                printf("Name of clicked square: %s\n", squares[sq].name);
            }
        }
	}
}

void display (void)
{

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f (1.0, 0.0, 0.0);

	glDrawBuffer (GL_FRONT);
	glClear (GL_COLOR_BUFFER_BIT);
	glBegin (GL_POLYGON);
	glVertex2s (1, 1);
	glVertex2s (2, 1);
	glVertex2s (2, 2);
	glVertex2s (1, 2);
	glEnd ();

	glBegin (GL_POLYGON);
	glVertex2s (8, 8);
	glVertex2s (9, 8);
	glVertex2s (9, 9);
	glVertex2s (8, 9);
	glEnd ();
   	glFlush ();

	glDrawBuffer (GL_BACK);
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 1.0, 0.0);
	glBegin (GL_POLYGON);
	glVertex2s (1, 1);
	glVertex2s (2, 1);
	glVertex2s (2, 2);
	glVertex2s (1, 2);
	glEnd ();

	glColor3f (0.0, 0.0, 1.0);
	glBegin (GL_POLYGON);
	glVertex2s (8, 8);
	glVertex2s (9, 8);
	glVertex2s (9, 9);
	glVertex2s (8, 9);
	glEnd ();

   	glFlush ();
}

int main (int argc, char** argv)
{
    glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize (200, 200);
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]);
	init ();

    squares[0].pixel[0] = 0.0;
    squares[0].pixel[1] = 1.0;
    squares[0].pixel[2] = 0.0;
    squares[0].name = "Charlie";
    squares[0].vertices[0][0] = 1;
    squares[0].vertices[0][1] = 1;
    squares[0].vertices[1][0] = 2;
    squares[0].vertices[1][1] = 1;
    squares[0].vertices[2][0] = 2;
    squares[0].vertices[2][1] = 2;
    squares[0].vertices[3][0] = 1;
    squares[0].vertices[3][1] = 2;

    squares[1].pixel[0] = 0.0;
    squares[1].pixel[1] = 0.0;
    squares[1].pixel[2] = 1.0;
    squares[1].name = "Dexter";
    squares[1].vertices[0][0] = 8;
    squares[1].vertices[0][1] = 8;
    squares[1].vertices[1][0] = 9;
    squares[1].vertices[1][1] = 8;
    squares[1].vertices[2][0] = 9;
    squares[1].vertices[2][1] = 9;
    squares[1].vertices[3][0] = 8;
    squares[1].vertices[3][1] = 9;

	glutReshapeFunc (reshape);
	glutMouseFunc (mouse);
	glutDisplayFunc (display);
	glutMainLoop ();
	return 0;
}
