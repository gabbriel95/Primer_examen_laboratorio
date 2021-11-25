#include "Clientes.h"
#include "Localidad.h"
#include "Input.h"

void InicializarListaClientes(eCliente listaClientes[], int sizeClientes)
{
	for(int i=0; i<sizeClientes;i++)
	{
		listaClientes[i].isEmpty = 1; //1 vacio 0 lleno
	}
}

int VerificarSiHayUnCliente(eCliente listaClientes[], int sizeClientes)
{
	int retorno = -1;
	if(listaClientes != NULL && sizeClientes > 0)
	{
		retorno = 0;
		for(int i=0; i<sizeClientes; i++)
		{
			if(listaClientes[i].isEmpty == 0) //1 vacio 0 lleno
			{
				retorno = 1;//1 hay al menos un cliente, 0 no hay clientes
				break;
			}
		}
	}

	return retorno; // -1: ERROR NULL---- 0:NO HAY NINGUN CLIENTE ---- 1: AL MENOS HAY UNO

}

int VerificarEspacioEnLista(eCliente listaClientes[], int sizeClientes)
{
	int retorno = -1;

	if(listaClientes != NULL && sizeClientes > 0)
	{
		retorno = 0;

		for(int i=0; i<sizeClientes; i++)
		{
			if(listaClientes[i].isEmpty == 1)
			{
				retorno = 1;
				break;
			}
		}

	}

	return retorno;
}

int VerificarId(eCliente listaClientes[], int sizeClientes, int IdAValidar)
{
	int retorno = -1;

	if(listaClientes != NULL && sizeClientes > 0)
	{
		retorno = 0;
		for(int i = 0; i<sizeClientes; i++)
		{
			if(listaClientes[i].idCliente == IdAValidar)
			{
				retorno = 1;
				puts("El ID ingresado coincide con uno de nuestros clientes\n");
				break;
			}
		}

		if(retorno == 0)
		{
			puts("El ID ingresado no pertenece a ningun cliente que este en nuestra base de datos\n");
		}
	}

	return retorno;
}

int CargarListaClientes(eCliente listaClientes[], int sizeClientes, int* idCliente)
{
	int retorno = -1;
	int respuesta;
	if(listaClientes != NULL && sizeClientes > 0)
	{
		retorno = 0;


		if(VerificarEspacioEnLista(listaClientes, sizeClientes) == 1)
		{
			for(int i=0; i<sizeClientes; i++)
			{
				if(listaClientes[i].isEmpty == 1)
				{
					if(
						PedirCadenaChars(listaClientes[i].nombreEmpresa, TAM_CARACTERES, "Ingrese el nombre de la empresa", "Error", 3) == 1 &&
						cargarCuit(listaClientes[i].cuit, 3) == 1 &&
						PedirAlphaNumerico(listaClientes[i].direccion, TAM_CARACTERES, "Ingrese la dirección de la empresa", "Error", 3) == 1 &&
						Utn_GetNumero(&respuesta, "\nSeleccione una localidad:\n 1) Quilmes\n 2) Varela\n 3) Avellaneda\n 4) Lanus\n 5) Almirante Brown\n", "\nError, opcion no valida", 1, 5, 3)==1)
					{
						listaClientes[i].isEmpty = 0;
						listaClientes[i].contadorPendientes = 0;
						listaClientes[i].contadorCompletados = 0;
						listaClientes[i].idCliente = GeneradorId(idCliente);
						listaClientes[i].idLocalidad = respuesta;

						if(respuesta == 3 || respuesta == 4)
						{
							listaClientes[i].idZona = 1;
						}else if (respuesta == 1 || respuesta == 5)
						{
							listaClientes[i].idZona = 2;
						}else
						{
							listaClientes[i].idZona = 3;
						}

						retorno = 1;
						printf("Cliente cargado con exito. Su numero de ID es: %d\n ", listaClientes[i].idCliente);
						break;
					}
					else
					{
						puts("Error, en la carga de un dato, no se pudo cargar el cliente");
					}

				}

			}

		}
		else
		{
			puts("No hay espacio en la lista de clientes");
		}

	}

	return retorno;
}

int ModificarCliente(eCliente listaClientes[], int sizeClientes, eLocalidad listaLocalidades[], int sizeLocalidades)
{
	int retorno = -1;
	int idABuscar;
	char direccionAux [51];
	int respuesta;

	if(listaClientes != NULL)
	{
		retorno = 0;
		MostrarListaClientes(listaClientes, sizeClientes, listaLocalidades, sizeLocalidades);
		if(Utn_GetNumero(&idABuscar, "\nIngrese el ID a modificar: ", "\nError, el id esta fuera de rango[1-100]", 1, 100, 3) == 1)
		{
			if(VerificarId(listaClientes, sizeClientes, idABuscar) == 1)
			{
				for(int i=0; i<sizeClientes; i++)
				{
					if(listaClientes[i].isEmpty == 0 && listaClientes[i].idCliente == idABuscar)
					{
						if( PedirAlphaNumerico(direccionAux, TAM_CARACTERES, "Ingrese la dirección de la empresa", "Error", 3) == 1 &&
								Utn_GetNumero(&respuesta, "\nSeleccione una localidad:\n 1) Quilmes\n 2) Varela\n 3) Avellaneda\n 4) Lanus\n 5) Almirante Brown\n", "\nError, opcion no valida", 1, 5, 3)==1)
						{
							strncpy(listaClientes[i].direccion, direccionAux, TAM_CARACTERES);
							listaClientes[i].idLocalidad = respuesta;
							retorno = 1;
						}
					}
				}
			}
		}

	}

	return retorno;
}

int EliminarCliente(eCliente listaClientes[], int sizeClientes, eLocalidad listaLocalidades[], int sizeLocalidades)
{
	int retorno = -1;
	int idABuscar;
	int respuesta;

	if(listaClientes != NULL)
	{
		MostrarListaClientes(listaClientes, sizeClientes, listaLocalidades, sizeLocalidades);
		retorno = 0;
		if(Utn_GetNumero(&idABuscar, "\nIngrese el ID a eliminar: ", "\nError, el id esta fuera de rango[1-100]", 1, 100, 3) == 1)
		{
			if(VerificarId(listaClientes, sizeClientes, idABuscar) == 1)
			{
				printf("\nSeguro quiere eliminar al id %d?\n", idABuscar);
				Utn_GetNumero(&respuesta, "0)NO \n 1)SI:", "Error, opcion no valida", 0, 1, 3);

				if(respuesta  == 1)
				{
					for(int i = 0; i<sizeClientes; i++)
					{
						if(listaClientes[i].idCliente == idABuscar && listaClientes[i].isEmpty == 0)
						{
							listaClientes[i].isEmpty = 1;
						}
					}
				}
			}

		}
	}


	return retorno;
}


void MostrarCliente(eCliente cliente, eLocalidad localidad)
{
	if(cliente.isEmpty == 0)
	{
		printf("%1d %13s %25s %20s %28s %15d\n", cliente.idCliente, cliente.nombreEmpresa, cliente.cuit, cliente.direccion, localidad.localidad, cliente.contadorPendientes);
	}

}

int MostrarListaClientes(eCliente listaClientes[], int sizeClientes, eLocalidad listaLocalidades[], int sizeLocalidades)
{
	int retorno = -1;

	if(listaClientes != NULL && sizeClientes > 0 && listaLocalidades != NULL && sizeLocalidades > 0)
	{
		retorno = 0;

		if(VerificarSiHayUnCliente(listaClientes, sizeClientes) == 1)
		{
			retorno = 1;
			printf("ID    	EMPRESA   		CUIT    		DIRECCION   		  LOCALIDAD  	 PEDIDOS PENDIENTES  \n");
			for(int i=0; i<sizeClientes; i++)
			{
				for(int j=0; j<sizeLocalidades; j++)
				{
					if(listaClientes[i].idLocalidad == listaLocalidades[j].idLocalidad)
					{
						MostrarCliente(listaClientes[i], listaLocalidades[j]);

					}
				}
			}
		}
		else
		{
			puts("Todavia no se ingreso ningun cliente\n");
		}

	}

	return retorno;
}

void AumentarContadorPendientes(eCliente listaClientes[], int sizeClientes, int idCliente)
{
	for(int i=0; i<sizeClientes; i++)
	{
		if(idCliente == listaClientes[i].idCliente)
		{
			listaClientes[i].contadorPendientes++;
		}
	}
}

void DisminuirContadorPendientes(eCliente listaClientes[], int sizeClientes, int idCliente)
{
	for(int i=0; i<sizeClientes; i++)
	{
		if(idCliente == listaClientes[i].idCliente)
		{
			listaClientes[i].contadorPendientes--;
			listaClientes[i].contadorCompletados++;
		}
	}
}


int ContadorClientes(eCliente listaClientes[], int sizeClientes, int* contador)
{
	int retorno = -1;
	int auxContador = 0;

	if(listaClientes != NULL && sizeClientes > 0 && contador != NULL)
	{
		retorno = 0;
		for(int i=0; i<sizeClientes; i++)
		{
			if(listaClientes[i].isEmpty == 0)
			{
				auxContador++;
			}
		}
	}

	*contador = auxContador;

	return retorno;
}
