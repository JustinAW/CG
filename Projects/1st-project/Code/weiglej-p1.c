
/********************************************************
 *                    Project 1                         *
 * Author: Justin Weigle                                *
 * Edited: 27 Sep, 2019                                 *
 * Submitted:                                           *
 ********************************************************/

#include <GL/glut.h>
#include <stdio.h>

// Suppress compiler warning about implicit declaration
void glMultiDrawElements(GLenum, const GLsizei *, GLenum, const GLvoid *, GLsizei);

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
        350.0, 191.0, 0.0, 0.30, 0.00, 0.00,    //2
        350.0, 000.0, 0.0, 0.20, 0.00, 0.00,    //3
        918.0, 191.0, 0.0, 0.65, 0.13, 0.13,    //4
        918.0, 000.0, 0.0, 0.65, 0.13, 0.13,    //5
        000.0, 555.0, 0.0, 0.07, 0.05, 0.05,    //6
        459.0, 555.0, 0.0, 0.30, 0.05, 0.05,    //7
        459.0, 191.0, 0.0, 0.07, 0.05, 0.05,    //8
        918.0, 555.0, 0.0, 0.07, 0.05, 0.05,    //9
        918.0, 191.0, 0.0, 0.07, 0.05, 0.05,    //10
        000.0, 918.0, 0.0, 0.07, 0.05, 0.05,    //11
        459.0, 918.0, 0.0, 0.07, 0.05, 0.05,    //12
        918.0, 918.0, 0.0, 0.07, 0.05, 0.05,    //13
    };

    glVertexPointer(3, GL_FLOAT, 6*sizeof(GLfloat), &vertexValues[0]);
    glColorPointer(3, GL_FLOAT, 6*sizeof(GLfloat), &vertexValues[3]);

    //ORDER OF INDICES: BL, TL, TR, BR
    static GLubyte ind1[] = {0, 1, 2, 3};       //left bottom strip
    static GLubyte ind2[] = {3, 2, 4, 5};       //right bottom strip
    static GLubyte ind3[] = {1, 6, 7, 8};       //bottom left of top
    //ORDER OF INDICES: BR, TR, TL, BL
    static GLubyte ind4[] = {10, 9, 7, 8};    //bottom right of top
    //ORDER OF INDICES: TL, BL, BR, TR
    static GLubyte ind5[] = {11, 6, 7, 12};    //top left of top
    //ORDER OF INDICES: TR, BR, BL, TL
    static GLubyte ind6[] = {13, 9, 7, 12};    //top right of top
    
    static GLsizei count[] = {4, 4, 4, 4, 4, 4};
    static GLvoid * indices[6] = {ind1, ind2, ind3, ind4, ind5, ind6};
    
    glMultiDrawElements(GL_POLYGON, count, GL_UNSIGNED_BYTE, indices, 6);
}

/*
 * Draws the shadowy parts
 */
void draw_shadows (void)
{
    static GLfloat vertexValues[] = {
        459.0, 549.0, 0.0, 0.27, 0.06, 0.06,    //0
        612.0, 443.0, 0.0, 0.30, 0.05, 0.05,    //1
        454.0, 328.0, 0.0, 0.25, 0.05, 0.05,    //2
        300.0, 442.0, 0.0, 0.27, 0.06, 0.06,    //3
        319.0, 420.0, 0.0, 0.30, 0.05, 0.05,    //4
        340.0, 352.0, 0.0, 0.30, 0.05, 0.05,    //5
        445.0, 315.0, 0.0, 0.30, 0.05, 0.05,    //6
        445.0, 198.0, 0.0, 0.20, 0.05, 0.05,    //7
        334.0, 198.0, 0.0, 0.20, 0.05, 0.05,    //8
        310.0, 272.0, 0.0, 0.30, 0.05, 0.05,    //9
        270.0, 388.0, 0.0, 0.30, 0.05, 0.05,    //10
        333.0, 191.0, 0.0, 0.40, 0.09, 0.09,    //11
        582.0, 191.0, 0.0, 0.55, 0.09, 0.08,    //12
        676.0, 138.0, 0.0, 0.34, 0.09, 0.08,    //13
        459.0, 97.00, 0.0, 0.20, 0.08, 0.08,    //14
        229.0, 134.0, 0.0, 0.20, 0.08, 0.08,    //15
        220.0, 147.0, 0.0, 0.20, 0.06, 0.06,    //16
        283.0, 325.0, 0.0, 0.22, 0.08, 0.08,    //17
        139.0, 276.0, 0.0, 0.12, 0.08, 0.08,    //18
        128.0, 395.0, 0.0, 0.16, 0.08, 0.08,    //19
        74.00, 379.0, 0.0, 0.16, 0.08, 0.08,    //20
        108.0, 526.0, 0.0, 0.18, 0.08, 0.08,    //21
        240.0, 426.0, 0.0, 0.16, 0.08, 0.08,    //22
        113.0, 538.0, 0.0, 0.15, 0.06, 0.06,    //23
        195.0, 478.0, 0.0, 0.20, 0.07, 0.07,    //24
        229.0, 551.0, 0.0, 0.20, 0.07, 0.07,    //25
        167.0, 642.0, 0.0, 0.16, 0.07, 0.08,    //26
        232.0, 758.0, 0.0, 0.13, 0.06, 0.06,    //27
        419.0, 756.0, 0.0, 0.28, 0.08, 0.07,    //28
        426.0, 635.0, 0.0, 0.32, 0.08, 0.08,    //29
        459.0, 562.0, 0.0, 0.29, 0.10, 0.10,    //30
        480.0, 635.0, 0.0, 0.22, 0.08, 0.08,    //31
        488.0, 756.0, 0.0, 0.32, 0.10, 0.10,    //32
        542.0, 595.0, 0.0, 0.26, 0.08, 0.08,    //33
        539.0, 549.0, 0.0, 0.26, 0.08, 0.08,    //34
        495.0, 539.0, 0.0, 0.22, 0.08, 0.08,    //35
        648.0, 510.0, 0.0, 0.32, 0.08, 0.08,    //36
        656.0, 528.0, 0.0, 0.32, 0.08, 0.08,    //37
        624.0, 450.0, 0.0, 0.32, 0.08, 0.08,    //38
        694.0, 498.0, 0.0, 0.32, 0.08, 0.08,    //39
        674.0, 554.0, 0.0, 0.35, 0.09, 0.07,    //40
        618.0, 756.0, 0.0, 0.22, 0.08, 0.07,    //41
        682.0, 756.0, 0.0, 0.22, 0.08, 0.08,    //42
        741.0, 647.0, 0.0, 0.25, 0.08, 0.07,    //43
        686.0, 572.0, 0.0, 0.32, 0.09, 0.08,    //44
        714.0, 499.0, 0.0, 0.22, 0.08, 0.08,    //45
        829.0, 378.0, 0.0, 0.16, 0.07, 0.07,    //46
        806.0, 537.0, 0.0, 0.22, 0.08, 0.08,    //47
        166.0, 643.0, 0.0, 0.13, 0.06, 0.06,    //48
        240.0, 551.0, 0.0, 0.22, 0.08, 0.07,    //49
        426.0, 630.0, 0.0, 0.28, 0.08, 0.08,    //50
        418.0, 758.0, 0.0, 0.22, 0.08, 0.07,    //51
        284.0, 443.0, 0.0, 0.23, 0.08, 0.08,    //52
        454.0, 621.0, 0.0, 0.23, 0.08, 0.08,    //53
        568.0, 756.0, 0.0, 0.25, 0.08, 0.08,    //54
        560.0, 603.0, 0.0, 0.28, 0.08, 0.08,    //55
        676.0, 551.0, 0.0, 0.35, 0.08, 0.08,    //56
        536.0, 552.0, 0.0, 0.25, 0.08, 0.08,    //57
        540.0, 505.0, 0.0, 0.26, 0.08, 0.08,    //58
        228.0, 130.0, 0.0, 0.12, 0.05, 0.05,    //59
        000.0, 142.0, 0.0, 0.07, 0.05, 0.05,    //60
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
    static GLubyte ltopquad[] = {23, 24, 25, 26};
    static GLubyte ltoppent[] = {25, 26, 27, 28, 29};
    static GLubyte topcent[] = {28, 29, 30, 31, 32};
    static GLubyte rtoppent[] = {30, 31, 33, 34, 35};
    static GLubyte rtopquad[] = {33, 34, 36, 37};
    static GLubyte rtoptri[] = {38, 39, 40};
    static GLubyte rquad[] = {41, 42, 43, 44};
    static GLubyte rpent[] = {43, 44, 45, 46, 47};
    static GLubyte tl3lines[] = {48, 49, 50, 51};
    static GLubyte tllinel[] = {49, 52};
    static GLubyte tlliner[] = {50, 53};
    static GLubyte tr2lines[] = {54, 55, 56};
    static GLubyte trlineb[] = {57, 58};
    static GLubyte ground[] = {59, 60};

    static GLsizei count[] = {4, 3, 5, 5, 3, 3, 4, 5, 5, 5, 4, 3, 4, 5};
    static GLvoid * indices[14] = {
        key, belowkeytri, belowkeypent, base, smlefttri, lglefttri, ltopquad, 
        ltoppent, topcent, rtoppent, rtopquad, rtoptri, rquad, rpent
    };
    
    glMultiDrawElements(GL_POLYGON, count, GL_UNSIGNED_BYTE, indices, 14);

    glLineWidth(9.0);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, belowkeyline);
    glLineWidth(15.0);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, lbaseline);
    glLineWidth(11.0);
    glDrawElements(GL_LINE_STRIP, 4, GL_UNSIGNED_BYTE, tl3lines);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, tllinel);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, tlliner);
    glLineWidth(13.0);
    glDrawElements(GL_LINE_STRIP, 3, GL_UNSIGNED_BYTE, tr2lines);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, trlineb);
    glLineWidth(9.0);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, ground);
}

void draw_highlights()
{
    static GLfloat vertexValues[] = {
        630.0, 428.0, 0.0, 0.75, 0.13, 0.12,    //0
        654.0, 415.0, 0.0, 0.70, 0.12, 0.11,    //1
        579.0, 197.0, 0.0, 0.50, 0.09, 0.08,    //2
        463.0, 197.0, 0.0, 0.47, 0.08, 0.08,    //3
        463.0, 315.0, 0.0, 0.75, 0.13, 0.12,    //4
        279.0, 428.0, 0.0, 0.81, 0.20, 0.16,    //5
        325.0, 400.0, 0.0, 0.85, 0.21, 0.17,    //6
        346.0, 351.0, 0.0, 0.83, 0.20, 0.17,    //7
        270.0, 390.0, 0.0, 0.83, 0.21, 0.17,    //8
        262.0, 415.0, 0.0, 0.86, 0.22, 0.18,    //9
        273.0, 384.0, 0.0, 0.68, 0.15, 0.12,    //10
        342.0, 348.0, 0.0, 0.71, 0.15, 0.13,    //11
        312.0, 260.0, 0.0, 0.61, 0.13, 0.11,    //12
        285.0, 314.0, 0.0, 0.84, 0.25, 0.20,    //13
        327.0, 190.0, 0.0, 0.82, 0.29, 0.23,    //14
        222.0, 136.0, 0.0, 0.44, 0.17, 0.14,    //15
        000.0, 000.0, 0.0, 0.00, 0.00, 0.00,    //16
        000.0, 000.0, 0.0, 0.00, 0.00, 0.00,    //17
        000.0, 000.0, 0.0, 0.00, 0.00, 0.00,    //18
        000.0, 000.0, 0.0, 0.00, 0.00, 0.00,    //19
        000.0, 000.0, 0.0, 0.00, 0.00, 0.00,    //20
        000.0, 000.0, 0.0, 0.00, 0.00, 0.00,    //BLANK
    };

    glVertexPointer(3, GL_FLOAT, 6*sizeof(GLfloat), &vertexValues[0]);
    glColorPointer(3, GL_FLOAT, 6*sizeof(GLfloat), &vertexValues[3]);

    static GLubyte centpent[] = {0, 1, 2, 3, 4};
    static GLubyte smcentpent[] = {5, 6, 7, 8, 9};
    static GLubyte centtri[] = {10, 11, 12};
    static GLubyte lefttri[] = {13, 14, 15};
    static GLubyte leftpent[] = {16, 17, 18, 19, 20};

    static GLsizei count[] = {5, 5, 3, 3, 5};
    static GLvoid * indices[5] = {
        centpent, smcentpent, centtri, lefttri, leftpent,
    };

    glMultiDrawElements(GL_POLYGON, count, GL_UNSIGNED_BYTE, indices, 5);
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
    draw_highlights();

    // Draw the shadows
    draw_shadows();

    // Draw the dodecahedron
    //draw_dodecahedron();

    // Draw the key
    //draw_key();

    // Draw the title
    //draw_title();

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
    /*
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, ind1);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, ind2);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, ind3);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, ind4);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, ind5);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, ind6);
    */

    /*
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
    */
