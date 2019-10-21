
/* Creates clipped pentagon swirls 
*/



#include <GL/glut.h>
#include <math.h>
#include <time.h>

static float TWOPI = 2*3.1415f;
static int nSides = 5;       //how many sides poly has
static int nPolys = 60;      //how many polys to inscribe in circle
static float rInit = 1;      //initial radius
static float rInc = 0.5;     //radius increment

static clock_t RESET_TIME, TIME = 0;
static GLfloat FPS = 30.0;
static GLfloat ROTATION_SPEED = 2.0;
static GLfloat DEGREES = 0.0;


void init (void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glShadeModel(GL_FLAT);
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

	glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(1.0, 0.0, 0.0);


    for (int j = 0; j < 4; j++)
    {
        for (int k = 0; k < 4; k++)
        {
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            if ((j + k) % 2 == 0)
            {
                gluOrtho2D(0.0, 40.0, 0.0, 40.0);
            }
            else
                gluOrtho2D(40.0, 0.0, 0.0, 40.0);

            glViewport(j*100, k*100, 100, 100);

            glPushMatrix();
                glRotatef(DEGREES, 0.0, 0.0, 1.0);
                for (i = 0; i < nPolys; i++)
                    regPoly(rInit + i * rInc, 20, 20, i * offset);
            glPopMatrix();
        }
    }

   	glFlush ();

}


void idle (void)
{
    TIME = clock();
    if (TIME > RESET_TIME)
    {
        RESET_TIME = RESET_TIME + (1.0/FPS) * CLOCKS_PER_SEC;

        DEGREES += ROTATION_SPEED;
        if (DEGREES > 360)
        {
            DEGREES = 0;
        }
        glutPostRedisplay();
    }
}

int main (int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition (100, 100);
	glutCreateWindow(argv[0]);
	init();
    glutIdleFunc(idle);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
