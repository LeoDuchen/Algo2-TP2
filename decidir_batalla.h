#ifndef __DECIDIR_BATALLA_H__
#define __DECIDIR_BATALLA_H__

#include "interfaz.h"
#include "gimnasio.h"

/* Dependiendo el ID puntero a función del gimnasio, devuelve la función de batalla correspondiente. */
bool decidir_batalla(juego_t* juego, pokemon_t* pokemon_rival);

#endif /* __DECIDIR_BATALLA_H__ */