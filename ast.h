#ifndef AST_H
#define AST_H

#include<vector>
#include<QString>
#include<QHash>
#include<QDebug>
#include"viewport.h"

//SYMBOL TABLE
class Identifier;
extern QHash<QString, Identifier*> symbols;

//DATA TYPES
enum DATATYPE{FLOAT_DT,VECT2_DT,VECT3_DT,COLOR_DT,POINT_DT,RECT_DT,CURVE_DT,PLANE_DT,TRIANGLE_DT,QUAD_DT,ELIPSE_DT,CIRC_DT,
              PARABOLE_DT,HYPERBOLE_DT,
              POLYHEDRON_DT,CILINDRE_DT,CONE_DT,SPHERE_DT,NONE_DT};

class DataType{
public:
    virtual QString getValueString(){
        return "Undefined";
    }
};

//INDENTIFIER CLASS
class Identifier{
public:

    enum ID_DIMENSION{GEOM2D,GEOM3D,NONE};
    Identifier(QString name,DATATYPE t,DataType * value){
        this->name=name;
        this->type=t;
        this->value = value;
        if(t==VECT2_DT||t==POINT_DT||t==RECT_DT||t==CURVE_DT||t==PLANE_DT||t==TRIANGLE_DT||t==QUAD_DT
                ||t==ELIPSE_DT||t==CIRC_DT||t==PARABOLE_DT||t==HYPERBOLE_DT)
        {
            this->dimension=GEOM2D;
        }else if(t==VECT3_DT||t==POLYHEDRON_DT||t==CILINDRE_DT||t==CONE_DT||t==SPHERE_DT)
        {
            this->dimension=GEOM3D;
        }
        else
        {
            this->dimension=NONE;
        }
        referenced=false;
    }
    DATATYPE type;
    ID_DIMENSION dimension;
    QString name;
    bool referenced;
    DataType * value;
    QString type_string(){
        switch (type) {
        case FLOAT_DT:
            return "Flotante";
        case VECT2_DT:
            return "Vector2d";
        case VECT3_DT:
            return "Vector3d";
        case COLOR_DT:
            return "Color";
        case POINT_DT:
            return "Punto";
        case RECT_DT:
            return "Recta";
        case CURVE_DT:
            return "Curva";
        case PLANE_DT:
            return "Plano";
        case TRIANGLE_DT:
            return "Triangulo";
        case QUAD_DT:
            return "Cuadrilatero";
        case ELIPSE_DT:
            return "Elipse";
        case CIRC_DT:
            return "Circunferencia";
        case PARABOLE_DT:
            return "Parabola";
        case HYPERBOLE_DT:
            return "Hiperbola";
        case POLYHEDRON_DT:
            return "Poliedro";
        case CONE_DT:
            return "Cono";
        case SPHERE_DT:
            return "Esfera";
        default:
            return "ERROR";
        }
    }
    QString dimension_string(){
        switch (dimension) {
        case GEOM2D:
            return "GEOM2D::";
        case GEOM3D:
            return "GEOM3D::";
        default:
            return "";
        }
    }
};

//BASIC DATA TYPE CLASSES

class Float: public DataType{
public:
    Float(float f){this->f=f;}
    float f;
    QString getValueString(){
        return QString::number(f);
    }
};

class Vect: public DataType{};

class Vect2d : public Vect{
public:
    Vect2d(float x,float y){this->x=x;this->y=y;}
    float x;
    float y;
    QString getValueString(){
        return "("+QString::number(x)+" , "+QString::number(y)+")";
    }
};

class Vect3d : public DataType{
public:
    Vect3d(float x,float y,float z){this->x=x;this->y=y;this->z=z;}
    float x;
    float y;
    float z;
    QString getValueString(){
        return "("+QString::number(x)+" , "+QString::number(y)+" , "+QString::number(z)+")";
    }
};

class Color : public DataType{
public:
    Color(float r,float g,float b,float a){this->red=r;this->green=g;this->blue=b;this->alpha=a;}
    Color(QString* c){
        this->alpha=0;
        QString name=*c;
        if(name=="NEGRO"){
            this->red=0;
            this->green=0;
            this->blue=0;
        }else if(name=="AZUL"){
            this->red=0;
            this->green=0;
            this->blue=255;
        }else if(name=="CIAN"){
            this->red=0;
            this->green=176;
            this->blue=246;
        }else if(name=="GIS"){
            this->red=152;
            this->green=152;
            this->blue=152;
        }else if(name=="VERDE"){
            this->red=0;
            this->green=255;
            this->blue=0;
        }else if(name=="MAGENTA"){
            this->red=245;
            this->green=0;
            this->blue=135;
        }else if(name=="NARANJA"){
            this->red=230;
            this->green=95;
            this->blue=0;
        }else if(name=="ROSADO"){
            this->red=247;
            this->green=191;
            this->blue=190;
        }else if(name=="ROJO"){
            this->red=255;
            this->green=0;
            this->blue=0;
        }else if(name=="BLANCO"){
            this->red=1;
            this->green=1;
            this->blue=1;
        }else if(name=="AMARILLO"){
            this->red=255;
            this->green=233;
            this->blue=0;
        }
    }

    float red;
    float green;
    float blue;
    float alpha;

    QString getValueString(){
        return "r:"+QString::number(red)+" g:"+QString::number(green)+" b:"+QString::number(blue)+" a:"+QString::number(alpha);
    }
};

class Param{
public:
    Param()
    {
        this->type=NONE_DT;
    }

    Param(DATATYPE type, void* value){
        this->type=type;
        this->value=value;
    }
    Param(QString* id){
        Identifier* identifier =  symbols[*id];
        this->type=identifier->type;
        this->value=identifier->value;
    }
    DATATYPE type;
    void * value;
};

class Point: public DataType{
public:
    Point(Param *p){
        if(p->type==VECT2_DT)
        point = (Vect2d*)p->value;
    }
    Vect2d* point;
    QString getValueString(){
        return "posicion: "+point->getValueString();
    }
};

class Rect: public DataType{
public:
    Rect(Param *p1,Param *p2){
        if(p1->type==VECT2_DT)
            this->a = (Vect2d*)p1->value;
        if(p2->type==VECT2_DT)
            this->b = (Vect2d*)p2->value;
    }
    Vect2d* a;
    Vect2d* b;
    QString getValueString(){
        return "punto a: "+a->getValueString()+" punto b: "+b->getValueString();
    }
};

class Curve: public DataType{
public:
    Curve(Param *p1,Param *p2,Param *p3){
        if(p1->type==VECT2_DT)
            this->a = (Vect2d*)p1->value;
        if(p2->type==VECT2_DT)
            this->b = (Vect2d*)p2->value;
        if(p2->type==VECT2_DT)
            this->c = (Vect2d*)p3->value;
    }
    Vect2d* a;
    Vect2d* b;
    Vect2d* c;
    QString getValueString(){
        return "punto a: "+a->getValueString()+" punto b: "+b->getValueString()+" punto c: "+c->getValueString();
    }
};


class Plane: public DataType{
public:
    Plane(Param *p1,Param *p2,Param *p3){
        if(p1->type==VECT3_DT)
            this->a = (Vect3d*)p1->value;
        if(p2->type==VECT3_DT)
            this->b = (Vect3d*)p2->value;
        if(p3->type==VECT3_DT)
            this->c = (Vect3d*)p3->value;
    }
    Vect3d* a;
    Vect3d* b;
    Vect3d* c;
    QString getValueString(){
        return "punto a: "+a->getValueString()+" punto b: "+b->getValueString()+" punto c: "+c->getValueString();
    }
};

class Triangle: public DataType{
public:
    Triangle(Param *p1,Param *p2,Param *p3){
        if(p1->type==VECT2_DT)
            this->a = (Vect2d*)p1->value;
        if(p2->type==VECT2_DT)
            this->b = (Vect2d*)p2->value;
        if(p2->type==VECT2_DT)
            this->c = (Vect2d*)p3->value;
    }
    Vect2d* a;
    Vect2d* b;
    Vect2d* c;

    QString getValueString(){
        return "vert a: "+a->getValueString()+" vert b: "+b->getValueString()+" vert c: "+c->getValueString();
    }

};

class Quad: public DataType{
public:
    Quad(Param *p1,Param *p2,Param *p3,Param *p4){
        if(p1->type==VECT2_DT)
            this->a = (Vect2d*)p1->value;
        if(p2->type==VECT2_DT)
            this->b = (Vect2d*)p2->value;
        if(p2->type==VECT2_DT)
            this->c = (Vect2d*)p3->value;
        if(p2->type==VECT2_DT)
            this->d = (Vect2d*)p4->value;
    }
    Vect2d* a;
    Vect2d* b;
    Vect2d* c;
    Vect2d* d;

    QString getValueString(){
        return "vert a: "+a->getValueString()+" vert b: "+b->getValueString()+" vert c: "+c->getValueString()+" vert d: "+d->getValueString();
    }

};


class Elipse: public DataType{
public:
    Elipse(Param *p1,Param *p2,Param *p3){
        if(p1->type==VECT2_DT)
            this->center = (Vect2d*)p1->value;
        if(p2->type==FLOAT_DT)
            this->width = ((Float*)p2->value)->f;
        if(p2->type==FLOAT_DT)
            this->height = ((Float*)p3->value)->f;
    }
    Vect2d* center;
    float width;
    float height;

    QString getValueString(){
        return "centro: "+center->getValueString()+" ancho: "+QString::number(width)+" altura: "+QString::number(height);
    }

};

class Circ: public DataType{
public:
    Circ(Param *p1,Param *p2){
        if(p1->type==VECT2_DT)
            this->center = (Vect2d*)p1->value;
        if(p2->type==FLOAT_DT)
            this->radius = ((Float*)p2->value)->f;
    }
    Vect2d* center;
    float radius;

    QString getValueString(){
        return "centro: "+center->getValueString()+" radio: "+QString::number(radius);
    }

};

class Parabole: public DataType{
public:
    Parabole(Param *p1,Param *p2){
        if(p1->type==VECT2_DT)
            this->yCutPoint = (Vect2d*)p1->value;
        if(p2->type==FLOAT_DT)
            this->factor = ((Float*)p2->value)->f;
    }
    Vect2d* yCutPoint;
    float factor;

    QString getValueString(){
        return "punto minimo: "+yCutPoint->getValueString()+" factor multiplicativo: "+QString::number(factor);
    }

};


class Hyperbole: public DataType{
public:
    Hyperbole(Param *p1,Param *p2){
        if(p1->type==VECT2_DT)
            this->yCutPoint = (Vect2d*)p1->value;
        if(p2->type==FLOAT_DT)
            this->factor = ((Float*)p2->value)->f;
    }
    Vect2d* yCutPoint;
    float factor;

    QString getValueString(){
        return "punto minimo: "+yCutPoint->getValueString()+" factor multiplicativo: "+QString::number(factor);
    }
};


class Cilindre: public DataType{
public:
    Cilindre(Param *p1,Param *p2,Param *p3){
        if(p1->type==VECT3_DT)
            this->center = (Vect3d*)p1->value;
        if(p2->type==FLOAT_DT)
            this->height = ((Float*)p2->value)->f;
        if(p3->type==FLOAT_DT)
            this->radius = ((Float*)p3->value)->f;
    }
    Vect3d* center;
    float height;
    float radius;

    QString getValueString(){
        return "centro de la base: "+center->getValueString()+" altura: "+QString::number(height)+" radio: "+QString::number(radius);
    }

};

class Cone: public DataType{
public:
    Cone(Param *p1,Param *p2,Param *p3){
        if(p1->type==VECT3_DT)
            this->center = (Vect3d*)p1->value;
        if(p2->type==FLOAT_DT)
            this->height = ((Float*)p2->value)->f;
        if(p3->type==FLOAT_DT)
            this->radius = ((Float*)p3->value)->f;
    }
    Vect3d* center;
    float height;
    float radius;

    QString getValueString(){
        return "centro de la base: "+center->getValueString()+" altura: "+QString::number(height)+" radio: "+QString::number(radius);
    }

};

class Sphere: public DataType{
public:
    Sphere(Param *p1,Param *p2){
        if(p1->type==VECT3_DT)
            this->center = (Vect3d*)p1->value;
        if(p2->type==FLOAT_DT)
            this->radius = ((Float*)p2->value)->f;
    }
    Vect3d* center;
    float radius;

    QString getValueString(){
        return "centro de la base: "+center->getValueString()+" radio: "+QString::number(radius);
    }

};


class Polyhedron: public DataType{
public:
    Polyhedron(Param *p1,Param *p2){
        if(p1->type==FLOAT_DT)
            this->n = ((Float*)p1->value)->f;
        if(p2->type==FLOAT_DT)
            this->m = ((Float*)p2->value)->f;
    }
    float n;
    float m;

    QString getValueString(){
        return "num caras: "+QString::number(n)+" num lados: "+QString::number(m);
    }

};

class Sentence{
public:
    virtual void GenerateCode(Viewport* v){  }
};

class Root {
public:
    Root(std::vector<Sentence*>* list){this->sentence_list=list;}
    std::vector<Sentence*> *sentence_list;
};

//DECLARATION CLASSES:

class Declaration : public Sentence{
public:
    QString* id;
};

class FloatDeclaration : public Declaration{
public:
    FloatDeclaration(QString* id,float fval){this->f=fval;this->id=id;}
    float f;
};

class Vect2dDeclaration : public Declaration{
public:
    Vect2dDeclaration(QString*id,Vect2d *v2d){this->id=id;this->v2d=v2d;}
    Vect2d *v2d;
};

class Vect3dDeclaration : public Declaration{
public:
    Vect3dDeclaration(QString*id,Vect3d *v3d){this->id=id;this->v3d=v3d;}
    Vect3d *v3d;
};

class ColorDeclaration : public Declaration{
public:
    ColorDeclaration(QString*id,Color *c){this->id=id;this->color=c;}
    Color *color;
};

class PointDeclaration : public Declaration{
public:
    PointDeclaration(QString*id,Param* p){this->id=id;this->p=p;}
    Param* p;
};

class RectDeclaration : public Declaration{
public:
    RectDeclaration(QString*id,Param *a,Param *b){this->id=id;this->a=a;this->b=b;}
    Param *a;
    Param *b;

};



//ASIGNATION CLASSES

class Expresion{
};

class Asignation : public Sentence{
public:
    Asignation(QString*id,Expresion* exp){this->id=id;this->exp=exp;}
    QString* id;
    Expresion *exp;
};

class ParamExpresion : public Expresion{
public:
    ParamExpresion(Param* p){this->p=p;}
    Param* p;
};

class Plus : public Expresion{
public:
    Plus(Param *a,Param* b){this->a=a;this->b=b;}
    Param* a;
    Param* b;
};

class Less : public Expresion{
public:
    Less(Param *a,Param* b){this->a=a;this->b=b;}
    Param* a;
    Param* b;
};

class Times : public Expresion{
public:
    Times(Param *a,Param* b){this->a=a;this->b=b;}
    Param* a;
    Param* b;
};

class Division : public Expresion{
public:
    Division(Param *a,Param* b){this->a=a;this->b=b;}
    Param* a;
    Param* b;
};

//FUNCTION CLASSES

class Function : public Sentence{
};

class Draw : public Function{
public:
    Draw(QString*id,Param* c){this->id=id;this->color=c;}
    QString*id;
    Param* color;
    void GenerateCode(Viewport *v){
        Color *c = (Color*)color->value;
        qDebug()<<"dibujando el id"<<*id<<"con color: "<<c->getValueString();
        Identifier *i = symbols.value(*id);
    }
};

class Background : public Function{
public:
    Background(Param* c){this->color=c;}
    Param* color;
    void GenerateCode(Viewport *v);
};

class Fill : public Function{
public:
    Fill(QString*id,Param* c){this->id=id;this->color=c;}
    QString*id;
    Param* color;
};

class Translate : public Function{
public:
    Translate(QString*id,Param* v){this->id=id;this->vect=v;}
    QString*id;
    Param* vect;
};

class Rotate : public Function{
public:
    Rotate(QString*id,Param* ax,Param *an){this->id=id;this->axis=ax;this->angle=an;}
    QString*id;
    Param* axis;
    Param* angle;
};

class Scale : public Function{
public:
    Scale(QString*id,Param* v){this->id=id;this->vect=v;}
    QString*id;
    Param* vect;
};

#endif // AST_H
