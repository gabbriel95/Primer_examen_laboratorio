#ifndef CLIENTES_H_
#define CLIENTES_H_

#include "Input.h"
#include "Localidad.h"

typedef struct
{
	int idCliente;
	char nombreEmpresa[TAM_CARACTERES];
	char cuit[TAM_CUIT];
	char direccion[TAM_CARACTERES];
	int idLocalidad;
	int isEmpty; // 1 vacio 0 lleno
	int contadorPendientes;
	int contadorCompletados;
	int idZona;
}eCliente;

void InicializarListaClientes(eCliente listaClientes[], int sizeClientes);
int VerificarSiHayUnCliente(eCliente listaClientes[], int sizeClientes);
int VerificarEspacioEnLista(eCliente listaClientes[], int sizeClientes);
int VerificarId(eCliente listaClientes[], int sizeClientes, int IdAValidar);

void AumentarContadorPendientes(eCliente listaClientes[], int sizeClientes, int idCliente);
void DisminuirContadorPendientes(eCliente listaClientes[], int sizeClientes, int idCliente);

int CargarListaClientes(eCliente listaClientes[], int sizeClientes, int* idCliente);
int ModificarCliente(eCliente listaClientes[], int sizeClientes, eLocalidad listaLocalidades[], int sizeLocalidades);
int EliminarCliente(eCliente listaClientes[], int sizeClientes, eLocalidad listaLocalidades[], int sizeLocalidades);

void MostrarCliente(eCliente cliente, eLocalidad localidad);
int MostrarListaClientes(eCliente listaClientes[], int sizeClientes, eLocalidad listaLocalidades[], int sizeLocalidades);

int ContadorClientes(eCliente listaClientes[], int sizeClientes, int* contador);



#endif
