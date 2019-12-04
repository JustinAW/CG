#ifndef DRAWFUNCTIONS_H
#define DRAWFUNCTIONS_H


void glMultiDrawElements (GLenum, const GLsizei *, GLenum, const GLvoid *, GLsizei);

GLfloat sq (GLdouble);

void normalize (GLdouble *);

void unit_square (void);

void unit_cube (void);

void inner_gear_surface (GLfloat, int);

void outer_gear_surface (GLfloat, int);

void gear_teeth_outline (int, int);

void unit_circle (GLfloat);

void x_unit_circle (GLfloat);

void x_disk_surface (GLfloat, GLfloat, GLfloat, GLfloat);

void z_disk_surface (GLfloat, GLfloat, GLfloat, GLfloat);

void intake_exhaust (void);

void chambers (void);

void rotor (void);

void eccentric_shaft (GLfloat, GLfloat);

void housing (void);

void spark_plug ();

void sparks (void);

void table (void);

void toolbox (void);

void overhead_light (void);

void flashlight (void);

#endif
