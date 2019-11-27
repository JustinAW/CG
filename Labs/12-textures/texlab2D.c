/********************************************************
 *                                                      *
 *                       texlab2d.c                     *
 *                                                      *
 ********************************************************/

#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

void init (void);
void reshape (int, int);
void display (void);
void buildTexture (void);
void keyboard (unsigned char, int, int);

static GLfloat CAM_X = 0;
static GLfloat CAM_Y = 0;
static GLfloat CAM_Z = 15;
static GLfloat ZOOM = 1;
static GLfloat CAM_ANGLE_X = 0;
static GLfloat CAM_ANGLE_Y = 0;

static GLfloat SIDES = 20;

static GLfloat light_position[] = {0, 0, 100, 1.0};
static GLfloat light_direction[] = {0, 0, -1};

GLubyte tex[8][8][4]; //Note: Could use 1D array but easier to conceptualize as
                      //2D array with 4 values per texel

int main (int argc, char** argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize (800, 800);
    glutInitWindowPosition (0, 0);
    glutCreateWindow (argv[0]);
    init ();

    glutReshapeFunc(reshape);
    glutDisplayFunc (display);
    glutKeyboardFunc(keyboard);
    glutMainLoop ();
    return 0;
}

void init (void)
{
    glLoadIdentity();

    buildTexture();
    glEnable(GL_TEXTURE_2D);

    glClearColor (0.0, 0.0, 0.0, 1.0);
    glShadeModel(GL_FLAT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_DEPTH_TEST);

    GLfloat global_ambient[] = {0.2, 0.2, 0.2, 1.0};
    GLfloat light_ambient[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_specular[] = {0.2, 0.2, 0.2, 1.0};

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
}

void reshape (int w, int h)
{
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

void display (void)
{
    glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLineWidth(3);

    glPushMatrix();
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 8, 8, 0, GL_RGBA,
                GL_UNSIGNED_BYTE, tex);

        glLightfv(GL_LIGHT0, GL_POSITION, light_position);
        glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light_direction);

        gluLookAt(CAM_X, CAM_Y, CAM_Z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
        glRotatef(CAM_ANGLE_X, 0, 1, 0);
        glRotatef(CAM_ANGLE_Y, 1, 0, 0);

        GLUquadricObj *q = gluNewQuadric();
        gluQuadricDrawStyle(q, GLU_FILL);
        gluQuadricOrientation(q, GLU_OUTSIDE);
        gluQuadricNormals(q, GLU_FLAT);
        gluQuadricTexture(q, GL_TRUE);
        gluCylinder(q, 3, 3, 6, 20, 20);
        gluDeleteQuadric(q);
    glPopMatrix();

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


GLfloat sq (GLdouble x)
{
    return x * x;
}


GLfloat get_magnitude_cam (void)
{
     return sqrt(sq(CAM_X) + sq(CAM_Y) + sq(CAM_Z));
}


void keyboard (unsigned char key, int x, int y)
{
    GLfloat m = get_magnitude_cam();
    switch(key){
        case 'f':
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
