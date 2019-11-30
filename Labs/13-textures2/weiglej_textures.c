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
    The grass texture is repeated 6 times, but each time it is mirrored, where
    the bottom is a mirror of the top. It is also mirrored across from one side
    to the other such that the second one is a mirror of the first horizontally
    and the third one is a mirror of the second one horizontally.

Q13:
    The grass texture is only whole in the bottom left corner, above and to the
    right is just lines of various colors from the palette of the texture. The
    upper right side is just a dark green, also a color from the texture.

Q14:
    This looks almost the same as the image for q13, but the whole texture in
    the bottom left looks slightly more zoomed out and the lines are a bit
    different as well.

Q15:
    This is like q14's image, however there are no lines and no color anywhere
    besides the bottom left corner where the texture is whole.

Q16:
    This is similar to q14 but much brighter colors from the texture for the
    lines and upper right corner.

Q17:
  4 This is the same as q14, but the lines are a lot sharper and the texture is
    sharper as well (more pixelated, no pixel averaging (interpolation)). Not
    only that, but it also used brighter colors similear to how q16 did.

  5 This is like q15, but rather than being smooth / slightly blurry, it is
    sharp / pixelated due to the lack of pixel averaging (interpolation)

  6 This is like q16, but similar to the other answers for this question, the
    lines are a lot sharper looking and the texture itself is more pixelated
    with the lack of interpolation.

Q18:
    Any time the texture is not set to go to the edge, the border is generated
    with the border color set. There is one exception, when nearest is used
    GL_CLAMP, the texture color is still used instead of the border color.
    Otherwise, the images produced are all the same as the ones from q14-q17

Q19:

