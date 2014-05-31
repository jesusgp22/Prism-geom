#include "viewport.h"
#include <QDebug>
#include <GL/glut.h>
#include <GL/glu.h>

#define AXE_DRAW_DISTANCE 1000

Viewport::Viewport(QWidget *parent) :
    QGLWidget(parent)
{
}

QSize Viewport::minimumSizeHint() const{
    return QSize(100,100);
}

QSize Viewport::sizeHint() const{
    return QSize(400,400);
}

Viewport::~Viewport(){
}

void Viewport::initializeGL(){

    glClearColor(0,0,0,1);
    glFrustum(10,10,10,10,3,1000);

}

void Viewport::paintGL(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

//    gluLookAt( 0,0,-10,
//               0,0,0,
//               0,1,0
//                );

    //DRAW AXES
    glBegin(GL_LINES);
        glVertex3f(-AXE_DRAW_DISTANCE,0,0);
        glVertex3f(AXE_DRAW_DISTANCE,0,0);

        glVertex3f(0,AXE_DRAW_DISTANCE,0);
        glVertex3f(0,-AXE_DRAW_DISTANCE,0);

        glVertex3f(0,0,AXE_DRAW_DISTANCE);
        glVertex3f(0,0,-AXE_DRAW_DISTANCE);
    glEnd();

    glutSolidCube(1);

}

void Viewport::resizeGL(int w, int h){
    qDebug()<<w<<" , "<<h;
}
