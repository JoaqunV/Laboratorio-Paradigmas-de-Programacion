#lang racket
;Constructor paciente
(define (createPaciente Id run email nombre apellido fechaNac) (if (and (integer? Id) (string? run) (string? email) (string? nombre) (string? apellido) (string? fechaNac)) (list (number->string Id) run email nombre apellido fechaNac) null))
;Constructor Doctor
(define(createDoctor Id run email nombre apellido especialidad) (if (and (integer? Id) (string? run) (string? email) (string? nombre) (string? apellido) (string? especialidad)) (list (number->string Id) run email nombre apellido especialidad) null))
;constructor Diagnostico
(define(createDiagnostico Id descripcionDiagnostico nivelGravedad) (if (and (integer? Id) (string? descripcionDiagnostico) (string? nivelGravedad)) (list (number->string Id) descripcionDiagnostico nivelGravedad) null))
;Constructor Tratamiento
(define(createTratamiento Id nombreTratamiento descripcionTratamiento nivelDeRiesgo) (if (and (integer? Id) (string? nombreTratamiento) (string? descripcionTratamiento) (string? nivelDeRiesgo)) (list (number->string Id) nombreTratamiento descripcionTratamiento nivelDeRiesgo) null))
;Constructor DiagnosticoPaciente
(define(createDiagnosticoPaciente idDiagnosticoPaciente idPaciente idDiagnostico fechaDiagnostico idDoctorDiagnostico estadoDiagnostico fechaAlta idDoctorAlta detalleAlta) (if (and (integer? idDiagnosticoPaciente) (integer? idPaciente) (integer? idDiagnostico) (string? fechaDiagnostico) (integer? idDoctorDiagnostico) (string? estadoDiagnostico) (string? fechaAlta) (integer? idDoctorAlta) (string? detalleAlta)) (list (number->string idDiagnosticoPaciente) (number->string idPaciente) (number->string idDiagnostico) fechaDiagnostico (number->string idDoctorDiagnostico) estadoDiagnostico fechaAlta (number->string idDoctorAlta) detalleAlta) null))
;Constructor TratamientoDiagnostico
(define(createTratamientoDiagnostico idDiagnostico idTratamiento) (if (and (integer? idDiagnostico) (integer? idTratamiento)) (list (number->string idDiagnostico) (number->string idTratamiento)) null))
;ConstructorTratamientoDiagnosticoPaciente
(define(createTratamientoDiagnosticoPaciente Id idTratamiento idDoctor fechaInicio duracionDias resultado) (if (and (integer? Id) (integer? idTratamiento) (integer? idDoctor) (string? fechaInicio) (integer? duracionDias) (string? resultado)) (list (number->string Id) (number->string idTratamiento) (number->string idDoctor) fechaInicio (number->string duracionDias) resultado) null))
