
/********************************************************
 *                                                      *
 *        Mouse-pick: interaction lab solution          *
 *                                                      *
 ********************************************************/

/* 3 squares in 400 X 400 window, using 400 X 400 view volume, 
   displayed in 400 X 400 window.
*/


#include <GL/glut.h>

float R1 = 1.0, G1 = 0.0, B1 = 0.0, 
      R2 = 0.0, G2 = 1.0, B2 = 0.0, 
      R3 = 0.0, G3 = 0.0, B3 = 1.0;    //colors of squares
float BGR = 1.0, BGG = 1.0, BGB = 1.0; //background colors
int   X1 = 50, Y1 = 50, 
      X2 = 200, Y2 = 100,
      X3 = 225, Y3 = 300;              //coords of squares
int   W = 30;                          //width of squares     

void init (void)
{
  glClearColor (BGR, BGG, BGB, 0.0);
  glShadeModel (GL_FLAT);
}

void drawSquare (int x, int y, int w)
{
  glBegin(GL_POLYGON);
    glVertex2i(x, y);
    glVertex2i(x + w, y);
    glVertex2i(x + w, y + w);
    glVertex2i(x, y + w);
  glEnd();
}


void display (void)
{
  glClear (GL_COLOR_BUFFER_BIT);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, 400, 0, 400);
  glPolygonMode(GL_FRONT, GL_FILL);
  glColor3f (R1, G1, B1);
  drawSquare (X1, Y1, W);
  glColor3f (R2, G2, B2);
  drawSquare (X2, Y2, W);
  glColor3f (R3, G3, B3);
  drawSquare (X3, Y3, W);

  glFlush ();
  glutSwapBuffers();
}

void mouse (int button, int state, int x, int y)
{
    switch(button)
    {
        case GLUT_LEFT_BUTTON:
            if(state == GLUT_DOWN)
            {
                glutPostRedisplay();
            }
            break;
        default:
            break;
    }
}

int main (int argc, char** argv)
{
  glutInit (&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize (400, 400);
  glutInitWindowPosition (100, 100);
  glutCreateWindow (argv[0]);
  init ();
  glutDisplayFunc (display);
  glutMouseFunc (mouse);
  glutMainLoop ();
  return 0;
}
