/**************************************************************
 *                                                            *
 *                     tex-lab2-zoom.c                        *
 *                     Texture Filters                        *
 *                                                            *
 *                                                            *
 **************************************************************/


#include <stdio.h>
#include "soil.h"
#include <GLUT/glut.h>
//#include <GL/glut.h>

void init (void);
void reshape (int, int);
void display (void);
void keyboard (unsigned char inKey, int x, int y);

int        width;       // Width of window 
int        height;      // Height of window 
GLubyte    *tex;        // Bitmap data

int cameraZ;

/**************************************************************
 *                            main                            *
 **************************************************************/

int main(int  argc, char *argv[]) 
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutInitWindowSize(792, 573);
  glutCreateWindow("Bitmap File Viewer");
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutDisplayFunc(display);

  tex = SOIL_load_OGL_texture("grass64.bmp", 4, 0, SOIL_FLAG_POWER_OF_TWO);
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
	glClearColor (1.0, 1.0, 1.0, 1.0);
	glShadeModel(GL_FLAT);
	cameraZ = -40.0;
}

/**************************************************************
 *                          reshape                           *
 **************************************************************/

void reshape (int w, int h)
{
	if ( w > h)
      glViewport (0, 0, (GLfloat) h, (GLfloat) h);
	else
      glViewport (0, 0, (GLfloat) w, (GLfloat) w);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	glFrustum (-5.0, 5.0, -5.0, 5.0, 5.0, 10000.0);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();
}

/**************************************************************
 *                          keyboard                          *
 **************************************************************/

void keyboard (unsigned char inKey, int x, int y)
{
	if (inKey == 'j') {
        cameraZ++;
	    glutPostRedisplay();
    }
	else if (inKey == 'k') {
        cameraZ--;
	    glutPostRedisplay();
	}
}
	
/**************************************************************
 *                           display                          *
 **************************************************************/

void display (void)
{
  glMatrixMode (GL_MODELVIEW);
  glLoadIdentity ();
  gluLookAt(0.0, 0.0, cameraZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glTexEnvi (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
  glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  //NOTE: No need to call glTexImage2D since SOIL_load_OGL_texture() loads
  //      loads the image directly into texture memory
  //glTexImage2D (GL_TEXTURE_2D, 0, GL_RGBA, 64, 64, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, tex);
  glEnable(GL_TEXTURE_2D);
  glColor4f(1.0, 0.0, 1.0, 1.0);
  glBegin(GL_POLYGON);
    glTexCoord2f(0.0, 0.0);
    glVertex2i(-3, -3);
    glTexCoord2f(1.0, 0.0);
    glVertex2i(3, -3);
    glTexCoord2f(1.0, 1.0);
    glVertex2i(3, 3);
    glTexCoord2f(0.0, 1.0);
    glVertex2i(-3, 3);
  glEnd();
  glutSwapBuffers();

  glFlush ();
}


