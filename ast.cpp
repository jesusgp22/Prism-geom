#include "ast.h"
#include "viewport.h"
#include "renderer.h"
#include <QDebug>

void Declaration::GenerateCode(Viewport *v){
    Identifier *i = symbols.value(*id);
    switch(i->type){
        case POINT_DT:
        {
            Point* p = (Point*)i->value;
            Renderer* r = new PointRenderer(p);
            v->addRenderer(*id,r);
            break;
        }
        case RECT_DT:
        {
            Rect* p = (Rect*)i->value;
            Renderer* r = new RectRenderer(p);
            v->addRenderer(*id,r);
            break;
        }
        case TRIANGLE_DT:
        {
            Triangle* p = (Triangle*)i->value;
            Renderer* r = new TriangleRenderer(p);
            v->addRenderer(*id,r);
            break;
        }
        case QUAD_DT:
        {
            Quad* p = (Quad*)i->value;
            Renderer* r = new QuadRenderer(p);
            v->addRenderer(*id,r);
            break;
        }
        default:
            qDebug()<<"Nada que hacer para este tipo de dato";
            break;
    }
}

void Draw::GenerateCode(Viewport *v){
    Color *c = (Color*)color->value;
    v->addDraw(*id,c);
}

void Fill::GenerateCode(Viewport *v){
    Color *c = (Color*)color->value;
    v->addFill(*id,c);
}

void Background::GenerateCode(Viewport *v){
    Color* c;
    if(color->type==COLOR_DT)
        c = (Color*)color->value;
    else
        c = new Color(0,0,0,1);
    v->setBackgroundColor(c);
}