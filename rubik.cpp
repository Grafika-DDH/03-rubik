#include "rubik.hpp"

GLfloat sisi[][3] = {
    // center back
    {-1.f,1.f,-3.f},
    {1.f,1.f,-3.f},
    {1.f,-1.f,-3.f},
    {-1.f,-1.f,-3.f},

    // center right back
    {1.f,1.f,-3.f},
    {3.f,1.f,-3.f},
    {3.f,-1.f,-3.f},
    {1.f,-1.f,-3.f},

    // center left back
    {-3.f,1.f,-3.f},
    {-1.f,1.f,-3.f},
    {-1.f,-1.f,-3.f},
    {-3.f,-1.f,-3.f},

    // center top back
    {-1.f,3.f,-3.f},
    {1.f,3.f,-3.f},
    {1.f,1.f,-3.f},
    {-1.f,1.f,-3.f},

    // center bottom back
    {-1.f,-1.f,-3.f},
    {1.f,-1.f,-3.f},
    {1.f,-3.f,-3.f},
    {-1.f,-3.f,-3.f},

    // top right back
    {1.f,3.f,-3.f},
    {3.f,3.f,-3.f},
    {3.f,1.f,-3.f},
    {1.f,1.f,-3.f},

    // top left back
    {-3.f,3.f,-3.f},
    {-1.f,3.f,-3.f},
    {-1.f,1.f,-3.f},
    {-3.f,1.f,-3.f},

    // bottom left back
    {-3.f,-1.f,-3.f},
    {-1.f,-1.f,-3.f},
    {-1.f,-3.f,-3.f},
    {-3.f,-3.f,-3.f},

    // bottom right back
    {1.f,-1.f,-3.f},
    {3.f,-1.f,-3.f},
    {3.f,-3.f,-3.f},
    {1.f,-3.f,-3.f},

    ////////////////////////////////////

    // center right
    {3.f,1.f,-1.f},
    {3.f,1.f,1.f},
    {3.f,-1.f,1.f},
    {3.f,-1.f,-1.f},

    // center right right
    {3.f,1.f,-3.f},
    {3.f,1.f,-1.f},
    {3.f,-1.f,-1.f},
    {3.f,-1.f,-3.f},

    // center left right
    {3.f,1.f,1.f},
    {3.f,1.f,3.f},
    {3.f,-1.f,3.f},
    {3.f,-1.f,1.f},

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
    {3.f,3.f,-3.f},
    {3.f,3.f,-1.f},
    {3.f,1.f,-1.f},
    {3.f,1.f,-3.f},

    // top left right
    {3.f,3.f,1.f},
    {3.f,3.f,3.f},
    {3.f,1.f,3.f},
    {3.f,1.f,1.f},

    // bottom left right
    {3.f,-1.f,1.f},
    {3.f,-1.f,3.f},
    {3.f,-3.f,3.f},
    {3.f,-3.f,1.f},

    // bottom right right
    {3.f,-1.f,-3.f},
    {3.f,-1.f,-1.f},
    {3.f,-3.f,-1.f},
    {3.f,-3.f,-3.f},

    /////////////////////////////////

    // center left
    {-3.f,1.f,-1.f},
    {-3.f,1.f,1.f},
    {-3.f,-1.f,1.f},
    {-3.f,-1.f,-1.f},

    // center right left
    {-3.f,1.f,-3.f},
    {-3.f,1.f,-1.f},
    {-3.f,-1.f,-1.f},
    {-3.f,-1.f,-3.f},

    // center left left
    {-3.f,1.f,1.f},
    {-3.f,1.f,3.f},
    {-3.f,-1.f,3.f},
    {-3.f,-1.f,1.f},

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
    {-3.f,3.f,-3.f},
    {-3.f,3.f,-1.f},
    {-3.f,1.f,-1.f},
    {-3.f,1.f,-3.f},

    // top left left
    {-3.f,3.f,1.f},
    {-3.f,3.f,3.f},
    {-3.f,1.f,3.f},
    {-3.f,1.f,1.f},

    // bottom left left
    {-3.f,-1.f,1.f},
    {-3.f,-1.f,3.f},
    {-3.f,-3.f,3.f},
    {-3.f,-3.f,1.f},

    // bottom right left
    {-3.f,-1.f,-3.f},
    {-3.f,-1.f,-1.f},
    {-3.f,-3.f,-1.f},
    {-3.f,-3.f,-3.f},

    /////////////////////////////

    // center front
    {-1.f,1.f,3.f},
    {1.f,1.f,3.f},
    {1.f,-1.f,3.f},
    {-1.f,-1.f,3.f},

    // center right front
    {1.f,1.f,3.f},
    {3.f,1.f,3.f},
    {3.f,-1.f,3.f},
    {1.f,-1.f,3.f},

    // center left front
    {-3.f,1.f,3.f},
    {-1.f,1.f,3.f},
    {-1.f,-1.f,3.f},
    {-3.f,-1.f,3.f},

    // center top front
    {-1.f,3.f,3.f},
    {1.f,3.f,3.f},
    {1.f,1.f,3.f},
    {-1.f,1.f,3.f},

    // center bottom front
    {-1.f,-1.f,3.f},
    {1.f,-1.f,3.f},
    {1.f,-3.f,3.f},
    {-1.f,-3.f,3.f},

    // top right front
    {1.f,3.f,3.f},
    {3.f,3.f,3.f},
    {3.f,1.f,3.f},
    {1.f,1.f,3.f},

    // top left front
    {-3.f,3.f,3.f},
    {-1.f,3.f,3.f},
    {-1.f,1.f,3.f},
    {-3.f,1.f,3.f},

    // bottom left front
    {-3.f,-1.f,3.f},
    {-1.f,-1.f,3.f},
    {-1.f,-3.f,3.f},
    {-3.f,-3.f,3.f},

    // bottom right front
    {1.f,-1.f,3.f},
    {3.f,-1.f,3.f},
    {3.f,-3.f,3.f},
    {1.f,-3.f,3.f},

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
    {-1.f,3.f,-3.f},
    {1.f,3.f,-3.f},
    {1.f,3.f,-1.f},
    {-1.f,3.f,-1.f},

    // center bottom top
    {-1.f,3.f,1.f},
    {1.f,3.f,1.f},
    {1.f,3.f,3.f},
    {-1.f,3.f,3.f},

    // top right top
    {1.f,3.f,-3.f},
    {3.f,3.f,-3.f},
    {3.f,3.f,-1.f},
    {1.f,3.f,-1.f},

    // top left top
    {-3.f,3.f,-3.f},
    {-1.f,3.f,-3.f},
    {-1.f,3.f,-1.f},
    {-3.f,3.f,-1.f},

    // bottom left top
    {-3.f,3.f,1.f},
    {-1.f,3.f,1.f},
    {-1.f,3.f,3.f},
    {-3.f,3.f,3.f},

    // bottom right top
    {1.f,3.f,1.f},
    {3.f,3.f,1.f},
    {3.f,3.f,3.f},
    {1.f,3.f,3.f},

    /////////////////////////

    // center bottom
    {-1.f,-3.f,1.f},
    {1.f,-3.f,1.f},
    {1.f,-3.f,-1.f},
    {-1.f,-3.f,-1.f},

    // center right bottom
    {1.f,-3.f,1.f},
    {3.f,-3.f,1.f},
    {3.f,-3.f,-1.f},
    {1.f,-3.f,-1.f},

    // center left bottom
    {-3.f,-3.f,1.f},
    {-1.f,-3.f,1.f},
    {-1.f,-3.f,-1.f},
    {-3.f,-3.f,-1.f},

    // center top bottom
    {-1.f,-3.f,-3.f},
    {1.f,-3.f,-3.f},
    {1.f,-3.f,-1.f},
    {-1.f,-3.f,-1.f},

    // center bottom bottom
    {-1.f,-3.f,1.f},
    {1.f,-3.f,1.f},
    {1.f,-3.f,3.f},
    {-1.f,-3.f,3.f},

    // top right bottom
    {1.f,-3.f,-3.f},
    {3.f,-3.f,-3.f},
    {3.f,-3.f,-1.f},
    {1.f,-3.f,-1.f},

    // top left bottom
    {-3.f,-3.f,-3.f},
    {-1.f,-3.f,-3.f},
    {-1.f,-3.f,-1.f},
    {-3.f,-3.f,-1.f},

    // bottom left bottom
    {-3.f,-3.f,1.f},
    {-1.f,-3.f,1.f},
    {-1.f,-3.f,3.f},
    {-3.f,-3.f,3.f},

    // bottom right bottom
    {1.f,-3.f,1.f},
    {3.f,-3.f,1.f},
    {3.f,-3.f,3.f},
    {1.f,-3.f,3.f},
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

int
    top[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    right[3][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}},
    front[3][3] = {{2, 2, 2}, {2, 2, 2}, {2, 2, 2}},
    back[3][3] = {{3, 3, 3}, {3, 3, 3}, {3, 3, 3}},
    bottom[3][3] = {{4, 4, 4}, {4, 4, 4}, {4, 4, 4}},
    left[3][3] = {{5, 5, 5}, {5, 5, 5}, {5, 5, 5}};

void draw_cube(){
    polygon(back[1][1],0,1,2,3);
    polygon(back[1][2],4,5,6,7);
    polygon(back[1][0],8,9,10,11);
    polygon(back[0][1],12,13,14,15);
    polygon(back[2][1],16,17,18,19);
    polygon(back[0][2],20,21,22,23);
    polygon(back[0][0],24,25,26,27);
    polygon(back[2][0],28,29,30,31);
    polygon(back[2][2],32,33,34,35);

    polygon(right[1][1],36,37,38,39);
    polygon(right[1][2],40,41,42,43);
    polygon(right[1][0],44,45,46,47);
    polygon(right[0][1],48,49,50,51);
    polygon(right[2][1],52,53,54,55);
    polygon(right[0][2],56,57,58,59);
    polygon(right[0][0],60,61,62,63);
    polygon(right[2][0],64,65,66,67);
    polygon(right[2][2],68,69,70,71);

    polygon(left[1][1],72,73,74,75);
    polygon(left[1][2],76,77,78,79);
    polygon(left[1][0],80,81,82,83);
    polygon(left[0][1],84,85,86,87);
    polygon(left[2][1],88,89,90,91);
    polygon(left[0][2],92,93,94,95);
    polygon(left[0][0],96,97,98,99);
    polygon(left[2][0],100,101,102,103);
    polygon(left[2][2],104,105,106,107);

    polygon(front[1][1],108,109,110,111);
    polygon(front[1][2],112,113,114,115);
    polygon(front[1][0],116,117,118,119);
    polygon(front[0][1],120,121,122,123);
    polygon(front[2][1],124,125,126,127);
    polygon(front[0][2],128,129,130,131);
    polygon(front[0][0],132,133,134,135);
    polygon(front[2][0],136,137,138,139);
    polygon(front[2][2],140,141,142,143);

    polygon(top[1][1],144,145,146,147);
    polygon(top[1][2],148,149,150,151);
    polygon(top[1][0],152,153,154,155);
    polygon(top[0][1],156,157,158,159);
    polygon(top[2][1],160,161,162,163);
    polygon(top[0][2],164,165,166,167);
    polygon(top[0][0],168,169,170,171);
    polygon(top[2][0],172,173,174,175);
    polygon(top[2][2],176,177,178,179);

    polygon(bottom[1][1],180,181,182,183);
    polygon(bottom[1][2],184,185,186,187);
    polygon(bottom[1][0],188,189,190,191);
    polygon(bottom[0][1],192,193,194,195);
    polygon(bottom[2][1],196,197,198,199);
    polygon(bottom[0][2],200,201,202,203);
    polygon(bottom[0][0],204,205,206,207);
    polygon(bottom[2][0],208,209,210,211);
    polygon(bottom[2][2],212,213,214,215);
}

void rotateTop(){
    int temp;

    temp = top[0][0];
    top[0][0] = top[2][0];
    top[2][0] = top[2][2];
    top[2][2] = top[0][2];
    top[0][2] = temp;

    temp = top[1][0];
    top[1][0] = top[2][1];
    top[2][1] = top[1][2];
    top[1][2] = top[0][1];
    top[0][1] = temp;

    int temp1 = front[0][0];
    int temp2 = front[0][1];
    int temp3 = front[0][2];

    front[0][0] = right[0][0];
    front[0][1] = right[0][1];
    front[0][2] = right[0][2];

    right[0][0] = back[0][2];
    right[0][1] = back[0][1];
    right[0][2] = back[0][0];

    back[0][2] = left[0][2];
    back[0][1] = left[0][1];
    back[0][0] = left[0][0];

    left[0][0] = temp3;
    left[0][1] = temp2;
    left[0][2] = temp1;
}

void rotateBottom(){
    int temp;

    temp = bottom[0][0];
    bottom[0][0] = bottom[2][0];
    bottom[2][0] = bottom[2][2];
    bottom[2][2] = bottom[0][2];
    bottom[0][2] = temp;

    temp = bottom[1][0];
    bottom[1][0] = bottom[2][1];
    bottom[2][1] = bottom[1][2];
    bottom[1][2] = bottom[0][1];
    bottom[0][1] = temp;

    int temp1 = front[2][0];
    int temp2 = front[2][1];
    int temp3 = front[2][2];

    front[2][0] = right[2][0];
    front[2][1] = right[2][1];
    front[2][2] = right[2][2];

    right[2][0] = back[2][2];
    right[2][1] = back[2][1];
    right[2][2] = back[2][0];

    back[2][2] = left[2][2];
    back[2][1] = left[2][1];
    back[2][0] = left[2][0];

    left[2][2] = temp1;
    left[2][1] = temp2;
    left[2][0] = temp3;
}

void rotateRight(){
    int temp;

    temp = right[0][0];
    right[0][0] = right[2][0];
    right[2][0] = right[2][2];
    right[2][2] = right[0][2];
    right[0][2] = temp;

    temp = right[1][0];
    right[1][0] = right[2][1];
    right[2][1] = right[1][2];
    right[1][2] = right[0][1];
    right[0][1] = temp;

    int temp1 = top[0][2];
    int temp2 = top[1][2];
    int temp3 = top[2][2];

    top[0][2] = front[0][2];
    top[1][2] = front[1][2];
    top[2][2] = front[2][2];

    front[0][2] = bottom[2][2];
    front[1][2] = bottom[1][2];
    front[2][2] = bottom[0][2];

    bottom[2][2] = back[2][2];
    bottom[1][2] = back[1][2];
    bottom[0][2] = back[0][2];

    back[2][2] = temp3;
    back[1][2] = temp2;
    back[0][2] = temp1;
}

void rotateLeft(){
    int temp;

    temp = left[0][0];
    left[0][0] = left[2][0];
    left[2][0] = left[2][2];
    left[2][2] = left[0][2];
    left[0][2] = temp;

    temp = left[1][0];
    left[1][0] = left[2][1];
    left[2][1] = left[1][2];
    left[1][2] = left[0][1];
    left[0][1] = temp;

    int temp1 = front[0][0];
    int temp2 = front[1][0];
    int temp3 = front[2][0];

    front[0][0] = top[0][0];
    front[1][0] = top[1][0];
    front[2][0] = top[2][0];

    top[0][0] = back[2][2];
    top[1][0] = back[1][2];
    top[2][0] = back[0][2];

    back[2][2] = bottom[0][0];
    back[1][2] = bottom[1][0];
    back[0][2] = bottom[2][0];

    bottom[0][0] = temp1;
    bottom[1][0] = temp2;
    bottom[2][0] = temp3;
}

void rotateFront(){
    int temp;

    temp = back[0][0];
    back[0][0] = back[2][0];
    back[2][0] = back[2][2];
    back[2][2] = back[0][2];
    back[0][2] = temp;

    temp = back[1][0];
    back[1][0] = back[2][1];
    back[2][1] = back[1][2];
    back[1][2] = back[0][1];
    back[0][1] = temp;

    int temp1 = top[0][0];
    int temp2 = top[0][1];
    int temp3 = top[0][2];

    top[0][0] = right[0][2];
    top[0][1] = right[1][2];
    top[0][2] = right[2][2];

    right[0][2] = bottom[2][2];
    right[1][2] = bottom[2][1];
    right[2][2] = bottom[2][0];

    bottom[2][2] = left[2][0];
    bottom[2][1] = left[1][0];
    bottom[2][0] = left[0][0];

    left[2][0] = temp1;
    left[1][0] = temp2;
    left[0][0] = temp3;
}

void rotateBack(){
    int temp;

    temp = front[0][0];
    front[0][0] = front[2][0];
    front[2][0] = front[2][2];
    front[2][2] = front[0][2];
    front[0][2] = temp;

    temp = front[1][0];
    front[1][0] = front[2][1];
    front[2][1] = front[1][2];
    front[1][2] = front[0][1];
    front[0][1] = temp;

    int temp1 = left[0][2];
    int temp2 = left[1][2];
    int temp3 = left[2][2];

    left[0][2] = bottom[0][0];
    left[1][2] = bottom[0][1];
    left[2][2] = bottom[0][2];

    bottom[0][0] = right[2][0];
    bottom[0][1] = right[1][0];
    bottom[0][2] = right[0][0];

    right[2][0] = top[2][2];
    right[1][0] = top[2][1];
    right[0][0] = top[2][0];

    top[2][2] = temp1;
    top[2][1] = temp2;
    top[2][0] = temp3;
}
