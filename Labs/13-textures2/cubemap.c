/**************************************************************
 *                                                            *
 *                        cubemap.c                           *
 *                                                            *
 *  Uses SOIL to load textures.                               *
 *                                                            *
 **************************************************************/


#include <stdio.h>
#include "SOIL/SOIL.h"
#include <GL/glut.h>
#include <math.h>

void init (void);
void reshape (int, int);
void display (void);
void keyboard (unsigned char, int, int);

static GLfloat CAM_X = 0;
static GLfloat CAM_Y = 0;
static GLfloat CAM_Z = 15;
static GLfloat ZOOM = 1;
static GLfloat CAM_ANGLE_X = 0;
static GLfloat CAM_ANGLE_Y = 0;

GLuint tex;

/**************************************************************
 *                            main                            *
 **************************************************************/
int main (int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(argv[0]);
    init();

    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return (0);
}


/**************************************************************
 *                            init                            *
 **************************************************************/
void init (void)
{
    glLoadIdentity();

    glClearColor (1.0, 1.0, 1.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_NORMALIZE);

//    tex = SOIL_load_OGL_texture("Bitmaps/sphere-256x256.bmp", 4, 0,
//            SOIL_FLAG_MIPMAPS);
//    if (!tex) {
//        printf("***NO BITMAP RETRIEVED***\n");
//        exit(1);
//    }
    tex = SOIL_load_OGL_cubemap
    (
        "Bitmaps/grass64.bmp",
        "Bitmaps/pattern1-64.bmp",
        "Bitmaps/grass64.bmp",
        "Bitmaps/pattern1-64.bmp",
        "Bitmaps/grass64.bmp",
        "Bitmaps/pattern1-64.bmp",
        SOIL_LOAD_RGBA,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS
    );
    glBindTexture(GL_TEXTURE_2D, tex);

    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
            GL_LINEAR_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

    glLoadIdentity();
}

/**************************************************************
 *                           reshape                          *
 **************************************************************/
void reshape (int w, int h)
{
    glLoadIdentity ();
    if ( w > h)
        glViewport (0, 0, (GLfloat) h, (GLfloat) h);
    else
        glViewport (0, 0, (GLfloat) w, (GLfloat) w);

    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective(75, 1, 5, 1000000000);

    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity ();
}

/**************************************************************
 *                           display                          *
 **************************************************************/
void display (void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glBindTexture(GL_TEXTURE_2D, tex);
    glPushMatrix();
        gluLookAt(CAM_X, CAM_Y, CAM_Z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
        glRotatef(CAM_ANGLE_X, 0, 1, 0);
        glRotatef(CAM_ANGLE_Y, 1, 0, 0);

        GLUquadricObj *q = gluNewQuadric();
        gluQuadricDrawStyle(q, GLU_FILL);
        gluQuadricOrientation(q, GLU_OUTSIDE);
        gluQuadricNormals(q, GLU_FLAT);
        gluQuadricTexture(q, GL_TRUE);
        gluSphere(q, 3, 10, 10);
        gluDeleteQuadric(q);
    glPopMatrix();

    glutSwapBuffers();
}


GLfloat sq (GLdouble x)
{
    return x * x;
}
GLfloat get_magnitude_cam (void)
{
     return sqrt(sq(CAM_X) + sq(CAM_Y) + sq(CAM_Z));
}
/**************************************************************
 *                          keyboard                          *
 **************************************************************/
void keyboard (unsigned char key, int x, int y)
{
    GLfloat m = get_magnitude_cam();
    switch(key){
        case 'f': case 27:
            exit(0);
            break;
        // ZOOM IN
        case 'E': case 'e':
            if ((CAM_X == 0.0) && (CAM_Y == 0.0) && (CAM_Z == 0.0))
            {
                printf("Full zoom, zoom out... if you want to\n");
                glutPostRedisplay();
                break;
            }
            CAM_X -= (CAM_X / m) * ZOOM;
            CAM_Y -= (CAM_Y / m) * ZOOM;
            CAM_Z -= (CAM_Z / m) * ZOOM;
            glutPostRedisplay();
            break;
        // ZOOM OUT
        case 'Q': case 'q':
            if ((CAM_X == 0.0) && (CAM_Y == 0.0) && (CAM_Z == 0.0))
            {
                CAM_X = 0.0;
                CAM_Y = 0.0;
                CAM_Z = 50.0;
                glutPostRedisplay();
                break;
            }
            CAM_X += (CAM_X / m) * ZOOM;
            CAM_Y += (CAM_Y / m) * ZOOM;
            CAM_Z += (CAM_Z / m) * ZOOM;
            glutPostRedisplay();
            break;
        // ROTATE CAMERA LEFT
        case 'A': case 'a':
            CAM_ANGLE_X += 5;
            if (CAM_ANGLE_X >= 360)
                CAM_ANGLE_X = 0;
            glutPostRedisplay();
            break;
        // ROTATE CAMERA RIGHT
        case 'D': case 'd':
            CAM_ANGLE_X -= 5;
            if (CAM_ANGLE_X <= 0)
                CAM_ANGLE_X = 360;
            glutPostRedisplay();
            break;
        // ROTATE CAMERA AROUND X CLOCKWISE
        case 'W': case 'w':
            CAM_ANGLE_Y += 5;
            if(CAM_ANGLE_Y >= 360)
                CAM_ANGLE_Y = 0;
            glutPostRedisplay();
            break;
        // ROTATE CAMERA AROUND X COUNTER CLOCKWISE
        case 'S': case 's':
            CAM_ANGLE_Y -= 5;
            if (CAM_ANGLE_Y <= 0)
                CAM_ANGLE_Y = 360;
            glutPostRedisplay();
            break;
        default:
            break;
    }
}
