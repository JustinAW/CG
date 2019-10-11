
/********************************************************
 *                                                      *
 *                                                      *
 ********************************************************/


#include <GL/glut.h>
#include <time.h>
#include <stdio.h>

int Cycle = 0;
float Colors[3][3] = {{0.0, 1.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 1.0}};
float Red, Green, Blue;
long Time, ResetTime = 0;
float position = 0.0;
float increment = 0.5;
float speed = 1.0;


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
    glutPostRedisplay();
}

void idle (void)
{
    Time = clock();
    if (Time > ResetTime) 
    {
        ResetTime = ResetTime + increment * CLOCKS_PER_SEC;
        position += speed;
        glutPostRedisplay();
    }
}


void display (void)
{
    glClear (GL_COLOR_BUFFER_BIT);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    Red = Colors[Cycle][0];
    Green = Colors[Cycle][1];
    Blue = Colors[Cycle][2];
    glColor3f (Red, Green, Blue);
    glBegin (GL_POLYGON);
        glVertex2s (position, 0);
        glVertex2s (position+10, 0);
        glVertex2s (position+10, 42);
        glVertex2s (position, 42);
    glEnd ();

    glFlush ();
}

void mouse (int button, int state, int x, int y)
{
    switch(button)
    {
        case GLUT_LEFT_BUTTON:
            if(state == GLUT_DOWN)
            {
                printf("Speeding up\n");
                speed = 2.0;
            }
            break;
        case GLUT_RIGHT_BUTTON:
            if(state == GLUT_DOWN)
            {
                printf("Slowing back down\n");
                speed = 1.0;
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
    glutInitWindowSize (200, 200);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    glutIdleFunc(idle);
    init ();
    glutReshapeFunc (reshape);
    glutDisplayFunc (display);
    Time = clock();                 //initialize timer
    ResetTime = Time + 3 * CLOCKS_PER_SEC;
    glutMouseFunc (mouse);
    glutMainLoop ();
    return 0;
}
