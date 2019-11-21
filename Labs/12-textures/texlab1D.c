

/********************************************************
 *                                                      *
 *                       texlab1d.c                     *
 *                                                      *
 ********************************************************/

/*
 * Tests 1S texturing
 */

#include <GL/glut.h>

void init (void);
void reshape (int, int);
void display (void);

GLubyte tex1[] =     {255, 0, 0, 255,
                      255, 0, 0, 255,
                      0, 0, 255, 255,
                      0, 0, 255, 255};


int main (int argc, char** argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize (800, 800);
    glutInitWindowPosition (0, 0);
    glutCreateWindow (argv[0]);
    glutReshapeFunc(reshape);
    init ();
    glutDisplayFunc (display);
    glutMainLoop ();
    return 0;
}

void init (void)
{
    glClearColor (1.0, 1.0, 1.0, 1.0);
    glShadeModel(GL_FLAT);
}

void reshape (int w, int h)
{
    if ( w > h)
        glViewport (0, 0, (GLfloat) h, (GLfloat) h);
    else
        glViewport (0, 0, (GLfloat) w, (GLfloat) w);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluOrtho2D (-5.0, 5.0, -5.0, 5.0);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity ();
}

void display (void)
{

    glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLineWidth(3);
    glTexEnvi (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexParameteri (GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri (GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage1D (GL_TEXTURE_1D, 0, GL_RGBA, 4, 0, GL_RGBA, GL_UNSIGNED_BYTE, tex1); 
    glEnable(GL_TEXTURE_1D);
    glBegin(GL_LINES);
        glTexCoord1f(0.0);
        glVertex2i(-3, -3);
        glTexCoord1i(1.0);
        glVertex2i(3, -3);
    glEnd();

    glFlush ();
}

