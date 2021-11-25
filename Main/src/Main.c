#include <stdio.h>
#include <stdlib.h>

#include "Input.h"
#include "Clientes.h"
#include "Pedidos.h"
#include "Informes.h"
#include "Localidad.h"
#include "Zonas.h"


int main(void) {

	setbuf(stdout, NULL);

	eCliente listaClientes[TAM_CLIENTES];
	ePedido listaPedidos[TAM_PEDIDOS];
	eLocalidad listaLocalidades[TAM_LOCALIDADES] = {{1,"Quilmes",0},{2,"Varela",0},{3,"Avellaneda",0},{4,"Lanus",0},{5,"Almirante Brown",0}};
	eZonas listaZonas[TAM_ZONAS] = {{1,ZONA_UNO,0,0},{2,ZONA_DOS,0,0},{3,ZONA_TRES,0,0}};

	int opcion;
	int idClientes = 0;
	int idPedidos = 0;

	InicializarListaClientes(listaClientes, TAM_CLIENTES);
	InicializarListaPedidos(listaPedidos, TAM_PEDIDOS);

	do{
		printf(
				"\n1- Alta cliente\n"
				"2- Modificar datos de cliente\n"
				"3- Baja cliente\n"
				"4- Crear pedido de recoleccion\n"
				"5- Procesar residuos\n"
				"6- Imprimir clientes\n"
				"7- Imprimir pedidos pendientes\n"
				"8- Imprimir pedidos procesados\n"
				"9- Pedidos pendientes por localidad\n"
				"10- Promedio de kilos de polipropileno reciclado por cliente\n"
				"11- Cliente con mas pedidos pendientes\n"
				"12- Cliente con mas pedidos completados\n"
				"13- Pedidos pendientes por zona\n"
				"14- Salir\n");

		if(Utn_GetNumero(&opcion, "\nSeleccione una opcion: ", "\nError, a seleccionado una opcion no valida.\n", 1, 14, 3)==1)
		{
			switch(opcion){
					case 1:
						CargarListaClientes(listaClientes, TAM_CLIENTES, &idClientes);
						break;
					case 2:
						ModificarCliente(listaClientes, TAM_CLIENTES, listaLocalidades, TAM_LOCALIDADES);
						break;
					case 3:
						EliminarCliente(listaClientes, TAM_CLIENTES, listaLocalidades, TAM_LOCALIDADES);
						break;
					case 4:
						AltaPedido(listaClientes, TAM_CLIENTES, listaPedidos, TAM_PEDIDOS, &idPedidos, listaLocalidades, TAM_LOCALIDADES);
						break;
					case 5:
						ProcesarPedido(listaPedidos, TAM_PEDIDOS, listaClientes, TAM_CLIENTES);
						break;
					case 6:
						MostrarListaClientes(listaClientes, TAM_CLIENTES, listaLocalidades, TAM_LOCALIDADES);
						break;
					case 7:
						ImprimirPedidosPendientes(listaPedidos, TAM_PEDIDOS, listaClientes, TAM_CLIENTES);
						break;
					case 8:
						ImprimirPedidosCompletados(listaPedidos, TAM_PEDIDOS, listaClientes, TAM_CLIENTES);
						break;
					case 9:
						MostrarCantidadPedidosPXLocalidad(listaClientes, TAM_CLIENTES, listaPedidos, TAM_PEDIDOS, listaLocalidades, TAM_LOCALIDADES);						break;
					case 10:
						CalcularPromedioPolipropileno(listaClientes, TAM_CLIENTES, listaPedidos, TAM_PEDIDOS);
						break;
					case 11:
						ClienteConMasPedidosPendientes(listaClientes, TAM_CLIENTES, listaPedidos, TAM_PEDIDOS);
						break;
					case 12:
						ClienteConMasPedidosCompletos(listaClientes, TAM_CLIENTES, listaPedidos, TAM_PEDIDOS);
						break;
					case 13:
						MostrarPedidosPedidosPendientesXZona(listaClientes, TAM_CLIENTES, listaPedidos, TAM_PEDIDOS, listaZonas, TAM_ZONAS);
						break;
					case 14:
						printf("Gracias vuelva pronto\n");
						break;
				}

		}
		else
		{
			 break;
		}

		}while(opcion !=14);

	return EXIT_SUCCESS;
}
