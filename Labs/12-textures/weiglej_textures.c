/************************************
 *         Textures Lab             *
 *           Lab 12                 *
 *  Author: Justin Weigle           *
 *  Edited: 27 Nov 2019             *
 ************************************/

Q1:
    It makes the line have 4 colors instead of just 2. Red, yellow, green, and
    cyan.

Q2:
    No longer using RGBA makes it so that the 4 colors defined in tex1 become 5
    colors + 1 value. Those are:
        {255,   0,   0,     // red
         255, 255,   0,     // yellow
           0, 255,   0,     // green
           0, 255, 255,     // cyan
           0,   0, 255,     // blue
           255}             // ??

Q3:
    The line becomes green-black-green.

Q4:
    Similar to Q2, this happens because tex1 is now viewed differently, it
    becomes a list of green values where the first 4 are used for the line
    which are 255, 0, 0, 255. 100% green, black, black, 100% green

Q5:
    The line becomes white-black-white. This is due to the values in tex being
    luminance (light) values. 255, 0, 0, 255 is now 100% light, dark, dark,
    100% light.

Q6:
    The white parts became grey. 200/255 = 0.784 = 78.4% light.

Q7:
    The line completely disappears / turns white

Q8:
    The line becomes red-blue-black.

Q9:
    This happens because the texture only has enough colors in it to texture
    up to a length of 4.

Q10:
    The line becomes red.

Q11:
    This happens because it is now only using 2 lines of tex1, and the first
    and second are both red.

Q12:
    The line becomes cyan-yellow.

Q13:
    This is the result of the formula used with GL_BLEND and the internal
    format being RGBA. The formula is:
        C = Cf(1 - Cs) + CcCs
        A = AfAs
    Therefore for the first and second line of tex1 the color is:
        // 255 simplified down to 1
        // Cf == (1,1,1) because default of white and no color set
        C = (1,1,1)((1,1,1) - (1,0,0)) + (0,0,0)(1,0,0)
          = (1,1,1)(0,1,1) + (0,0,0)
          = (0,1,1) + (0,0,0)
          = (0,1,1)
    and alpha:
        A = 1 * 1
          = 1
    and the third and fourth lines:
        C = (1,1,1)((1,1,1) - (0,0,1)) + (0,0,0)(0,0,1)
          = (1,1,1)(1,1,0) + (0,0,0)
          = (1,1,0) + (0,0,0)
          = (1,1,0)
    and alpha:
        A = 1 * 1
          = 1

Q14:
    Both result in the same image of red-blue

Q15:
    In scaling just the one dimension, it scales the texture down to fit all
    the colors in the space allotted, losing some of the quality in one
    dimension. In scaling both dimensions, it makes the quality go down in both
    directions. It pushes to the bottom left corner when scaling.

Q16:
    tex[0][0] is the lower left corner of the texture map.

Q17:
    tex[0][7] is the lower right corner.

Q18:
    glTexCoord2f(0.0, 1.0);
    glVertex2i(-3, -3);
    glTexCoord2f(1.0, 1.0);
    glVertex2i(3, -3);
    glTexCoord2f(1.0, 0.0);
    glVertex2i(3, 3);
    glTexCoord2f(0.0, 0.0);
    glVertex2i(-3, 3);

Q19:
    The texture is still mapped the entire width, and it is shrunk down to fit
    it vertically.

Q20:
    The texture is now mapped the entire width, but the height is mapped so it
    appears as if the image is still a square. Aka it's the original image, but
    with the top cut off.

Q21:
    This squishes the texture so that all of it is on the trapezoid, but it is
    quite distorted because it is a square texture.

Q22:
    It's about what I expected due to the texture being mapped to the corners
    of the trapezoid.

Q23:
    With the bottom left mapped to the bottom left and the bottom right mapped
    to the bottom right of the triangle, there's nothing unusual there. But
    with both the top left and top right of the texture mapped to the peak of
    the triangle, I kind of expected distortion, but it looks normal.

Q24:
    It depends what the desired result is, but I think the one with two coords
    mapped to the peak looked better.

Q25:
        GLdouble v[3];
        GLdouble theta;
        glBegin(GL_QUADS);
        for (int i = 0; i <= 360; i += 360 / SIDES)
        {
            theta = i * M_PI / 180;

            glTexCoord2f(i / (360 / SIDES) / SIDES, 1);

            v[0] = (sin(theta) * 3);
            v[1] = 3;
            v[2] = (cos(theta) * 3);
            glVertex3dv(v);

            glTexCoord2f(i / (360 / SIDES) / SIDES, 0);

            v[0] = (sin(theta) * 3);
            v[1] = -3;
            v[2] = (cos(theta) * 3);
            glVertex3dv(v);

            // Using quads instead of quad_strip, so coords must be repeated
            // to make a cylinder
            i += (360 / SIDES);
            theta = i * M_PI / 180;

            glTexCoord2f(i / (360 / SIDES) / SIDES, 0);

            v[0] = (sin(theta) * 3);
            v[1] = -3;
            v[2] = (cos(theta) * 3);
            glVertex3dv(v);

            glTexCoord2f(i / (360 / SIDES) / SIDES, 1);

            v[0] = (sin(theta) * 3);
            v[1] = 3;
            v[2] = (cos(theta) * 3);
            glVertex3dv(v);

            i -= (360 / SIDES);
        }

    /********************************************
     * If you want to make the texture mapped   *
     * like the glu quadric maps it, you can    *
     * modify the code to as follows:           *
     * (modifications labeled with comments)    *
     ********************************************/

        GLdouble v[3];
        GLdouble theta;
        glBegin(GL_QUADS);
        for (int i = 0; i <= 360; i += 360 / SIDES)
        {
            theta = i * M_PI / 180;

            // Coord2f(1 - ... , 1 was changed to 0);
            glTexCoord2f(1 - i / (360 / SIDES) / SIDES, 0);

            v[0] = (sin(theta) * 3);
            v[1] = 3;
            v[2] = (cos(theta) * 3);
            glVertex3dv(v);

            // Coord2f(1 - ... , 0 was changed to 1);
            glTexCoord2f(1 - i / (360 / SIDES) / SIDES, 1);

            v[0] = (sin(theta) * 3);
            v[1] = -3;
            v[2] = (cos(theta) * 3);
            glVertex3dv(v);

            i += (360 / SIDES);
            theta = i * M_PI / 180;

            // Coord2f(1 - ... , 0 was changed to 1);
            glTexCoord2f(1 - i / (360 / SIDES) / SIDES, 1);

            v[0] = (sin(theta) * 3);
            v[1] = -3;
            v[2] = (cos(theta) * 3);
            glVertex3dv(v);

            // Coord2f(1 - ... , 1 was changed to 0);
            glTexCoord2f(1 - i / (360 / SIDES) / SIDES, 0);

            v[0] = (sin(theta) * 3);
            v[1] = 3;
            v[2] = (cos(theta) * 3);
            glVertex3dv(v);

            i -= (360 / SIDES);
        }
