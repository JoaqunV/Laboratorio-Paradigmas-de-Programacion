#include <limits.h>
#include "funciones.h"
#define LARGO 105
#define LARGO2 1005

/*************** Declaraíón de Funciónes **************/
Medico *leerMedico();
Paciente *leerPaciente();
Tratamiento *leerTratamiento();
Diagnostico *leerDiagnostico();
DiagnosticoPaciente *leerDiagnosticoPaciente();
TratamientoDiagnostico *leerTratamientoDiagnostico();
TratamientoDiagnosticoPaciente *leerTratamientoDiagnosticoPaciente();

/**
	@file funciones.c
	@brief obtenerNombrePaciente: Función de nivel bajo que obtiene el nombre de un paciente a partir de su run.
    @param char runPaciente[]
    @returns none
    @verbatim 
    	Función que recibe como parametro el run de un paciente e indica el nombre corrrespondiente al run del paciente ingresado.
    	No posee retorno, ya que posee una salida directa a un archivo de texto.
    @endverbatim 
*/
void obtenerNombrePaciente(char runPaciente[])
{
	int i; 
	Paciente *Pacientes;
	char nombreArchivo[50];
	strcpy(nombreArchivo, "./Archivos_BD/Paciente.txt");
	Pacientes = leerPaciente(nombreArchivo, LARGO);
	//Crear puntero donde se guardará la dirección del archivo
	FILE * archivo;
	//Abrir el archvio nombre.txt en modo de lectura append
	archivo = fopen("./output.txt", "a");
	for(i=0; i<=LARGO; i++)
	{
		if(strcmp(runPaciente, Pacientes[i].run)==0)
		{
			fprintf(archivo, "%s\n", Pacientes[i].nombre);
			i=LARGO;
		}
	}
	fclose(archivo);
	free(Pacientes);	
}	

/**
	@file funciones.c
	@brief especialidad: Función de nivel bajo que obtiene la especialidad de un Medico a partir de su run.
    @param char runDoctor[]
    @returns none
    @verbatim 
    	Función que recibe como parametro el run de un medico e indica el nombre corrrespondiente al run del medico ingresado.
    	No posee retorno, ya que posee una salida directa a un archivo de texto.
    @endverbatim 
*/
void especialidad(char runDoctor[])
{
	int i;
	Medico *Doctor;
	char nombreArchivo[50];
	strcpy(nombreArchivo, "./Archivos_BD/Doctor.txt");
	Doctor = leerMedico(nombreArchivo, LARGO);
	//Crear puntero donde se guardará la dirección del archivo
	FILE * archivo;
	//Abrir el archvio nombre.txt en modo de lectura append
	archivo = fopen("./output.txt", "a");
	for(i=0; i<=LARGO; i++)
	{
		if(strcmp(runDoctor, Doctor[i].run)==0)
		{
			fprintf(archivo, "%s\n", Doctor[i].especialidad);
			i=LARGO;
		}
	}
	fclose(archivo);
	free(Doctor);	
}

/**
	@file funciones.c
	@brief tratamientoRiesgoso: Función de nivel bajo que obtiene el nombre de todos los tratamientos a partir del nivel de riesgo ingresado.
    @param char argumento[]
    @returns none
    @verbatim 
    	Función que recibe como parametro el nivel de riesgo de un tratamiento e indica el nombre corrrespondiente a todos los 
    	tratamientos que poseen dicho nivel de riesgo especificado. No posee retorno, ya que posee una salida directa a un archivo de texto.
    @endverbatim 
*/
void tratamientoRiesgoso(char argumento[])
{
	int i;
	char nombreArchivo[50];
	Tratamiento *Tratamientos;
	strcpy(nombreArchivo, "./Archivos_BD/Tratamiento.txt");
	Tratamientos = leerTratamiento(nombreArchivo, LARGO);
	//Crear puntero donde se guardará la dirección del archivo
	FILE * archivo;
	//Abrir el archvio nombre.txt en modo de lectura append
	archivo = fopen("./output.txt", "a");
	/** Comienzo a recorrer array y a comparar */
	for(i=0; i<=LARGO; i++)
	{		
		if(strcmp(argumento, Tratamientos[i].nivel_riesgo)==0)
		{
			fprintf(archivo, "%s\n", Tratamientos[i].nombre);
		}	
	}
	fclose(archivo);
	free(Tratamientos);
}

/**
	@file funciones.c
	@brief tratamientoMasUsado: Función de nivel bajo que obtiene el tratamiento más usado.
    @param int id_entrante
    @returns none
    @verbatim 
    	Función que recibe como parametro un identificador, el cual sirve para diferenciar las dos aplicaciones de la función.
    	Si el id_entrante es igual a cero, se realiza la busqueda simple del tratamiento más usado. 
    	Si no, se ejecuta la busqueda del tratamiento más usado para un determinado diagnostico.
    	La segunda segunda sección no esta implementada, quedando solo operativa la busqueda simple del tratamiento más usado. 
    	No posee retorno, ya que posee una salida directa a un archivo de texto.
    @endverbatim 
*/
void tratamientoMasUsado(int id_entrante)
{
	int i;
	//Crear puntero donde se guardará la dirección del archivo
	FILE * archivo;
	//Abrir el archvio nombre.txt en modo de lectura append
	archivo = fopen("./output.txt", "a");
	char nombreArchivo[50];
	Tratamiento *Tratamientos;
	TratamientoDiagnosticoPaciente *TratamientosDiagPac;
	strcpy(nombreArchivo, "./Archivos_BD/TratamientoDiagnosticoPaciente.txt");
	TratamientosDiagPac = leerTratamientoDiagnosticoPaciente(nombreArchivo, LARGO2);
	if(id_entrante!=0)
	{
		/* Tratamiento mas usado con opcion de idDiagnostico */
		for(i=0; i<=LARGO; i++)
		{}
	}
	else
	{
		/* Tratamiento mas usado simple */
		int Array[LARGO];
		/* Limpio arreglo creado */
		for (i = 0; i < LARGO; i++)
		{
			Array[i] = 0;
		}
		/* */
		for (i = 0; i < LARGO2; i++)
		{
			Array[TratamientosDiagPac[i].idTratamiento]++;
		}
		/* Determinar cual es la cantidad de uso mayor de un tratamiento.*/
		int cantUsos = INT_MIN;
		for(i=0; i<LARGO; i++)
		{
			if(cantUsos <= Array[i])
			{
				cantUsos = Array[i];
			}	
		}
		/*Como pueden haber muchos tratamientos que se hayan usado varias veces*/
		strcpy(nombreArchivo, "./Archivos_BD/Tratamiento.txt");
		Tratamientos = leerTratamiento(nombreArchivo, LARGO);
		int idTratMasUsado, j;
		for(i=0; i<LARGO; i++)
		{
			if(cantUsos==Array[i])
			{
				idTratMasUsado = i;
				/* A este punto, tengo el ID del tratamiento mas usado*/
				for (j = 0; j < LARGO; j++)
				{
					if(idTratMasUsado==Tratamientos[j].idTratamiento)
					{
						fprintf(archivo, "%s,%d\n", Tratamientos[j].nombre, cantUsos);
						j = LARGO;
					}
				}
			}	
		}	
	}
	fclose(archivo);
	free(TratamientosDiagPac);
	free(Tratamientos);
}

/**
	@file funciones.c
	@brief medicoMasAltas: Función de nivel bajo que obtiene el run, nombre y apellido del Medico que otorga más altas.
    @param none
    @returns none
    @verbatim 
    	Función que obtiene el run, nombre y apellido del Medico que otorga más altas.
    	No posee retorno, ya que posee una salida directa a un archivo de texto.
    @endverbatim 
*/
void medicoMasAltas(){	
	int i;
	Medico *Doctor;
	//Crear puntero donde se guardará la dirección del archivo
	FILE * archivo;
	//Abrir el archvio nombre.txt en modo de lectura append
	archivo = fopen("./output.txt", "a");
	char nombreArchivo[50];
	DiagnosticoPaciente *DiagnosticoPacientes;
	strcpy(nombreArchivo, "./Archivos_BD/DiagnosticoPaciente.txt");
	DiagnosticoPacientes = leerDiagnosticoPaciente(nombreArchivo, LARGO2);
	int Array[LARGO];
	/* Limpio arreglo creado */
	for (i = 0; i < LARGO; i++)
	{
		Array[i] = 0;
	}
	/* */
	for (i = 0; i < LARGO2; i++)
	{
		Array[DiagnosticoPacientes[i].idMedico_alta]++;
	}
	/* Determinar cual el medico que da más altas */
	int cantAltas = INT_MIN;
	for(i=0; i<LARGO; i++)
	{
		if(cantAltas <= Array[i])
		{
			cantAltas = Array[i];
		}	
	}
	/* Como pueden haber muchos medicos que den la misma cantidad de altas */
	strcpy(nombreArchivo, "./Archivos_BD/Doctor.txt");
	Doctor = leerMedico(nombreArchivo, LARGO);
	int idMasAltas, j;
	for(i=0; i<LARGO; i++)
	{
		if(cantAltas==Array[i])
		{
			idMasAltas = i;
			/* A este punto, tengo el ID del medico que da más altas */
			for (j = 0; j < LARGO; j++)
			{
				if(idMasAltas==Doctor[j].idMedico)
				{
					fprintf(archivo, "%s, %s %s\n", Doctor[j].run, Doctor[j].nombre, Doctor[j].apellido);
					j = LARGO;
				}
			}
		}	
	}
	fclose(archivo);
	free(DiagnosticoPacientes);
	free(Doctor);
}

/**
	@file funciones.c
	@brief riesgoUltimoTratamiento: Función de nivel alto que obtiene el riesgo del ultimo tratamiento recibido por un determinado paciente.
    @param char nombre[], char apellido[]
    @returns none
    @verbatim 
    	Función que recibe como parametro el nombre y apellido de un paciente X, y obtiene el riesgo del ultimo tratamiento que este ha recibido.
    	No posee retorno, ya que posee una salida directa a un archivo de texto.
    @endverbatim 
*/
void riesgoUltimoTratamiento(char nombre[], char apellido[])
{
	/* Inicializa Variables Locales */
	int i, idPac; 
	Paciente *Pacientes;
	char nombreArchivo[50];
	Tratamiento *Tratamientos;
	DiagnosticoPaciente *DiagnosticoPacientes;
	TratamientoDiagnosticoPaciente *TratamientosDiagPac;
	/*Finaliza Inicalización de Variables */

	//Crear puntero donde se guardará la dirección del archivo
	FILE * archivo;
	//Abrir el archvio nombre.txt en modo de lectura append
	archivo = fopen("./output.txt", "a");

	strcpy(nombreArchivo, "./Archivos_BD/Paciente.txt");
	Pacientes = leerPaciente(nombreArchivo, LARGO);

	for(i=0; i<=LARGO; i++)
	{
		if((strcmp(nombre, Pacientes[i].nombre)==0) && (strcmp(apellido, Pacientes[i].apellido)==0))
		{
			idPac = Pacientes[i].idPaciente;
			i=LARGO;
		}
	}
	free(Pacientes);

	int new_id = -1;
	strcpy(nombreArchivo, "./Archivos_BD/DiagnosticoPaciente.txt");
	DiagnosticoPacientes = leerDiagnosticoPaciente(nombreArchivo, LARGO2);
	for (i = (LARGO2/2); i < LARGO2; i++)
	{
		if(idPac == DiagnosticoPacientes[i].idPaciente)
			new_id = DiagnosticoPacientes[i].idDiagnosticoPaciente;
	}
	if(new_id == -1)
	{
		for (i = 0; i < (LARGO2/2); i++)
		{
			if(idPac == DiagnosticoPacientes[i].idPaciente)
				new_id = DiagnosticoPacientes[i].idDiagnosticoPaciente;
		}
	}
	free(DiagnosticoPacientes);

	int id_finalTratamiento = -1;
	strcpy(nombreArchivo, "./Archivos_BD/TratamientoDiagnosticoPaciente.txt");
	TratamientosDiagPac = leerTratamientoDiagnosticoPaciente(nombreArchivo, LARGO2);
	for (i = (LARGO2/2); i < LARGO2; i++)
	{
		if(new_id == TratamientosDiagPac[i].idDiagnosticoPaciente)
			id_finalTratamiento = TratamientosDiagPac[i].idTratamiento;
	}
	if(id_finalTratamiento == -1)
	{
		for (i = 0; i < (LARGO2/2); i++)
		{
			if(new_id == TratamientosDiagPac[i].idDiagnosticoPaciente)
				id_finalTratamiento = TratamientosDiagPac[i].idTratamiento;
		}
	}
	free(TratamientosDiagPac);
	
	/* A este punto, tengo el ID del tratamiento buscado*/
	strcpy(nombreArchivo, "./Archivos_BD/Tratamiento.txt");
	Tratamientos = leerTratamiento(nombreArchivo, LARGO);
	for (i = 0; i < LARGO; i++)
	{
		if(id_finalTratamiento==Tratamientos[i].idTratamiento)
		{
			fprintf(archivo, "%s\n", Tratamientos[i].nivel_riesgo);
			i = LARGO;
		}
	}	
	fclose(archivo);
	free(Tratamientos);
}

/**
	@file funciones.c
	@brief diagnosticoPacienteMedico: Función de nivel alto que obtiene los datos de los pacientes que recibieron un diagnostico X de parte de un medico Y. 
    @param char nombreDiagnostico[], char runDoctor[]
    @returns none
    @verbatim 
    	Función que recibe como parametro el nombre del diagnostico especificado y el run del medico diagnosticado. 
    	Con dichos datos, realiza una busqueda de vinculaciones, obteniendo los pacientes diagnosticados con dicho diagnostico X por el medico Y.
    	No posee retorno, ya que posee una salida directa a un archivo de texto.
    @endverbatim 
*/
void diagnosticoPacienteMedico(char nombreDiagnostico[], char runDoctor[])
{
	Medico *Doctor;
	Paciente *Pacientes;
	char nombreArchivo[50];
	Diagnostico *Diagnosticos;
	int i, indice, idDiag, idDoctor, idPac;
	DiagnosticoPaciente *DiagnosticoPacientes;
	/*Finaliza Inicalización de Variables */

	//Crear puntero donde se guardará la dirección del archivo
	FILE * archivo;
	//Abrir el archvio nombre.txt en modo de lectura append
	archivo = fopen("./output.txt", "a");

	/* Obtengo idDiagnostico buscado */
	strcpy(nombreArchivo, "./Archivos_BD/Diagnostico.txt");
	Diagnosticos = leerDiagnostico(nombreArchivo, LARGO);
	for(i=0; i<=LARGO; i++)
	{
		if(strcmp(nombreDiagnostico, Diagnosticos[i].nombre_diag)==0) 
		{
			idDiag = Diagnosticos[i].idDiagnostico;
			i=LARGO;
		}
	}
	free(Diagnosticos);

	/* Obtengo idMedico buscado */
	strcpy(nombreArchivo, "./Archivos_BD/Doctor.txt");
	Doctor = leerMedico(nombreArchivo, LARGO);
	for(i=0; i<=LARGO; i++)
	{
		if(strcmp(runDoctor, Doctor[i].run)==0) 
		{
			idDoctor = Doctor[i].idMedico;
			i=LARGO;
		}
	}
	free(Doctor);

	/* Busco los pacientes a los cuales se les diagnostico "idDiag" y les dio el alta "idDoctor" */
	strcpy(nombreArchivo, "./Archivos_BD/DiagnosticoPaciente.txt");
	DiagnosticoPacientes = leerDiagnosticoPaciente(nombreArchivo, LARGO2);
	strcpy(nombreArchivo, "./Archivos_BD/Paciente.txt");
	Pacientes = leerPaciente(nombreArchivo, LARGO);
	for(i=0; i<=LARGO2; i++)
	{
		if(DiagnosticoPacientes[i].idDiagnostico==idDiag &&  DiagnosticoPacientes[i].idMedico_alta==idDoctor)
		{
			idPac = DiagnosticoPacientes[i].idPaciente;
			for(indice=0; indice<LARGO; indice++)
			{
				if(Pacientes[indice].idPaciente==idPac)
				{
					fprintf(archivo, "%s, %s, %s \n", Pacientes[indice].run, Pacientes[indice].nombre, Pacientes[indice].apellido);
					indice = LARGO;
				}	
			}	

		}
	}
	fclose(archivo);
	free(Pacientes);
	free(DiagnosticoPacientes);
}

/**
	@file funciones.c
	@brief listarMedicosTratantesPaciente: Función de nivel alto que obtiene los datos de los medicos que han atendido un paciente X.
    @param char runPaciente[]
    @returns none
    @verbatim 
    	Función que recibe como parametro el run de un paciente en especifico, realiza una busqueda de vinculaciones, 
    	obteniendo los datos de los medicos que han atendido al paciente indicado.
    	Se consideran medido de diagnostico y medico que da el alta.
    	No posee retorno, ya que posee una salida directa a un archivo de texto.
    @endverbatim 
*/
void listarMedicosTratantesPaciente(char runPaciente[])
{
	Medico *Doctor;
	Paciente *Pacientes;
	char nombreArchivo[50];
	DiagnosticoPaciente *DiagnosticoPacientes;
	int i, indice, idDoctor_diag, idDoctor_alta, idPac;

	//Crear puntero donde se guardará la dirección del archivo
	FILE * archivo;
	//Abrir el archvio nombre.txt en modo de lectura append
	archivo = fopen("./output.txt", "a");

	/* Obtengo idPaciente buscado */
	strcpy(nombreArchivo, "./Archivos_BD/Paciente.txt");
	Pacientes = leerPaciente(nombreArchivo, LARGO);
	for(i=0; i<=LARGO; i++)
	{
		if(strcmp(runPaciente, Pacientes[i].run)==0) 
		{
			idPac = Pacientes[i].idPaciente;
			i=LARGO;
		}
	}
	free(Pacientes);

	/* Busco los medicos que han atendido al paciente encontrado*/
	strcpy(nombreArchivo, "./Archivos_BD/DiagnosticoPaciente.txt");
	DiagnosticoPacientes = leerDiagnosticoPaciente(nombreArchivo, LARGO2);
	strcpy(nombreArchivo, "./Archivos_BD/Doctor.txt");
	Doctor = leerMedico(nombreArchivo, LARGO);
	for(i=0; i<=LARGO2; i++)
	{
		if(DiagnosticoPacientes[i].idPaciente==idPac)
		{
			idDoctor_alta = DiagnosticoPacientes[i].idMedico_alta;
			idDoctor_diag = DiagnosticoPacientes[i].idMedico_diagnostico;
			for(indice=0; indice<LARGO; indice++)
			{
				if(Doctor[indice].idMedico==idDoctor_diag)
				{
					fprintf(archivo, "%s,%s,%s\n", Doctor[indice].run, Doctor[indice].nombre, Doctor[indice].apellido);
					indice = LARGO;
				}	
			}
			for(indice=0; indice<LARGO; indice++)
			{
				if(Doctor[indice].idMedico==idDoctor_alta)
				{
					fprintf(archivo, "%s,%s,%s\n", Doctor[indice].run, Doctor[indice].nombre, Doctor[indice].apellido);
					indice = LARGO;
				}	
			}
		}
	}
	fclose(archivo);
	free(Doctor);
	free(DiagnosticoPacientes);

}

/**
	@file funciones.c
	@brief rutPacienteDiagnostico: Función de nivel medio que determina el diagnostico mas frecuente de un paciente.
    @param char runPaciente[]
    @returns none
    @verbatim 
    	Función que recibe como parametro el run de un paciente e indica el diagnostico mas frecuente de dicho paciente.
    	No posee retorno, ya que posee una salida directa a un archivo de texto.
    @endverbatim 
*/
void rutPacienteDiagnostico(char runPaciente[])
{
	Paciente *Pacientes;
	char nombreArchivo[50];
	Diagnostico *Diagnosticos;
	DiagnosticoPaciente *DiagnosticoPacientes;
	int i, indice, idPac;

	//Crear puntero donde se guardará la dirección del archivo
	FILE * archivo;
	//Abrir el archvio nombre.txt en modo de lectura append
	archivo = fopen("./output.txt", "a");

	/* Obtengo idPaciente buscado */
	strcpy(nombreArchivo, "./Archivos_BD/Paciente.txt");
	Pacientes = leerPaciente(nombreArchivo, LARGO);
	for(i=0; i<=LARGO; i++)
	{
		if(strcmp(runPaciente, Pacientes[i].run)==0) 
		{
			idPac = Pacientes[i].idPaciente;
			i=LARGO;
		}
	}
	free(Pacientes);

	/* Obtengo los diagnosticos que ha recivido dicho paciente */
	strcpy(nombreArchivo, "./Archivos_BD/DiagnosticoPaciente.txt");
	DiagnosticoPacientes = leerDiagnosticoPaciente(nombreArchivo, LARGO2);
	int Array[LARGO];
	/* Limpio arreglo creado */
	for (i = 0; i < LARGO; i++)
	{ Array[i] = 0;}
	/* Guardo en cada posicion la cantidad de veces que aparece el id representado por la posicion del arreglo*/
	for (i = 0; i < LARGO2; i++)
	{
		if(idPac == DiagnosticoPacientes[i].idPaciente)
			Array[DiagnosticoPacientes[i].idDiagnostico]++;
	}
	/* Determinar el diagnostico mas frecuente */
	int cantFrecuencia = INT_MIN;
	for(i=0; i<LARGO; i++)
	{
		if(cantFrecuencia <= Array[i])
		{
			cantFrecuencia = Array[i];
		}	
	}
	/*Como pueden haber varios que tengan la misma frecuencia */
	strcpy(nombreArchivo, "./Archivos_BD/Diagnostico.txt");
	Diagnosticos = leerDiagnostico(nombreArchivo, LARGO);
	int idMasFrecuente, j;
	for(i=0; i<LARGO; i++)
	{
		if(cantFrecuencia==Array[i])
		{	
			idMasFrecuente = i;
			/* A este punto, tengo el ID del medico que da más altas */
			for (j = 0; j < LARGO; j++)
			{
				if(idMasFrecuente==Diagnosticos[j].idDiagnostico)
				{
					fprintf(archivo, "%s\n", Diagnosticos[j].nombre_diag);
					j = LARGO;
				}
			}
		}	
	}
	fclose(archivo);
	free(Diagnosticos);
	free(DiagnosticoPacientes);
}

/**
	@file funciones.c
	@brief tratamientosDiagnosticoPaciente: Función de nivel medio que determina que tratamiento puede recibir un paciente a partir de su diagnostico. 
    @param int idDiagnostico, int idPaciente
    @returns none
    @verbatim 
    	Función que recibe como parametro el identificador del diagnostico recibido y el identificador del paciente que recibe dicho tratamiento.
    	Se determina que tratamiento puede recibir el paciente a partir de su diagnostico. 
    	No posee retorno, ya que posee una salida directa a un archivo de texto.
    @endverbatim 
*/
void tratamientosDiagnosticoPaciente(int idDiagnostico, int idPaciente)
{
	char nombreArchivo[50];
	Tratamiento *Tratamientos;
	DiagnosticoPaciente *DiagnosticoPacientes;
	TratamientoDiagnosticoPaciente *TratamientosDiagPac;
	int i, j, k, idBuscadoDiagnosticoPaciente, idTrat;

	//Crear puntero donde se guardará la dirección del archivo
	FILE * archivo;
	//Abrir el archvio nombre.txt en modo de lectura append
	archivo = fopen("./output.txt", "a");

	strcpy(nombreArchivo, "./Archivos_BD/Tratamiento.txt");
	Tratamientos = leerTratamiento(nombreArchivo, LARGO);
	strcpy(nombreArchivo, "./Archivos_BD/DiagnosticoPaciente.txt");
	DiagnosticoPacientes = leerDiagnosticoPaciente(nombreArchivo, LARGO2);
	strcpy(nombreArchivo, "./Archivos_BD/TratamientoDiagnosticoPaciente.txt");
	TratamientosDiagPac = leerTratamientoDiagnosticoPaciente(nombreArchivo, LARGO2);

	for(i=0; i<LARGO2; i++)
	{
		if(DiagnosticoPacientes[i].idDiagnostico == idDiagnostico && DiagnosticoPacientes[i].idPaciente == idPaciente)
		{
			idBuscadoDiagnosticoPaciente = DiagnosticoPacientes[i].idDiagnosticoPaciente;
			for(j=0; j<LARGO2; j++)
			{
				if(TratamientosDiagPac[j].idDiagnosticoPaciente == idBuscadoDiagnosticoPaciente)
				{
					idTrat = TratamientosDiagPac[j].idTratamiento;
					for(k=0; k<LARGO; k++)
					{
						if(Tratamientos[k].idTratamiento == idTrat)
						{
							fprintf(archivo, "%s,%s\n", Tratamientos[k].nombre, Tratamientos[k].descripcion);
							k=LARGO;
						}	
					}
				}	
			}
		}
	}
	fclose(archivo);
	free(Tratamientos);
	free(DiagnosticoPacientes);
	free(TratamientosDiagPac);	
		
} 

/**
	@file funciones.c
	@brief medicosTratantes: Función de nivel medio que indica nombre y apellido de todos los medicos que han tratado a un paciente indicado.
    @param int idPaciente
    @returns none
    @verbatim 
    	Función que recibe como parametro el identificador de un paciente, realiza una busqueda en "BD" y entrega la información 
    	(nombre-apellido) de todos lo medicos tratantes del paciente especificado.
    	No posee retorno, ya que posee una salida directa a un archivo de texto.
    @endverbatim 
*/
void medicosTratantes(int idPaciente)
{
	Medico *Doctor;
	char nombreArchivo[50];
	DiagnosticoPaciente *DiagnosticoPacientes;
	int i, indice, idDoctor_diag, idDoctor_alta;

	//Crear puntero donde se guardará la dirección del archivo
	FILE * archivo;
	//Abrir el archvio nombre.txt en modo de lectura append
	archivo = fopen("./output.txt", "a");

	/* Busco los medicos que han atendido al paciente encontrado*/
	strcpy(nombreArchivo, "./Archivos_BD/DiagnosticoPaciente.txt");
	DiagnosticoPacientes = leerDiagnosticoPaciente(nombreArchivo, LARGO2);
	strcpy(nombreArchivo, "./Archivos_BD/Doctor.txt");
	Doctor = leerMedico(nombreArchivo, LARGO);
	for(i=0; i<=LARGO2; i++)
	{
		if(DiagnosticoPacientes[i].idPaciente==idPaciente)
		{
			idDoctor_alta = DiagnosticoPacientes[i].idMedico_alta;
			idDoctor_diag = DiagnosticoPacientes[i].idMedico_diagnostico;
			for(indice=0; indice<LARGO; indice++)
			{
				if(Doctor[indice].idMedico==idDoctor_diag)
				{
					fprintf(archivo, "%s %s\n", Doctor[indice].nombre, Doctor[indice].apellido);
					indice = LARGO;
				}	
			}
			for(indice=0; indice<LARGO; indice++)
			{
				if(Doctor[indice].idMedico==idDoctor_alta)
				{
					fprintf(archivo, "%s %s\n", Doctor[indice].nombre, Doctor[indice].apellido);
					indice = LARGO;
				}	
			}
		}
	}
	fclose(archivo);
	free(Doctor);
	free(DiagnosticoPacientes);
}

/**
	@file funciones.c
	@brief tratamientosPacienteCorreo: Función de nivel medio que lista los tratamientos recibidos por un paciente a partir de su correo electronico.
    @param char correo[]
    @returns none
    @verbatim 
    	Función que recibe como parametro el correo electronico de un paciente, realiza una busqueda en "BD" y entrega una lista de todos los 
    	tratamientos recibidos por paciente especificado.
    	No posee retorno, ya que posee una salida directa a un archivo de texto.
    @endverbatim 
*/
void tratamientosPacienteCorreo(char correo[])
{
	char nombreArchivo[50];
	Paciente *Pacientes;
	Tratamiento *Tratamientos;
	DiagnosticoPaciente *DiagnosticoPacientes;
	TratamientoDiagnosticoPaciente *TratamientosDiagPac;
	int i, indice, idPac, idDP, j, idTrat;

	//Crear puntero donde se guardará la dirección del archivo
	FILE * archivo;
	//Abrir el archvio nombre.txt en modo de lectura append
	archivo = fopen("./output.txt", "a");

	/* Obtengo idPaciente buscado */
	strcpy(nombreArchivo, "./Archivos_BD/Paciente.txt");
	Pacientes = leerPaciente(nombreArchivo, LARGO);
	for(i=0; i<=LARGO; i++)
	{
		if(strcmp(correo, Pacientes[i].email)==0) 
		{
			idPac = Pacientes[i].idPaciente;
			i=LARGO;
		}
	}
	free(Pacientes);

	/* Busco los IdDiagnosticoPaciente relacionados a mi IdPaciente y relaciono los tratamientos que ha recibido*/
	strcpy(nombreArchivo, "./Archivos_BD/DiagnosticoPaciente.txt");
	DiagnosticoPacientes = leerDiagnosticoPaciente(nombreArchivo, LARGO2);
	strcpy(nombreArchivo, "./Archivos_BD/Tratamiento.txt");
	Tratamientos = leerTratamiento(nombreArchivo, LARGO);
	strcpy(nombreArchivo, "./Archivos_BD/TratamientoDiagnosticoPaciente.txt");
	TratamientosDiagPac = leerTratamientoDiagnosticoPaciente(nombreArchivo, LARGO2);
	for(i=0; i<=LARGO2; i++)
	{
		if(DiagnosticoPacientes[i].idPaciente==idPac)
		{
			idDP = DiagnosticoPacientes[i].idDiagnosticoPaciente;
			for(indice=0; indice<LARGO2; indice++)
			{
				if(TratamientosDiagPac[indice].idDiagnosticoPaciente==idDP)
				{
					idTrat = TratamientosDiagPac[indice].idTratamiento;
					for(j=0; j<LARGO; j++)
					{
						if(idTrat==Tratamientos[j].idTratamiento)
						{
							fprintf(archivo, "%s,%s\n", Tratamientos[j].nombre, Tratamientos[j].descripcion);
						}	
					}	
				}	
			}
		}
	}
	fclose(archivo);
	free(Tratamientos);
	free(TratamientosDiagPac);
	free(DiagnosticoPacientes);

}

/**
	@file funciones.c
	@brief eliminarPaciente: Función de nivel medio elimina un paciente siempre cuando este no posea diagnosticos.
    @param char runPaciente[]
    @returns none
    @verbatim 
    	Función que recibe como parametro el run de un paciente, realiza una busqueda en "BD" y elimina los registros del paciente indicado,
    	siempre y cuando, este paciente no tenga diagnosticos en los registros del sistema.
    	No posee retorno, ya que la operación se refleja en el archivo Paciente.txt
    @endverbatim 
*/
void eliminarPaciente(char runPaciente[])
{
	char nombreArchivo[50];
	Paciente *Pacientes;
	DiagnosticoPaciente *DiagnosticoPacientes;
	int i, verificador, idPac = INT_MIN;

	//Crear puntero donde se guardará la dirección del archivo
	FILE * archivo;
	//Abrir el archvio nombre.txt en modo de lectura append
	archivo = fopen("./output.txt", "a");

	/* Obtengo idPaciente buscado */
	strcpy(nombreArchivo, "./Archivos_BD/Paciente.txt");
	Pacientes = leerPaciente(nombreArchivo, LARGO);
	for(i=0; i<LARGO; i++)
	{
		if(strcmp(runPaciente, Pacientes[i].run)==0) 
		{
			idPac = Pacientes[i].idPaciente;
			i=LARGO;
		}
	}
	verificador = 0; //Servira para comprobar si el paciente tiene diagnosticos en los registros.

	strcpy(nombreArchivo, "./Archivos_BD/DiagnosticoPaciente.txt");
	DiagnosticoPacientes = leerDiagnosticoPaciente(nombreArchivo, LARGO2);
	for(i=0; i<LARGO2;i++)
	{
		if(idPac==DiagnosticoPacientes[i].idPaciente)
		{
			verificador = 1;
			i=LARGO2;
		}		
	}

	if(verificador==0)
	{
		//Crear puntero donde se guardará la dirección del archivo
		FILE * archivoPacientes;
		//Abrir el archvio nombre.txt en modo de lectura append
		archivoPacientes = fopen("./Archivos_BD/Paciente.txt", "W");
		//Escribo la primera linea del archivo
		fprintf( archivoPacientes, "identificador,rut,email,nombre,apellido,fecha de nacimiento\n");
		for(i=0; i<LARGO; i++)
		{
			if(Pacientes[i].idPaciente!=idPac)
			{
				fprintf(archivoPacientes, "%d,%s,%s,%s,%s,%s", Pacientes[i].idPaciente,Pacientes[i].run,Pacientes[i].email,Pacientes[i].nombre,Pacientes[i].apellido,Pacientes[i].fecha_nac);
			}	
		}
		fclose(archivoPacientes);
	}	
	fclose(archivo);
	free(Pacientes);
	free(DiagnosticoPacientes);
}

/**
	@file funciones.c
	@brief eliminarMedico: Función de nivel medio elimina un medico.
    @param char runDoctor[]
    @returns none
    @verbatim 
    	Función que recibe como parametro el run de un medico, realiza una busqueda en "BD" y elimina los registros del medico indicado,
    	siempre y cuando, este medico no sea responsable de diagnosticos o tratamientos vigentes.
    	No posee retorno, ya que la operación se refleja en el archivo Doctor.txt
    @endverbatim 
*/
void eliminarMedico(char runDoctor[])
{
	char nombreArchivo[50];
	Medico *Doctor;
	DiagnosticoPaciente *DiagnosticoPacientes;
	int i, verificador, idDoc = INT_MIN;

	/* Obtengo idPaciente buscado */
	strcpy(nombreArchivo, "./Archivos_BD/Doctor.txt");
	Doctor = leerMedico(nombreArchivo, LARGO);
	for(i=0; i<LARGO; i++)
	{
		if(strcmp(runDoctor, Doctor[i].run)==0) 
		{
			idDoc = Doctor[i].idMedico;
			i=LARGO;
		}
	}
	
	verificador = 0; 

	/**Comprueba si el medico tiene diagnosticos o tratamientos vigentes*/
	strcpy(nombreArchivo, "./Archivos_BD/DiagnosticoPaciente.txt");
	DiagnosticoPacientes = leerDiagnosticoPaciente(nombreArchivo, LARGO2);
	for(i=0; i<LARGO2;i++)
	{
		if(idDoc==DiagnosticoPacientes[i].idMedico_diagnostico && strcmp(DiagnosticoPacientes[i].estado_diagnostico, "vigente")==0)
		{
			verificador = 1;
			i=LARGO2;
		}		
	}

	/**Si verificador es igual a 0 quiere decir que el medico puede ser eliminado*/
	if(verificador==0)
	{
		//Crear puntero donde se guardará la dirección del archivo
		FILE * archivDocs;
		//Abrir el archvio nombre.txt en modo de lectura append
		archivDocs = fopen("./Archivos_BD/Doctor.txt", "W");
		//Escribo la primera linea del archivo
		fprintf( archivDocs, "identificador,rut,email,Nombre,apellido,especialidad\n");
		for(i=0; i<=LARGO; i++)
		{
			if(Doctor[i].idMedico!=idDoc)
			{
				fprintf(archivDocs, "%d,%s,%s,%s,%s,%s", Doctor[i].idMedico,Doctor[i].run,Doctor[i].email,Doctor[i].nombre,Doctor[i].apellido,Doctor[i].especialidad);
			}	
		}
		fclose(archivDocs);
	}	
	free(Doctor);
	free(DiagnosticoPacientes);
}

/**
	@file funciones.c
	@brief modificarCorreoPaciente: Función de basico que modifica el correo de un paciente.
    @param char modificarCorreoPaciente[]
    @returns none
    @verbatim 
    	Función que recibe como parametro el correo actual de un paciente y el nuevo correo a registrar.
    	Reemplaza el correo antiguo por el nuevo correo ingresado.
    	No posee retorno, ya que la operación realizada se refleja en el archivo Paciente.txt
    @endverbatim 
*/
void modificarCorreoPaciente(char correoAntiguo[], char correoNuevo[])
{
	char nombreArchivo[50];
	Paciente *Pacientes;
	int i, verificador = 1;
	
	/* Obtengo idPaciente buscado */
	strcpy(nombreArchivo, "./Archivos_BD/Paciente.txt");
	Pacientes = leerPaciente(nombreArchivo, LARGO);
	for(i=0; i<LARGO; i++)
	{
		if(strcmp(correoAntiguo, Pacientes[i].email)==0) 
		{
			strcpy(Pacientes[i].email, correoNuevo);
			verificador = 0;
			i=LARGO;
		}
	}

	if(verificador==0)
	{
		//Crear puntero donde se guardará la dirección del archivo
		FILE * archivoPacientes;
		//Abrir el archvio nombre.txt en modo de lectura append
		archivoPacientes = fopen("./Archivos_BD/Paciente.txt", "w");
		//Escribo la primera linea del archivo
		fprintf( archivoPacientes, "identificador,rut,email,nombre,apellido,fecha de nacimiento\n");
		//Escribo las demas lineas del archivo.
		for(i=0; i<100; i++)
		{
			fprintf(archivoPacientes, "%d,%s,%s,%s,%s,%s", Pacientes[i].idPaciente,Pacientes[i].run,Pacientes[i].email,Pacientes[i].nombre,Pacientes[i].apellido,Pacientes[i].fecha_nac);	
		}
		fclose(archivoPacientes);
	}
	free(Pacientes);
}