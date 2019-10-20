
/* Creates clipped pentagon swirls 
*/



#include <GLUT/glut.h>
#include <math.h>

static float TWOPI = 2*3.1415f;
static int nSides = 5;       //how many sides poly has
static int nPolys = 60;      //how many polys to inscribe in circle
static float rInit = 1;      //initial radius
static float rInc = 0.5;     //radius increment

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);
	glShadeModel (GL_FLAT);
}

void regPoly (float r, int x, int y, float offset)
{
	float angleInc = TWOPI / nSides;
	int i;
	float xc, yc;
	float angle;

	glBegin(GL_POLYGON);
	for (i = 0; i < nSides; i++) {
		angle = i * angleInc + offset;
		xc = x + r * cos (angle);
		yc = x + r * sin (angle);
		glVertex2f(xc, yc);
	}
	glEnd();
}

void display (void)
{
	int i;
	float offset = TWOPI / nPolys;

	glClear (GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f (1.0, 0.0, 0.0);

	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D (0.0, 40.0, 0.0, 40.0);

	glViewport(10, 10, 100, 100);

	for (i = 0; i < nPolys; i++)
		regPoly(rInit + i * rInc, 20, 20, i * offset);

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
	glutMainLoop ();
	return 0;
}
