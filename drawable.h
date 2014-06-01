#ifndef DRAWABLE_H
#define DRAWABLE_H

#include<QList>
#include <GL/glut.h>
#include <GL/glu.h>
#include "ast.h"

class Transform{
public:
    virtual void transform();
};

class Rotate: public Transform{
public:
    Rotate(angle,x,y,z){
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

class Scale: public Transform{
public:
    Scale(x,y,z){
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

class Translate: public Transform{
public:
    Translate(x,y,z){
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

class Drawable{
public:
    QList<Transform> trans;
    bool draw;
    bool fill;
    Color* drawColor;
    Color* fillColor;

    void Draw(){
        //Push model matrix
        glPushMatrix();

            //apply transformations for each matrix
            QList<Transform>::iterator i;
            for (i = trans.begin(); i != trans.end(); ++i){
                i->Transform();
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
    virtual void DrawShape();
    virtual void FillShape();
}

#endif // DRAWABLE_H
