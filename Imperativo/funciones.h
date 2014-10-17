#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "estructuras.h"

/**
	@file funciones.h
	@brief str_split: Corta una cadena ingresada en cada aparición del delimitador indicado.
    @param a_str, a_delim
    @returns Arreglo de string.
    @verbatim 
    	Función que separa una cadena de caracteres en cada aparición del delimitador especificado.
		Cada separación efectuada pasa a ser una valor en una posición del arreglo a retornar.
    @endverbatim 
*/
char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so callerx	
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

/**
	@file funciones.h
	@brief largoDocumento: Carga un archivo y lo recorre, obteniendo el numero de lineas que contiene.
    @param nombre_archivo[]
    @returns int contador
    @verbatim 
    	Función que lee un documento especificado, recorriendolo en su totalidad y contando cada linea recorrida.
    	Retorna la cantidad de lineas del documento.
    @endverbatim 
*/
int largoDocumento(char nombre_archivo[])
{
	int contador=0;
	//Crear puntero donde se guardará la dirección del archivo
	FILE * archivo;
	//Abrir el archvio nombre.txt en modo de lectura read
	archivo = fopen(nombre_archivo, "r");
	//si el archivo existe será distinto de null
	if(archivo==NULL)
	{
		return -100;
	}
	else
	{
		while(feof(archivo)==0)
		{
			contador++;
		}
	}	
	return contador;
}

/**
	@file funciones.h
	@brief *leerPaciente: Funcion que lee un archivo y guarda los datos en una estructura Paciente. 
    @param char nombre_archivo[]
    @returns Paciente nombreEstructura
    @verbatim 
    	Función que lee un documento especificado, que debe contener los datos referentes a los Pacientes de la clinica fastClinic.
    	Guarda los datos en una estructura tipo Paciente, siendo esta retornada al finalizar el guardado de datos.
    @endverbatim 
*/
Paciente *leerPaciente(char nombre_archivo[], int cantidad_datos)
{
	int contador=0;
	int indice = 0;
	Paciente *nombreEstructura;
	nombreEstructura = (Paciente *)malloc(sizeof(Paciente)*(cantidad_datos));
	//Crear arreglo donde se guardaran los strings entrantes
	char lectura[100];
	char** array_lectura;
	//Crear puntero donde se guardará la dirección del archivo
	FILE * archivo;
	//Abrir el archvio nombre.txt en modo de lectura read
	archivo = fopen(nombre_archivo, "r");
	//si el archivo existe será distinto de null
	if(archivo==NULL)
	{
		return nombreEstructura;
	}
	//Si el archivo fue leido con fopen, se realizará lo siguiente:
	while(feof(archivo)==0)
	{
		if(contador==0)
		{
			fgets(lectura, 100, archivo);
			contador++;
		}
		else
		{
			fgets(lectura, 100, archivo);
			//Cortar linea asignandola a array.
			array_lectura = str_split(lectura, ',');
			//Asignar campos a estructuras.
			nombreEstructura[indice].idPaciente = atoi(array_lectura[0]);
			strcpy(nombreEstructura[indice].run, array_lectura[1]);
			strcpy(nombreEstructura[indice].email, array_lectura[2]);
			strcpy(nombreEstructura[indice].nombre, array_lectura[3]);
			strcpy(nombreEstructura[indice].apellido, array_lectura[4]);
			strcpy(nombreEstructura[indice].fecha_nac, array_lectura[5]);
			contador++;
			indice++;
		}
		
	} 
	fclose(archivo);
	//Finaliza While y se completa el arreglo con "cantidad_alumnos" elementos.
	return nombreEstructura;
}

/**
	@file funciones.h
	@brief *leerMedico: Funcion que lee un archivo y guarda los datos en una estructura Medico. 
    @param char nombre_archivo[]
    @returns Medico nombreEstructura
    @verbatim 
    	Función que lee un documento especificado, que debe contener los datos referentes a los Medicos de la clinica fastClinic.
    	Guarda los datos en una estructura tipo Medico, siendo esta retornada al finalizar el guardado de datos.
    @endverbatim 
*/
Medico *leerMedico(char nombre_archivo[], int cantidad_datos)
{
	int contador=0;
	int indice = 0;
	Medico *nombreEstructura;
	nombreEstructura = (Medico *)malloc(sizeof(Medico)*(cantidad_datos));
	//Crear arreglo donde se guardaran los strings entrantes
	char lectura[100];
	char** array_lectura;
	//Crear puntero donde se guardará la dirección del archivo
	FILE * archivo;
	//Abrir el archvio nombre.txt en modo de lectura read
	archivo = fopen(nombre_archivo, "r");

	//si el archivo existe será distinto de null
	if(archivo==NULL)
	{
		return nombreEstructura;
	}
	//Si el archivo fue leido con fopen, se realizará lo siguiente:
	while(feof(archivo)==0)
	{
		if(contador==0)
		{
			fgets(lectura, 100, archivo);
			contador++;
		}
		else 
		{
			fgets(lectura, 100, archivo);
			//Si los campos del archivo estan separados por coma.
			array_lectura = str_split(lectura, ',');
			nombreEstructura[indice].idMedico = atoi(array_lectura[0]);
			strcpy(nombreEstructura[indice].run, array_lectura[1]);
			strcpy(nombreEstructura[indice].email, array_lectura[2]);
			strcpy(nombreEstructura[indice].nombre, array_lectura[3]);
			strcpy(nombreEstructura[indice].apellido, array_lectura[4]);
			strcpy(nombreEstructura[indice].especialidad, array_lectura[5]);
			contador++;
			indice++;
		}
	} 
	fclose(archivo);
	//Finaliza While y se completa el arreglo con "cantidad_alumnos" elementos.
	return nombreEstructura;
}

/**
	@file funciones.h
	@brief *leerTratamiento: Funcion que lee un archivo y guarda los datos en una estructura Tratamiento. 
    @param char nombre_archivo[]
    @returns Tratamiento nombreEstructura
    @verbatim 
    	Función que lee un documento especificado, que debe contener los datos referentes a los Tratamientos de la clinica fastClinic.
    	Guarda los datos en una estructura tipo Tratamiento, siendo esta retornada al finalizar el guardado de datos.
    @endverbatim 
*/
Tratamiento *leerTratamiento(char nombre_archivo[], int cantidad_datos)
{
	Tratamiento *nombreEstructura;
	nombreEstructura = (Tratamiento *)malloc(sizeof(Tratamiento)*(cantidad_datos));
	//Crear arreglo donde se guardaran los strings entrantes
	char lectura[100];
	char** array_lectura;
	//Crear puntero donde se guardará la dirección del archivo
	FILE * archivo;
	//Abrir el archvio nombre.txt en modo de lectura read
	archivo = fopen(nombre_archivo, "r");

	//si el archivo existe será distinto de null
	if(archivo==NULL)
	{
		return nombreEstructura;
	}
	//Si el archivo fue leido con fopen, se realizará lo siguiente:
	int contador = 0;
	int indice   = 0;
	while(feof(archivo)==0)
	{
		if(contador==0)
		{
			contador++;
			fgets(lectura,100,archivo);
		}
		else 
		{
			fgets(lectura, 100, archivo);
			//Si los campos del archivo estan separados por coma.
			array_lectura = str_split(lectura, ',');
			nombreEstructura[indice].idTratamiento = atoi(array_lectura[0]);
			strcpy(nombreEstructura[indice].nombre, array_lectura[1]);
			strcpy(nombreEstructura[indice].descripcion, array_lectura[2]);
			strcpy(nombreEstructura[indice].nivel_riesgo, array_lectura[3]);
			contador++;
			indice++;
			
		}
	} 
	fclose(archivo);
	//Finaliza While y se completa el arreglo con "cantidad_alumnos" elementos.
	return nombreEstructura;
}

/**
	@file funciones.h
	@brief *leerDiagnostico: Funcion que lee un archivo y guarda los datos en una estructura Diagnostico. 
    @param char nombre_archivo[]
    @returns Diagnostico nombreEstructura
    @verbatim 
    	Función que lee un documento especificado, que debe contener los datos referentes a los Diagnosticos de la clinica fastClinic.
    	Guarda los datos en una estructura tipo Diagnostico, siendo esta retornada al finalizar el guardado de datos.
    @endverbatim 
*/
Diagnostico *leerDiagnostico(char nombre_archivo[], int cantidad_datos)
{
	Diagnostico *nombreEstructura;
	nombreEstructura = (Diagnostico *)malloc(sizeof(Diagnostico)*(cantidad_datos));
	//Crear arreglo donde se guardaran los strings entrantes
	char lectura[100];
	char** array_lectura;
	//Crear puntero donde se guardará la dirección del archivo
	FILE * archivo;
	//Abrir el archvio nombre.txt en modo de lectura read
	archivo = fopen(nombre_archivo, "r");

	//si el archivo existe será distinto de null
	if(archivo==NULL)
	{
		return nombreEstructura;
	}
	//Si el archivo fue leido con fopen, se realizará lo siguiente:
	int contador=0;
	int indice = 0;
	while(feof(archivo)==0)
	{
		if(contador==0)
		{
			contador++;
			fgets(lectura,100,archivo);
		}
		else 
		{
			fgets(lectura, 100, archivo);
			//Si los campos del archivo estan separados por coma.
			array_lectura = str_split(lectura, ',');
			nombreEstructura[indice].idDiagnostico = atoi(array_lectura[0]);
			strcpy(nombreEstructura[indice].nombre_diag, array_lectura[1]);
			strcpy(nombreEstructura[indice].nivel_gravedad, array_lectura[2]);
			contador++;
			indice++;
			
		}
	} 
	fclose(archivo);
	//Finaliza While y se completa el arreglo con "cantidad_alumnos" elementos.
	return nombreEstructura;
}

/**
	@file funciones.h
	@brief *leerPaciente: Funcion que lee un archivo y guarda los datos en una estructura Paciente. 
    @param char nombre_archivo[]
    @returns Paciente nombreEstructura
    @verbatim 
    	Función que lee un documento especificado, que debe contener los datos referentes a los Pacientes de la clinica fastClinic.
    	Guarda los datos en una estructura tipo Paciente, siendo esta retornada al finalizar el guardado de datos.
    @endverbatim 
*/
DiagnosticoPaciente *leerDiagnosticoPaciente(char nombre_archivo[], int cantidad_datos)
{
	DiagnosticoPaciente *nombreEstructura;
	nombreEstructura = (DiagnosticoPaciente *)malloc(sizeof(DiagnosticoPaciente)*(cantidad_datos));
	//Crear arreglo donde se guardaran los strings entrantes
	char lectura[1000];
	char** array_lectura;
	//Crear puntero donde se guardará la dirección del archivo
	FILE * archivo;
	//Abrir el archvio nombre.txt en modo de lectura read
	archivo = fopen(nombre_archivo, "r");

	//si el archivo existe será distinto de null
	if(archivo==NULL)
	{
		return nombreEstructura;
	}
	//Si el archivo fue leido con fopen, se realizará lo siguiente:
	int contador=0;
	int indice = 0;
	while(feof(archivo)==0)
	{
		if(contador==0)
		{
			contador++;
			fgets(lectura,1000,archivo);
		}
		else 
		{
			fgets(lectura, 1000, archivo);
			//Si los campos del archivo estan separados por coma.
			array_lectura = str_split(lectura, ',');
			nombreEstructura[indice].idDiagnosticoPaciente = atoi(array_lectura[0]);
			nombreEstructura[indice].idPaciente = atoi(array_lectura[1]);
			nombreEstructura[indice].idDiagnostico = atoi(array_lectura[2]);	
			strcpy(nombreEstructura[indice].fecha_diag, array_lectura[3]);
			nombreEstructura[indice].idMedico_diagnostico = atoi(array_lectura[4]);
			strcpy(nombreEstructura[indice].estado_diagnostico, array_lectura[5]);
			strcpy(nombreEstructura[indice].fecha_alta, array_lectura[6]);
			nombreEstructura[indice].idMedico_alta = atoi(array_lectura[7]);
			strcpy(nombreEstructura[indice].detalle_alta, array_lectura[8]);
			contador++;
			indice++;
			
		}
	} 
	fclose(archivo);
	//Finaliza While y se completa el arreglo con "cantidad_alumnos" elementos.
	return nombreEstructura;
}

/**
	@file funciones.h
	@brief *leerPaciente: Funcion que lee un archivo y guarda los datos en una estructura Paciente. 
    @param char nombre_archivo[]
    @returns Paciente nombreEstructura
    @verbatim 
    	Función que lee un documento especificado, que debe contener los datos referentes a los Pacientes de la clinica fastClinic.
    	Guarda los datos en una estructura tipo Paciente, siendo esta retornada al finalizar el guardado de datos.
    @endverbatim 
*/
TratamientoDiagnostico *leerTratamientoDiagnostico(char nombre_archivo[], int cantidad_datos)
{
	TratamientoDiagnostico *nombreEstructura; 
	nombreEstructura = (TratamientoDiagnostico *)malloc(sizeof(TratamientoDiagnostico)*(cantidad_datos));
	//Crear arreglo donde se guardaran los strings entrantes
	char lectura[100];
	char** array_lectura;
	//Crear puntero donde se guardará la dirección del archivo
	FILE * archivo;
	//Abrir el archvio nombre.txt en modo de lectura read
	archivo = fopen(nombre_archivo, "r");

	//si el archivo existe será distinto de null
	if(archivo==NULL)
	{
		return nombreEstructura;
	}
	//Si el archivo fue leido con fopen, se realizará lo siguiente:
	int contador=0;
	int indice = 0;
	while(feof(archivo)==0)
	{
		if(contador==0)
		{
			contador++;
			fgets(lectura,100,archivo);
		}
		else 
		{
			fgets(lectura, 100, archivo);
			//Si los campos del archivo estan separados por coma.
			array_lectura = str_split(lectura, ',');
			nombreEstructura[indice].idTratamiento = atoi(array_lectura[0]);
			nombreEstructura[indice].idDiagnostico = atoi(array_lectura[1]);	
			contador++;
			indice++;
			
		}
	} 
	fclose(archivo);
	//Finaliza While y se completa el arreglo con "cantidad_alumnos" elementos.
	return nombreEstructura;
}

/**
	@file funciones.h
	@brief *leerPaciente: Funcion que lee un archivo y guarda los datos en una estructura Paciente. 
    @param char nombre_archivo[]
    @returns Paciente nombreEstructura
    @verbatim 
    	Función que lee un documento especificado, que debe contener los datos referentes a los Pacientes de la clinica fastClinic.
    	Guarda los datos en una estructura tipo Paciente, siendo esta retornada al finalizar el guardado de datos.
    @endverbatim 
*/
TratamientoDiagnosticoPaciente *leerTratamientoDiagnosticoPaciente(char nombre_archivo[], int cantidad_datos)
{
	int contador=0;
	int indice = 0;
	TratamientoDiagnosticoPaciente *nombreEstructura;
	nombreEstructura = (TratamientoDiagnosticoPaciente *)malloc(sizeof(TratamientoDiagnosticoPaciente)*(cantidad_datos));
	//Crear arreglo donde se guardaran los strings entrantes
	char lectura[1000];
	char** array_lectura;
	//Crear puntero donde se guardará la dirección del archivo
	FILE * archivo;
	//Abrir el archvio nombre.txt en modo de lectura read
	archivo = fopen(nombre_archivo, "r");

	//si el archivo existe será distinto de null
	if(archivo==NULL)
	{
		return nombreEstructura;
	}
	//Si el archivo fue leido con fopen, se realizará lo siguiente:
	while(feof(archivo)==0)
	{
		if(contador==0)
		{
			contador++;
			fgets(lectura, 1000, archivo);
		}
		else 
		{
			fgets(lectura, 1000, archivo);
			//Cortar linea asignandola a array.
			array_lectura = str_split(lectura, ',');
			//Asignar campos a estructuras.
			nombreEstructura[indice].idDiagnosticoPaciente = atoi(array_lectura[0]);
			nombreEstructura[indice].idTratamiento = atoi(array_lectura[1]);
			nombreEstructura[indice].idMedico = atoi(array_lectura[2]);
			strcpy(nombreEstructura[indice].fecha_inicio, array_lectura[3]);
			strcpy(nombreEstructura[indice].duracion, array_lectura[4]);
			strcpy(nombreEstructura[indice].resultado, array_lectura[5]);	
			contador++;
			indice++;
		}
	} 
	fclose(archivo);
	//Finaliza While y se completa el arreglo con "cantidad_alumnos" elementos.
	return nombreEstructura;
}

