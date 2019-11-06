/****************************************************
 *                drawfunctions.c                   *
 ****************************************************
 *  Author:     Justin Weigle                       *
 *  Edited:     05 Nov 2019                         *
 ****************************************************
 * Contains the functions for drawing the parts of  *
 * a Wankel rotary engine                           *
 ****************************************************/

#include <GL/glut.h>
#include <math.h>
#include "drawfunctions.h"

const int SIDES = 360;


/****************************************************
 *              inner_gear_outline                  *
 ****************************************************
 * Draws the circular portion of the outline of an  *
 * inward facing gear                               *
 ****************************************************/
void inner_gear_outline (GLfloat depth)
{
    glBegin(GL_LINE_LOOP);
        double heading;
        int counter = 0;
        int toggle = 1;
        for (int i = 0; i <= 360; i += 360 / SIDES)
        {
            heading = i * 3.1415926535897932384626433832795 / 180;
            glVertex3d(cos(heading) * 1.3, sin(heading) * 1.3, depth);
        }
    glEnd();
}


/****************************************************
 *               outer_gear_outline                 *
 ****************************************************
 * Draws the circular portion of the outline of an  *
 * outward facing gear                              *
 ****************************************************/
void outer_gear_outline (GLfloat depth)
{
    glBegin(GL_LINE_LOOP);
        double heading;
        int counter = 0;
        int toggle = 1;
        for (int i = 0; i <= 360; i += 360 / SIDES)
        {
            heading = i * 3.1415926535897932384626433832795 / 180;
            glVertex3d(cos(heading) * 0.7, sin(heading) * 0.7, depth);
        }
    glEnd();
}


/****************************************************
 *                gear_teeth_outline                *
 ****************************************************
 * Draws the outline of the teeth of a gear         *
 ****************************************************/
void gear_teeth_outline (int gear_spacing, GLfloat depth)
{
    glBegin(GL_LINE_LOOP);
        double heading;
        int counter = 0;
        int toggle = 1;
        for (int i = 0; i <= 360; i += 360 / SIDES)
        {
            heading = i * 3.1415926535897932384626433832795 / 180;
            if (toggle)
                glVertex3d(cos(heading), sin(heading), depth);
            else
                glVertex3d(cos(heading) * 0.9, sin(heading) * 0.9, depth);

            counter += 1;
            if (counter == gear_spacing)
            {
                counter = 0;
                if (toggle == 1)
                    toggle = 0;
                else
                    toggle = 1;
            }
        }
    glEnd();
}


/****************************************************
 *                  unit_circle                     *
 ****************************************************
 * Draws a circle, where the starting point can be  *
 * set by i, and the degrees of the circle that are *
 * drawn are set by deg_rotation                    *
 ****************************************************/
void unit_circle (GLfloat depth)
{
    glBegin(GL_LINE_LOOP);
        double heading;
        for (int i = 0; i < 360; i += 360 / SIDES)
        {
            heading = i * 3.1415926535897932384626433832795 / 180;
            glVertex3d(cos(heading), sin(heading), depth);
        }
    glEnd();
}


/****************************************************
 *                  intake_exhaust                  *
 ****************************************************
 * Draws the intake/exhaust                         *
 ****************************************************/
void intake_exhaust (void)
{
    static GLfloat vertexValues[] = {
        0.00, 0.00, 0.0,    //0  rect1
        11.0, 0.00, 0.0,    //1
        11.0, 27.0, 0.0,    //2
        0.00, 27.0, 0.0,    //3_  end

        20.0, 0.00, 0.0,    //4  rect2
        31.0, 0.00, 0.0,    //5
        31.0, 27.0, 0.0,    //6
        20.0, 27.0, 0.0,    //7_  end

        40.0, 0.00, 0.0,    //8  rect3
        51.0, 0.00, 0.0,    //9
        51.0, 27.0, 0.0,    //10
        40.0, 27.0, 0.0,    //11_ end

        60.0, 0.00, 0.0,    //12 rect4
        71.0, 0.00, 0.0,    //13
        71.0, 27.0, 0.0,    //14
        60.0, 27.0, 0.0,    //15_ end

        80.0, 00.0, 0.0,    //16 rect5
        91.0, 00.0, 0.0,    //17
        91.0, 27.0, 0.0,    //18
        80.0, 27.0, 0.0,    //19_ end
    };
    static GLfloat vertexValues2[] = {
        0.00, 0.00, 0.0,    //0  rect1
        11.0, 0.00, 0.0,    //1
        11.0, 27.0, 0.0,    //2
        0.00, 27.0, 0.0,    //3_  end

        20.0, 0.00, 0.0,    //4  rect2
        31.0, 0.00, 0.0,    //5
        31.0, 27.0, 0.0,    //6
        20.0, 27.0, 0.0,    //7_  end

        40.0, 0.00, 0.0,    //8  rect3
        51.0, 0.00, 0.0,    //9
        51.0, 27.0, 0.0,    //10
        40.0, 27.0, 0.0,    //11_ end

        60.0, 0.00, 0.0,    //12 rect4
        71.0, 0.00, 0.0,    //13
        71.0, 27.0, 0.0,    //14
        60.0, 27.0, 0.0,    //15_ end

        80.0, 00.0, 0.0,    //16 rect5
        91.0, 00.0, 0.0,    //17
        91.0, 27.0, 0.0,    //18
        80.0, 27.0, 0.0,    //19_ end
    };

    glVertexPointer(3, GL_FLOAT, 3*sizeof(GLfloat), &vertexValues[0]);

    //Define pieces here
    static GLubyte name[] = {0, 0, 0, 0};
    static GLubyte rect1[] = {0, 1, 2, 3};
    static GLubyte rect2[] = {4, 5, 6, 7};
    static GLubyte rect3[] = {8, 9, 10, 11};
    static GLubyte rect4[] = {12, 13, 14, 15};
    static GLubyte rect5[] = {16, 17, 18, 19};

    static GLsizei count[] = {
        4, 4, 4, 4, 4,
    };

    static GLvoid *indices[] = {
        rect1, rect2, rect3, rect4, rect5
    };

    glMultiDrawElements(GL_POLYGON, count, GL_UNSIGNED_BYTE, indices, 5);
}


/****************************************************
 *                      rotor                       *
 ****************************************************
 * Draws the rotor and its outline                  *
 ****************************************************/
void rotor (void)
{
    static GLfloat vertexValues[] = {
        -76.0, 44.0, 0.0,   //0
        -51.0, 53.0, 0.0,   //1
        -26.0, 58.0, 0.0,   //2
        0.0, 60.0, 0.0,     //3
        26.0, 58.0, 0.0,    //4
        51.0, 53.0, 0.0,    //5
        76.0, 44.0, 0.0,    //6
        72.0, 20.0, 0.0,    //7
        65.0, -2.0, 0.0,    //8
        55.0, -25.0, 0.0,   //9
        41.0, -46.0, 0.0,   //10
        24.0, -67.0, 0.0,   //11
        0.0, -88.0, 0.0,    //12
        -24.0, -67.0, 0.0,  //13
        -41.0, -46.0, 0.0,  //14
        -55.0, -25.0, 0.0,  //15
        -65.0, -2.0, 0.0,   //16
        -72.0, 20.0, 0.0,   //17
    };
    static GLfloat vertexValues2[] = {
        -76.0, 44.0, -20.0,   //0
        -51.0, 53.0, -20.0,   //1
        -26.0, 58.0, -20.0,   //2
        0.0, 60.0, -20.0,     //3
        26.0, 58.0, -20.0,    //4
        51.0, 53.0, -20.0,    //5
        76.0, 44.0, -20.0,    //6
        72.0, 20.0, -20.0,    //7
        65.0, -2.0, -20.0,    //8
        55.0, -25.0, -20.0,   //9
        41.0, -46.0, -20.0,   //10
        24.0, -67.0, -20.0,   //11
        0.0, -88.0, -20.0,    //12
        -24.0, -67.0, -20.0,  //13
        -41.0, -46.0, -20.0,  //14
        -55.0, -25.0, -20.0,  //15
        -65.0, -2.0, -20.0,   //16
        -72.0, 20.0, -20.0,   //17
    };

    glVertexPointer(3, GL_FLOAT, 3*sizeof(GLfloat), &vertexValues[0]);

    static GLubyte rotor[] = {
        0, 1, 2, 3, 4, 5, 6, 
        7, 8, 9, 10, 11, 12, 
        13, 14, 15, 16, 17,
    };

    static GLsizei count[] = {
        18,
    };

    static GLvoid *indices[] = {
        rotor,
    };

    glMultiDrawElements(GL_LINE_LOOP, count, GL_UNSIGNED_BYTE, indices, 1);

    glDrawElements(GL_LINE_LOOP, 18, GL_UNSIGNED_BYTE, rotor);

    glVertexPointer(3, GL_FLOAT, 3*sizeof(GLfloat), &vertexValues2[0]);

    static GLubyte rotor2[] = {
        0, 1, 2, 3, 4, 5, 6, 
        7, 8, 9, 10, 11, 12, 
        13, 14, 15, 16, 17,
    };

    static GLsizei count2[] = {
        18,
    };

    static GLvoid *indices2[] = {
        rotor2,
    };

    glMultiDrawElements(GL_LINE_LOOP, count2, GL_UNSIGNED_BYTE, indices2, 1);

    glDrawElements(GL_LINE_LOOP, 18, GL_UNSIGNED_BYTE, rotor2);
}


/****************************************************
 *              eccentric_shaft                     *
 ****************************************************
 * Draws the outline of the eccentric shaft         *
 ****************************************************/
void eccentric_shaft (void)
{
    unit_circle(0.0);
}


/****************************************************
 *                      housing                     *
 ****************************************************
 * Draws the stator housing and its outline         *
 ****************************************************/
void housing (void)
{
    // -401, -417
    static GLfloat vertexValues[] = {
        -182,  123, 0,    //0     outer_outline
        -134,  123, 0,    //1
        -115,  143, 0,    //2
         -95,  160, 0,    //3
         -71,  173, 0,    //4
         -49,  182, 0,    //5
         -30,  186, 0,    //6
          -9,  189, 0,    //7
           5,  189, 0,    //8     peak
          21,  188, 0,    //9
          38,  185, 0,    //10
          62,  177, 0,    //11
          84,  165, 0,    //12
         101,  152, 0,    //13
         115,  137, 0,    //14
         128,  120, 0,    //15
         138,  101, 0,    //16
         146,   77, 0,    //17
         150,   52, 0,    //18
         150,  -50, 0,    //19    right side
         145,  -78, 0,    //20
         136, -103, 0,    //21
         124, -124, 0,    //22
         111, -140, 0,    //23
          94, -156, 0,    //24
          72, -170, 0,    //25
          49, -180, 0,    //26
          21, -186, 0,    //27
           3, -187, 0,    //28    valley
         -23, -185, 0,    //29
         -48, -178, 0,    //30
         -70, -168, 0,    //31
         -90, -154, 0,    //32
        -106, -139, 0,    //33
        -118, -124, 0,    //34
        -127, -109, 0,    //35
        -134,  -95, 0,    //36
        -182,  -95, 0,    //37 end    outer_outline

        -182,  -76, 0,    //38    inner_outline
        -120,  -76, 0,    //39
        -114,  -93, 0,    //40
        -106, -108, 0,    //41
         -93, -125, 0,    //42
         -76, -141, 0,    //43
         -58, -153, 0,    //44
         -37, -162, 0,    //45
         -15, -167, 0,    //46
           4, -169, 0,    //47
          26, -166, 0,    //48
          46, -161, 0,    //49
          69, -150, 0,    //50
          88, -136, 0,    //51
         103, -120, 0,    //52
         115, -102, 0,    //53
         125,  -81, 0,    //54
         130,  -61, 0,    //55
         131,  -42, 0,    //56
         131,  -22, 0,    //57
         129,  -13, 0,    //58
         127,   -3, 0,    //59
         127,    8, 0,    //60
         129,   17, 0,    //61
         131,   24, 0,    //62
         131,   52, 0,    //63
         127,   75, 0,    //64
         119,   97, 0,    //65
         108,  116, 0,    //66
          93,  133, 0,    //67
          77,  147, 0,    //68
          56,  159, 0,    //69
          37,  166, 0,    //70
          15,  170, 0,    //71
          -3,  171, 0,    //72 inner peak
         -26,  167, 0,    //73
         -49,  160, 0,    //74
         -69,  152, 0,    //75
         -86,  141, 0,    //76
        -104,  125, 0,    //77
        -120,  104, 0,    //78
        -182,  104, 0,    //79 end    inner_outline

        -182,   77, 0,    //80 betw_outline
        -125,   77, 0,    //81
        -125,  -48, 0,    //82
        -182,  -48, 0,    //83
        -182,  -29, 0,    //84
        -144,  -29, 0,    //85
        -144,   58, 0,    //86
        -182,   58, 0,    //87
    };
    static GLfloat vertexValues2[] = {
        -182,  123, -20,    //0     outer_outline
        -134,  123, -20,    //1
        -115,  143, -20,    //2
         -95,  160, -20,    //3
         -71,  173, -20,    //4
         -49,  182, -20,    //5
         -30,  186, -20,    //6
          -9,  189, -20,    //7
           5,  189, -20,    //8     peak
          21,  188, -20,    //9
          38,  185, -20,    //10
          62,  177, -20,    //11
          84,  165, -20,    //12
         101,  152, -20,    //13
         115,  137, -20,    //14
         128,  120, -20,    //15
         138,  101, -20,    //16
         146,   77, -20,    //17
         150,   52, -20,    //18
         150,  -50, -20,    //19    right side
         145,  -78, -20,    //20
         136, -103, -20,    //21
         124, -124, -20,    //22
         111, -140, -20,    //23
          94, -156, -20,    //24
          72, -170, -20,    //25
          49, -180, -20,    //26
          21, -186, -20,    //27
           3, -187, -20,    //28    valley
         -23, -185, -20,    //29
         -48, -178, -20,    //30
         -70, -168, -20,    //31
         -90, -154, -20,    //32
        -106, -139, -20,    //33
        -118, -124, -20,    //34
        -127, -109, -20,    //35
        -134,  -95, -20,    //36
        -182,  -95, -20,    //37 end    outer_outline

        -182,  -76, -20,    //38    inner_outline
        -120,  -76, -20,    //39
        -114,  -93, -20,    //40
        -106, -108, -20,    //41
         -93, -125, -20,    //42
         -76, -141, -20,    //43
         -58, -153, -20,    //44
         -37, -162, -20,    //45
         -15, -167, -20,    //46
           4, -169, -20,    //47
          26, -166, -20,    //48
          46, -161, -20,    //49
          69, -150, -20,    //50
          88, -136, -20,    //51
         103, -120, -20,    //52
         115, -102, -20,    //53
         125,  -81, -20,    //54
         130,  -61, -20,    //55
         131,  -42, -20,    //56
         131,  -22, -20,    //57
         129,  -13, -20,    //58
         127,   -3, -20,    //59
         127,    8, -20,    //60
         129,   17, -20,    //61
         131,   24, -20,    //62
         131,   52, -20,    //63
         127,   75, -20,    //64
         119,   97, -20,    //65
         108,  116, -20,    //66
          93,  133, -20,    //67
          77,  147, -20,    //68
          56,  159, -20,    //69
          37,  166, -20,    //70
          15,  170, -20,    //71
          -3,  171, -20,    //72 inner peak
         -26,  167, -20,    //73
         -49,  160, -20,    //74
         -69,  152, -20,    //75
         -86,  141, -20,    //76
        -104,  125, -20,    //77
        -120,  104, -20,    //78
        -182,  104, -20,    //79 end    inner_outline

        -182,   77, -20,    //80 betw_outline
        -125,   77, -20,    //81
        -125,  -48, -20,    //82
        -182,  -48, -20,    //83
        -182,  -29, -20,    //84
        -144,  -29, -20,    //85
        -144,   58, -20,    //86
        -182,   58, -20,    //87
    };

    glVertexPointer(3, GL_FLOAT, 3*sizeof(GLfloat), &vertexValues[0]);

    static GLubyte outline[] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
        10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
        20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
        30, 31, 32, 33, 34, 35, 36, 37,
    };

    static GLubyte inner_outline[] = {
        37, 38, 39,
        40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
        50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
        60, 61, 62, 63, 64, 65, 66, 67, 68, 69,
        70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
        0,
    };

    static GLubyte betw_outline[] = {
        80, 81, 82, 83, 84, 85, 86, 87,
        80,
    };

    static GLsizei count[] = {
        38, 44, 9,
    };

    static GLvoid *indices[] = {
        outline, inner_outline, betw_outline,
    };

    glMultiDrawElements(GL_LINE_STRIP, count, GL_UNSIGNED_BYTE, indices, 3);

    glVertexPointer(3, GL_FLOAT, 3*sizeof(GLfloat), &vertexValues2[0]);

    static GLubyte outline2[] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
        10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
        20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
        30, 31, 32, 33, 34, 35, 36, 37,
    };

    static GLubyte inner_outline2[] = {
        37, 38, 39,
        40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
        50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
        60, 61, 62, 63, 64, 65, 66, 67, 68, 69,
        70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
        0,
    };

    static GLubyte betw_outline2[] = {
        80, 81, 82, 83, 84, 85, 86, 87,
        80,
    };

    static GLsizei count2[] = {
        38, 44, 9,
    };

    static GLvoid *indices2[] = {
        outline2, inner_outline2, betw_outline2,
    };

    glMultiDrawElements(GL_LINE_STRIP, count2, GL_UNSIGNED_BYTE, indices2, 3);
}


/****************************************************
 *                  spark_plug                      *
 ****************************************************
 * Draws the spark plug and its outline. Can choose *
 * not to use the preset colors so that picking cam *
 * be done
 ****************************************************/
void spark_plug (void)
{
    static GLfloat vertexValues[] = {
        0.0, 0.0, 0.0,      //0
        0.0, 10.0, 0.0,     //1
        17.0, 10.0, 0.0,    //2
        17.0, 0.0, 0.0,     //3

        17.0, 12.0, 0.0,    //4
        23.0, 12.0, 0.0,    //5
        23.0, 10.0, 0.0,    //6
        44.0, 10.0, 0.0,    //7
        44.0, 0.0, 0.0,     //8
        23.0, 0.0, 0.0,     //9
        23.0, -2.0, 0.0,    //10
        17.0, -2.0, 0.0,    //11

        44.0, 8.0, 0.0,     //12
        60.0, 8.0, 0.0,     //13
        60.0, 2.0, 0.0,     //14
        44.0, 2.0, 0.0,     //15
    };

    glVertexPointer(3, GL_FLOAT, 3*sizeof(GLfloat), &vertexValues[0]);

    static GLubyte leftquad[] = {
        0, 1, 2, 3,
    };
    static GLubyte vertquad[] = {
        4, 5, 10, 11,
    };

    static GLubyte horzquad[] = {
        6, 7, 8, 9,
    };

    static GLubyte center[] = {
        4, 5, 6, 7, 8, 9, 10, 11,
    };

    static GLubyte rightquad[] = {
        12, 13, 14, 15,
    };

    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, leftquad);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, vertquad);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, horzquad);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, rightquad);

    glDrawElements(GL_LINE_LOOP, 4, GL_UNSIGNED_BYTE, leftquad);
    glDrawElements(GL_LINE_LOOP, 8, GL_UNSIGNED_BYTE, center);
}


/****************************************************
 *                    sparks                        *
 ****************************************************
 * Draws the sparks produced by the spark plugs     *
 ****************************************************/
void sparks (void)
{
    static GLfloat vertexValues[] = {
        2.0, 1.0, 0.0,      //0
        0.0, -13.0, 0.0,    //1
        -1.0, 4.0, 0.0,     //2
        -7.0, -11.0, 0.0,   //3
        -3.0, -3.0, 0.0,    //4
        -11.0, -6.0, 0.0,   //5
        -5.0, 1.0, 0.0,     //6
        -14.0, 2.0, 0.0,    //7
        -6.0, 6.0, 0.0,     //8
        -13.0, 9.0, 0.0,    //9
        -6.0, 10.0, 0.0,    //10
        -11.0, 17.0, 0.0,   //11
        -3.0, 13.0, 0.0,    //12
        -5.0, 22.0, 0.0,    //13
        0.0, 15.0, 0.0,     //14
        0.0, 24.0, 0.0,     //15
        2.0, 10.0, 0.0,     //16
    };

    glVertexPointer(3, GL_FLOAT, 3*sizeof(GLfloat), &vertexValues[0]);

    static GLubyte spark_tips[] = {
        0, 1, 2,
        2, 3, 4,
        4, 5, 6,
        6, 7, 8,
        8, 9, 10,
        10, 11, 12,
        12, 13, 14,
        14, 15, 16,
    };

    static GLubyte spark_body[] = {
        0, 2, 4, 6, 8, 10, 12, 14, 16,
    };

    glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_BYTE, spark_tips);
    glDrawElements(GL_POLYGON, 9, GL_UNSIGNED_BYTE, spark_body);
}
