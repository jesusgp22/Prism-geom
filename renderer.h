#ifndef RENDERER_H
#define RENDERER_H

#include<QDebug>
#include<QGLWidget>
#include "ast.h"

class ITransform{
public:
    virtual void Transform();
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
                qDebug()<<"aplicando una transformacion";
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

#endif // RENDERER_H
