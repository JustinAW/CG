/****************************************************
 *                 showinfo.c                       *
 ****************************************************
 *  Author:     Justin Weigle                       *
 *  Edited:     20 Oct 2019                         *
 ****************************************************
 * Contains the information and functionality to    *
 * draw the information about the Wankel rotary     *
 * engine to the screen                             *
 ****************************************************/

#include <GL/glut.h>
#include "showinfo.h"

const void *header = GLUT_BITMAP_TIMES_ROMAN_24;
const void *font = GLUT_BITMAP_HELVETICA_18;

/****************************************************
 *              render_bitmap_string                *
 ****************************************************
 * Renders a given string to the screen at the      *
 * provided x,y coordinates                         *
 ****************************************************/
void render_bitmap_string (GLfloat x, GLfloat y, void *font, const char *string)
{
    const char *c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}


/****************************************************
 *                   draw_info                      *
 ****************************************************
 * Using the selection, draws information about the *
 * various parts of the Wankel engine               *
 ****************************************************/
void draw_info (GLint selection)
{
    if (selection == 0) return;

    GLfloat x = 350;
    GLfloat y = 800;

    if (selection == 1)
    {
        render_bitmap_string(x, y, (void *)header, "INTAKE:");
        render_bitmap_string(x, y-30, (void *)font, 
                "The opening through which fuel and air is admitted."
        );
    }

    if (selection == 2)
    {
        render_bitmap_string(x, y, (void *)header, "EXHAUST:");
        render_bitmap_string(x, y-30, (void *)font,
                "The opening through which burned gases are expelled."
        );
    }

    if (selection == 3)
    {
        render_bitmap_string(x, y, (void *)header, "CHAMBER:");
        render_bitmap_string(x, y-30, (void *)font,
                "1 of 3 moving combustion chambers."
        );
    }

    if (selection == 4)
    {
        render_bitmap_string(x, y, (void *)header, "ROTOR:");
        render_bitmap_string(x, y-30, (void *)font,
                "Similar to a Reuleaux triangle, this is what turns the eccentric"
        );
        render_bitmap_string(x, y-50, (void *)font,
                "shaft in the Wankel engine and creates power."
        );
    }

    if (selection == 5)
    {
        render_bitmap_string(x, y, (void *)header, "ECCENTRIC SHAFT:");
        render_bitmap_string(x, y-30, (void *)font,
                "The equivalent to a crankshaft in a piston engine."
        );
        render_bitmap_string(x, y-50, (void *)font,
                "This shaft sends the power generated to the flywheel."
        );
    }

    if (selection == 6)
    {
        render_bitmap_string(x, y, (void *)header, "PINION:");
        render_bitmap_string(x, y-30, (void *)font,
                "A stationary gear that the crown gear rides on."
        );
    }

    if (selection == 7)
    {
        render_bitmap_string(x, y, (void *)header, "CROWN GEAR:");
        render_bitmap_string(x, y-30, (void *)font,
                "This gear, guided by the pinion, is what ensures that the"
        );
        render_bitmap_string(x, y-50, (void *)font,
                "rotor turns exactly 1/3 of a turn for each turn of the"
        );
        render_bitmap_string(x, y-70, (void *)font,
                "eccentric shaft."
        );
    }

    if (selection == 8)
    {
        render_bitmap_string(x, y, (void *)header, "STATOR HOUSING:");
        render_bitmap_string(x, y-30, (void *)font,
                "The stationary epitrochoid-shaped housing that allows the"
        );
        render_bitmap_string(x, y-50, (void *)font,
                "intake->compression->ignition->exhaust cycle to take place."
        );
    }

    if (selection == 9)
    {
        render_bitmap_string(x, y, (void *)header, "SPARK PLUG:");
        render_bitmap_string(x, y-30, (void *)font,
                "Creates an spark that ignites the compressed fuel."
        );
    }
}
