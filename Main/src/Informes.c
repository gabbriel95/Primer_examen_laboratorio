#include "Informes.h"
#include "Localidad.h"
#include "Zonas.h"

int AltaPedido(eCliente listaClientes[], int sizeClientes, ePedido listaPedidos[], int sizePedidos, int* idPedido, eLocalidad listaLocalidades[], int sizeLocalidades)
{
	int retorno = -1;
	int idCliente;

	if(listaClientes != NULL && sizeClientes > 0 && listaPedidos != NULL && sizePedidos >0 && listaLocalidades != NULL && sizeLocalidades > 0)
	{
		retorno = 0;

		if(VerificarSiHayUnCliente(listaClientes, sizeClientes) == 1)
		{
			MostrarListaClientes(listaClientes, sizeClientes, listaLocalidades, sizeLocalidades);
			Utn_GetNumero(&idCliente, "Ingrese el ID del cliente al que desea ingresarle un pedido\n", "Error, el ID ingresado esta fuera del rango\n", 1, INT_MAX, 3);

			if(VerificarId(listaClientes, sizeClientes, idCliente) == 1)
			{
				CargarPedido(listaPedidos, sizePedidos, idPedido, idCliente);
				AumentarContadorPendientes(listaClientes, sizeClientes, idCliente);

			}
		}
		else
		{
			puts("Primero debe dar de alta a un cliente\n");
		}

	}

	return retorno;
}

int ProcesarPedido(ePedido listaPedidos[], int sizePedidos, eCliente listaClientes[], int sizeClientes)
{
	int retorno = -1;
	int idPedido;
	float acumuladorKg = 0;
	if(listaPedidos != NULL && sizePedidos > 0)
	{
		retorno = 0;
		if(MostrarListaPedidos(listaPedidos, sizePedidos) == 1)
		{
			retorno = 1;
			Utn_GetNumero(&idPedido, "Ingrese el ID del pedido que desea procesar\n", "Error, el ID ingresado esta fuera del rango\n", 1, INT_MAX, 3);

			if(VerificarIdPedido(listaPedidos, sizePedidos, idPedido) == 1)
			{
				for(int i=0; i<sizePedidos; i++)
				{
					if(listaPedidos[i].idPedido == idPedido)
					{
						Utn_GetNumeroFlotante(&listaPedidos[i].kgHdpe, "Ingrese los KG de HDPE del pedido\n", "Error, esta fuera del rango\n", 1, INT_MAX, 3);
						Utn_GetNumeroFlotante(&listaPedidos[i].kgLdpe, "Ingrese los KG de LDPE del pedido\n", "Error, esta fuera del rango\n", 1, INT_MAX, 3);
						Utn_GetNumeroFlotante(&listaPedidos[i].gkPp, "Ingrese los KG de PP del pedido\n", "Error, esta fuera del rango\n", 1, INT_MAX, 3);

						acumuladorKg = listaPedidos[i].kgHdpe + listaPedidos[i].kgLdpe + listaPedidos[i].gkPp;

						if(acumuladorKg > listaPedidos[i].cantidadTotalARecolectar)
						{
							printf("\Error, no puede recolectar mas de la cantidad total a recolectar que es %f\n", listaPedidos[i].cantidadTotalARecolectar);
							printf("\n Vuelva a intentarlo en otra ocasion\n");
						}
						else
						{
							strncpy(listaPedidos[i].estadoPedido, COMPLETADO, TCADENA);
							DisminuirContadorPendientes(listaClientes, sizeClientes, listaPedidos[i].idCliente);
							puts("\n Operacion exitosa\n");
						}

					}
				}
			}
		}

	}

	return retorno;
}

int ImprimirPedidosPendientes(ePedido listaPedidos[], int sizePedidos, eCliente listaClientes[], int sizeClientes)
{
	int retorno = -1;
	if(listaPedidos != NULL && sizePedidos > 0 && listaClientes != NULL && sizeClientes > 0)
	{
		retorno = 0;

			if(VerificarSiHayUnCliente(listaClientes, sizeClientes) == 1 && VerificarSiHayUnPedido(listaPedidos, sizePedidos) == 1)
			{
				puts("\nListado de pedidos pendientes: \n\n");
				MenuPedidosPendientes();
				for(int i = 0; i < sizePedidos; i++)
				{
					if(VerificarEstadoPedido(listaPedidos[i]) == 1)
					{
						printf("%5d: \n\t", listaPedidos[i].idPedido);

						for(int j = 0; j<sizeClientes; j++)
						{
							if(listaPedidos[i].idCliente == listaClientes[j].idCliente && listaClientes[j].isEmpty == 0)
							{
								printf("%42s %35s %30.2f\n", listaClientes[j].cuit, listaClientes[j].direccion, listaPedidos[i].cantidadTotalARecolectar);
							}
						}
					}
				}

			}
			else
			{
				puts("\nError, primero debe ingresar un cliente y luego asignarle un pedido\n");
			}


	}


	return retorno;
}


int ImprimirPedidosCompletados(ePedido listaPedidos[], int sizePedidos, eCliente listaClientes[], int sizeClientes)
{
	int retorno = -1;
	if(listaPedidos != NULL && sizePedidos > 0 && listaClientes != NULL && sizeClientes > 0)
	{
		retorno = 0;

			if(VerificarSiHayUnCliente(listaClientes, sizeClientes) == 1 && VerificarSiHayUnPedido(listaPedidos, sizePedidos) == 1)
			{
				puts("\nListado de pedidos completados: \n\n");
				MenuPedidosCompletados();
				for(int i = 0; i < sizePedidos; i++)
				{
					if(VerificarEstadoPedido(listaPedidos[i]) == 0 && listaPedidos[i].isEmpty == 0)
					{
						printf("%5d: \n\t", listaPedidos[i].idPedido);

						for(int j = 0; j<sizeClientes; j++)
						{
							if(listaPedidos[i].idCliente == listaClientes[j].idCliente && listaClientes[j].isEmpty == 0)
							{
								printf("%42s %35s %10.2f %10.2f %10.2f\n", listaClientes[j].cuit, listaClientes[j].direccion, listaPedidos[i].kgHdpe, listaPedidos[i].kgLdpe, listaPedidos[i].gkPp);
							}
						}
					}
				}

			}
			else
			{
				puts("\nError, primero debe ingresar un cliente y luego asignarle un pedido\n");
			}


	}


	return retorno;
}

int ContadorPedidosPXLocalidad(eCliente listaClientes[], int sizeClientes, ePedido listaPedidos[], int sizePedidos, char localidad[], eLocalidad listaLocalidades[], int sizeLocalidades)
{
	int contador = -1;

	if(listaClientes != NULL && sizeClientes > 0 && listaPedidos != NULL && sizePedidos > 0)
	{
		contador = 0;
		for(int i=0; i<sizeClientes; i++)
		{
			for(int j=0; j<sizeLocalidades; j++)
			{
				if(listaClientes[i].idLocalidad == listaLocalidades[j].idLocalidad)
				{
					if(strncmp(localidad, listaLocalidades[j].localidad, TAM_CARACTERES) == 0)
					{
						for(int j=0; j<sizePedidos; j++)
						{
							if(listaClientes[i].idCliente == listaPedidos[j].idCliente && strncmp(listaPedidos[j].estadoPedido,PENDIENTE,TAM_CARACTERES) == 0)
							{
								contador++;
							}
						}
					}

				}

			}
		}

	}

	return contador;
}

int MostrarCantidadPedidosPXLocalidad(eCliente listaClientes[], int sizeClientes, ePedido listaPedidos[], int sizePedidos, eLocalidad listaLocalidad[], int sizeLocalidad)
{
	int retorno = -1;
	int contador;
	char localidad[TAM_CARACTERES];
	if(PedirCadenaChars(localidad, TAM_CARACTERES, "\nIngrese la localidad: \n", "\nError\n", 3)==1)
	{
		contador = ContadorPedidosPXLocalidad(listaClientes, sizeClientes, listaPedidos, sizePedidos, localidad, listaLocalidad, sizeLocalidad);

		printf("En la localidad %s, hay %d pedidos pendientes", localidad, contador);
	}

	return retorno;
}




int CalcularPromedioPolipropileno(eCliente listaClientes[], int sizeClientes, ePedido listaPedidos[], int sizePedidos)
{
	int retorno = -1;
	int contadorClientes = 0;
	float acumuladorPp = 0;
	float promedio;

	if(listaClientes != NULL && sizeClientes > 0 && listaPedidos != NULL && sizePedidos > 0)
	{
		retorno = 0;
		if(VerificarSiHayUnPedidoProcesado(listaPedidos, sizePedidos) == 1)
		{
			AcumuladorPolipropileno(listaPedidos, sizePedidos, &acumuladorPp);
			ContadorClientes(listaClientes, sizeClientes, &contadorClientes);
			promedio = acumuladorPp/contadorClientes;
			printf("\nEl promedio de kg de Polipropileno por cliente es %.2f KG \n", promedio);
		}
		else
		{
			printf("\nError, no hay pedidos procesados\n");
		}
	}

	return retorno;
}

int ClienteConMasPedidosPendientes(eCliente listaClientes[], int sizeClientes, ePedido listaPedidos[], int sizePedidos)
{
	int retorno = -1;
	int maximoPendiente;
	int indice;

	if(listaClientes != NULL && sizeClientes)
	{
		if(VerificarSiHayUnPedidoPendiente(listaPedidos, sizePedidos) == 1)
		{
			for(int i=0; i<sizeClientes; i++)
			{
				if(i==0 && listaClientes[i].isEmpty == 0)
				{
					maximoPendiente = listaClientes[i].contadorPendientes;
					indice = i;
				}
				else if(maximoPendiente < listaClientes[i].contadorPendientes && listaClientes[i].isEmpty == 0)
				{
					maximoPendiente = listaClientes[i].contadorPendientes;
					indice = i;
				}
			}
		printf("\nEl cliente con mayor cantidad de pedidos pendientes es %s con %d pedidos pendientes", listaClientes[indice].nombreEmpresa, maximoPendiente);
		}
		else
		{
			printf("\n No hay pedidos pendientes\n");
		}
	}



	return retorno;
}

int ClienteConMasPedidosCompletos(eCliente listaClientes[], int sizeClientes, ePedido listaPedidos[], int sizePedidos)
{
	int retorno = -1;
	int maximoCompletado;
	int indice;

	if(listaClientes != NULL && sizeClientes)
	{
		if(VerificarSiHayUnPedidoProcesado(listaPedidos, sizePedidos) == 1)
		{
			for(int i=0; i<sizeClientes; i++)
			{
				if(i==0 && listaClientes[i].isEmpty == 0)
				{
					maximoCompletado = listaClientes[i].contadorCompletados;
					indice = i;
				}
				else if(maximoCompletado < listaClientes[i].contadorCompletados && listaClientes[i].isEmpty == 0)
				{
					maximoCompletado = listaClientes[i].contadorCompletados;
					indice = i;
				}
			}
			printf("\nEl cliente con mayor cantidad de pedidos pendientes es %s con %d pedidos pendientes", listaClientes[indice].nombreEmpresa, maximoCompletado);
		}
		else
		{
			printf("\n No hay pedidos completados\n");
		}
	}


	return retorno;
}

int MostrarPedidosPedidosPendientesXZona(eCliente listaClientes[], int sizeClientes, ePedido listaPedidos[], int sizePedidos, eZonas listaZonas[], int sizeZonas)
{
	int retorno = -1;
	int respuesta;
	if(listaClientes != NULL && sizeClientes > 0 &&  listaPedidos != NULL && sizePedidos > 0 && listaZonas != NULL && sizeZonas > 0)
	{

	 if(Utn_GetNumero(&respuesta, "\nSeleccione la zona: \n 1)Zona UNO [Avellaneda-Lanus]\n 2) Zona DOS [Quilmes-Almirante]\n 3) Zona TRES [Varela]\n ", "Error, opcion no valida", 1, 3, 3) == 1)
	 {
		for(int i=0; i<sizeClientes; i++)
		{
			if(listaClientes[i].isEmpty == 0 && listaClientes[i].idZona == listaZonas[respuesta-1].idZona)
			{
				listaZonas[respuesta-1].pedidosPendientes += listaClientes[i].contadorPendientes;
				printf("\n%d", listaZonas[respuesta-1].pedidosPendientes);
			}

		}
	 }

	}
	if(listaZonas[respuesta-1].pedidosPendientes > 0)
	{
		printf("\nLos pedidos pendientes de la zona %s son %d", listaZonas[respuesta-1].zona, listaZonas[respuesta-1].pedidosPendientes);
	}else
	{
		printf("\nPrimero debe cargar un pedido a un cliente en esa zona\n");
	}

	return retorno;
}
