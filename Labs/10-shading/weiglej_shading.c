/************************************
 *         Shading Lab              *
 *           Lab 10                 *
 *  Author: Justin Weigle           *
 *  Edited: 10 Nov 2019             *
 ************************************/

Q2:
    It doesn't affect the image at all because the light angle by default is
    at 180, a special value which makes the light point in every direction.
    This includes the location of the sphere in relation to the light location
    when the light is initially local(positional).

Q3:
    This makes the sphere very dark blue. It is only lit by the global ambient
    light. It looks like a dark blue circle.

Q4:
    This makes the sphere look like a black circle because now there is no
    light on it at all.

Q5:
    This makes the sphere slightly shiny. It appears as if it has a more smooth
    textured surface.

Q7:
    The first one with surface normals did not show any sort of lighting, the
    one with vertex normals had lighting effects in the bottom left.

Q8:
    It doesn't appear to make a difference regardless of the exponent value.
    It is supposed to make the light more concentrated, but likely due to the
    small cutoff value provided, it doesn't matter if the exponent is high or
    low, it looks very similar / the same.

Q9:
    This initially makes the light disappear, but with increasing values for
    the cutoff, the light appears starting at the bottom left and works toward
    the top right.
