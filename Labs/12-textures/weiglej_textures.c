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

