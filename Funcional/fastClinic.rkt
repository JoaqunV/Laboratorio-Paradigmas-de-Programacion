#lang racket
;
; SOFTWARE DE GESTIÓN FASTCLINIC 
;
; AUTOR: JOAQUÍN IGNACIO VILLAGRA PACHECO
; ESTUDIANTE INGENIERÍA CIVIL INFORMÁTICA
; UNIVERSIDAD DE SANTIAGO DE CHILE
; ASIGNATURA RELACIONADA: LABORATORIO PARADIGMAS DE PROGRAMACIÓN 
; FECHA: 17/10/2014


;importo Biblioteca necesaria para leer archivos de texto en formato csv (separados por comas).
(require (planet neil/csv:2:0))
(require "selectores.rkt")
(require "pertenencias.rkt")
(require "constructores.rkt")
(require "modificadores.rkt")

;Se definen las diversas listas, contenedoras de los datos de la clinica (contenido de archivos o "BD"). 
(define Doctores (csv->list (open-input-file "Doctor.txt")))
(define Pacientes (csv->list (open-input-file "Paciente.txt")))
(define Tratamientos (csv->list (open-input-file "Tratamiento.txt")))
(define Diagnosticos (csv->list (open-input-file "Diagnostico.txt")))
(define DiagnosticosPacientes (csv->list (open-input-file "DiagnosticoPaciente.txt")))
(define TratamientosDiagnosticos (csv->list (open-input-file "TratamientoDiagnostico.txt")))
(define TratamientosDiagnosticosPac (csv->list (open-input-file "TratamientoDiagnosticoPaciente.txt")))

;Cierro puertos de lectura de archivos
(close-input-port Doctores)
(close-input-port Pacientes)
(close-input-port Diagnosticos)
(close-input-port Tratamientos)
(close-input-port DiagnosticosPacientes)
(close-input-port TratamientosDiagnosticos)
(close-input-port TratamientosDiagnosticosPac)

;Carga de funciones de pertenencia desde archivo pertenencias.rkt
(provide isPaciente?)
(provide isDoctor?)
(provide isDiagnostico?)
(provide isTratamiento?)
(provide isDiagnosticoPaciente?)
(provide isTratamientoDiagnostico?)
(provide isTratamientoDiagnosticoPaciente?)

;Carga de funciones contructores desde archivo contructores.rkt
(provide createDoctor)
(provide createPaciente)
(provide createDiagnostico)
(provide createTratamiento)
(provide createDiagnosticoPaciente)
(provide createTratamientoDiagnostico)
(provide createTratamientoDiagnosticoPaciente)

;Carga funciones modificadores desde archivo modificadores.rkt
(provide modificaIDPaciente)
(provide modificaRunPaciente)
(provide modificaEmailPaciente)
(provide modificaNombrePaciente)
(provide modificaApellidoPaciente)
(provide modificaFechaNacimientoPaciente)
(provide modificaIDDoctor)
(provide modificaEmailDoctor)
(provide modificaNombreDoctor)
(provide modificaApellidoDoctor)
(provide modificaEspecialidadDoctor)
(provide modificaIDDiagnostico)
(provide modificaDescripcionDiagnostico)
(provide modificaNivelGravedadDiagnostico)
(provide modificaIDTratamiento)
(provide modificaNombreTratamiento)
(provide modificadescripcionTratamiento)
(provide modificaNivelRiesgoTratamiento)
(provide modificaIDDiagnosticoPaciente)
(provide modificaIdPacienteDiagnosticoPaciente)
(provide modificaIdDiagnosticoDiagnosticoPaciente)
(provide modificaFechaDiagnosticoDiagnosticoPaciente)
(provide modificaIdDoctorDiagnosticoPaciente)
(provide modificaEstadoDiagnosticoDiagnosticoPaciente)
(provide modificaFechaAltaDiagnosticoPaciente)
(provide modificaIdDoctorAltaDiagnosticoDiagnosticoPaciente)
(provide modificaDetalleAltaDiagnosticoPaciente)
(provide modificaIdDiagnosticoTratamientoDiagnostico)
(provide modificaIdTratamientoTratamientoDiagnostico)
(provide modificaIDTratamientoDiagnosticoPaciente)
(provide modificaIDTratamientoTratamietoDiagnosticoPaciente)
(provide modificaIdDoctorTratamientoDiagnosticoPaciente)
(provide modificaFechaInicioTratamientoDiagnosticoPaciente)
(provide modificaDuracionDiasTratamientoDiagnosticoPaciente)
(provide modificaResultadoTratamientoDiagnosticoPaciente)

;Carga de funciones de seleccion desde selectores.rkt
(provide obtenerIDPaciente)
(provide obtenerRunPaciente)
(provide obtenerEmailPaciente)
(provide obtenerNombrePaciente)
(provide obtenerApellidoPaciente)
(provide obtenerFechaNacimientoPaciente)
(provide obtenerIDDoctor)
(provide obtenerRunDoctor)
(provide obtenerEmailDoctor)
(provide obtenerNombreDoctor)
(provide obtenerApellidoDoctor)
(provide obtenerEspecialidadDoctor)
(provide obtenerIDDiagnostico)
(provide obtenerDescripcionDiagnostico)
(provide obtenerNivelGravedadDiagnostico)
(provide obtenerIDTratamiento)
(provide obtenerNombreTratamiento)
(provide obtenerDescripcionTratamiento)
(provide obtenerNivelRiesgoTratamiento)
(provide obtenerIDDiagnosticoPaciente)
(provide obtenerIdPacienteDiagnosticoPaciente)
(provide obtenerIdDiagnosticoDiagnosticoPaciente)
(provide obtenerFechaDiagnosticoDiagnosticoPaciente)
(provide obtenerIdDoctorDiagnosticoDiagnosticoPaciente)
(provide obtenerEstadoDiagnosticoDiagnosticoPaciente)
(provide obtenerFechaAltaDiagnosticoPaciente)
(provide obtenerIdDoctorAltaDiagnosticoPaciente)
(provide obtenerDetalleAltaDiagnosticoPaciente)
(provide obtenerIdDiagnosticoTratamientoDiagnostico)
(provide obtenerIdTratamientoTratamientoDiagnostico)
(provide obtenerIdDiagnosticoTratamientoDiagnosticoPaciente)
(provide obtenerIdTratamientoTratamientoDiagnosticoPaciente)
(provide obtenerIdDoctorTratamientoDiagnosticoPaciente)
(provide obtenerFechaInicioTratamientoDiagnosticoPaciente)
(provide obtenerDuracionDiasTratamientoDiagnosticoPaciente)
(provide obtenerResultadoTratamientoDiagnosticoPaciente)

;FUNCIONES DE SELECCIÓN BASICAS

;Función que obtiene el nombre de un paciente a partir de su run.
(define (obtenerNombrePaciente run) (define obtenerPaciente(lambda (run Pacientes)(if (null? Pacientes) #f (if (equal? (obtenerRunPaciente(car Pacientes)) run) #t (obtenerPaciente run (cdr Pacientes)))))) (if (list? Pacientes) (obtenerPaciente run Pacientes) #f ))

;Función que obtiene la especialidad de un medico a partir de su run.
(define (especialidad run) (define obtenerDoctor(lambda (run Doctores)(if (null? Doctores) (void) (if (equal? (obtenerRunDoctor(car Doctores)) run) (obtenerEspecialidadDoctor(car Doctores)) (obtenerDoctor run (cdr Doctores)))))) (if (list? Pacientes) (obtenerDoctor run Doctores) (void)))

;Función que indica los tratamientos que cumplen con un cierto nivel de riesgo especificado.
(define (tratamientoRiesgoso nivelRiesgo) (define obtenerTratamiento(lambda (nivelRiesgo Tratamientos) (if (null? Tratamientos) (void) (if (equal? (obtenerNivelRiesgoTratamiento(car Tratamientos)) nivelRiesgo) (begin (display (obtenerNombreTratamiento(car Tratamientos)))(newline) (obtenerTratamiento nivelRiesgo (cdr Tratamientos))) (obtenerTratamiento nivelRiesgo (cdr Tratamientos)))))) (if (list? Tratamientos) (obtenerTratamiento nivelRiesgo Tratamientos) (void)))

;Función que obtiene la cantidad de medicos que han brindado un determinado tratamiento
(define (cantidadMedicosTratamiento idTratamiento) (define comprobarDiferencia(lambda (medicos idPaciente) (if (null? medicos) #t (if (equal? (car medicos) idPaciente) #f (comprobarDiferencia (cdr medicos) idPaciente))))) (define obtenerCantidad(lambda (idTratamiento TratamientosDiagnosticosPac medicos) (if (null? TratamientosDiagnosticosPac) (display (length medicos)) (cond [(and (equal? (obtenerIdTratamientoTratamientoDiagnosticoPaciente(car TratamientosDiagnosticosPac)) (number->string idTratamiento)) (comprobarDiferencia medicos (obtenerIdDoctorTratamientoDiagnosticoPaciente (car TratamientosDiagnosticosPac)))) (obtenerCantidad idTratamiento (cdr TratamientosDiagnosticosPac) (cons  (obtenerIdDoctorTratamientoDiagnosticoPaciente (car TratamientosDiagnosticosPac) )  medicos))] (else (obtenerCantidad idTratamiento (cdr TratamientosDiagnosticosPac) medicos)))))) (if (list? TratamientosDiagnosticosPac) (obtenerCantidad idTratamiento TratamientosDiagnosticosPac empty) (void)))

;Función que obtiene la cantidad de paciente que posee un medico.
(define (cantidadPacientesMedico  idDoctor) (define comprobarDiferencia(lambda (pacientes idPaciente) (if (null? pacientes) #t (if (equal? (car pacientes) idPaciente) #f (comprobarDiferencia (cdr pacientes) idPaciente)))))(define obtenerCantidad(lambda  (idDoctor DiagnosticosPacientes pacientes) (if (null? DiagnosticosPacientes) (display (length pacientes)) (cond [(and (or (equal? (obtenerIdDoctorDiagnosticoDiagnosticoPaciente(car DiagnosticosPacientes)) (number->string idDoctor)) (equal? (obtenerIdDoctorAltaDiagnosticoPaciente(car DiagnosticosPacientes)) (number->string idDoctor))) (comprobarDiferencia pacientes (obtenerIdPacienteDiagnosticoPaciente (car DiagnosticosPacientes)))) (obtenerCantidad idDoctor (cdr DiagnosticosPacientes) (cons  (obtenerIdPacienteDiagnosticoPaciente (car DiagnosticosPacientes) )  pacientes))] (else (obtenerCantidad idDoctor (cdr DiagnosticosPacientes) pacientes)))))) (if (list? DiagnosticosPacientes) (obtenerCantidad idDoctor DiagnosticosPacientes empty) (void)))

;Función que obtiene el tratamiento más usado por un diagnostico indicado.
(define (tratamientoMasUsadoPorDiagnostico  idDiagnostico) (define contarYagregar(lambda (cantidad idTratamiento idDiagnostico TratamientosDiagnosticos cont) (if (null? TratamientosDiagnosticos)(cons (list idTratamiento cont) cantidad) (if (and (equal? (obtenerIdTratamientoTratamientoDiagnostico (car TratamientosDiagnosticos)) idTratamiento) (equal? (obtenerIdDiagnosticoTratamientoDiagnostico (car TratamientosDiagnosticos)) idDiagnostico)) (contarYagregar cantidad idTratamiento idDiagnostico (cdr TratamientosDiagnosticos) (+ cont 1)) (contarYagregar cantidad idTratamiento idDiagnostico (cdr TratamientosDiagnosticos) cont))))) (define comprobarDiferencia(lambda (cantidad idTratamiento) (if (null? cantidad) #t (if (equal? (list-ref (car cantidad) 0) idTratamiento) #f (comprobarDiferencia (cdr cantidad) idTratamiento))))) (define mayor(lambda (cantidad valor) (if (null? cantidad) valor (if (> (list-ref (car cantidad) 1) valor) (mayor (cdr cantidad) (list-ref (car cantidad) 1)) (mayor (cdr cantidad) valor))))) (define nombreTratamiento(lambda (cantidad tratamiento mayor) (if (null? cantidad) null (if (and (equal? (list-ref (car cantidad) 1) mayor) (equal? (obtenerIDTratamiento tratamiento) (list-ref (car cantidad) 0))) (obtenerNombreTratamiento tratamiento) (nombreTratamiento (cdr cantidad) tratamiento mayor))))) (define Mostrar(lambda  (cantidad mayor Tratamientos) (if (null? Tratamientos) (void) (cond [(not (null? (nombreTratamiento cantidad (car Tratamientos) mayor))) (display (nombreTratamiento cantidad (car Tratamientos) mayor)) (display ",") (display (number->string mayor)) (display "\n") (Mostrar cantidad mayor (cdr Tratamientos))] (else (Mostrar cantidad mayor (cdr Tratamientos))))))) (define obtenerCantidad(lambda  (idDiagnostico TratamientosDiagnosticos cantidad) (if (null? TratamientosDiagnosticos)(Mostrar cantidad (mayor cantidad 0) Tratamientos) (cond [(and (equal? (obtenerIdDiagnosticoTratamientoDiagnostico (car TratamientosDiagnosticos)) (number->string idDiagnostico)) (comprobarDiferencia cantidad (obtenerIdTratamientoTratamientoDiagnostico (car TratamientosDiagnosticos)))) (obtenerCantidad idDiagnostico (cdr TratamientosDiagnosticos) (contarYagregar cantidad (obtenerIdTratamientoTratamientoDiagnostico (car TratamientosDiagnosticos)) (number->string idDiagnostico) TratamientosDiagnosticos 0))] (else (obtenerCantidad idDiagnostico (cdr TratamientosDiagnosticos) cantidad)))))) (if (list? TratamientosDiagnosticos) (obtenerCantidad idDiagnostico TratamientosDiagnosticos empty) (void)))
 
;Función que obtiene el medico que ha dado más altas. 
(define (medicoMasAltas) (define contarYagregar(lambda (cantidad idMedico DiagnosticosPacientes cont) (if (null? DiagnosticosPacientes) (cons (list idMedico cont) cantidad) (if (equal? (obtenerIdDoctorAltaDiagnosticoPaciente (car DiagnosticosPacientes)) idMedico) (contarYagregar cantidad idMedico (cdr DiagnosticosPacientes) (+ cont 1)) (contarYagregar cantidad idMedico (cdr DiagnosticosPacientes) cont))))) (define comprobarDiferencia(lambda (cantidad idTratamiento) (if (null? cantidad) #t (if (equal? (list-ref (car cantidad) 0) idTratamiento) #f (comprobarDiferencia (cdr cantidad) idTratamiento))))) (define mayor(lambda (cantidad valor) (if (null? cantidad) valor (if (> (list-ref (car cantidad) 1) valor) (mayor (cdr cantidad) (list-ref (car cantidad) 1)) (mayor (cdr cantidad) valor))))) (define nombreMedico(lambda (cantidad medico mayor) (if (null? cantidad) null (if (and (equal? (list-ref (car cantidad) 1) mayor) (equal? (obtenerIDDoctor medico) (list-ref (car cantidad) 0))) medico (nombreMedico (cdr cantidad) medico mayor))))) (define Mostrar(lambda  (cantidad mayor Doctores) (if (null? Doctores) (void) (cond [(not (null? (nombreMedico cantidad (car Doctores) mayor))) (display (obtenerRunDoctor (nombreMedico cantidad (car Doctores) mayor))) (display ",") (display (obtenerNombreDoctor (nombreMedico cantidad (car Doctores) mayor))) (display (obtenerApellidoDoctor (nombreMedico cantidad (car Doctores) mayor))) (display ",") (display (number->string mayor)) (display "\n") (Mostrar cantidad mayor (cdr Doctores))] (else (Mostrar cantidad mayor (cdr Doctores))))))) (define obtenerCantidad(lambda  (DiagnosticosPacientes cantidad) (if (null? DiagnosticosPacientes) (Mostrar cantidad (mayor cantidad 0) Doctores) (cond [(and (obtenerIdDoctorAltaDiagnosticoPaciente (car DiagnosticosPacientes)) (comprobarDiferencia cantidad (obtenerIdDoctorAltaDiagnosticoPaciente (car DiagnosticosPacientes)))) (obtenerCantidad (cdr DiagnosticosPacientes) (contarYagregar cantidad (obtenerIdDoctorAltaDiagnosticoPaciente (car DiagnosticosPacientes)) DiagnosticosPacientes 0))] (else (obtenerCantidad (cdr DiagnosticosPacientes) cantidad)))))) (if (list? DiagnosticosPacientes) (obtenerCantidad DiagnosticosPacientes empty) (void)))


