
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
        000.0, 000.0, 0.0, 0.00, 0.00, 0.00,    //0
        000.0, 191.0, 0.0, 0.07, 0.05, 0.05,    //1
        350.0, 191.0, 0.0, 0.40, 0.00, 0.00,    //2
        350.0, 000.0, 0.0, 0.20, 0.00, 0.00,    //3
        350.0, 000.0, 0.0, 0.20, 0.00, 0.00,    //4
        350.0, 191.0, 0.0, 0.40, 0.00, 0.00,    //5
        918.0, 191.0, 0.0, 0.65, 0.13, 0.13,    //6
        918.0, 000.0, 0.0, 0.65, 0.13, 0.13,    //7
        000.0, 555.0, 0.0, 0.07, 0.05, 0.05,    //8
        459.0, 555.0, 0.0, 0.30, 0.05, 0.05,    //9
        459.0, 191.0, 0.0, 0.07, 0.05, 0.05,    //10
        918.0, 555.0, 0.0, 0.07, 0.05, 0.05,    //11
        918.0, 191.0, 0.0, 0.07, 0.05, 0.05,    //12
        000.0, 918.0, 0.0, 0.07, 0.05, 0.05,    //13
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
        458.0, 332.0, 0.0, 0.25, 0.05, 0.05,    //2
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
        232.0, 758.0, 0.0, 0.22, 0.08, 0.08,    //27
        419.0, 756.0, 0.0, 0.22, 0.08, 0.08,    //28
        426.0, 635.0, 0.0, 0.22, 0.08, 0.08,    //29
        459.0, 565.0, 0.0, 0.22, 0.08, 0.08,    //30
        480.0, 635.0, 0.0, 0.22, 0.08, 0.08,    //31
        488.0, 756.0, 0.0, 0.22, 0.08, 0.08,    //32
        542.0, 595.0, 0.0, 0.22, 0.08, 0.08,    //33
        539.0, 549.0, 0.0, 0.22, 0.08, 0.08,    //34
        495.0, 539.0, 0.0, 0.22, 0.08, 0.08,    //35
        648.0, 510.0, 0.0, 0.22, 0.08, 0.08,    //36
        656.0, 528.0, 0.0, 0.22, 0.08, 0.08,    //37
        624.0, 450.0, 0.0, 0.22, 0.08, 0.08,    //38
        694.0, 498.0, 0.0, 0.22, 0.08, 0.08,    //39
        674.0, 554.0, 0.0, 0.22, 0.08, 0.08,    //40
        618.0, 756.0, 0.0, 0.22, 0.08, 0.08,    //41
        682.0, 756.0, 0.0, 0.22, 0.08, 0.08,    //42
        741.0, 647.0, 0.0, 0.22, 0.08, 0.08,    //43
        686.0, 572.0, 0.0, 0.22, 0.08, 0.08,    //44
        714.0, 499.0, 0.0, 0.22, 0.08, 0.08,    //45
        829.0, 378.0, 0.0, 0.22, 0.08, 0.08,    //46
        806.0, 537.0, 0.0, 0.22, 0.08, 0.08,    //47
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
    static GLubyte topcent[] = {28, 29, 30, 31, 32};
    static GLubyte rtoppent[] = {30, 31, 33, 34, 35};
    static GLubyte rtopquad[] = {33, 34, 36, 37};
    static GLubyte rtoptri[] = {38, 39, 40};
    static GLubyte rquad[] = {41, 42, 43, 44};
    static GLubyte rpent[] = {43, 44, 45, 46, 47};

    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, key);
    glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_BYTE, belowkeytri);
    glDrawElements(GL_POLYGON, 5, GL_UNSIGNED_BYTE, belowkeypent);
    glDrawElements(GL_POLYGON, 5, GL_UNSIGNED_BYTE, base);
    glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_BYTE, smlefttri);
    glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_BYTE, lglefttri);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, ltopl);
    glDrawElements(GL_POLYGON, 5, GL_UNSIGNED_BYTE, ltoppent);
    glDrawElements(GL_POLYGON, 5, GL_UNSIGNED_BYTE, topcent);
    glDrawElements(GL_POLYGON, 5, GL_UNSIGNED_BYTE, rtoppent);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, rtopquad);
    glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_BYTE, rtoptri);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, rquad);
    glDrawElements(GL_POLYGON, 5, GL_UNSIGNED_BYTE, rpent);

    glLineWidth(7.0);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, belowkeyline);
    glLineWidth(13.0);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, lbaseline);
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
