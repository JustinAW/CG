/**************************************************************
 *                                                            *
 *                     tex-lab2-zoom.c                        *
 *                     Texture Filters                        *
 *                                                            *
 *                                                            *
 **************************************************************/


#include <stdio.h>
#include "SOIL/SOIL.h"
#include <GL/glut.h>

void init (void);
void reshape (int, int);
void display (void);
void keyboard (unsigned char inKey, int x, int y);
void draw_info (void);

static int        width;       // Width of window 
static int        height;      // Height of window 
static GLuint     tex;        // Bitmap data

static GLint CAMERA_Z = 40.0;

static int MINIFYING_MODE = 0;
static int FILTER_MODE = 0;

static void *font = GLUT_BITMAP_HELVETICA_18;

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

    tex = SOIL_load_OGL_texture("Bitmaps/grass64.bmp", 4, 0, SOIL_FLAG_POWER_OF_TWO);
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
    glLoadIdentity();
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glLoadIdentity();
}

/**************************************************************
 *                          reshape                           *
 **************************************************************/
void reshape (int w, int h)
{
    if ( w > h)
        glViewport(0, 0, (GLfloat) h, (GLfloat) h);
    else
        glViewport(0, 0, (GLfloat) w, (GLfloat) w);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 10000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
}


void mode_swap (void)
{
    if (MINIFYING_MODE == 0) {
        if (FILTER_MODE == 0)
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        else
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    }
    else {
        if (FILTER_MODE == 0)
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        else
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    }
}


/**************************************************************
 *                          keyboard                          *
 **************************************************************/
void keyboard (unsigned char key, int x, int y)
{
    switch (key) {
        case 'q': case 'Q':
            CAMERA_Z++;
            glutPostRedisplay();
            break;
        case 'e': case 'E':
            CAMERA_Z--;
            glutPostRedisplay();
            break;
        case 'z': case 'Z':
            MINIFYING_MODE = 1 - MINIFYING_MODE;
            mode_swap();
            glutPostRedisplay();
            break;
        case 'x': case 'X':
            FILTER_MODE = 1 - FILTER_MODE;
            mode_swap();
            glutPostRedisplay();
            break;
        case 27:
            exit(0);
        default:
            break;
    }
}

	
/**************************************************************
 *                           display                          *
 **************************************************************/
void display (void)
{
    glPushMatrix();
        gluLookAt(0.0, 0.0, CAMERA_Z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        draw_info();
        //NOTE: No need to call glTexImage2D since SOIL_load_OGL_texture()
        //      loads the image directly into texture memory
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
    glPopMatrix();
    glutSwapBuffers();
}


void render_bitmap_string (GLfloat x, GLfloat y, void *font, const char *string)
{
    const char *c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}


void draw_info (void)
{
    glDisable(GL_TEXTURE_2D);

    glColor3f(0, 0, 0);
    GLfloat x = 0;
    GLfloat y = 5;

    if (MINIFYING_MODE == 0) {
        render_bitmap_string(x, y, font, "NEAREST");
    }
    if (MINIFYING_MODE == 1) {
        render_bitmap_string(x, y, font, "LINEAR");
    }

    if (FILTER_MODE == 0) {
        render_bitmap_string(x, y-10, font, "MAG");
    }
    if (FILTER_MODE == 1) {
        render_bitmap_string(x, y-10, font, "MIN");
    }
    glEnable(GL_TEXTURE_2D);
}
