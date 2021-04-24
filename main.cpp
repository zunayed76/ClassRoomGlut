#include<GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <windows.h>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;







///Z for front V for back
///X for left C for right
///Y for up U for down










double windowHeight=1920, windowWidth=1080;
bool rott=false;
float rotlimit=0.0;
float rotlimS = 0.0;
bool chkx = false;
bool chky = false;
bool chkz = false;

bool chX = false;
bool chY = false;
bool chZ = false;

bool scenerotY = false;

#define PI 3.141592654

GLfloat eyeX = 0;      ///eye  4.5
GLfloat eyeY = 1.9;     /// 1.9
GLfloat eyeZ = -14;        ///-6

GLfloat lookX = 0;      ///look at point
GLfloat lookY = 0;
GLfloat lookZ = 0;




void cube(float fr = 1.0, float fg = 0.0, float fb = 0.0,float lr = 0.0, float lg = 1.0, float lb = 0.0,float tr = 0.0, float tg = 0.0, float tb = 1.0 )
{

    glBegin(GL_QUADS);
    /// FRONT
    glColor3f(fr,fg,fb);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f( 0.5f, -0.5f, 0.5f);
    glVertex3f( 0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);

    // BACK
    glColor3f(fr,fg,fb);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f( 0.5f, 0.5f, -0.5f);
    glVertex3f( 0.5f, -0.5f, -0.5f);

    /// LEFT
    glColor3f(lr,lg,lb);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);

    // RIGHT
    glColor3f(lr,lg,lb);
    glVertex3f( 0.5f, -0.5f, -0.5f);
    glVertex3f( 0.5f, 0.5f, -0.5f);
    glVertex3f( 0.5f, 0.5f, 0.5f);
    glVertex3f( 0.5f, -0.5f, 0.5f);

    /// TOP
    glColor3f(tr,tg,tb);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f( 0.5f, 0.5f, 0.5f);
    glVertex3f( 0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);

    // BOTTOM
    glColor3f(tr,tg,tb);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f( 0.5f, -0.5f, -0.5f);
    glVertex3f( 0.5f, -0.5f, 0.5f);
    glEnd();
}




/// wall alada akbo




void cubeSilver()
{

    glBegin(GL_QUADS);
    // FRONT
    glColor3f(0.753, 0.753, 0.753);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f( 0.5f, -0.5f, 0.5f);
    glVertex3f( 0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);

    // BACK
    glColor3f(0.753, 0.753, 0.753);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f( 0.5f, 0.5f, -0.5f);
    glVertex3f( 0.5f, -0.5f, -0.5f);

    // LEFT
    glColor3f(0.700, 0.700, 0.700);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);

    // RIGHT
    glColor3f(0.700, 0.700, 0.700);
    glVertex3f( 0.5f, -0.5f, -0.5f);
    glVertex3f( 0.5f, 0.5f, -0.5f);
    glVertex3f( 0.5f, 0.5f, 0.5f);
    glVertex3f( 0.5f, -0.5f, 0.5f);

    // TOP
    glColor3f(0.753, 0.753, 0.753);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f( 0.5f, 0.5f, 0.5f);
    glVertex3f( 0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);

    // BOTTOM
    glColor3f(0.753, 0.753, 0.753);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f( 0.5f, -0.5f, -0.5f);
    glVertex3f( 0.5f, -0.5f, 0.5f);
    glEnd();
}































void chair()
{

    glPushMatrix();     /// 4 ta pa
    glScalef(0.3,2,0.3);
    cube(0.855, 0.647, 0.125,0.800, 0.600, 0.100,0.722, 0.525, 0.043);    ///cube gold
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2,0,0);
    glScalef(0.3,2,0.3);
    cube(0.855, 0.647, 0.125,0.800, 0.600, 0.100,0.722, 0.525, 0.043);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,2);
    glScalef(0.3,2,0.3);
    cube(0.855, 0.647, 0.125,0.800, 0.600, 0.100,0.722, 0.525, 0.043);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2,0,2);
    glScalef(0.3,2,0.3);
    cube(0.855, 0.647, 0.125,0.800, 0.600, 0.100,0.722, 0.525, 0.043);
    glPopMatrix();

    glPushMatrix();       ///bosar jayga
    glTranslatef(1,1,1);
    glRotatef(90,0,0,1);
    glScalef(0.3,3,3);
    cube(0.855, 0.647, 0.125,0.800, 0.600, 0.100,0.722, 0.525, 0.043);
    glPopMatrix();

    glPushMatrix();   /// 2 ta rod
    glTranslatef(2,1.6,2);
    glScalef(0.3,0.7,0.3);
    cube(0.502, 0.502, 0.502,0.470, 0.470, 0.470,0.502, 0.502, 0.502);     /// gray color
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,1.6,2);
    glScalef(0.3,0.7,0.3);
    cube(0.502, 0.502, 0.502,0.470, 0.470, 0.470,0.502, 0.502, 0.502);
    glPopMatrix();

    glPushMatrix();   /// helan deoar jayga
    glTranslatef(1,2.5,2);
    glRotatef(90,0,0,1);
    glScalef(1,2.8,0.3);
    cube(1.000, 0.843, 0.00,1.000, 1.000, 0.000,1.000, 1.000, 0.878);    ///yellow cube
    glPopMatrix();

}
void desk()
{

    glPushMatrix();
    glScalef(0.3,4,0.3);
    cube(0.824, 0.412, 0.118,0.800, 0.390, 0.100,0.780, 0.390, 0.90);   /// chocolate
                                                                        /// tablee r paya
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4,0,0);
    glScalef(0.3,4,0.3);
    cube(0.824, 0.412, 0.118,0.800, 0.390, 0.100,0.780, 0.390, 0.90);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,4);
    glScalef(0.3,4,0.3);
    cube(0.824, 0.412, 0.118,0.800, 0.390, 0.100,0.780, 0.390, 0.90);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4,0,4);
    glScalef(0.3,4,0.3);
    cube(0.824, 0.412, 0.118,0.800, 0.390, 0.100,0.780, 0.390, 0.90);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(4/2,4/2,4/2);
    glRotatef(90,0,0,1);
    glScalef(0.3,5,5);
    cube(0.647, 0.165, 0.165,0.580, 0.70, 0.80,0.502, 0.000, 0.000);     /// table er upre cube maroon
    glPopMatrix();
}


void shroud(float fr = 1.0, float fg = 0.0, float fb = 0.0){

    glBegin(GL_QUADS);
        glColor3f(fr,fg,fb);
        glVertex3f(-0.5f,-0.5f,0);
        glVertex3f(0.5f,-0.5f,0);
        glVertex3f(0.5f,0.5f,0);
        glVertex3f(-0.5f,0.5f,0);
    glEnd();
}

void cylinder(float fr = 0.9, float fg = 0.9, float fb = 0.9)
{
    int s=20;
    float h=1;
    float r=0.5;
    float t=0;
    float tI=(2*PI)/s;

    float x = r*cos(t);
    float z = r*sin(t);

    glBegin(GL_QUAD_STRIP);

    glColor3f(fr,fg,fb);
    glVertex3f(x,0,z);
    glColor3f(fr,fg,fb);
    glVertex3f(x,h,z);
    for(t=tI; t<2*PI; t=t+tI)
    {
        x = r*cos(t);
        z = r*sin(t);
        glColor3f(fr,fg,fb);
        glVertex3f(x,0,z);
        glColor3f(fr,fg,fb);
        glVertex3f(x,h,z);
    }
    t=0;
    x = r*cos(t);
    z = r*sin(t);
    glColor3f(fr,fg,fb);
    glVertex3f(x,0,z);
    glColor3f(fr,fg,fb);
    glVertex3f(x,h,z);

    glEnd();
}


void fan()
{
    glPushMatrix();
    glTranslatef(3,0,0);
    glScalef(3,0.1,1);
    cube(0.000, 0.000, 1.000,0.000, 0.000, 0.900,0.098, 0.098, 0.439);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1,0,0);
    glScalef(1,0.1,0.1);
    cube(0.000, 0.000, 1.000,0.000, 0.000, 0.900,0.098, 0.098, 0.439);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3,0,0);
    glScalef(3,0.1,1);
    cube(0.000, 0.000, 1.000,0.000, 0.000, 0.900,0.098, 0.098, 0.439);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1,0,0);
    glScalef(1,0.1,0.1);
    cube(0.000, 0.000, 1.000,0.000, 0.000, 0.900,0.098, 0.098, 0.439);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,3);
    glScalef(1,0.1,3);
    cube(0.000, 0.000, 1.000,0.000, 0.000, 0.900,0.098, 0.098, 0.439);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,1);
    glScalef(0.1,0.1,1);
    cube(0.000, 0.000, 1.000,0.000, 0.000, 0.900,0.098, 0.098, 0.439);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,-3);
    glScalef(1,0.1,3);
    cube(0.000, 0.000, 1.000,0.000, 0.000, 0.900,0.098, 0.098, 0.439);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,-1);
    glScalef(0.1,0.1,1);
    cube(0.000, 0.000, 1.000,0.000, 0.000, 0.900,0.098, 0.098, 0.439);
    glPopMatrix();
   // glPushMatrix();
    //glTranslatef(0,-0.2,0);
    //glScalef(01,0.2,1);
    //cylinder(0.980, 0.922, 0.843);      ///0.098, 0.098, 0.439
    //glPopMatrix();
}




void cabinet()
{

    ///left side
    glPushMatrix();
    glScalef(0.1,10,5);
    cube(0.600, 0.000, 0.600,1.000, 0.000, 1.000,0.800, 0.000, 0.800);   ///violet cube
    glPopMatrix();
    /// right side
    glPushMatrix();
    glTranslatef(6,0,0);
    glScalef(0.1,10,5);
    cube(0.600, 0.000, 0.600,1.000, 0.000, 1.000,0.800, 0.000, 0.800);   ///violet cube
    glPopMatrix();

    /// back side
    glPushMatrix();
    glTranslatef(6/2,0,5.0/2);
    glScalef(6,10,0.1);
    cube(0.600, 0.000, 0.600,1.000, 0.000, 1.000,0.800, 0.000, 0.800);   ///violet cube
    glPopMatrix();

    /// ceiling side
    glPushMatrix();
    glTranslatef(6/2,5,0);
    glScalef(6,0.1,5);
    cube(0.600, 0.000, 0.600,1.000, 0.000, 1.000,0.800, 0.000, 0.800);   ///violet cube
    glPopMatrix();

    /// bottom side
    glPushMatrix();
    glTranslatef(6.0/2,-5,0);
    glScalef(6,0.1,5);
    cube(0.600, 0.000, 0.600,1.000, 0.000, 1.000,0.800, 0.000, 0.800);
    glPopMatrix();

    /// right door
    glPushMatrix();
    glTranslatef(3.0/2,0,-5.0/2);
    glScalef(3,10,0.1);
    cube(0.600, 0.000, 0.600,1.000, 0.000, 1.000,0.800, 0.000, 0.800);   ///violet cube
    glPopMatrix();

    ///Door handle right
    glPushMatrix();
    glTranslatef(3.0/1.5,1,-3);
    glScalef(0.2,1.5,0.2);     /// x =
    cube(0.753, 0.753, 0.753,0.753, 0.753, 0.753,0.753, 0.753, 0.753);       ///cubeSilver
    glPopMatrix();

    /// left door
    glPushMatrix();
    glTranslatef(6-3.0/2,0,-5.0/2);
    glScalef(3,10,0.1);
    cube(0.600, 0.200, 0.600,1.000, 0.000, 1.000,0.800, 0.000, 0.800);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(3.0/1.5,1.6,-2.8);
    glScalef(0.2,0.2,0.4);     /// x =
    cube(0.753, 0.753, 0.753,0.753, 0.753, 0.753,0.753, 0.753, 0.753);       ///cubeSilver   0.753, 0.753, 0.753,0.753, 0.753, 0.753,0.753, 0.753, 0.753
    glPopMatrix();
    glPushMatrix();
    glTranslatef(3.0/1.5,0.35,-2.8);
    glScalef(0.2,0.2,0.4);     /// x =
    cube(0.753, 0.753, 0.753,0.753, 0.753, 0.753,0.753, 0.753, 0.753);       ///cubeSilver   0.753, 0.753, 0.753,0.753, 0.753, 0.753,0.753, 0.753, 0.753
    glPopMatrix();
    ///
    //glPushMatrix();
    //glTranslatef(6-3.0/1.5,3.0/2,-5.0/2);
    //glScalef(0.1,0.5,0.5);
    //cube(0.753, 0.753, 0.753,0.753, 0.753, 0.753,0.753, 0.753, 0.753);       ///cube silver
    //glPopMatrix();
    ///Door handle lefy
    glPushMatrix();
    glTranslatef(6-3.0/1.5,1,-3);
    glScalef(0.2,1.5,0.2);     /// x =
    cube(0.753, 0.753, 0.753,0.753, 0.753, 0.753,0.753, 0.753, 0.753);       ///cubeSilver
    glPopMatrix();
    glPushMatrix();
    glTranslatef(6-3.0/1.5,1.6,-2.8);
    glScalef(0.2,0.2,0.4);     /// x =
    cube(0.753, 0.753, 0.753,0.753, 0.753, 0.753,0.753, 0.753, 0.753);       ///cubeSilver   0.753, 0.753, 0.753,0.753, 0.753, 0.753,0.753, 0.753, 0.753
    glPopMatrix();
    glPushMatrix();
    glTranslatef(6-3.0/1.5,0.35,-2.8);
    glScalef(0.2,0.2,0.4);     /// x =
    cube(0.753, 0.753, 0.753,0.753, 0.753, 0.753,0.753, 0.753, 0.753);       ///cubeSilver   0.753, 0.753, 0.753,0.753, 0.753, 0.753,0.753, 0.753, 0.753
    glPopMatrix();


}

void fanUpy()
{
    glPushMatrix();
    glRotatef(rotlimit,0,1,0);
    fan();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,0);
    glScalef(1.5,1.5,1.5);
    cylinder();
    glPopMatrix();
}


void slateBoard(){
    glPushMatrix();
    glScalef(14,7,0.8);
    cube( 0.545, 0.271, 0.075, 0.545, 0.271, 0.075, 0.545, 0.271, 0.075);           ///slate color 0.545, 0.271, 0.075
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,-0.5f);
    glScalef(13,6,0.5);
    shroud(0.184, 0.310, 0.310); ///slate rer border saddle browen
    glPopMatrix();


}


void dias()
{
    glPushMatrix();
    glScalef(14,3,4);
    cube( 0.545, 0.271, 0.075, 0.645, 0.371, 0.175, 0.445, 0.171, 0.075);           ///slate color 0.545, 0.271, 0.075
    glPopMatrix();
}




///

/// extra

///





void title_part_function(float h,float w,float l)
{
    glPushMatrix();
    glScalef(h,w,l);
    cube(0,0,0,0,0,0,0,0,0);
    glPopMatrix();
}

void C_drawing_part(float h,float w,float l)
{
    //<-----------Left------------->
    title_part_function(h,2*w,l);

    //<-------Upper------------>
    glPushMatrix();
    glTranslatef(w,2*w,0);
    title_part_function(w,h,l);
    glPopMatrix();

    //<-------Lower------------>
    glPushMatrix();
    glTranslatef(w,-2*w,0);
    title_part_function(w,h,l);
    glPopMatrix();
}

void S_drawing_part(float h,float w,float l)
{
    //<-------Upper------------>
    glPushMatrix();
    glTranslatef(w,2*w,0);
    title_part_function(w,h,l);
    glPopMatrix();

    //<-------Lower------------>
    glPushMatrix();
    glTranslatef(w,-2*w,0);
    title_part_function(w,h,l);
    glPopMatrix();

    //<-------Middle------------>
    glPushMatrix();
    glTranslatef(w,0,0);
    title_part_function(w,h,l);
    glPopMatrix();

    //<--------Left------------->
    glPushMatrix();
    glTranslatef(0,w,0);
    title_part_function(h,w,l);
    glPopMatrix();

    //<--------Right------------->
    glPushMatrix();
    glTranslatef((w+2*l),-w,0);
    title_part_function(h,w,l);
    glPopMatrix();
}


void E_drawing_part(float h,float w,float l)
{
    //<-----------Left------------->
    title_part_function(h,2*w,l);

    //<-------Upper------------>
    glPushMatrix();
    glTranslatef(w,2*w,0);
    title_part_function(w,h,l);
    glPopMatrix();

    //<-------Lower------------>
    glPushMatrix();
    glTranslatef(w,-2*w,0);
    title_part_function(w,h,l);
    glPopMatrix();

    //<-------Middle------------>
    glPushMatrix();
    glTranslatef(w,0,0);
    title_part_function(w,h,l);
    glPopMatrix();

}

void CSE_drawing_part(float h,float w,float l)
{
    //<--------------"C"----------->
    glPushMatrix();
    glTranslatef(-2*(w+l),0,0);
    C_drawing_part(h,w,l);
    glPopMatrix();

    //<--------------"S"----------->
    glPushMatrix();
    S_drawing_part(h,w,l);
    glPopMatrix();

    //<--------------"E"----------->
    glPushMatrix();
    glTranslatef(2*(w+l),0,0);
    E_drawing_part(h,w,l);
    glPopMatrix();
}

void four_drawing_part(float h,float w,float l)
{
    //<-------Middle------------>
    glPushMatrix();
    glTranslatef(w,0,0);
    title_part_function(w,h,l);
    glPopMatrix();

    //<--------Left Upper------------->
    glPushMatrix();
    glTranslatef(0,w,0);
    title_part_function(h,w,l);
    glPopMatrix();

    //<--------Right Upper------------->
    glPushMatrix();
    glTranslatef((w+2*l),w,0);
    title_part_function(h,w,l);
    glPopMatrix();

    //<--------Right Lower------------->
    glPushMatrix();
    glTranslatef((w+2*l),-w,0);
    title_part_function(h,w,l);
    glPopMatrix();
}

void two_drawing_part(float h,float w,float l)
{
    //<-------Upper------------>
    glPushMatrix();
    glTranslatef(w,2*w,0);
    title_part_function(w,h,l);
    glPopMatrix();

    //<-------Lower------------>
    glPushMatrix();
    glTranslatef(w,-2*w,0);
    title_part_function(w,h,l);
    glPopMatrix();

    //<-------Middle------------>
    glPushMatrix();
    glTranslatef(w,0,0);
    title_part_function(w,h,l);
    glPopMatrix();

    //<--------Left Lower------------->
    glPushMatrix();
    glTranslatef(0,-w,0);
    title_part_function(h,w,l);
    glPopMatrix();

    //<--------Right Upper------------->
    glPushMatrix();
    glTranslatef((w+2*l),w,0);
    title_part_function(h,w,l);
    glPopMatrix();
}

void zero_drawing_part(float h,float w,float l)
{
    //<-------Upper------------>
    glPushMatrix();
    glTranslatef(w,2*w,0);
    title_part_function(w,h,l);
    glPopMatrix();

    //<-------Lower------------>
    glPushMatrix();
    glTranslatef(w,-2*w,0);
    title_part_function(w,h,l);
    glPopMatrix();

    //<--------Left------------->
    glPushMatrix();
    title_part_function(h,2*w,l);
    glPopMatrix();

    //<--------Right------------->
    glPushMatrix();
    glTranslatef((w+3*l),0,0);
    title_part_function(h,2*w,l);
    glPopMatrix();
}

void eight_drawing_part(float h,float w,float l)
{
    //<-------Upper------------>
    glPushMatrix();
    glTranslatef(w,2*w,0);
    title_part_function(w,h,l);
    glPopMatrix();

    //<-------Lower------------>
    glPushMatrix();
    glTranslatef(w,-2*w,0);
    title_part_function(w,h,l);
    glPopMatrix();

    //<-------Middle------------>
    glPushMatrix();
    glTranslatef(w,0,0);
    title_part_function(w,h,l);
    glPopMatrix();

    //<--------Left------------->
    glPushMatrix();
    title_part_function(h,2*w,l);
    glPopMatrix();

    //<--------Right------------->
    glPushMatrix();
    glTranslatef((w+3*l),0,0);
    title_part_function(h,2*w,l);
    glPopMatrix();
}

void Course_drawing_part(float h,float w,float l)
{
    //<--------------"4"----------->
    glPushMatrix();
    glTranslatef(-2*(w+l),0,0);
    four_drawing_part(h,w,l);
    glPopMatrix();

    //<--------------"2"----------->
    glPushMatrix();
    two_drawing_part(h,w,l);
    glPopMatrix();

    //<--------------"0"----------->
    glPushMatrix();
    glTranslatef(2*(w+l),0,0);
    zero_drawing_part(h,w,l);
    glPopMatrix();

    //<--------------"8"----------->
    glPushMatrix();
    glTranslatef(4.5*(w+l),0,0);
    eight_drawing_part(h,w,l);
    glPopMatrix();
}

void course_title_draw()
{
    float h=0.05,w=0.15,l=0.05;
    //<----------CSE---------------->
    glPushMatrix();
    glTranslatef(-0.7,0,0);
    CSE_drawing_part(h,w,l);
    glPopMatrix();

    //<----------4208---------------->
    glPushMatrix();
    glTranslatef(0.7,0,0);
    Course_drawing_part(h,w,l);
    glPopMatrix();
}








void window()
{
    ///part
    glPushMatrix();
    glScalef(2,6,1);
    cube( 0.863, 0.863, 0.863 ,0.863, 0.863, 0.863,0.863, 0.863, 0.863);           ///slate color 0.545, 0.271, 0.075
    glPopMatrix();
    ///middle

    glPushMatrix();
    glTranslatef(1,0,0);
    glScalef(0.2,6,1.3);
    cube(	0.184, 0.310, 0.310,	0.184, 0.310, 0.310,	0.184, 0.310, 0.310);   ///violet cube
    glPopMatrix();
    ///part
    glPushMatrix();
    glTranslatef(2,0,0);
    glScalef(2,6,1);
    cube(  0.863, 0.863, 0.863 ,0.863, 0.863, 0.863,0.863, 0.863, 0.863);           ///slate color 0.545, 0.271, 0.075
    glPopMatrix();
    /// left bar
    glPushMatrix();
    glTranslatef(-1,0,0);
    glScalef(0.2,6,1.3);
    cube(	0.184, 0.310, 0.310,	0.184, 0.310, 0.310,	0.184, 0.310, 0.310);   ///violet cube
    glPopMatrix();
     /// right bar
    glPushMatrix();
    glTranslatef(3,0,0);
    glScalef(0.2,6,1.3);
    cube(	0.184, 0.310, 0.310,	0.184, 0.310, 0.310,	0.184, 0.310, 0.310);   ///violet cube
    glPopMatrix();

     /// up
    glPushMatrix();
    glTranslatef(1,3,0);
    glScalef(4.2,0.2,1.3);
    cube(	0.184, 0.310, 0.310,	0.184, 0.310, 0.310,	0.184, 0.310, 0.310);   ///violet cube
    glPopMatrix();

    /// down
    glPushMatrix();
    glTranslatef(1,-3,0);
    glScalef(4.2,0.2,1.3);
    cube(	0.184, 0.310, 0.310,	0.184, 0.310, 0.310,	0.184, 0.310, 0.310);   ///violet cube
    glPopMatrix();


}









void scene(){
    /// l wall
    glPushMatrix();
    glTranslatef(-20.0/2,0,0);
    glScalef(0.1,22,30);
    cube(1.000, 0.894, 0.769,1.000, 0.894, 0.769,1.000, 0.894, 0.769);     ///bisque
    glPopMatrix();
    /// r wall
    glPushMatrix();

    glTranslatef(20.0/2,0,0);
    glScalef(0.1,22,30);
    cube(1.000, 0.894, 0.769,1.000, 0.894, 0.769,1.000, 0.894, 0.769);      ///bisque
    glPopMatrix();

    /// front wall
    glPushMatrix();
    glTranslatef(0,0,30.0/2);
    glScalef(20,22,0.1);
    cube(1.000, 0.973, 0.863,1.000, 0.973, 0.863,0.827, 0.827, 0.827);      ///cornsilk
    //cube();
    glPopMatrix();

    /// roof
    glPushMatrix();
    glTranslatef(0,22.0/2,0);
    glScalef(20,0.1,30);
    cube(1.000, 0.980, 0.980,1.000, 0.980, 0.980,1.000, 0.980, 0.980);             ///snow
    glPopMatrix();

    /// floor
    glPushMatrix();
    glTranslatef(0,-10.0/2,0);
    glScalef(20,0.1,30);
    cube(0,0,0,0,0,0,0.827, 0.827, 0.827);  ///gray
    glPopMatrix();


    /// fan
    glPushMatrix();
    glTranslatef(0,22.0/2-1,5);
    fanUpy();
    glPopMatrix();

    ///cabinet
    glPushMatrix();
    glTranslatef(-9.4,1,3);
    glRotatef(-90,0,1,0);
    glScalef(0.6,1.2,0.6);
    cabinet();
    glPopMatrix();

    /// board
    glPushMatrix();
    glTranslatef(0,5.5,30.0/2);
    slateBoard();
    glPopMatrix();

    ///dias
    glPushMatrix();
    glTranslatef(0,-4,13);
    dias();
    glPopMatrix();

     ///windw 1
    glPushMatrix();
    glTranslatef(10.3,4,5);
    glRotatef(-90,0,1,0);
    window();
    glPopMatrix();
    ///windw 2
    glPushMatrix();
    glTranslatef(10.3,4,-5);
    glRotatef(-90,0,1,0);
    window();
    glPopMatrix();

    ///course
    glPushMatrix();
    glTranslatef(1.3,0,14);
    glRotatef(-180,0,1,0);
    glScalef(4,4,2);
    course_title_draw();
    glPopMatrix();









    /// desk
    glPushMatrix();
    glTranslatef(5.5,-3,10-3);
    //glRotatef(-90,0,1,0);
    glScalef(0.65,0.9,0.4);
    desk();
    glPopMatrix();
    /// desk
    glPushMatrix();
    glTranslatef(-1,-3,10-3);
    //glRotatef(-90,0,1,0);
    glScalef(0.65,0.9,0.4);
    desk();
    glPopMatrix();
    /// desk
    glPushMatrix();
    glTranslatef(-6.5,-3,10 -3);
    //glRotatef(-90,0,1,0);
    glScalef(0.65,0.9,0.4);
    desk();
    glPopMatrix();

    /// chair
    glPushMatrix();
    glTranslatef(7,-4,9-3);
    glRotatef(180,0,1,0);
    glScalef(0.65,1,0.4);
    chair();
    glPopMatrix();
    /// chair
    glPushMatrix();
    glTranslatef(0.85,-4,9-3);
    glRotatef(180,0,1,0);
    glScalef(0.65,1,0.4);
    chair();
    glPopMatrix();
    /// chair
    glPushMatrix();
    glTranslatef(-4.2,-4,9-3);
    glRotatef(180,0,1,0);
    glScalef(0.65,1,0.4);
    chair();
    glPopMatrix();






    ///second row
    /// desk
    glPushMatrix();
    glTranslatef(5.5,-3,5-3);
    //glRotatef(-90,0,1,0);
    glScalef(0.65,0.9,0.4);
    desk();
    glPopMatrix();
    /// desk
    glPushMatrix();
    glTranslatef(-1,-3,5-3);
    //glRotatef(-90,0,1,0);
    glScalef(0.65,0.9,0.4);
    desk();
    glPopMatrix();
    /// desk
    glPushMatrix();
    glTranslatef(-6.5,-3,5-3);
    //glRotatef(-90,0,1,0);
    glScalef(0.65,0.9,0.4);
    desk();
    glPopMatrix();

    /// chair
    glPushMatrix();
    glTranslatef(7,-4,4-3);
    glRotatef(180,0,1,0);
    glScalef(0.65,1,0.4);
    chair();
    glPopMatrix();
    /// chair
    glPushMatrix();
    glTranslatef(0.85,-4,4-3);
    glRotatef(180,0,1,0);
    glScalef(0.65,1,0.4);
    chair();
    glPopMatrix();
    /// chair
    glPushMatrix();
    glTranslatef(-4.2,-4,4-3);
    glRotatef(180,0,1,0);
    glScalef(0.65,1,0.4);
    chair();
    glPopMatrix();



    ///third row

    /// desk
    glPushMatrix();
    glTranslatef(5.5,-3,0-3);
    //glRotatef(-90,0,1,0);
    glScalef(0.65,0.9,0.4);
    desk();
    glPopMatrix();
    /// desk
    glPushMatrix();
    glTranslatef(-1,-3,0-3);
    //glRotatef(-90,0,1,0);
    glScalef(0.65,0.9,0.4);
    desk();
    glPopMatrix();
    /// desk
    glPushMatrix();
    glTranslatef(-6.5,-3,0-3);
    //glRotatef(-90,0,1,0);
    glScalef(0.65,0.9,0.4);
    desk();
    glPopMatrix();

    /// chair
    glPushMatrix();
    glTranslatef(7,-4,-1-3);
    glRotatef(180,0,1,0);
    glScalef(0.65,1,0.4);
    chair();
    glPopMatrix();
    /// chair
    glPushMatrix();
    glTranslatef(0.85,-4,-1-3);
    glRotatef(180,0,1,0);
    glScalef(0.65,1,0.4);
    chair();
    glPopMatrix();
    /// chair
    glPushMatrix();
    glTranslatef(-4.2,-4,-1-3);
    glRotatef(180,0,1,0);
    glScalef(0.65,1,0.4);
    chair();
    glPopMatrix();

///fourth row

    /// desk
    glPushMatrix();
    glTranslatef(5.5,-3,-5-3);
    //glRotatef(-90,0,1,0);
    glScalef(0.65,0.9,0.4);
    desk();
    glPopMatrix();
    /// desk
    glPushMatrix();
    glTranslatef(-1,-3,-5-3);
    //glRotatef(-90,0,1,0);
    glScalef(0.65,0.9,0.4);
    desk();
    glPopMatrix();
    /// desk
    glPushMatrix();
    glTranslatef(-6.5,-3,-5-3);
    //glRotatef(-90,0,1,0);
    glScalef(0.65,0.9,0.4);
    desk();
    glPopMatrix();

    /// chair
    glPushMatrix();
    glTranslatef(7,-3-1,-6-3);
    glRotatef(180,0,1,0);
    glScalef(0.65,1,0.4);
    chair();
    glPopMatrix();
    /// chair
    glPushMatrix();
    glTranslatef(0.85,-4,-6-3);
    glRotatef(180,0,1,0);
    glScalef(0.65,1,0.4);
    chair();
    glPopMatrix();
    /// chair
    glPushMatrix();
    glTranslatef(-4.2,-4,-6-3);
    glRotatef(180,0,1,0);
    glScalef(0.65,1,0.4);
    chair();
    glPopMatrix();


       ///dag dag
    glPushMatrix();
    glTranslatef(0,-4.9,0);
    glScalef(0.05,0.05,30);
    cube(0,0,0,0,0,0,0,0,0);  ///gray
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3,-4.9,0);
    glScalef(0.05,0.05,30);
    cube(0,0,0,0,0,0,0,0,0);  ///gray
    glPopMatrix();

    glPushMatrix();
    glTranslatef(6,-4.9,0);
    glScalef(0.05,0.05,30);
    cube(0,0,0,0,0,0,0,0,0);  ///gray
    glPopMatrix();

    glPushMatrix();
    glTranslatef(9,-4.9,0);
    glScalef(0.05,0.05,30);
    cube(0,0,0,0,0,0,0,0,0);  ///gray
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3,-4.9,0);
    glScalef(0.05,0.05,30);
    cube(0,0,0,0,0,0,0,0,0);  ///gray
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-6,-4.9,0);
    glScalef(0.05,0.05,30);
    cube(0,0,0,0,0,0,0,0,0);  ///gray
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-9,-4.9,0);
    glScalef(0.05,0.05,30);
    cube(0,0,0,0,0,0,0,0,0);  ///gray
    glPopMatrix();



    ///dag dag ulta
    glPushMatrix();
    glTranslatef(0,-4.9,0);
    glScalef(20,0.05,0.05);
    cube(0,0,0,0,0,0,0,0,0);  ///gray
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-4.9,3);
    glScalef(20,0.05,0.05);
    cube(0,0,0,0,0,0,0,0,0);  ///gray
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-4.9,6);
    glScalef(20,0.05,0.05);
    cube(0,0,0,0,0,0,0,0,0);  ///gray
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-4.9,9);
    glScalef(20,0.05,0.05);
    cube(0,0,0,0,0,0,0,0,0);  ///gray
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-4.9,12);
    glScalef(20,0.05,0.05);
    cube(0,0,0,0,0,0,0,0,0);  ///gray
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-4.9,-3);
    glScalef(20,0.05,0.05);
    cube(0,0,0,0,0,0,0,0,0);  ///gray
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-4.9,-6);
    glScalef(20,0.05,0.05);
    cube(0,0,0,0,0,0,0,0,0);  ///gray
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-4.9,-9);
    glScalef(20,0.05,0.05);
    cube(0,0,0,0,0,0,0,0,0);  ///gray
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-4.9,-12);
    glScalef(20,0.05,0.05);
    cube(0,0,0,0,0,0,0,0,0);  ///gray
    glPopMatrix();







}



void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    //glOrtho(0.0,2,0.0,2,0.0,1.0);
    //glFrustum(-6,6,-6,6, 1, 30);
    glFrustum(-3.4,3.4,-3,3,1.5,60);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt(eyeX,eyeY,eyeZ, lookX,lookY,lookZ, 0,1,0);

    glViewport(0, 0, windowHeight, windowWidth);
    glPushMatrix();
    //glRotatef(rotlimit,0,1,0);
    //fan();
    //fanUpy();
    //chair();
    //desk();
     //cabinet();
    glRotatef(rotlimS,0,1,0);
    //dias();
    //course_title_draw();
    //window();
    scene();

    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}


void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {
    case 's':
        rott = !rott;
        break;

    case 'x':
        chkx = !chkx;
        break;
    case 'y':
        chky = !chky;
        break;
    case 'z':
        chkz = !chkz;
        break;
    case 'c':
        chX = !chX;
        break;
    case 'u':
        chY = !chY;
        break;
    case 'v':
        chZ = !chZ;
        break;
    case 'r':
        scenerotY = !scenerotY;
        break;
    case 27:	// Escape key
        exit(1);
    }
}

void animate()
{
    if (rott)
    {
        rotlimit+= 0.5;
        if(rotlimit > 360)
            rotlimit = 0.0;
    }
    if (scenerotY)
    {
        rotlimS+= 0.5;

        if(rotlimS > 360)
            rotlimS = 0.0;

    }
    if (chkx)
    {
        eyeX = eyeX + 1;
        lookX = lookX + 1;
        chkx = false;
        cout<<eyeX<<" "<<eyeY<<" "<<eyeZ<<endl;
        cout<<lookX<<" "<<lookY<<" "<<lookZ<<endl;
    }
    if (chky)
    {
        eyeY = eyeY + 1;
        lookY = lookY + 1;
        chky = false;
        cout<<eyeX<<" "<<eyeY<<" "<<eyeZ<<endl;
        cout<<lookX<<" "<<lookY<<" "<<lookZ<<endl;
    }
    if (chkz)
    {
        eyeZ = eyeZ + 1;
        lookZ = lookZ + 1;
        chkz = false;
        cout<<eyeX<<" "<<eyeY<<" "<<eyeZ<<endl;
        cout<<lookX<<" "<<lookY<<" "<<lookZ<<endl;
    }
    if (chX)
    {
        eyeX = eyeX - 1;
        lookX = lookX - 1;
        chX = false;
        cout<<eyeX<<" "<<eyeY<<" "<<eyeZ<<endl;
        cout<<lookX<<" "<<lookY<<" "<<lookZ<<endl;
    }
    if (chY)
    {
        eyeY = eyeY - 1;
        lookY = lookY - 1;
        chY = false;
        cout<<eyeX<<" "<<eyeY<<" "<<eyeZ<<endl;
        cout<<lookX<<" "<<lookY<<" "<<lookZ<<endl;
    }
    if (chZ)
    {
        eyeZ = eyeZ - 1;
        lookZ = lookZ - 1;
        chZ = false;
        cout<<eyeX<<" "<<eyeY<<" "<<eyeZ<<endl;
        cout<<lookX<<" "<<lookY<<" "<<lookZ<<endl;
    }

    glutPostRedisplay();
}

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(0,0);
    glutInitWindowSize(windowHeight, windowWidth);
    glutCreateWindow("1607076-ClassRoom");

    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );
    glEnable(GL_NORMALIZE);
    glEnable(GL_BLEND);

    glutKeyboardFunc(myKeyboardFunc);
    glutDisplayFunc(display);
    glutIdleFunc(animate);


    glutMainLoop();

    return 0;
}
