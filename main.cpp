//
// This code was created by Jeff Molofee '99 (ported to Linux/GLUT by Richard Campbell '99)
//
// If you've found this code useful, please let me know.
//
// Visit me at www.demonews.com/hosted/nehe
// (email Richard Campbell at ulmont@bellsouth.net)
//
#include <GL/glut.h>    // Header File For The GLUT Library
#include <GL/gl.h>	// Header File For The OpenGL32 Library
#include <GL/glu.h>	// Header File For The GLu32 Library
#include <unistd.h>     // Header File For sleeping.

/* ASCII code for the escape key. */
#define ESCAPE 27

/* The number of our GLUT window */
int window;
float angle = 0;

/* rotation angle for the triangle. */
float rtri = 0.0f;

/* rotation angle for the quadrilateral. */
float rquad = 0.0f;

typedef struct {
    float x, y, z;
} Vertex3D;

typedef struct {
    float r, g, b;
} Color3;

/* A general OpenGL initialization function.  Sets all of the initial parameters. */
void InitGL(int Width, int Height)	        // We call this right after our OpenGL window is created.
{
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);		// This Will Clear The Background Color To Black
  glClearDepth(1.0);				// Enables Clearing Of The Depth Buffer
  glDepthFunc(GL_LESS);				// The Type Of Depth Test To Do
  glEnable(GL_DEPTH_TEST);			// Enables Depth Testing
  glShadeModel(GL_SMOOTH);			// Enables Smooth Color Shading

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();				// Reset The Projection Matrix

  gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);	// Calculate The Aspect Ratio Of The Window

  glMatrixMode(GL_MODELVIEW);
}

void drawBoxAtPoint(float x, float y, float z) {
    glTranslatef(x,y,z);

    glColor3f(0.5f,0.5f,1.0f);
    glBegin(GL_QUADS);
    glVertex3f(-1.0f, 1.0f, 0.0f);
    glVertex3f( 1.0f, 1.0f, 0.0f);
    glVertex3f( 1.0f,-1.0f, 0.0f);
    glVertex3f(-1.0f,-1.0f, 0.0f);
    glEnd();

    glTranslatef(-x,-y,-z);
}

void drawSquare3d(Vertex3D vertex[4], Color3 color) {
    glBegin(GL_TRIANGLE_STRIP);

    glColor3f(color.r, color.g, color.b);

    for(int i = 0; i < 4; ++i)
        glVertex3f(vertex[i].x, vertex[i].y, vertex[i].z);

    glEnd();
}

void drawCubeAtPoint(float x, float y, float z) {
    float max = 1.0f;
    float min = -max;
    glTranslatef(x,y,z);

    Vertex3D vertexSide1[4] = {
        { min, min, max },
        { max, min, max },
        { min, max, max },
        { max, max, max }
    };

    Vertex3D vertexSide2[4] = {
        { min, min, min },
        { max, min, min },
        { min, max, min },
        { max, max, min }
    };

    Vertex3D vertexSide3[4] = {
        { min, min, min },
        { min, max, min },
        { min, min, max },
        { min, max, max }
    };

    Vertex3D vertexSide4[4] = {
        { max, min, min },
        { max, max, min },
        { max, min, max },
        { max, max, max }
    };

    Vertex3D vertexSide5[4] = {
        { min, min, min },
        { min, min, max },
        { max, min, min },
        { max, min, max }
    };

    Vertex3D vertexSide6[4] = {
        { min, max, min },
        { min, max, max },
        { max, max, min },
        { max, max, max }
    };

    Color3 color1 = {0.5, 0, 0};
    Color3 color2 = {0, 0.5, 0};
    Color3 color3 = {0, 0, 0.5};

    drawSquare3d(vertexSide1, color1);
    drawSquare3d(vertexSide2, color1);
    drawSquare3d(vertexSide3, color2);
    drawSquare3d(vertexSide4, color2);
    drawSquare3d(vertexSide5, color3);
    drawSquare3d(vertexSide6, color3);

    glTranslatef(-x,-y,-z);
}

/* The function called when our window is resized (which shouldn't happen, because we're fullscreen) */
void ReSizeGLScene(int Width, int Height)
{
  if (Height==0)				// Prevent A Divide By Zero If The Window Is Too Small
    Height=1;

  glViewport(0, 0, Width, Height);		// Reset The Current Viewport And Perspective Transformation

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);
  glMatrixMode(GL_MODELVIEW);
}

/* The main drawing function. */
void DrawGLScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear The Screen And The Depth Buffer
    glLoadIdentity();				// Reset The View

    gluLookAt(7, 7, 7,
              5, 5, 3,
              0, 1, 0);

    glTranslatef(0.0f, 0.0f, -8.2f);
    glRotatef(angle, 0.f, 1.f, 0.f);
    glTranslatef(0.0f, 0.0f, 8.2f);

    float z = -6.0f;

    drawCubeAtPoint(-2.2f, 2.2f, z);
    drawCubeAtPoint(-2.2f, 0.f, z);
    drawCubeAtPoint(-2.2f, -2.2f, z);
    drawCubeAtPoint(0.f, 2.2f, z);
    drawCubeAtPoint(0.f, 0.f, z);
    drawCubeAtPoint(0.f, -2.2f, z);
    drawCubeAtPoint(2.2f, 2.2f, z);
    drawCubeAtPoint(2.2f, 0.f, z);
    drawCubeAtPoint(2.2f, -2.2f, z);

    z -= 2.2f;

    drawCubeAtPoint(-2.2f, 2.2f, z);
    drawCubeAtPoint(-2.2f, 0.f, z);
    drawCubeAtPoint(-2.2f, -2.2f, z);
    drawCubeAtPoint(0.f, 2.2f, z);
    drawCubeAtPoint(0.f, 0.f, z);
    drawCubeAtPoint(0.f, -2.2f, z);
    drawCubeAtPoint(2.2f, 2.2f, z);
    drawCubeAtPoint(2.2f, 0.f, z);
    drawCubeAtPoint(2.2f, -2.2f, z);

    z -= 2.2f;

    drawCubeAtPoint(-2.2f, 2.2f, z);
    drawCubeAtPoint(-2.2f, 0.f, z);
    drawCubeAtPoint(-2.2f, -2.2f, z);
    drawCubeAtPoint(0.f, 2.2f, z);
    drawCubeAtPoint(0.f, 0.f, z);
    drawCubeAtPoint(0.f, -2.2f, z);
    drawCubeAtPoint(2.2f, 2.2f, z);
    drawCubeAtPoint(2.2f, 0.f, z);
    drawCubeAtPoint(2.2f, -2.2f, z);

    // swap the buffers to display, since double buffering is used.
    glutSwapBuffers();
}

/* The function called whenever a key is pressed. */
void keyPressed(unsigned char key, int x, int y)
{
    /* sleep to avoid thrashing this procedure */
    usleep(100);

    /* If escape is pressed, kill everything. */
    if (key == ESCAPE)
    {
        /* shut down our window */
        glutDestroyWindow(window);

        /* exit the program...normal termination. */
        exit(0);
    } else if(key == 'p') {
        int goal = 90;
        int degree_per_frame = 5;
        int frame = goal / degree_per_frame;
        for(int i = 0; i < frame; i++) {
          angle += 1;
          DrawGLScene();
        }
    } else if(key == 'o') {
        int goal = 90;
        int degree_per_frame = 5;
        int frame = goal / degree_per_frame;
        for(int i = 0; i < frame; i++) {
          angle -= 1;
          DrawGLScene();
        }
    }
}

int main(int argc, char **argv)
{
  /* Initialize GLUT state - glut will take any command line arguments that pertain to it or
     X Windows - look at its documentation at http://reality.sgi.com/mjk/spec3/spec3.html */
  glutInit(&argc, argv);

  /* Select type of Display mode:
     Double buffer
     RGBA color
     Alpha components supported
     Depth buffer */
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);

  /* get a 640 x 480 window */
  glutInitWindowSize(640, 480);

  /* the window starts at the upper left corner of the screen */
  glutInitWindowPosition(0, 0);

  /* Open a window */
  window = glutCreateWindow("Jeff Molofee's GL Code Tutorial ... NeHe '99");

  /* Register the function to do all our OpenGL drawing. */
  glutDisplayFunc(&DrawGLScene);
  /* Even if there are no events, redraw our gl scene. */
  glutIdleFunc(&DrawGLScene);

  /* Register the function called when our window is resized. */
  glutReshapeFunc(&ReSizeGLScene);

  /* Register the function called when the keyboard is pressed. */
  glutKeyboardFunc(&keyPressed);

  /* Initialize our window. */
  InitGL(640, 480);

  /* Start Event Processing Engine */
  glutMainLoop();

  return 1;
}
