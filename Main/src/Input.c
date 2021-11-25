#include "Input.h"


/// @brief Verifica si la cadena ingresada es numerica
///
/// @param cadena Cadena de caracteres a ser analizada
/// @return retorna 1(verdadero) si la cadena es numerica, y 0  (error) si no
static int EsNumerica(char* cadena);



/// @brief verifica que la cadena ingresada sea un numero flotante
/// @param cadena array de caracteres
/// @return retorno(0) if error, (1) if ok
static int EsFlotante(char* cadena);

int PedirCadenaChars(char cadena[], int tam, char mensaje[], char mensajeError[], int reintentos)
{
	char auxiliar[1000];
	int retorno = 1;


	if(cadena != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			MyGets(auxiliar, 1000);


			if(EsChar(auxiliar) == 0)
			{
				printf("Error, usted ingresado números.\n");
				reintentos --;
				retorno = 0;
			}
			else
			{

				if(strlen(auxiliar) > tam-1)
				{
					printf("%s\n",mensajeError);
					reintentos --;
					retorno = 0;
				}
				else
				{
					strncpy(cadena, auxiliar, TCADENA-1);
					retorno = 1;
					break;
				}

			}

			strncpy(cadena, auxiliar, TCADENA-1);

		}while(reintentos >= 0);

		if(reintentos < 0)
		{
			puts("Se quedo sin reintentos");
		}

	}

	return retorno;
}

int EsChar(char* cadena)
{
	int i=0;
	int retorno = 1;// es letra
	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if((cadena[i] < 'A' || cadena[i] > 'z') && cadena[i] != 32) // no es una letra
			{
				retorno = 0;// no es letra
				break;
			}
			i++;
		}

	}
	return retorno;
}


int MyGets(char* cadena, int longitud)
{
	int retorno = 0;
	if(cadena != NULL && longitud > 0 && fgets(cadena,longitud,stdin)==cadena)
	{
		__fpurge(stdin);
		if(cadena[strlen(cadena)-1] == '\n')
		{
			cadena[strlen(cadena)-1] = '\0';
		}
		retorno = 1;
	}
	return retorno;
}

int Utn_GetNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = 0;
	int bufferInt;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo &&reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);

			if(GetInt(&bufferInt) == 0 && bufferInt <= maximo && bufferInt >= minimo)
			{
				*pResultado = bufferInt;
				retorno = 1;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}

		}while(reintentos >= 0);
	}
	if(reintentos < 0)
	{
		printf("\nTe quedaste sin reintentos.\n\n");
	}

	return retorno;
}

int GetInt(int* pResultado)
{
	int retorno = -1;
	char buffer[64];

	if(MyGets(buffer, sizeof(buffer))==1 && EsNumerica(buffer))
	{
		*pResultado = atoi(buffer);
		retorno = 0;
	}

	return retorno;
}


static int EsNumerica(char* cadena)
{
	int i=0;
	int retorno = 1;
	if(cadena != NULL && strlen(cadena) > 0)
	{
		if(cadena[0] == '-')
		{
			i = 1;
		}

		while(cadena[i] != '\0')
		{
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			i++;
		}

	}
	return retorno;
}

int Utn_GetNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = 0;
	float bufferFloat;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo &&reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);

			if(GetFloat(&bufferFloat) == 0 && bufferFloat <= maximo && bufferFloat >= minimo)
			{
				*pResultado = bufferFloat;
				retorno = 1;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}

		}while(reintentos >= 0);
	}

	return retorno;
}

static int EsFlotante(char* cadena)
{
	int i=0;
	int retorno = 1;
	int contadorPuntos = 0;
	if(cadena != NULL && strlen(cadena) > 0)
	{
		if(cadena[0] == '-')
		{
			i = 1;
		}

		while(cadena[i] != '\0')
		{
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
			i++;
		}

	}
	return retorno;
}

int GetFloat(float* pResultado)
{
	int retorno = -1;
	char buffer[64];

	if(MyGets(buffer, sizeof(buffer))==1 && EsFlotante(buffer))
	{
		*pResultado = atof(buffer);
		retorno = 0;
	}

	return retorno;
}

int verificaCuit(char* cadena)
{
	int retorno = 1;

	int i = 0;
	if(cadena != NULL)
	{
		while(cadena[i] != '\0')
		{
			if((cadena[i] < '0' || cadena[i] > '9'))
			{
				retorno = 0;
			}
			i++;

		}
	}
	return retorno;
}

int cargarCuit(char cuit[], int reintentos)
{
	char auxCuit[12];
	int retorno = 0;

	do
	{
		printf("\nIngrese el cuit: ");
		MyGets(auxCuit, 12);
		if((strlen(auxCuit) > 11 || strlen(auxCuit) < 11))
		{
			printf("Error, un cuit esta constitituido por 11 numeros\n");
			reintentos--;
		}
		else
		{
			if(verificaCuit(auxCuit) == 1)
			{
				printf("Cuit cargardo con exito\n");
				strncpy(cuit, auxCuit, 14-1);
				retorno = 1;
				break;
			}
			else
			{
				printf("Ingrese solo números\n");
				reintentos--;
			}

		}

	}while(reintentos >= 0);

	return retorno;
}

int PedirAlphaNumerico(char cadena[], int tam, char mensaje[], char mensajeError[], int reintentos)
{
	char auxiliar[1000];
	int retorno = 1;


	if(cadena != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			MyGets(auxiliar, 1000);


				if(strlen(auxiliar) > tam-1)
				{
					printf("%s\n",mensajeError);
					reintentos --;
					retorno = 0;
				}
				else
				{
					strncpy(cadena, auxiliar, TCADENA-1);
					retorno = 1;
					break;
				}



			strncpy(cadena, auxiliar, TCADENA-1);

		}while(reintentos >= 0);

		if(reintentos < 0)
		{
			puts("Se quedo sin reintentos");
		}

	}

	return retorno;
}

int GeneradorId(int* idCliente)
{
	int idAux = *idCliente;

	idAux = idAux +1;

	*idCliente = idAux;

	return idAux;
}

void MenuPedidosPendientes(void)
{
	char id[12] = "Id Pedidos";
	char cuit[16] = "Cuit Clientes";
	char direccion[21] = "Direccion clientes";
	char kg[25] = "Cantidad KG a recolectar";

	printf("%s %40s %35s %40s\n", id, cuit, direccion, kg);

}

void MenuPedidosCompletados(void)
{
	char id[12] = "Id Pedidos";
	char cuit[16] = "Cuit Clientes";
	char direccion[21] = "Direccion clientes";
	char kgHdpe[10] = "KG Hdpe";
	char kgLdpe[10] = "KG Ldpe";
	char kgPp[10] = "KG Pp";

	printf("%s %40s %35s %10s %10s %10s\n", id, cuit, direccion, kgHdpe, kgLdpe, kgPp);

}


float kgHdpe;
float kgLdpe;
float gkPp;
