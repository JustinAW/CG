
/********************************************************
 *                                                      *
 *                      Reshape1.c                      *
 *                                                      *
 ********************************************************/

/* Draws a 3 X 3 grid of squares using a default viewport.
*/

#include <GL/glut.h>

void init (void)
{
  glClearColor (1.0, 1.0, 1.0, 0.0);
  glShadeModel (GL_FLAT);
}

void display (void)
{
  glClear (GL_COLOR_BUFFER_BIT);
  glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
  glColor3f (1.0, 0.0, 0.0);
  glBegin (GL_QUADS);

    //bottom row
    glVertex2s (10, 10);
    glVertex2s (90, 10);
    glVertex2s (90, 90);
    glVertex2s (10, 90);

    glVertex2s (110, 10);
    glVertex2s (190, 10);
    glVertex2s (190, 90);
    glVertex2s (110, 90);

    glVertex2s (210, 10);
    glVertex2s (290, 10);
    glVertex2s (290, 90);
    glVertex2s (210, 90);

    //middle row
    glVertex2s (10, 110);
    glVertex2s (90, 110);
    glVertex2s (90, 190);
    glVertex2s (10, 190);

    glVertex2s (110, 110);
    glVertex2s (190, 110);
    glVertex2s (190, 190);
    glVertex2s (110, 190);

    glVertex2s (210, 110);
    glVertex2s (290, 110);
    glVertex2s (290, 190);
    glVertex2s (210, 190);

    //top row
    glVertex2s (10, 210);
    glVertex2s (90, 210);
    glVertex2s (90, 290);
    glVertex2s (10, 290);

    glVertex2s (110, 210);
    glVertex2s (190, 210);
    glVertex2s (190, 290);
    glVertex2s (110, 290);

    glVertex2s (210, 210);
    glVertex2s (290, 210);
    glVertex2s (290, 290);
    glVertex2s (210, 290);

  glEnd ();

  glFlush ();
}

//reshape function
void reshape (int w, int h)
{
  glViewport (0, 0, 100, 100);                //values as appropriate
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluOrtho2D (0.0, (GLdouble)100, 0.0, (GLdouble)100);                //values as appropriate
}


int main (int argc, char** argv)
{
  glutInit (&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize (100, 100);
  glutInitWindowPosition (0, 0);
  glutCreateWindow (argv[0]);
  init ();

  //These 3 lines will migrate to the reshape function
  /*
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluOrtho2D (0.0, (GLdouble) 100, 0.0, (GLdouble) 100);
  */

  glutDisplayFunc (display);

  glutReshapeFunc (reshape);  //enable when use reshape function
  glutMainLoop ();
  return 0;
}
