

/********************************************************
 *                                                      *
 *                       wheel.c                        *
 *                                                      *
 ********************************************************/

/* Instance modeling lab: Robot from unit square.
   Right way to do it.
*/

#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

long Time, ResetTime = 0;
float SPEED = -1.0;
float FPS = 30.0;
const int sides = 360;
int RUN_ANIMATION = 0;

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);
}

void unitCircle (void)
{
    glBegin(GL_LINE_LOOP);
        double heading;
        int counter = 0;
        int toggle = 1;
        for (int i = 0; i < 360; i += 360 / sides)
        {
            heading = i * 3.1415926535897932384626433832795 / 180;
            if (toggle)
            {
                glVertex2d(cos(heading), sin(heading));
            }
            else
            {
                glVertex2d(cos(heading) * 0.9, sin(heading) * 0.9);
            }

            //glVertex2d(cos(heading) * radius, sin(heading) * radius);
            counter += 1;
            if (counter == 10)
            {
                counter = 0;
                if (toggle == 1)
                {
                    toggle = 0;
                }
                else
                {
                    toggle = 1;
                }
            }
        }
    glEnd();
}

void drawSpoke (void)
{
    glBegin(GL_LINES);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0, 1.0);
    glEnd();
}

void drawSpokes()
{
    for (float i = 0; i < 360; i += 45)
    {
        glPushMatrix();
            glRotatef(i, 0.0, 0.0, 1.0);
            glTranslatef(0.0, 1.0, 0.0);
            glScalef(1.0, 7.0, 0.0);
            drawSpoke();
        glPopMatrix();
    }
}

void drawCircles()
{
    glPushMatrix();
        glScalef(10.0, 10.0, 1.0);
        unitCircle();
    glPopMatrix();
    glPushMatrix();
        glScalef(8.0, 8.0, 1.0);
        unitCircle();
    glPopMatrix();
    glPushMatrix();
        glScalef(1.0, 1.0, 1.0);
        unitCircle();
    glPopMatrix();
}

void drawWheel ()
{
    drawCircles();
//    drawSpokes();
}

void reshape (int w, int h)
{
	if (w > h)
	  glViewport (0, 0, (GLsizei) h, (GLsizei) h);
	else
	  glViewport (0, 0, (GLsizei) w, (GLsizei) w);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D (0.0, 50.0, 0.0, 50.0);
}

void display (void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity ();
	glColor3f(1.0, 0.0, 0.0);
    glTranslatef(22.0, 22.0, 0.0);
    glScalef(2.0, 2.0, 1.0);
    glLineWidth(2.0);
    drawWheel();
	glFlush ();
}

void idle (void)
{
    if (RUN_ANIMATION == 1)
    {
        Time = clock();
        if (Time > ResetTime)
        {
            ResetTime = ResetTime + (1.0/FPS) * CLOCKS_PER_SEC;
            glClear (GL_COLOR_BUFFER_BIT);
            glRotatef(SPEED, 0.0, 0.0, 1.0);
            drawWheel();
            glFlush();
        }
    }
}

void menu_choice (int selection)
{
    if (selection == 1)
    {
        exit(0);
    }
}

void toggle_animation (int selection)
{
    if (selection == 1)
    {
        RUN_ANIMATION = 1;
    }
    if (selection == 2)
    {
        RUN_ANIMATION = 0;
    }
}

int main (int argc, char** argv)
{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize (400, 400);
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]);
	glutReshapeFunc(reshape);
	init ();

    int submenu = glutCreateMenu(toggle_animation);
    glutAddMenuEntry("Start Animation", 1);
    glutAddMenuEntry("Stop Animation", 2);

    glutCreateMenu(menu_choice);
    glutAddSubMenu("Toggle Animation", submenu);
    glutAddMenuEntry("Exit", 1);
    glutAttachMenu (GLUT_RIGHT_BUTTON);

    glutIdleFunc (idle);
	glutDisplayFunc (display);
	glutMainLoop ();
	return 0;
}
