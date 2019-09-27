
/********************************************************
 *                                                      *
 *                    simple animation                  *
 *                                                      *
 ********************************************************/

/* changes color of an object at fixed time intervals.
   The redisplay isn't needed.  Note that if it is included, 
   it will cause the display fn to be recalled; i.e., the 
   loop begins all over again!
*/


#include <GL/glut.h>
#include <time.h>
#include <stdio.h>

long ResetTime;
int Cycle = 0;
float Colors[3][3] = {{0.0, 1.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 1.0}};
float Red, Green, Blue;
long Time, ResetTime;


void init (void)
{
  glClearColor (1.0, 1.0, 1.0, 0.0);
  glShadeModel (GL_FLAT);
}

void reshape (int w, int h)
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
  long Time, ResetTime;
  int i;

  glClear (GL_COLOR_BUFFER_BIT);

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  Red = Colors[Cycle][0];
  Green = Colors[Cycle][1];
  Blue = Colors[Cycle][2];
  glColor3f (Red, Green, Blue);
  glBegin (GL_POLYGON);
    glVertex2s (6, 0);
    glVertex2s (16, 0);
    glVertex2s (16, 42);
    glVertex2s (6, 42);
  glEnd ();

  glutSwapBuffers();
  glFlush ();

  Time = clock();
  ResetTime = Time + 3 * CLOCKS_PER_SEC;
  for (i = 0; ; i++) {
    Time = clock();
    if (Time > ResetTime) {
      printf ("%d   %d\n", ResetTime, i);
      ResetTime = ResetTime + 3 * CLOCKS_PER_SEC;
      Cycle++;
      Cycle = Cycle % 3;
      Red = Colors[Cycle][0];
      Green = Colors[Cycle][1];
      Blue = Colors[Cycle][2];
      glColor3f (Red, Green, Blue);
      glBegin (GL_POLYGON);
        glVertex2s (6, 0);
        glVertex2s (16, 0);
        glVertex2s (16, 42);
        glVertex2s (6, 42);
      glEnd ();
      glutSwapBuffers();
      glFlush ();
    }
  }
}

int main (int argc, char** argv)
{
  glutInit (&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE|GLUT_RGB);
  glutInitWindowSize (200, 200);
  glutInitWindowPosition (100, 100);
  glutCreateWindow (argv[0]);
  init ();
  glutReshapeFunc (reshape);
  glutDisplayFunc (display);
  glutMainLoop ();
  return 0;
}
