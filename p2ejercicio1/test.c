/*******************************
* Prueba de la práctica
*/

#include <stdio.h>
#include <assert.h>
#include "practica.h"
#include "test_lista.h"

#define NPRUEBAS 100000
#define LPRUEBA 100

const char rueda[] = {'|', '/', '-', '\\' }; 

void test_prueba_diferencias(){
	Lista lista1, lista2, d;
	bool ok;
	int v, a;
	
	test_iniciar( );
	
	vacia( &lista1 );
	vacia( &lista2 );
	
	for( unsigned k = 0; k < LPRUEBA; k++ ){
		assert( longitud( lista1 ) == k );
		v = test_generarValor1();
		
		almacenaValor( &lista1, v, &ok );
		assert( ok );
		a = obtieneValor( lista1, k, &ok );
		assert( ok );
		assert( a == v );
	}
	assert( longitud( lista1 ) == LPRUEBA );
		
	for( unsigned k = 0; k < LPRUEBA; k++ ){
		assert( longitud( lista2 ) == k );
		v = test_generarValor2();
		
		almacenaValor( &lista2, v, &ok );
		assert( ok );
		a = obtieneValor( lista2, k, &ok );
		assert( ok );
		assert( a == v );
	}
	assert( longitud( lista2 ) == LPRUEBA );
	
	d = diferenciaSimetrica( lista1, lista2);
	
	assert( test_diferenciaSimetrica( d ));
	
	liberaLista( &d );
	test_finalizar();
}



int main() {
	for( unsigned k = 0; k < NPRUEBAS; k++ ){
		printf( "\r(%c)", rueda[k%4] );
		fflush(stdout);
		test_prueba_diferencias();
	}
	
  printf("Todas las pruebas pasaron exitosamente.\n");
  return 0;
}

