#ifndef __INTERFAZ_H__
#define __INTERFAZ_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "lista.h"
#include "heap.h"
#include "batallas.h"

static const char INGRESAR_ARCHIVO = 'E', AGREGAR_GIMNASIO = 'A', COMENZAR_PARTIDA = 'I', SIMULAR_PARTIDA = 'S';
static const char GIMNASIO_CHAR = 'G', ENTRENADOR_CHAR = 'E', LIDER_CHAR = 'L', POKEMON_CHAR = 'P';
static const char MOSTRAR_PRINCIPAL = 'E', INFO_GIMNASIO = 'G', CAMBIAR_POKEMON = 'C', PROXIMA_BATALLA = 'B';
static const char PROXIMO_COMBATE = 'N', TOMAR_POKEMON = 'T', REINTENTAR_GIMNASIO = 'R', FINALIZAR_PARTIDA = 'F';
#define FORMATO_LECTURA_ENTRENADOR "%40[^\n]\n"
#define FORMATO_LECTURA_POKEMON "%10[^;];%i;%i;%i\n"
#define FORMATO_LECTURA_GIMNASIO "%40[^;];%i;%i\n"
#define FORMATO_LECTURA_CARACTER "%c;"
#define ARCHIVO_PERSONAJE_DEFAULT "personaje_principal_default.txt"
#define ARCHIVO_GIMNASIO_DEFAULT "gimnasios_teselia_default.txt"

#define MAX_CHAR 101
#define MAX_NOMBRE 41
#define MAX_NOMBRE_POKEMON 11
#define MAX_POKEMON_EQUIPO 6
#define ALEATORIO_RANGO_MAX 17
#define MAX_PUNTOS 63
#define CHAR_VACIO 'a'
#define STRING_VACIO ""
#define ERROR -1
#define EXITO 0

#define TIPO_NORMAL 0
#define TIPO_AGUA 1
#define TIPO_FUEGO 2
#define TIPO_PLANTA 3
#define TIPO_ELECTRICO 4
#define TIPO_TIERRA 5
#define TIPO_ROCA 6
#define TIPO_VENENO 7
#define TIPO_DRAGON 8
#define TIPO_PSIQUICO 9
#define TIPO_FANTASMA 10
#define TIPO_SINIESTRO 11
#define TIPO_BICHO 12
#define TIPO_HADA 13
#define TIPO_HIELO 14
#define TIPO_ACERO 15
#define TIPO_VOLADOR 16
#define TIPO_LUCHA 17

#define BATALLA_TIPOS 1
#define BATALLA_NOMBRES 2
#define BATALLA_CARACTERISTICAS 3
#define BATALLA_NIVELES 4
#define BATALLA_EDGY 5

typedef int (*funcion_batalla)(void*, void*);

typedef struct pokemon{
	char nombre[MAX_NOMBRE_POKEMON];
	int velocidad;
	int ataque;
	int defensa;
	int nivel;
	char tipo[MAX_CHAR];
	int puntos_ganados;
}pokemon_t;

typedef struct entrenador{
	char nombre[MAX_NOMBRE];
	char frase_inicial[MAX_CHAR];
	char frase_final[MAX_CHAR];
	lista_t* lista_pokemon;
}entrenador_t;

typedef struct personaje{
	char nombre[MAX_NOMBRE];
	lista_t* lista_pokemon_combate;
	lista_t* lista_pokemon_obtenidos;
}personaje_t;

typedef struct gimnasio{
	char nombre[MAX_NOMBRE];
	int dificultad;
	int id_puntero_funcion;
	lista_t* pila_entrenadores;
}gimnasio_t;

typedef struct juego{
	personaje_t* personaje;
	heap_t* heap_gimnasio;
	bool simular_juego;
	bool terminar_partida;
}juego_t;

/* Verifica que el elemento enviado se pueda liberar y llama a la función que lo libera. */
void destructor_pokemon(void* elemento);

/* Pide un carácter. */
int obtener_caracter();

/* Pide un carácter para el menú principal. */
void pedir_caracter_inicio(char* input);

/* Pide y devuelve la ruta de un archivo de personaje principal. */
char* pedir_ruta_personaje(char* ruta_personaje);

/* Crea un Pokémon reservando la memoria necesaria. */
pokemon_t* pokemon_crear();

/* Crea punteros a los Pokémon obtenidos para los combates. */
int asignar_pokemon_combate(personaje_t* personaje);

/* La función devuelve un número aleatorio entre 0 y 17 inclusive. */
int numero_aleatorio();

/* Asigna nivel y tipo al Pokémon. */
void asignar_nivel_tipo(pokemon_t* pokemon);

/* Libera la memoria reservada por el personaje principal. */
void destruir_personaje_principal(personaje_t* personaje);

/* Crea al personaje principal, junto a sus Pokémon, desde un archivo, reservando la memoria necesaria. */
int crear_personaje_principal(juego_t* juego, const char* ruta_gimnasio);

/* Libera la memoria del gimnasio y lo borra del heap. */
void vaciar_heap_gimnasio(heap_t* heap);

/* Muestra las opciones al ser derrotado en un gimnasio. */
void menu_derrota(juego_t* juego);

#endif /* __INTERFAZ_H__ */