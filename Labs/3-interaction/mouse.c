
/********************************************************
 *                                                      *
 *        Mouse-pick: interaction lab solution          *
 *                                                      *
 ********************************************************/

/* 3 squares in 400 X 400 window, using 400 X 400 view volume, 
   displayed in 400 X 400 window.
*/


#include <GL/glut.h>
#include <stdio.h>

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

void check_squares (int x, int y);
void mouse (int button, int state, int x, int y)
{
    switch(button)
    {
        case GLUT_LEFT_BUTTON:
            if(state == GLUT_DOWN)
            {
                check_squares(x, y);
                glutPostRedisplay();
            }
            break;
        default:
            break;
    }
}

void keyboard (unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'e':
            check_squares(x, y);
            glutPostRedisplay();
            break;
        case 'E':
            check_squares(x, y);
            glutPostRedisplay();
            break;
        default:
            break;
    }
}

void check_squares (int x, int y)
{
    if(X1 < x && x < (X1 + W) && (400 - Y1 - W) < y && y < (400 - Y1))
    {
        printf("Red:\n");
        printf("x: %d - y: %d\n", x, y);
        R1 = BGR;
        G1 = BGG;
        B1 = BGB;
    }
    if(X2 < x && x < (X2 + W) && (400 - Y2 - W) < y && y < (400 - Y2))
    {
        printf("Green:\n");
        printf("x: %d - y: %d\n", x, y);
        R2 = BGR;
        G2 = BGG;
        B2 = BGB;
    }
    if(X3 < x && x < (X3 + W) && (400 - Y3 - W) < y && y < (400 - Y3))
    {
        printf("Blue:\n");
        printf("x: %d - y: %d\n", x, y);
        R3 = BGR;
        G3 = BGG;
        B3 = BGB;
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
  glutKeyboardFunc (keyboard);
  glutMainLoop ();
  return 0;
}
