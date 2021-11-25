#ifndef PEDIDOS_H_
#define PEDIDOS_H_

#include "Input.h"

typedef struct
{
	int idPedido;
	int idCliente;
	char estadoPedido[TCADENA];
	int isEmpty;
	float cantidadTotalARecolectar;
	float kgHdpe;
	float kgLdpe;
	float gkPp;
}ePedido;

void InicializarListaPedidos(ePedido listaPedidos[], int sizePedidos);
int CargarPedido(ePedido listaPedidos[], int sizePedidos, int* idPedido, int idCliente);
int VerificarSiHayUnPedido(ePedido listaPedidos[], int sizePedidos);
int VerificarSiHayUnPedidoProcesado(ePedido listaPedidos[], int sizePedidos);
int VerificarSiHayUnPedidoPendiente(ePedido listaPedidos[], int sizePedidos);
void MostrarPedido(ePedido listaPedidos);
int MostrarListaPedidos(ePedido listaPedidos[], int sizePedidos);
int VerificarIdPedido(ePedido listaPedidos[], int sizePedidos, int IdAValidar);
int VerificarEstadoPedido(ePedido listaPedidos);
int AcumuladorPolipropileno(ePedido listaPedidos[], int sizePedidos, float* acumulador);
#endif
