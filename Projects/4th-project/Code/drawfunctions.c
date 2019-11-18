/****************************************************
 *                drawfunctions.c                   *
 ****************************************************
 *  Author:     Justin Weigle                       *
 *  Edited:     18 Nov 2019                         *
 ****************************************************
 * Contains the functions for drawing the parts of  *
 * a Wankel rotary engine in 3d                     *
 ****************************************************/

#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include "drawfunctions.h"

const int SIDES = 360;


/****************************************************
 *              inner_gear_surface                  *
 ****************************************************
 * Draws the surface of a gear with teeth that are  *
 * facing inward                                    *
 ****************************************************/
void inner_gear_surface (GLfloat depth, int gear_spacing)
{
    glBegin(GL_TRIANGLE_STRIP);
        double heading;
        int counter = 0;
        int toggle = 1;
        for (int i = 0; i <= 360; i += 360 / SIDES)
        {
            heading = i * 3.1415926535897932384626433832795 / 180;
            glVertex3d(cos(heading) * 1.3, sin(heading) * 1.3, depth);

            if (toggle)
            {
                glVertex3d(cos(heading), sin(heading), depth);
            }
            else
            {
                glVertex3d(cos(heading) * 0.9, sin(heading) * 0.9, depth);
            }

            counter += 1;
            if (counter == gear_spacing)
            {
                counter = 0;
                toggle = 1 - toggle;
            }
        }
    glEnd();
}


/****************************************************
 *               outer_gear_surface                 *
 ****************************************************
 * Draws the surface of a gear with teeth that are  *
 * facing outward                                   *
 ****************************************************/
void outer_gear_surface (GLfloat depth, int gear_spacing)
{
    glBegin(GL_TRIANGLE_STRIP);
        double heading;
        int counter = 0;
        int toggle = 1;
        for (int i = 0; i <= 360; i += 360 / SIDES)
        {
            heading = i * 3.1415926535897932384626433832795 / 180;
            glVertex3d(cos(heading) * 0.7, sin(heading) * 0.7, depth);

            if (toggle)
            {
                glVertex3d(cos(heading), sin(heading), depth);
            }
            else
            {
                glVertex3d(cos(heading) * 0.9, sin(heading) * 0.9, depth);
            }

            counter += 1;
            if (counter == gear_spacing)
            {
                counter = 0;
                toggle = 1 - toggle;
            }
        }
    glEnd();
}


/****************************************************
 *                gear_teeth_outline                *
 ****************************************************
 * Draws the outline of the teeth of a gear         *
 ****************************************************/
void gear_teeth_outline (int gear_spacing)
{
    glBegin(GL_TRIANGLE_STRIP);
        double heading;
        int counter = 0;
        int toggle = 1;
        for (int i = 0; i <= 360; i += 360 / SIDES)
        {
            heading = i * 3.1415926535897932384626433832795 / 180;
            if (toggle)
            {
                glVertex3d(cos(heading), sin(heading), 0);
                glVertex3d(cos(heading), sin(heading), -20);
            }
            else
            {
                glVertex3d(cos(heading) * 0.9, sin(heading) * 0.9, 0);
                glVertex3d(cos(heading) * 0.9, sin(heading) * 0.9, -20);
            }

            counter += 1;
            if (counter == gear_spacing)
            {
                counter = 0;
                toggle = 1 - toggle;
            }
        }
    glEnd();
}


/****************************************************
 *                  unit_circle                     *
 ****************************************************
 * Draws a circle where the z location is set by    *
 * depth                                            *
 ****************************************************/
void unit_circle (GLfloat depth)
{
    glBegin(GL_POLYGON);
        double heading;
        for (int i = 0; i < 360; i += 360 / SIDES)
        {
            heading = i * 3.1415926535897932384626433832795 / 180;
            glVertex3d(cos(heading), sin(heading), depth);
        }
    glEnd();
}


/****************************************************
 *                x_unit_circle                     *
 ****************************************************
 * Draws a circle where the x location is set by    *
 * x and the circle is drawn parallel to the z      *
 * axis                                             *
 ****************************************************/
void x_unit_circle (GLfloat x)
{
    glBegin(GL_POLYGON);
        double heading;
        for (int i = 0; i < 360; i += 360 / SIDES)
        {
            heading = i * 3.1415926535897932384626433832795 / 180;
            glVertex3d(x, cos(heading), sin(heading));
        }
    glEnd();
}


/****************************************************
 *                 x_disk_surface                   *
 ****************************************************
 * Draws lines on the surface of a disk's perimeter *
 * that is parallel to the x axis                   *
 ****************************************************/
void x_disk_surface (GLfloat divisions, GLfloat z1, GLfloat z2, GLfloat scale)
{
    glBegin(GL_TRIANGLE_STRIP);
        double heading;
        for (int i = 0; i <= 360; i += 360 / divisions)
        {
            heading = i * M_PI / 180;
            glVertex3d(cos(heading) * scale, sin(heading) * scale, z1);
            glVertex3d(cos(heading) * scale, sin(heading) * scale, z2);
        }
    glEnd();
}


/****************************************************
 *                  z_disk_surface                  *
 ****************************************************
 * Draws lines on the surface of a disk's perimeter *
 * that is parallel to the z axis                   *
 ****************************************************/
void z_disk_surface (GLfloat divisions, GLfloat x1, GLfloat x2, GLfloat scale)
{
    glBegin(GL_TRIANGLE_STRIP);
        double heading;
        for (int i = 0; i <= 360; i += 360 / divisions)
        {
            heading = i * M_PI / 180;
            glVertex3d(x1, cos(heading) * scale, sin(heading) * scale);
            glVertex3d(x2, cos(heading) * scale, sin(heading) * scale);
        }
    glEnd();
}


/****************************************************
 *                 eccentric_shaft                  *
 ****************************************************
 * Draws the eccentric shaft                        *
 ****************************************************/
void eccentric_shaft (GLfloat ECC_SHFT_HEADING, GLfloat ECC_SHFT_I)
{
    glPushMatrix();
        glTranslatef((cos(ECC_SHFT_HEADING) * 26), (sin(ECC_SHFT_HEADING) * 26), 0.0);
        glRotatef((-ECC_SHFT_I/3) + 30, 0.0, 0.0, 1.0);
        glScalef(60.0, 60.0, 1.0);
        x_disk_surface(60, -20, -80, 1.3);
        glPushMatrix();
            glScalef(1.3, 1.3, 1.0);
            glBegin(GL_TRIANGLE_STRIP);
                double heading;
                for (int i = 0; i <= 360; i += 360 / (SIDES / 6))
                {
                    heading = i * 3.1415926535897932384626433832795 / 180;
                    glVertex3d(cos(heading), sin(heading), -20);
                    glVertex3d(0.0, 0.0, -20.0);
                }
            glEnd();
            glBegin(GL_TRIANGLE_STRIP);
                for (int i = 0; i <= 360; i += 360 / (SIDES / 6))
                {
                    heading = i * 3.1415926535897932384626433832795 / 180;
                    glVertex3d(cos(heading), sin(heading), -80);
                    glVertex3d(0.0, 0.0, -80.0);
                }
            glEnd();
        glPopMatrix();
    glPopMatrix();
    glPushMatrix();
        glRotatef((-ECC_SHFT_I/3) + 30, 0.0, 0.0, 1.0);
        glScalef(30.0, 30.0, 1.0);
        x_disk_surface(30.0, 10.0, -20.0, 0.88);
        x_disk_surface(30.0, 40.0, 10.0, 0.44);
        x_disk_surface(30.0, -80, -120, 0.88);
        glPushMatrix();
            glScalef(0.88, 0.88, 1.0);
            glBegin(GL_TRIANGLE_STRIP);
                for (int i = 0; i <= 360; i += 360 / (SIDES / 12))
                {
                    heading = i * 3.1415926535897932384626433832795 / 180;
                    glVertex3d(cos(heading), sin(heading), 10);
                    glVertex3d(0.0, 0.0, 10.0);
                }
            glEnd();
            glBegin(GL_TRIANGLE_STRIP);
                for (int i = 0; i <= 360; i += 360 / (SIDES / 12))
                {
                    heading = i * 3.1415926535897932384626433832795 / 180;
                    glVertex3d(cos(heading), sin(heading), -120);
                    glVertex3d(0.0, 0.0, -120.0);
                }
            glEnd();
        glPopMatrix();
        glPushMatrix();
            glScalef(0.44, 0.44, 1.0);
            glBegin(GL_TRIANGLE_STRIP);
                for (int i = 0; i <= 360; i += 360 / (SIDES / 24))
                {
                    heading = i * 3.1415926535897932384626433832795 / 180;
                    glVertex3d(cos(heading), sin(heading), 40);
                    glVertex3d(0.0, 0.0, 40.0);
                }
            glEnd();
        glPopMatrix();
    glPopMatrix();
}


/****************************************************
 *                  intake_exhaust                  *
 ****************************************************
 * Draws the intake/exhaust                         *
 ****************************************************/
void intake_exhaust (void)
{
    z_disk_surface(20.0, 0.0, 35.0, 15.0);
}


/****************************************************
 *                      rotor                       *
 ****************************************************
 * Draws the rotor                                  *
 ****************************************************/
void rotor (void)
{
    static GLfloat vertexValues[] = {
        -76.0,  44.0,   0.0,    //0
        -51.0,  53.0,   0.0,    //1
        -26.0,  58.0,   0.0,    //2
          0.0,  60.0,   0.0,    //3
         26.0,  58.0,   0.0,    //4
         51.0,  53.0,   0.0,    //5
         76.0,  44.0,   0.0,    //6
         72.0,  20.0,   0.0,    //7
         65.0,  -2.0,   0.0,    //8
         55.0, -25.0,   0.0,    //9
         41.0, -46.0,   0.0,    //10
         24.0, -67.0,   0.0,    //11
          0.0, -88.0,   0.0,    //12
        -24.0, -67.0,   0.0,    //13
        -41.0, -46.0,   0.0,    //14
        -55.0, -25.0,   0.0,    //15
        -65.0,  -2.0,   0.0,    //16
        -72.0,  20.0,   0.0,    //17

        -76.0,  44.0, -60.0,    //18
        -51.0,  53.0, -60.0,    //19
        -26.0,  58.0, -60.0,    //20
          0.0,  60.0, -60.0,    //21
         26.0,  58.0, -60.0,    //22
         51.0,  53.0, -60.0,    //23
         76.0,  44.0, -60.0,    //24
         72.0,  20.0, -60.0,    //25
         65.0,  -2.0, -60.0,    //26
         55.0, -25.0, -60.0,    //27
         41.0, -46.0, -60.0,    //28
         24.0, -67.0, -60.0,    //29
          0.0, -88.0, -60.0,    //30
        -24.0, -67.0, -60.0,    //31
        -41.0, -46.0, -60.0,    //32
        -55.0, -25.0, -60.0,    //33
        -65.0,  -2.0, -60.0,    //34
        -72.0,  20.0, -60.0,    //35
    };

    glVertexPointer(3, GL_FLOAT, 3*sizeof(GLfloat), &vertexValues[0]);

    static GLubyte rotor_perim[] = {
        0, 18, 1, 19, 2, 20, 3, 21, 4, 22,
        5, 23, 6, 24, 7, 25, 8, 26, 9, 27,
        10, 28, 11, 29, 12, 30, 13, 31, 14, 32,
        15, 33, 16, 34, 17, 35, 0, 18,
    };

    static GLsizei count[] = {
        38,
    };

    static GLvoid *indices[] = {
        rotor_perim,
    };

    glMultiDrawElements(GL_TRIANGLE_STRIP, count, GL_UNSIGNED_BYTE, indices, 1);

    glPushMatrix();
        glBegin(GL_TRIANGLE_STRIP);
            double heading;
            int stagger = 0;
            int index = 7 * 3;
            for (int i = 0; i <= 360; i += 360 / SIDES)
            {
                heading = i * 3.1415926535897932384626433832795 / 180;
                glVertex3d(cos(heading) * 47.32, sin(heading) * 47.32, 0);
                glVertex3d(vertexValues[index],
                        vertexValues[index+1],
                        vertexValues[index+2]);

                stagger++;
                if (stagger == 20)
                {
                    stagger = 0;
                    index -= 3;
                    if (index < 0)
                        index = 17 * 3;
                }
            }
        glEnd();
        glBegin(GL_TRIANGLE_STRIP);
            stagger = 0;
            index = 25 * 3;
            for (int i = 0; i <= 360; i += 360 / SIDES)
            {
                heading = i * 3.1415926535897932384626433832795 / 180;
                glVertex3d(cos(heading) * 47.32, sin(heading) * 47.32, -60);
                glVertex3d(vertexValues[index],
                        vertexValues[index+1],
                        vertexValues[index+2]);

                stagger++;
                if (stagger == 20)
                {
                    stagger = 0;
                    index -= 3;
                    if (index < 18 * 3)
                        index = 35 * 3;
                }
            }
        glEnd();
    glPopMatrix();
}


/****************************************************
 *                      housing                     *
 ****************************************************
 * Draws the stator housing                         *
 ****************************************************/
void housing (void)
{
    static GLfloat vertexValues[] = {
        -128,  120, 0,    //0   outer_outline
        -109,  143, 0,    //1
         -89,  160, 0,    //2
         -65,  173, 0,    //3
         -43,  182, 0,    //4
         -24,  186, 0,    //5
          -3,  189, 0,    //6
           5,  189, 0,    //7   peak
          21,  188, 0,    //8
          38,  185, 0,    //9
          62,  177, 0,    //10
          84,  165, 0,    //11
         101,  152, 0,    //12
         115,  137, 0,    //13
         128,  120, 0,    //14
         138,  101, 0,    //15
         146,   77, 0,    //16
         150,   52, 0,    //17
         150,  -50, 0,    //18  right side
         145,  -78, 0,    //19
         136, -103, 0,    //20
         124, -124, 0,    //21
         111, -140, 0,    //22
          94, -156, 0,    //23
          72, -170, 0,    //24
          49, -180, 0,    //25
          21, -186, 0,    //26
           3, -187, 0,    //27  valley
          -8, -187, 0,    //28
         -36, -182, 0,    //29
         -58, -175, 0,    //30
         -68, -170, 0,    //31
         -88, -158, 0,    //32
        -113, -132, 0,    //33
        -130, -109, 0,    //34
        -136,  -95, 0,    //35
        -140,  -85, 0,    //36
        -142,  -75, 0,    //37
        -144,  -65, 0,    //38
        -145,  -55, 0,    //39
        -146,  -50, 0,    //40
        -146,   50, 0,    //41
        -145,   55, 0,    //42
        -144,   65, 0,    //43
        -143,   75, 0,    //44
        -141,   85, 0,    //45
        -137,   95, 0,    //46
        -132,  110, 0,    //47  end    outer_outline

        -114,  104, 0,    //48  inner_outline
         -98,  125, 0,    //49
         -80,  141, 0,    //50
         -63,  152, 0,    //51
         -43,  162, 0,    //52
         -20,  169, 0,    //53
          -3,  171, 0,    //54  inner peak
          15,  170, 0,    //55
          37,  166, 0,    //56
          56,  159, 0,    //57
          77,  147, 0,    //58
          93,  133, 0,    //59
         108,  116, 0,    //60
         119,   97, 0,    //61
         127,   75, 0,    //62
         131,   52, 0,    //63
         131,   24, 0,    //64
         129,   17, 0,    //65
         127,    8, 0,    //66
         127,   -3, 0,    //67
         129,  -13, 0,    //68
         131,  -22, 0,    //69
         131,  -42, 0,    //70
         130,  -61, 0,    //71
         125,  -81, 0,    //72
         115, -102, 0,    //73
         103, -120, 0,    //74
          88, -136, 0,    //75
          69, -150, 0,    //76
          46, -161, 0,    //77
          26, -166, 0,    //78
           4, -169, 0,    //79
         -17, -167, 0,    //80
         -39, -162, 0,    //80
         -60, -153, 0,    //82
         -78, -141, 0,    //83
         -95, -125, 0,    //84
        -108, -108, 0,    //85
        -116,  -93, 0,    //86
        -122,  -76, 0,    //87
        -124,  -65, 0,    //88
        -125,  -55, 0,    //89
        -126,  -50, 0,    //90
        -124,  -25, 0,    //91
        -122,    0, 0,    //92
        -124,   25, 0,    //93
        -126,   50, 0,    //94
        -125,   55, 0,    //95
        -124,   65, 0,    //96
        -123,   75, 0,    //97
        -121,   85, 0,    //98
        -117,   95, 0,    //99  end     inner_outline

        // -Z ... add 100 to index: 100 through 199
        -128,  120, -60,    //0   outer_outline
        -109,  143, -60,    //1
         -89,  160, -60,    //2
         -65,  173, -60,    //3
         -43,  182, -60,    //4
         -24,  186, -60,    //5
          -3,  189, -60,    //6
           5,  189, -60,    //7   peak
          21,  188, -60,    //8
          38,  185, -60,    //9
          62,  177, -60,    //10
          84,  165, -60,    //11
         101,  152, -60,    //12
         115,  137, -60,    //13
         128,  120, -60,    //14
         138,  101, -60,    //15
         146,   77, -60,    //16
         150,   52, -60,    //17
         150,  -50, -60,    //18  right side
         145,  -78, -60,    //19
         136, -103, -60,    //20
         124, -124, -60,    //21
         111, -140, -60,    //22
          94, -156, -60,    //23
          72, -170, -60,    //24
          49, -180, -60,    //25
          21, -186, -60,    //26
           3, -187, -60,    //27  valley
          -8, -187, -60,    //28
         -36, -182, -60,    //29
         -58, -175, -60,    //30
         -68, -170, -60,    //31
         -88, -158, -60,    //32
        -113, -132, -60,    //33
        -130, -109, -60,    //34
        -136,  -95, -60,    //35
        -140,  -85, -60,    //36
        -142,  -75, -60,    //37
        -144,  -65, -60,    //38
        -145,  -55, -60,    //39
        -146,  -50, -60,    //40
        -146,   50, -60,    //41
        -145,   55, -60,    //42
        -144,   65, -60,    //43
        -143,   75, -60,    //44
        -141,   85, -60,    //45
        -137,   95, -60,    //46
        -132,  110, -60,    //47  end    outer_outline

        -114,  104, -60,    //48  inner_outline
         -98,  125, -60,    //49
         -80,  141, -60,    //50
         -63,  152, -60,    //51
         -43,  162, -60,    //52
         -20,  169, -60,    //53
          -3,  171, -60,    //54  inner peak
          15,  170, -60,    //55
          37,  166, -60,    //56
          56,  159, -60,    //57
          77,  147, -60,    //58
          93,  133, -60,    //59
         108,  116, -60,    //60
         119,   97, -60,    //61
         127,   75, -60,    //62
         131,   52, -60,    //63
         131,   24, -60,    //64
         129,   17, -60,    //65
         127,    8, -60,    //66
         127,   -3, -60,    //67
         129,  -13, -60,    //68
         131,  -22, -60,    //69
         131,  -42, -60,    //70
         130,  -61, -60,    //71
         125,  -81, -60,    //72
         115, -102, -60,    //73
         103, -120, -60,    //74
          88, -136, -60,    //75
          69, -150, -60,    //76
          46, -161, -60,    //77
          26, -166, -60,    //78
           4, -169, -60,    //79
         -17, -167, -60,    //80
         -39, -162, -60,    //80
         -60, -153, -60,    //82
         -78, -141, -60,    //83
         -95, -125, -60,    //84
        -108, -108, -60,    //85
        -116,  -93, -60,    //86
        -122,  -76, -60,    //87
        -124,  -65, -60,    //88
        -125,  -55, -60,    //89
        -126,  -50, -60,    //90
        -124,  -25, -60,    //91
        -122,    0, -60,    //92
        -124,   25, -60,    //93
        -126,   50, -60,    //94
        -125,   55, -60,    //95
        -124,   65, -60,    //96
        -123,   75, -60,    //97
        -121,   85, -60,    //98
        -117,   95, -60,    //99  end     inner_outline
    };

    glVertexPointer(3, GL_FLOAT, 3*sizeof(GLfloat), &vertexValues[0]);

    static GLubyte surface_front[] = {
         0, 48,  1, 49,  2, 50,  3, 51,  4, 52,
         5, 53,  6, 54,  7, 55,  8, 56,  9, 57,
        10, 58, 11, 59, 12, 60, 13, 61, 14, 62,
        15, 63, 16, 64, 17, 65, 17, 66, 17, 67,
        18, 68, 18, 69, 18, 70, 19, 71, 20, 72,
        21, 73, 22, 74, 23, 75, 24, 76, 25, 77,
        26, 78, 27, 79, 28, 80, 29, 81, 30, 82,
        31, 83, 32, 84, 33, 85, 34, 86, 35, 87,
        36, 88, 37, 89, 38, 90, 39, 91, 40, 92,
        41, 93, 42, 94, 43, 95, 44, 96, 45, 97,
        46, 98, 47, 99,  0, 48,
    };

    static GLubyte surface_back[] = {
        100, 148, 101, 149, 102, 150, 103, 151, 104, 152,
        105, 153, 106, 154, 107, 155, 108, 156, 109, 157,
        110, 158, 111, 159, 112, 160, 113, 161, 114, 162,
        115, 163, 116, 164, 117, 165, 117, 166, 117, 167,
        118, 168, 118, 169, 118, 170, 119, 171, 120, 172,
        121, 173, 122, 174, 123, 175, 124, 176, 125, 177,
        126, 178, 127, 179, 128, 180, 129, 181, 130, 182,
        131, 183, 132, 184, 133, 185, 134, 186, 135, 187,
        136, 188, 137, 189, 138, 190, 139, 191, 140, 192,
        141, 193, 142, 194, 143, 195, 144, 196, 145, 197,
        146, 198, 147, 199, 100, 148,
    };

    static GLubyte surface_outin[] = {
        0, 100, 1, 101, 2, 102, 3, 103, 4, 104,
        5, 105, 6, 106, 7, 107, 8, 108, 9, 109,
        10, 110, 11, 111, 12, 112, 13, 113, 14, 114,
        15, 115, 16, 116, 17, 117, 18, 118, 19, 119,
        20, 120, 21, 121, 22, 122, 23, 123, 24, 124,
        25, 125, 26, 126, 27, 127, 28, 128, 29, 129,
        30, 130, 31, 131, 32, 132, 33, 133, 34, 134,
        35, 135, 36, 136, 37, 137, 38, 138, 39, 139,
        40, 140, 41, 141, 42, 142, 43, 143, 44, 144,
        45, 145, 46, 146, 47, 147, 48, 148, 49, 149,
        50, 150, 51, 151, 52, 152, 53, 153, 54, 154,
        55, 155, 56, 156, 57, 157, 58, 158, 59, 159,
        60, 160, 61, 161, 62, 162, 63, 163, 64, 164,
        65, 165, 66, 166, 67, 167, 68, 168, 69, 169,
        70, 170, 71, 171, 72, 172, 73, 173, 74, 174,
        75, 175, 76, 176, 77, 177, 78, 178, 79, 179,
        80, 180, 81, 181, 82, 182, 83, 183, 84, 184,
        85, 185, 86, 186, 87, 187, 88, 188, 89, 189,
        90, 190, 91, 191, 92, 192, 93, 193, 94, 194,
        95, 195, 96, 196, 97, 197, 98, 198, 99, 199,
    };

    static GLvoid *indices[] = {
        surface_front,
        surface_back,
        surface_outin,
    };
    static GLsizei count[] = {
        106,
        106,
        200,
    };

    glMultiDrawElements(GL_TRIANGLE_STRIP, count, GL_UNSIGNED_BYTE, indices, 3);
}


/****************************************************
 *                  spark_plug                      *
 ****************************************************
 * Draws the spark plug and its surface             *
 ****************************************************/
void spark_plug (void)
{
    z_disk_surface(10.0, 0.0, 17.0, 5.0);
    glPushMatrix();
        glScalef(1.0, 5.0, 5.0);
        x_unit_circle(0.0);
        x_unit_circle(17.0);
    glPopMatrix();
    z_disk_surface(12.0, 17.0, 23.0, 6.0);
    glPushMatrix();
        glScalef(1.0, 6.0, 6.0);
        x_unit_circle(17.0);
        x_unit_circle(23.0);
    glPopMatrix();
    z_disk_surface(10.0, 23.0, 44.0, 5.0);
    glPushMatrix();
        glScalef(1.0, 5.0, 5.0);
        x_unit_circle(23.0);
        x_unit_circle(44.0);
    glPopMatrix();
    z_disk_surface(8.0, 44.0, 60.0, 3.0);
    glPushMatrix();
        glScalef(1.0, 3.0, 3.0);
        x_unit_circle(44.0);
        x_unit_circle(60.0);
    glPopMatrix();
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
