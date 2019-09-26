/*
 *
 */

// Q1
/*
 * Resizing the window just resizes the square that is visible, it does not
 * make any of the other squares visible
 */

// Q2
//in main
    glutInitWindowSize (100, 100);
    gluOrtho2D (0.0, (GLdouble) 100, 0.0, (GLdouble) 100);

//Q3
//in reshape function
    glViewport (0, 0, 100, 100);
    gluOrtho2D (0.0, (GLdouble) 100, 0.0, (GLdouble) 100);

//Q4

