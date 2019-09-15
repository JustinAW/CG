
/********************************************************
 *              OpenGL Primitives Lab                   *
 * Author: Justin Weigle                                *
 * Edited: 14 Sep, 2019                                 *
 ********************************************************/

#include <GL/glut.h>

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);
	glShadeModel (GL_FLAT);
}

void display (void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
    
    glColor3f (1.0, 0.0, 0.0);
    glPointSize (4.25);

/*
    glBegin(GL_POINTS);
        glVertex2s (3, 3);
        glVertex2s (5, 5);
        glVertex2s (5, 3);
    glEnd();

    glBegin(GL_LINES);
        glVertex2s (91, 70);
        glVertex2s (53, 42);
        glVertex2s (25, 34);
        glVertex2s (47, 76);
        glVertex2s (39, 58);
        glVertex2s (62, 81);
        glVertex2s (191, 70);
    glEnd();

    glBegin(GL_LINE_STRIP);
        glVertex2s (191, 70);
        glVertex2s (153, 42);
        glVertex2s (125, 34);
        glVertex2s (147, 76);
        glVertex2s (139, 58);
        glVertex2s (162, 81);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2s (291, 70);
        glVertex2s (253, 42);
        glVertex2s (225, 34);
        glVertex2s (247, 76);
        glVertex2s (239, 58);
        glVertex2s (262, 81);
    glEnd();

    glLineWidth(9.5);
    glBegin(GL_LINES);
        // Horizontal
        glVertex2s (10, 20);
        glVertex2s (110, 20);
        // Vertical
        glVertex2s (80, 100);
        glVertex2s (80, 200);
        // Fourty-Five
        glVertex2s (30, 30);
        glVertex2s (75, 75);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glVertex2s (10, 100);
        glVertex2s (10, 160);
        glVertex2s (40, 160);
        glVertex2s (80, 100);
        glVertex2s (40, 40);
        glVertex2s (10, 40);
        glVertex2s (75, 75);
//        glVertex2s (30, 30);
    glEnd();

    glBegin(GL_QUAD_STRIP);
        glVertex2s (10, 160);
        glVertex2s (40, 160);
        glVertex2s (10, 100);
        glVertex2s (40, 100);
        glVertex2s (10, 40);
        glVertex2s (40, 40);
        glVertex2s (10, 10);
        glVertex2s (40, 10);
    glEnd();


	glPolygonMode (GL_FRONT_AND_BACK, GL_POINT);
    glBegin(GL_TRIANGLES);
        glVertex2s (10, 100);
        glVertex2s (10, 160);
        glVertex2s (40, 160);
    glEnd();

	glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_TRIANGLES);
        glVertex2s (80, 100);
        glVertex2s (40, 40);
        glVertex2s (10, 40);
    glEnd();

	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUAD_STRIP);
        glVertex2s (100, 160);
        glVertex2s (400, 160);
        glVertex2s (100, 100);
        glVertex2s (400, 100);
    glEnd();


	glBegin (GL_POLYGON);
        glVertex2s (42, 90);
        glVertex2s (16, 10);
        glVertex2s (84, 60);
        glVertex2s (0, 60);
        glVertex2s (68, 10);
	glEnd ();

	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
	glBegin (GL_POLYGON);
        glVertex2s (142, 90);
        glVertex2s (116, 10);
        glVertex2s (184, 60);
        glVertex2s (100, 60);
        glVertex2s (168, 10);
	glEnd ();
*/

	glBegin (GL_POLYGON);
        glVertex2s (0, 60);
        glEdgeFlag(GL_FALSE);
        glVertex2s (26, 41);
        glEdgeFlag(GL_TRUE);
        glVertex2s (32, 60);
	glEnd ();
	glBegin (GL_POLYGON);
        glVertex2s (16, 10);
        glEdgeFlag(GL_FALSE);
        glVertex2s (42, 29);
        glEdgeFlag(GL_TRUE);
        glVertex2s (26, 41);
	glEnd ();
	glBegin (GL_POLYGON);
        glVertex2s (68, 10);
        glEdgeFlag(GL_FALSE);
        glVertex2s (59, 41);
        glEdgeFlag(GL_TRUE);
        glVertex2s (42, 29);
	glEnd ();
	glBegin (GL_POLYGON);
        glVertex2s (84, 60);
        glEdgeFlag(GL_FALSE);
        glVertex2s (52, 60);
        glEdgeFlag(GL_TRUE);
        glVertex2s (59, 41);
	glEnd ();
	glBegin (GL_POLYGON);
        glVertex2s (42, 90);
        glEdgeFlag(GL_FALSE);
        glVertex2s (32, 60);
        glEdgeFlag(GL_TRUE);
        glVertex2s (52, 60);
	glEnd ();

    glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
	glBegin (GL_POLYGON);
        glVertex2s (100, 60);
        glVertex2s (126, 41);
        glVertex2s (132, 60);
	glEnd ();
	glBegin (GL_POLYGON);
        glVertex2s (116, 10);
        glVertex2s (142, 29);
        glVertex2s (126, 41);
	glEnd ();
	glBegin (GL_POLYGON);
        glVertex2s (168, 10);
        glVertex2s (159, 41);
        glVertex2s (142, 29);
	glEnd ();
	glBegin (GL_POLYGON);
        glVertex2s (184, 60);
        glVertex2s (152, 60);
        glVertex2s (159, 41);
	glEnd ();
	glBegin (GL_POLYGON);
        glVertex2s (142, 90);
        glVertex2s (132, 60);
        glVertex2s (152, 60);
	glEnd ();

	glFlush ();
}

int main (int argc, char** argv)
{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize (450, 250);
	glutInitWindowPosition (0, 0);
	glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc (display);
	glViewport (0, 0, (GLsizei) 450, (GLsizei) 250);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D (0.0, (GLdouble) 450, 0.0, (GLdouble) 250);
	glutMainLoop ();
	return 0;
}

/* Code for CONCAVE FROM CONVEX part of lab:
	glBegin (GL_POLYGON);
        glVertex2s (0, 60);
        glVertex2s (26, 41);
        glVertex2s (32, 60);
	glEnd ();
	glBegin (GL_POLYGON);
        glVertex2s (16, 10);
        glVertex2s (42, 29);
        glVertex2s (26, 41);
	glEnd ();
	glBegin (GL_POLYGON);
        glVertex2s (68, 10);
        glVertex2s (59, 41);
        glVertex2s (42, 29);
	glEnd ();
	glBegin (GL_POLYGON);
        glVertex2s (84, 60);
        glVertex2s (52, 60);
        glVertex2s (59, 41);
	glEnd ();
	glBegin (GL_POLYGON);
        glVertex2s (42, 90);
        glVertex2s (32, 60);
        glVertex2s (52, 60);
	glEnd ();
*/
