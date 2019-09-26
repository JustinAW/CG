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
/*
 * The image being displayed always retains its square shape, but it doesn't
 * necessarily stay in the window depending on how resizing is done.
 * Resizing the window to be wider without making it taller allows the viewport
 * to extend out of the window. Resizing the window to be thinner makes the 
 * viewport smaller.  Resizing to be taller but not wider keeps the viewport 
 * the same size. Resizing to be shorter makes the viewport smaller.
 */

//Q5

