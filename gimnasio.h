#ifndef __GIMNASIO_H__
#define __GIMNASIO_H__

#include "interfaz.h"
#include "decidir_batalla.h"

/* Pide y devuelve la ruta de un archivo de gimnasio. */
char* pedir_ruta_gimnasio();

/* Libera la memoria reservada por el gimnasio. */
void liberar_gimnasio(gimnasio_t* gimnasio);

/* Agrega gimnasios al heap de gimnasios. */
int agregar_heap_gimnasios(juego_t* juego, const char* ruta_gimnasio);

/* Permite cambiar los Pokémon de batalla dependiendo las posiciones que sean introducidas. */
void cambiar_pokemon_batalla(juego_t* juego);

/* Hace batallar a los Pokémon del personaje principal, contando sus derrotas. */
bool batalla_entre_pokemon(juego_t* juego, pokemon_t* pokemon_rival, int (*funcion_batalla)(void*, void*));

/* Simula la batalla en un gimnasio. */
void batalla_gimnasio(juego_t* juego);

/* Limpia la pantalla y el input. */
void limpiar_pantalla_input(char* input);

/* Muestra las opciones del gimnasio. */
void menu_gimnasio(juego_t* juego);

#endif /* __GIMNASIO_H__ */