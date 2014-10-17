;====Nivel Alto==========
;========================

(define (listarMedicosTratantesPaciente run) (define (ObtenIdentificadorPaciente run Pacientes)
    (if (null? Pacientes) null (if(equal? run (obtenerRunPaciente (car Pacientes))) (obtenerIDPaciente (car Pacientes)) (ObtenIdentificadorPaciente run (cdr Pacientes)))))
  (define (ObtenerIdentificadorDoctor Id DiagnosticosPacientes)
    (if (null? DiagnosticosPacientes)
        null
        (if(equal? Id (obtenerIdPacienteDiagnosticoPaciente (car DiagnosticosPacientes)))
           (cons (obtenerIdDoctorDiagnosticoDiagnosticoPaciente (car DiagnosticosPacientes)) (ObtenerIdentificadorDoctor Id (cdr DiagnosticosPacientes)))
           (ObtenerIdentificadorDoctor Id (cdr DiagnosticosPacientes))
           )
        )
    )
  
  (define (ObtenerDatosNecesarios Id Doctores)
    (if (null? Doctores)
        null
        (if(equal? Id (obtenerIDDoctor (car Doctores)))
           (string-append (obtenerRunDoctor (car Doctores)) ", " (getNombreDoc (car Doctores)) ", " (getApellidoDoc (car Doctores)))
           (ObtenerDatosNecesarios Id (cdr Doctores))
           )
        )
    )
   (define (CrearListaDeString ListaDeDoctores)
    (if (null? ListaDeDoctores)
        null
        (cons (ObtenerDatosNecesarios (car ListaDeDoctores) Doctores) (CrearListaDeString (cdr ListaDeDoctores)))
        )
    )
  (CrearListaDeString (ObtenerIdentificadorDoctor (ObtenIdentificadorPaciente run Pacientes) DiagnosticosPacientes))
;==========


;==================================================
(define (diagnosticoPacienteMedico nombreDiag rutDoc) ;recibe 2 string retorna lista de string
  
  (define (conseguirIdDiag nombreDiag Diagnosticos);obtencion datos utiles recursivamente
    (if (null? Diagnosticos)
        null
        (if(equal? nombreDiag (getDescripDiag (car Diagnosticos)))
           (getIdDiag (car Diagnosticos))
           (conseguirIdDiag nombreDiag (cdr Diagnosticos))
           )
        )
    )
  
  (define (conseguirIdDoc run Doctores);obtencion datos utiles recursivamente
    (if (null? Doctores)
        null
        (if(equal? run (obtenerRunDoctor (car Doctores)))
           (obtenerIDDoctor (car Doctores))
           (conseguirIdDoc rutDoc (cdr Doctores))
           )
        )
    )
  
  (define (ObtenIdentificadorPaciente idDiag DocAlta DiagnosticosPacientes);obtencion datos utiles recursivamente
    (if(null? DiagnosticosPacientes)
       null
       (if(and (equal? idDiag (getIdDiagDP (car DiagnosticosPacientes))) 
               (equal? DocAlta (getDoctorAlta (car DiagnosticosPacientes))) )
          (cons (obtenerIdPacienteDiagnosticoPaciente (car DiagnosticosPacientes)) (ObtenIdentificadorPaciente idDiag DocAlta (cdr DiagnosticosPacientes)))
          (ObtenIdentificadorPaciente idDiag DocAlta (cdr DiagnosticosPacientes))
          )
       )
    )
  
  (define (ObtenerDatosNecesarios Id Pacientes);obtencion datos pedidos
    (if(null? Pacientes)
       null
       (if(equal? Id (obtenerIDPaciente (car Pacientes)))
          ;creacion string
          (string-append (obtenerRunPaciente(car Pacientes)) ", " (getNombrePac (car Pacientes)) ", " (getApellidoPac (car Pacientes)))
          (ObtenerDatosNecesarios Id (cdr Pacientes))
          )
       )
    )
  (define (CrearListaDeString listPacs);creacion lista string
    (if (null? listPacs)
        null
        (cons (ObtenerDatosNecesarios (car listPacs) Pacientes) (CrearListaDeString (cdr listPacs)))
        )
    )
  ;llamado funcion
  (CrearListaDeString (ObtenIdentificadorPaciente (conseguirIdDiag nombreDiag Diagnosticos) (conseguirIdDoc rutDoc Doctores) DiagnosticosPacientes))
)
 
