/*******************************
* Ejemplo de uso de la práctica
* Este programa lee una cantidad de números de teclado, los muestra por pantalla y muestra su suma.
*/

#include <stdio.h>
#include <stdlib.h>
#include "practica.h"


void leerLista( Lista* lista ){
	int v;
	bool ok;

	vacia( lista );	

	printf( "Teclea números enteros y finaliza con un valor 0\n" );
	
	scanf( "%d", &v );
	while (v != 0){
		almacenaValor( lista, v, &ok );
		if (!ok){
			printf( "Error al almacenar valor\n" );
			exit( 1 );
		}
		scanf( "%d", &v );
	}
}

void imprimirLista( Lista lista ){
	bool ok;
	
	printf( "Números en la lista:\n" );
	for( unsigned k = 0; k < longitud( lista ); k++ ){
		printf( "%d ", obtieneValor( lista, k, &ok ) );
		if (!ok){
			printf( "Error al obtener valor\n" );
			exit( 1 );
		}
	}
	printf( "\n" );
}


int main(){
	Lista lista1, lista2, diferencia;
	
	
	printf( "Introducción de la lista 1\n" );
	leerLista( &lista1 );

	printf( "Introducción de la lista 2\n" );
	leerLista( &lista2 );

	printf( "Los números que has tecleado en la lista 1 son:\n" );
	imprimirLista( lista1 );
	
	printf( "Los números que has tecleado en la lista 2 son:\n" );
	imprimirLista( lista2 );
	
	diferencia = diferenciaSimetrica( lista1, lista2 );
	
	printf( "\nLa diferencia simétrica de lista 1 y lista 2 es:\n" );
	imprimirLista( diferencia );
	
	liberaLista( &lista1 );
	liberaLista( &lista2 );
	liberaLista( &diferencia );

	return 0;
}


