/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "rubik.hpp"

/* GLUT callback Handlers */

float rotateSpeed = 2.f;

float viewX = 0.f, viewY = 0.f, viewZ = 0.f;
float t_x, t_y;

typedef struct Point {
    GLfloat x;
    GLfloat y;
    GLfloat z;
} Point;

typedef struct Color {
    int x;
    int y;
    int z;
} Color;

typedef struct Cell {
    Color color;
    Point position;
} Cell;

void generateCell(){

}

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}


void motion(int x, int y) {
    viewY += x - t_x;
    viewX += y - t_y;
    t_x = x;
    t_y = y;
    glutPostRedisplay();
}

void mouse_drag(int btn, int state, int x, int y) {
    t_x = x;
    t_y = y;
}


static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(10, 10, 10,
              4, 3, 3,
              0, 1, 0);

    draw_cube(viewX, viewY, viewZ);

    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;
        case 'w':
        case 'W':
            rotateTop();
            break;
        case 'a':
        case 'A':
            rotateLeft();
            break;
        case 'd':
        case 'D':
            rotateRight();
            break;
        case 's':
        case 'S':
            rotateBottom();
            break;
        case 'f':
        case 'F':
            rotateFront();
            break;
        case 'b':
        case 'B':
            rotateBack();
            break;
    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

/* Program entry point */

int main(int argc, char *argv[])
{

    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);
    glutMouseFunc(mouse_drag);
    glutMotionFunc(motion);

    //glEnable(GL_CULL_FACE);
    //glCullFace(GL_FRONT);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);

    glutMainLoop();

    return EXIT_SUCCESS;
}
