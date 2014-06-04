#include "viewport.h"
#include <QDebug>
#include <GL/glut.h>
#include <GL/glu.h>
#include "ast.h"
#include "renderer.h"

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

    //clear color
    glClearColor(backgroundColor->red,backgroundColor->green,backgroundColor->blue,1);

    //allow drawing polygons no matter where they face
    glDisable(GL_CULL_FACE);

    //allow depth testing ?
    //glEnable( GL_DEPTH_TEST);

    //allow color alpha blending
    glEnable( GL_BLEND );
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //set up point and line size
    glPointSize(3);
    glLineWidth(2);

    //antialising settings
    glEnable( GL_LINE_SMOOTH );
    glEnable( GL_POLYGON_SMOOTH );
    glHint( GL_LINE_SMOOTH_HINT, GL_NICEST );
    glHint( GL_POLYGON_SMOOTH_HINT, GL_NICEST );

    //if 2d scene
    glViewport(0, 0, this->width(), this->height());
    glMatrixMode(GL_PROJECTION);
    float aspect = (float)this->width() / (float)this->height();
    glOrtho(-aspect, aspect, -1, 1, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void Viewport::paintGL(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
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

    glMatrixMode(GL_MODELVIEW_MATRIX);
    QHash<QString, Renderer*>::iterator i;
    for (i = renderers.begin(); i != renderers.end(); ++i){
        i.value()->Draw();
    }
}

void Viewport::resizeGL(int w, int h){
    //if 2d scene
//    glViewport(0, 0, w, h);
//    glMatrixMode(GL_PROJECTION);
//    float aspect = w / h;
//    glOrtho(-aspect, aspect, -1, 1, -1, 1);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
}

void Viewport::setBackgroundColor(Color *c){
    this->backgroundColor = c;
}

void Viewport::addRenderer(QString id,Renderer* renderer){
    if(renderers.contains(id)){
        qDebug()<<"Error id ya existe";
        return;
    }
    renderers.insert(id,renderer);
}

void Viewport::addDraw(QString id,Color* c){
    if(renderers.contains(id))
        renderers.value(id)->AddDraw(c);
    else
        qDebug()<<"Error: el id especificado no esta en la tabla de simbolos";
}
void Viewport::addFill(QString id,Color* c){
    if(renderers.contains(id))
        renderers.value(id)->AddFill(c);
    else
        qDebug()<<"Error: el id especificado no esta en la tabla de simbolos";
}
void Viewport::addTransform(QString id,ITransform* t){
    if(renderers.contains(id))
        renderers.value(id)->AddTransform(t);
    else
        qDebug()<<"Error: el id especificado no esta en la tabla de simbolos";
}
