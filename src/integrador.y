%{ /* seccion de definiciones */

	#include <stdio.h>
	#include <math.h>
	#include <ctype.h>
	#include <stdlib.h>
	#include <string.h>
	#include "tablaDeSimbolos.h"
	#include "tablaDeSimbolos.c"
	#define YYERROR_VERBOSE
	extern FILE* yyin; 
	extern FILE* yyout;
	int my_line=1;
	
	// el mensaje muestre la línea en la que está el error

	int yylex();

	void yyerror (char const *s) {
		agregarErrorSintactico(s,my_line);
		//fprintf(stderr, "hay un error \n", s); 
	}

%}


%union{
	struct{
		char cadena[50];
		int tipo;// char=0,int=1, float=2, double=3, void=4 ,char*=5
		float numero;
	}s;
}

%token <s> FOR
%token <s> IF 
%token <s> ELSE 
%token <s> RETURN
%token <s> SWITCH 
%token <s> DECIMAL
%token <s> HEXA
%token <s> OCTAL
%token <s> NUM_R
%token <s> IDENTIFICADOR
%token <s> TIPO_DATO
%token <s> DO
%token <s> WHILE
%token <s> CHAR
%token <s> LITERAL_CADENA
%token <s> MAYOR_IGUAL
%token <s> MENOR_IGUAL
%token <s> IGUALDAD
%token <s> AND
%token <s> OR
%token <s> DESIGUALDAD
%token <s> CASE
%token <s> BREAK
%token <s> DEFAULT
%token <s> MAS_IGUAL
%token <s> MENOS_IGUAL
%token <s> POR_IGUAL
%token <s> DIVIDIDO_IGUAL
%token <s> MAS_MAS
%token <s> MENOS_MENOS
%token <s> error
%token <s> ERROR_LEXICO

%type <s> incrementoDecremento
%type <s> auxi
%type <s> expC
%type <s> identificadorA
%type <s> exp
%type <s> sentenciaDeclaracion
%type <s> listaParametrosPrototipo
%type <s> listaParametrosFuncion
%type <s> parametro
%type <s> listaIdentificadores
%type <s> sentenciaReturn


%%

input:    /* vacío */ 
        | input line
		| ERROR_LEXICO { agregarErrorLexico($<s.cadena>1);}
;

line:   
		|'\n'    {my_line++;}     
		| listadoDeSentenciasDeDeclaracion saltoOpcional
		| invocacionFuncion saltoOpcional 
		| prototipoFuncion saltoOpcional
		| desarrolloFuncion saltoOpcional
		| sentenciaSwitch saltoOpcional
		| sentenciaWhile saltoOpcional
		| sentenciaFor saltoOpcional
		| sentenciaDoWhile saltoOpcional
		| sentenciaIfElse saltoOpcional
		| sentenciaAsignacion saltoOpcional
		| incrementoDecremento saltoOpcional
		| error saltoOpcional { yyerrok;}
;


saltoOpcional:  /* vacío */ {}
				| '\n' saltoOpcional {my_line++;} 
				| '\n'  {my_line++;} 
;


invocacionFuncion: IDENTIFICADOR '(' listaParametrosInvocacion ')' ';'  {/*verificaciones de prototipo*/}
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
					| invocacionFuncion saltoOpcional
					| incrementoDecremento listadoDeSentencias
					| '\n' listadoDeSentencias {my_line++;} 
;
sentenciaDoWhile: DO saltoOpcional '{' listadoDeSentencias '}' WHILE '(' exp ')' ';' {printf( "Se ha declarado una sentencia do-while \n");}

;
sentenciaFor:	FOR  '(' sentenciaDecOAsig  expC ';' incrementoParaFor ')' saltoOpcional '{' listadoDeSentencias '}'  {printf("Se ha declarado una sentencia for\n");}
;

sentenciaDecOAsig: sentenciaAsignacion
				|  sentenciaDeclaracion
;


incrementoParaFor: IDENTIFICADOR MAS_MAS       {printf("Se ha incrementado la variable %s \n",$<s.cadena>1);}
				  |IDENTIFICADOR MENOS_MENOS  {printf("Se ha decrementado la variable %s\n",$<s.cadena>1);}
;


incrementoDecremento: IDENTIFICADOR MAS_MAS ';'  		 {printf("Se ha incrementado la variable %s \n",$<s.cadena>1);} 
					  |IDENTIFICADOR MENOS_MENOS ';'     {printf("Se ha decrementado la variable %s\n",$<s.cadena>1);} 
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

sentenciaDeclaracion: 	TIPO_DATO IDENTIFICADOR ';'				 					 {printf("entra por la gramatica de la linea 181");agregarIdentificador($<s.cadena>2, $<s.tipo>1);} 
						| TIPO_DATO listaIdentificadores  ';'	    
						| TIPO_DATO IDENTIFICADOR '[' expC ']' ';'  				 {agregarIdentificador($<s.cadena>2, $<s.tipo>1);}
						| TIPO_DATO IDENTIFICADOR '[' expC ']' '=' '{' auxi '}' ';'  {agregarIdentificador($<s.cadena>2, $<s.tipo>1);}
						| TIPO_DATO '*' IDENTIFICADOR ';'          				     {agregarIdentificador($<s.cadena>2, $<s.tipo>1);}
						| error saltoOpcional { yyerrok; }
; 


desarrolloFuncion: TIPO_DATO IDENTIFICADOR '(' listaParametrosFuncion ')'  saltoOpcional '{' listadoDeSentencias '}' ';'  
;

prototipoFuncion: TIPO_DATO IDENTIFICADOR '(' listaParametrosPrototipo ')' ';'  
;


auxi: expC ',' auxi 
	| expC 
;

sentenciaAsignacion: parametro '=' exp ';'  			 {if(flag()){printf("y se le asigno %s \n ",$<s.cadena>3);}else{bajarFlag();}} 
					|parametro MAS_IGUAL exp ';'		 {if(flag()){printf("y se le asigno el mismo mas %s \n",$<s.cadena>3);}else{bajarFlag();}} 
					|parametro MENOS_IGUAL exp ';'  	 {if(flag()){printf("y se le asigno el mismo menos %s \n",$<s.cadena>3);}else{bajarFlag();}} 
					|parametro POR_IGUAL exp ';'    	 {if(flag()){printf("y se le asigno el mismo por %s \n",$<s.cadena>3);}else{bajarFlag();}} 
					|parametro DIVIDIDO_IGUAL exp ';'    {if(flag()){printf("y se le asigno el mismo dividido por %s \n",$<s.cadena>3);}else{bajarFlag();}} 
;

parametro:	 TIPO_DATO IDENTIFICADOR  					{agregarIdentificador($<s.cadena>2,$<s.tipo>1);printf("Se declaro  %s del tipo %s y se le asigno ",$<s.cadena>2,$<s.cadena>1);}
			| IDENTIFICADOR 	      					{if(idYaSeDeclaro($<s.cadena>1)!=NULL){printf ("Se le asigno a %s y se le asigno ",$<s.cadena>1);}/* else{agregar a error semantico;levantarFlag();} */}

;



listaIdentificadores: identificadorA   
						| listaIdentificadores ',' identificadorA 					
;

identificadorA:		IDENTIFICADOR 				    	{agregarIdentificador($<s.cadena>1,mostrarUltimoDato());} 
					|IDENTIFICADOR '=' exp			    {agregarIdentificador($<s.cadena>1,mostrarUltimoDato());} 
					|IDENTIFICADOR MAS_IGUAL exp 		{agregarIdentificador($<s.cadena>1,mostrarUltimoDato());}
					|IDENTIFICADOR MENOS_IGUAL exp  	{agregarIdentificador($<s.cadena>1,mostrarUltimoDato());}
					|IDENTIFICADOR POR_IGUAL exp  		{agregarIdentificador($<s.cadena>1,mostrarUltimoDato());}
					|IDENTIFICADOR DIVIDIDO_IGUAL exp  	{agregarIdentificador($<s.cadena>1,mostrarUltimoDato());}

;

listaParametrosPrototipo:  	/* vacio */ 
							| TIPO_DATO 							 {agregarParametro($<s.tipo>1);}
							| TIPO_DATO ',' listaParametrosPrototipo {agregarParametro($<s.tipo>1);}
							| listaParametrosFuncion
;



listaParametrosFuncion: 	/* vacio */ 
							|TIPO_DATO IDENTIFICADOR							{agregarParametro($<s.tipo>1);}
							|TIPO_DATO IDENTIFICADOR ',' listaParametrosFuncion	{agregarParametro($<s.tipo>1);} //AREGLAR CON LO Q DIJO JUAN

;

listaParametrosInvocacion: /* vacio */ 
				    	  | noTerminal ',' listaParametrosInvocacion 
						  | noTerminal

;

noTerminal: IDENTIFICADOR 							{int tipo=buscarTipo($<s.cadena>1);if(tipo>=0){agregarParametro(tipo);}/* else{} */}
			| CHAR 									{agregarParametro($<s.tipo>1);}
			| DECIMAL 								{agregarParametro($<s.tipo>1);}
			| HEXA    								{agregarParametro($<s.tipo>1);}
			| OCTAL  								{agregarParametro($<s.tipo>1);}
			| NUM_R   								{agregarParametro($<s.tipo>1);}
			| noTerminal IGUALDAD noTerminal	    {agregarParametro(1);}          
			| noTerminal MAYOR_IGUAL noTerminal     {agregarParametro(1);}          
			| noTerminal MENOR_IGUAL noTerminal     {agregarParametro(1);}          
			| noTerminal DESIGUALDAD noTerminal     {agregarParametro(1);}          
			| noTerminal AND noTerminal       	    {agregarParametro(0);}             
			| noTerminal OR noTerminal         	    {agregarParametro(0);} 

;




exp: 		LITERAL_CADENA
			| expC         
			
;



expC:		IDENTIFICADOR
			| CHAR
			| expC '+' expC           {printf ("Se escribio una expresion  \n");} 
			| expC '-' expC           {printf ("Se escribio una expresion usando una resta \n");}         
			| expC '>' expC           {printf ("Se escribio una expresion con signo de desigualdad \n");}         
			| expC '<' expC           {printf ("Se escribio una expresion con signo de desigualdad \n");}         
			| expC IGUALDAD expC	  {printf ("Se escribio una expresion con signo de igualdad \n");}          
			| expC MAYOR_IGUAL expC   {printf ("Se escribio una expresion con signo de desigualdad \n");}          
			| expC MENOR_IGUAL expC   {printf ("Se escribio una expresion con signo de desigualdad \n");}          
			| expC DESIGUALDAD expC   {printf ("Se escribio una expresion con signo de distinto \n");}          
			| expC AND expC       	  {printf ("Se escribio una expresion con la operacion logica and \n");}             
			| expC OR expC         	  {printf ("Se escribio una expresion con la operacion logica or \n");}             
			| DECIMAL
			| HEXA
			| OCTAL
			| NUM_R
			| expC '*' expC       	  {printf ("Se escribio una expresion  \n");}              
			| expC '/' expC           {printf ("Se escribio una expresion  \n");}              
			 

;

			



%%

int main ()
{

	yyin=fopen("entrada.c","r");
   	printf("pruebaPreParse");
	yyparse();
 	#ifdef BISON_DEBUG
        yydebug = 1;
	#endif
	printf("prueba");
	generarReporte();
	printf("otraPrueba");
	fclose(yyin);
	system("pause");	
	return 0;

}

