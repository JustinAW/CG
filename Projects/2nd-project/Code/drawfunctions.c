#include <GL/glut.h>
#include <math.h>
#include "drawfunctions.h"

const int SIDES = 360;

void gear (void)
{
    glBegin(GL_LINE_LOOP);
        double heading;
        int counter = 0;
        int toggle = 1;
        for (int i = 0; i < 360; i += 360 / SIDES)
        {
            heading = i * 3.1415926535897932384626433832795 / 180;
            if (toggle)
                glVertex2d(cos(heading), sin(heading));
            else
                glVertex2d(cos(heading) * 0.9, sin(heading) * 0.9);

            counter += 1;
            if (counter == 10)
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


void unit_circle (int i, int deg_rotation)
{
    glBegin(GL_LINE_LOOP);
        double heading;
        for (; i < deg_rotation; i += 360 / SIDES)
        {
            heading = i * 3.1415926535897932384626433832795 / 180;
            glVertex2d(cos(heading), sin(heading));
        }
    glEnd();
}


void unit_circle_fill (int i, int deg_rotation)
{
    glBegin(GL_POLYGON);
        double heading;
        for (i = 0; i < deg_rotation; i += 360 / SIDES)
        {
            heading = i * 3.1415926535897932384626433832795 / 180;
            glVertex2d(cos(heading), sin(heading));
        }
    glEnd();
}


void slider (GLint SLIDER_X, int part)
{
    int bar = 1;
    int slide = 2;

    if (part == bar)
    {
        glBegin(GL_LINES);
            glVertex2s (300, 30);
            glVertex2s (500, 30);
        glEnd();
    }
    if (part == slide)
    {
        glBegin(GL_POLYGON);
            glVertex2s (SLIDER_X, 20);
            glVertex2s (SLIDER_X+10, 20);
            glVertex2s (SLIDER_X+10, 40);
            glVertex2s (SLIDER_X, 40);
        glEnd();
    }
}


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


void chambers (void)
{
    static GLfloat vertexValues[] = {
        272.0, 371.0, 0.0,  //0
        275.0, 491.0, 0.0,  //1
        299.0, 538.0, 0.0,  //2
        357.0, 595.0, 0.0,  //3
        475.0, 584.0, 0.0,  //4
        541.0, 497.0, 0.0,  //5
        537.0, 326.7, 0.0,  //6
        497.0, 256.0, 0.0,  //7
        355.0, 241.0, 0.0,  //8
        276.0, 319.0, 0.0,  //9
    };

    glVertexPointer(3, GL_FLOAT, 3*sizeof(GLfloat), &vertexValues[0]);

    static GLubyte chamber[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    static GLsizei count[] = {
        10,
    };

    static GLvoid *indices[] = {
        chamber,
    };

    glMultiDrawElements(GL_POLYGON, count, GL_UNSIGNED_BYTE, indices, 1);
}


void rotor (void)
{
    static GLfloat vertexValues[] = {
        -146.0, 28.0, 0.0,  //0 side | end
        -99.0, 64.0, 0.0,  //1
        -35.0, 97.0, 0.0,  //2
        34.0, 114.0, 0.0,  //3
        94.0, 115.0, 0.0,  //4_ end | side
        102.0, 60.0, 0.0,  //5
        98.0, -10.0, 0.0,  //6
        79.0, -79.0, 0.0,  //7
        50.0, -135.0, 0.0,  //8_ end | side
        -11.0, -111.0, 0.0,  //9
        -65.0, -73.0, 0.0,  //10
        -110.0, -26.0, 0.0,  //11
    };

    glVertexPointer(3, GL_FLOAT, 3*sizeof(GLfloat), &vertexValues[0]);

    static GLubyte rotor_f[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0};

    static GLsizei count[] = {
        12,
    };

    static GLvoid *indices[] = {
        rotor_f,
    };

    glMultiDrawElements(GL_POLYGON, count, GL_UNSIGNED_BYTE, indices, 1);
    
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(2.0);
    glDrawElements(GL_LINE_LOOP, 12, GL_UNSIGNED_BYTE, rotor_f);
    glLineWidth(1.0);
}


void eccentric_shaft (void)
{
    unit_circle(0, 360);
}


void eccentric_shaft_fill (int rotation)
{
    unit_circle_fill(rotation, 360);
    glColor3f(0.66, 0.66, 0.66);
    unit_circle_fill(0, rotation);
}


void housing (int fill)
{
    static GLfloat vertexValues[] = {
        219, 540, 0,    //0
        267, 540, 0,    //1
        286, 560, 0,    //2
        306, 577, 0,    //3
        330, 590, 0,    //4
        352, 599, 0,    //5
        371, 603, 0,    //6
        392, 606, 0,    //7
        406, 606, 0,    //8     peak
        422, 605, 0,    //9
        439, 602, 0,    //10
        463, 594, 0,    //11
        485, 582, 0,    //12
        502, 569, 0,    //13
        516, 554, 0,    //14
        529, 537, 0,    //15
        539, 518, 0,    //16
        547, 494, 0,    //17
        551, 469, 0,    //18
        551, 367, 0,    //19    right side
        546, 339, 0,    //20
        537, 314, 0,    //21
        525, 293, 0,    //22
        512, 277, 0,    //23
        495, 261, 0,    //24
        473, 247, 0,    //25
        450, 237, 0,    //26
        422, 231, 0,    //27
        404, 230, 0,    //28    valley
        378, 232, 0,    //29
        353, 239, 0,    //30
        331, 249, 0,    //31
        311, 263, 0,    //32
        295, 278, 0,    //33
        283, 293, 0,    //34
        274, 308, 0,    //35
        267, 322, 0,    //36
        219, 322, 0,    //37
        219, 341, 0,    //38
        281, 341, 0,    //39
        287, 324, 0,    //40
        295, 309, 0,    //41
        308, 292, 0,    //42
        325, 276, 0,    //43
        343, 264, 0,    //44
        364, 255, 0,    //45
        386, 250, 0,    //46
        405, 248, 0,    //47
        427, 251, 0,    //48
        447, 256, 0,    //49
        470, 267, 0,    //50
        489, 281, 0,    //51
        504, 297, 0,    //52
        516, 315, 0,    //53
        526, 336, 0,    //54
        531, 356, 0,    //55
        532, 375, 0,    //56
        532, 395, 0,    //57
        530, 404, 0,    //58
        528, 414, 0,    //59
        528, 425, 0,    //60
        530, 434, 0,    //61
        532, 441, 0,    //62
        532, 469, 0,    //63
        528, 492, 0,    //64
        520, 514, 0,    //65
        509, 533, 0,    //66
        494, 550, 0,    //67
        478, 564, 0,    //68
        457, 576, 0,    //69
        438, 583, 0,    //70
        416, 587, 0,    //71
        398, 588, 0,    //72 inner peak
        375, 584, 0,    //73
        352, 577, 0,    //74
        332, 569, 0,    //75
        315, 558, 0,    //76
        297, 542, 0,    //77
        281, 521, 0,    //78
        219, 521, 0,    //79

        219, 494, 0,    //80 betw_outline
        276, 494, 0,    //81
        276, 369, 0,    //82
        219, 369, 0,    //83
        219, 388, 0,    //84
        257, 388, 0,    //85
        257, 475, 0,    //86
        219, 475, 0,    //87
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
}
