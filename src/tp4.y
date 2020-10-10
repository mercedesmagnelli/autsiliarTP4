%{ /* seccion de definiciones */

	#include <stdio.h>
	#include <math.h>
	#include <ctype.h>
	#include <stdlib.h>
	#include <string.h>
	extern FILE* yyin; 


	void yyerror (char const *s) {
  		 fprintf(stderr, "hay un error \n", s);
	}

	int yylex();

	
   

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
%token <cadena> MAS_MAS
%token <cadena> MENOS_MENOS
%token <mystruct> error


%type <cadena> incrementoDecremento
%type <cadena> auxi
%type <cadena> expC
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

line:   
		|'\n'      
		| listadoDeSentenciasDeDeclaracion saltoOpcional
		| definicionFuncion  saltoOpcional
		| sentenciaSwitch saltoOpcional
		| sentenciaWhile saltoOpcional
		| sentenciaFor saltoOpcional
		| sentenciaDoWhile saltoOpcional
		| sentenciaIfElse saltoOpcional
		| sentenciaAsignacion saltoOpcional
		| incrementoDecremento saltoOpcional
		| error saltoOpcional { yyerrok; }

;
//lo agregamos para ver si se solucionaba el problema de los saltos de linea pero no funciona
 
saltoOpcional:  /* vacío */
				| '\n' saltoOpcional
				| '\n'
;

definicionFuncion: TIPO_DATO IDENTIFICADOR '(' listaParametros')' saltoOpcional '{' listadoDeSentencias '}' ';' {printf("Se ha definido una funcion de tipo %s llamada %s \n",$<cadena>1,$<cadena>2);}
;

listadoDeSentencias: /* vacio */
					| sentenciaSwitch listadoDeSentencias 
					| sentenciaDoWhile listadoDeSentencias
					| sentenciaFor listadoDeSentencias
					| sentenciaWhile listadoDeSentencias
					| sentenciaIfElse listadoDeSentencias
					| sentenciaAsignacion listadoDeSentencias
					| sentenciaReturn listadoDeSentencias
					| listadoDeSentenciasDeDeclaracion listadoDeSentencias
					| incrementoDecremento listadoDeSentencias
					| '\n' listadoDeSentencias
;
sentenciaDoWhile: DO '{' listadoDeSentencias '}' WHILE '(' exp ')' ';' {printf( "Se ha declarado una sentencia do-while \n");}

;
sentenciaFor:	FOR  '(' sentenciaDecOAsig  expC ';' incrementoParaFor ')' saltoOpcional '{' listadoDeSentencias '}'  {printf("Se ha declarado una sentencia for\n");}

;

sentenciaDecOAsig: sentenciaAsignacion
				|  sentenciaDeclaracion
;


incrementoParaFor: IDENTIFICADOR MAS_MAS       {printf("Se ha incrementado la variable %s \n",$<cadena>1);}
				  |	IDENTIFICADOR MENOS_MENOS  {printf("Se ha decrementado la variable %s\n",$<cadena>1);}
;


incrementoDecremento: IDENTIFICADOR MAS_MAS ';'  		 {printf("Se ha incrementado la variable %s \n",$<cadena>1);}
					  |IDENTIFICADOR MENOS_MENOS ';'     {printf("Se ha decrementado la variable %s\n",$<cadena>1);}
;


sentenciaIfElse: IF '(' exp ')' saltoOpcional '{' listadoDeSentencias '}' {printf ("Se declaro un if \n");} sentenciaElse
		| error saltoOpcional { yyerrok; }
;

sentenciaElse: 	/* vacío */
				| ELSE saltoOpcional '{' listadoDeSentencias '}' {printf ("Se declaron un else \n");}
;

sentenciaWhile: WHILE '(' exp ')' saltoOpcional '{'  listadoDeSentencias '}' {printf ("Se declaro un while \n");}

;

sentenciaSwitch: /* vacío */
				| SWITCH '(' exp ')' saltoOpcional '{' sentenciaCase '}' {printf ("Se declaro un switch \n");}

;

sentenciaCase:  /* vacío */
				| CASE exp ':' listadoDeSentencias BREAK ';' {printf ("Se declaro un case \n");}
				| sentenciaCase DEFAULT ':' listadoDeSentencias {printf ("Se declaro el default \n");}
;

sentenciaReturn: /* vacío */
				|RETURN exp ';' {printf ("Se declaro un return \n ");}
;

listadoDeSentenciasDeDeclaracion:	/* vacío */
									| sentenciaDeclaracion
									| sentenciaDeclaracion ';' listadoDeSentenciasDeDeclaracion 
;

sentenciaDeclaracion: 	TIPO_DATO IDENTIFICADOR ';'				  {printf ("Se declaro una variable de tipo %s llamada %s \n", $<cadena>1,$<cadena>2);} 
						| TIPO_DATO listaIdentificadores       
						| TIPO_DATO IDENTIFICADOR '[' expC ']' ';' {printf ("Se declaro un arreglo de tipo %s llamado %s \n",$<cadena>1,$<cadena>2);}
						| TIPO_DATO IDENTIFICADOR '[' expC ']' '=' '{' auxi '}' ';' {printf ("Se declaro y se asignaron valores a las posiciones de un arreglo de tipo %s llamado %s \n",$<cadena>1,$<cadena>2);}
						| TIPO_DATO '*' IDENTIFICADOR ';'          {printf ("Se declaro un puntero \n");}
						| TIPO_DATO IDENTIFICADOR '(' listaParametros ')' ';'    {printf ("Se declaro un prototipo de una funcion de tipo %s llamada %s \n",  $<cadena>1, $<cadena>2);}
; 

auxi: expC ',' auxi 
	| expC 
;

sentenciaAsignacion: parametro '=' exp ';'  {printf ("Se le asigno  %s y se le asigno el valor %s \n",$<cadena>1,$<cadena>3);}
					|parametro MAS_IGUAL exp ';' {printf ("Se le asigno  %s y se le asigno su valor mas %s \n",$<cadena>1,$<cadena>3);}
					|parametro MENOS_IGUAL exp ';'  {printf ("Se le asigno  %s y se le asigno su valor menos %s \n",$<cadena>1,$<cadena>3);}
					|parametro POR_IGUAL exp ';'   {printf ("Se le asigno  %s y se le asigno su valor por %s \n",$<cadena>1,$<cadena>3);}
					|parametro DIVIDIDO_IGUAL exp ';'  {printf ("Se le asigno  %s y se le asigno su valor dividido %s \n",$<cadena>1,$<cadena>3);}
					
;

parametro:	 TIPO_DATO IDENTIFICADOR
			| IDENTIFICADOR 

;

listaIdentificadores: 	  identificadorA
						| listaIdentificadores ',' identificadorA 
						

;

identificadorA:		 IDENTIFICADOR ';'				    	{printf ("Se declaro una variable llamada %s \n",$<cadena>1);}
					|IDENTIFICADOR '=' exp';'			    {printf ("Se declaro una variable llamada %s y se le asigno el valor %s \n",$<cadena>1,$<cadena>3);}
					|IDENTIFICADOR MAS_IGUAL exp ';'		{printf ("Se declaro una variable llamada %s y se le asigno el valor %s \n",$<cadena>1,$<cadena>3);}
					|IDENTIFICADOR MENOS_IGUAL exp ';' 		{printf ("Se declaro una variable llamada %s y se le asigno el valor %s \n",$<cadena>1,$<cadena>3);}
					|IDENTIFICADOR POR_IGUAL exp ';' 		{printf ("Se declaro una variable llamada %s y se le asigno el valor %s \n",$<cadena>1,$<cadena>3);}
					|IDENTIFICADOR DIVIDIDO_IGUAL exp ';' 	{printf ("Se declaro una variable llamada %s y se le asigno el valor %s \n",$<cadena>1,$<cadena>3);}

;

listaParametros:  TIPO_DATO
				| TIPO_DATO ',' listaParametros
				|TIPO_DATO IDENTIFICADOR
				|TIPO_DATO IDENTIFICADOR ',' listaParametros

;

			
exp: 		LITERAL_CADENA
			| expC         
			
;

expC:		IDENTIFICADOR
			| CHAR
			| expC '-' expC           {printf ("Se escribio una expresion usando una resta \n");}         
			| expC '>' expC           {printf ("Se escribio una expresion con signo de desigualdad \n");}         
			| expC '<' expC           {printf ("Se escribio una expresion con signo de desigualdad \n");}         
			| expC IGUALDAD expC	  {printf ("Se escribio una expresion con signo de igualdad \n");}          
			| expC MAYOR_IGUAL expC   {printf ("Se escribio una expresion con signo de desigualdad \n");}          
			| expC MENOR_IGUAL expC   {printf ("Se escribio una expresion con signo de desigualdad \n");}          
			| expC DESIGUALDAD expC   {printf ("Se escribio una expresion con signo de distinto \n");}          
			| expC AND expC       	  {printf ("Se escribio una expresion con la operacion logica and \n");}             
			| expC OR expC         	  {printf ("Se escribio una expresion con la operacion logica or \n");}             
			| NUM 
			| NUM_R
			| expC '*' expC       	  {printf ("Se escribio una expresion  \n");}              
			| expC '/' expC           {printf ("Se escribio una expresion  \n");}              
			| expC '+' expC           {printf ("Se escribio una expresion  \n");}  

;





%%

int main ()
{

	yyin=fopen("entrada.c","r");
 
   	yyparse();
 
	
	#ifdef BISON_DEBUG
        yydebug = 1;
	#endif
	fclose(yyin);
	system("pause");
	return 0;

}
