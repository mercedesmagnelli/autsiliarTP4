
#ifndef TABLADESIMBOLOS_H
#define TABLADESIMBOLOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ultimoTDato;

struct nodoIdentificadores{
    int cantidad; // este nos sirve para controlar la repetición
    int tipo;
    char* identificador;
    struct nodoIdentificadores* next;
};
typedef struct nodoIdentificadores NodoId;
struct parametros {
    int tipo;
    struct parametros* next;
};
typedef struct parametros NodoParametrosFuncion;



struct nodoFuncion{
  char* identificador;                      //IDENTIFICADOR
  int tipoRetorno;                          //TIPO_DATO
  NodoParametrosFuncion * listaParametros;
  int cantidadVecesDeclarado;
  int cantidadVecesDesarrollada;
  int cantidadParametros;
  struct nodoFuncion* next;
};
typedef struct nodoFuncion NodoFuncion;


struct nodoErrorInvocacionFuncion{
    char* identificadorFuncion;
    int errorDeInvocacion; // 0 = diferente cantidad de parametros , 1 = diferente tipos de parametros, 2 = return malo, 3 = nunca se declaro la funcion,4 hay un parametro no es definido
};
typedef struct nodoErrorInvocacionFuncion NodoErrorFuncionInvocacion;


struct nodoErrorLexico{
    char* error;
    struct nodoErrorLexico* next;
    
};
typedef struct nodoErrorLexico NodoErrorLexico;



struct nodoErrorSintactico{
    int lineaError;
    char* error;
    struct nodoErrorSintactico* next;
};
typedef struct nodoErrorSintactico NodoErrorSintactico;


struct nodoControlTipos{
    char *exp1;
	char *exp2;
	char *operacion;
    struct nodoControlTipos* next;
};
typedef struct nodoControlTipos NodoCT;


// prototipos de funciones 
void ultimoTipoDato(int tipo);

int mostrarUltimoDato();

NodoId* idYaSeDeclaro(char* id);

void agregarIdentificador(char* id, int tipo);

void agregarErrorLexico(char* errorLexico);

void erroresLexicos();

void agregarErrorSintactico(char const *errorSintactico, int linea);

void erroresSintacticos();

void dobleDeclaracion();

void erroresSemanticos();

void mostrarVariablesDeclaradas();

void generarReporte();

void agregarFuncion(int tipo, char* id, int tipoInvocacion);

void agregarParametro(int tipo);

NodoFuncion* funcionYaSeDeclaro(char* id);

int cantidadNodos(NodoParametrosFuncion*);

int idEncontrado(NodoId*,char* id);

int sonOperables(char*);

int buscarTipo(char*); 

void verificaFuncion(char*);

void verificarTiposDeParametros(char*,NodoParametrosFuncion*,NodoParametrosFuncion*);

NodoId* idYaSeDeclaro(char*);

int calcularTipo(char*, int);

void agregarErrorFuncionInvocacion(char*,int);

int sonOperables(char*);

#endif