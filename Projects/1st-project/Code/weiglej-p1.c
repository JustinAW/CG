
/********************************************************
 *                    Project 1                         *
 * Author: Justin Weigle                                *
 * Edited: 30 Sep, 2019                                 *
 * Submitted:                                           *
 ********************************************************
 *      Draws the album art for Asking Alexandria's     *
 *      self titled album                               *
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
        115.0, 310.0, 0.0, 0.22, 0.09, 0.08,    //61
        125.0, 382.0, 0.0, 0.18, 0.09, 0.07,    //62
        425.0, 624.0, 0.0, 0.47, 0.09, 0.08,    //63
        452.0, 559.0, 0.0, 0.54, 0.11, 0.11,    //64
        482.0, 635.0, 0.0, 0.76, 0.17, 0.14,    //65
        672.0, 549.0, 0.0, 0.53, 0.10, 0.09,    //66
        485.0, 635.0, 0.0, 0.70, 0.17, 0.14,    //67
        466.0, 556.0, 0.0, 0.32, 0.09, 0.09,    //68
        462.0, 625.0, 0.0, 0.41, 0.12, 0.11,    //69
        621.0, 450.0, 0.0, 0.56, 0.11, 0.11,    //70
        744.0, 645.0, 0.0, 0.31, 0.09, 0.09,    //70
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

    // lines tacked on due to highlight/shadow overlap
    static GLubyte lvertl[] = {61, 62};
    static GLubyte tll[] = {63, 64};
    static GLubyte trlhor[] = {65, 66};
    static GLubyte trlvert[] = {67, 68};
    static GLubyte trlsm[] = {67, 69};
    static GLubyte rldown[] = {66, 70};
    static GLubyte rlup[] = {66, 71};

    glLineWidth(7.0);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, lvertl);
    glLineWidth(5.0);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, tll);
    glLineWidth(7.0);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, trlhor);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, trlvert);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, trlsm);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, rldown);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, rlup);
}

/*
 * Draws the parts that are brighter
 */
void draw_highlights()
{
    static GLfloat vertexValues[] = {
        628.0, 432.0, 0.0, 0.75, 0.13, 0.12,    //0
        654.0, 415.0, 0.0, 0.70, 0.12, 0.11,    //1
        579.0, 197.0, 0.0, 0.50, 0.09, 0.08,    //2
        463.0, 197.0, 0.0, 0.47, 0.08, 0.08,    //3
        463.0, 315.0, 0.0, 0.75, 0.13, 0.12,    //4
        282.0, 437.0, 0.0, 0.81, 0.20, 0.16,    //5
        320.0, 420.0, 0.0, 0.85, 0.21, 0.17,    //6
        346.0, 351.0, 0.0, 0.83, 0.20, 0.17,    //7
        270.0, 390.0, 0.0, 0.83, 0.21, 0.17,    //8
        260.0, 420.0, 0.0, 0.86, 0.22, 0.18,    //9
        273.0, 384.0, 0.0, 0.68, 0.15, 0.12,    //10
        342.0, 348.0, 0.0, 0.71, 0.15, 0.13,    //11
        312.0, 260.0, 0.0, 0.61, 0.13, 0.11,    //12
        285.0, 314.0, 0.0, 0.84, 0.25, 0.20,    //13
        327.0, 190.0, 0.0, 0.82, 0.29, 0.23,    //14
        222.0, 136.0, 0.0, 0.44, 0.17, 0.14,    //15
        252.0, 429.0, 0.0, 0.67, 0.16, 0.13,    //16
        282.0, 329.0, 0.0, 0.66, 0.16, 0.13,    //17
        219.0, 152.0, 0.0, 0.43, 0.16, 0.14,    //18
        131.0, 284.0, 0.0, 0.25, 0.10, 0.09,    //19
        125.0, 398.0, 0.0, 0.28, 0.09, 0.08,    //20
        232.0, 558.0, 0.0, 0.40, 0.10, 0.09,    //21
        280.0, 443.0, 0.0, 0.56, 0.11, 0.10,    //22
        256.0, 425.0, 0.0, 0.56, 0.11, 0.10,    //23
        186.0, 479.0, 0.0, 0.42, 0.11, 0.09,    //24
        244.0, 548.0, 0.0, 0.36, 0.09, 0.09,    //25
        453.0, 638.0, 0.0, 0.46, 0.09, 0.08,    //26
        458.0, 556.0, 0.0, 0.51, 0.09, 0.08,    //27
        286.0, 443.0, 0.0, 0.40, 0.09, 0.09,    //28
        485.0, 756.0, 0.0, 0.50, 0.11, 0.09,    //29
        609.0, 756.0, 0.0, 0.42, 0.11, 0.09,    //30
        483.0, 633.0, 0.0, 0.63, 0.13, 0.11,    //31
        681.0, 551.0, 0.0, 0.61, 0.13, 0.10,    //32
        634.0, 435.0, 0.0, 0.75, 0.14, 0.12,    //33
        708.0, 483.0, 0.0, 0.81, 0.17, 0.14,    //34
        723.0, 466.0, 0.0, 0.75, 0.17, 0.14,    //35
        659.0, 414.0, 0.0, 0.70, 0.14, 0.12,    //36
        828.0, 355.0, 0.0, 0.46, 0.10, 0.09,    //37
        719.0, 191.0, 0.0, 0.30, 0.09, 0.08,    //38
        589.0, 191.0, 0.0, 0.40, 0.09, 0.08,    //39
        124.0, 382.0, 0.0, 0.36, 0.11, 0.11,    //40
        256.0, 420.0, 0.0, 0.93, 0.32, 0.23,    //41
        491.0, 756.0, 0.0, 0.54, 0.12, 0.11,    //42
        485.0, 630.0, 0.0, 0.86, 0.17, 0.14,    //43
        660.0, 415.0, 0.0, 0.78, 0.12, 0.10,    //44
        805.0, 379.0, 0.0, 0.45, 0.10, 0.08,    //45
        807.0, 326.0, 0.0, 0.44, 0.10, 0.09,    //46
    };

    glVertexPointer(3, GL_FLOAT, 6*sizeof(GLfloat), &vertexValues[0]);
    glColorPointer(3, GL_FLOAT, 6*sizeof(GLfloat), &vertexValues[3]);

    static GLubyte centpent[] = {0, 1, 2, 3, 4};
    static GLubyte smcentpent[] = {5, 6, 7, 8, 9};
    static GLubyte centtri[] = {10, 11, 12};
    static GLubyte lefttri[] = {13, 14, 15};
    static GLubyte leftpent[] = {16, 17, 18, 19, 20};
    static GLubyte tlquadsm[] = {21, 22, 23, 24};
    static GLubyte tlquadlg[] = {25, 26, 27, 28};
    static GLubyte trtrism[] = {29, 30, 31};
    static GLubyte trtrilg[] = {30, 31, 32};
    static GLubyte rquad[] = {33, 34, 35, 36};
    static GLubyte rpent[] = {35, 37, 38, 39, 36};
    static GLubyte lhorl[] = {40, 41};
    static GLubyte trhorl[] = {42, 43};
    static GLubyte brhor[] = {44, 45};
    static GLubyte brvert[] = {45, 46};

    static GLsizei count[] = {5, 5, 3, 3, 5, 4, 4, 3, 3, 4, 5};
    static GLvoid * indices[11] = {
        centpent, smcentpent, centtri, lefttri, leftpent, tlquadsm, tlquadlg,
        trtrism, trtrilg, rquad, rpent,
    };

    glMultiDrawElements(GL_POLYGON, count, GL_UNSIGNED_BYTE, indices, 11);

    glLineWidth(5.0);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, lhorl);
    glLineWidth(7.0);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, trhorl);
    glLineWidth(1.0);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, brhor);
    glLineWidth(7.0);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, brvert);
}

/*
 * Draws the dodecahedron on the album cover
 */
void draw_dodecahedron()
{
    //vertices repeated once for texturing purposes
    static GLfloat vertexValues[] = {
        458.0, 555.0, 0.0, 0.00, 1.00, 1.00,    //0
        458.0, 555.0, 0.0, 0.00, 1.00, 1.00,    //1 ]
        659.0, 417.0, 0.0, 0.00, 1.00, 1.00,    //2
        659.0, 417.0, 0.0, 0.00, 1.00, 1.00,    //3 ]
        584.0, 193.0, 0.0, 0.00, 1.00, 1.00,    //4
        584.0, 193.0, 0.0, 0.00, 1.00, 1.00,    //5 ]
        331.0, 193.0, 0.0, 0.00, 1.00, 1.00,    //6
        331.0, 193.0, 0.0, 0.00, 1.00, 1.00,    //7 ]
        257.0, 420.0, 0.0, 0.00, 1.00, 1.00,    //8
        257.0, 420.0, 0.0, 0.00, 1.00, 1.00,    //9 ]
        682.0, 137.0, 0.0, 0.00, 1.00, 1.00,    //10
        682.0, 137.0, 0.0, 0.00, 1.00, 1.00,    //11]
        459.0, 92.00, 0.0, 0.00, 1.00, 1.00,    //12
        459.0, 92.00, 0.0, 0.00, 1.00, 1.00,    //13]
        224.0, 133.0, 0.0, 0.00, 1.00, 1.00,    //14
        224.0, 133.0, 0.0, 0.00, 1.00, 1.00,    //15]
        76.00, 368.0, 0.0, 0.00, 1.00, 1.00,    //16
        76.00, 368.0, 0.0, 0.00, 1.00, 1.00,    //17]
        106.0, 535.0, 0.0, 0.00, 1.00, 1.00,    //18
        106.0, 535.0, 0.0, 0.00, 1.00, 1.00,    //19]
        230.0, 762.0, 0.0, 0.00, 1.00, 1.00,    //20
        230.0, 762.0, 0.0, 0.00, 1.00, 1.00,    //21]
        458.0, 760.0, 0.0, 0.00, 1.00, 1.00,    //22
        458.0, 760.0, 0.0, 0.00, 1.00, 1.00,    //23]
        682.0, 761.0, 0.0, 0.00, 1.00, 1.00,    //24
        682.0, 761.0, 0.0, 0.00, 1.00, 1.00,    //25]
        807.0, 537.0, 0.0, 0.00, 1.00, 1.00,    //26
        807.0, 537.0, 0.0, 0.00, 1.00, 1.00,    //27]
        832.0, 363.0, 0.0, 0.00, 1.00, 1.00,    //28
        832.0, 363.0, 0.0, 0.00, 1.00, 1.00,    //29]
        457.0, 322.0, 0.0, 0.00, 1.00, 1.00,    //30
        457.0, 322.0, 0.0, 0.00, 1.00, 1.00,    //31]
        200.0, 495.0, 0.0, 0.00, 1.00, 1.00,    //32
        200.0, 495.0, 0.0, 0.00, 1.00, 1.00,    //33]
        303.0, 761.0, 0.0, 0.00, 1.00, 1.00,    //34
        303.0, 761.0, 0.0, 0.00, 1.00, 1.00,    //35]
        607.0, 760.0, 0.0, 0.00, 1.00, 1.00,    //36
        607.0, 760.0, 0.0, 0.00, 1.00, 1.00,    //37
        705.0, 491.0, 0.0, 0.00, 1.00, 1.00,    //38
        705.0, 491.0, 0.0, 0.00, 1.00, 1.00,    //39]
        000.0, 000.0, 0.0, 0.00, 1.00, 1.00,    //
    };

    glVertexPointer(3, GL_FLOAT, 6*sizeof(GLfloat), &vertexValues[0]);
    glColorPointer(3, GL_FLOAT, 6*sizeof(GLfloat), &vertexValues[3]);

    static GLubyte back1[] = {0, 2};
    static GLubyte back2[] = {2, 4};
    static GLubyte back3[] = {4, 6};
    static GLubyte back4[] = {6, 8};
    static GLubyte back5[] = {8, 0};

    static GLubyte base1[] = {5, 10};
    static GLubyte base2[] = {11, 12};
    static GLubyte base3[] = {12, 14};
    static GLubyte base4[] = {15, 7};

    static GLubyte bklbot1[] = {15, 16};
    static GLubyte bklbot2[] = {16, 18};
    static GLubyte bklbot3[] = {19, 8};

    static GLubyte bkltop1[] = {18, 20};
    static GLubyte bkltop2[] = {20, 22};
    static GLubyte bkltop3[] = {22, 1};

    static GLubyte bkrtop1[] = {23, 24};
    static GLubyte bkrtop2[] = {24, 26};
    static GLubyte bkrtop3[] = {26, 3};

    static GLubyte bkrbot1[] = {26, 28};
    static GLubyte bkrbot2[] = {28, 10};

    static GLubyte ftlbot1[] = {14, 17};
    static GLubyte ftlbot2[] = {16, 32};
    static GLubyte ftlbot3[] = {32, 30};
    static GLubyte ftlbot4[] = {30, 13};

    static GLubyte ftltop[] = {33, 34};

    static GLubyte ftrtop1[] = {36, 38};
    static GLubyte ftrtop2[] = {38, 29};

    static GLubyte ftrbot[] = {38, 30};

    static GLubyte front1[] = {31, 33};
    static GLubyte front2[] = {33, 35};
    static GLubyte front3[] = {35, 37};
    static GLubyte front4[] = {37, 39};
    static GLubyte front5[] = {39, 31};

    glLineWidth(10.0);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, back1);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, back2);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, back3);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, back4);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, back5);

    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, base1);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, base2);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, base3);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, base4);

    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, bklbot1);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, bklbot2);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, bklbot3);

    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, bkltop1);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, bkltop2);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, bkltop3);

    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, bkrtop1);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, bkrtop2);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, bkrtop3);

    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, bkrbot1);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, bkrbot2);

    glLineWidth(15.0);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, ftlbot1);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, ftlbot2);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, ftlbot3);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, ftlbot4);

    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, ftltop);

    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, ftrtop1);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, ftrtop2);

    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, ftrbot);

    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, front1);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, front2);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, front3);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, front4);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, front5);
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
    draw_dodecahedron();

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
