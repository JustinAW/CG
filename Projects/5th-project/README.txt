Justin Weigle
CG Project 5
Wankel Rotary Engine

MIPMAPPING has been applied using SOIL's automatic mipmapping at texture load
time.
Very noticeable when looking at the environment map applied to the barrel.

CAMERA CONTROLS have been implemented using the keyboard rather than the menu.
Camera controls are as follows:
    A/a -> Rotate camera left / clockwise around the Y axis
    D/d -> Rotate camera right / counter clockwise around the Y axis
    W/w -> Rotate camera clockwise around X axis
    S/s -> Rotate camera counter clockwise around X axis

    E/e -> Zoom in
    Q/q -> Zoom out

SPOTLIGHT CONTROLS have also been implemented using the keyboard.
Spotlight controls are as follows:
    UP_ARROW    -> Move spotlight up
    DOWN_ARROW  -> Move spotlight down
    LEFT_ARROW  -> Move spotlight left
    RIGHT_ARROW -> Move spotlight right

MAKEFILE FUNCTIONALITY
    make            -compiles (outputs executable named "rotary")
    make run        -compiles and runs
    make clean      -deletes executable
