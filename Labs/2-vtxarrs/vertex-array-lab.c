
/********************************************************
 *            OpenGL Vertex Arrays Lab                  *
 *                      Lab 2                           *
 * Author: Justin Weigle                                *
 * Edited: 19 Sep, 2019                                 *
 * Submitted: 21 Sep, 2019                              *
 ********************************************************/

/* Creates a six-sided cylinder using quads and hexagons
*/


#include <GL/glut.h>
#include <stdio.h>

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);
	glShadeModel (GL_SMOOTH);
}

//All drawing starts on positive X-axis
void display (void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    static GLfloat vertexValues[] = {
        100.0, 150.0, 0.0, 1.0, 1.0, 0.0,       //0
        100.0, 50.0, 0.0, 0.0, 1.0, 0.0,        //1
        50.0, 50.0, 0.0, 1.0, 0.0, 0.0,         //2
        50.0, 150.0, 0.0, 0.0, 0.0, 1.0,        //3
        150.0, 50.0, 0.0, 1.0, 0.0, 0.0,        //4
        150.0, 150.0, 0.0, 0.0, 0.0, 1.0,       //5
        200.0, 150.0, 0.0, 1.0, 1.0, 0.0,       //6
        200.0, 50.0, 0.0, 0.0, 1.0, 0.0,        //7
        250.0, 50.0, 0.0, 1.0, 0.0, 0.0,        //8
        250.0, 150.0, 0.0, 0.0, 0.0, 1.0        //9
        };

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 6*sizeof(GLfloat), &vertexValues[0]);
    glColorPointer(3, GL_FLOAT, 6*sizeof(GLfloat), &vertexValues[3]);

    static GLubyte indices1[] = {0,1,2,3};
    static GLubyte indices2[] = {0,1,4,5};
    static GLubyte indices3[] = {6,7,4,5};
    static GLubyte indices4[] = {8,9,6,7};

    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, indices1);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, indices2);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, indices3);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, indices4);

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
	gluOrtho2D (0.0, (GLdouble) 300, 0.0, (GLdouble) 200);
	glutMainLoop ();
	return 0;
}
/*
	//Draw panel1 (cw)
	glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 0.0);
	glVertex2f(100.0f, 150.0f);
        glColor3f(0.0, 1.0, 0.0);
	glVertex2f(100.0f, 50.0f);
        glColor3f(1.0, 0.0, 0.0);
	glVertex2f(50.0f, 50.0f);
        glColor3f(0.0, 0.0, 1.0);
	glVertex2f(50.0f, 150.0f);
	glEnd ();

	//Draw panel2 (ccw)
	glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 0.0);
	glVertex2f(100.0f, 150.0f);
        glColor3f(0.0, 1.0, 0.0);
	glVertex2f(100.0f, 50.0f);
        glColor3f(1.0, 0.0, 0.0);
	glVertex2f(150.0f, 50.0f);
        glColor3f(0.0, 0.0, 1.0);
	glVertex2f(150.0f, 150.0f);
	glEnd ();

	//Draw panel3 (cw)
	glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 0.0);
	glVertex2f(200.0f, 150.0f);
        glColor3f(0.0, 1.0, 0.0);
	glVertex2f(200.0f, 50.0f);
        glColor3f(1.0, 0.0, 0.0);
	glVertex2f(150.0f, 50.0f);
        glColor3f(0.0, 0.0, 1.0);
	glVertex2f(150.0f, 150.0f);
	glEnd ();

	//Draw panel4 (ccw)
	glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 0.0);
	glVertex2f(200.0f, 150.0f);
        glColor3f(0.0, 1.0, 0.0);
	glVertex2f(200.0f, 50.0f);
        glColor3f(1.0, 0.0, 0.0);
	glVertex2f(250.0f, 50.0f);
        glColor3f(0.0, 0.0, 1.0);
	glVertex2f(250.0f, 150.0f);
	glEnd ();

    // Problem 1 and 2
    static GLfloat vertices[] = {100.0, 150.0,  //0
                                100.0, 50.0,    //1
                                50.0, 50.0,     //2
                                50.0, 150.0,    //3
                                150.0, 50.0,    //4
                                150.0, 150.0,   //5
                                200.0, 150.0,   //6
                                200.0, 50.0,    //7
                                250.0, 50.0,    //8
                                250.0, 150.0    //9
                                };
    static GLfloat colors[] = {1.0, 1.0, 0.0,   //0
                                0.0, 1.0, 0.0,  //1
                                1.0, 0.0, 0.0,  //2
                                0.0, 0.0, 1.0,  //3
                                1.0, 0.0, 0.0,  //4
                                0.0, 0.0, 1.0,  //5
                                1.0, 1.0, 0.0,  //6
                                0.0, 1.0, 0.0,  //7
                                1.0, 0.0, 0.0,  //8
                                0.0, 0.0, 1.0   //9
                                };
    glVertexPointer(2, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);

    // Problem 1
    glBegin(GL_POLYGON);
        for(int i = 0; i < 4; i++) {
            glArrayElement(i);
        }
    glEnd();
    glBegin(GL_POLYGON);
        glArrayElement(0);
        glArrayElement(1);
        glArrayElement(4);
        glArrayElement(5);
    glEnd();
    glBegin(GL_POLYGON);
        glArrayElement(6);
        glArrayElement(7);
        glArrayElement(4);
        glArrayElement(5);
    glEnd();
    glBegin(GL_POLYGON);
        glArrayElement(8);
        glArrayElement(9);
        glArrayElement(6);
        glArrayElement(7);
    glEnd();

    // Problem 2 and 3
    static GLubyte indices1[] = {0,1,2,3};
    static GLubyte indices2[] = {0,1,4,5};
    static GLubyte indices3[] = {6,7,4,5};
    static GLubyte indices4[] = {8,9,6,7};

    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, indices1);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, indices2);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, indices3);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, indices4);
*/
