#include <GL/glut.h>
#include <math.h>

const int SIDES = 360;

void gear (void)
{
    glBegin(GL_LINE_LOOP);
        double heading;
        int counter = 0;
        int toggle = 1;
        for (int i = 0; i < 360; i += 360 / SIDES)
        {
            heading = i * 3.1415926535897932384626433832795 / 180;
            if (toggle)
                glVertex2d(cos(heading), sin(heading));
            else
                glVertex2d(cos(heading) * 0.9, sin(heading) * 0.9);

            counter += 1;
            if (counter == 10)
            {
                counter = 0;
                if (toggle == 1)
                    toggle = 0;
                else
                    toggle = 1;
            }
        }
    glEnd();
}


void unit_circle (void)
{
    glBegin(GL_LINE_LOOP);
        double heading;
        for (int i = 0; i < 360; i += 360 / SIDES)
        {
            heading = i * 3.1415926535897932384626433832795 / 180;
            glVertex2d(cos(heading), sin(heading));
        }
    glEnd();
}


void slider (void)
{
}
