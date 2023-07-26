#include "interfaz.h"
#include "gimnasio.h"

/* Recibe un Pokémon y lo libera. */
void destruir_pokemon(pokemon_t* pokemon) {
	free(pokemon);
}

void destructor_pokemon(void* elemento) {
	if (!elemento) {
		return;
	}

	destruir_pokemon((pokemon_t*)elemento);
}

int obtener_caracter() {
	int letra;
	int c;
	letra = getchar();

	while ((c = getchar()) != EOF && (c != '\n'));

	return letra;
}

void pedir_caracter_inicio(char* input) {
	printf("────────▄███████████▄────────\n─────▄███▓▓▓▓▓▓▓▓▓▓▓███▄─────\n────███▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓███────\n───██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██───\n──██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██──\n─██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██─\n██▓▓▓▓▓▓▓▓▓███████▓▓▓▓▓▓▓▓▓██\n██▓▓▓▓▓▓▓▓██░░░░░██▓▓▓▓▓▓▓▓██\n██▓▓▓▓▓▓▓██░░███░░██▓▓▓▓▓▓▓██\n███████████░░███░░███████████\n\tAventura Pokémon\n██░░░░░░░██░░███░░██░░░░░░░██\n██░░░░░░░░██░░░░░██░░░░░░░░██\n██░░░░░░░░░███████░░░░░░░░░██\n─██░░░░░░░░░░░░░░░░░░░░░░░██─\n──██░░░░░░░░░░░░░░░░░░░░░██──\n───██░░░░░░░░░░░░░░░░░░░██───\n────███░░░░░░░░░░░░░░░███────\n─────▀███░░░░░░░░░░░███▀─────\n────────▀███████████▀────────\n\tMenú Principal\n%c) Ingresa el archivo del entrenador principal.\n%c) Agrega un gimnasio al árbol de gimnasios.\n%c) Comienza la partida.\n%c) Simula la partida.\n", INGRESAR_ARCHIVO, AGREGAR_GIMNASIO, COMENZAR_PARTIDA, SIMULAR_PARTIDA);
	*input = (char)obtener_caracter();
}

char* pedir_ruta_personaje(char* ruta_personaje) {
	printf("Ingrese ruta del \"personaje_principal.txt\".\n");
	scanf("%s", ruta_personaje);

	return ruta_personaje;
}

/* Crea al personaje principal reservando la memoria necesaria. */
personaje_t* personaje_crear() {
	personaje_t* personaje = calloc(1, 1 * sizeof(personaje_t));
	if (!personaje) {
		return NULL;
	}

	personaje->lista_pokemon_obtenidos = lista_crear(destructor_pokemon);
	if (!personaje->lista_pokemon_obtenidos) {
		return NULL;
	}

	return personaje;
}

pokemon_t* pokemon_crear() {
	pokemon_t* pokemon = calloc(1, 1 * sizeof(pokemon_t));
	if (!pokemon) {
		return NULL;
	}

	return pokemon;
}

int asignar_pokemon_combate(personaje_t* personaje) {
	pokemon_t** pokemon_asignado;
	int estado_insertar = ERROR;
	int cantidad_pokemon = 0;

	if (personaje->lista_pokemon_combate) {
		lista_destruir(personaje->lista_pokemon_combate);
		personaje->lista_pokemon_combate = lista_crear(NULL);
	}

	if (lista_elementos(personaje->lista_pokemon_obtenidos) > MAX_POKEMON_EQUIPO) {
		cantidad_pokemon = MAX_POKEMON_EQUIPO;
	} else {
		cantidad_pokemon = (int)lista_elementos(personaje->lista_pokemon_obtenidos);
	}

	for (size_t i = 0; i < cantidad_pokemon; i++) {
		pokemon_asignado = lista_elemento_en_posicion(personaje->lista_pokemon_obtenidos, i);
		estado_insertar = lista_insertar(personaje->lista_pokemon_combate, pokemon_asignado);
	}

	return estado_insertar;
}

int numero_aleatorio() {
	int numero_aleatorio = 0;
	numero_aleatorio = rand() % ALEATORIO_RANGO_MAX;

	return numero_aleatorio;
}

/* Asigna un tipo de Pokémon dependiendo el número recibido. */
void tipo_pokemon(char* tipo_pokemon, int numero_aleatorio) {
	switch (numero_aleatorio) {
		case TIPO_NORMAL:
			strcpy(tipo_pokemon, "Normal");
			break;
		case TIPO_AGUA:
			strcpy(tipo_pokemon, "Agua");
			break;
		case TIPO_FUEGO:
			strcpy(tipo_pokemon, "Fuego");
			break;
		case TIPO_PLANTA:
			strcpy(tipo_pokemon, "Planta");
			break;
		case TIPO_ELECTRICO:
			strcpy(tipo_pokemon, "Eléctrico");
			break;
		case TIPO_TIERRA:
			strcpy(tipo_pokemon, "Tierra");
			break;
		case TIPO_ROCA:
			strcpy(tipo_pokemon, "Roca");
			break;
		case TIPO_VENENO:
			strcpy(tipo_pokemon, "Veneno");
			break;
		case TIPO_DRAGON:
			strcpy(tipo_pokemon, "Dragón");
			break;
		case TIPO_PSIQUICO:
			strcpy(tipo_pokemon, "Psíquico");
			break;
		case TIPO_FANTASMA:
			strcpy(tipo_pokemon, "Fantasma");
			break;
		case TIPO_SINIESTRO:
			strcpy(tipo_pokemon, "Siniestro");
			break;
		case TIPO_BICHO:
			strcpy(tipo_pokemon, "Bicho");
			break;
		case TIPO_HADA:
			strcpy(tipo_pokemon, "Hada");
			break;
		case TIPO_HIELO:
			strcpy(tipo_pokemon, "Hielo");
			break;
		case TIPO_ACERO:
			strcpy(tipo_pokemon, "Acero");
			break;
		case TIPO_VOLADOR:
			strcpy(tipo_pokemon, "Volador");
			break;
		case TIPO_LUCHA:
			strcpy(tipo_pokemon, "Lucha");
			break;
	}
}

void asignar_nivel_tipo(pokemon_t* pokemon) {
	pokemon->nivel = 1;
	tipo_pokemon(pokemon->tipo, numero_aleatorio());
}

void destruir_personaje_principal(personaje_t* personaje) {
	if (!personaje) {
		return;
	}

	if (personaje->lista_pokemon_combate) {
		lista_destruir(personaje->lista_pokemon_combate);
	}

	if (personaje->lista_pokemon_obtenidos) {
		lista_destruir(personaje->lista_pokemon_obtenidos);
	}

	free(personaje);
}

/* Libera el Pokémon que fue creado mientras se intentaba crear al personaje principal. 
Cambia el estado de la función a ERROR. */
void liberar_pokemon_creado(pokemon_t* pokemon, int* estado_funcion) {
	if (!pokemon) {
		return;
	}

	free(pokemon);
	*estado_funcion = ERROR;
}

int crear_personaje_principal(juego_t* juego, const char* ruta_personaje) {
	if ((!juego) || (!ruta_personaje)) return ERROR;
	int estado_funcion = EXITO;
	char caracter_inicial = CHAR_VACIO;

	FILE* archivo_personaje = fopen(ruta_personaje, "r");
	if (!archivo_personaje) {
		return ERROR;
	}
	if ((fscanf(archivo_personaje, FORMATO_LECTURA_CARACTER, &caracter_inicial) != 1) || (caracter_inicial != ENTRENADOR_CHAR)) {
		fclose(archivo_personaje);
		return ERROR;
	}
	personaje_t* personaje = personaje_crear();
	if (!personaje) {
		fclose(archivo_personaje);
		return ERROR;
	}
	if (fscanf(archivo_personaje, FORMATO_LECTURA_ENTRENADOR, personaje->nombre) != 1) {
		fclose(archivo_personaje);
		return ERROR;
	}

	while (fscanf(archivo_personaje, FORMATO_LECTURA_CARACTER, &caracter_inicial) == 1) {
		if (caracter_inicial == POKEMON_CHAR) {
			pokemon_t* pokemon = pokemon_crear();
			if ((!pokemon) || (fscanf(archivo_personaje, FORMATO_LECTURA_POKEMON, pokemon->nombre, &pokemon->velocidad, &pokemon->ataque, &pokemon->defensa) != 4)) {
				liberar_pokemon_creado(pokemon, &estado_funcion);
				break;
			}
			asignar_nivel_tipo(pokemon);
			if (lista_insertar(personaje->lista_pokemon_obtenidos, pokemon) == ERROR) {
				liberar_pokemon_creado(pokemon, &estado_funcion);
				break;
			}
		} else {
			estado_funcion = ERROR;
			break;
		}
	}
	fclose(archivo_personaje);

	if ((estado_funcion == ERROR) || (!(personaje->lista_pokemon_combate = lista_crear(NULL))) || (asignar_pokemon_combate(personaje) == ERROR)) {
		destruir_personaje_principal(personaje);
		return ERROR;
	}
	juego->personaje = personaje;
	return EXITO;
}

/* Pide un carácter para el menú de derrota. */
void pedir_caracter_derrota(char* input) {
	printf("\n\tTe han derrotado...\n%c) Permite cambiar los Pokémon de batalla.\n%c) Reintenta el gimnasio.\n%c) Finaliza la partida.\n", CAMBIAR_POKEMON, REINTENTAR_GIMNASIO, FINALIZAR_PARTIDA);
	*input = (char)obtener_caracter();
}

void vaciar_heap_gimnasio(heap_t* heap) {
	if (!heap) {
		return;
	}

	while (!heap_vacio(heap)) {
		liberar_gimnasio(heap_raiz(heap));
		heap_extraer_raiz(heap);
	}
}

/* Muestra las opciones al ser derrotado. */
void menu_derrota(juego_t* juego) {
	if (!juego) {
		return;
	}
	char input = CHAR_VACIO;

	while ((input != CAMBIAR_POKEMON) && (input != REINTENTAR_GIMNASIO) && (input != FINALIZAR_PARTIDA)) {
		if (!juego->simular_juego) {
			pedir_caracter_derrota(&input);
		}

		if (input == CAMBIAR_POKEMON) {
			limpiar_pantalla_input(&input);
			cambiar_pokemon_batalla(juego);
		}

		if (input == REINTENTAR_GIMNASIO) {
			limpiar_pantalla_input(&input);
			return;		
		}

		if ((input == FINALIZAR_PARTIDA) || (juego->simular_juego)) {
			limpiar_pantalla_input(&input);
			vaciar_heap_gimnasio(juego->heap_gimnasio);
			juego->terminar_partida = true;
			return;
		}
	}
}