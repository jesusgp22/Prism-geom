%{
    #include <stdio.h>
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

    void check_or_insert(QString,DATATYPE,DataType *);
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
        float* fval;
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

%token INICIO FIN ESCENA _2D _3D
%token DIBUJAR RELLENAR ROTAR TRASLADAR ESCALAR EJE FONDO
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
          |INICIO ESCENA _2D Lista_Sentencias FIN  {root = new Root($4,true);
                                        if(errors==0)
                                            syntax+="\nSintaxis Correcta\n";}
          |INICIO ESCENA _3D Lista_Sentencias FIN  {root = new Root($4,false);
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

Declaracion : FLOTANTE ID PTO_FLOT {$$ = new Declaration($2);
                                    check_or_insert(*$2,FLOAT_DT,new Float(*$3));}
                |VECT2D ID Vect2d {$$ = new Declaration($2);
                                    check_or_insert(*$2,VECT2_DT,$3);}
                |VECT3D ID Vect3d {$$ = new Declaration($2);
                                    check_or_insert(*$2,VECT3_DT,$3);}
                |COLOR ID Color {$$ = new Declaration($2);
                                    check_or_insert(*$2,COLOR_DT,$3);}

                |PUNTO ID '{' Param '}' {$$ = new Declaration($2);
                                    check_or_insert(*$2,POINT_DT,new Point($4));
                                    if($4->type!=VECT2_DT){yyerror("ERROR: La posicion del punto debe ser Vector2d\nPrototipo: Punto {Vector2d posicion}");}
                                    }

                |RECTA ID '{' Param ',' Param '}' {$$ = new Declaration($2);
                                    check_or_insert(*$2,RECT_DT,new Rect($4,$6));
                                    if($4->type!=VECT2_DT){yyerror("ERROR: El punto \"a\" debe ser Vector2d\nPrototipo: Recta {Vector2d a,Vector2d b}");}
                                    if($6->type!=VECT2_DT){yyerror("ERROR: El punto \"b\" debe ser Vector2d\nPrototipo: Recta {Vector2d a,Vector2d b}");}
                                    }

                |CURVA ID '{' Param ',' Param ',' Param '}' {$$ = new Declaration($2);
                                    check_or_insert(*$2,CURVE_DT,new Curve($4,$6,$8));
                                    if($4->type!=VECT2_DT){yyerror("ERROR: El punto \"a\" debe ser Vector2d\nPrototipo: Curva {Vector2d a,Vector2d b,Vector2d c}");}
                                    if($6->type!=VECT2_DT){yyerror("ERROR: El punto \"b\" debe ser Vector2d\nPrototipo: Curva {Vector2d a,Vector2d b,Vector2d c}");}
                                    if($8->type!=VECT2_DT){yyerror("ERROR: El punto \"c\" debe ser Vector2d\nPrototipo: Curva {Vector2d a,Vector2d b,Vector2d c}");}
                                    Vect2d *a,*b,*c;
                                    a = (Vect2d*)$4->value;
                                    b = (Vect2d*)$6->value;
                                    c = (Vect2d*)$8->value;
                                    if(!((a->x<b->x) && (b->x < c->x ))){yyerror("ERROR: La coordenada x de los puntos debe estar ordenada de menor a mayor");}
                                    }


                |PLANO ID '{' Param ',' Param '}' {$$ = new Declaration($2);
                                    check_or_insert(*$2,PLANE_DT,new Plane($4,$6));
                                    if($4->type!=VECT3_DT){yyerror("ERROR: El centro debe ser Vector3d\nPrototipo: Plano {Vector2d centro,Flotante lado}");}
                                    if($6->type!=FLOAT_DT){yyerror("ERROR: El lado debe ser flotante\nPrototipo: Plano {Vector2d centro,Flotante lado}");}
                                    }

                |TRIANGULO ID '{' Param ',' Param ',' Param '}' {$$ = new Declaration($2);
                                    check_or_insert(*$2,TRIANGLE_DT,new Triangle($4,$6,$8));
                                    if($4->type!=VECT2_DT){yyerror("ERROR: El vertice \"a\" debe ser Vector2d\nPrototipo: Triangulo {Vector2d a,Vector2d b,Vector2d c}");}
                                    if($6->type!=VECT2_DT){yyerror("ERROR: El vertice \"b\" debe ser Vector2d\nPrototipo: Triangulo {Vector2d a,Vector2d b,Vector2d c}");}
                                    if($8->type!=VECT2_DT){yyerror("ERROR: El vertice \"c\" debe ser Vector2d\nPrototipo: Triangulo {Vector2d a,Vector2d b,Vector2d c}");}
                                    }

                |CUADRILATERO ID '{' Param ',' Param ',' Param ',' Param '}' {$$ = new Declaration($2);
                                    check_or_insert(*$2,QUAD_DT,new Quad($4,$6,$8,$10));
                                    if($4->type!=VECT2_DT){yyerror("ERROR: El vertice \"a\" debe ser Vector2d\nPrototipo: Cuadrilatero {Vector2d a,Vector2d b,Vector2d c,Vector2d d}");}
                                    if($6->type!=VECT2_DT){yyerror("ERROR: El vertice \"b\" debe ser Vector2d\nPrototipo: Cuadrilatero {Vector2d a,Vector2d b,Vector2d c,Vector2d d}");}
                                    if($8->type!=VECT2_DT){yyerror("ERROR: El vertice \"c\" debe ser Vector2d\nPrototipo: Cuadrilatero {Vector2d a,Vector2d b,Vector2d c,Vector2d d}");}
                                    if($10->type!=VECT2_DT){yyerror("ERROR: El vertice \"d\" debe ser Vector2d\nPrototipo: Cuadrilatero {Vector2d a,Vector2d b,Vector2d c,Vector2d d}");}
                                    }

                |ELIPSE ID '{' Param ',' Param ',' Param '}' {$$ = new Declaration($2);
                                    check_or_insert(*$2,ELIPSE_DT,new Elipse($4,$6,$8));
                                    if($4->type!=VECT2_DT){yyerror("ERROR: El centro debe ser Vector2d\nPrototipo: Elipse {Vector2d centro,Flotante ancho,Flotante altura}");}
                                    if($6->type!=FLOAT_DT){yyerror("ERROR: El ancho debe ser Flotante\nPrototipo: Elipse {Vector2d centro,Flotante ancho,Flotante altura}");}
                                    if($8->type!=FLOAT_DT){yyerror("ERROR: La altura debe ser Flotante\nPrototipo: Elipse {Vector2d centro,Flotante ancho,Flotante altura}");}
                                    }

                |CIRCUNFERENCIA ID '{' Param ',' Param '}' {$$ = new Declaration($2);
                                    check_or_insert(*$2,CIRC_DT,new Circ($4,$6));
                                    if($4->type!=VECT2_DT){yyerror("ERROR: El centro debe ser Vector2d\nPrototipo: Circunferencia {Vector2d centro,Flotante radio}");}
                                    if($6->type!=FLOAT_DT){yyerror("ERROR: El radio debe ser Flotante\nPrototipo: Circunferencia {Vector2d centro,Flotante radio}");}
                                    }

                |PARABOLA ID '{' Param ',' Param '}' {$$ = new Declaration($2);
                                    check_or_insert(*$2,PARABOLE_DT,new Parabole($4,$6));
                                    if($4->type!=VECT2_DT){yyerror("ERROR: El punto minimo debe ser Vector2d\nPrototipo: Parabola {Vector2d punto_minimo,Flotante factor_multiplicativo}");}
                                    if($6->type!=FLOAT_DT){yyerror("ERROR: El factor multiplicativo debe ser Flotante\nPrototipo: Parabola {Vector2d punto_minimo,Flotante factor_multiplicativo}");}
                                    }

                |HIPERBOLA ID '{' Param ',' Param ',' Param '}' {$$ = new Declaration($2);
                                    check_or_insert(*$2,HYPERBOLE_DT,new Hyperbole($4,$6,$8));
                                    if($4->type!=VECT2_DT){yyerror("ERROR: El foco debe ser Vector2d\nPrototipo: Hiperbola {Vector2d foco,Flotante factor_multiplicativo,Flotante distancia_focal}");}
                                    if($6->type!=FLOAT_DT){yyerror("ERROR: El factor multiplicativo debe ser Flotante\nPrototipo: Hiperbola {Vector2d foco,Flotante factor_multiplicativo,Flotante distancia_focal}");}
                                    if($8->type!=FLOAT_DT){yyerror("ERROR: La distancia focal ser Flotante\nPrototipo: Hiperbola {Vector2d foco,Flotante factor_multiplicativo,Flotante distancia_focal}");}
                                    }

                |POLIEDRO ID '{' Param ',' Param '}' {$$ = new Declaration($2);
                                    check_or_insert(*$2,POLYHEDRON_DT,new Polyhedron($4,$6));
                                    if($4->type!=FLOAT_DT){yyerror("ERROR: El numero de caras debe ser Flotante\nPrototipo: Poliedro {Flotante num_caras,Flotante num_lados}");}
                                    if($6->type!=FLOAT_DT){yyerror("ERROR: El numero de lados debe ser Flotante\nPrototipo: Poliedro {Flotante num_caras,Flotante num_lados}");}
                                    }

                |CILINDRO ID '{' Param ',' Param ',' Param '}' {$$ = new Declaration($2);
                                    check_or_insert(*$2,CYLINDRE_DT,new Cylindre($4,$6,$8));
                                    if($4->type!=VECT3_DT){yyerror("ERROR: El centro de la base ser Vector3d\nPrototipo: Cilindro {Vector3d centro,Flotante altura,Flotante radio}");}
                                    if($6->type!=FLOAT_DT){yyerror("ERROR: La altura debe ser Flotante\nPrototipo: Cilindro {Vector3d centro,Flotante altura,Flotante radio}");}
                                    if($8->type!=FLOAT_DT){yyerror("ERROR: El radio debe ser Flotante\nPrototipo: Cilindro {Vector3d centro,Flotante altura,Flotante radio}");}
                                    }

                |CONO ID '{' Param ',' Param ',' Param '}' {$$ = new Declaration($2);
                                    check_or_insert(*$2,CONE_DT,new Cone($4,$6,$8));
                                    if($4->type!=VECT3_DT){yyerror("ERROR: El centro de la base ser Vector3d\nPrototipo: Cono {Vector3d centro,Flotante altura,Flotante radio}");}
                                    if($6->type!=FLOAT_DT){yyerror("ERROR: La altura debe ser Flotante\nPrototipo: Cono {Vector3d centro,Flotante altura,Flotante radio}");}
                                    if($8->type!=FLOAT_DT){yyerror("ERROR: El radio de la base debe ser Flotante\nPrototipo: Cono {Vector3d centro,Flotante altura,Flotante radio}");}
                                    }

                |ESFERA ID '{' Param ',' Param '}' {$$ = new Declaration($2);
                                    check_or_insert(*$2,SPHERE_DT,new Sphere($4,$6));
                                    if($4->type!=VECT3_DT){yyerror("ERROR: El centro de la base ser Vector3d\nPrototipo: Esfera {Vector3d centro,Flotante radio}");}
                                    if($6->type!=FLOAT_DT){yyerror("ERROR: El radio debe ser Flotante\nPrototipo: Esfera {Vector3d centro,Flotante radio}");}
                                    }
;

Asignacion : ID '=' Expresion {$$ = new Asignation($1,$3);
                                check(*$1);
                              }
; 

Expresion : Param {$$ = new ParamExpresion($1);}
            |Param '+' Param {$$ = new Plus($1,$3);
                                if($1->type != $3->type){yyerror("ERROR: Los parametros de la suma no concuerdan");} }
            |Param '-' Param {$$ = new Less($1,$3);
                                if($1->type != $3->type){yyerror("ERROR: Los parametros de la resta no concuerdan");} }
            |Param '*' Param {$$ = new Times($1,$3);
                                if($1->type != $3->type){yyerror("ERROR: Los parametros de la multiplicacion no concuerdan");} }
            |Param '/' Param {$$ = new Division($1,$3);
                                if($1->type != $3->type){yyerror("ERROR: Los parametros de la division no concuerdan");} }
;

Param : Color {$$= new Param(COLOR_DT,(void*)$1);}
        |PTO_FLOT {$$= new Param(FLOAT_DT,(void*)new Float(*$1));}
        |Vect2d {$$= new Param(VECT2_DT,(void*)$1);}
        |Vect3d {$$= new Param(VECT3_DT,(void*)$1);}
        |ID { if(check(*$1)) {$$ = new Param($1);} else{ $$ = new Param(); } }
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

Rotar : ROTAR ID EJE Param Param { $$ = new Rotate($2,$4,$5);
    if(check(*$2))
    {
        Identifier* id = symbols.value(*$2);
        if(id->type == VECT2_DT||id->type == VECT3_DT || id->type == FLOAT_DT)
            yyerror("ERROR: Solo se pueden rotar figuras GEOM2D o GEOM3D");
        if($4->type!=VECT3_DT)
            yyerror("ERROR: El eje de rotacion debe ser un Vector3d" );
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

Color : '(' PTO_FLOT ',' PTO_FLOT ',' PTO_FLOT ',' PTO_FLOT ')' {$$=new Color(*$2,*$4,*$6,*$8);
                                                                if(*$2<0||*$2>1)
                                                                    yyerror("ERROR: El componente de rojo del color debe estar entre 0 y 1");
                                                                if(*$4<0||*$4>1)
                                                                    yyerror("ERROR: El componente de verde del color debe estar entre 0 y 1");
                                                                if(*$6<0||*$6>1)
                                                                    yyerror("ERROR: El componente de azul del color debe estar entre 0 y 1");
                                                                if(*$8<0||*$8>1)
                                                                    yyerror("ERROR: El componente alpha (transparencia) del color debe estar entre 0 y 1");
                                                                }
                |COLOR_PREDEF {$$=new Color($1);}
;

Vect2d: '(' PTO_FLOT ',' PTO_FLOT ')' {$$=new Vect2d(*$2,*$4);}
;

Vect3d: '(' PTO_FLOT ',' PTO_FLOT ',' PTO_FLOT ')' {$$=new Vect3d(*$2,*$4,*$6);}

         
%% 

void check_or_insert(QString name,DATATYPE t,DataType * value){
    if(symbols.contains(name))
    {
        yyerror("ERROR: No se puede redefinir una variable ya declarada" );
    }
    else
    {
        symbols.insert(name,new Identifier(name,t,value));
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
    //syntax+="En la linea ";
    //syntax+=QString::number(line);
    //syntax+=":  ";
    if(strcmp (s,"syntax error")==0)
        syntax+="ERROR: Error de sintaxis ";
    else
        syntax+=s;
    syntax+='\n';
}
 

