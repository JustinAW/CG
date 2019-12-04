/********************************************************
 *                                                      *
 *                   texlab2d-zoom.c                    *
 *                                                      *
 ********************************************************/

#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#include "SOIL/SOIL.h"

void init (void);
void reshape (int, int);
void keyboard (unsigned char, int, int);
void display (void);
void buildTexture (void);

int CAM_Z = -6;

//GLubyte mm64[64][64][4];
//GLubyte mm32[32][32][4];
//GLubyte mm16[16][16][4];
//GLubyte mm8[8][8][4];
//GLubyte mm4[4][4][4];
//GLubyte mm2[2][2][4];
//GLubyte mm1[1][1][4];

static GLuint tex;
int WIDTH = 64;
int HEIGHT = 64;
int CHANNELS = 4;

void init (void)
{
    glColor3f(0,0,0);
    glClearColor (1.0, 1.0, 1.0, 1.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    tex = SOIL_load_OGL_texture("Bitmaps/grass64.bmp",
            4, 0, SOIL_FLAG_POWER_OF_TWO); // SOIL_FLAG_MIPMAPS
    if (!tex) {
        printf("***NO BITMAP RETRIEVED***\n");
        exit(1);
    }

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
            GL_NEAREST_MIPMAP_NEAREST);

    unsigned char *image;
    image = SOIL_load_image("Bitmaps/grass64.bmp", &WIDTH, &HEIGHT, &CHANNELS,
            SOIL_LOAD_RGBA);
    if (!image) {
        printf("***NO IMAGE RETRIEVED***\n");
        exit(1);
    }
    gluBuild2DMipmapLevels(GL_TEXTURE_2D, GL_RGBA, 64, 64, GL_RGBA,
            GL_UNSIGNED_BYTE, 0, 0, 6, image);
    free(image);

//    buildTexture();
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 64, 64, 0,
//            GL_RGBA, GL_UNSIGNED_BYTE, mm64);
//    glTexImage2D(GL_TEXTURE_2D, 1, GL_RGBA, 32, 32, 0,
//            GL_RGBA, GL_UNSIGNED_BYTE, mm32);
//    glTexImage2D(GL_TEXTURE_2D, 2, GL_RGBA, 16, 16, 0,
//            GL_RGBA, GL_UNSIGNED_BYTE, mm16);
//    glTexImage2D(GL_TEXTURE_2D, 3, GL_RGBA, 8, 8, 0,
//            GL_RGBA, GL_UNSIGNED_BYTE, mm8);
//    glTexImage2D(GL_TEXTURE_2D, 4, GL_RGBA, 4, 4, 0,
//            GL_RGBA, GL_UNSIGNED_BYTE, mm4);
//    glTexImage2D(GL_TEXTURE_2D, 5, GL_RGBA, 2, 2, 0,
//            GL_RGBA, GL_UNSIGNED_BYTE, mm2);
//    glTexImage2D(GL_TEXTURE_2D, 6, GL_RGBA, 1, 1, 0,
//            GL_RGBA, GL_UNSIGNED_BYTE, mm1);

    glLoadIdentity();
}

void display (void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glBindTexture(GL_TEXTURE_2D, tex);

    glPushMatrix();
        gluLookAt(0.0, 0.0, CAM_Z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
        glBegin(GL_POLYGON);
            glTexCoord2f(0.0, 0.0);
            glVertex2i(-3, -3);
            glTexCoord2f(1.0, 0.0);
            glVertex2i(3, -3);
            glTexCoord2f(1.0, 1.0);
            glVertex2i(3, 3);
            glTexCoord2f(0.0, 1.0);
            glVertex2i(-3, 3);
        glEnd();
    glPopMatrix();

    glutSwapBuffers();
}

//void buildTexture (void)
//{
//    GLubyte base, offset, i, j;
//
//    for (i = 0; i < 64; i++) {
//        for (j = 0; j < 64; j++) {
//            mm64[i][j][0] = 255;
//            mm64[i][j][1] = 0;
//            mm64[i][j][2] = 0;
//            mm64[i][j][3] = 255;
//        }
//    }
//    for (i = 0; i < 32; i++) {
//        for (j = 0; j < 32; j++) {
//            mm32[i][j][0] = 0;
//            mm32[i][j][1] = 255;
//            mm32[i][j][2] = 0;
//            mm32[i][j][3] = 255;
//        }
//    }
//    for (i = 0; i < 16; i++) {
//        for (j = 0; j < 16; j++) {
//            mm16[i][j][0] = 0;
//            mm16[i][j][1] = 0;
//            mm16[i][j][2] = 255;
//            mm16[i][j][3] = 255;
//        }
//    }
//    for (i = 0; i < 8; i++) {
//        for (j = 0; j < 8; j++) {
//            mm8[i][j][0] = 255;
//            mm8[i][j][1] = 0;
//            mm8[i][j][2] = 255;
//            mm8[i][j][3] = 255;
//        }
//    }
//    for (i = 0; i < 4; i++) {
//        for (j = 0; j < 4; j++) {
//            mm4[i][j][0] = 255;
//            mm4[i][j][1] = 255;
//            mm4[i][j][2] = 0;
//            mm4[i][j][3] = 255;
//        }
//    }
//    for (i = 0; i < 2; i++) {
//        for (j = 0; j < 2; j++) {
//            mm2[i][j][0] = 0;
//            mm2[i][j][1] = 255;
//            mm2[i][j][2] = 255;
//            mm2[i][j][3] = 255;
//        }
//    }
//    for (i = 0; i < 1; i++) {
//        for (j = 0; j < 1; j++) {
//            mm1[i][j][0] = 200;
//            mm1[i][j][1] = 200;
//            mm1[i][j][2] = 200;
//            mm1[i][j][3] = 255;
//        }
//    }
//}

void reshape (int w, int h)
{
    if ( w > h)
        glViewport (0, 0, (GLfloat) h, (GLfloat) h);
    else
        glViewport (0, 0, (GLfloat) w, (GLfloat) w);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glFrustum (-5.0, 5.0, -5.0, 5.0, 5.0, 10000.0);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity ();
}

void keyboard (unsigned char key, int x, int y)
{
    switch (key) {
        case 'k':
            CAM_Z++;
            glutPostRedisplay();
            break;
        case 'j':
            CAM_Z--;
            glutPostRedisplay();
            break;
        case 27:
            exit(0);
        default:
            break;
    }
}

int main (int argc, char** argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize (800, 800);
    glutInitWindowPosition (0, 0);
    glutCreateWindow (argv[0]);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    init ();
    glutDisplayFunc (display);
    glutMainLoop ();
    return 0;
}
