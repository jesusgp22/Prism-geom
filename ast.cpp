#include "ast.h"
#include "viewport.h"

void Background::GenerateCode(Viewport *v){
    Color* c;
    if(color->type==COLOR_DT)
        c = (Color*)color->value;
    else
        c = new Color(0,0,0,1);
    v->setBackgroundColor(c);
}
