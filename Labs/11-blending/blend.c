
/********************************************************
 *                                                      *
 *                        Blend.c                       *
 *                                                      *
 ********************************************************/

/*
 * Blending quads
 */

#include <GL/glut.h>

void init (void)
{
    glEnable(GL_DEPTH_TEST);

    glClearColor (1.0, 1.0, 1.0, 0.0);
    glShadeModel (GL_FLAT);
    glLoadIdentity();
}

void display (void)
{
    glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthFunc(GL_LESS);

    glPushMatrix();
        // Simple quads
        glColor4f (0.0, 1.0, 0.0, 1.0);
        glBegin (GL_QUADS);
            glVertex3i (30, 0, -2);
            glVertex3i (60, 0, -2);
            glVertex3i (60, 30, -2);
            glVertex3i (30, 30, -2);
        glEnd ();
    glPopMatrix();

    glPushMatrix();
        glDepthMask(GL_FALSE);
        glEnable(GL_BLEND);

        glColor4f (0.0, 0.0, 1.0, 0.3333);
        glBegin (GL_QUADS);
            glVertex3i (20, 20, -1);
            glVertex3i (50, 20, -1);
            glVertex3i (50, 50, -1);
            glVertex3i (20, 50, -1);
        glEnd ();

        glColor4f (1.0, 0.0, 0.0, 0.3333);
        glBegin (GL_QUADS);
            glVertex3i (10, 0, -3);
            glVertex3i (40, 0,  -3);
            glVertex3i (40, 30, -3);
            glVertex3i (10, 30, -3);
        glEnd ();

        glDepthMask(GL_TRUE);
    glPopMatrix();

    glFlush ();
}

void reshape (int w, int h)
{
    if (w > h)
        glViewport (0, 0, (GLsizei) h, (GLsizei) h);
    else
        glViewport (0, 0, (GLsizei) w, (GLsizei) w);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glOrtho (0.0, 70.0, -10.0, 60.0, 0.0, 5.0);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity ();
}


int main (int argc, char** argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize (200, 200);
    glutInitWindowPosition (0, 0);
    glutCreateWindow (argv[0]);
    init ();
    glutDisplayFunc (display);
    glutReshapeFunc (reshape);
    glutMainLoop ();
    return 0;
}
