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

