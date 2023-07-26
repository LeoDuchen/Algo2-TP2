#include "interfaz.h"
#include "gimnasio.h"

/* Crea al juego reservando la memoria necesaria. */
juego_t* juego_crear() {
	juego_t* juego = calloc(1, 1 * sizeof(juego_t));
	if (!juego) {
		return NULL;
	}

	return juego;
}

/* Libera la memoria reservada por el juego. */
void liberar_juego(juego_t* juego) {
	if (!juego) {
		return;
	}

	if (juego->heap_gimnasio) {
		heap_destruir(juego->heap_gimnasio);
	}

	destruir_personaje_principal(juego->personaje);
	free(juego);
}

/* Pide la ruta del personaje principal para poder crearlo. */
int ingresar_personaje(juego_t* juego, char* input) {
	char ruta[MAX_CHAR] = STRING_VACIO;

	if (crear_personaje_principal(juego, pedir_ruta_personaje(ruta)) == ERROR) {
		return ERROR;
	}
	*input = CHAR_VACIO;

	return EXITO;
}

/* Pide la ruta del gimnasio para poder agregarlo al heap de gimnasios. */
int ingresar_gimnasio(juego_t* juego, char* input) {
	char ruta[MAX_CHAR] = STRING_VACIO;

	if (agregar_heap_gimnasios(juego, pedir_ruta_gimnasio(ruta)) == ERROR) {
		return ERROR;
	}
	*input = CHAR_VACIO;

	return EXITO;
}

/* Ingresa un personaje principal por default y lo crea. */
int ingresar_personaje_default(juego_t* juego) {
	if (crear_personaje_principal(juego, ARCHIVO_PERSONAJE_DEFAULT) == ERROR) {
		return ERROR;
	}

	return EXITO;
}

/* Ingresa gimnasios por default al heap de gimnasios. */
int ingresar_gimnasio_default(juego_t* juego) {
	if (agregar_heap_gimnasios(juego, ARCHIVO_GIMNASIO_DEFAULT) == ERROR) {
		return ERROR;
	}

	return EXITO;
}

int main() {
	char input = CHAR_VACIO;
	srand ((unsigned)time(NULL));
	juego_t* juego = juego_crear();

	if (juego) {
		while ((input != INGRESAR_ARCHIVO) && (input != AGREGAR_GIMNASIO) && (input != COMENZAR_PARTIDA) && (input != SIMULAR_PARTIDA)) {
			system("clear");
			pedir_caracter_inicio(&input);
			if (input == INGRESAR_ARCHIVO) {
				destruir_personaje_principal(juego->personaje);
				if (ingresar_personaje(juego, &input) == ERROR) {
					break;
				}
			}
			if (input == AGREGAR_GIMNASIO) {
				if (ingresar_gimnasio(juego, &input) == ERROR) {
					vaciar_heap_gimnasio(juego->heap_gimnasio);
					break;
				}
			}
			if ((input == COMENZAR_PARTIDA) || (input == SIMULAR_PARTIDA)) {
				if (input == SIMULAR_PARTIDA) {
					juego->simular_juego = true;
				}
				if (!juego->personaje) {
					if (ingresar_personaje_default(juego) == ERROR) {
						break;
					}
				}
				if (!juego->heap_gimnasio) {
					if (ingresar_gimnasio_default(juego) == ERROR) {
						break;
					}
				}
				menu_gimnasio(juego);
			}
		}
	}
	liberar_juego(juego);
	return 0;
}