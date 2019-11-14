
/********************************************************
 *                                                      *
 *                     Antialias.c                      *
 *                                                      *
 ********************************************************/

#include <GL/glut.h>
#include <stdio.h>

void init (void)
{
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glShadeModel (GL_FLAT);
    glEnable(GL_BLEND);
    glEnable(GL_MULTISAMPLE);
}

void display (void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

    glColor4f (1.0, 0.0, 0.0, 0.5);

    glLineWidth(5);
    glBegin (GL_LINES);
        glVertex3i (10, 0, -3);
        glVertex3i (15, 30,  -3);
    glEnd ();

    glLineWidth(7);
    glBegin (GL_LINES);
        glVertex3i (15, 0, -3);
        glVertex3i (25, 30,  -3);
    glEnd ();

    glLineWidth(9);
    glBegin (GL_LINES);
        glVertex3i (25, 0, -3);
        glVertex3i (45, 30,  -3);
    glEnd ();

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
    glutInitDisplayMode (GLUT_SINGLE|GLUT_RGB|GLUT_MULTISAMPLE);
    glutInitWindowSize (200, 200);
    glutInitWindowPosition (0, 0);
    glutCreateWindow (argv[0]);
    init ();

    GLint bufs, samples;
    glGetIntegerv(GL_SAMPLE_BUFFERS, &bufs);
    glGetIntegerv(GL_SAMPLES, &samples);

    printf("bufs: %d\nsamples: %d\n", bufs, samples);

    glutDisplayFunc (display);
    glutReshapeFunc (reshape);
    glutMainLoop ();
    return 0;
}
