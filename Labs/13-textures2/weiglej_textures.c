/************************************
 *         Textures Lab 2           *
 *           Lab 13                 *
 *  Author: Justin Weigle           *
 *  Edited: 30 Nov 2019             *
 ************************************/

Q1:
    Setting both EYE_LINEAR and x + y + z = 0 results in the original vertical
    magenta lines becoming curved. The curves are relative to the eye, or in
    other terms, it is perpendicular to the base of the window regardless of
    how the teapot oriented. This means that rotating the teapot, the curves
    do not move.

Q2:
    x = 0 results in the original image when running the program where the
    magenta lines on the teapot are all vertical no matter the orientation
    of the teapot. The lines do not move when the teapot moves, just as in
    q1.

Q3:
    This appears no different from q1 initially, but if the teapot is rotated,
    the curved lines stay relative to the teapot, not the eye/window. They move
    with the teapot.

Q4:
    This results in the lines staying perpendicular to the base of the teapot.
    Just like q3, the lines move with the teapot.


Q5:
    S coordinates seem to start a little bit higher and to the left in terms of
    it's center. S coordinates also has a longer transition between colors in
    the texture, which suggests that it repeats the texture less than T.
    Not just that, but it also appears as if S coordinates have a slight amount
    of overlap between the colors in the texture while T does not.

Q6:
    Very similar to q5, except it is now related to the object instead of the
    eye. Also, for both object and eye linear, for T the center is green, and
    for S the center is blue and red.

Q7:
    This is the same comparisons made in q5 and q6, but this time, the S coord
    one moves with the object, and the T coord one stays relative to the eye.

Q8:
    The difference between S and T is the same as Q 5-7, but with slant changed
    to xequalzero, instead of having a circular pattern, the texture follows
    a linear pattern up and slightly to the right.

Q9:
    Linear performs averaging of the four texture elements that are nearest it,
    and nearest just uses the value of the texture element that is nearest to
    the center of the pixel being textured. This results in nearest being a bit
    pixelated looking and linear being smoother but a bit blurry looking.

Q10:
    It appears as if there is no difference between linear and nearest.

Q11:
    This is simply the grass texture, but repeated 6 times.

Q12:

