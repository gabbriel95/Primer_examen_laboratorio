#ifndef INFORMES_H_
#define INFORMES_H_

#include "Clientes.h"
#include "Pedidos.h"
#include "Zonas.h"

int AltaPedido(eCliente listaClientes[], int sizeClientes, ePedido listaPedidos[], int sizePedidos, int* idPedido, eLocalidad listaLocalidades[], int sizeLocalidades);


int ImprimirPedidosPendientes(ePedido listaPedidos[], int sizePedidos, eCliente listaClientes[], int sizeClientes);
int ImprimirPedidosCompletados(ePedido listaPedidos[], int sizePedidos, eCliente listaClientes[], int sizeClientes);
int ProcesarPedido(ePedido listaPedidos[], int sizePedidos, eCliente listaClientes[], int sizeClientes);
int ContadorPedidosPXLocalidad(eCliente listaClientes[], int sizeClientes, ePedido listaPedidos[], int sizePedidos, char localidad[], eLocalidad listaLocalidades[], int sizeLocalidades);
int MostrarCantidadPedidosPXLocalidad(eCliente listaClientes[], int sizeClientes, ePedido listaPedidos[], int sizePedidos, eLocalidad listaLocalidad[], int sizeLocalidad);
int CalcularPromedioPolipropileno(eCliente listaClientes[], int sizeClientes, ePedido listaPedidos[], int sizePedidos);

int ClienteConMasPedidosPendientes(eCliente listaClientes[], int sizeClientes, ePedido listaPedidos[], int sizePedidos);
int ClienteConMasPedidosCompletos(eCliente listaClientes[], int sizeClientes, ePedido listaPedidos[], int sizePedidos);

int MostrarPedidosPendientesXZona(eCliente listaClientes[], int sizeClientes, eZonas listaZonas[], int sizeZonas);


#endif
