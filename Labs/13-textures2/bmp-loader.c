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

    tex = SOIL_load_OGL_texture("Bitmaps/grass64.bmp", 4, 0, 0);
    if (!tex) {
        printf("***NO BITMAP RETRIEVED***\n");  //Check to see if successfully loaded
        exit(1);
    }
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
  glClearColor (1.0, 1.0, 1.0, 0.0);
  glShadeModel(GL_FLAT);
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
    glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glTexEnvi (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    //NOTE: No need to call glTexImage2D since SOIL_load_OGL_texture() loads
    //      loads the image directly into texture memory
    glEnable(GL_TEXTURE_2D);

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

    glFlush ();
}


void keyboard (unsigned char key, int x, int y) {
    switch (key) {
        case 27:
            exit(0);
        default:
            break;
    }
}
