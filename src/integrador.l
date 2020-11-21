%{

  
#include "integrador.tab.h"
#include "tablaDeSimbolos.h"
#include <string.h>
#include <stdlib.h>



%}
DIGITO_DECIMAL [0-9]    
DIGITO_OCTAL [0-7] 
DIGITO_HEXADECIMAL [a-fA-F0-9] 
CARACTER_IMPRIMIBLE  ["!"|"|"|"\"|"\""|"#"|"$"|"%"|"&"|"'"|"("|")"|"\*"|"+"|","|"-"|"."|"/"|"0"|"1"|"2"|"3"|"4"|"5"|"6"|"7"|"8"|"9"|":"|";"|"<"|"="|">"|"?"|"@"|"A"|"B"|"C"|"D"|"E"|"F"|"G"|"H"|"I"|"J"|"K"|"L"|"M"|"N"|"O"|"P"|"Q"|"R"|"S"|"T"|"U"|"V"|"W"|"X"|"Y"|"Z"|"\["|"\]"|"^"|"_"|"`"|"a"|"b"|"c"|"d"|"e"|"f"|"g"|"h"|"i"|"j"|"k"|"l"|"m"|"n"|"o"|"p"|"q"|"r"|"s"| "t"|"u"|"v"|"w"|"x"|"y"|"z"|"\{"|"\}"|"~"]




%%

"+="										 { strcpy(yylval.s.cadena, yytext); return MAS_IGUAL;}
"-="										 { strcpy(yylval.s.cadena, yytext); return MENOS_IGUAL;}
"*="										 { strcpy(yylval.s.cadena, yytext); return POR_IGUAL;}
"/="										 { strcpy(yylval.s.cadena, yytext); return DIVIDIDO_IGUAL;}
0{DIGITO_OCTAL}*                             { yylval.s.numero = strtoll(yytext, NULL, 8); yylval.s.tipo=1; return OCTAL;}
0[xX]{DIGITO_HEXADECIMAL}+                   { yylval.s.numero = strtoll(yytext, NULL, 16); yylval.s.tipo=1; return HEXA;}
[1-9]{DIGITO_DECIMAL}*                       { yylval.s.numero = atoi(yytext); yylval.s.tipo=1; return DECIMAL;} 
[0-9]+("."[0-9]+)?                           { yylval.s.numero = atof(yytext); yylval.s.tipo=2; return NUM_R; }
while 										 { strcpy(yylval.s.cadena, yytext); return WHILE;}
do 											 { strcpy(yylval.s.cadena, yytext); return DO;}
case										 { strcpy(yylval.s.cadena, yytext); return CASE;}
break										 { strcpy(yylval.s.cadena, yytext); return BREAK;}
default										 { strcpy(yylval.s.cadena, yytext); return DEFAULT;}
for                                          { strcpy(yylval.s.cadena, yytext); return FOR;}
switch                                       { strcpy(yylval.s.cadena, yytext); return SWITCH;}
if                    		               	 { strcpy(yylval.s.cadena, yytext); return IF;}
else            			               	 { strcpy(yylval.s.cadena, yytext); return ELSE;}
return		            	               	 { strcpy(yylval.s.cadena, yytext); return RETURN;}
char                                         { strcpy(yylval.s.cadena, yytext);yylval.s.tipo=0, yytext;ultimoTipoDato(0); return TIPO_DATO;}
int                                          { strcpy(yylval.s.cadena, yytext);yylval.s.tipo=1, yytext;ultimoTipoDato(1);return TIPO_DATO;}
float                                        { strcpy(yylval.s.cadena, yytext);yylval.s.tipo=2, yytext;ultimoTipoDato(2);return TIPO_DATO;}
double                                       { strcpy(yylval.s.cadena, yytext);yylval.s.tipo=3, yytext;ultimoTipoDato(3);return TIPO_DATO;}   
void                                         { strcpy(yylval.s.cadena, yytext);yylval.s.tipo=4, yytext;ultimoTipoDato(4);return TIPO_DATO;}
(\'[a-zA-Z]\')                               { strcpy(yylval.s.cadena, yytext);yylval.s.tipo=0; return CHAR;}
[a-zA-Z_]([a-zA-Z_]|[0-9])*                  { strcpy(yylval.s.cadena, yytext); return IDENTIFICADOR; }
">="										 { strcpy(yylval.s.cadena, yytext); return MAYOR_IGUAL;}
"<="										 { strcpy(yylval.s.cadena, yytext); return MENOR_IGUAL;}
"=="										 { strcpy(yylval.s.cadena, yytext); return IGUALDAD;}
"&&"									     { strcpy(yylval.s.cadena, yytext); return AND;}
"||"										 { strcpy(yylval.s.cadena, yytext); return OR;}
"!="										 { strcpy(yylval.s.cadena, yytext); return DESIGUALDAD;}
\"CARACTER_IMPRIMIBLE*\"			 		 { strcpy(yylval.s.cadena, yytext); return  LITERAL_CADENA;}
"++"                                         { strcpy(yylval.s.cadena, yytext); return  MAS_MAS;}
"--"                                         { strcpy(yylval.s.cadena, yytext); return  MENOS_MENOS;}
","     { return ','; }
"="     { return '='; }
";"     { return ';'; }
"+"     { return '+'; }
"-"     { return '-'; }
"*"     { return '*'; }
"/"     { return '/'; }
"%"     { return '%'; }
")"     { return ')'; }
"("     { return '('; }
"{"     { return '{'; }
"}"     { return '}'; }
"["     { return '['; }
"]"     { return ']'; }
"&"     { return '&'; }
"|"     { return '|'; }
"<"     { return '<'; }
">"     { return '>'; }
"!"     { return '!'; }
":"		{ return ':'; }
"\n"    { return '\n';}
" "     {}
.       {strcpy(yylval.s.cadena, yytext); return  ERROR_LEXICO;}


%%