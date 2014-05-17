%option noyywrap

%{
#include<cstdlib>
#include"ast.h"
#include"prism.tab.h"
#include<QString>

QString tokens;
int line = 0;
%}


DIGIT    [0-9]
ID       [a-zA-Z][a-zA-Z0-9]*

%%


("+"|"-")?{DIGIT}+("."{DIGIT}*)?   {    tokens+="<PTO_FLOT>, \""; tokens+=yytext; tokens+="\"\n";
                                                                        yylval.fval = atof(yytext);
									return PTO_FLOT;}

Inicio			{tokens +=  "<PAL_RES>, \" " ;tokens += yytext; tokens += "\"\n";
                                                                        return INICIO;
                                                                        }

Fin			{tokens +=  "<PAL_RES>, \" " ;tokens += yytext; tokens += "\"\n";
									return FIN;}

Dibujar		{tokens +=  "<PAL_RES>, \" " ;tokens += yytext; tokens += "\"\n";
									return DIBUJAR;}

Fondo 				{tokens +=  "<PAL_RES>, \" " ;tokens += yytext; tokens += "\"\n";
									return FONDO;}

Rellenar	{tokens +=  "<PAL_RES>, \" " ;tokens += yytext; tokens += "\"\n";
									return RELLENAR;}

Color		{tokens +=  "<PAL_RES>, \" " ;tokens += yytext; tokens += "\"\n";
									return COLOR;}

Rotar		{tokens +=  "<PAL_RES>, \" " ;tokens += yytext; tokens += "\"\n";
									return ROTAR;}

Escalar 	{tokens +=  "<PAL_RES>, \" " ;tokens += yytext; tokens += "\"\n";
									return ESCALAR;}
								
Trasladar	{tokens +=  "<PAL_RES>, \" " ;tokens += yytext; tokens += "\"\n";
									return TRASLADAR;}

Sobre	{tokens +=  "<PAL_RES>, \" " ;tokens += yytext; tokens += "\"\n";
									return SOBRE;}

Flotante	{tokens +=  "<PAL_RES>, \" " ;tokens += yytext; tokens += "\"\n";
									return FLOTANTE;}

Vector2d	{tokens +=  "<PAL_RES>, \" " ;tokens += yytext; tokens += "\"\n";
									return VECT2D;}

Vector3d	{tokens +=  "<PAL_RES>, \" " ;tokens += yytext; tokens += "\"\n";
									return VECT3D;}

Punto		{tokens +=  "<PAL_RES>, \" " ;tokens += yytext; tokens += "\"\n";
									return PUNTO;}

Recta		{tokens +=  "<PAL_RES>, \" " ;tokens += yytext; tokens += "\"\n";
									return RECTA;}

Curva		{tokens +=  "<PAL_RES>, \" " ;tokens += yytext; tokens += "\"\n";
									return CURVA;}

Plano		{tokens +=  "<PAL_RES>, \" " ;tokens += yytext; tokens += "\"\n";
									return PLANO;}

Triangulo		{tokens +=  "<PAL_RES>, \" " ;tokens += yytext; tokens += "\"\n";
									return TRIANGULO;}

Cuadrilatero		{tokens +=  "<PAL_RES>, \" " ;tokens += yytext; tokens += "\"\n";
									return CUADRILATERO;}

Elipse		{tokens +=  "<PAL_RES>, \" " ;tokens += yytext; tokens += "\"\n";
									return ELIPSE;}

Circunferencia		{tokens +=  "<PAL_RES>, \" " ;tokens += yytext; tokens += "\"\n";
									return CIRCUNFERENCIA;}

Parabola		{tokens +=  "<PAL_RES>, \" " ;tokens += yytext; tokens += "\"\n";
									return PARABOLA;}

Hiperbola		{tokens +=  "<PAL_RES>, \" " ;tokens += yytext; tokens += "\"\n";
									return HIPERBOLA;}

Poliedro		{tokens +=  "<PAL_RES>, \" " ;tokens += yytext; tokens += "\"\n";
									return POLIEDRO;}

Cilindro		{tokens +=  "<PAL_RES>, \" " ;tokens += yytext; tokens += "\"\n";
									return CILINDRO;}

Cono		{tokens +=  "<PAL_RES>, \" " ;tokens += yytext; tokens += "\"\n";
									return CONO;}

Esfera		{tokens +=  "<PAL_RES>, \" " ;tokens += yytext; tokens += "\"\n";
									return ESFERA;}

NEGRO|AZUL|CIAN|GRIS|VERDE|MAGENTA|NARANJA|ROSADO|ROJO|BLANCO|AMARILLO       {tokens +=  "<COLOR_PREDEF>, \"";tokens += yytext; tokens += "\"\n";
                                                                                yylval.string = new QString(QString::fromLocal8Bit(yytext));
                                                                                return COLOR_PREDEF;}

{ID}        {tokens +=  "<ID>, \" "; tokens +=yytext; tokens += "\"\n";
                                yylval.string = new QString(QString::fromLocal8Bit(yytext));
				return ID; }

"="     {tokens += "<ASIGN>, \""; tokens += yytext; tokens += "\"\n";
			return yytext[0]; }

"+"|"-"|"*"|"/"   {tokens +=  "<OP>, \"" ;tokens += yytext; tokens += "\"\n";
						return yytext[0]; }
"{"|"}"|";"|","|"("|")"   {tokens +=  "<DELIMITADOR>, \"" ;tokens += yytext; tokens += "\"\n";
							return yytext[0]; }

"\n"		{ line++;}   /* count lines */ 

[ \t]+          /* eat up whitespace */

.           {tokens +=  "<CARACTER_INVALIDO>, \""; tokens += yytext; tokens += "\"\n"; }

%%

void reestart(){
    YY_FLUSH_BUFFER;
}
