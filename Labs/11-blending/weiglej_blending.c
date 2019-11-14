/************************************
 *         Blending Lab             *
 *           Lab 11                 *
 *  Author: Justin Weigle           *
 *  Edited: 14 Nov 2019             *
 ************************************/

Q1:
    Yes, this changes the color in the center because the square on top
    will be the prevalent color yet will allow some of the color of the square
    behind to blend with it.

Q2:
    Green and red overlapping make a kind of brown color.
    Red and blue overlapping make a pinkish color.
    Blue and green overlapping make a teal/turquoise color.

Q3:
    All 3 overlapping make a purplish color.

Q4:
    It makes sense to me according to the order they were drawn in. With
    certain colors on top of the others, the ones on top will have more
    prevalence when blending them.

Q5:
    No, the green square being opaque while depth buffering is on appears to
    have interfered with the opacity of the red and blue squares, specifically
    where they overlap with one another, but not with the green square.

Q6:
    Only making the depth buffer read only after the opaque(green) square does
    not resolve the issue. However, the issue can be resolved by the following
    steps -
    1. Draw opaque objects
    2. Set depth buffer to read only (glDepthMask(GL_FALSE);)
    3. Enable blending
    4. Draw translucent objects
    5. Set depth buffer back to writeable (glDepthMask(GL_TRUE);)

Q7:
    It's significantly less noticeable with antialiasing on.

Q8:
    There's no notable difference other than the lines are less transparent.

Q9:
    To be honest regular antialiasing looks better to me. Multisampling has
    more of a hazy look along the edges where regular antialiasing looks a
    little more sharp.

Q10:
    No, but there's a possibility that it would look better on a larger scale.
