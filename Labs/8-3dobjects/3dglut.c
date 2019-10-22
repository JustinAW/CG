

/********************************************************
 *                                                      *
 *                        3dglut.c                      *
 *                                                      *
 ********************************************************/

/* Skeleton for displaying glut 3D primitives
*/

#include <GL/glut.h>
#include <stdio.h>


/*************************************
 *               drawAxes            *
 *************************************/
void drawAxes (void)
{
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(2.0, 0.0, 0.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 2.0, 0.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 0.0, 2.0);
    glEnd();
    glRasterPos3f(2.1, 0.1, 0.0);
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, 'x');
    glRasterPos3f(0.1, 2.1, 0.0);
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, 'y');
    glRasterPos3f(0.1, 0.1, 2.0);
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, 'z');
}

/*************************************
 *               display             *
 *************************************/
void display (void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    //glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    //isometric view in upper left corner
//    glLoadIdentity();
    glPushMatrix();
    gluLookAt(10.0, 10.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glViewport(20, 300, 250, 250);
    drawAxes();

    //**** Call to glut 3D functions go here
    // radius, slices, stacks
    // slices: # divs around z axis (latitudinal)
    // stacks: # divs along z axis (longitudinal)
    glutWireSphere(1.0, 10.0, 5.0);
    glPopMatrix();

    //side elevation in upper right corner
    glPushMatrix();
    gluLookAt(10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glViewport(300, 300, 250, 250);
    drawAxes();

    //**** Call to glut 3D functions go here
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glutWireSphere(1.0, 10.0, 5.0);
    glPopMatrix();

    //front elevation in lower left corner
    glPushMatrix();
    gluLookAt(0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glViewport(20, 20, 250, 250);
    drawAxes();

    //**** Call to glut 3D functions go here
    glutWireSphere(1.0, 10.0, 5.0);
    glPopMatrix();

    glFlush ();
}

/*************************************
 *                init               *
 *************************************/
void init (void)
{
    glLoadIdentity();
    glClearColor (1.0, 1.0, 1.0, 0.0);
    //glEnable(GL_DEPTH_TEST);

}

/*************************************
 *              reshape              *
 *************************************/
//Static viewports

void reshape (int w, int h)
{
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glOrtho (-3.0, 3.0, -3.0, 3.0, 5.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/*************************************
 *                main               *
 *************************************/
int main (int argc, char** argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE|GLUT_RGB);
    //glutInitDisplayMode (GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize (600, 600);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    glutReshapeFunc(reshape);
    init ();
    glutDisplayFunc (display);
    glutMainLoop ();
    return 0;
}
