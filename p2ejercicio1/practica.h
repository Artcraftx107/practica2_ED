/*******************************
* Práctica
* Realizar una ejercicio que utilice una estructura de datos consistente en una lista
* enlazada de números enteros
*/

#ifndef PRACTICA_H
#define PRACTICA_H

#include <stdbool.h>

typedef struct Nodo{
	int dato;
	struct Nodo* siguiente;
} Nodo;

typedef Nodo* Lista;


/*
* Crea un lista enlazada de números enteros vacía
* Parámetros:
*   lista :    estructura de datos
*/
void vacia( Lista* lista );

/*
* Almacena un valor al final de la lista
* Parámetros:
*   lista :    lista enlazada donde almacenar el valor al final
*   valor :     valor que se almacena
*   ok :        devuelve verdadero si se pudo almacenar el valor. Falso en caso contrario
*/
void almacenaValor( Lista* lista, int valor, bool* ok );

/*
* Obtiene un valor en una posición de la lista
* Parámetros:
*   lista :  lista enlazada
*   pos :    posición que se quiere devolver
*   ok  :    devuelve verdadero si la posición es válida. Falso en caso contrario
* Devuelve:
*   Valor almacenado en la lista en la posición recibida o 0 si la posición no es válida
*/
int obtieneValor( Lista lista, unsigned pos, bool* ok );

/* 
* Devuelve cuantos números hay en la lista
* Parámetros:
*   lista :   lista enlazada
* Devuelve:
*   El número de nodos de la lista
*/
unsigned longitud( Lista lista );

/* 
* Libera la memoria asignada a la lista
* Debe dejar el puntero de la lista a NULL
*/
void liberaLista( Lista* lista );


/*
* Función para buscar si un dato existe en una lista
* Parámetros:
*   lista : lista enlazada
*   datos : valor que se quiere buscar
* Devuelve:
*   Verdadero si dato esta en algún nodo de la lista o falso en caso contrario
*/
bool buscar(Lista lista, int dato);


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
Lista diferenciaSimetrica(Lista lista1, Lista lista2);




#endif


