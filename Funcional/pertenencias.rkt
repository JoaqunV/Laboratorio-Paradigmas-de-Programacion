#lang racket
;Función de pertenencia para Pacientes
(define (isPaciente? Pacientes) (and (list? Pacientes) (= (length Pacientes) 6) (not (equal? (string->number (car Pacientes)) #f)) (string? (cadr Pacientes)) (string? (caddr Pacientes)) (string? (cadddr Pacientes)) (string? (cadddr (cdr Pacientes))) (string? (cadddr (cddr Pacientes)))))
;Función de pertenencia para Doctores
(define (isDoctor? Doctores)(and (list? Doctores) (= (length Doctores) 6) (not (equal? (string->number (car Doctores)) #f)) (string? (cadr Doctores)) (string? (caddr Doctores)) (string? (cadddr Doctores)) (string? (cadddr (cdr Doctores))) (string? (cadddr (cddr Doctores)))))
;Función de pertenencia para Diagnosticos
(define (isDiagnostico? Diagnosticos) (and (list? Diagnosticos) (= (length Diagnosticos) 3) (not (equal? (string->number (car Diagnosticos)) #f)) (string? (cadr Diagnosticos)) (not (equal? (string->number (caddr Diagnosticos)) #f)) ))
;Función de pertenencia para Tratamientos
(define (isTratamiento? Tratamientos) (and (list? Tratamientos) (= (length Tratamientos) 4) (not (equal? (string->number (car Tratamientos)) #f)) (string? (cadr Tratamientos)) (string? (caddr Tratamientos)) (string? (cadddr Tratamientos))))
;Función de pertenencia para DiagnosticosPacientes
(define (isDiagnosticoPaciente? DiagnosticosPacientes) (and (list? DiagnosticosPacientes) (= (length DiagnosticosPacientes) 9) (not (equal? (string->number (car DiagnosticosPacientes)) #f)) (not (equal? (string->number (cadr DiagnosticosPacientes)) #f)) (not (equal? (string->number (caddr DiagnosticosPacientes)) #f)) (string? (cadddr DiagnosticosPacientes)) (not (equal? (string->number (cadddr (cdr DiagnosticosPacientes))) #f)) (string? (cadddr (cddr DiagnosticosPacientes))) (string? (cadddr (cdddr DiagnosticosPacientes))) (not (equal? (string->number (cadddr (cdddr (cdr DiagnosticosPacientes)))) #f)) (string? (cadddr (cdddr (cddr DiagnosticosPacientes))))))
;Función de pertenencia para TratamientosDiagnosticos
(define (isTratamientoDiagnostico? TratamientosDiagnosticos) (and (list? TratamientosDiagnosticos) (= (length TratamientosDiagnosticos) 2) (not (equal? (string->number (car TratamientosDiagnosticos)) #f)) (not (equal? (string->number (cadr TratamientosDiagnosticos)) #f)) ))
;Función de pertenencia para TratamientosDiagnosticosPac
(define (isTratamientoDiagnosticoPaciente? TratamientosDiagnosticosPac) (and (list? TratamientosDiagnosticosPac) (= (length TratamientosDiagnosticosPac) 6) (not (equal? (string->number (car TratamientosDiagnosticosPac)) #f)) (not (equal? (string->number (cadr TratamientosDiagnosticosPac)) #f)) (not (equal? (string->number (caddr TratamientosDiagnosticosPac)) #f)) (string? (cadddr TratamientosDiagnosticosPac)) (not (equal? (string->number (cadddr (cdr TratamientosDiagnosticosPac))) #f)) (string? (cadddr (cddr TratamientosDiagnosticosPac))) ))
