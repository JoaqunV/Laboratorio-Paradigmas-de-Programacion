
#include "funciones.c"

/****************** Comienzo del main ******************/
int main(int argc, char **argv)
{
	int a, b;
	/** Opción Basica obtenerNombrePaciente */
	if(strcmp(argv[1],"-obtenerNombrePaciente")==0)
	{	
		obtenerNombrePaciente(argv[2]);
	}
	else
	{	/** Opción Basica especialidad */
		if(strcmp(argv[1],"-especialidad")==0)
		{
			especialidad(argv[2]);
		}
		else
		{
			if(strcmp(argv[1], "-tratamientoRiesgoso")==0)
			{	
				char argumento[10] = "";
				if(argc==4)
				{
					strcat(argumento, argv[2]);
					strcat(argumento, " ");
					strcat(argumento, argv[3]);
					strcat(argumento, "\n");
				}
				else
				{
					strcat(argumento, argv[2]);
					strcat(argumento, "\n");
				}
				tratamientoRiesgoso(argumento);
			}	
			else
			{
				if(strcmp(argv[1], "-tratamientoMasUsado")==0)
				{
					/* Tratamiento mas usado con opcion de idDiagnostico */
					if(argc==3)
					{
						int identificador = atoi(argv[2]); 
						tratamientoMasUsado(identificador);
					}	
					else
						tratamientoMasUsado(0);
				}
				else
				{
					
					if(strcmp(argv[1], "-medicoMasAltas")==0)
					{
						medicoMasAltas();
					}
					else
					{ 
						if(strcmp(argv[1], "-riesgoUltimoTratamiento")==0)
						{
							riesgoUltimoTratamiento(argv[2], argv[3]);
						}
						else
						{   
							if(strcmp(argv[1], "-diagnosticoPacienteMedico")==0)
							{
								diagnosticoPacienteMedico(argv[2], argv[3]);
							}
							else
							{ 
								if(strcmp(argv[1], "-listarMedicosTratantesPaciente")==0)
								{
									listarMedicosTratantesPaciente(argv[2]);
								}
								else
								{
									if (strcmp(argv[1], "-rutPacienteDiagnostico")==0)
									{
										rutPacienteDiagnostico(argv[2]);
									}
									else	
									{	
										if(strcmp(argv[1], "-tratamientosDiagnosticoPaciente")==0)
										{
											a = atoi(argv[2]);
											b = atoi(argv[3]);
											tratamientosDiagnosticoPaciente(a,b);
										}
										else
										{	
											if(strcmp(argv[1], "-medicosTratantes")==0)
											{
												a = atoi(argv[2]);
												medicosTratantes(a);
											}
											else
											{
												if(strcmp(argv[1], "-tratamientosPacienteCorreo")==0)
												{
													tratamientosPacienteCorreo(argv[2]);
												}
												else
												{
													if(strcmp(argv[1], "-eliminarPaciente")==0)
													{
														eliminarPaciente(argv[2]);
													}
													else
													{ 
														if(strcmp(argv[1], "-eliminarMedico")==0)
														{
															eliminarMedico(argv[2]);
														}
														else
														{
															if(strcmp(argv[1],"-modificarCorreoPaciente")==0)
															{
																modificarCorreoPaciente(argv[2], argv[3]);
															}
															else
															{
																printf("Opcion ingresada no es valida...\n");
															}	
														}
													}	
												}
											}
										}
									}
								} 
							}	
						}
					}
				}
			}
		}
	}
	return 0;

}
