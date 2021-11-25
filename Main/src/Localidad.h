#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_

#include "Input.h"

typedef struct
{
	int idLocalidad;
	char localidad[TAM_CARACTERES];
	int isEmpty; // 1 vacio 0 lleno

}eLocalidad;
#endif
