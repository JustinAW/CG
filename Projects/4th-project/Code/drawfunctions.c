/****************************************************
 *                drawfunctions.c                   *
 ****************************************************
 *  Author:     Justin Weigle                       *
 *  Edited:     21 Nov 2019                         *
 ****************************************************
 * Contains the functions for drawing the parts of  *
 * a Wankel rotary engine in 3d                     *
 ****************************************************/

#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include "drawfunctions.h"

const int SIDES = 360;

static GLfloat silver_ambient[] = {0.29225, 0.29225, 0.29225, 1.0};
static GLfloat silver_diffuse[] = {0.50754, 0.50754, 0.50754, 1.0};
static GLfloat silver_specular[] = {0.508273, 0.508273, 0.508273, 1.0};
static GLfloat silver_shine = 51.2;

// polished silver
static GLfloat psilver_ambient[] = {0.23125, 0.23125, 0.23125, 1.0};
static GLfloat psilver_diffuse[] = {0.2775, 0.2775, 0.2775, 1.0};
static GLfloat psilver_specular[] = {0.773911, 0.773911, 0.773911, 1.0};
static GLfloat psilver_shine = 89.6;

static GLfloat tin_ambient[] = {0.105882, 0.058824, 0.113725, 1.0};
static GLfloat tin_diffuse[] = {0.427451, 0.470588, 0.541176, 1.0};
static GLfloat tin_specular[] = {0.333333, 0.333333, 0.521569, 1.0};
static GLfloat tin_shine = 9.84615;

static GLfloat chrome_ambient[] = {0.25, 0.25, 0.25, 1.0};
static GLfloat chrome_diffuse[] = {0.4, 0.4, 0.4, 1.0};
static GLfloat chrome_specular[] = {0.774597, 0.774597, 0.774597, 1.0};
static GLfloat chrome_shine = 76.8;

// polished chrome
static GLfloat pchrome_ambient[] = {0.2, 0.2, 0.2, 1.0};
static GLfloat pchrome_diffuse[] = {0.3, 0.3, 0.3, 1.0};
static GLfloat pchrome_specular[] = {0.874597, 0.874597, 0.874597, 1.0};
static GLfloat pchrome_shine = 86.8;

// obsidian
static GLfloat obi_ambient[] = {0.05375, 0.05, 0.06625, 0.82};
static GLfloat obi_diffuse[] = {0.18275, 0.17, 0.22525, 0.82};
static GLfloat obi_specular[] = {0.332741, 0.328634, 0.346435, 0.82};
static GLfloat obi_shine = 38.4;

// white plastic
static GLfloat wplastic_ambient[] = {0.3, 0.3, 0.3, 1.0};
static GLfloat wplastic_diffuse[] = {0.78, 0.78, 0.78, 1.0};
static GLfloat wplastic_specular[] = {0.80, 0.80, 0.80, 1.0};
static GLfloat wplastic_shine = 32.0;

static GLfloat ruby_ambient[] = {0.1745, 0.01175, 0.01175, 0.55};
static GLfloat ruby_diffuse[] = {0.61424, 0.04136, 0.04136, 0.55};
static GLfloat ruby_specular[] = {0.727811, 0.626959, 0.626959, 0.55};
static GLfloat ruby_shine = 76.8;

static GLfloat bronze_ambient[] = {0.2125, 0.1275, 0.054, 1.0};
static GLfloat bronze_diffuse[] = {0.714, 0.4284, 0.18144, 1.0};
static GLfloat bronze_specular[] = {0.393548, 0.271906, 0.166721, 1.0};
static GLfloat bronze_shine = 25.6;

static GLfloat wood_ambient[] = {0.25, 0.148, 0.06475, 1.0};
static GLfloat wood_diffuse[] = {0.4, 0.2168, 0.1036, 1.0};
static GLfloat wood_specular[] = {0.393548, 0.271906, 0.166721, 1.0};
static GLfloat wood_shine = 5.0;

static GLfloat flashlight_emission[] = {0.91, 0.71, 0.48, 1.0};
static GLfloat zero_emission[] = {0.0, 0.0, 0.0, 1.0};
static GLfloat spark_emission[] = {1.0, 0.97, 0.52, 1.0};


/****************************************************
 *                       sq                         *
 ****************************************************
 * squares a number                                 *
 ****************************************************/
GLfloat sq (GLdouble x)
{
    return x * x;
}


/****************************************************
 *                    normalize                     *
 ****************************************************
 * Normalizes a vector                              *
 ****************************************************/
void normalize (GLdouble *v)
{
    GLdouble n = sqrt(sq(v[0]) + sq(v[1]) + sq(v[2]));

    v[0] /= n;
    v[1] /= n;
    v[2] /= n;
}


void unit_square (void)
{
    glBegin(GL_QUADS);
        glVertex3d(0,0,0);
        glVertex3d(0,1,0);
        glVertex3d(1,1,0);
        glVertex3d(1,0,0);
    glEnd();
}


/****************************************************
 *                    unit_cube                     *
 ****************************************************
 * Draws a length 1 cube with origin at 0,0,0       *
 ****************************************************/
void unit_cube (void)
{
    static GLfloat vertexValues[] = {
        // front
        0, 0, 0, -1, -1, 1,   //0
        0, 1, 0, -1,  1, 1,   //1
        1, 1, 0,  1,  1, 1,   //2
        1, 0, 0,  1, -1, 1,   //3
        // back
        0, 0, -1, -1, -1, -1,   //4
        0, 1, -1, -1,  1, -1,   //5
        1, 1, -1,  1,  1, -1,   //6
        1, 0, -1,  1, -1, -1,   //7
    };

    glVertexPointer(3, GL_FLOAT, 6*sizeof(GLfloat), &vertexValues[0]);
    glNormalPointer(GL_FLOAT, 6*sizeof(GLfloat), &vertexValues[3]);

    static GLubyte top[] = { 1, 5, 6, 2, };
    static GLubyte front[] = { 0, 1, 2, 3, };
    static GLubyte right[] = { 3, 2, 6, 7, };
    static GLubyte back[] = { 7, 6, 5, 4, };
    static GLubyte left[] = { 4, 5, 1, 0, };
    static GLubyte bottom[] = { 0, 4, 7, 3, };

    static GLvoid *indices[] = { top, front, right, back, left, bottom, };

    static GLsizei count[] = { 4, 4, 4, 4, 4, 4, };

    glMultiDrawElements(GL_QUADS, count, GL_UNSIGNED_BYTE, indices, 6);
}


/****************************************************
 *              inner_gear_surface                  *
 ****************************************************
 * Draws the surface of a gear with teeth that are  *
 * facing inward                                    *
 ****************************************************/
void inner_gear_surface (GLfloat depth, int gear_spacing)
{
    glMaterialfv(GL_FRONT, GL_AMBIENT,  chrome_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,  chrome_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, chrome_specular);
    glMateriali(GL_FRONT, GL_SHININESS, chrome_shine);

    glBegin(GL_TRIANGLE_STRIP);
        double heading;
        int counter = 0;
        int toggle = 1;
        glNormal3d(0.0, 0.0, 1.0);
        for (int i = 0; i <= 360; i += 360 / SIDES)
        {
            heading = i * M_PI / 180;
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
    glMaterialfv(GL_FRONT, GL_AMBIENT,  chrome_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,  chrome_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, chrome_specular);
    glMateriali(GL_FRONT, GL_SHININESS, chrome_shine);

    glBegin(GL_TRIANGLE_STRIP);
        double heading;
        int counter = 0;
        int toggle = 1;
        glNormal3d(0.0, 0.0, 1.0);
        for (int i = 0; i <= 360; i += 360 / SIDES)
        {
            heading = i * M_PI / 180;
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
void gear_teeth_outline (int gear_spacing, int inner)
{
    GLdouble v[3], n[3];
    glMaterialfv(GL_FRONT, GL_AMBIENT,  chrome_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,  chrome_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, chrome_specular);
    glMateriali(GL_FRONT, GL_SHININESS, chrome_shine);

    glBegin(GL_TRIANGLE_STRIP);
        double heading;
        int counter = 0;
        int toggle = 1;
        for (int i = 0; i <= 360; i += 360 / SIDES)
        {
            heading = i * M_PI / 180;
            if (toggle)
            {
                n[0] = v[0] = (cos(heading));
                n[1] = v[1] = (sin(heading));
                n[2] = v[2] = (0);
                if (inner == 1)
                {
                    n[0] *= -1;
                    n[1] *= -1;
                }
                normalize(n);
                glNormal3dv(n);
                glVertex3dv(v);

                n[0] = v[0] = (cos(heading));
                n[1] = v[1] = (sin(heading));
                n[2] = v[2] = (-20);
                if (inner == 1)
                {
                    n[0] *= -1;
                    n[1] *= -1;
                }
                normalize(n);
                glNormal3dv(n);
                glVertex3dv(v);
            }
            else
            {
                n[0] = v[0] = (cos(heading) * 0.9);
                n[1] = v[1] = (sin(heading) * 0.9);
                n[2] = v[2] = (0);
                if (inner == 1)
                {
                    n[0] *= -1;
                    n[1] *= -1;
                }
                normalize(n);
                glNormal3dv(n);
                glVertex3dv(v);

                n[0] = v[0] = (cos(heading) * 0.9);
                n[1] = v[1] = (sin(heading) * 0.9);
                n[2] = v[2] = (-20);
                if (inner == 1)
                {
                    n[0] *= -1;
                    n[1] *= -1;
                }
                normalize(n);
                glNormal3dv(n);
                glVertex3dv(v);
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
            heading = i * M_PI / 180;
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
    GLdouble v[3], n[3];
    glBegin(GL_POLYGON);
        double heading;
        for (int i = 0; i < 360; i += 360 / SIDES)
        {
            heading = i * M_PI / 180;

            n[0] = v[0] = (x);
            n[1] = v[1] = (cos(heading));
            n[2] = v[2] = (sin(heading));
            normalize(n);
            glNormal3dv(n);
            glVertex3dv(v);
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
    GLdouble v[3], n[3];
    glBegin(GL_TRIANGLE_STRIP);
        double heading;
        for (int i = 0; i <= 360; i += 360 / divisions)
        {
            heading = i * M_PI / 180;

            n[0] = v[0] = (cos(heading) * scale);
            n[1] = v[1] = (sin(heading) * scale);
            n[2] = v[2] = (z1);
            normalize(n);
            glNormal3dv(n);
            glVertex3dv(v);

            n[0] = v[0] = (cos(heading) * scale);
            n[1] = v[1] = (sin(heading) * scale);
            n[2] = v[2] = (z2);
            normalize(n);
            glNormal3dv(n);
            glVertex3dv(v);
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
    GLdouble v[3], n[3];
    glBegin(GL_TRIANGLE_STRIP);
        GLdouble heading;
        for (int i = 0; i <= 360; i += 360 / divisions)
        {
            heading = i * M_PI / 180;

            n[0] = v[0] = (x1);
            n[1] = v[1] = (cos(heading) * scale);
            n[2] = v[2] = (sin(heading) * scale);
            normalize(n);
            glNormal3dv(n);
            glVertex3dv(v);

            n[0] = v[0] = (x2);
            n[1] = v[1] = (cos(heading) * scale);
            n[2] = v[2] = (sin(heading) * scale);
            normalize(n);
            glNormal3dv(n);
            glVertex3dv(v);
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
    GLdouble v[3], n[3];
    glMaterialfv(GL_FRONT, GL_AMBIENT,  silver_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,  silver_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, silver_specular);
    glMateriali(GL_FRONT, GL_SHININESS, silver_shine);

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
                    heading = i * M_PI / 180;

                    n[0] = v[0] = (cos(heading));
                    n[1] = v[1] = (sin(heading));
                    n[2] = v[2] = (-20);
                    normalize(n);
                    glNormal3dv(n);
                    glVertex3dv(v);

                    glNormal3d(0.0, 0.0, 1.0);  // front in rotor
                    glVertex3d(0.0, 0.0, -20.0);
                }
            glEnd();
            glBegin(GL_TRIANGLE_STRIP);
                for (int i = 0; i <= 360; i += 360 / (SIDES / 6))
                {
                    heading = i * M_PI / 180;

                    n[0] = v[0] = (cos(heading));
                    n[1] = v[1] = (sin(heading));
                    n[2] = v[2] = (-80);
                    normalize(n);
                    glNormal3dv(n);
                    glVertex3dv(v);

                    glNormal3d(0.0, 0.0, -1.0); // back in rotor
                    glVertex3d(0.0, 0.0, -80.0);
                }
            glEnd();
        glPopMatrix();
    glPopMatrix();
    glPushMatrix();
        glRotatef((-ECC_SHFT_I/3) + 30, 0.0, 0.0, 1.0);
        glScalef(30.0, 30.0, 1.0);
        x_disk_surface(30.0, 10.0, -20.0, 0.7);
        x_disk_surface(30.0, 40.0, 10.0, 0.4);
        x_disk_surface(30.0, -80, -120, 0.7);
        glPushMatrix();
            glScalef(0.7, 0.7, 1.0);
            glBegin(GL_TRIANGLE_STRIP);
                for (int i = 0; i <= 360; i += 360 / (SIDES / 12))
                {
                    heading = i * M_PI / 180;

                    n[0] = v[0] = (cos(heading));
                    n[1] = v[1] = (sin(heading));
                    n[2] = v[2] = (10.0);
                    normalize(n);
                    glNormal3dv(n);
                    glVertex3dv(v);

                    glNormal3d(0.0, 0.0, 1.0);  // one back from front
                    glVertex3d(0.0, 0.0, 10.0);
                }
            glEnd();
            glBegin(GL_TRIANGLE_STRIP);
                for (int i = 0; i <= 360; i += 360 / (SIDES / 12))
                {
                    heading = i * M_PI / 180;

                    n[0] = v[0] = (cos(heading));
                    n[1] = v[1] = (sin(heading));
                    n[2] = v[2] = (-120);
                    normalize(n);
                    glNormal3dv(n);
                    glVertex3dv(v);

                    glNormal3d(0.0, 0.0, -1.0); // backmost
                    glVertex3d(0.0, 0.0, -120.0);
                }
            glEnd();
        glPopMatrix();
        glPushMatrix();
            glScalef(0.4, 0.4, 1.0);
            glBegin(GL_TRIANGLE_STRIP);
                for (int i = 0; i <= 360; i += 360 / (SIDES / 24))
                {
                    heading = i * M_PI / 180;

                    n[0] = v[0] = (cos(heading));
                    n[1] = v[1] = (sin(heading));
                    n[2] = v[2] = (40.0);
                    normalize(n);
                    glNormal3dv(n);
                    glVertex3dv(v);

                    glNormal3d(0.0, 0.0, 1.0);  // frontmost
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
    glMaterialfv(GL_FRONT, GL_AMBIENT,  obi_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,  obi_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, obi_specular);
    glMateriali(GL_FRONT, GL_SHININESS, obi_shine);

    z_disk_surface(20.0, 0.0, 35.0, 15.0);
}


/****************************************************
 *                      rotor                       *
 ****************************************************
 * Draws the rotor                                  *
 ****************************************************/
void rotor (void)
{
    glMaterialfv(GL_FRONT, GL_AMBIENT,  psilver_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,  psilver_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, psilver_specular);
    glMateriali(GL_FRONT, GL_SHININESS, psilver_shine);

    static GLfloat vertexValues[] = {
        -76.0,  44.0,   0.0, -0.723,  0.424, 0.546,    //0
        -51.0,  53.0,   0.0, -0.240,  0.861, 0.448,    //1
        -26.0,  58.0,   0.0, -0.122,  0.886, 0.448,    //2
          0.0,  60.0,   0.0,  0.000,  0.894, 0.448,    //3
         26.0,  58.0,   0.0,  0.122,  0.886, 0.448,    //4
         51.0,  53.0,   0.0,  0.240,  0.861, 0.448,    //5
         76.0,  44.0,   0.0,  0.723,  0.424, 0.546,    //6
         72.0,  20.0,   0.0,  0.869, -0.210, 0.448,    //7
         65.0,  -2.0,   0.0,  0.837, -0.314, 0.448,    //8
         55.0, -25.0,   0.0,  0.785, -0.428, 0.449,    //9
         41.0, -46.0,   0.0,  0.720, -0.530, 0.448,    //10
         24.0, -67.0,   0.0,  0.644, -0.620, 0.449,    //11
          0.0, -88.0,   0.0,  0.000, -0.833, 0.553,    //12
        -24.0, -67.0,   0.0, -0.644, -0.620, 0.448,    //13
        -41.0, -46.0,   0.0, -0.720, -0.530, 0.448,    //14
        -55.0, -25.0,   0.0, -0.785, -0.428, 0.449,    //15
        -65.0,  -2.0,   0.0, -0.837, -0.314, 0.448,    //16
        -72.0,  20.0,   0.0, -0.869, -0.210, 0.448,    //17

        -76.0,  44.0, -60.0, -0.723,  0.424, -0.546,    //18
        -51.0,  53.0, -60.0, -0.240,  0.861, -0.448,    //19
        -26.0,  58.0, -60.0, -0.122,  0.886, -0.448,    //20
          0.0,  60.0, -60.0,  0.000,  0.894, -0.448,    //21
         26.0,  58.0, -60.0,  0.122,  0.886, -0.448,    //22
         51.0,  53.0, -60.0,  0.240,  0.861, -0.448,    //23
         76.0,  44.0, -60.0,  0.723,  0.424, -0.546,    //24
         72.0,  20.0, -60.0,  0.869, -0.210, -0.448,    //25
         65.0,  -2.0, -60.0,  0.837, -0.314, -0.448,    //26
         55.0, -25.0, -60.0,  0.785, -0.428, -0.449,    //27
         41.0, -46.0, -60.0,  0.720, -0.530, -0.448,    //28
         24.0, -67.0, -60.0,  0.644, -0.620, -0.449,    //29
          0.0, -88.0, -60.0,  0.000, -0.833, -0.553,    //30
        -24.0, -67.0, -60.0, -0.644, -0.620, -0.448,    //31
        -41.0, -46.0, -60.0, -0.720, -0.530, -0.448,    //32
        -55.0, -25.0, -60.0, -0.785, -0.428, -0.449,    //33
        -65.0,  -2.0, -60.0, -0.837, -0.314, -0.448,    //34
        -72.0,  20.0, -60.0, -0.869, -0.210, -0.448,    //35
    };

    glVertexPointer(3, GL_FLOAT, 6*sizeof(GLfloat), &vertexValues[0]);
    glNormalPointer(GL_FLOAT, 6*sizeof(GLfloat), &vertexValues[3]);

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

    GLdouble v[3], n[3];
    glPushMatrix();
        glBegin(GL_TRIANGLE_STRIP);
            double heading;
            int stagger = 0;
            int index = 7 * 6;
            n[0] = 0;
            n[1] = 0;
            n[2] = 1;
            for (int i = 0; i <= 360; i += 360 / SIDES)
            {
                heading = i * M_PI / 180;

                v[0] = (cos(heading) * 47.32);
                v[1] = (sin(heading) * 47.32);
                v[2] = (0);
                glNormal3dv(n);
                glVertex3dv(v);

                v[0] = (vertexValues[index]);
                v[1] = (vertexValues[index+1]);
                v[2] = (vertexValues[index+2]);
                glNormal3f(vertexValues[index+3],
                        vertexValues[index+4],
                        vertexValues[index+5]);
                glVertex3dv(v);

                stagger++;
                if (stagger == 20)
                {
                    stagger = 0;
                    index -= 6;
                    if (index < 0)
                        index = 17 * 6;
                }
            }
        glEnd();
        glBegin(GL_TRIANGLE_STRIP);
            stagger = 0;
            index = 25 * 6;
            n[0] = 0;
            n[1] = 0;
            n[2] = -1;
            for (int i = 0; i <= 360; i += 360 / SIDES)
            {
                heading = i * M_PI / 180;

                v[0] = (cos(heading) * 47.32);
                v[1] = (sin(heading) * 47.32);
                v[2] = (-60);
                glNormal3dv(n);
                glVertex3dv(v);

                v[0] = (vertexValues[index]);
                v[1] = (vertexValues[index+1]);
                v[2] = (vertexValues[index+2]);
                glNormal3f(vertexValues[index+3],
                        vertexValues[index+4],
                        vertexValues[index+5]);
                glVertex3dv(v);

                stagger++;
                if (stagger == 20)
                {
                    stagger = 0;
                    index -= 6;
                    if (index < 18 * 6)
                        index = 35 * 6;
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
    glMaterialfv(GL_FRONT, GL_AMBIENT,  pchrome_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,  pchrome_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, pchrome_specular);
    glMateriali(GL_FRONT, GL_SHININESS, pchrome_shine);

    static GLfloat vertexValues[] = {
        -128,  120, 0, -0.767,  0.455, 0.452,    //0   outer_outline
        -109,  143, 0, -0.636,  0.628, 0.449,    //1
         -89,  160, 0, -0.505,  0.737, 0.449,    //2
         -65,  173, 0, -0.383,  0.808, 0.448,    //3
         -43,  182, 0, -0.262,  0.854, 0.449,    //4
         -24,  186, 0, -0.155,  0.881, 0.447,    //5
          -3,  189, 0, -0.063,  0.892, 0.448,    //6
           5,  189, 0,  0.028,  0.894, 0.447,    //7   peak
          21,  188, 0,  0.106,  0.888, 0.448,    //8
          38,  185, 0,  0.220,  0.867, 0.448,    //9
          62,  177, 0,  0.357,  0.819, 0.449,    //10
          84,  165, 0,  0.487,  0.750, 0.448,    //11
         101,  152, 0,  0.600,  0.662, 0.448,    //12
         115,  137, 0,  0.683,  0.577, 0.448,    //13
         128,  120, 0,  0.753,  0.481, 0.448,    //14
         138,  101, 0,  0.822,  0.351, 0.448,    //15
         146,   77, 0,  0.868,  0.213, 0.448,    //16
         150,   52, 0,  0.891,  0.071, 0.448,    //17
         150,  -50, 0,  0.890, -0.079, 0.449,    //18  right side
         145,  -78, 0,  0.863, -0.231, 0.448,    //19
         136, -103, 0,  0.812, -0.374, 0.449,    //20
         124, -124, 0,  0.737, -0.505, 0.448,    //21
         111, -140, 0,  0.655, -0.609, 0.448,    //22
          94, -156, 0,  0.549, -0.705, 0.449,    //23
          72, -170, 0,  0.419, -0.789, 0.448,    //24
          49, -180, 0,  0.273, -0.851, 0.449,    //25
          21, -186, 0,  0.119, -0.886, 0.448,    //26
           3, -187, 0,  0.025, -0.894, 0.447,    //27  valley
          -8, -187, 0, -0.079, -0.890, 0.449,    //28
         -36, -182, 0, -0.215, -0.868, 0.448,    //29
         -58, -175, 0, -0.336, -0.828, 0.448,    //30
         -68, -170, 0, -0.430, -0.784, 0.448,    //31
         -88, -158, 0, -0.556, -0.698, 0.450,    //32
        -113, -132, 0, -0.683, -0.577, 0.448,    //33
        -130, -109, 0, -0.775, -0.444, 0.450,    //34
        -136,  -95, 0, -0.826, -0.342, 0.447,    //35
        -140,  -85, 0, -0.857, -0.255, 0.449,    //36
        -142,  -75, 0, -0.877, -0.175, 0.447,    //37
        -144,  -65, 0, -0.884, -0.132, 0.448,    //38
        -145,  -55, 0, -0.884, -0.132, 0.448,    //39
        -146,  -50, 0, -0.889, -0.088, 0.449,    //40
        -146,   50, 0, -0.889,  0.088, 0.449,    //41
        -145,   55, 0, -0.884,  0.132, 0.448,    //42
        -144,   65, 0, -0.890,  0.089, 0.447,    //43
        -143,   75, 0, -0.884,  0.132, 0.448,    //44
        -141,   85, 0, -0.857,  0.255, 0.449,    //45
        -137,   95, 0, -0.840,  0.308, 0.447,    //46
        -132,  110, 0, -0.840,  0.308, 0.447,    //47  end    outer_outline

        -114,  104, 0,  0.789, -0.417, 0.452,    //48  inner_outline
         -98,  125, 0,  0.655, -0.608, 0.449,    //49
         -80,  141, 0,  0.541, -0.711, 0.448,    //50
         -63,  152, 0,  0.443, -0.776, 0.448,    //51
         -43,  162, 0,  0.331, -0.830, 0.448,    //52
         -20,  169, 0,  0.183, -0.875, 0.449,    //53
          -3,  171, 0,  0.028, -0.893, 0.449,    //54  inner peak
          15,  170, 0, -0.105, -0.888, 0.448,    //55
          37,  166, 0, -0.235, -0.862, 0.449,    //56
          56,  159, 0, -0.378, -0.810, 0.448,    //57
          77,  147, 0, -0.518, -0.728, 0.449,    //58
          93,  133, 0, -0.631, -0.634, 0.448,    //59
         108,  116, 0, -0.725, -0.522, 0.449,    //60
         119,   97, 0, -0.810, -0.378, 0.449,    //61
         127,   75, 0, -0.864, -0.230, 0.449,    //62
         131,   52, 0, -0.890, -0.077, 0.449,    //63
         131,   24, 0, -0.884,  0.124, 0.451,    //64
         129,   17, 0, -0.867,  0.220, 0.447,    //65
         127,    8, 0, -0.888,  0.097, 0.449,    //66
         127,   -3, 0, -0.889, -0.088, 0.449,    //67
         129,  -13, 0, -0.875, -0.185, 0.447,    //68
         131,  -22, 0, -0.888, -0.097, 0.449,    //69
         131,  -42, 0, -0.894,  0.024, 0.447,    //70
         130,  -61, 0, -0.884,  0.132, 0.449,    //71
         125,  -81, 0, -0.841,  0.302, 0.449,    //72
         115, -102, 0, -0.777,  0.441, 0.448,    //73
         103, -120, 0, -0.700,  0.555, 0.448,    //74
          88, -136, 0, -0.594,  0.668, 0.449,    //75
          69, -150, 0, -0.460,  0.766, 0.449,    //76
          46, -161, 0, -0.303,  0.841, 0.449,    //77
          26, -166, 0, -0.169,  0.878, 0.448,    //78
           4, -169, 0, -0.018,  0.893, 0.450,    //79
         -17, -167, 0,  0.142,  0.883, 0.448,    //80
         -39, -162, 0,  0.276,  0.850, 0.449,    //80
         -60, -153, 0,  0.426,  0.786, 0.449,    //82
         -78, -141, 0,  0.556,  0.700, 0.448,    //83
         -95, -125, 0,  0.664,  0.599, 0.448,    //84
        -108, -108, 0,  0.752,  0.483, 0.448,    //85
        -116,  -93, 0,  0.818,  0.360, 0.448,    //86
        -122,  -76, 0,  0.864,  0.229, 0.448,    //87
        -124,  -65, 0,  0.886,  0.125, 0.448,    //88
        -125,  -55, 0,  0.884,  0.132, 0.448,    //89
        -126,  -50, 0,  0.891,  0.052, 0.451,    //90
        -124,  -25, 0,  0.892, -0.071, 0.447,    //91
        -122,    0, 0,  0.894,  0.000, 0.448,    //92
        -124,   25, 0,  0.892,  0.071, 0.447,    //93
        -126,   50, 0,  0.891, -0.052, 0.451,    //94
        -125,   55, 0,  0.884, -0.132, 0.448,    //95
        -124,   65, 0,  0.890, -0.090, 0.447,    //96
        -123,   75, 0,  0.884, -0.132, 0.448,    //97
        -121,   85, 0,  0.857, -0.255, 0.449,    //98
        -117,   95, 0,  0.840, -0.308, 0.447,    //99  end     inner_outline

        // -Z ... add 100 to index: 100 through 199
        -128,  120, -60, -0.767,  0.455, -0.452,    //0   outer_outline
        -109,  143, -60, -0.636,  0.628, -0.449,    //1
         -89,  160, -60, -0.505,  0.737, -0.449,    //2
         -65,  173, -60, -0.383,  0.808, -0.448,    //3
         -43,  182, -60, -0.262,  0.854, -0.449,    //4
         -24,  186, -60, -0.155,  0.881, -0.447,    //5
          -3,  189, -60, -0.063,  0.892, -0.448,    //6
           5,  189, -60,  0.028,  0.894, -0.447,    //7   peak
          21,  188, -60,  0.106,  0.888, -0.448,    //8
          38,  185, -60,  0.220,  0.867, -0.448,    //9
          62,  177, -60,  0.357,  0.819, -0.449,    //10
          84,  165, -60,  0.487,  0.750, -0.448,    //11
         101,  152, -60,  0.600,  0.662, -0.448,    //12
         115,  137, -60,  0.683,  0.577, -0.448,    //13
         128,  120, -60,  0.753,  0.481, -0.448,    //14
         138,  101, -60,  0.822,  0.351, -0.448,    //15
         146,   77, -60,  0.868,  0.213, -0.448,    //16
         150,   52, -60,  0.891,  0.071, -0.448,    //17
         150,  -50, -60,  0.890, -0.079, -0.449,    //18  right side
         145,  -78, -60,  0.863, -0.231, -0.448,    //19
         136, -103, -60,  0.812, -0.374, -0.449,    //20
         124, -124, -60,  0.737, -0.505, -0.448,    //21
         111, -140, -60,  0.655, -0.609, -0.448,    //22
          94, -156, -60,  0.549, -0.705, -0.449,    //23
          72, -170, -60,  0.419, -0.789, -0.448,    //24
          49, -180, -60,  0.273, -0.851, -0.449,    //25
          21, -186, -60,  0.119, -0.886, -0.448,    //26
           3, -187, -60,  0.025, -0.894, -0.447,    //27  valley
          -8, -187, -60, -0.079, -0.890, -0.449,    //28
         -36, -182, -60, -0.215, -0.868, -0.448,    //29
         -58, -175, -60, -0.336, -0.828, -0.448,    //30
         -68, -170, -60, -0.430, -0.784, -0.448,    //31
         -88, -158, -60, -0.556, -0.698, -0.450,    //32
        -113, -132, -60, -0.683, -0.577, -0.448,    //33
        -130, -109, -60, -0.775, -0.444, -0.450,    //34
        -136,  -95, -60, -0.826, -0.342, -0.447,    //35
        -140,  -85, -60, -0.857, -0.255, -0.449,    //36
        -142,  -75, -60, -0.877, -0.175, -0.447,    //37
        -144,  -65, -60, -0.884, -0.132, -0.448,    //38
        -145,  -55, -60, -0.884, -0.132, -0.448,    //39
        -146,  -50, -60, -0.889, -0.088, -0.449,    //40
        -146,   50, -60, -0.889,  0.088, -0.449,    //41
        -145,   55, -60, -0.884,  0.132, -0.448,    //42
        -144,   65, -60, -0.890,  0.089, -0.447,    //43
        -143,   75, -60, -0.884,  0.132, -0.448,    //44
        -141,   85, -60, -0.857,  0.255, -0.449,    //45
        -137,   95, -60, -0.840,  0.308, -0.447,    //46
        -132,  110, -60, -0.840,  0.308, -0.447,    //47  end    outer_outline

        -114,  104, -60,  0.789, -0.417, -0.452,    //48  inner_outline
         -98,  125, -60,  0.655, -0.608, -0.449,    //49
         -80,  141, -60,  0.541, -0.711, -0.448,    //50
         -63,  152, -60,  0.443, -0.776, -0.448,    //51
         -43,  162, -60,  0.331, -0.830, -0.448,    //52
         -20,  169, -60,  0.183, -0.875, -0.449,    //53
          -3,  171, -60,  0.028, -0.893, -0.449,    //54  inner peak
          15,  170, -60, -0.105, -0.888, -0.448,    //55
          37,  166, -60, -0.235, -0.862, -0.449,    //56
          56,  159, -60, -0.378, -0.810, -0.448,    //57
          77,  147, -60, -0.518, -0.728, -0.449,    //58
          93,  133, -60, -0.631, -0.634, -0.448,    //59
         108,  116, -60, -0.725, -0.522, -0.449,    //60
         119,   97, -60, -0.810, -0.378, -0.449,    //61
         127,   75, -60, -0.864, -0.230, -0.449,    //62
         131,   52, -60, -0.890, -0.077, -0.449,    //63
         131,   24, -60, -0.884,  0.124, -0.451,    //64
         129,   17, -60, -0.867,  0.220, -0.447,    //65
         127,    8, -60, -0.888,  0.097, -0.449,    //66
         127,   -3, -60, -0.889, -0.088, -0.449,    //67
         129,  -13, -60, -0.875, -0.185, -0.447,    //68
         131,  -22, -60, -0.888, -0.097, -0.449,    //69
         131,  -42, -60, -0.894,  0.024, -0.447,    //70
         130,  -61, -60, -0.884,  0.132, -0.449,    //71
         125,  -81, -60, -0.841,  0.302, -0.449,    //72
         115, -102, -60, -0.777,  0.441, -0.448,    //73
         103, -120, -60, -0.700,  0.555, -0.448,    //74
          88, -136, -60, -0.594,  0.668, -0.449,    //75
          69, -150, -60, -0.460,  0.766, -0.449,    //76
          46, -161, -60, -0.303,  0.841, -0.449,    //77
          26, -166, -60, -0.169,  0.878, -0.448,    //78
           4, -169, -60, -0.018,  0.893, -0.450,    //79
         -17, -167, -60,  0.142,  0.883, -0.448,    //80
         -39, -162, -60,  0.276,  0.850, -0.449,    //80
         -60, -153, -60,  0.426,  0.786, -0.449,    //82
         -78, -141, -60,  0.556,  0.700, -0.448,    //83
         -95, -125, -60,  0.664,  0.599, -0.448,    //84
        -108, -108, -60,  0.752,  0.483, -0.448,    //85
        -116,  -93, -60,  0.818,  0.360, -0.448,    //86
        -122,  -76, -60,  0.864,  0.229, -0.448,    //87
        -124,  -65, -60,  0.886,  0.125, -0.448,    //88
        -125,  -55, -60,  0.884,  0.132, -0.448,    //89
        -126,  -50, -60,  0.891,  0.052, -0.451,    //90
        -124,  -25, -60,  0.892, -0.071, -0.447,    //91
        -122,    0, -60,  0.894,  0.000, -0.448,    //92
        -124,   25, -60,  0.892,  0.071, -0.447,   //93
        -126,   50, -60,  0.891, -0.052, -0.451,    //94
        -125,   55, -60,  0.884, -0.132, -0.448,    //95
        -124,   65, -60,  0.890, -0.090, -0.447,    //96
        -123,   75, -60,  0.884, -0.132, -0.448,    //97
        -121,   85, -60,  0.857, -0.255, -0.449,    //98
        -117,   95, -60,  0.840, -0.308, -0.447,    //99  end     inner_outline
    };

    glVertexPointer(3, GL_FLOAT, 6*sizeof(GLfloat), &vertexValues[0]);
    glNormalPointer(GL_FLOAT, 6*sizeof(GLfloat), &vertexValues[3]);

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
         0, 100,  1, 101,  2, 102,  3, 103,  4, 104,
         5, 105,  6, 106,  7, 107,  8, 108,  9, 109,
        10, 110, 11, 111, 12, 112, 13, 113, 14, 114,
        15, 115, 16, 116, 17, 117, 18, 118, 19, 119,
        20, 120, 21, 121, 22, 122, 23, 123, 24, 124,
        25, 125, 26, 126, 27, 127, 28, 128, 29, 129,
        30, 130, 31, 131, 32, 132, 33, 133, 34, 134,
        35, 135, 36, 136, 37, 137, 38, 138, 39, 139,
        40, 140, 41, 141, 42, 142, 43, 143, 44, 144,
        45, 145, 46, 146, 47, 147,  0, 100, 48, 148,
        49, 149, 50, 150, 51, 151, 52, 152, 53, 153,
        54, 154, 55, 155, 56, 156, 57, 157, 58, 158,
        59, 159, 60, 160, 61, 161, 62, 162, 63, 163,
        64, 164, 65, 165, 66, 166, 67, 167, 68, 168,
        69, 169, 70, 170, 71, 171, 72, 172, 73, 173,
        74, 174, 75, 175, 76, 176, 77, 177, 78, 178,
        79, 179, 80, 180, 81, 181, 82, 182, 83, 183,
        84, 184, 85, 185, 86, 186, 87, 187, 88, 188,
        89, 189, 90, 190, 91, 191, 92, 192, 93, 193,
        94, 194, 95, 195, 96, 196, 97, 197, 98, 198,
        99, 199, 48, 148,
    };

    static GLvoid *indices[] = {
        surface_front,
        surface_back,
        surface_outin,
    };
    static GLsizei count[] = {
        106,
        106,
        204,
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
    glMaterialfv(GL_FRONT, GL_AMBIENT, silver_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, silver_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, silver_specular);
    glMateriali(GL_FRONT, GL_SHININESS, silver_shine);

    z_disk_surface(10.0, 0.0, 17.0, 5.0);
    glPushMatrix();
        glScalef(1.0, 5.0, 5.0);
        x_unit_circle(0.0);
        x_unit_circle(17.0);
    glPopMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT, silver_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, silver_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, silver_specular);
    glMateriali(GL_FRONT, GL_SHININESS, silver_shine);

    z_disk_surface(12.0, 17.0, 23.0, 6.0);
    glPushMatrix();
        glScalef(1.0, 6.0, 6.0);
        x_unit_circle(17.0);
        x_unit_circle(23.0);
    glPopMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT,  wplastic_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,  wplastic_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, wplastic_specular);
    glMateriali(GL_FRONT, GL_SHININESS, wplastic_shine);

    z_disk_surface(10.0, 23.0, 44.0, 5.0);
    glPushMatrix();
        glScalef(1.0, 5.0, 5.0);
        x_unit_circle(23.0);
        x_unit_circle(44.0);
    glPopMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT,  obi_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,  obi_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, obi_specular);
    glMateriali(GL_FRONT, GL_SHININESS, obi_shine);

    z_disk_surface(8.0, 44.0, 52.0, 3.0);
    glPushMatrix();
        glScalef(1.0, 3.0, 3.0);
        x_unit_circle(44.0);
        x_unit_circle(52.0);
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

    glMaterialfv(GL_FRONT, GL_EMISSION, spark_emission);
    glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_BYTE, spark_tips);
    glDrawElements(GL_POLYGON, 9, GL_UNSIGNED_BYTE, spark_body);
    glMaterialfv(GL_FRONT, GL_EMISSION, zero_emission);
}


/****************************************************
 *                   table                          *
 ****************************************************
 * Draws a nice table                               *
 ****************************************************/
void table (void)
{
    //top
    glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT,  wood_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,  wood_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR, wood_specular);
        glMateriali(GL_FRONT, GL_SHININESS, wood_shine);
        glTranslatef(-500, -237, 170);
        glScalef(1000, 50, 400);
        unit_cube();
    glPopMatrix();
    //legs
    glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT,  obi_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,  obi_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR, obi_specular);
        glMateriali(GL_FRONT, GL_SHININESS, obi_shine);
        glTranslatef(-500, -237, 145);
        glRotatef(180, 1, 0, 0);
        glScalef(25, 400, 25);
        unit_cube(); //front left
        glPushMatrix();
            glTranslatef(39, 0, 0);
            unit_cube(); //front right
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0, 0, 15);
            unit_cube(); //back left
        glPopMatrix();
        glPushMatrix();
            glTranslatef(39, 0, 15);
            unit_cube(); //back right
        glPopMatrix();
    glPopMatrix();
}


/****************************************************
 *                   toolbox                        *
 ****************************************************
 * Draws a ruby red toolbox                         *
 ****************************************************/
void toolbox (void)
{
    glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT,  ruby_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,  ruby_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR, ruby_specular);
        glMateriali(GL_FRONT, GL_SHININESS, ruby_shine);
        glTranslatef(-1050, -637, 170);
        glPushMatrix();
            glScalef(500, 700, 400);
            unit_cube();
        glPopMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT,  silver_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,  silver_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR, silver_specular);
        glMateriali(GL_FRONT, GL_SHININESS, silver_shine);
        glPushMatrix();
            glTranslatef(50, 150, 5);
            glScalef(400, 10, 10);
            unit_cube();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(50, 300, 5);
            glScalef(400, 10, 10);
            unit_cube();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(50, 450, 5);
            glScalef(400, 10, 10);
            unit_cube();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(50, 550, 5);
            glScalef(400, 10, 10);
            unit_cube();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(50, 625, 5);
            glScalef(400, 10, 10);
            unit_cube();
        glPopMatrix();
    glPopMatrix();
}


/****************************************************
 *                overhead_light                    *
 ****************************************************
 * Draws an overhead light to put a light source in *
 ****************************************************/
void overhead_light (void)
{
    glPushMatrix();
        glTranslatef(-250, 450, 0);
        glRotatef(90, 0, 0, 1);
        glPushMatrix();
            glScalef(70, 30, 30);
            z_disk_surface(20, 0, 1, 1);
            x_unit_circle(1);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(70, 0, 0);
            glScalef(300, 3, 3);
            z_disk_surface(20, 0, 1, 1);
        glPopMatrix();
    glPopMatrix();
}


/****************************************************
 *                flashlight                        *
 ****************************************************
 * Draws a flashlight on the table                  *
 ****************************************************/
void flashlight (void)
{
    glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT,  tin_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,  tin_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR, tin_specular);
        glMateriali(GL_FRONT, GL_SHININESS, tin_shine);
        glTranslatef(250, -170, 0);
        glRotatef(45, 0, 1, 0);
        glRotatef(-3, 0, 0, 1);
        glPushMatrix();
            glScalef(110, 10, 10);
            z_disk_surface(20, 0, 1, 1);
            x_unit_circle(1);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-30, 0, 0);
            glScalef(30, 15, 15);
            z_disk_surface(20, 0, 1, 1);
            x_unit_circle(1);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-55, 0, 0);
            glScalef(30, 14.8, 14.8);
            glMaterialfv(GL_FRONT, GL_EMISSION, flashlight_emission);
            x_unit_circle(1);
            glMaterialfv(GL_FRONT, GL_EMISSION, zero_emission);
        glPopMatrix();
    glPopMatrix();
}
