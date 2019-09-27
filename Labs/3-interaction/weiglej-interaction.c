/************************************
 *      Interaction Lab             *
 *          Lab 3                   *
 *  Author: Justin Weigle           *
 *  Edited: 26 Sep 2019             *
 *  Submitted: 26 Sep 2019          *
 ************************************/


________________Q1_________________
Resizing the window just resizes the square that is visible, it does not
make any of the other squares visible


________________Q2_________________
in main:
    glutInitWindowSize (100, 100);
    gluOrtho2D (0.0, (GLdouble) 100, 0.0, (GLdouble) 100);


________________Q3_________________
in reshape function:
    glViewport (0, 0, 100, 100);
    gluOrtho2D (0.0, (GLdouble) 100, 0.0, (GLdouble) 100);


________________Q4_________________
The square being displayed always retains its square shape and it always
keeps the whole image in view


________________Q5_________________
in reshape function:
    if (w > h)
    {
        glViewport(0, 0, (GLfloat)h, (GLfloat)h/2);
    }
    else
    {
        glViewport(0, 0, (GLfloat)w, (GLfloat)w/2);
    }
    ...
    gluOrtho2D (0.0, (GLdouble)200, 0.0, (GLdouble)100);


________________Q6_________________
Resizing the window does not affect the size or shape of the rendered image,
it only shows more or less of it


________________Q7_________________
in reshape function:
    glViewport(0, 0, w, h);
    ...
    gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);


________________Q8_________________
in main:
    glutMouseFunc (mouse);

mouse function:
void mouse (int button, int state, int x, int y)
{
    switch(button)
    {
        case GLUT_LEFT_BUTTON:
            if(state == GLUT_DOWN)
            {
                check_squares(x, y);
                glutPostRedisplay();
            }
            break;
        default:
            break;
    }
}

check_squares function:
    void check_squares (int x, int y)
    {
        if(X1 < x && x < (X1 + W) && (400 - Y1 - W) < y && y < (400 - Y1))
        {
            printf("Red:\n");
            printf("x: %d - y: %d\n", x, y);
            R1 = BGR;
            G1 = BGG;
            B1 = BGB;
        }
        if(X2 < x && x < (X2 + W) && (400 - Y2 - W) < y && y < (400 - Y2))
        {
            printf("Green:\n");
            printf("x: %d - y: %d\n", x, y);
            R2 = BGR;
            G2 = BGG;
            B2 = BGB;
        }
        if(X3 < x && x < (X3 + W) && (400 - Y3 - W) < y && y < (400 - Y3))
        {
            printf("Blue:\n");
            printf("x: %d - y: %d\n", x, y);
            R3 = BGR;
            G3 = BGG;
            B3 = BGB;
        }
    }


________________Q9_________________
in main:
    glutKeyboardFunc (keyboard);

keyboard function:
    void keyboard (unsigned char key, int x, int y)
    {
        switch(key)
        {
            case 'e':
                check_squares(x, y);
                glutPostRedisplay();
                break;
            case 'E':
                check_squares(x, y);
                glutPostRedisplay();
                break;
            default:
                break;
        }
    }


________________Q10________________
in main:
    int submenu = glutCreateMenu(color_choice);
    glutAddMenuEntry("Red", 1);
    glutAddMenuEntry("Green", 2);
    glutAddMenuEntry("Blue", 3);

    glutCreateMenu(choice);
    glutAddMenuEntry("EXIT", 1);
    glutAddSubMenu("Change Color", submenu);
    glutAttachMenu (GLUT_RIGHT_BUTTON);

void choice (int selection)
{
    if (selection == 1)
    {
        exit(0);
    }
}

void color_choice (int selection)
{
    if (selection == 1)
    {
        Red = 1.0, Green = 0.0, Blue = 0.0;
    }
    if (selection == 2)
    {
        Red = 0.0, Green = 1.0, Blue = 0.0;
    }
    if (selection == 3)
    {
        Red = 0.0, Green = 0.0, Blue = 1.0;
    }
    glutPostRedisplay();
}


________________Q11________________
initialized defaults for both versions:
float position = 0.0
float interval = 0.5;
float speed = 1.0;

polygon settings for both versions:
glBegin (GL_POLYGON);
    glVertex2s (position, 0);
    glVertex2s (position+10, 0);
    glVertex2s (position+10, 42);
    glVertex2s (position, 42);
glEnd();

idle function for both versions:
void idle (void)
{
  Time = clock();
  if (Time > ResetTime) {
    ResetTime = ResetTime + interval * CLOCKS_PER_SEC;
    position += speed;
    glutPostRedisplay();
  }
}

mouse functions:
    interval variance version:
    void mouse (int button, int state, int x, int y)
    {
        switch(button)
        {
            case GLUT_LEFT_BUTTON:
                if(state == GLUT_DOWN)
                {
                    printf("Speeding up\n");
                    interval = 0.25;
                }
                break;
            default:
                break;
        }
    }

    speed variance version:
    interval = 0.25; changed to speed = 2.0;


________________Q12________________
Decreasing the interval at which the position is updated provides for a 
smoother animation.


________________Q13________________
Animating using the interval gives the advantage of smoother animation
because things can move in smaller increments. Animating using different
increments of speed just ends up making things look like they're teleporting
across the screen when you get to higher increments. So the only real advantage
to increment adjustment would be lower processing power because there are less
updates occuring to change the position.
