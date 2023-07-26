#include "interfaz.h"

/* Muestra la información de los dos Pokémon. */
void mostrar_info_pokemon(void* pkm_1, void* pkm_2) {
	printf("\n\tComienza la batalla entre %s y %s!\n", ((pokemon_t*)pkm_1)->nombre, ((pokemon_t*)pkm_2)->nombre);
	printf("\n%s tiene una velocidad de %i, una ataque de %i, una defensa de %i, un nivel de %i y es de tipo %s.\n", ((pokemon_t*)pkm_1)->nombre, ((pokemon_t*)pkm_1)->velocidad, ((pokemon_t*)pkm_1)->ataque, ((pokemon_t*)pkm_1)->defensa, ((pokemon_t*)pkm_1)->nivel, ((pokemon_t*)pkm_1)->tipo);
	printf("\nMientras que %s tiene una velocidad de %i, una ataque de %i, una defensa de %i, un nivel de %i y es de tipo %s.\n", ((pokemon_t*)pkm_2)->nombre, ((pokemon_t*)pkm_2)->velocidad, ((pokemon_t*)pkm_2)->ataque, ((pokemon_t*)pkm_2)->defensa, ((pokemon_t*)pkm_2)->nivel, ((pokemon_t*)pkm_2)->tipo);
	printf("\n\t¿Quién ganará esta batalla?\n\n");
}

/* Devuelve al Pokémon ganador dependiendo su tipo. 
Si por alguna razón ningún Pokémon cumple las condiciones, gana el primero. */
int ganador_tipo(void* pkm_1, void* pkm_2) {
	if ((!pkm_1) || (!pkm_2)) {
		return GANO_PRIMERO;
	}

	if ((strcmp(((pokemon_t*)pkm_1)->tipo, "Dragón") == 0) || (strcmp(((pokemon_t*)pkm_1)->tipo, "Psíquico") == 0)|| (strcmp(((pokemon_t*)pkm_1)->tipo, "Veneno") == 0) || (strcmp(((pokemon_t*)pkm_1)->tipo, "Roca") == 0) || (strcmp(((pokemon_t*)pkm_1)->tipo, "Fantasma") == 0) || (strcmp(((pokemon_t*)pkm_1)->tipo, "Siniestro") == 0)) {
		if ((strcmp(((pokemon_t*)pkm_2)->tipo, "Bicho") == 0) || (strcmp(((pokemon_t*)pkm_2)->tipo, "Hada") == 0) || (strcmp(((pokemon_t*)pkm_2)->tipo, "Hielo") == 0) || (strcmp(((pokemon_t*)pkm_2)->tipo, "Acero") == 0) || (strcmp(((pokemon_t*)pkm_2)->tipo, "Volador") == 0) || (strcmp(((pokemon_t*)pkm_2)->tipo, "Lucha") == 0)) {
			return GANO_SEGUNDO;
		} else {
			return GANO_PRIMERO;
		}
	}
	if ((strcmp(((pokemon_t*)pkm_1)->tipo, "Bicho") == 0) || (strcmp(((pokemon_t*)pkm_1)->tipo, "Hada") == 0) || (strcmp(((pokemon_t*)pkm_1)->tipo, "Hielo") == 0) || (strcmp(((pokemon_t*)pkm_2)->tipo, "Acero") == 0) || (strcmp(((pokemon_t*)pkm_1)->tipo, "Volador") == 0) || (strcmp(((pokemon_t*)pkm_1)->tipo, "Lucha") == 0)) {
		if ((strcmp(((pokemon_t*)pkm_2)->tipo, "Normal") == 0) || (strcmp(((pokemon_t*)pkm_2)->tipo, "Agua") == 0) || (strcmp(((pokemon_t*)pkm_2)->tipo, "Fuego") == 0) || (strcmp(((pokemon_t*)pkm_2)->tipo, "Planta") == 0) || (strcmp(((pokemon_t*)pkm_2)->tipo, "Eléctrico") == 0) || (strcmp(((pokemon_t*)pkm_2)->tipo, "Tierra") == 0)) {
			return GANO_SEGUNDO;
		} else {
			return GANO_PRIMERO;
		}
	}
	if ((strcmp(((pokemon_t*)pkm_1)->tipo, "Normal") == 0) || (strcmp(((pokemon_t*)pkm_1)->tipo, "Agua") == 0) || (strcmp(((pokemon_t*)pkm_1)->tipo, "Fuego") == 0) || (strcmp(((pokemon_t*)pkm_1)->tipo, "Planta") == 0) || (strcmp(((pokemon_t*)pkm_1)->tipo, "Eléctrico") == 0) || (strcmp(((pokemon_t*)pkm_1)->tipo, "Tierra") == 0)) {
		if ((strcmp(((pokemon_t*)pkm_2)->tipo, "Dragón") == 0) || (strcmp(((pokemon_t*)pkm_2)->tipo, "Psíquico") == 0) || (strcmp(((pokemon_t*)pkm_2)->tipo, "Veneno") == 0) || (strcmp(((pokemon_t*)pkm_2)->tipo, "Roca") == 0) || (strcmp(((pokemon_t*)pkm_2)->tipo, "Fantasma") == 0) || (strcmp(((pokemon_t*)pkm_2)->tipo, "Siniestro") == 0)) {
			return GANO_SEGUNDO;
		} else {
			return GANO_PRIMERO;
		}
	}

	return GANO_PRIMERO;
}

/* El Pokémon que tenga un tipo ventajoso sobre el otro gana la batalla. 
Si hay algún error, gana el primero. */
int funcion_batalla_1(void* pkm_1, void* pkm_2) {
	if ((!pkm_1) || (!pkm_2)) {
		return GANO_PRIMERO;
	}

	mostrar_info_pokemon(pkm_1, pkm_2);

	int ganador = ganador_tipo(pkm_1, pkm_2);

	if (ganador == GANO_PRIMERO) {
		printf("%s es de tipo %s y tiene ventaja sobre %s que es de tipo %s, así que %s es el ganador!\n", ((pokemon_t*)pkm_1)->nombre, ((pokemon_t*)pkm_1)->tipo, ((pokemon_t*)pkm_2)->nombre, ((pokemon_t*)pkm_2)->tipo, ((pokemon_t*)pkm_1)->nombre);
	} else {
		printf("%s es de tipo %s y tiene ventaja sobre %s que es de tipo %s, así que %s es el ganador!\n", ((pokemon_t*)pkm_2)->nombre, ((pokemon_t*)pkm_2)->tipo, ((pokemon_t*)pkm_1)->nombre, ((pokemon_t*)pkm_1)->tipo, ((pokemon_t*)pkm_2)->nombre);
	}

	return ganador;
}

/* Devuelve al Pokémon ganador dependiendo de su nombre. 
Si por alguna razón ningún Pokémon cumple las condiciones, gana el primero. */
int ganador_nombre(void* pkm_1, void* pkm_2) {
	if ((!pkm_1) || (!pkm_2)) {
		return GANO_PRIMERO;
	}

	if ((strlen(((pokemon_t*)pkm_2)->nombre)) > (strlen(((pokemon_t*)pkm_1)->nombre))) {
		return GANO_SEGUNDO;
	} else {
		return GANO_PRIMERO;
	}

	return GANO_PRIMERO;
}

/* El Pokémon que tenga un nombre más largo gana la batalla. 
Si hay algún error, gana el primero. */
int funcion_batalla_2(void* pkm_1, void* pkm_2) {
	if ((!pkm_1) || (!pkm_2)) {
		return GANO_PRIMERO;
	}

	mostrar_info_pokemon(pkm_1, pkm_2);

	int ganador = ganador_nombre(pkm_1, pkm_2);

	if (ganador == GANO_PRIMERO) {
		printf("%s tiene un nombre más largo que %s, así que %s es el ganador!\n", ((pokemon_t*)pkm_1)->nombre, ((pokemon_t*)pkm_2)->nombre, ((pokemon_t*)pkm_1)->nombre);
	} else {
		printf("%s tiene un nombre más largo que %s, así que %s es el ganador!\n", ((pokemon_t*)pkm_2)->nombre, ((pokemon_t*)pkm_1)->nombre, ((pokemon_t*)pkm_2)->nombre);
	}

	return ganador;
}

/* Devuelve al Pokémon ganador dependiendo de sus características. 
Si por alguna razón ningún Pokémon cumple las condiciones, gana el primero. */
int ganador_caracteristicas(void* pkm_1, void* pkm_2) {
	if ((!pkm_1) || (!pkm_2)) {
		return GANO_PRIMERO;
	}

	if ((((((pokemon_t*)pkm_2)->velocidad) + (((pokemon_t*)pkm_2)->ataque) + (((pokemon_t*)pkm_2)->defensa)) / 3) > (((((pokemon_t*)pkm_1)->velocidad) + (((pokemon_t*)pkm_1)->ataque) + (((pokemon_t*)pkm_1)->defensa)) / 3)) {
		return GANO_SEGUNDO;
	} else {
		return GANO_PRIMERO;
	}

	return GANO_PRIMERO;
}

/* El Pokémon que tenga características más altas gana la batalla. 
Si hay algún error, gana el primero. */
int funcion_batalla_3(void* pkm_1, void* pkm_2) {
	if ((!pkm_1) || (!pkm_2)) {
		return GANO_PRIMERO;
	}

	mostrar_info_pokemon(pkm_1, pkm_2);

	int ganador = ganador_caracteristicas(pkm_1, pkm_2);

	if (ganador == GANO_PRIMERO) {
		printf("%s tiene una suma de características más altas que %s, así que %s es el ganador!\n", ((pokemon_t*)pkm_1)->nombre, ((pokemon_t*)pkm_2)->nombre, ((pokemon_t*)pkm_1)->nombre);
	} else {
		printf("%s tiene una suma de características más altas que %s, así que %s es el ganador!\n", ((pokemon_t*)pkm_2)->nombre, ((pokemon_t*)pkm_1)->nombre, ((pokemon_t*)pkm_2)->nombre);
	}

	return ganador;
}

/* Devuelve al Pokémon ganador dependiendo de su nivel. 
Si por alguna razón ningún Pokémon cumple las condiciones, gana el primero. */
int ganador_nivel(void* pkm_1, void* pkm_2) {
	if ((!pkm_1) || (!pkm_2)) {
		return GANO_PRIMERO;
	}

	if (((pokemon_t*)pkm_2)->nivel > ((pokemon_t*)pkm_1)->nivel) {
		return GANO_SEGUNDO;
	} else {
		return GANO_PRIMERO;
	}

	return GANO_PRIMERO;
}

/* El Pokémon que tenga características nivel más alto gana la batalla. 
Si hay algún error, gana el primero. */
int funcion_batalla_4(void* pkm_1, void* pkm_2) {
	if ((!pkm_1) || (!pkm_2)) {
		return GANO_PRIMERO;
	}

	mostrar_info_pokemon(pkm_1, pkm_2);

	int ganador = ganador_nivel(pkm_1, pkm_2);

	if (ganador == GANO_PRIMERO) {
		printf("%s tiene un nivel de %i y %s tiene un nivel de %i, así que %s es el ganador!\n", ((pokemon_t*)pkm_1)->nombre, ((pokemon_t*)pkm_1)->nivel, ((pokemon_t*)pkm_2)->nombre, ((pokemon_t*)pkm_2)->nivel, ((pokemon_t*)pkm_1)->nombre);
	} else {
		printf("%s tiene un nivel de %i y %s tiene un nivel de %i, así que %s es el ganador!\n", ((pokemon_t*)pkm_2)->nombre, ((pokemon_t*)pkm_2)->nivel, ((pokemon_t*)pkm_1)->nombre, ((pokemon_t*)pkm_1)->nivel, ((pokemon_t*)pkm_2)->nombre);
	}

	return ganador;
}

/* Devuelve al Pokémon ganador dependiendo de si es edgy (muy cool). 
Si por alguna razón ningún Pokémon cumple las condiciones, gana el primero. */
int ganador_edgy(void* pkm_1, void* pkm_2) {
	if ((!pkm_1) || (!pkm_2)) {
		return GANO_PRIMERO;
	}

	if ((strcmp(((pokemon_t*)pkm_2)->nombre, "Serperior") == 0) || (strcmp(((pokemon_t*)pkm_2)->nombre, "Charizard") == 0) || (strcmp(((pokemon_t*)pkm_2)->nombre, "Feraligatr") == 0)  || (strcmp(((pokemon_t*)pkm_2)->nombre, "Mewtwo") == 0) || (strcmp(((pokemon_t*)pkm_2)->nombre, "Blastoise") == 0) || (strcmp(((pokemon_t*)pkm_2)->nombre, "Venusaur") == 0) || (strcmp(((pokemon_t*)pkm_2)->nombre, "Zapdos") == 0) || (strcmp(((pokemon_t*)pkm_2)->nombre, "Moltres") == 0) || (strcmp(((pokemon_t*)pkm_2)->nombre, "Articuno") == 0) || (strcmp(((pokemon_t*)pkm_2)->nombre, "Haxorus") == 0) || (strcmp(((pokemon_t*)pkm_2)->nombre, "Metagross") == 0) || (strcmp(((pokemon_t*)pkm_2)->nombre, "Garchomp") == 0)) {
		return GANO_SEGUNDO;
	} else {
		return GANO_PRIMERO;
	}

	return GANO_PRIMERO;
}

/* El Pokémon que sea más edgy gana la batalla. 
Si hay algún error, gana el primero. */
int funcion_batalla_5(void* pkm_1, void* pkm_2) {
	if ((!pkm_1) || (!pkm_2)) {
		return GANO_PRIMERO;
	}

	mostrar_info_pokemon(pkm_1, pkm_2);

	int ganador = ganador_edgy(pkm_1, pkm_2);

	if (ganador == GANO_PRIMERO) {
		printf("%s es más edgy que %s, así que %s es el ganador!\n", ((pokemon_t*)pkm_1)->nombre, ((pokemon_t*)pkm_2)->nombre, ((pokemon_t*)pkm_1)->nombre);
	} else {
		printf("%s es más edgy que %s, así que %s es el ganador!\n", ((pokemon_t*)pkm_2)->nombre, ((pokemon_t*)pkm_1)->nombre, ((pokemon_t*)pkm_2)->nombre);
	}

	return ganador;
}