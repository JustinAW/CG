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


void unit_circle (int deg_rotation)
{
    glBegin(GL_LINE_LOOP);
        double heading;
        for (int i = 0; i < deg_rotation; i += 360 / SIDES)
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

        80.0, 00.0, 0.0,    //16
        91.0, 00.0, 0.0,    //17
        91.0, 27.0, 0.0,    //18
        80.0, 27.0, 0.0,    //19
    };

    glVertexPointer(3, GL_FLOAT, 3*sizeof(GLfloat), &vertexValues[0]);
    //glColorPointer(3, GL_FLOAT, 6*sizeof(GLfloat), &vertexValues[3]);

    //Define pieces here
    static GLubyte name[] = {0, 0, 0, 0};
    static GLubyte rect1[] = {0, 1, 2, 3};
    static GLubyte rect2[] = {4, 5, 6, 7};
    static GLubyte rect3[] = {8, 9, 10, 11};
    static GLubyte rect4[] = {12, 13, 14, 15};
    static GLubyte rect5[] = {16, 17, 18, 19};

    // list of vertex counts for each part
    static GLsizei count[] = {
        4, 4, 4, 4, 4,
    };

    // list of piece names
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
    //glColorPointer(3, GL_FLOAT, 6*sizeof(GLfloat), &vertexValues[3]);

    //Define pieces here
    static GLubyte name[] = {0, 0, 0, 0};
    static GLubyte chamber[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // list of vertex counts for each part
    static GLsizei count[] = {
        10,
    };

    // list of piece names
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
    //glColorPointer(3, GL_FLOAT, 6*sizeof(GLfloat), &vertexValues[3]);

    //Define pieces here
    static GLubyte name[] = {0, 0, 0, 0};
    static GLubyte rotor_f[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0};

    // list of vertex counts for each part
    static GLsizei count[] = {
        12,
    };

    // list of piece names
    static GLvoid *indices[] = {
        rotor_f,
    };

    glMultiDrawElements(GL_POLYGON, count, GL_UNSIGNED_BYTE, indices, 1);
}
