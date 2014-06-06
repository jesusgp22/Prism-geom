#ifndef RENDERER_H
#define RENDERER_H

#include<QGLWidget>
#include<QVector>
#include<QVector2D>
#include<vector>
#include "ast.h"
#include <cmath>
#include "spline.h"
#include <GL/glut.h>
#include <GL/glu.h>

#define PI 3.141592
#define NUM_STEPS 50

class ITransform{
public:
    virtual void Transform(){}
};

class IRotate: public ITransform{
public:
    IRotate(float angle,float x,float y,float z){
        this->angle = angle;
        this->x = x;
        this->y = y;
        this->z = z;
    }
    void Transform(){
        glRotatef(angle,x,y,z);
    }
    float angle;
    float x;
    float y;
    float z;
};

class IScale: public ITransform{
public:
    IScale(float x,float y,float z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
    void Transform(){
        glScalef(x,y,z);
    }
    float x;
    float y;
    float z;
};

class ITranslate: public ITransform{
public:
    ITranslate(float x,float y,float z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
    void Transform(){
        glTranslatef(x,y,z);
    }
    float x;
    float y;
    float z;
};

class Renderer{
public:
    Renderer(){
        draw = false;
        fill = false;
    }

    QList<ITransform*> trans;
    bool draw;
    bool fill;
    Color* drawColor;
    Color* fillColor;

    void Draw(){

        //Push model matrix
        glPushMatrix();
            //apply transformations for each matrix
            QList<ITransform*>::iterator i;
            for (i = trans.begin(); i != trans.end(); ++i){
                (*i)->Transform();
            }
            //draw shape
            if(draw){
                //set the draw color
                glColor4f(drawColor->red,drawColor->green,drawColor->blue,drawColor->alpha);
                DrawShape();
            }
            //fill shape
            if(fill){
                //set the fill color
                glColor4f(fillColor->red,fillColor->green,fillColor->blue,fillColor->alpha);
                FillShape();
            }

        //pop the model matrix
        glPopMatrix();
    }

    void AddTransform(ITransform* t){
        trans.append(t);
    }
    void AddDraw(Color* color){
        draw = true;
        drawColor = color;
    }
    void AddFill(Color* color){
        fill = true;
        fillColor = color;
    }

    virtual void DrawShape(){}
    virtual void FillShape(){}
};

class PointRenderer: public Renderer{
public:
    PointRenderer(Point *p){this->point = p;}
    Point* point;

    void DrawShape(){
        glBegin(GL_POINTS);
            glVertex2f(point->point->x,point->point->y);
        glEnd();
    }

    void FillShape(){
        DrawShape();
    }
};

class RectRenderer: public Renderer{
public:
    RectRenderer(Rect *p){this->rect = p;}
    Rect* rect;

    void DrawShape(){
        glBegin(GL_LINES);
            glVertex2f(rect->a->x,rect->a->y);
            glVertex2f(rect->b->x,rect->b->y);
        glEnd();
    }

    void FillShape(){
        DrawShape();
    }
};


class QuadRenderer: public Renderer{
public:
    QuadRenderer(Quad *p){this->quad = p;}
    Quad* quad;

    void DrawShape(){
        glBegin(GL_LINES);
            glVertex2f(quad->a->x,quad->a->y);
            glVertex2f(quad->b->x,quad->b->y);

            glVertex2f(quad->b->x,quad->b->y);
            glVertex2f(quad->c->x,quad->c->y);

            glVertex2f(quad->c->x,quad->c->y);
            glVertex2f(quad->d->x,quad->d->y);

            glVertex2f(quad->a->x,quad->a->y);
            glVertex2f(quad->d->x,quad->d->y);
        glEnd();
    }

    void FillShape(){
        glBegin(GL_QUADS);
            glVertex2f(quad->a->x,quad->a->y);
            glVertex2f(quad->b->x,quad->b->y);
            glVertex2f(quad->c->x,quad->c->y);
            glVertex2f(quad->d->x,quad->d->y);
        glEnd();
    }
};

class TriangleRenderer: public Renderer{
public:
    TriangleRenderer(Triangle *p){this->triangle = p;}
    Triangle* triangle;

    void DrawShape(){
        glBegin(GL_LINES);
            glVertex2f(triangle->a->x,triangle->a->y);
            glVertex2f(triangle->b->x,triangle->b->y);

            glVertex2f(triangle->b->x,triangle->b->y);
            glVertex2f(triangle->c->x,triangle->c->y);

            glVertex2f(triangle->a->x,triangle->a->y);
            glVertex2f(triangle->c->x,triangle->c->y);
        glEnd();
    }

    void FillShape(){
        glBegin(GL_TRIANGLES);
            glVertex2f(triangle->a->x,triangle->a->y);
            glVertex2f(triangle->b->x,triangle->b->y);
            glVertex2f(triangle->c->x,triangle->c->y);
        glEnd();
    }
};

class ElipseRenderer: public Renderer{
public:
    ElipseRenderer(Elipse *p){this->elipse = p;initialized=false;}
    Elipse* elipse;
    bool initialized;
    QVector<QVector2D*> verts;

    void Init(){
        initialized = true;
        float x;
        float y;
        float stepSize;
        stepSize = 2*PI/NUM_STEPS;
        for(int i=0;i<NUM_STEPS;i++){
            float t = stepSize*i;
            x = elipse->width*cos(t)+elipse->center->x;
            y = elipse->height*sin(t)+elipse->center->y;
            verts.append(new QVector2D(x,y));
        }
    }

    void DrawShape(){
        if(!initialized){
            Init();
        }
        glBegin(GL_LINE_LOOP);
            for(int i=0;i<verts.size();i++){
                glVertex2f(verts[i]->x(),verts[i]->y());
            }
        glEnd();

    }

    void FillShape(){
        if(!initialized){
            Init();
        }
        glBegin(GL_TRIANGLE_FAN);
            //glVertex2f(elipse->center->x,elipse->center->y);
            for(int i=0;i<verts.size();i++){
                glVertex2f(verts[i]->x(),verts[i]->y());
            }
        glEnd();

    }
};

class CircRenderer: public Renderer{
public:
    CircRenderer(Circ* c){this->circle=c; initialized=false;}
    Circ* circle;
    bool initialized;
    QVector<QVector2D*> verts;

    void Init(){
        initialized = true;
        float x;
        float y;
        float stepSize;
        stepSize = 2*PI/NUM_STEPS;
        for(int i=0;i<NUM_STEPS;i++){
            float t = stepSize*i;
            x = circle->radius*cos(t)+circle->center->x;
            y = circle->radius*sin(t)+circle->center->y;
            verts.append(new QVector2D(x,y));
        }
    }

    void DrawShape(){
        if(!initialized){
            Init();
        }
        glBegin(GL_LINE_LOOP);
            for(int i=0;i<verts.size();i++){
                glVertex2f(verts[i]->x(),verts[i]->y());
            }
        glEnd();

    }

    void FillShape(){
        if(!initialized){
            Init();
        }
        glBegin(GL_TRIANGLE_FAN);
            for(int i=0;i<verts.size();i++){
                glVertex2f(verts[i]->x(),verts[i]->y());
            }
        glEnd();

    }
};

class ParaboleRenderer: public Renderer{
public:
    ParaboleRenderer(Parabole* c){this->parabole=c; initialized=false;}
    Parabole* parabole;
    bool initialized;
    QVector<QVector2D*> verts;

    void Init(){
        initialized = true;
        float x;
        float y;
        float stepSize;

        GLint m_viewport[4];
        //this call should be avoided and replaced by variables
        glGetIntegerv( GL_VIEWPORT, m_viewport );

        float startPoint = (float)m_viewport[2]/(float)m_viewport[3];

        stepSize = startPoint*2/NUM_STEPS; //integration range between num steps

        for(int i=0;i<=NUM_STEPS;i++){
            float t = (-startPoint)+stepSize*i; //start integration from -1
            x = t+parabole->minPoint->x;
            y = t*t*parabole->factor+parabole->minPoint->y;
            verts.append(new QVector2D(x,y));
        }
    }

    void DrawShape(){
        if(!initialized){
            Init();
        }
        glBegin(GL_LINE_STRIP);
            for(int i=0;i<verts.size();i++){
                glVertex2f(verts[i]->x(),verts[i]->y());
            }
        glEnd();

    }

    void FillShape(){
        if(!initialized){
            Init();
        }
        glBegin(GL_TRIANGLE_FAN);
            for(int i=0;i<verts.size();i++){
                glVertex2f(verts[i]->x(),verts[i]->y());
            }
        glEnd();

    }
};

class HyperboleRenderer: public Renderer{
public:
    HyperboleRenderer(Hyperbole* c){this->hyperbole=c; initialized=false;}
    Hyperbole* hyperbole;
    bool initialized;
    QVector<QVector2D*> vertsUpper;
    QVector<QVector2D*> vertsLower;

    void Init(){
        //this function works with a little math magic and a lot of unstable stuff, threat with extreme caution
        initialized = true;
        float x;
        float y;
        float stepSize;

        //t ranges between pi and -pi
        stepSize = 2*PI/NUM_STEPS;

        for(int i=0;i<=NUM_STEPS;i++){
            float t = -PI + stepSize*i;
            x = hyperbole->a*cosh(t);
            y = hyperbole->b*sinh(t);
            vertsUpper.append(new QVector2D(x,y));
            x = -x;
            vertsLower.append(new QVector2D(x,y));
        }
    }

    void DrawShape(){
        if(!initialized){
            Init();
        }
        glBegin(GL_LINE_STRIP);
            for(int i=0;i<vertsUpper.size();i++){
                glVertex2f(vertsUpper[i]->x(),vertsUpper[i]->y());
            }
        glEnd();
        glBegin(GL_LINE_STRIP);
            for(int i=0;i<vertsLower.size();i++){
                glVertex2f(vertsLower[i]->x(),vertsLower[i]->y());
            }
        glEnd();

    }

    void FillShape(){
        if(!initialized){
            Init();
        }
        glBegin(GL_TRIANGLE_FAN);
            for(int i=0;i<vertsUpper.size();i++){
                glVertex2f(vertsUpper[i]->x(),vertsUpper[i]->y());
            }
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
            for(int i=0;i<vertsLower.size();i++){
                glVertex2f(vertsLower[i]->x(),vertsLower[i]->y());
            }
        glEnd();

    }
};

class CurveRenderer: public Renderer{
public:
    CurveRenderer(Curve* c){this->curve=c; initialized=false;}
    Curve* curve;
    bool initialized;
    QVector<QVector2D*> verts;

    void Init(){
        //this function might be easily changed for more than three point splines!
        initialized = true;

        //spline calculation
        vector<double> xs;
        xs.push_back(curve->a->x);
        xs.push_back(curve->b->x);
        xs.push_back(curve->c->x);
        vector<double> ys;
        ys.push_back(curve->a->y);
        ys.push_back(curve->b->y);
        ys.push_back(curve->c->y);

        vector<SplineSet> cs = CalculateSpline(xs,ys);

        //vertex calculation
        float x,y,t;
        float numSteps = 5;
        float stepSize;

        for(int i=0;i<cs.size();i++){
            qDebug()<<cs[i].d<<cs[i].c<<cs[i].b<<cs[i].a<<cs[i].x;
            stepSize = 0.4/numSteps;
            for(int j=0;j<numSteps;j++){
                t = j*stepSize;
                x = j*stepSize+i*0.4;
                y = cs[i].d*(t*t*t) + cs[i].c*t*t + cs[i].b*t + cs[i].a;
                qDebug()<<t<<","<<y;
                verts.append(new QVector2D(x,y));
            }
        }
    }

    void DrawShape(){
        if(!initialized){
            Init();
        }
        glBegin(GL_LINE_STRIP);
            for(int i=0;i<verts.size();i++){
                glVertex2f(verts[i]->x(),verts[i]->y());
            }
        glEnd();

    }

    void FillShape(){
        DrawShape();
    }
};

class ConeRenderer: public Renderer{
public:
    ConeRenderer(Cone* c){this->cone=c;}
    Cone* cone;

    void DrawShape(){
        glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
        glPushMatrix();
            glTranslatef(cone->center->x,cone->center->y,cone->center->z);
            glutWireCone(cone->radius,cone->height,NUM_STEPS,1);
        glPopMatrix();
    }

    void FillShape(){
        glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
        glPushMatrix();
            glTranslatef(cone->center->x,cone->center->y,cone->center->z);
            glutSolidCone(cone->radius,cone->height,NUM_STEPS,1);
        glPopMatrix();
    }
};

class SphereRenderer: public Renderer{
public:
    SphereRenderer(Sphere* c){this->sphere=c;}
    Sphere* sphere;

    void DrawShape(){
        glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
        glPushMatrix();
            glTranslatef(sphere->center->x,sphere->center->y,sphere->center->z);
            glutWireSphere(sphere->radius,NUM_STEPS,NUM_STEPS);
        glPopMatrix();
    }

    void FillShape(){
        glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
        glPushMatrix();
            glTranslatef(sphere->center->x,sphere->center->y,sphere->center->z);
            glutSolidSphere(sphere->radius,NUM_STEPS/2,NUM_STEPS/2);
        glPopMatrix();
    }
};

class CylinderRenderer: public Renderer{
public:
    CylinderRenderer(Cylindre* c){this->cylindre=c;}
    Cylindre* cylindre;

    void DrawShape(){
        glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
        glPushMatrix();
            glTranslatef(cylindre->center->x,cylindre->center->y,cylindre->center->z);
            GLUquadric* q = gluNewQuadric();
            gluQuadricDrawStyle(q,GLU_LINE);
            gluCylinder(q,cylindre->radius,cylindre->radius,cylindre->height,NUM_STEPS/2,1);
        glPopMatrix();
    }

    void FillShape(){
        glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
        glPushMatrix();
            glTranslatef(cylindre->center->x,cylindre->center->y,cylindre->center->z);
            GLUquadric* q = gluNewQuadric();
            gluQuadricDrawStyle(q,GLU_FILL);
            gluCylinder(q,cylindre->radius,cylindre->radius,cylindre->height,NUM_STEPS/2,1);
        glPopMatrix();
    }
};

class PlaneRenderer: public Renderer{
public:
    PlaneRenderer(Plane* c){this->plane=c;this->plane->side=this->plane->side/2;}
    Plane* plane;

    void DrawShape(){

        glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
        glBegin(GL_LINE_LOOP);
            glNormal3f(0,1,0);
            glVertex3f(plane->center->x-plane->side,plane->center->y,plane->center->z+plane->side);
            glVertex3f(plane->center->x+plane->side,plane->center->y,plane->center->z+plane->side);
            glVertex3f(plane->center->x+plane->side,plane->center->y,plane->center->z-plane->side);
            glVertex3f(plane->center->x-plane->side,plane->center->y,plane->center->z-plane->side);
        glEnd();
    }

    void FillShape(){
        glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
        glBegin(GL_TRIANGLE_FAN);
            glNormal3f(0,1,0);
            glVertex3f(plane->center->x-plane->side,plane->center->y,plane->center->z+plane->side);
            glVertex3f(plane->center->x+plane->side,plane->center->y,plane->center->z+plane->side);
            glVertex3f(plane->center->x+plane->side,plane->center->y,plane->center->z-plane->side);
            glVertex3f(plane->center->x-plane->side,plane->center->y,plane->center->z-plane->side);
        glEnd();
    }
};

#endif // RENDERER_H
