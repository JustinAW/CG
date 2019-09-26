
/********************************************************
 *                                                      *
 *                       redisplay1                     *
 *                                                      *
 ********************************************************/

/* Lab skeleton.
   Changes color of a rectangle from a menu.  Used to enforce
   redisplay and use of menus (or mouse or keyboard).  
*/


#include <GL/glut.h>
#include <time.h>
#include <stdio.h>

float Red = 1.0, Green = 0.0, Blue = 0.0;  //color settings are global

void init (void)
{
  glClearColor (1.0, 1.0, 1.0, 0.0);
  glShadeModel (GL_FLAT);
}

void reshape (int w, int h)  //stay focussed on main object
{
  if ( w > h)
    glViewport (0, 0, (GLfloat) h, (GLfloat) h);
  else
    glViewport (0, 0, (GLfloat) w, (GLfloat) w);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluOrtho2D (-14.0, 38.0, -6.0, 46.0);
}


void display (void)
{
  glClear (GL_COLOR_BUFFER_BIT);

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glColor3f (Red, Green, Blue);
  glBegin (GL_POLYGON);
  glVertex2s (6, 0);
  glVertex2s (16, 0);
  glVertex2s (16, 42);
  glVertex2s (6, 42);
  glEnd ();

  glFlush ();

}

//Put menu and submenu function definitions here

int main (int argc, char** argv)
{
  glutInit (&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize (200, 200);
  glutInitWindowPosition (100, 100);
  glutCreateWindow (argv[0]);
  init ();

  //Create the submenu and menu here

  glutDisplayFunc (display);
  glutReshapeFunc (reshape);
  glutMainLoop ();
  return 0;
}
