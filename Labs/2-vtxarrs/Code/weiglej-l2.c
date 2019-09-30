
/********************************************************
 *            OpenGL Vertex Arrays Lab                  *
 *                      Lab 2                           *
 * Author: Justin Weigle                                *
 * Edited: 19 Sep, 2019                                 *
 * Submitted: 21 Sep, 2019                              *
 ********************************************************/

/*
 * Step 1
 */
void display (void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    static GLfloat vertices[] = {100.0, 150.0,  //0
                                100.0, 50.0,    //1
                                50.0, 50.0,     //2
                                50.0, 150.0,    //3
                                150.0, 50.0,    //4
                                150.0, 150.0,   //5
                                200.0, 150.0,   //6
                                200.0, 50.0,    //7
                                250.0, 50.0,    //8
                                250.0, 150.0    //9
                                };
    static GLfloat colors[] = {1.0, 1.0, 0.0,   //0
                                0.0, 1.0, 0.0,  //1
                                1.0, 0.0, 0.0,  //2
                                0.0, 0.0, 1.0,  //3
                                1.0, 0.0, 0.0,  //4
                                0.0, 0.0, 1.0,  //5
                                1.0, 1.0, 0.0,  //6
                                0.0, 1.0, 0.0,  //7
                                1.0, 0.0, 0.0,  //8
                                0.0, 0.0, 1.0   //9
                                };

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);

    glBegin(GL_POLYGON);
        for(int i = 0; i < 4; i++) {
            glArrayElement(i);
        }
    glEnd();
    glBegin(GL_POLYGON);
        glArrayElement(0);
        glArrayElement(1);
        glArrayElement(4);
        glArrayElement(5);
    glEnd();
    glBegin(GL_POLYGON);
        glArrayElement(6);
        glArrayElement(7);
        glArrayElement(4);
        glArrayElement(5);
    glEnd();
    glBegin(GL_POLYGON);
        glArrayElement(8);
        glArrayElement(9);
        glArrayElement(6);
        glArrayElement(7);
    glEnd();

    glFlush ();
}

/*
 * Step 2
 */
void display (void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    static GLfloat vertices[] = {100.0, 150.0,  //0
                                100.0, 50.0,    //1
                                50.0, 50.0,     //2
                                50.0, 150.0,    //3
                                150.0, 50.0,    //4
                                150.0, 150.0,   //5
                                200.0, 150.0,   //6
                                200.0, 50.0,    //7
                                250.0, 50.0,    //8
                                250.0, 150.0    //9
                                };
    static GLfloat colors[] = {1.0, 1.0, 0.0,   //0
                                0.0, 1.0, 0.0,  //1
                                1.0, 0.0, 0.0,  //2
                                0.0, 0.0, 1.0,  //3
                                1.0, 0.0, 0.0,  //4
                                0.0, 0.0, 1.0,  //5
                                1.0, 1.0, 0.0,  //6
                                0.0, 1.0, 0.0,  //7
                                1.0, 0.0, 0.0,  //8
                                0.0, 0.0, 1.0   //9
                                };

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);

    static GLubyte indices1[] = {0,1,2,3};
    static GLubyte indices2[] = {0,1,4,5};
    static GLubyte indices3[] = {6,7,4,5};
    static GLubyte indices4[] = {8,9,6,7};

    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, indices1);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, indices2);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, indices3);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, indices4);

    glFlush ();
}

/*
 * Step 3
 */
void display (void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    static GLfloat vertexValues[] = {
        100.0, 150.0, 0.0, 1.0, 1.0, 0.0,       //0
        100.0, 50.0, 0.0, 0.0, 1.0, 0.0,        //1
        50.0, 50.0, 0.0, 1.0, 0.0, 0.0,         //2
        50.0, 150.0, 0.0, 0.0, 0.0, 1.0,        //3
        150.0, 50.0, 0.0, 1.0, 0.0, 0.0,        //4
        150.0, 150.0, 0.0, 0.0, 0.0, 1.0,       //5
        200.0, 150.0, 0.0, 1.0, 1.0, 0.0,       //6
        200.0, 50.0, 0.0, 0.0, 1.0, 0.0,        //7
        250.0, 50.0, 0.0, 1.0, 0.0, 0.0,        //8
        250.0, 150.0, 0.0, 0.0, 0.0, 1.0        //9
        };

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 6*sizeof(GLfloat), &vertexValues[0]);
    glColorPointer(3, GL_FLOAT, 6*sizeof(GLfloat), &vertexValues[3]);

    static GLubyte indices1[] = {0,1,2,3};
    static GLubyte indices2[] = {0,1,4,5};
    static GLubyte indices3[] = {6,7,4,5};
    static GLubyte indices4[] = {8,9,6,7};

    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, indices1);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, indices2);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, indices3);
    glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, indices4);

    glFlush ();
}
