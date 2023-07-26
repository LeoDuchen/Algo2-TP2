#include "decidir_batalla.h"

bool decidir_batalla(juego_t* juego, pokemon_t* pokemon_rival) {
	gimnasio_t* gimnasio = heap_raiz(juego->heap_gimnasio);

	switch (gimnasio->id_puntero_funcion) {
		case BATALLA_TIPOS:
			return batalla_entre_pokemon(juego, pokemon_rival, &funcion_batalla_1);
			break;
		case BATALLA_NOMBRES:
			return batalla_entre_pokemon(juego, pokemon_rival, &funcion_batalla_2);
			break;
		case BATALLA_CARACTERISTICAS:
			return batalla_entre_pokemon(juego, pokemon_rival, &funcion_batalla_3);
			break;
		case BATALLA_NIVELES:
			return batalla_entre_pokemon(juego, pokemon_rival, &funcion_batalla_4);
			break;
		case BATALLA_EDGY:
			return batalla_entre_pokemon(juego, pokemon_rival, &funcion_batalla_5);
			break;
	}

	return true;
}