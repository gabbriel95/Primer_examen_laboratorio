#ifndef INPUT_H_
#define INPUT_H_

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

#define TCADENA 51
#define TAM_CLIENTES 100
#define TAM_PEDIDOS 1000
#define TAM_LOCALIDADES 20
#define TAM_ESTADO_PEDIDOS 2
#define TAM_CARACTERES 51
#define TAM_CUIT 12
#define PENDIENTE "Pendiente"
#define COMPLETADO "Completado"

#define TAM_ZONAS 3
#define ZONA_UNO "1er Cordon del conurbano"
#define ZONA_DOS "2do Cordon del conurbano"
#define ZONA_TRES "3er Cordon del conurbano"



int PedirCadenaChars(char cadena[], int tam, char mensaje[], char mensajeError[], int reintentos);

/// @brief Recorre la cadena para verificar si los caracteres del array son letras o no
/// @param cadena array de caracteres
/// @return		return (0) no es letra   (1) es letra
int EsChar(char* cadena);

/// @brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un maximo
/// 		de longitud -1 caracteres
/// @param cadena Puntero al espacio de memoria donde se copiara la cadena obtenida
/// @param longitud Define el tamaño de la cadena
/// @return Retorna 1 (exito) si se obtiene una cadena y 0(error) si no
int MyGets(char* cadena, int longitud);


/// @brief Obtener un numero entero desde la terminal
///
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return Retorna 0 (exito) si se obtiene un entero y -1 (error)
///
int GetInt(int* pResultado);

/// @brief Solicita el ingreso de un entero por mensaje y lo retorna por puntero pResultado
/// @param pResultado  Numero a retoronar
/// @param mensaje		Mensaje
/// @param mensajeError Mensaje Error
/// @param minimo		Rango minimo de numeros que puede ingresar
/// @param maximo		Rango maximo de numeros que puede ingresar
/// @param reintentos   Cantidad de reintentos
/// @return   return (1) If ok,   (0) Error, se quedo sin reintentos
int Utn_GetNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/// @brief  Solicita el ingreso de un numero decimal por mensaje y retorna por puntero pResultado
/// @param pResultado  puntero numero a retornar
/// @param mensaje		mensaje
/// @param mensajeError	mensaje error
/// @param minimo		rango minimo de numeros que puede ingresar
/// @param maximo		rango maximo de numeros que puede ingresar
/// @param reintentos   cantidad de reintentos
/// @return  return (1) If ok,   (0) Error, se quedo sin reintentos
int Utn_GetNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

/// @brief Verifica que la cadena de chars ingresada sea un cuit de 11 numeros
/// @param cadena Cadena a verificar
/// @return (1) if Ok, (0) Error, no son numeros
int verificaCuit(char* cadena);

/// @brief Solicita el ingreso de un cuit de 11 numeros, si tiene exito lo carga
/// @param  Cuit[] cadena a retornar si tiene exito
/// @param reintentos Cantidad de posibilidades de error
/// @return (1) if Ok, (0) Error
int cargarCuit(char cuit[], int reintentos);

/// @brief  Solicita el ingreso de numeros y letra por mensaje y retorna por cadena cadena
/// @param cadena  puntero a cadena a retornar
/// @param mensaje		mensaje
/// @param mensajeError	mensaje error
/// @param reintentos   cantidad de reintentos
/// @return  return (1) If ok,   (0) Error, se quedo sin reintentos
int PedirAlphaNumerico(char cadena[], int tam, char mensaje[], char mensajeError[], int reintentos);

/// @brief
/// @param pResultado
/// @return retorno(0) if error, (1) if ok
int GetFloat(float* pResultado);

/// @brief Aumenta en 1 el id tomado como parametro
/// @param idCliente puntero a id
/// @return(1) ok --- return(0) Error
int GeneradorId(int* idCliente);


void MenuPedidosPendientes(void);
void MenuPedidosCompletados(void);
#endif /* INPUT_H_ */
