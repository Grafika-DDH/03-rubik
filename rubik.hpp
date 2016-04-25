#ifndef _Rubick_H
#define _Rubick_H

#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>

void draw_cube();
void rotateTop();
void rotateBottom();
void rotateLeft();
void rotateRight();
void rotateFront();
void rotateBack();

void draw_cube(float angle, float viewX, float viewY, float viewZ, int rotation);

void draw_front_side_cube();
void draw_left_side_cube();
void draw_right_side_cube();
void draw_back_side_cube();
void draw_top_side_cube();
void draw_bottom_side_cube();


#endif
