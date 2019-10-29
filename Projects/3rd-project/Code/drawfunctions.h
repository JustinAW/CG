#ifndef DRAWFUNCTIONS_H
#define DRAWFUNCTIONS_H

void glMultiDrawElements (GLenum, const GLsizei *, GLenum, const GLvoid *, GLsizei);

void inner_gear (int);

void inner_gear_outline (void);

void outer_gear (int);

void outer_gear_outline (void);

void gear_teeth_outline (int);

void unit_circle (int, int);

void unit_circle_fill (int, int);

void intake_exhaust (void);

void chambers (void);

void rotor (void);

void eccentric_shaft (void);

void eccentric_shaft_fill (int);

void housing (void);

void spark_plug (int);

void sparks (void);

#endif
