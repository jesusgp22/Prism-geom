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

    glViewport(0, 0, this->width(), this->height());
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); //carefull
    float aspect = (float)this->width() / (float)this->height();

    //if 2d scene
    //glOrtho(-aspect, aspect, -1, 1, -1, 1);


    //if 3d scene
    //allow for color material
    glEnable(GL_COLOR_MATERIAL);
    //reduce line width for 3d
    glLineWidth(2);

    //set up prespective
    //glFrustum(-aspect,aspect,-1,1,0.1,10);
    gluPerspective(90,aspect,1,3);

    //enable lightning
    glEnable(GL_LIGHTING);
    //set up the light
    GLfloat lightpos[] = {.5, 1., 1., 0.};
    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
    glEnable(GL_LIGHT0);

    drawAxes = true;

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


}

void Viewport::paintGL(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0,0,2,0,0,0,0,1,0);
    //DRAW AXES
    if(drawAxes){

        glBegin(GL_LINES);
            glColor3f(1,0.5,0.5);
            glVertex3f(-AXE_DRAW_DISTANCE,0,0);
            glVertex3f(AXE_DRAW_DISTANCE,0,0);
            glColor3f(0.5,1,0.5);
            glVertex3f(0,AXE_DRAW_DISTANCE,0);
            glVertex3f(0,-AXE_DRAW_DISTANCE,0);
            glColor3f(0.5,0.5,1);
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
