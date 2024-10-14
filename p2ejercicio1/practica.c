/*******************************
* Práctica
* Implementa los siguientes subalgoritmos
* Incluir aquí la implementación de cualquier otro subalgoritmo que se considere necesario
*/

#include "practica.h"
#include <stdlib.h>
#include <stdio.h>


/*
* Crea un lista enlazada de números enteros vacía
* Parámetros:
*   lista :    estructura de datos
*/
void vacia( Lista* lista ){
    *lista=NULL; 
}

/*
* Almacena un valor al final de la lista
* Parámetros:
*   lista :    lista enlazada donde almacenar el valor al final
*   valor :     valor que se almacena
*   ok :        devuelve verdadero si se pudo almacenar el valor. Falso en caso contrario
*/
void almacenaValor( Lista* lista, int valor, bool* ok ){
    *ok = false; 
    Lista tmp =(Lista)malloc(sizeof(struct Nodo)); 
    if(tmp==NULL){
        return; 
    }
    tmp->dato=valor; 
    tmp->siguiente=NULL; 
    if(*lista == NULL){
        *lista=tmp; 
        *ok=true; 
    }else{
        Lista actual = *lista; 
        while (actual->siguiente!=NULL){
            actual=actual->siguiente; 
        }
        actual->siguiente=tmp; 
        if(actual->siguiente==tmp){
            *ok=true; 
        }
    }
}

/*
* Obtiene un valor en una posición de la lista
* Parámetros:
*   lista :  lista enlazada
*   pos :    posición que se quiere devolver
*   ok  :    devuelve verdadero si la posición es válida. Falso en caso contrario
* Devuelve:
*   Valor almacenado en la lista en la posición recibida o 0 si la posición no es válida
*/
int obtieneValor( Lista lista, unsigned pos, bool* ok ){
    Lista actual = lista; 
    unsigned contador = 0; 
    int num = 0; 

    while (actual!=NULL && contador<pos)
    {
        actual=actual->siguiente; 
        contador++; 
    }

    if(actual!=NULL){
        *ok=true; 
        num=actual->dato; 
    }else{
        *ok=false; 
    }
    return num; //Si se ha encontrado, devuelve el valor, sino, devuelve 0. 
}
 
 
/* 
* Devuelve cuantos números hay en la lista
* Parámetros:
*   lista :   lista enlazada
* Devuelve:
*   El número de nodos de la lista
*/
unsigned longitud( Lista lista ){
    unsigned contador =0; 
    Lista actual = lista; 
    while(actual!=NULL){
        contador++; 
        actual=actual->siguiente; 
    }
    return contador; //Devuelve el numero de nodos de la lista 
}

/* 
* Libera la memoria asignada a la lista
* Debe dejar el puntero de la lista a NULL
*/
void liberaLista( Lista* lista ){
    Lista actual = *lista; 
    Lista siguiente; 

    while(actual!=NULL){
        siguiente = actual->siguiente; 
        free(actual); //Liberamos memoria del nodo actual
        actual=siguiente; 
    }

    *lista=NULL; //Nos aseguramos de que esta a null. 
}


/*
* Función para buscar si un dato existe en una lista
* Parámetros:
*   lista : lista enlazada
*   datos : valor que se quiere buscar
* Devuelve:
*   Verdadero si dato esta en algún nodo de la lista o falso en caso contrario
*/
bool buscar(Lista lista, int dato) {
    Lista tmp = lista;
    
    //Recorro la lista hasta encontrarlo o terminar de recorrerla
    while (tmp!=NULL)
    {
        if(tmp->dato==dato){
            return true;  //Devuelve valor true si se encuentra el numero en alguna instancia, saliendo del while antes de recorrer la lista por completo
        }else{
            tmp=tmp->siguiente; //Seguir iterando por los elementos de la lista si aun no se ha encontrado 
        }
    }
    //Devolver si se ha encontrado el numero (true) o no (false)
    return false;  
}


/*
* Función que devuelve los elementos de la primera lista que no están en la segunda
* Parámetros:
*   lista1 y lista2 : Listas 
* Devuelve:
*   Una nueva lista con los elementos de la primera lista que no están en la segunda y los elementos de la 
*   segunda que no están en la primera. Las lista orignales (lista1 y lista2) no deben modificarse.
*   Los valores deben mantener el orden en que se encontraban en la lista original. Además, primero aparecerán los valores
*   provenientes de la lista1 y después los de la lista2
*/
Lista diferenciaSimetrica(Lista lista1, Lista lista2) {
    Lista resultado = NULL; 
    bool ok; 

    //Añado elementos de lista1 que no esten en lista2
    Lista actual1 = lista1; 
    while(actual1!=NULL){
        if(!buscar(lista2, actual1->dato)){
            almacenaValor(&resultado, actual1->dato, &ok); 
        }
        actual1=actual1->siguiente; 
    }

    //Añado elementos de lista2 que no esten en lista1
    Lista actual2 = lista2; 
    while(actual2!=NULL){
        if(!buscar(lista1, actual2->dato)){
            almacenaValor(&resultado, actual2->dato, &ok); 
        }
        actual2=actual2->siguiente; 
    }

    return resultado; 
}