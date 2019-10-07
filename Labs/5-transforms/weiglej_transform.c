/************************************
 *      Transforms Lab              *
 *          Lab 5                   *
 *  Author: Justin Weigle           *
 *  Edited: 06 Oct 2019             *
 *  Submitted: 06 Oct 2019          *
 ************************************/

Q1:
    Translate appears first
Q2:
    Translate is applied first
Q3:
    No, the triangle appears in the center with the translate first and at the
    side with rotate first. This is due to the fact that when translated first,
    the triangle starts the rotation out to the right where it was translated
    to. But when it is rotated first, it translates upwards.
Q4:
    No, scaling first leads to the triangle being moved farther. Translating
    first and then scaling moves the triangle the expected amount and then
    scales it.
Q5:
    No, scaling first makes it rotate farther
Q6:
    Same as Q5, scaling first makes it rotate farther


Q7:
    All
Q8:
    All
Q9:
    All

Q10:
    Everything between the push and pop call only affected the green triangle
Q11:
    Red - only the scale, Green - everything, Blue - only the scale
Q12:
    OpenGL keeps a stack of matrices to apply and remove transformations.
    glPushMatrix copies the top matrix and pushes it onto the stack.
    glPopMatrix pops the top matrix off of the stack. All transformation
    functions operate on the top matrix, and rendering commands use the top
    matrix to transform data.
    So in the context of this code, glPushMatrix puts a non-transformed matrix,
    matrix 1, on top of the stack. Then the two translates are applied to 
    that matrix and therefore applied to the green triangle. After that,
    glPopMatrix is called which pops(deletes) matrix 1 off the stack leaving
    the matrix on top, matrix 0, to have the scale applied to.


Q13:
    The calls to glLoadIdentity(); change the matrix on top to the identity
    matrix, which prevents the translate from having any effect


Q14:
    void drawCap()
    {
        glPushMatrix();
            glScalef(2.0, 2.0, 1.0);
            unitTriangle();
        glPopMatrix();
    }

    void drawBody()
    {
        glPushMatrix();
            glTranslatef(5.0, 5.0, 0.0);    //move base over and up a bit
            glPushMatrix();
                glScalef(20.0, 2.0, 1.0);
                unitSquare();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(2.0, 2.0, 0.0);    //next tier translate from base
                glPushMatrix();
                    glScalef(16.0, 2.0, 1.0);
                    unitSquare();
                glPopMatrix();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(4.0, 4.0, 0.0);    // next tier
                glPushMatrix();
                    glScalef(12.0, 2.0, 1.0);
                    unitSquare();
                glPopMatrix();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(6.0, 6.0, 0.0);    // next tier
                glPushMatrix();
                    glScalef(8.0, 2.0, 1.0);
                    unitSquare();
                glPopMatrix();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(8.0, 8.0, 0.0);    // next tier
                glPushMatrix();
                    glScalef(4.0, 2.0, 1.0);
                    unitSquare();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
    }

    void drawPyramid ()
    {
        glPushMatrix();
            glTranslatef(14.0, 15.0, 0.0);
            drawCap();
        glPopMatrix();
        drawBody();
    }

Q15:

    const int sides = 40;

    void unitCircle (void)
    {
        glBegin(GL_LINE_LOOP);
            double heading;
            for (int i = 0; i < 360; i += 360 / sides)
            {
                heading = i * 3.1415926535897932384626433832795 / 180;
                glVertex2d(cos(heading), sin(heading));
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
        drawSpokes();
    }

    void display (void)
    {
        ...
        glColor3f(1.0, 0.0, 0.0);
        glTranslatef(11.0, 11.0, 0.0);
        drawWheel();
        glFlush();
    }
