/**************************************************************
 *                                                            *
 *                         Tiling.c                           *
 *  Same as bmp-loader except modified for tiling             *
 *                                                            *
 **************************************************************/


#include <stdio.h>
#include "soil.h"
//#include <GL/glut.h>
#include <GLUT/glut.h>

void init (void);
void reshape (int, int);
void display (void);

int        width;       // Width of window 
int        height;      // Height of window 
GLubyte    *tex;        // Bitmap data
GLfloat borderColor[] = {1.0, 0.0, 0.0, 1.0};

/**************************************************************
 *                            main                            *
 **************************************************************/

int main(int  argc, char *argv[]) 
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
  glutInitWindowSize(792, 573);
  glutCreateWindow("Bitmap File Viewer");
  glutReshapeFunc(reshape);
  glutDisplayFunc(display);

  //Put path to texture file as first argument
  tex = SOIL_load_OGL_texture("grass64.bmp", 4, 0, 0);
  if (!tex) {
	printf("***NO BITMAP RETRIEVED***\n");  //Check to see if successfully loaded
	exit(1);
  }
  init();
  glutMainLoop();
  return (0);
}


/**************************************************************
 *                            init                            *
 **************************************************************/

void init (void)
{
  glClearColor (1.0, 1.0, 1.0, 0.0);
  glShadeModel(GL_FLAT);
  glTexEnvi (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  //NOTE: No need to call glTexImage2D since SOIL_load_OGL_texture() loads
  //      loads the image directly into texture memory
  //glTexImage2D (GL_TEXTURE_2D, 0, GL_RGBA, 64, 64, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, tex);
  glEnable(GL_TEXTURE_2D);
}

/**************************************************************
 *                           reshape                          *
 **************************************************************/

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

/**************************************************************
 *                           display                          *
 **************************************************************/

void display (void)
{
  glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glColor4f(1.0, 0.0, 1.0, 1.0);
  glBegin(GL_POLYGON);
    glTexCoord2f(0.0, 0.0);
    glVertex2i(-3, -2);
    glTexCoord2f(3.0, 0.0);
    glVertex2i(3, -2);
    glTexCoord2f(3.0, 2.0);
    glVertex2i(3, 2);
    glTexCoord2f(0.0, 2.0);
    glVertex2i(-3, 2);
  glEnd();

  glFlush ();
}


