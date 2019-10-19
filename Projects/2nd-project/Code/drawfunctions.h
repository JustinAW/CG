#ifndef DRAWFUNCTIONS_H
#define DRAWFUNCTIONS_H

void glMultiDrawElements (GLenum, const GLsizei *, GLenum, const GLvoid *, GLsizei);

void gear (void);

void unit_circle (int, int);

void unit_circle_fill (int, int);

void slider (GLint, int);

void intake_exhaust (void);

void chambers (void);

void rotor (void);

void eccentric_shaft (void);

void eccentric_shaft_fill (int);

void housing (int);

#endif
