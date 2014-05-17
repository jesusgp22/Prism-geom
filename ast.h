#ifndef AST_H
#define AST_H

#include<vector>
#include<QString>
#include<QHash>
#include<QDebug>
class Identifier;
extern QHash<QString, Identifier*> symbols;

enum DATATYPE{FLOAT_DT,VECT2_DT,VECT3_DT,COLOR_DT,POINT_DT,RECT_DT,CURVE_DT,PLANE_DT,TRIANGLE_DT,QUAD_DT,ELIPSE_DT,CIRC_DT,
              PARABOLE_DT,HYPERBOLE_DT,
             POLYHEDRON_DT,CILINDRE_DT,CONE_DT,SPHERE_DT,NONE_DT};

class Identifier{
public:

    enum ID_DIMENSION{GEOM2D,GEOM3D,NONE};
    Identifier(QString name,DATATYPE t){
        this->name=name;
        this->type=t;
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

class Vect{};

class Vect2d : public Vect{
public:
    Vect2d(float x,float y){this->x=x;this->y=y;}
    float x;
    float y;
};

class Vect3d : public Vect{
public:
    Vect3d(float x,float y,float z){this->x=x;this->y=y;this->z=z;}
    float x;
    float y;
    float z;
};

class Color{
public:
    Color(float r,float g,float b,float a){this->red=r;this->green=g;this->blue=b;this->alpha=a;}
    Color(QString* c)
    {
        if(c)
            this->alpha=0;

    }
    float red;
    float green;
    float blue;
    float alpha;
};

class Param{
public:
    DATATYPE type;
    bool isID;
};

class Vect2dParam : public Param{
public:
    Vect2dParam(Vect2d* v){this->v2d=v;type=VECT2_DT;this->isID=false;}
    Vect2d* v2d;
};

class Vect3dParam : public Param{
public:
    Vect3dParam(Vect3d* v){this->v3d=v;type=VECT3_DT;this->isID=false;}
    Vect3d* v3d;

};

class IdParam : public Param{
public:
    IdParam(QString* id){
        this->isID =true;
        if(symbols.contains(*id)){
            this->id=symbols.value(*id);
            this->type=this->id->type;
        }else{
            this->id=NULL;
            this->type=NONE_DT;
        }
    }
    Identifier* id;
};

class FloatParam : public Param{
public:
    FloatParam(float f){this->f=f;type=FLOAT_DT;this->isID=false;}
    float f;
};

class ColorParam : public Param{
public:
    ColorParam(Color* c){this->color = c;type=COLOR_DT;this->isID=false;}
    Color* color;
};


//ROOT CLASS

class Sentence{
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
    FloatDeclaration(QString*id,float fval){this->f=fval;this->id=id;}
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
};

class Background : public Function{
public:
    Background(Param* c){this->color=c;}
    Param* color;
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
