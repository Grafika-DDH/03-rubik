#include "rubik.hpp"

GLfloat sisi[][3] = {
    // center front
    {-1.f,1.f,-3.f},
    {1.f,1.f,-3.f},
    {1.f,-1.f,-3.f},
    {-1.f,-1.f,-3.f},

    // center right front
    {1.f,1.f,-3.f},
    {3.f,1.f,-3.f},
    {3.f,-1.f,-3.f},
    {1.f,-1.f,-3.f},

    // center left front
    {-3.f,1.f,-3.f},
    {-1.f,1.f,-3.f},
    {-1.f,-1.f,-3.f},
    {-3.f,-1.f,-3.f},

    // center top front
    {-1.f,3.f,-3.f},
    {1.f,3.f,-3.f},
    {1.f,1.f,-3.f},
    {-1.f,1.f,-3.f},

    // center bottom front
    {-1.f,-1.f,-3.f},
    {1.f,-1.f,-3.f},
    {1.f,-3.f,-3.f},
    {-1.f,-3.f,-3.f},

    // top left front
    {-3.f,3.f,-3.f},
    {-1.f,3.f,-3.f},
    {-1.f,1.f,-3.f},
    {-3.f,1.f,-3.f},

    // top right front
    {1.f,3.f,-3.f},
    {3.f,3.f,-3.f},
    {3.f,1.f,-3.f},
    {1.f,1.f,-3.f},

    // bottom right front
    {1.f,-1.f,-3.f},
    {3.f,-1.f,-3.f},
    {3.f,-3.f,-3.f},
    {1.f,-3.f,-3.f},

    // bottom left front
    {-3.f,-1.f,-3.f},
    {-1.f,-1.f,-3.f},
    {-1.f,-3.f,-3.f},
    {-3.f,-3.f,-3.f},

    ////////////////////////////////////

    // center right
    {3.f,1.f,-1.f},
    {3.f,1.f,1.f},
    {3.f,-1.f,1.f},
    {3.f,-1.f,-1.f},

    // center right right
    {3.f,1.f,1.f},
    {3.f,1.f,3.f},
    {3.f,-1.f,3.f},
    {3.f,-1.f,1.f},

    // center left right
    {3.f,1.f,-3.f},
    {3.f,1.f,-1.f},
    {3.f,-1.f,-1.f},
    {3.f,-1.f,-3.f},

    // center top right
    {3.f,3.f,-1.f},
    {3.f,3.f,1.f},
    {3.f,1.f,1.f},
    {3.f,1.f,-1.f},

    // center bottom right
    {3.f,-1.f,-1.f},
    {3.f,-1.f,1.f},
    {3.f,-3.f,1.f},
    {3.f,-3.f,-1.f},

    // top right right
    {3.f,3.f,1.f},
    {3.f,3.f,3.f},
    {3.f,1.f,3.f},
    {3.f,1.f,1.f},

    // top left right
    {3.f,3.f,-3.f},
    {3.f,3.f,-1.f},
    {3.f,1.f,-1.f},
    {3.f,1.f,-3.f},

    // bottom left right
    {3.f,-1.f,-3.f},
    {3.f,-1.f,-1.f},
    {3.f,-3.f,-1.f},
    {3.f,-3.f,-3.f},

    // bottom roght right
    {3.f,-1.f,1.f},
    {3.f,-1.f,3.f},
    {3.f,-3.f,3.f},
    {3.f,-3.f,1.f},

    /////////////////////////////////

    // center left
    {-3.f,1.f,-1.f},
    {-3.f,1.f,1.f},
    {-3.f,-1.f,1.f},
    {-3.f,-1.f,-1.f},

    // center right left
    {-3.f,1.f,1.f},
    {-3.f,1.f,3.f},
    {-3.f,-1.f,3.f},
    {-3.f,-1.f,1.f},

    // center left left
    {-3.f,1.f,-3.f},
    {-3.f,1.f,-1.f},
    {-3.f,-1.f,-1.f},
    {-3.f,-1.f,-3.f},

    // center top left
    {-3.f,3.f,-1.f},
    {-3.f,3.f,1.f},
    {-3.f,1.f,1.f},
    {-3.f,1.f,-1.f},

    // center bottom left
    {-3.f,-1.f,-1.f},
    {-3.f,-1.f,1.f},
    {-3.f,-3.f,1.f},
    {-3.f,-3.f,-1.f},

    // top right left
    {-3.f,3.f,1.f},
    {-3.f,3.f,3.f},
    {-3.f,1.f,3.f},
    {-3.f,1.f,1.f},

    // top left left
    {-3.f,3.f,-3.f},
    {-3.f,3.f,-1.f},
    {-3.f,1.f,-1.f},
    {-3.f,1.f,-3.f},

    // bottom left left
    {-3.f,-1.f,-3.f},
    {-3.f,-1.f,-1.f},
    {-3.f,-3.f,-1.f},
    {-3.f,-3.f,-3.f},

    // bottom right left
    {-3.f,-1.f,1.f},
    {-3.f,-1.f,3.f},
    {-3.f,-3.f,3.f},
    {-3.f,-3.f,1.f},

    /////////////////////////////

    // center back
    {-1.f,1.f,3.f},
    {1.f,1.f,3.f},
    {1.f,-1.f,3.f},
    {-1.f,-1.f,3.f},

    // center right back
    {1.f,1.f,3.f},
    {3.f,1.f,3.f},
    {3.f,-1.f,3.f},
    {1.f,-1.f,3.f},

    // center left back
    {-3.f,1.f,3.f},
    {-1.f,1.f,3.f},
    {-1.f,-1.f,3.f},
    {-3.f,-1.f,3.f},

    // center top back
    {-1.f,3.f,3.f},
    {1.f,3.f,3.f},
    {1.f,1.f,3.f},
    {-1.f,1.f,3.f},

    // center bottom back
    {-1.f,-1.f,3.f},
    {1.f,-1.f,3.f},
    {1.f,-3.f,3.f},
    {-1.f,-3.f,3.f},

    // top left back
    {-3.f,3.f,3.f},
    {-1.f,3.f,3.f},
    {-1.f,1.f,3.f},
    {-3.f,1.f,3.f},

    // top right back
    {1.f,3.f,3.f},
    {3.f,3.f,3.f},
    {3.f,1.f,3.f},
    {1.f,1.f,3.f},

    // bottom right back
    {1.f,-1.f,3.f},
    {3.f,-1.f,3.f},
    {3.f,-3.f,3.f},
    {1.f,-3.f,3.f},

    // bottom left back
    {-3.f,-1.f,3.f},
    {-1.f,-1.f,3.f},
    {-1.f,-3.f,3.f},
    {-3.f,-3.f,3.f},

    ////////////////////////////

    // center top
    {-1.f,3.f,1.f},
    {1.f,3.f,1.f},
    {1.f,3.f,-1.f},
    {-1.f,3.f,-1.f},

    // center right top
    {1.f,3.f,1.f},
    {3.f,3.f,1.f},
    {3.f,3.f,-1.f},
    {1.f,3.f,-1.f},

    // center left top
    {-3.f,3.f,1.f},
    {-1.f,3.f,1.f},
    {-1.f,3.f,-1.f},
    {-3.f,3.f,-1.f},

    // center top top
    {-1.f,3.f,3.f},
    {1.f,3.f,3.f},
    {1.f,3.f,1.f},
    {-1.f,3.f,1.f},

    // center bottom top
    {-1.f,3.f,-1.f},
    {1.f,3.f,-1.f},
    {1.f,3.f,-3.f},
    {-1.f,3.f,-3.f},

    // top left top
    {-3.f,3.f,3.f},
    {-1.f,3.f,3.f},
    {-1.f,3.f,1.f},
    {-3.f,3.f,1.f},

    // top right top
    {1.f,3.f,3.f},
    {3.f,3.f,3.f},
    {3.f,3.f,1.f},
    {1.f,3.f,1.f},

    // bottom right top
    {1.f,3.f,-1.f},
    {3.f,3.f,-1.f},
    {3.f,3.f,-3.f},
    {1.f,3.f,-3.f},

    // bottom left top
    {-3.f,3.f,-1.f},
    {-1.f,3.f,-1.f},
    {-1.f,3.f,-3.f},
    {-3.f,3.f,-3.f},

    /////////////////////////

    // center top
    {-1.f,-3.f,1.f},
    {1.f,-3.f,1.f},
    {1.f,-3.f,-1.f},
    {-1.f,-3.f,-1.f},

    // center right top
    {1.f,-3.f,1.f},
    {3.f,-3.f,1.f},
    {3.f,-3.f,-1.f},
    {1.f,-3.f,-1.f},

    // center left top
    {-3.f,-3.f,1.f},
    {-1.f,-3.f,1.f},
    {-1.f,-3.f,-1.f},
    {-3.f,-3.f,-1.f},

    // center top top
    {-1.f,-3.f,3.f},
    {1.f,-3.f,3.f},
    {1.f,-3.f,1.f},
    {-1.f,-3.f,1.f},

    // center bottom top
    {-1.f,-3.f,-1.f},
    {1.f,-3.f,-1.f},
    {1.f,-3.f,-3.f},
    {-1.f,-3.f,-3.f},

    // top left top
    {-3.f,-3.f,3.f},
    {-1.f,-3.f,3.f},
    {-1.f,-3.f,1.f},
    {-3.f,-3.f,1.f},

    // top right top
    {1.f,-3.f,3.f},
    {3.f,-3.f,3.f},
    {3.f,-3.f,1.f},
    {1.f,-3.f,1.f},

    // bottom right top
    {1.f,-3.f,-1.f},
    {3.f,-3.f,-1.f},
    {3.f,-3.f,-3.f},
    {1.f,-3.f,-3.f},

    // bottom left top
    {-3.f,-3.f,-1.f},
    {-1.f,-3.f,-1.f},
    {-1.f,-3.f,-3.f},
    {-3.f,-3.f,-3.f},
};

GLfloat color[][3] = {
    {1.f, 1.f, 1.f}, // white
    {1.f, 0.5f, 0.f}, // orange
    {0.f, 0.f, 1.f}, // blue
    {0.f, 1.f, 0.f}, // green
    {1.f, 1.f, 0.f}, // yellow
    {1.f, 0.f, 0.f}, // red
};

void polygon(int indexColor, int a, int b, int c, int d) {
    glColor3f(0, 0, 0);
    glLineWidth(3.f);
    glBegin(GL_LINE_LOOP);
    glVertex3fv(sisi[a]);
    glVertex3fv(sisi[b]);
    glVertex3fv(sisi[c]);
    glVertex3fv(sisi[d]);
    glEnd();

    glColor3fv(color[indexColor]);
    glBegin(GL_POLYGON);
    glVertex3fv(sisi[a]);
    glVertex3fv(sisi[b]);
    glVertex3fv(sisi[c]);
    glVertex3fv(sisi[d]);
    glEnd();
}

void draw_cube(){
    int warna = -1;
    for(int i = 0; i < 216; i+=4){
        if(i % 35 == 0) ++warna;
        polygon(i%36,i,i+1,i+2,i+3);
    }

}
