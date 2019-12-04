/**************************************************************
 *                                                            *
 *                        bmp-loader.c                        *
 *                                                            *
 *  Uses SOIL to load textures.                               *
 *                                                            *
 **************************************************************/


#include <stdio.h>
#include "SOIL/SOIL.h"
#include <GL/glut.h>

void init (void);
void reshape (int, int);
void display (void);
void keyboard (unsigned char, int, int);

GLuint tex;        // Bitmap data
GLuint tex2;

/**************************************************************
 *                            main                            *
 **************************************************************/
int main (int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);

    init();

    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return (0);
}


/**************************************************************
 *                            init                            *
 **************************************************************/
void init (void)
{
    tex = SOIL_load_OGL_texture("Bitmaps/grass64.bmp", 4, 0, 0);
    if (!tex) {
        printf("***NO BITMAP RETRIEVED***\n");  //Check to see if successfully loaded
        exit(1);
    }
    glBindTexture(GL_TEXTURE_2D, tex);

    tex2 = SOIL_load_OGL_texture("Bitmaps/pattern1-64.bmp", 4, 0, 0);
    if (!tex2) {
        printf("***NO BITMAP RETRIEVED***\n");
        exit(1);
    }
    glBindTexture(GL_TEXTURE_2D, tex2);

    glClearColor (1.0, 1.0, 1.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_TEXTURE_2D);
    glLoadIdentity();
}

/**************************************************************
 *                           reshape                          *
 **************************************************************/
void reshape (int w, int h)
{
    glLoadIdentity ();
    if ( w > h)
        glViewport (0, 0, (GLfloat) h, (GLfloat) h);
    else
        glViewport (0, 0, (GLfloat) w, (GLfloat) w);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluOrtho2D (-25.0, 25.0, -25.0, 25.0);

    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity ();
}

/**************************************************************
 *                           display                          *
 **************************************************************/
void display (void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glBindTexture(GL_TEXTURE_2D, tex);
    glBegin(GL_POLYGON);
        glTexCoord2f(0.0, 0.0);
        glVertex2i(-12, -2);
        glTexCoord2f(3.0, 0.0);
        glVertex2i(-6, -2);
        glTexCoord2f(3.0, 2.0);
        glVertex2i(-6, 2);
        glTexCoord2f(0.0, 2.0);
        glVertex2i(-12, 2);
    glEnd();
    glBegin(GL_POLYGON);
        glTexCoord2f(0.0, 0.0);
        glVertex2i(-6, -2);
        glTexCoord2f(3.0, 0.0);
        glVertex2i(0, -2);
        glTexCoord2f(3.0, 1.0);
        glVertex2i(0, 0);
        glTexCoord2f(0.0, 1.0);
        glVertex2i(-6, 0);
    glEnd();

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glBindTexture(GL_TEXTURE_2D, tex2);
    glBegin(GL_POLYGON);
        glTexCoord2f(0.0, 0.0);
        glVertex2i(-6, 0);
        glTexCoord2f(2.0, 0.0);
        glVertex2i(-3, 0);
        glTexCoord2f(2.0, 3.0);
        glVertex2i(-3, 6);
        glTexCoord2f(0.0, 3.0);
        glVertex2i(-6, 6);
    glEnd();
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glBegin(GL_POLYGON);
        glTexCoord2f(0.0, 0.0);
        glVertex2i(-12, -4);
        glTexCoord2f(6.0, 0.0);
        glVertex2i(0, -4);
        glTexCoord2f(6.0, 1.0);
        glVertex2i(0, -2);
        glTexCoord2f(0.0, 1.0);
        glVertex2i(-12, -2);
    glEnd();

    glFlush();
}

/**************************************************************
 *                          keyboard                          *
 **************************************************************/
void keyboard (unsigned char key, int x, int y) {
    switch (key) {
        case 27:
            exit(0);
        default:
            break;
    }
}
