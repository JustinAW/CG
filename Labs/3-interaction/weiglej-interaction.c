Q1:
Resizing the window just resizes the square that is visible, it does not
make any of the other squares visible


Q2:
in main:
    glutInitWindowSize (100, 100);
    gluOrtho2D (0.0, (GLdouble) 100, 0.0, (GLdouble) 100);

Q3:
in reshape function:
    glViewport (0, 0, 100, 100);
    gluOrtho2D (0.0, (GLdouble) 100, 0.0, (GLdouble) 100);

Q4:
The square being displayed always retains its square shape and it always
keeps the whole image in view


Q5:
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

Q6:
Resizing the window does not affect the size or shape of the rendered image,
it only shows more or less of it

Q7:
in reshape function:
    glViewport(0, 0, w, h);
    ...
    gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);

Q8:

