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
   fprintf(stderr, "%s\n", s);
	}

%}

%union
{
	int numero;
	float numeroR;
	char cadena[50];
}


// token -> terminales
%token <numero> NUM_ENTERO        
%token <numeroR> NUM_REAL        
%token <cadena> LITERAL_CADENA    
%token <cadena> PALABRA_RESERVADA 
%token <cadena> TIPO_DATO        
%token <cadena> IDENTIFICADOR  
%token <cadena> SIZEOF 
%token <cadena> MAS_MAS 
%token <cadena> MAYOR_IGUAL
%token <cadena> MENOS_IGUAL
%token <cadena> IGUAL_IGUAL
%token <cadena> AND
%token <cadena> OR
%token <cadena> DISTINTO


%left '+' '-' '*' ',' OR AND IGUAL_IGUAL DISTINTO MAYOR_IGUAL MENOR_IGUAL
%right '=' ':' '&' '!' '(' ')' '[' ']'MAS_IGUAL MENOS_IGUAL  MAS_MAS SIZEOF



%% /* A continuación las reglas gramaticales y las acciones */

input:  /* vacio */
		| input line
;

line:   '\n'
		| expresion '\n'
;

expresion: expAsignacion ';'
;

expAsignacion: expCondicional
			 | expUnaria operAsignacion expAsignacion 	{printf("se encontro una asignacion \n");}
;

operAsignacion: '='
				|MAS_IGUAL
				|MENOS_IGUAL
;

expCondicional: expOr
			  | expOr expresion ':' expCondicional  	{printf("se encontro una condicion \n");}
			  | expresion ':' expCondicional 			{printf("se encontro una condicion \n");}
;



expOr: 			expAnd
			| expOr OR expAnd
;

expAnd: expIgualdad 
		| expAnd AND expIgualdad
;

expIgualdad: expRelacional
			| expIgualdad IGUAL_IGUAL expRelacional
			| expIgualdad DISTINTO expRelacional 
;

expRelacional: expAditiva
			 | expRelacional operadorRelacional expAditiva

;

operadorRelacional:  MAYOR_IGUAL		
					|MENOR_IGUAL
					|'>'
					|'<'
					
;


expAditiva: expMultiplicativa	
			|expAditiva operadorAditivo expMultiplicativa
;


operadorAditivo: '+'
				| '-'
;

expMultiplicativa: expUnaria
				   | expMultiplicativa operadorMultiplicativo expUnaria
;

operadorMultiplicativo: '*'
						| '/'
;

expUnaria: expPostFijo
			| MAS_MAS expUnaria
			| operUnario expUnaria
			| SIZEOF '(' TIPO_DATO ')'
;


operUnario: '&'
			| '*'
			| '-'
			| '!'
;

expPostFijo: expPrimaria
			| expPostFijo '[' expresion ']'
			| expPostFijo '(' listaArgumentos ')' {printf("se encontro una declaracion de funcion \n");}
			| expPostFijo '('')' 
;

listaArgumentos: expAsignacion
				| listaArgumentos ',' expAsignacion
;

expPrimaria:  IDENTIFICADOR 	
			 | NUM_ENTERO		
			 | NUM_REAL			
			 | LITERAL_CADENA 	
			 | PALABRA_RESERVADA 
			 | TIPO_DATO		
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