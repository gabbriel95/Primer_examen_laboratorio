/*
 * Zonas.h
 *
 *  Created on: 25 nov. 2021
 *      Author: juan
 */

#ifndef ZONAS_H_
#define ZONAS_H_
#include "Input.h"

typedef struct
{
	int idZona;
	char zona[TAM_CARACTERES];
	int pedidosPendientes;
	int isEmpty; // 1 vacio 0 lleno

}eZonas;

#endif /* ZONAS_H_ */
