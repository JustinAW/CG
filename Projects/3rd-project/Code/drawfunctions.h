#ifndef DRAWFUNCTIONS_H
#define DRAWFUNCTIONS_H

void glMultiDrawElements (GLenum, const GLsizei *, GLenum, const GLvoid *, GLsizei);

void inner_gear_outline (GLfloat);

void outer_gear_outline (GLfloat);

void gear_teeth_outline (int, GLfloat);

void unit_circle (GLfloat);

void x_unit_circle (GLfloat);

void z_disk_surface (GLfloat, GLfloat, GLfloat);

void x_disk_surface (GLfloat, GLfloat, GLfloat, GLfloat);

void intake_exhaust (void);

void chambers (void);

void rotor (void);

void housing (void);

void spark_plug ();

void sparks (void);

#endif
