/************************************
 *       Picking Lab                *
 *          Lab 4                   *
 *  Author: Justin Weigle           *
 *  Edited: 05 Oct 2019             *
 *  Submitted: 05 Oct 2019          *
 ************************************/


Q1:
    No, it doesn't change the window coordinates that the viewport is at 
    because the origin for the mouse is at the upper left and the viewport
    stays attached to the bottom left.
Q2:
    Similar to Q1, but this is because the image is tied to the bottom left,
    so it follows the window when it is expanded.
Q3:
    Yes, it keeps the viewport tied to the bottom left corner, but the mouse
    coordinates follow along with the expansion of the top left corner.
Q4:
    Yes, it moves the viewport down since it is tied to the bottom left, but 
    the mouse coordinates remain tied to the top of the window


Q5:
    No, changing the width to be wider leaves the height of the viewport in
    tact, and therefore does not affect the coordinates, same as Q1.
Q6:
    Again no, similar to Q5 and Q2, this does not change the coordinates on the
    x axis because both viewport and mouse coordinate are tied to the left and
    the height did not change, therefore the viewport remained the same size.
Q7:
    Yes. This is the same answer as Q3 because the viewport does not move
Q8:
    Yes. This is the same answer as Q4 because the viewport moves down too


Q9:
    GLint viewport[4];
    GLdouble mvmatrix[16], projmatrix[16];
    GLint ry, wh;
    GLdouble wx, wy, wz;

    if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)) {
        glGetIntegerv(GL_VIEWPORT, viewport);
        glGetDoublev(GL_MODELVIEW_MATRIX, mvmatrix);
        glGetDoublev(GL_PROJECTION_MATRIX, projmatrix);
        wh = glutGet(GLUT_WINDOW_HEIGHT);

        ry = wh - (GLint) y;
        gluUnProject((GLdouble) x, (GLdouble) ry, 0.0, 
                mvmatrix, projmatrix, viewport, &wx, &wy, &wz);

        if (x1 < wx && wx < x2 && y1 < wy && wy < y2)
        {
            printf("red rectangle clicked\n");
        }
        if (a1 < wx && wx < a2 && b1 < wy && wy < b2)
        {
            printf("blue rectangle clicked\n");
        }
    }


Q10:
    struct {
        GLfloat pixel[4];
        char * name;
    }squares[3];

    void mouse (int button, int state, GLint x, GLint y)
    {
        ...

        if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)) {
            glReadPixels(x, y, 1.0, 1.0, GL_RGBA, GL_FLOAT, &pixel);
            r = pixel[0]; g = pixel[1]; b = pixel[2];

            for(int sq = 0; sq < 3; sq++)
            {
                if (squares[sq].pixel[0] == r
                    && squares[sq].pixel[1] == g
                    && squares[sq].pixel[2] == b)
                {
                    printf("Name of clicked square: %s\n", squares[sq].name);
                }
            }
        }
    }

    int main (int argc, char** argv)
    {
        ...

        squares[0].pixel[0] = 0.0;
        squares[0].pixel[1] = 1.0;
        squares[0].pixel[2] = 0.0;
        squares[0].name = "Charlie";

        squares[1].pixel[0] = 0.0;
        squares[1].pixel[1] = 0.0;
        squares[1].pixel[2] = 1.0;
        squares[1].name = "Dexter";

        ...
    }
