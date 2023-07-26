#include "gimnasio.h"

/* Recibe 2 gimnasios, compara sus dificultades y devuelve 0 si son iguales, 1 si el primero 
es mayor que el segundo y -1 si el segundo es mayor que el primero. */
int comparador_dificultad_gimnasio(void* gimnasio1, void* gimnasio2) {
	if ((((gimnasio_t*)gimnasio1)->dificultad) == (((gimnasio_t*)gimnasio2)->dificultad)) {
		return 0;
	} else if ((((gimnasio_t*)gimnasio1)->dificultad) > (((gimnasio_t*)gimnasio2)->dificultad)) {
		return 1;
	} else {
		return -1;
	}
}

/* Recibe un gimnasio y lo libera. */
void destruir_gimnasio(gimnasio_t* gimnasio) {
	free(gimnasio->pila_entrenadores);
	free(gimnasio);
}

/* Verifica que el elemento enviado se pueda liberar y llama a la función que lo libera. */
void destructor_gimnasios(void* elemento) {
	if (!elemento) {
		return;
	}

	destruir_gimnasio((gimnasio_t*)elemento);
}

/* Recibe un entrenador y lo libera. */
void destruir_entrenador(entrenador_t* entrenador) {
	free(entrenador->lista_pokemon);
	free(entrenador);
}

/* Verifica que el elemento enviado se pueda liberar y llama a la función que lo libera. */
void destructor_entrenadores(void* elemento) {
	if (!elemento) {
		return;
	}

	destruir_entrenador((entrenador_t*)elemento);
}

/* Crea un gimnasio reservando la memoria necesaria. */
gimnasio_t* gimnasio_crear() {
	gimnasio_t* gimnasio = calloc(1, 1 * sizeof(gimnasio_t));
	if (!gimnasio) {
		return NULL;
	}

	gimnasio->pila_entrenadores = pila_crear(destructor_entrenadores);
	if (!gimnasio->pila_entrenadores) {
		return NULL;
	}

	return gimnasio;
}

/* Crea un entrenador reservando la memoria necesaria. */
entrenador_t* entrenador_crear() {
	entrenador_t* entrenador = calloc(1, 1 * sizeof(entrenador_t));
	if (!entrenador) {
		return NULL;
	}

	entrenador->lista_pokemon = lista_crear(destructor_pokemon);
	if (!entrenador->lista_pokemon) {
		return NULL;
	}

	return entrenador;
}

/* Pide la ruta de un archivo de gimnasio. */
char* pedir_ruta_gimnasio(char* ruta_gimnasio) {
	printf("Ingrese ruta del gimnasio con extensión \".txt\".\n");
	scanf("%s", ruta_gimnasio);

	return ruta_gimnasio;
}

/* Asigna una frase inicial al entrenador dependiendo el número recibido. */
void frase_inicial_entrenador(char* frase_inicial, int numero_aleatorio) {
	switch (numero_aleatorio) {
		case 0:
			strcpy(frase_inicial, "¡Hoy seré tu rival!");
			break;
		case 1:
			strcpy(frase_inicial, "¡Hora de pelear!");
			break;
		case 2:
			strcpy(frase_inicial, "¡Yo, te desafío!");
			break;
		case 3:
			strcpy(frase_inicial, "¡Mis pokémon estan listos para la batalla!");
			break;
		case 4:
			strcpy(frase_inicial, "¡Despedite de tu cuenta lince");
			break;
		case 5:
			strcpy(frase_inicial, "¡Usar legendarios es trampa!");
			break;
		case 6:
			strcpy(frase_inicial, "¡Enfréntame!");
			break;
		case 7:
			strcpy(frase_inicial, "¡No podrás vencerme!");
			break;
		case 8:
			strcpy(frase_inicial, "¡Demuéstrame tu valor!");
			break;
		case 9:
			strcpy(frase_inicial, "¡Lucharaaán, mucha lucha!");
			break;
		case 10:
			strcpy(frase_inicial, "Quiero ser torero!");
			break;
		case 11:
			strcpy(frase_inicial, "Yo quiero ser siempre el mejor.");
			break;
		case 12:
			strcpy(frase_inicial, "Mejor que nadie más.");
			break;
		case 13:
			strcpy(frase_inicial, "Hora de una batalla Bakug... Pokémon!");
			break;
		case 14:
			strcpy(frase_inicial, "Por la nación Pokémon!");
			break;
		case 15:
			strcpy(frase_inicial, "Shinzou wo Sasageyo!");
			break;
		case 16:
			strcpy(frase_inicial, "I just keep moving forward.");
			break;
		case 17:
			strcpy(frase_inicial, "Subete al Eva, entrenador.");
			break;
	}
}

/* Asigna una frase final al entrenador dependiendo el número recibido. */
void frase_final_entrenador(char* frase_final, int numero_aleatorio) {
	switch (numero_aleatorio) {
		case 0:
			strcpy(frase_final, "¡Bien... tú ganas!");
			break;
		case 1:
			strcpy(frase_final, "¡Buena batalla!");
			break;
		case 2:
			strcpy(frase_final, "Oh, me ganaste...");
			break;
		case 3:
			strcpy(frase_final, "¡Mis pokémon NO estaban listos para la batalla!");
			break;
		case 4:
			strcpy(frase_final, "Debí entrenar Digimon...");
			break;
		case 5:
			strcpy(frase_final, "¡TRAMPAAAAAAAA!");
			break;
		case 6:
			strcpy(frase_final, "¡Buena partida chaval!");
			break;
		case 7:
			strcpy(frase_final, "¡Eres genial!");
			break;
		case 8:
			strcpy(frase_final, "¡Sí... perdí!");
			break;
		case 9:
			strcpy(frase_final, "El sol y la luna serán cenizas y mitos. ¡El cambio viene!");
			break;
		case 10:
			strcpy(frase_final, "Omedeto.");
			break;
		case 11:
			strcpy(frase_final, "Until my enemies are destroyed.");
			break;
		case 12:
			strcpy(frase_final, "Goku! AAAAAAH!.");
			break;
		case 13:
			strcpy(frase_final, "Oh no, perdí...");
			break;
		case 14:
			strcpy(frase_final, "Nunca saldré de bronce.");
			break;
		case 15:
			strcpy(frase_final, "Nos volveremos a ver...");
			break;
		case 16:
			strcpy(frase_final, "Mi pokémon... ha perdido?");
			break;
		case 17:
			strcpy(frase_final, "Edward es un vampiro?");
			break;
	}
}

/* Asigna una frase inicial y una final al entrenador. */
void asignar_frases_entrenador(entrenador_t* entrenador) {
	frase_inicial_entrenador(entrenador->frase_inicial, numero_aleatorio());
	frase_final_entrenador(entrenador->frase_final, numero_aleatorio());
}

void liberar_gimnasio(gimnasio_t* gimnasio) {
	if (!gimnasio) {
		return;
	}

	while (pila_elementos(gimnasio->pila_entrenadores) != 0) {
		entrenador_t* entrenador = lista_tope(gimnasio->pila_entrenadores);
		while (lista_elementos(entrenador->lista_pokemon) != 0) {
			lista_borrar(entrenador->lista_pokemon);
		}
		lista_desapilar(gimnasio->pila_entrenadores);
	}
}

/* Libera al gimnasio que fue creado mientras se intentaba crear la lista de gimnasios. 
Cambia el estado de la función a ERROR. */
void liberar_gimnasio_creado(gimnasio_t* gimnasio, int* estado_funcion) {
	if (!gimnasio) {
		return;
	}

	liberar_gimnasio(gimnasio);
	free(gimnasio->pila_entrenadores);
	free(gimnasio);
	*estado_funcion = ERROR;
}

/* Libera al entrenador que fue creado mientras se intentaba crear la lista de gimnasios. 
Cambia el estado de la función a ERROR. */
void liberar_entrenador_creado(gimnasio_t* gimnasio, entrenador_t* entrenador, int* estado_funcion) {
	if ((!gimnasio) || (!entrenador)) {
		return;
	}

	liberar_gimnasio_creado(gimnasio, estado_funcion);
	free(entrenador->lista_pokemon);
	free(entrenador);
}

/* Libera al Pokémon que fue creado mientras se intentaba crear la lista de gimnasios. 
Cambia el estado de la función a ERROR. */
void liberar_pokemon_gym(gimnasio_t* gimnasio, pokemon_t* pokemon, int* estado_funcion) {
	if ((!gimnasio) || (!pokemon)) {
		return;
	}

	liberar_gimnasio_creado(gimnasio, estado_funcion);
	free(pokemon);
}

/* Libera la lista de gimnasios. 
Cambia el estado de la función a ERROR. */
void* liberar_lista_gimnasios(lista_t* lista_gimnasios, int* estado_funcion) {
	if (!lista_gimnasios) {
		return NULL;
	}

	while (lista_elementos(lista_gimnasios) != 0) {
		gimnasio_t* gimnasio_a_liberar = lista_ultimo(lista_gimnasios);
		liberar_gimnasio_creado(gimnasio_a_liberar, estado_funcion);
		lista_borrar(lista_gimnasios);
	}
	lista_destruir(lista_gimnasios);

	return NULL;
}

/* Carga los gimnasios por medio de un archivo, los inserta y devuelve en una lista. */
lista_t* cargar_gimnasio(const char* ruta_gimnasio) {
	if (!ruta_gimnasio) return NULL;
	int estado_funcion = EXITO;
	char caracter_inicial = CHAR_VACIO;
	bool gimnasio_existente = false;
	gimnasio_t* gimnasio;
	entrenador_t* entrenador;

	FILE* archivo_gimnasio = fopen(ruta_gimnasio, "r");
	if (!archivo_gimnasio) {
		return NULL;
	}
	if ((fscanf(archivo_gimnasio, FORMATO_LECTURA_CARACTER, &caracter_inicial) != 1) || (caracter_inicial != GIMNASIO_CHAR)) {
		fclose(archivo_gimnasio);
		return NULL;
	}
	lista_t* lista_gimnasios = lista_crear(NULL);
	if (!lista_gimnasios) {
		fclose(archivo_gimnasio);
		return NULL;
	}

	while (fscanf(archivo_gimnasio, FORMATO_LECTURA_CARACTER, &caracter_inicial) == 1) {
		if (caracter_inicial == GIMNASIO_CHAR) {
			if (gimnasio_existente) {
				if (lista_insertar(lista_gimnasios, gimnasio) == ERROR) {
					liberar_gimnasio_creado(gimnasio, &estado_funcion);
					break;
				}
			}
			gimnasio = gimnasio_crear();
			gimnasio_existente = true;
			if ((!gimnasio) || (fscanf(archivo_gimnasio, FORMATO_LECTURA_GIMNASIO, gimnasio->nombre, &gimnasio->dificultad, &gimnasio->id_puntero_funcion) != 3)) {
				liberar_gimnasio_creado(gimnasio, &estado_funcion);
				break;
			}
		} else if ((caracter_inicial == LIDER_CHAR) || (caracter_inicial == ENTRENADOR_CHAR)) {
			entrenador = entrenador_crear();
			if ((!entrenador) || (fscanf(archivo_gimnasio, FORMATO_LECTURA_ENTRENADOR, entrenador->nombre) != 1)) {
				liberar_entrenador_creado(gimnasio, entrenador, &estado_funcion);
				break;
			}
			asignar_frases_entrenador(entrenador);
			if (lista_apilar(gimnasio->pila_entrenadores, entrenador) == ERROR) {
				liberar_entrenador_creado(gimnasio, entrenador, &estado_funcion);
				break;
			}
		} else if (caracter_inicial == POKEMON_CHAR) {
			if (lista_elementos(entrenador->lista_pokemon) < MAX_POKEMON_EQUIPO) {
				pokemon_t* pokemon = pokemon_crear();
				if ((!pokemon) || (fscanf(archivo_gimnasio, FORMATO_LECTURA_POKEMON, pokemon->nombre, &pokemon->velocidad, &pokemon->ataque, &pokemon->defensa) != 4)) {
					liberar_pokemon_gym(gimnasio, pokemon, &estado_funcion);
					break;
				}
				asignar_nivel_tipo(pokemon);
				if (lista_insertar(entrenador->lista_pokemon, pokemon) == ERROR) {
					liberar_pokemon_gym(gimnasio, pokemon, &estado_funcion);
					break;
				}
			}	
		} else {
			liberar_gimnasio_creado(gimnasio, &estado_funcion);
			break;
		}
	}
	fclose(archivo_gimnasio);

	if (estado_funcion == ERROR) {
		return liberar_lista_gimnasios(lista_gimnasios, &estado_funcion);
	}
	if (lista_insertar(lista_gimnasios, gimnasio) == ERROR) {
		return liberar_lista_gimnasios(lista_gimnasios, &estado_funcion);
	}
	return lista_gimnasios;
}

/* Inserta los gimnasios en el heap de gimnasios. */
bool insertar_gimnasios(void* elemento, void* contexto) {
	if (!elemento) {
		return false;
	}

	if (heap_insertar(contexto, (gimnasio_t*)elemento) == ERROR) {
		return false;
	}

    return true;
}

int agregar_heap_gimnasios(juego_t* juego, const char* ruta_gimnasio) {
	if ((!juego) || (!ruta_gimnasio)) {
		return ERROR;
	}
	if (!juego->heap_gimnasio) {
		if (!(juego->heap_gimnasio = heap_crear(comparador_dificultad_gimnasio, destructor_gimnasios))) {
			return ERROR;
		}
	}

	lista_t* lista_gimnasios = cargar_gimnasio(ruta_gimnasio);
	if (!lista_gimnasios) {
		return ERROR;
	}
	lista_con_cada_elemento(lista_gimnasios, insertar_gimnasios, juego->heap_gimnasio);
	lista_destruir(lista_gimnasios);

	return EXITO;
}

/* Pide un carácter para el menú del gimnasio. */
void pedir_caracter_gimnasio(char* input) {
	printf("\n\t\tMenú de Gimnasio\n%c) Muestra el entrenador principal junto a sus Pokémon.\n%c) Muestra la información del gimnasio actual.\n%c) Permite cambiar los Pokémon de batalla.\n%c) Realiza la próxima batalla planificada.\n", MOSTRAR_PRINCIPAL, INFO_GIMNASIO, CAMBIAR_POKEMON, PROXIMA_BATALLA);
	*input = (char)obtener_caracter();
}

/* Muestra las características del Pokémon. */
bool mostrar_pokemon(void* elemento, void* contexto) {
	if (!elemento) {
		return false;
	}

	printf("%i  \t%s  \t%i  \t%i  \t%i  \t%i  \t%s\n", *(int*)contexto, ((pokemon_t*)elemento)->nombre, ((pokemon_t*)elemento)->velocidad, ((pokemon_t*)elemento)->ataque, ((pokemon_t*)elemento)->defensa, ((pokemon_t*)elemento)->nivel, ((pokemon_t*)elemento)->tipo);
	*(int*)contexto += 1;

    return true;
}

/* Muestra la información del personaje principal y sus Pokémon. */
void mostrar_info_principal(juego_t* juego, lista_t* lista_pokemon) {
	if ((!juego) || (!lista_pokemon)) {
		return;
	}

	int contador = 1;

	printf("\t\t\t%s\nPos. | Pokémon | Velocidad | Ataque | Defensa | Nivel | Tipo\n-------------------------------------------------------------\n", juego->personaje->nombre);
	lista_con_cada_elemento(lista_pokemon, mostrar_pokemon, (void*)&contador);
}

/* Muestra la información del gimnasio actual. */
void mostrar_info_gimnasio(juego_t* juego) {
	if (!juego) {
		return;
	}

	gimnasio_t* gimnasio = heap_raiz(juego->heap_gimnasio);
	entrenador_t* entrenador = lista_tope(gimnasio->pila_entrenadores);
	size_t cantidad_entrenadores = pila_elementos(gimnasio->pila_entrenadores);

	printf("Nombre: %s\nDificultad: %i\nID Batalla: %i\nSiguiente entrenador a batallar: %s\nEntrenadores que faltan derrotar: %li\n", gimnasio->nombre, gimnasio->dificultad, gimnasio->id_puntero_funcion, entrenador->nombre, cantidad_entrenadores);
}

/* Borra en la posición del Pokémon a sacar e inserta el Pokémon a incluir, y viceversa. */
int intercambiar_posiciones_pokemon(lista_t* lista_pokemon, size_t posicion_pokemon_sacar, size_t posicion_pokemon_incluir, pokemon_t* pokemon_sacar, pokemon_t* pokemon_incluir) {
	if (!lista_pokemon) {
		return ERROR;
	}

	if (lista_borrar_de_posicion(lista_pokemon, posicion_pokemon_sacar - 1) == ERROR) {
		return ERROR;
	}

	if (lista_insertar_en_posicion(lista_pokemon, pokemon_incluir, posicion_pokemon_sacar - 1) == ERROR) {
		return ERROR;
	}

	if (posicion_pokemon_incluir == lista_elementos(lista_pokemon)) {
		if (lista_borrar(lista_pokemon) == ERROR) {
			return ERROR;
		}
	} else {
		if (lista_borrar_de_posicion(lista_pokemon, posicion_pokemon_incluir - 1) == ERROR) {
			return ERROR;
		}
	}

	if (lista_insertar_en_posicion(lista_pokemon, pokemon_sacar, posicion_pokemon_incluir - 1) == ERROR) {
		return ERROR;
	}

	return EXITO;
}

/* Pide la posición del Pokémon a sacar del equipo de combate. */
size_t pedir_pos_poke_sacar() {
	size_t posicion_pokemon_sacar = 0;

	while ((posicion_pokemon_sacar < 1) || (posicion_pokemon_sacar > MAX_POKEMON_EQUIPO)) {
		printf("\nEscriba la posición Pokémon que desees sacar:\n");
		scanf("%zu", &posicion_pokemon_sacar);
	}

	return posicion_pokemon_sacar;
}

/* Pide la posición del Pokémon a incluir en el equipo de combate. */
size_t pedir_pos_poke_incluir(juego_t* juego) {
	size_t posicion_pokemon_incluir = 0;

	while ((posicion_pokemon_incluir < 1) || (posicion_pokemon_incluir > lista_elementos(juego->personaje->lista_pokemon_obtenidos))) {
		printf("\nAhora, la posición del Pokémon que quieras incluir:\n");
		scanf("%zu", &posicion_pokemon_incluir);
	}

	return posicion_pokemon_incluir;
}

void cambiar_pokemon_batalla(juego_t* juego) {
	if ((!juego) || (lista_elementos(juego->personaje->lista_pokemon_obtenidos) < MAX_POKEMON_EQUIPO)) {
		return;
	}

	mostrar_info_principal(juego, juego->personaje->lista_pokemon_obtenidos);
	size_t posicion_pokemon_sacar = pedir_pos_poke_sacar();
	size_t posicion_pokemon_incluir = pedir_pos_poke_incluir(juego);
	lista_cambiar_destructor(juego->personaje->lista_pokemon_obtenidos, NULL);

	pokemon_t* pokemon_sacar = lista_elemento_en_posicion(juego->personaje->lista_pokemon_obtenidos, posicion_pokemon_sacar - 1);
	pokemon_t* pokemon_incluir = lista_elemento_en_posicion(juego->personaje->lista_pokemon_obtenidos, posicion_pokemon_incluir - 1);

	if (intercambiar_posiciones_pokemon(juego->personaje->lista_pokemon_obtenidos, posicion_pokemon_sacar, posicion_pokemon_incluir, pokemon_sacar, pokemon_incluir) == ERROR) {
		return;
	}
	lista_cambiar_destructor(juego->personaje->lista_pokemon_obtenidos, destructor_pokemon);
	asignar_pokemon_combate(juego->personaje);
}

/* Pide la posición de un Pokémon del líder para incluir en el equipo de combate. */
size_t pedir_pos_poke_lider(size_t cantidad_pokemon_lider) {
	size_t posicion_pokemon = 0;

	while ((posicion_pokemon < 1) || (posicion_pokemon > cantidad_pokemon_lider)) {
		printf("\nQue Pokémon deseas tomar prestado? Escriba una posición.:\n");
		scanf("%zu", &posicion_pokemon);
	}

	return posicion_pokemon;
}

/* Recibe dos Pokémon e iguala las características de uno al otro. */
void copiar_caracteristicas_pokemon(pokemon_t* pokemon_incluir, pokemon_t* pokemon_auxiliar) {
	strcpy(pokemon_incluir->nombre, pokemon_auxiliar->nombre);
	pokemon_incluir->velocidad = pokemon_auxiliar->velocidad;
	pokemon_incluir->ataque = pokemon_auxiliar->ataque;
	pokemon_incluir->defensa = pokemon_auxiliar->defensa;
	pokemon_incluir->nivel = pokemon_auxiliar->nivel;
	strcpy(pokemon_incluir->tipo, pokemon_auxiliar->tipo);
}

/* Toma un Pokémon del lider y lo incorpora a la lista de Pokémon obtenidos del personaje principal. */
void tomar_pokemon_lider(juego_t* juego, entrenador_t* lider) {
	if (!juego) {
		return;
	}
	int contador = 1;

	printf("\t\t\t%s\nPos. | Pokémon | Velocidad | Ataque | Defensa | Nivel | Tipo\n-------------------------------------------------------------\n", juego->personaje->nombre);
	lista_con_cada_elemento(lider->lista_pokemon, mostrar_pokemon, (void*)&contador);

	size_t posicion_pokemon = pedir_pos_poke_lider(lista_elementos(lider->lista_pokemon));
	pokemon_t* pokemon_incluir = pokemon_crear();
	if (!pokemon_incluir) {
		return;
	}

	pokemon_t* pokemon_auxiliar = lista_elemento_en_posicion(lider->lista_pokemon, posicion_pokemon - 1);
	copiar_caracteristicas_pokemon(pokemon_incluir, pokemon_auxiliar);

	if (lista_insertar(juego->personaje->lista_pokemon_obtenidos, pokemon_incluir) == ERROR) {
		return;
	}
}

/* Aumenta las características del Pokémon. */
void aumentar_puntos_pokemon(pokemon_t* pokemon) {
	if (!pokemon) {
		return;
	}

	if (pokemon->puntos_ganados < MAX_PUNTOS) {
		pokemon->velocidad++;
		pokemon->ataque++;
		pokemon->defensa++;
		pokemon->nivel++;
		pokemon->puntos_ganados++;
	}
}

/* Pide N para continuar a la siguiente batalla. */
void pedir_continuar_combate(bool simular_juego) {
	char input = CHAR_VACIO;

	printf("\nIngrese N para continuar a la siguiente batalla Pokémon.\n");
	while ((!simular_juego) && (input != PROXIMO_COMBATE)) {
		input = (char)obtener_caracter();
	}

	system("clear");
}

bool batalla_entre_pokemon(juego_t* juego, pokemon_t* pokemon_rival, int (*funcion_batalla)(void*, void*)) {
	if ((!juego) || (!pokemon_rival)) {
		return false;
	}
	int ganador_batalla = 0, contador_derrotas = 0;

	while ((contador_derrotas < lista_elementos(juego->personaje->lista_pokemon_combate)) && (ganador_batalla != GANO_PRIMERO)) {
		ganador_batalla = funcion_batalla(lista_elemento_en_posicion(juego->personaje->lista_pokemon_combate, (size_t)contador_derrotas), pokemon_rival);
		if (ganador_batalla == GANO_SEGUNDO) {
			pedir_continuar_combate(juego->simular_juego);
			contador_derrotas++;
		} else {
			aumentar_puntos_pokemon(lista_elemento_en_posicion(juego->personaje->lista_pokemon_combate, (size_t)contador_derrotas));
		}
	}

	if (contador_derrotas == lista_elementos(juego->personaje->lista_pokemon_combate)) {
		menu_derrota(juego);
		return false;
	}

	return true;
}

/* Libera la memoria reservada por el entrenador. */
void liberar_entrenador(gimnasio_t* gimnasio, entrenador_t* entrenador) {
	if ((!gimnasio) || (!entrenador)) {
		return;
	}

	while (lista_elementos(entrenador->lista_pokemon) != 0) {
		lista_borrar(entrenador->lista_pokemon);
	}

	lista_desapilar(gimnasio->pila_entrenadores);
}

/* Devuelve la cantidad de entrenadores que faltan derrotar. */
size_t cantidad_entrenadores_faltantes(gimnasio_t* gimnasio, entrenador_t* entrenador, size_t cantidad_entrenadores) {
	printf("\n%s: %s\n---------------------------------------------------\n", entrenador->nombre, entrenador->frase_final);
	if (cantidad_entrenadores > 1) {
		liberar_entrenador(gimnasio, entrenador);
	}

	return cantidad_entrenadores - 1;
}

void batalla_gimnasio(juego_t* juego) {
	if (!juego) {
		return;
	}
	bool seguir_combatiendo = true;
	gimnasio_t* gimnasio = heap_raiz(juego->heap_gimnasio);
	size_t cantidad_entrenadores = pila_elementos(gimnasio->pila_entrenadores), cantidad_pokemon = 0;

	while ((cantidad_entrenadores != 0) && (seguir_combatiendo)) {
		entrenador_t* entrenador = lista_tope(gimnasio->pila_entrenadores);
		cantidad_pokemon = lista_elementos(entrenador->lista_pokemon);
		printf("\n%s: %s\n", entrenador->nombre, entrenador->frase_inicial);
		while ((cantidad_pokemon != 0) && (seguir_combatiendo)) {
			pokemon_t* pokemon_rival = lista_elemento_en_posicion(entrenador->lista_pokemon, lista_elementos(entrenador->lista_pokemon) - cantidad_pokemon);
			pedir_continuar_combate(juego->simular_juego);
			seguir_combatiendo = decidir_batalla(juego, pokemon_rival);
			cantidad_pokemon--;
		}

		if (seguir_combatiendo) {
			cantidad_entrenadores = cantidad_entrenadores_faltantes(gimnasio, entrenador, cantidad_entrenadores);
		}
		if (!juego->terminar_partida) {
			seguir_combatiendo = true;
		}
	}
}

/* Pide un carácter para el menú de victoria. */
void pedir_caracter_victoria(char* input) {
	printf("\n\tLe ganaste al líder del gimnasio!\n%c) Pedir prestando un Pokémon del líder e incorporarlo al equipo.\n%c) Permite cambiar los Pokémon de batalla.\n%c) Próximo gimnasio.\n", TOMAR_POKEMON, CAMBIAR_POKEMON, PROXIMO_COMBATE);
	*input = (char)obtener_caracter();
}

void limpiar_pantalla_input(char* input) {
	system("clear");
	*input = CHAR_VACIO;
}

/* Muestra las opciones al ganar un gimnasio. */
void menu_victoria(juego_t* juego, entrenador_t* lider) {
	if (!juego) {
		return;
	}
	char input = CHAR_VACIO;

	while ((input != TOMAR_POKEMON) && (input != CAMBIAR_POKEMON) && (input != PROXIMO_COMBATE)) {
		if (!juego->simular_juego) {
			pedir_caracter_victoria(&input);
		}

		if (input == TOMAR_POKEMON) {
			limpiar_pantalla_input(&input);
			tomar_pokemon_lider(juego, lider);
		}

		if (input == CAMBIAR_POKEMON) {
			limpiar_pantalla_input(&input);
			cambiar_pokemon_batalla(juego);
		}

		if ((input == PROXIMO_COMBATE) || (juego->simular_juego)) {
			limpiar_pantalla_input(&input);
			return;
		}
	}
}

void menu_gimnasio(juego_t* juego) {
	if (!juego) return;
	char input = CHAR_VACIO;
	system("clear");

	while ((input != MOSTRAR_PRINCIPAL) && (input != INFO_GIMNASIO) && (input != CAMBIAR_POKEMON) && (input != PROXIMA_BATALLA)) {
		if (!juego->simular_juego) {
			pedir_caracter_gimnasio(&input);
		}
		if (input == MOSTRAR_PRINCIPAL) {
			limpiar_pantalla_input(&input);
			mostrar_info_principal(juego, juego->personaje->lista_pokemon_combate);
		}
		if (input == INFO_GIMNASIO) {
			limpiar_pantalla_input(&input);
			mostrar_info_gimnasio(juego);
		}
		if (input == CAMBIAR_POKEMON) {
			limpiar_pantalla_input(&input);
			cambiar_pokemon_batalla(juego);
		}
		if ((input == PROXIMA_BATALLA) || (juego->simular_juego)) {
			system("clear");
			batalla_gimnasio(juego);
			if (!juego->terminar_partida) {
				gimnasio_t* gimnasio = heap_raiz(juego->heap_gimnasio);
				entrenador_t* lider = lista_tope(gimnasio->pila_entrenadores);
				input = CHAR_VACIO;
				menu_victoria(juego, lider);
				liberar_entrenador(gimnasio, lider);
				heap_extraer_raiz(juego->heap_gimnasio);
				if (heap_vacio(juego->heap_gimnasio) == true) {
					printf("Has vencido a todos los gimnasios, eres un maestro Pokémon!\n");
					break;
				}
			}
			if (juego->terminar_partida) {
				printf("Perdiste.\n");
				break;
			}
		}
	}
}