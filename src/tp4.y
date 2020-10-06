%{ /* seccion de definiciones */
	#include <stdio.h>
	#include <math.h>
	#include <ctype.h>
	#include <stdlib.h>

	int yylex();

	 int yywrap(){
		return(1);
		 
	} 
   void yyerror (char const *s) {
  		 fprintf(stderr, "hay un error \n", s);
	}

%}
/* 	struct{
     char cadena[50];
     float valor;
     int tipo;
	}s; */

%union{
char cadena[50];
}

%token <cadena> FOR
%token <cadena> IF 
%token <cadena> ELSE 
%token <cadena> RETURN
%token <cadena> SWITCH 
%token <cadena> NUM
%token <cadena> NUM_R
%token <cadena> IDENTIFICADOR
%token <cadena> TIPO_DATO
%token <cadena> DO
%token <cadena> WHILE
%token <cadena> CHAR
%token <cadena> LITERAL_CADENA
%token <cadena> MAYOR_IGUAL
%token <cadena> MENOR_IGUAL
%token <cadena> IGUALDAD
%token <cadena> AND
%token <cadena> OR
%token <cadena> DESIGUALDAD
%token <cadena> CASE
%token <cadena> BREAK
%token <cadena> DEFAULT
%token <cadena> MAS_IGUAL
%token <cadena> MENOS_IGUAL
%token <cadena> POR_IGUAL
%token <cadena> DIVIDIDO_IGUAL

%type <cadena> identificadorA
%type <cadena> exp
%type <cadena> sentenciaDeclaracion
%type <cadena> listaParametros
%type <cadena> parametro
%type <cadena> listaIdentificadores
%type <cadena> sentenciaReturn

%%

input:    /* vacío */
        | input line
;

line:     '\n'
		| listadoDeSentenciasDeDeclaracion '\n'
		| definicionFuncion  '\n'
		| sentenciaSwitch '\n'
		| sentenciaWhile '\n'
		| sentenciaFor '\n'
		| sentenciaDoWhile '\n'
		| sentenciaIfElse '\n'
		| sentenciaAsignacion '\n'
		| error '\n' { yyerrok; }

;


definicionFuncion: TIPO_DATO IDENTIFICADOR '(' listaParametros')' '{' listadoDeSentencias '}' ';' {printf("Se ha definido una funcion \n");}
;

listadoDeSentencias: 
					| sentenciaSwitch listadoDeSentencias
					| sentenciaDoWhile listadoDeSentencias
					| sentenciaFor listadoDeSentencias
					| sentenciaWhile listadoDeSentencias
					| sentenciaIfElse listadoDeSentencias
					| sentenciaAsignacion listadoDeSentencias
					| sentenciaReturn listadoDeSentencias
					| listadoDeSentenciasDeDeclaracion listadoDeSentencias
;
sentenciaDoWhile: DO '{' listadoDeSentencias '}' WHILE '(' exp ')' ';' {printf( "Se ha declarado una sentencia do-while \n");}

;
sentenciaFor:	FOR  '(' sentenciaDeclaracion exp ';' identificadorA '+''+' ')' '{' listadoDeSentencias '}'  {printf("Se ha declarado una sentencia for\n");}
				| FOR '(' sentenciaDeclaracion ';' exp ';' identificadorA '-''-' ')' '{' listadoDeSentencias '}' {printf("Se ha declarado una sentencia for\n")}
;



sentenciaIfElse: IF '(' exp ')' '{' listadoDeSentencias '}' {printf ("Se declaro un if \n");} sentenciaElse
;

sentenciaElse:
				| ELSE '{' listadoDeSentencias '}' {printf ("Se declaron un else \n");}
;

sentenciaWhile: WHILE '(' exp ')' '{' listadoDeSentencias '}' {printf ("Se declaro un while \n");}

;

sentenciaSwitch:
				| SWITCH '(' exp ')' '{' sentenciaCase '}' {printf ("Se declaro un switch \n");}

;

sentenciaCase:
				| CASE exp ':' listadoDeSentencias BREAK ';' {printf ("Se declaro un case \n");}
				| sentenciaCase DEFAULT ':' listadoDeSentencias {printf ("Se declaro el default \n");}
;

sentenciaReturn: 
				|RETURN exp ';'
;

listadoDeSentenciasDeDeclaracion:
									| sentenciaDeclaracion
									| sentenciaDeclaracion ';' listadoDeSentenciasDeDeclaracion 
;

sentenciaDeclaracion:	TIPO_DATO IDENTIFICADOR ';'				  {printf ("Se declaro una variable \n");}
						| TIPO_DATO listaIdentificadores ';'      
						| TIPO_DATO IDENTIFICADOR '[' exp ']' ';' {printf ("Se declaro un arreglo \n");}
						| TIPO_DATO '*' IDENTIFICADOR';'          {printf ("Se declaro un puntero \n");}
						| TIPO_DATO IDENTIFICADOR '(' listaParametros')' ';'    {printf ("Se declaro un prototipo de función \n");}
; 

sentenciaAsignacion: parametro '=' exp ';' 
					|parametro MAS_IGUAL exp ';'
					|parametro MENOS_IGUAL exp ';' 
					|parametro POR_IGUAL exp ';' 
					|parametro DIVIDIDO_IGUAL exp ';' 
					

;

parametro:
			| TIPO_DATO IDENTIFICADOR
			| IDENTIFICADOR 

;

listaIdentificadores: 	  identificadorA
						| listaIdentificadores ',' identificadorA 
						

;

identificadorA:		  IDENTIFICADOR 						{printf ("Se declaró una variable \n");}
					| IDENTIFICADOR '=' exp 				{printf ("Se declaró una variable y se le asignó un valor \n");}
					               

;

listaParametros:  TIPO_DATO
				| TIPO_DATO ',' listaParametros
				|TIPO_DATO IDENTIFICADOR
				|TIPO_DATO IDENTIFICADOR ',' listaParametros

;

exp: 
			| LITERAL_CADENA
			| IDENTIFICADOR
			| CHAR
			| exp '-' exp                   
			| exp '>' exp                   
			| exp '<' exp                   
			| exp IGUALDAD exp		        
			| exp MAYOR_IGUAL exp           
			| exp MENOR_IGUAL exp           
			| exp DESIGUALDAD exp          
			| exp AND exp                   
			| exp OR exp                    
			| NUM 
			| NUM_R
			| exp '*' exp                   
			| exp '/' exp                   
			| exp '+' exp                   
			
;



%%

void main ()
{
	#ifdef BISON_DEBUG
        yydebug = 1;
	#endif
	yyparse();
	system("pause");
}