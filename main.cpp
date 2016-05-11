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

float rotateSpeed = 0.5f;

float viewX = 0.f, viewY = 0.f, viewZ = 0.f;
float t_x, t_y;

float theta = 0.f;
bool isKeyPressed = false;
int rotation = 0;
int complete = 0;
float angle = 0.f;

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

    draw_cube(angle, viewX, viewY, viewZ, rotation);

    glutSwapBuffers();
}


void rotate_cube()
{
    if (!isKeyPressed)
        return;

    angle += 0.005 + rotateSpeed;
    while (angle >= 360.f)
        angle -= 360.f;

    if (angle < 90.f) {
        glutPostRedisplay();
        return;
    }

    complete = 1;
    glutIdleFunc(NULL);

    switch (rotation)
    {
        case 1:
            rotateTop();
            break;
        case 3:
            rotateLeft();
            break;
        case 4:
            rotateRight();
            break;
        case 2:
            rotateBottom();
            break;
        case 5:
            rotateFront();
            break;
        case 6:
            rotateBack();
            break;
    }

    rotation = 0;
    angle = 0;
    isKeyPressed = false;

    glutPostRedisplay();
}

static void key(unsigned char key, int x, int y)
{
    if (isKeyPressed)
        return;

    isKeyPressed = true;

    glutPostRedisplay();
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;
        case 'w':
        case 'W':
            rotation = 1;
            break;
        case 'a':
        case 'A':
            rotation = 3;
            break;
        case 'd':
        case 'D':
            rotation = 4;
            break;
        case 's':
        case 'S':
            rotation = 2;
            break;
        case 'f':
        case 'F':
            rotation = 5;
            break;
        case 'b':
        case 'B':
            rotation = 6;
            break;
    }

    complete = 0;
    glutIdleFunc(rotate_cube);
}

void InitializeLight() {
    // Lighting set up
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// Set lighting intensity and color
	GLfloat qaAmbientLight[]	= {0.2, 0.2, 0.2, 1.0};
	GLfloat qaDiffuseLight[]	= {0.8, 0.8, 0.8, 1.0};
	GLfloat qaSpecularLight[]	= {1.0, 1.0, 1.0, 1.0};
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);

	// Set the light position
	GLfloat qaLightPosition[]	= {.5, .5, 0.0, 1.0};
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);
}

/* Program entry point */

int main(int argc, char *argv[])
{

    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");
    InitializeLight();

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(rotate_cube);
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
