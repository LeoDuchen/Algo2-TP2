#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdbool.h>

/* Comparador de elementos. Recibe dos elementos del heap y devuelve 
0 en caso de ser iguales, 1 si el primer elemento es mayor al 
segundo o -1 si el primer elemento es menor al segundo. */
typedef int (*heap_comparador)(void*, void*);

/* Destructor de elementos. Cada vez que un elemento deja el heap 
se invoca al destructor pasandole el elemento. */
typedef void (*heap_liberar_elemento)(void*);


typedef struct heap{
	void** vector;
	int tope;
	heap_comparador comparador;
	heap_liberar_elemento destructor;
}heap_t;

/*
 * Crea el heap reservando la memoria necesaria.
 * Devuelve un puntero a un heap creado o NULL en caso de error.
 */
heap_t* heap_crear(heap_comparador comparador, heap_liberar_elemento destructor);

/*
 * Crea el heap desde un vector reservando la memoria necesaria.
 * Devuelve un puntero a un heap creado o NULL en caso de error.
 */
heap_t* heap_crear_desde_vector(void** vector, int n, heap_comparador comparador, heap_liberar_elemento destructor);

/*
 * Inserta un elemento en el heap.
 * Devuelve 0 si pudo insertar o -1 si no pudo.
 */
int heap_insertar(heap_t* heap, void* elemento);

/*
 * Devuelve la raíz del heap.
 */
void* heap_raiz(heap_t* heap);

/*
 * Elimina la raíz del heap y la devuelve.
 */
void* heap_extraer_raiz(heap_t* heap);

/* 
 * Devuelve true si el heap está vacío o false en caso contrario.
 */
bool heap_vacio(heap_t* heap);

/*
 * Libera la memoria reservada por el heap.
 */
void heap_destruir(heap_t* heap);

heap_t* heapify(void** vector, int n);

void heap_sort(void** vector, int n);

#endif /* __HEAP_H__ */