#ifndef RUBIK_H_INCLUDED
#define RUBIK_H_INCLUDED

#include <GL/glut.h>



#endif // RUBIK_H_INCLUDED

#include "rubik.h"

GLfloat color[][3] = {
    {1.f, 1.f, 1.f}, // white
    {1.f, 0.5f, 0.f}, // orange
    {0.f, 0.f, 1.f}, // blue
    {0.f, 1.f, 0.f}, // green
    {1.f, 1.f, 0.f}, // yellow
    {1.f, 0.f, 0.f}, // red
    {0.5f, 0.5f, 0.5}, // grey (uncolored)
};

int
    top[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}},
    right[3][3] = {{1,1,1}, {1,1,1}, {1,1,1}},
    bottom[3][3] = {{2,2,2}, {2,2,2}, {2,2,2}},
    left[3][3] = {{3,3,3}, {3,3,3}, {3,3,3}},
    front[3][3] = {{4,4,4}, {4,4,4}, {4,4,4}},
    back[3][3] = {{5,5,5}, {5,5,5}, {5,5,5}};

void polygon(int idxColor, int a, int b, int c, int d){
    glColor3f(0, 0, 0);
    glLineWidth(3.f);
    glBegin(GL_LINE_LOOP);
    glVertex3fv(sisi[a]);
    glVertex3fv(sisi[b]);
    glVertex3fv(sisi[c]);
    glVertex3fv(sisi[c]);
    glEnd();

    glColor3fv(color[idxColor]);
    glBegin(GL_POLYGON);
    glVertex3fv(sisi[a]);
    glVertex3fv(sisi[b]);
    glVertex3fv(sisi[c]);
    glVertex3fv(sisi[c]);
    glEnd();
}

void draw_center(){
    polygon(6, 7, 6, 2, 3);
    polygon(6, 5, 1, 2, 6);
    polygon(6, 4, 5, 1, 0);
    polygon(6, 0, 4, 7, 3);
    polygon(6, 4, 5, 6, 7);
    polygon(6, 0, 1, 2, 3);
}

void draw_center_front(){

}

