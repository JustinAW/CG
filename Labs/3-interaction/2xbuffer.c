
/********************************************************
 *                                                      *
 *                      2xbuffer.c                      *
 *                                                      *
 ********************************************************/

/* This program draws 100 colored 2D rectangles in single 
   buffered mode.  Left clicking the mouse redraws the 
   scene, with a noticeable flicker.  The faster you click, 
   the more noticeable.

   Double buffering eliminates this.

  ** NOTE: You may need to increase the number of 
     iterations of the loop to produce noticeable flicker.

*/

#include <GL/glut.h>
#include<stdio.h>

static int X0 = 5;
static int Y0 = 5;
static int HEIGHT = 4;
static int WIDTH = 4;
static float COLORINC = 0.01f;

void mouse1 (int, int, int, int);
void init (void);
void display (void);

int main (int argc, char** argv)
{
  glutInit (&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize (800, 800);
  glutInitWindowPosition (0, 50);
  glutCreateWindow (argv[0]);
  init ();
  glutDisplayFunc (display);
  glutMouseFunc(mouse1);
  glutMainLoop ();
  return 0;
}

void init (void)
{
  glClearColor (1.0, 1.0, 1.0, 0.0);
  glShadeModel (GL_FLAT);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluOrtho2D (0.0, 800.0, 0.0, 800.0);
  glMatrixMode (GL_MODELVIEW);
  glLoadIdentity ();
}

void display (void)
{
  int X = 5, Y = 5;
  int XINC = WIDTH + 3;
  int YINC = HEIGHT + 3; 
  int i, j, k;
  float Red = 0.0f, Green = 0.0f , Blue = 0.0f , BlueBase = 0.0;

  glClear (GL_COLOR_BUFFER_BIT);
  glViewport (0, 0, 800, 800);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

  //Lots of filled objects
  for (i = 0; i < 100; i++) {
    glColor3f(Red+=COLORINC, Green, Blue);
    Blue = BlueBase;
    for (j = 0; j < 100; j++) {
      glColor3f(Red, Green, Blue+=COLORINC);
      glBegin(GL_POLYGON);
        glVertex2i(X, Y);
        glVertex2i(X+WIDTH, Y);
        glVertex2i(X+WIDTH, Y+HEIGHT);
        glVertex2i(X, Y+HEIGHT);
      glEnd();
      X+=XINC;
      for (k = 0; k < 1000; k++);  //loop to slow things up even more
    }
    X = X0; Y += YINC;
  }
      
  glFlush ();
}

void mouse1 (int Button, int State, int X, int Y)
{
  if ((Button == GLUT_LEFT_BUTTON) && (State == GLUT_DOWN))
    glutPostRedisplay();
}

