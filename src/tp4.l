%option noyywrap
%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tp4.tab.h"

%}

DIGITO_DECIMAL [0-9]    
DIGITO_OCTAL [0-7]                                                                                                                                                                                                                          
DIGITO_HEXADECIMAL [a-fA-F0-9] 
LETRA [a-zA-Z] 
CARACTER_IMPRIMIBLE  ["!"|"|"|"\"|"\""|"#"|"$"|"%"|"&"|"'"|"("|")"|"\*"|"+"|","|"-"|"."|"/"|"0"|"1"|"2"|"3"|"4"|"5"|"6"|"7"|"8"|"9"|":"|";"|"<"|"="|">"|"?"|"@"|"A"|"B"|"C"|"D"|"E"|"F"|"G"|"H"|"I"|"J"|"K"|"L"|"M"|"N"|"O"|"P"|"Q"|"R"|"S"|"T"|"U"|"V"|"W"|"X"|"Y"|"Z"|"\["|"\]"|"^"|"_"|"`"|"a"|"b"|"c"|"d"|"e"|"f"|"g"|"h"|"i"|"j"|"k"|"l"|"m"|"n"|"o"|"p"|"q"|"r"|"s"| "t"|"u"|"v"|"w"|"x"|"y"|"z"|"\{"|"\}"|"~"]


%%
'\n'                                         {return '\n';} 
[+-/*:()^;><=]                               {return yytext[0];}
"sizeof"                                     {return SIZEOF;}
"++"                                         {return MAS_MAS;}
">="										 {return MAYOR_IGUAL;}
"<="										 {return MENOS_IGUAL;}
"=="										 {return IGUAL_IGUAL;}
"&&"										 {return AND;}
"||"										 {return OR;}
"!="									     {return DISTINTO;}
"\""{CARACTER_IMPRIMIBLE}+"\""               {strcpy(yylval.cadena, yytext); return LITERAL_CADENA;}
0{DIGITO_OCTAL}*                             {yylval.numero=strtol(yytext,NULL,8); return NUM_ENTERO;}
0[xX]{DIGITO_HEXADECIMAL}+                   {yylval.numero=strtol(yytext,NULL,16); return NUM_ENTERO;} 
[1-9]{DIGITO_DECIMAL}*                       {yylval.numero=atoi(yytext); return NUM_ENTERO;} 
{DIGITO_DECIMAL}\.([Ee](\+|\-)?{DIGITO_DECIMAL})? {yylval.numeroR=atof(yytext); return NUM_REAL;}
(int|float|char|long|double|unsigned|short|struct|typedef|void|signed|enum|register|union)      {strcpy(yylval.cadena, yytext); return TIPO_DATO ;}
(do|while|else|if|for|break|case|switch)     {strcpy(yylval.cadena, yytext); return PALABRA_RESERVADA;}
({LETRA}|"_")({LETRA}|"_"|{DIGITO_DECIMAL})* {strcpy(yylval.cadena, yytext); return IDENTIFICADOR;}   
. {}
%%