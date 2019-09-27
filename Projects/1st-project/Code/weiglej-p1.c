
/********************************************************
 *                    Project 1                         *
 * Author: Justin Weigle                                *
 * Edited: 27 Sep, 2019                                 *
 * Submitted:                                           *
 ********************************************************/

#include <GL/glut.h>
#include <stdio.h>

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);
	glShadeModel (GL_SMOOTH);
}

/*
 * Draws the album art's background
 */
void draw_bg (void)
{
    static GLfloat vertexValues[] = {
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0,           //0
        0.0, 191.0, 0.0, 0.07, 0.05, 0.05,      //1
        350.0, 191.0, 0.0, 0.4, 0.0, 0.0,       //2
        350.0, 0.0, 0.0, 0.2, 0.0, 0.0,         //3
        350.0, 0.0, 0.0, 0.2, 0.0, 0.0,         //4
        350.0, 191.0, 0.0, 0.4, 0.0, 0.0,       //5
        918.0, 191.0, 0.0, 0.65, 0.13, 0.13,    //6
        918.0, 0.0, 0.0, 0.65, 0.13, 0.13,      //7
        0.0, 555.0, 0.0, 0.07, 0.05, 0.05,      //8
        459.0, 555.0, 0.0, 0.3, 0.05, 0.05,     //9
        459.0, 191.0, 0.0, 0.07, 0.05, 0.05,    //10
        918.0, 555.0, 0.0, 0.07, 0.05, 0.05,    //11
        918.0, 191.0, 0.0, 0.07, 0.05, 0.05,    //12
        0.0, 918.0, 0.0, 0.07, 0.05, 0.05,      //13
        459.0, 918.0, 0.0, 0.07, 0.05, 0.05,    //14
        918.0, 918.0, 0.0, 0.07, 0.05, 0.05,    //15
    };

    glVertexPointer(3, GL_FLOAT, 6*sizeof(GLfloat), &vertexValues[0]);
    glColorPointer(3, GL_FLOAT, 6*sizeof(GLfloat), &vertexValues[3]);

    //ORDER OF INDICES: BL, TL, TR, BR
    static GLubyte indices1[] = {0, 1, 2, 3};       //left bottom strip
    static GLubyte indices2[] = {4, 5, 6, 7};       //right bottom strip
    static GLubyte indices3[] = {1, 8, 9, 10};      //bottom left of top
    //ORDER OF INDICES: BR, TR, TL, BL
    static GLubyte indices4[] = {12, 11, 9, 10};    //bottom right of top
    //ORDER OF INDICES: TL, BL, BR, TR
    static GLubyte indices5[] = {13, 8, 9, 14};    //top left of top
    //ORDER OF INDICES: TR, BR, BL, TL
    static GLubyte indices6[] = {15, 11, 9, 14};    //top right of top
    
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, indices1);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, indices2);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, indices3);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, indices4);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, indices5);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, indices6);

}

void draw_shadows (void)
{
    static GLfloat vertexValues[] = {
        459.0, 549.0, 0.0, 0.3, 0.05, 0.05,     //0
        612.0, 443.0, 0.0, 0.3, 0.05, 0.05,     //1
        456.0, 334.0, 0.0, 0.3, 0.05, 0.05,     //2
        300.0, 442.0, 0.0, 0.3, 0.05, 0.05,     //3
        319.0, 400.0, 0.0, 0.3, 0.05, 0.05,     //4
        340.0, 352.0, 0.0, 0.3, 0.05, 0.05,     //5
        445.0, 310.0, 0.0, 0.3, 0.05, 0.05,     //6
        445.0, 198.0, 0.0, 0.3, 0.05, 0.05,     //7
        334.0, 198.0, 0.0, 0.3, 0.05, 0.05,     //8
        310.0, 272.0, 0.0, 0.3, 0.05, 0.05,     //9
    };

    glVertexPointer(3, GL_FLOAT, 6*sizeof(GLfloat), &vertexValues[0]);
    glColorPointer(3, GL_FLOAT, 6*sizeof(GLfloat), &vertexValues[3]);

    static GLubyte key[] = {0, 1, 2, 3};
    static GLubyte belowkeytri[] = {4, 5, 6};
    static GLubyte belowkeypent[] = {5, 6, 7, 8, 9};

    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, key);
    glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_BYTE, belowkeytri);
    glDrawElements(GL_POLYGON, 5, GL_UNSIGNED_BYTE, belowkeypent);
}

//All drawing starts on positive X-axis
void display (void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    // Draw the background first
    draw_bg();

    // Draw the highlights
    //draw_highlights();

    // Draw the shadows
    draw_shadows();

    glFlush ();
}

int main (int argc, char** argv)
{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize (920, 920);
	glutInitWindowPosition (0, 0);
	glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc (display);
	glViewport (0, 0, (GLsizei) 920, (GLsizei) 920);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D (0.0, (GLdouble) 920, 0.0, (GLdouble) 920);
	glutMainLoop ();
	return 0;
}
