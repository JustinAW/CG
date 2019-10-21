/************************************
 *         Viewing Lab              *
 *          Lab 7                   *
 *  Author: Justin Weigle           *
 *  Edited: 21 Oct 2019             *
 *  Submitted: 21 Oct 2019          *
 ************************************/

Q1:
    Part of the arrow is displayed, or to be exact, half. I set the x to 20.

Q2:
    None of the arrow is displayed, using x 40, 80 and y 40, 80.

Q3:
    The window is displayed in the upper left hand corner

Q4:
    When the window initialized is greater than the width of the screen, it
    automatically reduces itself to be the width of the screen. This happens
    with width of 1930, 1960, and any number greater than 1920 when the
    width of the screen's resolution is 1920.

Q5:
    0,0 of the window is in the bottom left corner. The corner of the viewport
    mapped to this location is the bottom left corner.

Q6:
    This distorts the image by squashing/stretching.

Q7:
    for (int i = 0; i < 4; i++)
    {
        glViewport(i*100, 0, 100, 100);
        arrow();
    }

Q8:
    First is normal, the second is facing up and to the left, third is 
    facing down and to the right, fourth is facing down and to the left.

Q9:
    for (int j = 0; j < 4; j++)
    {
        for (int k = 0; k < 4; k++)
        {
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            if ((j + k) % 2 == 0)
            {
                gluOrtho2D(0.0, 40.0, 0.0, 40.0);
            }
            else
                gluOrtho2D(40.0, 0.0, 0.0, 40.0);

            glViewport(j*100, k*100, 100, 100);

            for (i = 0; i < nPolys; i++)
                regPoly(rInit + i * rInc, 20, 20, i * offset);
        }
    }
