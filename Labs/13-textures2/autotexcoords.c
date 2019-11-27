
/********************************************************
 *                                                      *
 *                    autotexcoords.c                   *
 *                                                      *
 ********************************************************/

/*
 * From Programmers' Guide C9: Automatic Tex Coord Generation
 */

#include <GL/glut.h>

#define stripeImageWidth 32

void init (void);
void reshape (int, int);
void display (void);
void makeStripeImage (void);
void keyboard (unsigned char key, int x, int y);
void makeStripeImage (void);
void buildTexture (void);

GLubyte stripeImage[4*stripeImageWidth];

//GLubyte tex[8][8][4]; Loaded by buildTexture 

// Planes for texture-coordinate generation

static GLfloat xequalzero[] = {1.0, 0.0, 0.0, 0.0};
static GLfloat slanted[] = {1.0, 1.0, 1.0, 0.0};
static GLfloat *currentCoeff;
static GLenum currentPlane;
static GLint currentGenMode;
static GLint anglez = 0;
static GLint angley = 0;

int main (int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(256, 256);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();

    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

void init (void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    makeStripeImage();
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage1D(GL_TEXTURE_1D, 0, GL_RGBA, stripeImageWidth, 0, GL_RGBA,
            GL_UNSIGNED_BYTE, stripeImage);
//    glTexImage2D (GL_TEXTURE_2D, 0, GL_RGBA, 8, 8, 0, GL_RGBA,
//            GL_UNSIGNED_BYTE, tex);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    currentCoeff = xequalzero;
    currentGenMode = GL_OBJECT_LINEAR;
    currentPlane = GL_OBJECT_PLANE;
    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, currentGenMode);
    glTexGenfv(GL_S, currentPlane, currentCoeff);

    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_1D);
    glEnable(GL_CULL_FACE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_NORMALIZE);
    glFrontFace(GL_CW);
    glCullFace(GL_BACK);
    glMaterialf(GL_FRONT, GL_SHININESS, 64.0);
}

void reshape (int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-3.5, 3.5, -3.5 * (GLfloat)h / (GLfloat)w,
                3.5 * (GLfloat)h / (GLfloat)w, -3.5, 3.5);
    else
        glOrtho(-3.5 * (GLfloat)w / (GLfloat)h,
                3.5 * (GLfloat)w / (GLfloat)h, -3.5, 3.5, -3.5, 3.5);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display (void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(anglez, 0.0, 0.0, 1.0);
        glRotatef(angley, 0.0, 1.0, 0.0);
        glutSolidTeapot(2.0);
    glPopMatrix();
    glutSwapBuffers();
}

void keyboard (unsigned char key, int x, int y)
{
    switch (key) {
        case 'e': case 'E':
            currentGenMode = GL_EYE_LINEAR;
            currentPlane = GL_EYE_PLANE;
            glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, currentGenMode);
            glTexGenfv(GL_S, currentPlane, currentCoeff);
            glutPostRedisplay();
            break;
        case 'o': case 'O':
            currentGenMode = GL_OBJECT_LINEAR;
            currentPlane = GL_OBJECT_PLANE;
            glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, currentGenMode);
            glTexGenfv(GL_S, currentPlane, currentCoeff);
            glutPostRedisplay();
            break;
        case 's': case 'S':
            currentCoeff = slanted;
            glTexGenfv(GL_S, currentPlane, currentCoeff);
            glutPostRedisplay();
            break;
        case 'x': case 'X':
            currentCoeff = xequalzero;
            glTexGenfv(GL_S, currentPlane, currentCoeff);
            glutPostRedisplay();
            break;
        case 'z': case 'Z':
            anglez = (anglez + 1) % 360;
            glutPostRedisplay();
            break;
        case 'y': case 'Y':
            angley = (angley + 1) % 360;
            glutPostRedisplay();
            break;
        case 'q': case 'Q':
            exit(0);
        default:
            break;
    }
}

//Builds a 1D texture

void makeStripeImage (void)
{
  int j;

  for (j = 0; j < stripeImageWidth; j++) {
    stripeImage[4 * j] = (GLubyte) ((j <= 4) ? 255 : 0);
    stripeImage[4 * j + 1] = (GLubyte) ((j > 4) ? 255 : 0);
    stripeImage[4 * j + 2] = (GLubyte) 0;
    stripeImage[4 * j + 2] = (GLubyte) 255;
  }
}

//Builds a 2D texture

/*
void buildTexture (void)
{
  GLubyte offset, i, j;

  for (i = 0; i < 8; i++) //load grey
    for (j = 0; j < 8; j++) {
      tex[i][j][0] = 127;
      tex[i][j][1] = 127;
      tex[i][j][2] = 127;
      tex[i][j][3] = 255;
	}
  for (i = 0; i < 4; i++) { //load red diagonal stripe
    for (j = 3; j < 5; j++) {
      offset = j - i;
      if (offset >= 0) {
        tex[i][offset][0] = 255;
        tex[i][offset][1] = 0;
        tex[i][offset][2] = 0;
        tex[i][offset][3] = 255;
	  }
	}
  }
  for (i = 0; i < 8; i++) { //load green diagonal stripe
    for (j = 7; j < 9; j++) {
      offset = j - i;
      if (offset < 8) {
        tex[i][offset][0] = 0;
        tex[i][offset][1] = 255;
        tex[i][offset][2] = 0;
        tex[i][offset][3] = 255;
	  }
	}
  }
  for (i = 4; i < 8; i++) { //load blue diagonal stripe
    for (j = 7; j < 9; j++) {
      offset = j - i + 4;
      if (offset < 8) {
        tex[i][offset][0] = 0;
        tex[i][offset][1] = 0;
        tex[i][offset][2] = 255;
        tex[i][offset][3] = 255;
	  }
	}
  }
}

*/
