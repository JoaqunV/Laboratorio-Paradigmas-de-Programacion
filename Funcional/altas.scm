
(define (diagnosticoPacienteMedico nombre run) 
  
  (define (obtenerIdDiags nombre Diagnosticos)
    (if (null? Diagnosticos)
        null
        (if(equal? nombre (obtenerDescripcionDiagnostico (car Diagnosticos)))
           (obtenerIDDiagnostico (car Diagnosticos))
           (obtenerIdDiags nombre (cdr Diagnosticos))
           )
        )
    )
  
  (define (obtenerIdDoc run Doctores)
    (if (null? Doctores)
        null
        (if(equal? run (obtenerRunDoctor (car Doctores)))
           (obtenerIDDoctor (car Doctores))
           (obtenerIdDoc run (cdr Doctores))
           )
        )	
    )
  
  (define (ObtenIdentificadorPaciente Id doctorDeAlta DiagnosticosPacientes)
    (if(null? DiagnosticosPacientes)
       null
       (if(and (equal? Id (getIdDiagDP (car DiagnosticosPacientes))) 
               (equal? doctorDeAlta (getDoctorAlta (car DiagnosticosPacientes))) )
          (cons (obtenerIdPacienteDiagnosticoPaciente (car DiagnosticosPacientes)) (ObtenIdentificadorPaciente Id doctorDeAlta (cdr DiagnosticosPacientes)))
          (ObtenIdentificadorPaciente Id doctorDeAlta (cdr DiagnosticosPacientes))))) (define (ObtenerDatosNecesarios Id Pacientes) (if(null? Pacientes) null (if(equal? Id (obtenerIDPaciente (car Pacientes))) (string-append (obtenerRunPaciente(car Pacientes)) ", " (obtenerNombrePaciente (car Pacientes)) ", " (obtenerApellidoPaciente (car Pacientes))) (ObtenerDatosNecesarios Id (cdr Pacientes))))) (define (CrearListaDeString listaDePacientes) (if (null? listaDePacientes) null (cons (ObtenerDatosNecesarios (car listaDePacientes) Pacientes) (CrearListaDeString (cdr listaDePacientes))))) (CrearListaDeString (ObtenIdentificadorPaciente (obtenerIdDiags nombre Diagnosticos) (obtenerIdDoc run Doctores) DiagnosticosPacientes)))
  
