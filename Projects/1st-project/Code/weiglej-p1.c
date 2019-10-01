
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
    glEnable(GL_LINE_SMOOTH);

	glClearColor (0.0, 0.0, 0.0, 0.0);
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
        308.0, 272.0, 0.0, 0.30, 0.05, 0.05,    //9
        270.0, 388.0, 0.0, 0.30, 0.05, 0.05,    //10
        333.0, 191.0, 0.0, 0.40, 0.09, 0.09,    //11
        582.0, 191.0, 0.0, 0.55, 0.09, 0.08,    //12
        676.0, 138.0, 0.0, 0.34, 0.09, 0.08,    //13
        459.0, 97.00, 0.0, 0.20, 0.08, 0.08,    //14
        229.0, 134.0, 0.0, 0.20, 0.08, 0.08,    //15
        220.0, 147.0, 0.0, 0.20, 0.06, 0.06,    //16
        285.0, 327.0, 0.0, 0.22, 0.08, 0.08,    //17
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
        287.0, 314.0, 0.0, 0.84, 0.25, 0.20,    //13
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
        459.6, 565.2, 0.0, 0.40, 0.17, 0.12,    //0     back
        664.9, 422.8, 0.0, 0.43, 0.12, 0.10,    //1
        658.8, 411.9, 0.0, 0.86, 0.38, 0.29,    //2
        453.0, 552.9, 0.0, 0.94, 0.61, 0.43,    //3_1
        654.0, 419.7, 0.0, 0.72, 0.31, 0.25,    //4
        665.7, 415.7, 0.0, 0.73, 0.26, 0.23,    //5
        590.6, 191.7, 0.0, 0.31, 0.09, 0.08,    //6
        577.4, 195.0, 0.0, 0.83, 0.50, 0.40,    //7_2
        583.8, 197.3, 0.0, 0.86, 0.40, 0.28,    //8
        586.8, 189.4, 0.0, 0.77, 0.31, 0.23,    //9
        330.6, 191.5, 0.0, 0.83, 0.31, 0.22,    //10
        330.4, 198.1, 0.0, 0.83, 0.27, 0.22,    //11_3
        326.7, 190.1, 0.0, 0.79, 0.28, 0.21,    //12
        251.3, 419.6, 0.0, 0.87, 0.52, 0.36,    //13
        261.1, 421.6, 0.0, 0.93, 0.42, 0.29,    //14
        334.8, 194.0, 0.0, 0.92, 0.44, 0.32,    //15_4
        253.8, 425.9, 0.0, 0.93, 0.44, 0.30,    //16
        457.1, 565.1, 0.0, 0.86, 0.47, 0.38,    //17
        456.9, 549.5, 0.0, 0.96, 0.83, 0.73,    //18
        259.3, 414.1, 0.0, 0.94, 0.50, 0.35,    //19_5  endback
        585.2, 196.9, 0.0, 0.41, 0.11, 0.10,    //20    base
        685.8, 141.1, 0.0, 0.31, 0.09, 0.08,    //21
        678.2, 136.0, 0.0, 0.27, 0.08, 0.07,    //22
        582.6, 188.5, 0.0, 0.27, 0.09, 0.09,    //23_1
        681.6, 139.6, 0.0, 0.62, 0.23, 0.21,    //24
        683.1, 129.3, 0.0, 0.64, 0.14, 0.12,    //25
        459.0, 86.50, 0.0, 0.52, 0.12, 0.10,    //26
        459.7, 97.50, 0.0, 0.68, 0.17, 0.14,    //27_2
        459.0, 86.50, 0.0, 0.15, 0.06, 0.06,    //28
        222.4, 127.0, 0.0, 0.06, 0.06, 0.05,    //29
        227.3, 135.2, 0.0, 0.07, 0.06, 0.05,    //30
        461.1, 96.90, 0.0, 0.11, 0.06, 0.07,    //31_3
        225.1, 139.0, 0.0, 0.29, 0.14, 0.13,    //32
        331.0, 197.8, 0.0, 0.75, 0.21, 0.17,    //33
        332.1, 191.7, 0.0, 0.76, 0.22, 0.18,    //34
        229.8, 134.5, 0.0, 0.24, 0.12, 0.10,    //35_4  endbase
        222.4, 127.0, 0.0, 0.06, 0.05, 0.05,    //36    bklbot
        70.60, 364.5, 0.0, 0.07, 0.05, 0.05,    //37
        80.20, 368.3, 0.0, 0.11, 0.08, 0.07,    //38
        231.5, 132.2, 0.0, 0.12, 0.08, 0.07,    //39_1
        70.60, 364.5, 0.0, 0.08, 0.06, 0.06,    //40
        101.7, 539.3, 0.0, 0.14, 0.08, 0.07,    //41
        112.2, 539.8, 0.0, 0.23, 0.09, 0.08,    //42
        80.50, 368.5, 0.0, 0.15, 0.09, 0.09,    //43_2
        112.2, 539.8, 0.0, 0.24, 0.09, 0.09,    //44
        261.7, 423.6, 0.0, 0.93, 0.46, 0.34,    //45
        257.2, 414.4, 0.0, 0.96, 0.41, 0.29,    //46
        107.5, 528.0, 0.0, 0.32, 0.11, 0.11,    //47_3  endbklbot
        101.7, 539.3, 0.0, 0.15, 0.08, 0.06,    //48    bkltop
        227.8, 767.0, 0.0, 0.08, 0.05, 0.05,    //49
        232.7, 758.0, 0.0, 0.08, 0.05, 0.05,    //50
        109.1, 536.0, 0.0, 0.24, 0.09, 0.08,    //51_1
        227.8, 767.0, 0.0, 0.08, 0.05, 0.05,    //52
        458.0, 765.8, 0.0, 0.08, 0.05, 0.05,    //53
        457.8, 754.2, 0.0, 0.08, 0.05, 0.05,    //54
        232.7, 758.0, 0.0, 0.08, 0.05, 0.05,    //55_2
        449.4, 761.0, 0.0, 0.49, 0.15, 0.13,    //56
        464.4, 761.1, 0.0, 0.19, 0.09, 0.08,    //57
        465.2, 558.8, 0.0, 0.40, 0.17, 0.12,    //58
        450.3, 558.9, 0.0, 0.86, 0.47, 0.38,    //59_3  endbkltop
        458.0, 765.8, 0.0, 0.08, 0.05, 0.05,    //60    bkrtop
        683.7, 765.4, 0.0, 0.16, 0.08, 0.06,    //61
        686.0, 754.6, 0.0, 0.30, 0.11, 0.09,    //62
        457.8, 754.2, 0.0, 0.08, 0.05, 0.05,    //63_1
        683.7, 765.4, 0.0, 0.16, 0.08, 0.06,    //64
        809.5, 539.9, 0.0, 0.29, 0.10, 0.09,    //65
        803.7, 535.8, 0.0, 0.12, 0.07, 0.06,    //66
        679.6, 757.0, 0.0, 0.16, 0.11, 0.09,    //67_2
        803.7, 535.8, 0.0, 0.12, 0.07, 0.06,    //68
        808.2, 527.8, 0.0, 0.09, 0.06, 0.05,    //69
        662.8, 413.0, 0.0, 0.33, 0.08, 0.07,    //70
        654.6, 424.0, 0.0, 0.65, 0.14, 0.12,    //71_3  endbkrtop
        809.5, 539.9, 0.0, 0.29, 0.10, 0.09,    //72    bkrbot
        837.2, 363.2, 0.0, 0.33, 0.11, 0.10,    //73
        829.4, 364.5, 0.0, 0.23, 0.11, 0.09,    //74
        803.7, 535.8, 0.0, 0.12, 0.07, 0.06,    //75_1
        837.2, 363.2, 0.0, 0.33, 0.11, 0.10,    //76
        683.6, 129.4, 0.0, 0.57, 0.13, 0.13,    //77
        681.9, 139.7, 0.0, 0.20, 0.07, 0.06,    //78
        829.4, 364.5, 0.0, 0.23, 0.11, 0.09,    //79_2  endbkrbot
        73.80, 378.8, 0.0, 0.07, 0.05, 0.06,    //80    ftlbot
        197.2, 506.1, 0.0, 0.11, 0.06, 0.05,    //81
        210.2, 486.8, 0.0, 0.08, 0.06, 0.06,    //82
        79.80, 357.5, 0.0, 0.06, 0.05, 0.05,    //83_1
        205.0, 503.7, 0.0, 0.00, 0.00, 0.00,    //84
        471.3, 322.2, 0.0, 0.00, 0.00, 0.00,    //85
        445.2, 312.2, 0.0, 0.00, 0.00, 0.00,    //86
        196.6, 486.0, 0.0, 0.00, 0.00, 0.00,    //87_2
        445.2, 312.2, 0.0, 0.00, 0.00, 0.00,    //88
        471.3, 322.2, 0.0, 0.00, 0.00, 0.00,    //89
        469.6, 95.00, 0.0, 0.00, 0.00, 0.00,    //90
        445.5, 95.50, 0.0, 0.00, 0.00, 0.00,    //91_3  endftlbot
        190.7, 498.7, 0.0, 0.00, 0.00, 0.00,    //92    ftltop
        296.5, 766.7, 0.0, 0.00, 0.00, 0.00,    //93
        314.6, 766.4, 0.0, 0.00, 0.00, 0.00,    //94
        205.5, 491.0, 0.0, 0.00, 0.00, 0.00,    //95_1  endftltop
        597.5, 761.8, 0.0, 0.00, 0.00, 0.00,    //96    ftrtop
        616.8, 762.5, 0.0, 0.00, 0.00, 0.00,    //97
        714.6, 499.2, 0.0, 0.00, 0.00, 0.00,    //98
        698.7, 488.5, 0.0, 0.00, 0.00, 0.00,    //99_1
        698.7, 488.5, 0.0, 0.00, 0.00, 0.00,    //100
        714.6, 499.2, 0.0, 0.00, 0.00, 0.00,    //101
        837.2, 367.1, 0.0, 0.00, 0.00, 0.00,    //102
        827.7, 353.5, 0.0, 0.00, 0.00, 0.00,    //103_2 endftrtop
        696.4, 500.0, 0.0, 0.00, 0.00, 0.00,    //104   ftrbot
        714.2, 486.1, 0.0, 0.00, 0.00, 0.00,    //105
        463.3, 311.5, 0.0, 0.00, 0.00, 0.00,    //106
        453.2, 331.7, 0.0, 0.00, 0.00, 0.00,    //107_1 endftrbot
        0, 0, 0.0, 0.00, 0.00, 0.00,    //
    };

    glVertexPointer(3, GL_FLOAT, 6*sizeof(GLfloat), &vertexValues[0]);
    glColorPointer(3, GL_FLOAT, 6*sizeof(GLfloat), &vertexValues[3]);

    static GLubyte back1[] = {0, 1, 2, 3};
    static GLubyte back2[] = {4, 5, 6, 7};
    static GLubyte back3[] = {8, 9, 10, 11};
    static GLubyte back4[] = {12, 13, 14, 15};
    static GLubyte back5[] = {16, 17, 18, 19};

    static GLubyte base1[] = {20, 21, 22, 23};
    static GLubyte base2[] = {24, 25, 26, 27};
    static GLubyte base3[] = {28, 29, 30, 31};
    static GLubyte base4[] = {32, 33, 34, 35};
    
    static GLubyte bklbot1[] = {36, 37, 38, 39};
    static GLubyte bklbot2[] = {40, 41, 42, 43};
    static GLubyte bklbot3[] = {44, 45, 46, 47};

    static GLubyte bkltop1[] = {48, 49, 50, 51};
    static GLubyte bkltop2[] = {52, 53, 54, 55};
    static GLubyte bkltop3[] = {56, 57, 58, 59};

    static GLubyte bkrtop1[] = {60, 61, 62, 63};
    static GLubyte bkrtop2[] = {64, 65, 66, 67};
    static GLubyte bkrtop3[] = {68, 69, 70, 71};

    static GLubyte bkrbot1[] = {72, 73, 74, 75};
    static GLubyte bkrbot2[] = {76, 77, 78, 79};

    static GLubyte ftlbot1[] = {80, 81, 82, 83};
    static GLubyte ftlbot2[] = {84, 85, 86, 87};
    static GLubyte ftlbot3[] = {88, 89, 90, 91};

    static GLubyte ftltop1[] = {92, 93, 94, 95};

    static GLubyte ftrtop1[] = {96, 97, 98, 99};
    static GLubyte ftrtop2[] = {100, 101, 102, 103};

    static GLubyte ftrbot1[] = {104, 105, 106, 107};

    static GLsizei count[] = {
        4, 4, 4, 4, 4, 
        4, 4, 4, 4, 
        4, 4, 4, 
        4, 4, 4, 
        4, 4, 4,
        4, 4,
        4, 4, 4,
        4,
        4, 4,
        4,
    };
    static GLvoid * indices[27] = {
        back1, back2, back3, back4, back5,
        base1, base2, base3, base4,
        bklbot1, bklbot2, bklbot3,
        bkltop1, bkltop2, bkltop3,
        bkrtop1, bkrtop2, bkrtop3,
        bkrbot1, bkrbot2,
        ftlbot1, ftlbot2, ftlbot3,
        ftltop1,
        ftrtop1, ftrtop2,
        ftrbot1,
    };

    glMultiDrawElements(GL_POLYGON, count, GL_UNSIGNED_BYTE, indices, 27);

    /*
     * LINES
    static GLubyte back1[] = {0, 1};
    static GLubyte back2[] = {1, 2};
    static GLubyte back3[] = {2, 3};
    static GLubyte back4[] = {3, 4};
    static GLubyte back5[] = {4, 0};

    static GLubyte base1[] = {2, 5};
    static GLubyte base2[] = {5, 6};
    static GLubyte base3[] = {6, 7};
    static GLubyte base4[] = {7, 3};

    static GLubyte bklbot1[] = {7, 8};
    static GLubyte bklbot2[] = {8, 9};
    static GLubyte bklbot3[] = {9, 4};

    static GLubyte bkltop1[] = {9, 10};
    static GLubyte bkltop2[] = {10, 11};
    static GLubyte bkltop3[] = {11, 0};

    static GLubyte bkrtop1[] = {11, 12};
    static GLubyte bkrtop2[] = {12, 13};
    static GLubyte bkrtop3[] = {13, 1};

    static GLubyte bkrbot1[] = {13, 14};
    static GLubyte bkrbot2[] = {14, 5};

    static GLubyte ftlbot1[] = {8, 15};
    static GLubyte ftlbot2[] = {15, 16};
    static GLubyte ftlbot3[] = {16, 6};

    static GLubyte ftltop[] = {15, 17};

    static GLubyte ftrtop1[] = {18, 19};
    static GLubyte ftrtop2[] = {19, 14};

    static GLubyte ftrbot[] = {19, 16};

    static GLubyte front1[] = {31, 33};
    static GLubyte front2[] = {33, 35};
    static GLubyte front3[] = {35, 37};
    static GLubyte front4[] = {37, 39};
    static GLubyte front5[] = {39, 31};
    */

    /*
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

    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, ftlbot1);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, ftlbot2);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, ftlbot3);

    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, ftltop);

    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, ftrtop1);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, ftrtop2);

    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, ftrbot);

    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, front1);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, front2);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, front3);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, front4);
    glDrawElements(GL_LINES, 2, GL_UNSIGNED_BYTE, front5);
    */
}

void draw_key()
{
    static GLfloat vertexValues[] = {
        376.0, 464.7, 0.0, 0.00, 0.00, 0.00,    //0
        495.0, 465.4, 0.0, 0.00, 0.00, 0.00,    //1
        495.0, 447.0, 0.0, 0.00, 0.00, 0.00,    //2
        375.5, 445.9, 0.0, 0.00, 0.00, 0.00,    //3_shaft
        517.4, 494.3, 0.0, 0.00, 0.00, 0.00,    //4
        522.0, 493.6, 0.0, 0.00, 0.00, 0.00,    //5
        526.7, 491.5, 0.0, 0.00, 0.00, 0.00,    //6
        530.2, 488.3, 0.0, 0.00, 0.00, 0.00,    //7
        532.8, 484.2, 0.0, 0.00, 0.00, 0.00,    //8
        535.5, 479.2, 0.0, 0.00, 0.00, 0.00,    //9
        537.3, 474.4, 0.0, 0.00, 0.00, 0.00,    //10
        538.1, 469.5, 0.0, 0.00, 0.00, 0.00,    //11
        538.9, 463.9, 0.0, 0.00, 0.00, 0.00,    //12
        538.9, 457.4, 0.0, 0.00, 0.00, 0.00,    //13
        538.8, 452.3, 0.0, 0.00, 0.00, 0.00,    //14
        538.2, 446.6, 0.0, 0.00, 0.00, 0.00,    //15
        537.1, 440.9, 0.0, 0.00, 0.00, 0.00,    //16
        535.6, 436.0, 0.0, 0.00, 0.00, 0.00,    //17
        534.1, 431.9, 0.0, 0.00, 0.00, 0.00,    //18
        531.7, 427.1, 0.0, 0.00, 0.00, 0.00,    //19
        529.4, 423.9, 0.0, 0.00, 0.00, 0.00,    //20
        525.8, 421.3, 0.0, 0.00, 0.00, 0.00,    //21
        521.9, 418.9, 0.0, 0.00, 0.00, 0.00,    //22
        517.1, 417.8, 0.0, 0.00, 0.00, 0.00,    //23
        512.4, 417.0, 0.0, 0.00, 0.00, 0.00,    //24
        508.1, 418.6, 0.0, 0.00, 0.00, 0.00,    //25
        504.5, 421.5, 0.0, 0.00, 0.00, 0.00,    //26
        501.0, 425.2, 0.0, 0.00, 0.00, 0.00,    //27
        498.6, 430.0, 0.0, 0.00, 0.00, 0.00,    //28
        497.0, 435.9, 0.0, 0.00, 0.00, 0.00,    //29
        495.7, 441.3, 0.0, 0.00, 0.00, 0.00,    //30
        494.9, 445.2, 0.0, 0.00, 0.00, 0.00,    //31
        493.5, 464.0, 0.0, 0.00, 0.00, 0.00,    //32
        494.5, 468.8, 0.0, 0.00, 0.00, 0.00,    //33
        495.9, 473.1, 0.0, 0.00, 0.00, 0.00,    //34
        497.8, 477.6, 0.0, 0.00, 0.00, 0.00,    //35
        499.8, 481.8, 0.0, 0.00, 0.00, 0.00,    //36
        502.9, 485.9, 0.0, 0.00, 0.00, 0.00,    //37
        506.3, 489.4, 0.0, 0.00, 0.00, 0.00,    //38
        509.8, 492.3, 0.0, 0.00, 0.00, 0.00,    //39
        513.6, 493.9, 0.0, 0.00, 0.00, 0.00,    //40_bow
        382.6, 446.0, 0.0, 0.00, 0.00, 0.00,    //41
        391.4, 423.4, 0.0, 0.00, 0.00, 0.00,    //42
        402.5, 446.0, 0.0, 0.00, 0.00, 0.00,    //43_bit1
        396.9, 446.0, 0.0, 0.00, 0.00, 0.00,    //44
        419.8, 446.0, 0.0, 0.00, 0.00, 0.00,    //45
        407.2, 430.8, 0.0, 0.00, 0.00, 0.00,    //46_bit2
        0, 0, 0.0, 0.00, 0.00, 0.00,    //
    };

    glVertexPointer(3, GL_FLOAT, 6*sizeof(GLfloat), &vertexValues[0]);
    glColorPointer(3, GL_FLOAT, 6*sizeof(GLfloat), &vertexValues[3]);

    static GLubyte shaft[] = {0, 1, 2, 3};
    static GLubyte bow[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40};
    static GLubyte bit1[] = {41, 42, 43};
    static GLubyte bit2[] = {44, 45, 46};

    static GLsizei count[] = {
        4, 37, 3, 3,
    };

    static GLvoid * indices[] = {
        shaft, bow, bit1, bit2,
    };

    glMultiDrawElements(GL_POLYGON, count, GL_UNSIGNED_BYTE, indices, 4);
}

/*
 * Draws a given string starting at coords x,y using font
 */
void renderBitmapString(float x, float y, void *font, const char *string)
{
    const char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

const void *font = GLUT_BITMAP_TIMES_ROMAN_24;

/*
 * Draws ASKING ALEXANDRIA, the album title
 */
void draw_title()
{
    renderBitmapString(290, 845, (void *)font, "A        S        K        I        N        G");
    renderBitmapString(162, 805, (void *)font, "A        L        E        X        A       N       D        R        I        A");
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
    draw_key();

    // Draw the title
    draw_title();

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
        458.0, 555.0, 0.0, 0.00, 0.00, 0.00,    //20    ]0
        659.0, 417.0, 0.0, 0.00, 0.00, 0.00,    //21    ]1
        584.0, 193.0, 0.0, 0.00, 0.00, 0.00,    //22    ]2
        331.0, 193.0, 0.0, 0.00, 0.00, 0.00,    //23    ]3
        257.0, 420.0, 0.0, 0.00, 0.00, 0.00,    //24    ]4
        682.0, 137.0, 0.0, 0.00, 0.00, 0.00,    //25    ]5
        459.0, 92.00, 0.0, 0.00, 0.00, 0.00,    //26    ]6
        224.0, 133.0, 0.0, 0.00, 0.00, 0.00,    //27    ]7
        76.00, 368.0, 0.0, 0.00, 0.00, 0.00,    //28    ]8
        106.0, 535.0, 0.0, 0.00, 0.00, 0.00,    //29    ]9
        230.0, 762.0, 0.0, 0.00, 0.00, 0.00,    //30    ]10
        458.0, 760.0, 0.0, 0.00, 0.00, 0.00,    //31    ]11
        682.0, 761.0, 0.0, 0.00, 0.00, 0.00,    //32    ]12
        807.0, 537.0, 0.0, 0.00, 0.00, 0.00,    //33    ]13
        832.0, 363.0, 0.0, 0.00, 0.00, 0.00,    //34    ]14
        200.0, 495.0, 0.0, 0.00, 0.00, 0.00,    //35    ]15
        457.0, 322.0, 0.0, 0.00, 0.00, 0.00,    //36    ]16
        303.0, 761.0, 0.0, 0.00, 0.00, 0.00,    //37    ]17
        607.0, 760.0, 0.0, 0.00, 0.00, 0.00,    //38    ]18
        705.0, 491.0, 0.0, 0.00, 0.00, 0.00,    //39    ]19
*/
