%{
    #include <stdio.h>
    #include <QDebug>
    #include <QString>
    #include <QHash>
    #include "ast.h"

    //FLEX + BISON variables
    extern int yylex();
    extern char*yytext;
    extern int yyparse();
    extern FILE *yyin;
    extern int line;

    int errors = 0;

    void check_or_insert(QString,DATATYPE);
    bool check(QString);
    //QT interface variable;
    QString syntax;

    //Error handling function
    void yyerror(const char *s);

    //ast root
    Root *root;

    //symbol table
    QHash<QString,Identifier*> symbols;
%}

%union{
        float fval;
        QString* string;
        std::vector<Sentence*>* sentence_list;
        Sentence* sentence;
        Declaration* declaration;
        Asignation* asignation;
        Function* function;
        Draw* draw;
        Background* background;
        Fill* fill;
        Rotate* rotate;
        Translate* translate;
        Scale* scale;
        Param* param;
        Vect* vect;
        Vect2d* vect2d;
        Vect3d* vect3d;
        Color * color;
        Expresion* expresion;
}

%token INICIO FIN 
%token DIBUJAR RELLENAR ROTAR TRASLADAR ESCALAR SOBRE FONDO
%token <fval>PTO_FLOT
%token COLOR VECT2D VECT3D FLOTANTE
%token PUNTO RECTA CURVA PLANO TRIANGULO CUADRILATERO 
%token ELIPSE CIRCUNFERENCIA PARABOLA HIPERBOLA 
%token POLIEDRO CILINDRO CONO ESFERA 
%token <string>COLOR_PREDEF
%token <string>ID

%type <sentence_list>Lista_Sentencias
%type <sentence>Sentencia
%type <declaration>Declaracion
%type <asignation>Asignacion
%type <function> Funcion
%type <param> Param;
%type <vect2d> Vect2d
%type <vect3d> Vect3d
%type <color> Color
%type <draw>Dibujar
%type <fill> Rellenar
%type <rotate> Rotar
%type <scale> Escalar
%type <translate> Trasladar
%type <expresion> Expresion

%start Programa

%% 

Programa : INICIO Lista_Sentencias FIN  {root = new Root($2);
                                        if(errors==0)
                                            syntax+="\nSintaxis Correcta\n";}
; 

Lista_Sentencias : Sentencia    {$$ = new std::vector<Sentence*>(); $$->push_back($1);}
      | Lista_Sentencias Sentencia  {$$->push_back($2);} //push lista de parametros
; 

Sentencia : Declaracion ';' {$$ = $1;}
                |	Asignacion ';' {$$ = $1;}
                |	Funcion ';' { $$ = $1; }
; 

Declaracion : FLOTANTE ID PTO_FLOT {$$ = new FloatDeclaration($2,$3);
                                    check_or_insert(*$2,FLOAT_DT);}
                |VECT2D ID Vect2d {$$ = new Vect2dDeclaration($2,$3);
                                    check_or_insert(*$2,VECT2_DT);}
                |VECT3D ID Vect3d {$$ = new Vect3dDeclaration($2,$3);
                                    check_or_insert(*$2,VECT3_DT);}
                |COLOR ID Color {$$ = new ColorDeclaration($2,$3);
                                    check_or_insert(*$2,COLOR_DT);}
                |PUNTO ID '{' Param '}' {$$ = new PointDeclaration($2,$4);
                                    check_or_insert(*$2,POINT_DT);}
                |RECTA ID '{' Param ',' Param '}' {$$ = new RectDeclaration($2,$4,$6);
                                    check_or_insert(*$2,RECT_DT);}
                |CURVA ID '{' '}' {$$ = new Declaration;
                                    check_or_insert(*$2,CURVE_DT);}
                |PLANO ID '{' '}' {$$ = new Declaration;
                                    check_or_insert(*$2,PLANE_DT);}
                |TRIANGULO ID '{' Param ',' Param ',' Param '}' {$$ = new Declaration;
                                    check_or_insert(*$2,TRIANGLE_DT);}
                |CUADRILATERO ID '{' Param ',' Param ',' Param ',' Param '}' {$$ = new Declaration;
                                    check_or_insert(*$2,QUAD_DT);}
                |ELIPSE ID '{' '}' {$$ = new Declaration;
                                    check_or_insert(*$2,ELIPSE_DT);}
                |CIRCUNFERENCIA ID '{' Param ',' Param '}' {$$ = new Declaration;
                                    check_or_insert(*$2,CIRC_DT);}
                |PARABOLA ID '{' '}' {$$ = new Declaration;
                                    check_or_insert(*$2,PARABOLE_DT);}
                |HIPERBOLA ID '{' '}' {$$ = new Declaration;
                                    check_or_insert(*$2,HYPERBOLE_DT);}
                |POLIEDRO ID '{' '}' {$$ = new Declaration;
                                    check_or_insert(*$2,POLYHEDRON_DT);}
                |CILINDRO ID '{' '}' {$$ = new Declaration;
                                    check_or_insert(*$2,CILINDRE_DT);}
                |CONO ID '{' '}' {$$ = new Declaration;
                                    check_or_insert(*$2,CONE_DT);}
                |ESFERA ID '{' Param ',' Param '}' {$$ = new Declaration;
                                    check_or_insert(*$2,SPHERE_DT);}
;

Asignacion : ID '=' Expresion {$$ = new Asignation($1,$3);
                                check(*$1);
                              }
; 

Expresion : Param {$$ = new ParamExpresion($1);}
            |Param '+' Param {$$ = new Plus($1,$3);
                                if($1->type != $3->type){yyerror("Error: Los parametros de la suma no concuerdan");} }
            |Param '-' Param {$$ = new Less($1,$3);
                                if($1->type != $3->type){yyerror("Error: Los parametros de la resta no concuerdan");} }
            |Param '*' Param {$$ = new Times($1,$3);
                                if($1->type != $3->type){yyerror("Error: Los parametros de la multiplicacion concuerdan");} }
            |Param '/' Param {$$ = new Division($1,$3);
                                if($1->type != $3->type){yyerror("Error: Los parametros de la division no concuerdan");} }
;

Param : Color {$$= new ColorParam($1);}
        |PTO_FLOT {$$= new FloatParam($1);}
        | Vect2d {$$= new Vect2dParam($1);}
        | Vect3d {$$= new Vect3dParam($1);}
        | ID {$$= new IdParam($1);
                check(*$1);
      }
;

Funcion : Dibujar {$$=$1;}
                |Rellenar {$$=$1;}
                |Rotar {$$=$1;}
                |Trasladar {$$=$1;}
                |Escalar {$$=$1;}
                |FONDO Param {$$= new Background($2);}
;

Dibujar : DIBUJAR ID COLOR Param { $$ = new Draw($2,$4);
    if(check(*$2))
    {
        Identifier* id = symbols.value(*$2);
        if(id->type == VECT2_DT||id->type == VECT3_DT || id->type == FLOAT_DT)
            yyerror("ERROR: Solo se pueden dibujar figuras GEOM2D o GEOM3D");
    if($4->type!=COLOR_DT)
        yyerror("ERROR: El parametro de Color debe ser un Color valido rgba o un color predefinido" );
    }
}
;

Rellenar : RELLENAR ID COLOR Param { $$ = new Fill($2,$4); check(*$2);
    if(check(*$2))
    {
        Identifier* id = symbols.value(*$2);
        if(id->type == VECT2_DT||id->type == VECT3_DT || id->type == FLOAT_DT)
            yyerror("ERROR: Solo se pueden dibujar figuras GEOM2D o GEOM3D");
        if($4->type!=COLOR_DT){
            yyerror("ERROR: El parametro de Color debe ser un Color valido rgba o un color predefinido" );
        }

    }
}
;

Rotar : ROTAR ID SOBRE Param Param { $$ = new Rotate($2,$4,$5);
    if(check(*$2))
    {
        Identifier* id = symbols.value(*$2);
        if(id->type == VECT2_DT||id->type == VECT3_DT || id->type == FLOAT_DT)
            yyerror("ERROR: Solo se pueden rotar figuras GEOM2D o GEOM3D");
        else if(id->dimension == Identifier::GEOM2D && $4->type!=VECT2_DT){
            yyerror("ERROR: El punto de rotacion ser un Vector2d" );
        }else if(id->dimension == Identifier::GEOM3D && $4->type!=VECT3_DT){
            yyerror("ERROR: El punto de rotacion debe ser un Vector3d" );
        }
        if($5->type!=FLOAT_DT)
            yyerror("ERROR: El parametro de rotacion debe ser un Flotante");
    }
}
;

Escalar : ESCALAR ID Param { $$ = new Scale($2,$3);
if(check(*$2))
{
    Identifier* id = symbols.value(*$2);
    if(id->type == VECT2_DT||id->type == VECT3_DT || id->type == FLOAT_DT)
        yyerror("ERROR: Solo se pueden escalar figuras GEOM2D o GEOM3D");
    else if(id->dimension == Identifier::GEOM2D && $3->type!=VECT2_DT){
        yyerror("ERROR: El parametro de escala debe ser un Vector2d" );
    }else if(id->dimension == Identifier::GEOM3D && $3->type!=VECT3_DT){
        yyerror("ERROR: El parametro de escala debe ser un Vector3d" );
    }
}
}
;

Trasladar : TRASLADAR ID Param { $$ = new Translate($2,$3);
    if(check(*$2))
    {
        Identifier* id = symbols.value(*$2);
        if(id->type == VECT2_DT||id->type == VECT3_DT || id->type == FLOAT_DT)
            yyerror("ERROR: Solo se pueden trasladar figuras GEOM2D o GEOM3D");
        else if(id->dimension == Identifier::GEOM2D && $3->type!=VECT2_DT){
            yyerror("ERROR: El parametro de traslacion debe ser un Vector2d" );
        }else if(id->dimension == Identifier::GEOM3D && $3->type!=VECT3_DT){
            yyerror("ERROR: El parametro de traslacion debe ser un Vector3d" );
        }
    }
}
;

Color : '(' PTO_FLOT ',' PTO_FLOT ',' PTO_FLOT ',' PTO_FLOT ')' {$$=new Color($2,$4,$6,$8);
                                                                if($2<0||$2>1)
                                                                    yyerror("ERROR: El componente de rojo del color debe estar entre 0 y 1");
                                                                if($4<0||$4>1)
                                                                    yyerror("ERROR: El componente de verde del color debe estar entre 0 y 1");
                                                                if($6<0||$6>1)
                                                                    yyerror("ERROR: El componente de azul del color debe estar entre 0 y 1");
                                                                if($8<0||$8>1)
                                                                    yyerror("ERROR: El componente alpha (transparencia) del color debe estar entre 0 y 1");
                                                                }
                |COLOR_PREDEF {$$=new Color($1);}
;

Vect2d: '(' PTO_FLOT ',' PTO_FLOT ')' {$$=new Vect2d($2,$4);}
;

Vect3d: '(' PTO_FLOT ',' PTO_FLOT ',' PTO_FLOT ')' {$$=new Vect3d($2,$4,$6);}

         
%% 

void check_or_insert(QString name,DATATYPE t){
    if(symbols.contains(name))
    {
        yyerror("ERROR: No se puede redefinir una variable ya declarada" );
    }
    else
    {
        symbols.insert(name,new Identifier(name,t));
    }
}

bool check(QString name){
    if(!symbols.contains(name))
    {
        yyerror("ERROR: Variable no declarada");
        return false;
    }
    symbols.value(name)->referenced=true;
    return true;
}

int yywrap()  
{  
   return 1;  
}  

void yyerror(const char *s){
    errors++;
    syntax+="En la linea ";
    syntax+=QString::number(line);
    syntax+=":  ";
    if(strcmp (s,"syntax error")==0)
        syntax+="ERROR: Error de sintaxis ";
    else
        syntax+=s;
    syntax+='\n';
}
 

