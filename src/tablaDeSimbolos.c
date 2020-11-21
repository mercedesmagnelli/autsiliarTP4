
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tablaDeSimbolos.h"

NodoId *raizId=NULL;
NodoParametrosFuncion *raizParametro=NULL;
NodoFuncion *raizFuncion=NULL;
NodoErrorLexico *raizErrorLexico=NULL;
NodoErrorFuncionInvocacion *raizErrorFuncionInvocacion = NULL;
NodoErrorSintactico *raizErrorSintactico=NULL;
NodoCT *raizControlTipos=NULL;


int ultimoTDato;
int flagError=0;

void levantarFlag(){
    flagError=1;
}

void bajarFlag(){
    flagError=0;
}

int flag(){
    return flagError;
}

void agregarFuncion(int tipo, char* id,int funcionalidad){ //funcionalidad=0 prototipo, funcionalidad=1 desarrollo
    NodoFuncion* nuevoNodo;
    if(raizFuncion==NULL){
        nuevoNodo = (NodoFuncion *) malloc (sizeof(NodoFuncion)); //ver lo q esta entre () casting
        nuevoNodo -> identificador=strdup(id);
        nuevoNodo -> tipoRetorno=tipo;
        nuevoNodo -> listaParametros = raizParametro; 
        nuevoNodo -> cantidadVecesDeclarado = 0;   
        nuevoNodo -> cantidadVecesDesarrollada = 0;
        nuevoNodo -> cantidadParametros = cantidadNodos(nuevoNodo -> listaParametros);
        if(funcionalidad==0){
                nuevoNodo -> cantidadVecesDeclarado = (nuevoNodo -> cantidadVecesDeclarado)++;
        }else{
                nuevoNodo -> cantidadVecesDesarrollada= ( nuevoNodo -> cantidadVecesDesarrollada)++;
        }
        nuevoNodo -> next = NULL;
        raizFuncion = nuevoNodo;
        raizParametro = NULL; // este null lo que hace es que "resetea" la listaParametros global   
    }else{
        NodoFuncion *encontrado = funcionYaSeDeclaro(id);
        if(encontrado ==NULL){
            //no lo encuentra en la lista de identificadores encontrados
            nuevoNodo = (NodoFuncion *) malloc (sizeof(NodoFuncion)); //ver lo q esta entre () casting
            nuevoNodo -> identificador=strdup(id);
            nuevoNodo -> tipoRetorno=tipo;
            nuevoNodo -> listaParametros = raizParametro;
            nuevoNodo -> cantidadVecesDesarrollada = 0;
            nuevoNodo -> cantidadVecesDeclarado = 0;
            nuevoNodo -> cantidadParametros = cantidadNodos(nuevoNodo -> listaParametros);// falta hacer la funcion
            if(funcionalidad==0){
                nuevoNodo -> cantidadVecesDeclarado= (nuevoNodo -> cantidadVecesDeclarado)++;
            }else{
                nuevoNodo -> cantidadVecesDesarrollada= ( nuevoNodo -> cantidadVecesDesarrollada)++;
            }
            nuevoNodo -> next = NULL;
            NodoFuncion *auxiliar = raizFuncion;
            while(auxiliar->next!=NULL){
                auxiliar=auxiliar->next;
            }
            auxiliar->next=nuevoNodo;
            raizParametro = NULL;
        }else{
            //lo encuentra en la lista de funciones declarados
            if(funcionalidad==0){
                encontrado -> cantidadVecesDeclarado+=1;
            }else{
                nuevoNodo -> cantidadVecesDesarrollada+=1;
            }
            raizParametro = NULL;
        }
    }
}

void verificaFuncion(char* id){
    NodoFuncion* auxiliar=raizFuncion;
    if(raizFuncion==NULL){
        //NO SE DECLARO: invocamos algo que no existe
        //  agregarErrorFuncionInvocacion(id,3);
    }else{
        while(auxiliar!=NULL&&strcmp(auxiliar->identificador,id)!=0){
            auxiliar=auxiliar->next;
        }
        if(auxiliar==NULL){
           //NO SE DECLARO
        //   agregarErrorFuncionInvocacion(id,3);
        }else{
            if(auxiliar->cantidadParametros!=cantidadNodos(raizParametro)){
                        //diferente cantidad de parametros
                        //agregarErrorFuncionInvocacion(id,0);
            }else{
                  //  verificarTiposDeParametros(auxiliar,auxiliar->listaParametros,raizParametro);
            }
            }
        }   
    }

void verificarTiposDeParametro (NodoFuncion* auxiliar, NodoParametrosFuncion * listaParametros, NodoParametrosFuncion* raizParametro){

    NodoParametrosFuncion * auxiliarListaParam = listaParametros;
    NodoParametrosFuncion * auxiliarRaizParam = raizParametro;

    while(sonOperablesODelMismoTipo(listaParametros->tipo,raizParametro->tipo) && listaParametros!=NULL) {
      listaParametros = listaParametros->next;
      raizParametro= raizParametro->next;
    }
    if(listaParametros!=NULL || raizParametro!=NULL){

        //agregarErrorFuncionInvocacion(auxiliar->id, 1);
    }

    
    
}


NodoFuncion* funcionYaSeDeclaro(char* id){
    NodoFuncion *auxiliar=raizFuncion;
    while(auxiliar!=NULL){
        if(strcmp(auxiliar->identificador,id)==0){
           return auxiliar;
        }else{
            auxiliar=auxiliar->next;
        }
    }
    return NULL;
}




/*
void verificarTiposDeParametros(char* id,NodoParametrosFuncion *raizParaEnFuncion,NodoParametrosFuncion *raizParaInvocada){
    NodoParametrosFuncion *auxParaEnFuncion=raizParaEnFuncion;
    NodoParametrosFuncion *auxParaInvocada=raizParaInvocada;
    while(strcmp(auxParaEnFuncion->tipo,auxParaInvocada->tipo)==0 ){
        auxParaEnFuncion=auxParaEnFuncion->next;
        auxParaInvocada=auxParaInvocada->next;
    }
    if(auxParaEnFuncion!=NULL || auxParaInvocada!=NULL){ //ver borrar alguno porq van a la par
       // agregarErrorFuncionInvocacion(id,1);
    }
}

*/



void ultimoTipoDato(int tipo){
    ultimoTDato = tipo;
}

int mostrarUltimoDato(){
    return ultimoTDato;
}



NodoId* idYaSeDeclaro(char* id){
    NodoId *auxiliar=raizId;
    while(auxiliar!=NULL && strcmp(auxiliar->identificador,id)!=0){ 
    auxiliar=auxiliar->next;
    }
    return auxiliar;
}

void agregarIdentificador(char* id, int tipo){
    NodoId *nuevoNodo; 
    if(raizId==NULL){
        nuevoNodo = (NodoId *) malloc (sizeof(NodoId)); //ver lo q esta entre () casting
        nuevoNodo -> identificador=strdup(id); 
        nuevoNodo -> tipo = tipo;
        nuevoNodo -> cantidad = 1;
        nuevoNodo -> next = NULL;
        raizId = nuevoNodo;
        //ven 
    }else{
        NodoId *encontrado = idYaSeDeclaro(id);
        if(encontrado == NULL){
            //no lo encuentra en la lista de identificadores encontrados
            nuevoNodo = (NodoId *) malloc (sizeof(NodoId));   
            nuevoNodo -> identificador=strdup(id); 
            nuevoNodo -> tipo = tipo; 
            nuevoNodo -> cantidad = 1;
            nuevoNodo -> next = NULL; 
            NodoId *auxiliar=raizId;
            while(auxiliar->next!=NULL){
                auxiliar=auxiliar->next;
            }
            auxiliar->next=nuevoNodo;
        }else{
            //lo encuentra en la lista de identificadores declarados
            encontrado -> cantidad += 1;
        }
    }
}


//funciones relacionadas a los errores lexicos
void agregarErrorLexico(char* errorLexico){
    NodoErrorLexico *nuevoNodo,*auxiliar; 
    nuevoNodo = (NodoErrorLexico *) malloc (sizeof(NodoErrorLexico)); //ver lo q esta entre () casting
    nuevoNodo -> error =strdup(errorLexico); 
    nuevoNodo ->next = NULL;
    auxiliar=raizErrorLexico;
    if(raizErrorLexico==NULL){
        raizErrorLexico=nuevoNodo;
    }else{
        while(auxiliar->next!=NULL){
            auxiliar=auxiliar->next;
        }
        auxiliar->next=nuevoNodo;
    }

}



// funciones relacionadas a los errores sintacticos

void agregarErrorSintactico(char const *errorSintactico, int linea){
    NodoErrorSintactico *nuevoNodo,*auxiliar;
    nuevoNodo= (NodoErrorSintactico *) malloc (sizeof(NodoErrorSintactico));
    nuevoNodo -> error =strdup(errorSintactico); 
    nuevoNodo ->lineaError=linea;
    auxiliar=raizErrorSintactico;
    if(raizErrorSintactico==NULL){
        raizErrorSintactico=nuevoNodo;  
    }else{
        while(auxiliar->next!=NULL){
            auxiliar=auxiliar->next;
        }
        auxiliar->next=nuevoNodo;
    }
}



//funciones relacionadas con los errores semanticos

void invocacionesIncorrectas(){}

void agregarParametro(int tipoNuevo){
    NodoParametrosFuncion *auxiliar=raizParametro;
    NodoParametrosFuncion *nuevoNodo;
    if(raizParametro==NULL){
        nuevoNodo = (NodoParametrosFuncion *) malloc (sizeof(NodoParametrosFuncion)); 
        nuevoNodo ->tipo = tipoNuevo;        
        nuevoNodo->next=NULL;
        raizParametro=nuevoNodo;
    }else{
        while(auxiliar->next!=NULL){
            auxiliar=auxiliar->next;
        }
        auxiliar->next=nuevoNodo;
        nuevoNodo = (NodoParametrosFuncion *) malloc (sizeof(NodoParametrosFuncion)); 
        nuevoNodo -> tipo = tipoNuevo; 
        nuevoNodo->next=NULL;
    }
    

}

int cantidadNodos(NodoParametrosFuncion *unaListaParametros){ 
    NodoParametrosFuncion* auxiliar = unaListaParametros;
    int cant = 0;
    if(auxiliar==NULL) {
    }else{
        while(auxiliar->next != NULL){
        cant++;
        auxiliar = auxiliar -> next;
       }
        cant++;
    }
    return cant;
}




void dobleDeclaracion(){ //es semantico y va para Id y funciones
    NodoId *auxiliarRecorrido=raizId;
    NodoFuncion *auxiliarRecorridos=raizFuncion;
    //doble declaraciones de variables
    while(auxiliarRecorrido!=NULL){
        if(auxiliarRecorrido->cantidad!=1){
            printf("Se realizo una doble declaracion con el identificador %s \n",auxiliarRecorrido->identificador);
            auxiliarRecorrido=auxiliarRecorrido->next;
        }
    auxiliarRecorrido=auxiliarRecorrido->next;
    }
    //doble declaraciones de prototipos de funciones
    while(auxiliarRecorridos!=NULL){
        if(auxiliarRecorridos->cantidadVecesDeclarado!=1){
            printf("Se realizo una doble declaracion de la funcion %s \n",auxiliarRecorridos->identificador);
            auxiliarRecorridos=auxiliarRecorridos->next;
        }
    auxiliarRecorridos=auxiliarRecorridos->next;
    }
    //doble delcaraciones de desarrollo de funciones
    auxiliarRecorridos=raizFuncion;
    while(auxiliarRecorridos!=NULL){
        if(auxiliarRecorridos->cantidadVecesDesarrollada!=1){
            printf("Se realizo mas de un desarrollo  de la funcion %s \n",auxiliarRecorridos->identificador);
            auxiliarRecorridos=auxiliarRecorridos->next;
        }
    auxiliarRecorridos=auxiliarRecorridos->next;
    }


}

//funcion principal de generar reporte
void generarReporte(){
    printf("\n");
    //funcionDePrueba();
    variablesCorrectamenteDeclaradas();
    //funcionesCorrectamenteDeclaradas();
    //erroresLexicos();
    //erroresSintacticos();
    //erroresSemanticos();
}

void funcionDePrueba() {
    printf("estamos chequeando que llegue a la funcion generarReporte()");
}
// funciones de impresion por pantalla para reporte
void variablesCorrectamenteDeclaradas(){
    printf("Se encontro el identificador %s del tipo %s \n",raizId->identificador, raizId->tipo );
    /* NodoId *auxiliarRecorrido=raizId;
    while(auxiliarRecorrido!=NULL){
        if(auxiliarRecorrido->cantidad==1){
            printf("Se encontro el identificador %s del tipo %s \n",auxiliarRecorrido->identificador, auxiliarRecorrido->tipo );
            auxiliarRecorrido=auxiliarRecorrido->next;
        }
    auxiliarRecorrido=auxiliarRecorrido->next;
    }*/
} 

void funcionesCorrectamenteDeclaradas(){
    NodoFuncion *auxiliarRecorridos=raizFuncion;
     while(auxiliarRecorridos!=NULL){
        if(auxiliarRecorridos->cantidadVecesDesarrollada==1&&auxiliarRecorridos->cantidadVecesDeclarado==1){
            printf("Se realizo el prototipo y el desarrollo correcto de la funcion %s que cuenta con %d parametros, siendo la misma del tipo %s \n",auxiliarRecorridos->identificador,auxiliarRecorridos->cantidadParametros,tipoRepresentado(auxiliarRecorridos->tipoRetorno));
            auxiliarRecorridos=auxiliarRecorridos->next;
        }
    auxiliarRecorridos=auxiliarRecorridos->next;
    }

}

void erroresLexicos(){
    NodoErrorLexico *auxiliarRecorrido;
    while(auxiliarRecorrido!=NULL){
         printf("Se presento el error lexico  %s \n",auxiliarRecorrido->error);
         auxiliarRecorrido=auxiliarRecorrido->next; 

    }
}

void erroresSintacticos(){
    NodoErrorSintactico *auxiliarRecorrido=raizErrorSintactico;
    while(auxiliarRecorrido!=NULL){
        printf("Se encontro el error sintactico %s en la linea %d",auxiliarRecorrido->error,auxiliarRecorrido->lineaError);
        auxiliarRecorrido=auxiliarRecorrido->next;
    }
}

void erroresSemanticos(){
    //incovacionesIncorrectas();
    //controlTipos();
    dobleDeclaracion();
}
//funciones utilizadas en generacion de informe
char* tipoRepresentado(int enNumero){
    switch (enNumero)
    {
    case 0:
        return "char";
        break;
    case 1:
        return "int";
        break;
    case 2:
        return "float";
        break;
    case 3:
        return "double";
        break;
    case 4:
        return "void";
        break;
    case 5:
        return "char";
        break;
    case 6:
        return "char";
        break;
    }
}





int calcularTipo(char* potencialIdentificador, int tipoOriginal){
    if (idEncontrado(raizId,potencialIdentificador)){            //encuentra el id?

        return buscarTipo(potencialIdentificador);                  //obtener el tipo del id encontrado

    }
    return tipoOriginal;                                            //retorno del tipo original en caso de no encontrar el id en la lista
}

int idEncontrado(NodoId* lista,char* iden){
	NodoId* aux = raizId;
	while(aux!=NULL){
		if(!strcmp(aux->identificador, iden)){
			return 1;
		}else{
		aux=aux->next;
		}
	}
	return 0;
}


int esOperable (char* iden){
	NodoId* aux = raizId;
	while(aux!=NULL){
		if(!strcmp(aux->identificador, iden)){              //el if de la linea 128 muestra los 4 tipos de variables posibles para operaciones

			if(aux->tipo== 0 || aux->tipo== 1 || aux->tipo== 2 || aux->tipo== 3)
            {return 1;} 
            else 
            { return 2;};
		}else{
		aux=aux->next;
		}


	}
	return 0;
}

/* 
    funcion(int tipo1, int tipo2){
        fijarse que tipo1 y tipo 2 sean operables con funcion SonOperables
    }

 */

int sonOperablesODelMismoTipo(int unTipo, int otroTipo){
    // 1: operables 2: mismo tipo 0: no operables
    // resumen: 1 y 2 son operables
    if (unTipo==otroTipo) {return 2;} else if(unTipo < 4 && otroTipo < 4) {return 1;}  else {return 0;}
}


int buscarTipo(char* iden){
    NodoId* aux = raizId;
    while(aux!=NULL){
        if(aux!=NULL&&strcmp(aux->identificador, iden)!=0){  
           aux=aux->next;
        }
        if(aux==NULL){
             return -1; //no se encontro el id 
        }else{
            return aux->tipo;
        }
    }
}



