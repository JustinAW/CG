
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
 * Draws the background
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
    static GLubyte ind1[] = {0, 1, 2, 3};       //left bottom strip
    static GLubyte ind2[] = {4, 5, 6, 7};       //right bottom strip
    static GLubyte ind3[] = {1, 8, 9, 10};      //bottom left of top
    //ORDER OF INDICES: BR, TR, TL, BL
    static GLubyte ind4[] = {12, 11, 9, 10};    //bottom right of top
    //ORDER OF INDICES: TL, BL, BR, TR
    static GLubyte ind5[] = {13, 8, 9, 14};    //top left of top
    //ORDER OF INDICES: TR, BR, BL, TL
    static GLubyte ind6[] = {15, 11, 9, 14};    //top right of top
    
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, ind1);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, ind2);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, ind3);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, ind4);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, ind5);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, ind6);

    /*
    static GLsizei count[] = {4, 4, 4, 4, 4, 4};
    static GLvoid * indices[6] = {ind1, ind2, ind3, ind4, ind5, ind6};
    
    glMultiDrawElements(GL_POLYGON, count, GL_UNSIGNED_BYTE, indices, 6);
    */
}

/*
 * Draws the shadowy parts
 */
void draw_shadows (void)
{
    static GLfloat vertexValues[] = {
        459.0, 549.0, 0.0, 0.27, 0.06, 0.06,    //0
        612.0, 443.0, 0.0, 0.30, 0.05, 0.05,    //1
        456.0, 334.0, 0.0, 0.25, 0.05, 0.05,    //2
        300.0, 442.0, 0.0, 0.27, 0.06, 0.06,    //3
        319.0, 400.0, 0.0, 0.30, 0.05, 0.05,    //4
        340.0, 352.0, 0.0, 0.30, 0.05, 0.05,    //5
        445.0, 310.0, 0.0, 0.30, 0.05, 0.05,    //6
        445.0, 198.0, 0.0, 0.20, 0.05, 0.05,    //7
        334.0, 198.0, 0.0, 0.20, 0.05, 0.05,    //8
        310.0, 272.0, 0.0, 0.30, 0.05, 0.05,    //9
        270.0, 388.0, 0.0, 0.30, 0.05, 0.05,    //10
        333.0, 191.0, 0.0, 0.40, 0.09, 0.09,    //11
        582.0, 191.0, 0.0, 0.55, 0.09, 0.08,    //12
        676.0, 138.0, 0.0, 0.34, 0.09, 0.08,    //13
        459.0, 97.00, 0.0, 0.20, 0.08, 0.08,    //14
        231.0, 134.0, 0.0, 0.20, 0.08, 0.08,    //15
        218.0, 150.0, 0.0, 0.20, 0.08, 0.08,    //16
        283.0, 325.0, 0.0, 0.22, 0.08, 0.08,    //17
        139.0, 276.0, 0.0, 0.22, 0.08, 0.08,    //18
        128.0, 395.0, 0.0, 0.22, 0.08, 0.08,    //19
        74.00, 379.0, 0.0, 0.22, 0.08, 0.08,    //20
        108.0, 526.0, 0.0, 0.22, 0.08, 0.08,    //21
        240.0, 426.0, 0.0, 0.22, 0.08, 0.08,    //22
        113.0, 538.0, 0.0, 0.22, 0.08, 0.08,    //23
        195.0, 478.0, 0.0, 0.22, 0.08, 0.08,    //24
        229.0, 559.0, 0.0, 0.22, 0.08, 0.08,    //25
        167.0, 642.0, 0.0, 0.22, 0.08, 0.08,    //26
    };

    glVertexPointer(3, GL_FLOAT, 6*sizeof(GLfloat), &vertexValues[0]);
    glColorPointer(3, GL_FLOAT, 6*sizeof(GLfloat), &vertexValues[3]);

    static GLubyte key[] = {0, 1, 2, 3};
    static GLubyte belowkeytri[] = {4, 5, 6};
    static GLubyte belowkeypent[] = {5, 6, 7, 8, 9};
    static GLubyte belowkeyline[] = {5, 10};
    static GLubyte base[] = {11, 12, 13, 14, 15};
    static GLubyte lbaseline[] = {16, 17};
    static GLubyte smlefttri[] = {18, 19, 20};
    static GLubyte lglefttri[] = {20, 21, 22};
    static GLubyte ltopl[] = {23, 24, 25, 26};
    static GLubyte ltoppent[] = {25, 26, 27, 28, 29};


    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, key);
    glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_BYTE, belowkeytri);
    glDrawElements(GL_POLYGON, 5, GL_UNSIGNED_BYTE, belowkeypent);
    glLineWidth(7.0);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, belowkeyline);
    
    glDrawElements(GL_POLYGON, 5, GL_UNSIGNED_BYTE, base);
    glLineWidth(13.0);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, lbaseline);
    glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_BYTE, smlefttri);
    glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_BYTE, lglefttri);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, ltopl);
}

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
	glutInitWindowSize (918, 918);
	glutInitWindowPosition (0, 0);
	glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc (display);
	glViewport (0, 0, (GLsizei) 918, (GLsizei) 918);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D (0.0, (GLdouble) 918, 0.0, (GLdouble) 918);
	glutMainLoop ();
	return 0;
}
