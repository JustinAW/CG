/************************************
 *      Projection Lab              *
 *          Lab 6                   *
 *  Author: Justin Weigle           *
 *  Edited: 17 Oct 2019             *
 *  Submitted: 17 Oct 2019          *
 ************************************/

Q2:
    The image gets smaller each added distance, but it is less distorted. This
    is due to the fact that the camera is getting farther away from the pillar.
    As the camera gets farther, the fact that we can see the entire pillar at
    any distance becomes less and less impactful on the perceived vertical fov.

Q4:
    The values I used were -6.0, 6.0, -6.0, 6.0
 
Q5:
    This image appears much more realistic than the images from Q2. It is not
    nearly as distorted and the wire sphere on top shows more detail.

Q7:
    The only thing visible is the center of the pillar. The second one, where
    the camera is 100 units from the origin, makes the pillar appear closer
    even though the near clip plane is still the same distance from the pillar.

Q9:
    fov: 8.55 aspect: 1.0

Q10:
    The image doesn't change at all.

Q11:
    Parallel viewing does not have a viewing angle that changes how much of
    the image you see from different distances and it does not distort the
    image as you get closer to it. Perspective views have a viewing angle that
    can potentially distort the image as you get closer and closer to it.

Q12:
    It has no effect.

Q14:
    glRotatef (-45.0, 0.0, 1.0, 0.0);
    glTranslatef (-50.0, -46.0, -50.0);
