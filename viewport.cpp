#include "viewport.h"
#include <QDebug>
#include <GL/glut.h>
#include <GL/glu.h>
#include "ast.h"

#define AXE_DRAW_DISTANCE 1000

Viewport::Viewport(QWidget *parent) :
    QGLWidget(parent)
{
    drawAxes = true;
    backgroundColor = new Color(1,1,1,1);
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

    glClearColor(backgroundColor->red,backgroundColor->green,backgroundColor->blue,1);
    //glEnable(GL_DEPTH_TEST);
    glEnable( GL_BLEND );
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);



}

void Viewport::paintGL(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    //DRAW AXES
    if(drawAxes){
        glColor3f(1,1,1);
        glBegin(GL_LINES);
            glVertex3f(-AXE_DRAW_DISTANCE,0,0);
            glVertex3f(AXE_DRAW_DISTANCE,0,0);

            glVertex3f(0,AXE_DRAW_DISTANCE,0);
            glVertex3f(0,-AXE_DRAW_DISTANCE,0);

            glVertex3f(0,0,AXE_DRAW_DISTANCE);
            glVertex3f(0,0,-AXE_DRAW_DISTANCE);
        glEnd();
    }


    glColor4f(1,0,0,1);
    glBegin(GL_TRIANGLES);
        glVertex3d(0,0,0);
        glVertex3d(0,0.5,0);
        glVertex3d(0.5,0,0);
    glEnd();

    glMatrixMode(GL_MODELVIEW_MATRIX);
    glPushMatrix();
    glRotatef(45,0,0,1);
    glTranslatef(0.1,0.1,0);
    glScalef(0.5,0.5,0.5);
        glPointSize(3);
        glColor4f(0,1,0,0.5);
        glBegin(GL_TRIANGLES);
            glVertex3d(0,0,0);
            glVertex3d(0,0.5,0);
            glVertex3d(0.5,0,0);
        glEnd();
    glPopMatrix();

}

void Viewport::resizeGL(int w, int h){
    qDebug()<<w<<" , "<<h;
}

void Viewport::setBackgroundColor(Color *c){
    this->backgroundColor = c;
}
