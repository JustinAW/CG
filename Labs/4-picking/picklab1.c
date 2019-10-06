
/********************************************************
 *                                                      *
 *                       picklab1                       *
 *                                                      *
 ********************************************************/

/* Manual picking based on manual 2D inverse mapping.  
*/


#include <GL/glut.h>
#include <stdio.h>

static int x1 = 40, y1 = 260;          //lower left corner of red rectangle
static int x2 = 140, y2 = 360;         //upper right corner of red rectangle
static int a1 = 260, b1 = 40;          //lower left corner of blue rectangle
static int a2 = 360, b2 = 140;         //upper right corner of blue rectangle
static float ppw = 400.0, pph = 400.0; //projection plane dimensions

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);
	glShadeModel (GL_FLAT);
}

void reshape (int w, int h)
{
    //glViewport (0, 0, 400, 400);
    if (w > h)
    {
        glViewport(0, 0, h, h);
    }
    else
    {
        glViewport(0, 0, w, w);
    }
    //glViewport(0, 0, h, h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D (0.0, ppw, 0.0, pph);
	glMatrixMode (GL_MODELVIEW);
	
}

void mouse (int button, int state, GLint x, GLint y)
{
//	y = 400 - y;
    GLint viewport[4];
    GLdouble mvmatrix[16], projmatrix[16];
    GLint ry, wh, ww;
    GLdouble wx, wy, wz;

	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)) {
        glGetIntegerv(GL_VIEWPORT, viewport);
        glGetDoublev(GL_MODELVIEW_MATRIX, mvmatrix);
        glGetDoublev(GL_PROJECTION_MATRIX, projmatrix);
        wh = glutGet(GLUT_WINDOW_HEIGHT);
        printf("Window height: %4d\n", wh);
        ww = glutGet(GLUT_WINDOW_WIDTH);
        printf("Window width: %4d\n", ww);

        //ry = viewport[3] - (GLint) y - 1;
        ry = wh - (GLint) y;
		printf("x = %4d, ry = %4d\n", x, ry);
        gluUnProject((GLdouble) x, (GLdouble) ry, 0.0, mvmatrix, projmatrix, viewport, &wx, &wy, &wz);
        printf("World coords at z = 0.0 are (%f, %f, %f)\n", wx, wy, wz);

        if (x1 < wx && wx < x2 && y1 < wy && wy < y2)
        {
            printf("red rectangle clicked\n");
        }
        if (a1 < wx && wx < a2 && b1 < wy && wy < b2)
        {
            printf("blue rectangle clicked\n");
        }
	}
}

void display (void)
{

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 0.0, 0.0);
	glBegin (GL_POLYGON);
	glVertex2i (x1, y1);
	glVertex2i (x2, y1);
	glVertex2i (x2, y2);
	glVertex2i (x1, y2);
	glEnd ();

	glColor3f (0.0, 0.0, 1.0);
	glBegin (GL_POLYGON);
	glVertex2i (a1, b1);
	glVertex2i (a2, b1);
	glVertex2i (a2, b2);
	glVertex2i (a1, b2);
	glEnd ();

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
	glutReshapeFunc (reshape);
	glutMouseFunc (mouse);
	glutDisplayFunc (display);
	glutMainLoop ();
	return 0;
}
/*
 *
	//***** picking code goes here *****
        if(x1 < x && x < x2 && y1 < y && y < y2)
        {
            printf("red rectangle clicked\n");
        }
        if(a1 < x && x < a2 && b1 < y && y < b2)
        {
            printf("blue rectangle clicked\n");
        }
        */
