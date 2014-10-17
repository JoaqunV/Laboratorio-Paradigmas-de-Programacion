#lang racket
;Selectores para el TDA Paciente
(define (obtenerIDPaciente Pacientes) (if (isPaciente? Pacientes) (car Pacientes) #f))
(define (obtenerRunPaciente Pacientes) (if (isPaciente? Pacientes) (cadr Pacientes) #f))
(define (obtenerEmailPaciente Pacientes) (if (isPaciente? Pacientes) (caddr Pacientes) #f))
(define (obtenerNombrePaciente Pacientes) (if (isPaciente? Pacientes) (cadddr Pacientes) #f))
(define (obtenerApellidoPaciente Pacientes) (if (isPaciente? Pacientes) (cadddr (cdr Pacientes)) #f))
(define (obtenerFechaNacimientoPaciente Pacientes) (if (isPaciente? Pacientes) (cadddr (cddr Pacientes)) #f ))

;Selectores para el TDA Doctor
(define (obtenerIDDoctor Doctores) (if (isDoctor? Doctores) (car Doctores) #f))
(define (obtenerRunDoctor Doctores) (if (isDoctor? Doctores) (cadr Doctores) #f))
(define (obtenerEmailDoctor Doctores) (if (isDoctor? Doctores) (caddr Doctores) #f))
(define (obtenerNombreDoctor Doctores) (if (isDoctor? Doctores) (cadddr Doctores) #f))
(define (obtenerApellidoDoctor Doctores) (if (isDoctor? Doctores) (cadddr (cdr Doctores)) #f))
(define (obtenerEspecialidadDoctor Doctores) (if (isDoctor? Doctores) (cadddr (cddr Doctores)) #f))

;Selectores para el TDA Diagnostico
(define (obtenerIDDiagnostico Diagnosticos) (if (isDiagnostico? Diagnosticos) (car Diagnosticos) #f))
(define (obtenerDescripcionDiagnostico Diagnosticos) (if (isDiagnostico? Diagnosticos) (cadr Diagnosticos) #f))
(define (obtenerNivelGravedadDiagnostico Diagnosticos) (if (isDiagnostico? Diagnosticos) (caddr Diagnosticos) #f))

;Selectores para el TDA Tratamiento
(define (obtenerIDTratamiento Tratamientos) (if (isTratamiento? Tratamientos) (car Tratamientos) #f))
(define (obtenerNombreTratamiento Tratamientos) (if (isTratamiento? Tratamientos) (cadr Tratamientos) #f))
(define (obtenerDescripcionTratamiento Tratamientos) (if (isTratamiento? Tratamientos) (caddr Tratamientos) #f))
(define (obtenerNivelRiesgoTratamiento Tratamientos) (if (isTratamiento? Tratamientos) (cadddr Tratamientos) #f))

;Selectores para los datos relacionados de Pacientes&Tratamientos
(define (obtenerIDDiagnosticoPaciente DiagnosticosPacientes) (if (isDiagnosticoPaciente? DiagnosticosPacientes) (car DiagnosticosPacientes) #f))
(define (obtenerIdPacienteDiagnosticoPaciente DiagnosticosPacientes) (if (isDiagnosticoPaciente? DiagnosticosPacientes) (cadr DiagnosticosPacientes) #f))
(define (obtenerIdDiagnosticoDiagnosticoPaciente DiagnosticosPacientes) (if (isDiagnosticoPaciente? DiagnosticosPacientes) (caddr DiagnosticosPacientes) #f))
(define (obtenerFechaDiagnosticoDiagnosticoPaciente DiagnosticosPacientes) (if (isDiagnosticoPaciente? DiagnosticosPacientes) (cadddr DiagnosticosPacientes) #f))
(define (obtenerIdDoctorDiagnosticoDiagnosticoPaciente DiagnosticosPacientes) (if (isDiagnosticoPaciente? DiagnosticosPacientes) (cadddr (cdr DiagnosticosPacientes)) #f))
(define (obtenerEstadoDiagnosticoDiagnosticoPaciente DiagnosticosPacientes) (if (isDiagnosticoPaciente? DiagnosticosPacientes) (cadddr (cddr DiagnosticosPacientes)) #f))
(define (obtenerFechaAltaDiagnosticoPaciente DiagnosticosPacientes) (if (isDiagnosticoPaciente? DiagnosticosPacientes) (cadddr (cdddr DiagnosticosPacientes)) #f))
(define (obtenerIdDoctorAltaDiagnosticoPaciente DiagnosticosPacientes) (if (isDiagnosticoPaciente? DiagnosticosPacientes) (cadddr (cdddr (cdr DiagnosticosPacientes))) #f))
(define (obtenerDetalleAltaDiagnosticoPaciente DiagnosticosPacientes) (if (isDiagnosticoPaciente? DiagnosticosPacientes) (cadddr (cdddr (cddr DiagnosticosPacientes))) #f))

;Selectores para los datos relacionados de Tratamientos&Diagnostico
(define (obtenerIdDiagnosticoTratamientoDiagnostico TratamientosDiagnosticos) (if (isTratamientoDiagnostico? TratamientosDiagnosticos) (car TratamientosDiagnosticos) #f))
(define (obtenerIdTratamientoTratamientoDiagnostico TratamientosDiagnosticos) (if (isTratamientoDiagnostico? TratamientosDiagnosticos) (cadr TratamientosDiagnosticos) #f))

;Selectores para los datos relacionados de Tratamientos&Diagnostico&Paciente
(define (obtenerIdDiagnosticoTratamientoDiagnosticoPaciente TratamientosDiagnosticosPac) (if (isTratamientoDiagnosticoPaciente? TratamientosDiagnosticosPac) (car TratamientosDiagnosticosPac) #f))
(define (obtenerIdTratamientoTratamientoDiagnosticoPaciente TratamientosDiagnosticosPac) (if (isTratamientoDiagnosticoPaciente? TratamientosDiagnosticosPac) (cadr TratamientosDiagnosticosPac) #f))
(define (obtenerIdDoctorTratamientoDiagnosticoPaciente TratamientosDiagnosticosPac) (if (isTratamientoDiagnosticoPaciente? TratamientosDiagnosticosPac) (caddr TratamientosDiagnosticosPac) #f))
(define (obtenerFechaInicioTratamientoDiagnosticoPaciente TratamientosDiagnosticosPac) (if (isTratamientoDiagnosticoPaciente? TratamientosDiagnosticosPac) (cadddr TratamientosDiagnosticosPac) #f))
(define (obtenerDuracionDiasTratamientoDiagnosticoPaciente TratamientosDiagnosticosPac) (if (isTratamientoDiagnosticoPaciente? TratamientosDiagnosticosPac) (cadddr (cdr TratamientosDiagnosticosPac)) #f))
(define (obtenerResultadoTratamientoDiagnosticoPaciente TratamientosDiagnosticosPac) (if (isTratamientoDiagnosticoPaciente? TratamientosDiagnosticosPac) (cadddr (cddr TratamientosDiagnosticosPac)) #f))
