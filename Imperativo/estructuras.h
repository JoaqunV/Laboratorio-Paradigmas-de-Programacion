						

						/**En este archivo se definen todas las estructuras a ultilizar en fastClinic*/

						/** Estructura que engloba las caracteristicas de nuestro Paciente */
						typedef struct paciente 
						{
							int idPaciente;
							char run[20];
							char email[50];
							char nombre[45];
							char apellido[45];
							char fecha_nac[10];

						}Paciente;

						/** Estructura que engloba las caracteristicas de nuestro Medico */
						typedef struct medico 
						{
							int idMedico;
							char run[20];
							char email[45];
							char nombre[45];
							char apellido[45];
							char especialidad[45];

						}Medico;

						/** Estructura que engloba las caracteristicas de nuestros Tratamientos */
						typedef struct tratamiento 
						{
							int idTratamiento;
							char nombre[45];
							char descripcion[400];
							char nivel_riesgo[10];

						}Tratamiento;

						/** Estructura que engloba las caracteristicas de nuestros Diagnosticos */
						typedef struct diagnostico 
						{
							int idDiagnostico;
							char nombre_diag[45];
							char nivel_gravedad[10];	

						}Diagnostico;

						/** Estructura que relaciona el tratamiento con el diagnostico */
						typedef struct tratamientoDiagnostico 
						{
							int idTratamiento;
							int idDiagnostico;

						}TratamientoDiagnostico;

						/** Estructura que relaciona los registros de tratamiento, diagnostico y pacientes. */
						typedef struct tratamientoDiagnosticoPaciente
						{
							int idDiagnosticoPaciente;
							int idTratamiento;
							int idMedico;
							char fecha_inicio[15];
							char duracion[25];
							char resultado[15];

						}TratamientoDiagnosticoPaciente;

						/** Estructura que relaciona los registros de diagnosticos y pacientes */
						typedef struct diagnosticoPaciente 
						{
							int idDiagnosticoPaciente;
							int idPaciente;
							int idDiagnostico;
							char fecha_diag[10];
							int idMedico_diagnostico;
							char estado_diagnostico[10];
							char fecha_alta[10];
							int idMedico_alta;
							char detalle_alta[200];
	
						}DiagnosticoPaciente;
