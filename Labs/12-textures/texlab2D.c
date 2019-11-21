

/********************************************************
 *                                                      *
 *                       texlab2d.c                     *
 *                                                      *
 ********************************************************/

/*
 * Tests 1S texturing
 */

#include <GL\glut.h>

void init (void);
void reshape (int, int);
void display (void);
void buildTexture (void);

GLubyte tex[8][8][4]; //Note: Could use 1D array, but easier to conceptualize as 
                      //2D array with 4 values per texel

void keyboard (unsigned char key, int x, int y)
{
    switch(key){
        case 27:
            exit(0);
            break;
        default:
            break;
    }
}


int main (int argc, char** argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize (800, 800);
    glutInitWindowPosition (0, 0);
    glutCreateWindow (argv[0]);
    glutReshapeFunc(reshape);
    init ();
    glutDisplayFunc (display);
    glutKeyboardFunc(keyboard);
    glutMainLoop ();
    return 0;
}

void init (void)
{
    glClearColor (1.0, 1.0, 1.0, 1.0);
    glShadeModel(GL_FLAT);
    buildTexture();
}

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

void display (void)
{
    glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLineWidth(3);
    glTexEnvi (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D (GL_TEXTURE_2D, 0, GL_RGBA, 8, 8, 0, GL_RGBA, GL_UNSIGNED_BYTE, tex); 
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

    glFlush ();
}

void buildTexture (void)
{
    GLubyte base, offset, i, j;

    for (i = 0; i < 8; i++) {//load grey
        for (j = 0; j < 8; j++) {
            tex[i][j][0] = 127;
            tex[i][j][1] = 127;
            tex[i][j][2] = 127;
            tex[i][j][3] = 255;
        }
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

