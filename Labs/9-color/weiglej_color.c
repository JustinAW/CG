/************************************
 *          Color Lab               *
 *           Lab 9                  *
 *  Author: Justin Weigle           *
 *  Edited: 25 Oct 2019             *
 *  Submitted: 25 Oct 2019          *
 ************************************/

Q1:
    If a negative value is given, it is treated as a 0

Q2:
    The color is determined by the color set before the first vertex.

Q3:
    The color is determined by the color set before the last vertex.

Q4:
    GL_TRIANGLE_STRIP: The color of the initial triangle is determined by the
        last color set before the third vertex, and the second triangle's color
        is determined by the color set before the fourth vertex.
    GL_TRIANGLE_FAN: This works the same way as TRIANGLE_STRIP

Q5:
    The last vertex declared determines the color.

Q6:
    No, because it doesn't apply to polygons. The first vertex controls the
    color of a polygon.

Q7:
    QUADS and QUAD_STRIPs follow the same rule as TRIANGLES.

Q8:
    Smooth shading works the same regardless if it is a polygon or another
    primitive.
