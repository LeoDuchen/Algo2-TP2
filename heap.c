#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

#define ERROR -1
#define EXITO 0

heap_t* heap_crear(heap_comparador comparador, heap_liberar_elemento destructor) {
	if (!comparador) {
		return NULL;
	}

	heap_t* heap = malloc(1 * sizeof(heap_t));
	if (!heap) {
		return NULL;
	}

	heap->vector = NULL;
	heap->tope = 0;
	heap->comparador = comparador;
	heap->destructor = destructor;

	return heap;
}

heap_t* heap_crear_desde_vector(void** vector, int n, heap_comparador comparador, heap_liberar_elemento destructor) {
	if ((!vector) || (!comparador)) {
		return NULL;
	}

	return NULL;
}

/* Devuelve la posición del padre. */
int posicion_padre(int n) {
	return ((n - 1) / 2);
}

/* Devuelve la posición del hijo derecho. */
int posicion_hijo_derecho(int n) {
	return ((2 * n) + 2);
}

/* Devuelve la posición del hijo izquierdo. */
int posicion_hijo_izquierdo(int n) {
	return ((2 * n) + 1);
}

/* Intercambia los valores. */
void swap(void** vector, int i, int j) {
	if (!vector) {
		return;
	}

	void* auxiliar = vector[i];
	vector[i] = vector[j];
	vector[j] = auxiliar;
}

void sift_up(heap_t* heap, int n) {
	if (n == 0) {
		return;
	}

	int padre = posicion_padre(n);

	if ((heap->comparador(heap->vector[n], heap->vector[padre])) < 0) {
		swap(heap->vector, n, padre);
		sift_up(heap, padre);
	}
}

int heap_insertar(heap_t* heap, void* elemento) {
	if (!heap) {
		return ERROR;
	}

	void* auxiliar = realloc(heap->vector, sizeof(void*) * (long unsigned)(heap->tope + 1));
	if (!auxiliar) {
		return ERROR;
	}

	heap->tope++;
	heap->vector = auxiliar;

	heap->vector[heap->tope - 1] = elemento;
	sift_up(heap, heap->tope - 1);

	return EXITO;
}

void sift_down(heap_t* heap, int n) {
	int posicion_derecha = posicion_hijo_derecho(n);
	int posicion_izquierda = posicion_hijo_izquierdo(n);
	int posicion_mayor = posicion_izquierda;

	if (posicion_izquierda >= heap->tope) {
		return;
	}

	if (posicion_derecha < heap->tope) {
		if (heap->comparador(heap->vector[posicion_derecha], heap->vector[posicion_izquierda]) < 0) {
			posicion_mayor = posicion_derecha;
		}
	}

	if (heap->comparador(heap->vector[n], heap->vector[posicion_mayor]) > 0) {
		swap(heap->vector, n, posicion_mayor);
		sift_down(heap, posicion_mayor);
	}
}

void* heap_raiz(heap_t* heap) {
	if ((!heap) || (heap->tope == 0)) {
		return NULL;
	}

	return heap->vector[0];
}

void* heap_extraer_raiz(heap_t* heap) {
	if ((!heap) || (heap->tope == 0)) {
		return 0;
	}

	void* valor = heap->vector[0];

	if (heap->destructor) {
		heap->destructor(valor);
	}

	swap(heap->vector, 0, heap->tope - 1);

	void* auxiliar = realloc(heap->vector, sizeof(void*) * (long unsigned)(heap->tope - 1));

	heap->vector = auxiliar;

	heap->tope--;

	if (heap->tope != 0) {
		sift_down(heap, 0);
	}

	return valor;
}

bool heap_vacio(heap_t* heap) {
	if ((!heap) || (heap->tope == 0)) {
		return true;
	}

	return false;
}

void heap_destruir(heap_t* heap) {
	if (!heap) {
		return;
	}

	if (heap->destructor) {
		for (int i = 0; i < heap->tope; i++) {
			heap->destructor(heap->vector[i]);
		}
	}

	free(heap->vector);
	free(heap);
}

heap_t* heapify(void** vector, int n) {
	heap_t* mi_heap = NULL;
	mi_heap->vector = vector;
	mi_heap->tope = n;

	int primero = posicion_padre(n - 1);

	while (primero >= 0) {
		sift_down(mi_heap, primero);
		primero--;
	}

	return mi_heap;
}

void heap_sort(void** vector, int n) {
	heap_t* heap = heapify(vector, n);

	while (n > 0) {
		heap_extraer_raiz(heap);
		n--;
	}
}