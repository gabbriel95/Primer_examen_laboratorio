#include "Pedidos.h"
#include "Input.h"


void InicializarListaPedidos(ePedido listaPedidos[], int sizePedidos)
{
	for(int i=0; i<sizePedidos;i++)
	{
		listaPedidos[i].isEmpty = 1; //1 vacio 0 lleno
	}
}

int CargarPedido(ePedido listaPedidos[], int sizePedidos, int* idPedido, int idCliente)
{
	int retorno = -1;
	if(listaPedidos != NULL && sizePedidos > 0)
	{
		retorno = 0;

		for(int i = 0; i<sizePedidos; i++)
		{
			if(listaPedidos[i].isEmpty == 1)
			{
				Utn_GetNumeroFlotante(&listaPedidos[i].cantidadTotalARecolectar, "Ingrese la cantidad de KG a recolectar\n", "Error, rango de KG invalido", 0, INT_MAX, 3);
				listaPedidos[i].isEmpty = 0;
				strncpy(listaPedidos[i].estadoPedido, PENDIENTE, TCADENA);
				listaPedidos[i].idCliente = idCliente;
				listaPedidos[i].idPedido = GeneradorId(idPedido);
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

int VerificarSiHayUnPedido(ePedido listaPedidos[], int sizePedidos)
{
	int retorno = -1;
	if(listaPedidos != NULL && sizePedidos > 0)
	{
		retorno = 0;
		for(int i=0; i<sizePedidos; i++)
		{
			if(listaPedidos[i].isEmpty == 0) //1 vacio 0 lleno
			{
				retorno = 1;//1 hay al menos un pedido, 0 no hay pedidos
				break;
			}
		}
	}

	return retorno; // -1: ERROR NULL---- 0:NO HAY NINGUN CLIENTE ---- 1: AL MENOS HAY UNO

}

int VerificarSiHayUnPedidoProcesado(ePedido listaPedidos[], int sizePedidos)
{
	int retorno = -1;
	if(listaPedidos != NULL && sizePedidos > 0)
	{
		retorno = 0;
		for(int i=0; i<sizePedidos; i++)
		{
			if(strncmp(COMPLETADO, listaPedidos[i].estadoPedido, TAM_CARACTERES) == 0) //1 vacio 0 lleno
			{
				retorno = 1;//1 hay al menos un pedido, 0 no hay pedidos
				break;
			}
		}
	}

	return retorno; // -1: ERROR NULL---- 0:NO HAY NINGUN CLIENTE ---- 1: AL MENOS HAY UNO

}

int VerificarSiHayUnPedidoPendiente(ePedido listaPedidos[], int sizePedidos)
{
	int retorno = -1;
	if(listaPedidos != NULL && sizePedidos > 0)
	{
		retorno = 0;
		for(int i=0; i<sizePedidos; i++)
		{
			if(strncmp(PENDIENTE, listaPedidos[i].estadoPedido, TAM_CARACTERES) == 0) //1 vacio 0 lleno
			{
				retorno = 1;//1 hay al menos un pedido, 0 no hay pedidos
				break;
			}
		}
	}

	return retorno; // -1: ERROR NULL---- 0:NO HAY NINGUN CLIENTE ---- 1: AL MENOS HAY UNO

}

int VerificarEstadoPedido(ePedido listaPedidos)
{
	int retorno = 0;

	if(strcmp(listaPedidos.estadoPedido, PENDIENTE) == 0)
	{
		retorno = 1;
	}

	return retorno;
}

void MostrarPedido(ePedido listaPedidos)
{

	if(listaPedidos.isEmpty == 0)
	{
		printf("%d -- %s\n", listaPedidos.idPedido, listaPedidos.estadoPedido);
	}

}

int MostrarListaPedidos(ePedido listaPedidos[], int sizePedidos)
{
	int retorno = -1;

	if(listaPedidos != NULL && sizePedidos > 0)
	{
		retorno = 0;

		if(VerificarSiHayUnPedido(listaPedidos, sizePedidos) == 1)
		{
			for(int i=0; i<sizePedidos; i++)
			{
				MostrarPedido(listaPedidos[i]);
				retorno = 1;
			}
		}
		else
		{
			puts("Todavia no se ingreso ningun pedido\n");
		}
	}


	return retorno;
}

int VerificarIdPedido(ePedido listaPedidos[], int sizePedidos, int IdAValidar)
{
	int retorno = -1;

	if(listaPedidos != NULL && sizePedidos > 0)
	{
		retorno = 0;
		for(int i = 0; i<sizePedidos; i++)
		{
			if(listaPedidos[i].idPedido == IdAValidar)
			{
				retorno = 1;
				puts("El ID ingresado coincide con uno de los pedidos\n");
				break;
			}
		}

		if(retorno == 0)
		{
			puts("El ID ingresado no pertenece a ningun pedido que este en nuestra base de datos\n");
		}
	}

	return retorno;
}

int AcumuladorPolipropileno(ePedido listaPedidos[], int sizePedidos, float* acumulador)
{
	int retorno = -1;
	float auxAcumulador = 0;

	if(listaPedidos != NULL && sizePedidos > 0 &&  acumulador != NULL)
	{
		retorno = 0;

		for(int i=0; i < sizePedidos; i++)
		{
			if(listaPedidos[i].isEmpty == 0)
			{
				auxAcumulador = auxAcumulador + listaPedidos[i].gkPp;
			}
		}

		*acumulador = auxAcumulador;

	}
	return retorno;
}


