#include <GL/glut.h>
#include "showinfo.h"

const void *header = GLUT_BITMAP_TIMES_ROMAN_24;
const void *font = GLUT_BITMAP_HELVETICA_18;

void render_bitmap_string (GLfloat x, GLfloat y, void *font, const char *string)
{
    const char *c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

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
                "This shaft sends the power generated to the flywheel"
        );
    }
}
