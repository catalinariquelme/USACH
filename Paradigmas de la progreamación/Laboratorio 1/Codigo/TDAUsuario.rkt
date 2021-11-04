#lang racket

(require "TDADate.rkt")

;TDA Usuario
;   Username: string
;   Password: string
;   TDA Date
;      Dia: number
;      Mes: number
;      Año: number
;   Lista id publicaciones: numbers
;   Lista contactos: string


;---CONSTRUCTOR ---
;Descripción: Funcion que construye al TDA usuario
;Dominio: Recibe el fecha, nombre y su contrasena
;Recorrido: Retorna un aviso si no corresponde los formatos a fecha y/o usuario y/o contraseña o retorna la lista usuario
(define set_usuario(lambda(fecha usuario contrasena id_pregunta . listContactos)
                 (if(date? fecha)
                    (if(string? usuario)
                       (if(string? contrasena)
                          (if(list? listContactos)
                             (list usuario contrasena fecha id_pregunta listContactos)
                             (raise "El parametro ingresado no corresponde a usuarios"))
                          (raise "El parametro ingresado no corresponde a una contraseña"))
                       (raise "El parametro ingresado no corresponde a un usuario"))
                    (raise "El parametro ingresado no corresponde a una fecha"))))



;---PERTENENCIA---
;Funcion que recibe el TDA usuario
;Verifica si cada parametro de la lista corresponde a la representacion
;Retorna un boleano
(define usuario? (lambda(usuario)
                   (if(null? usuario)
                      #f
                      (if(and(list? usuario) (= (length usuario) 4))
                         (if (and (date? (car usuario))
                                  (string? (cadr usuario))
                                  (string? (caddr usuario))
                                  (list? (cadddr usuario)))
                             #t
                             #f)
                         #f))))


;---SELECTORES---
;Funcion que recibe el TDA usuario,
;retornando la fecha de este
(define get_usuario(lambda(usuario)
                           (car usuario)))
;Funcion que recibe el TDA usuario,
;retornando el nombre de este
(define get_contrasena(lambda(usuario)
                           (car(cdr usuario))))

;Funcion que recibe el TDA usuario,
;retornando la contrasena de este
(define get_fecha_usuario(lambda(usuario)
                             (car(cddr usuario))))

;Funcion que recibe el TDA usuario,
;retornando lista id publicaciones
(define get_id_publicaciones_usuario(lambda(usuario)
                             (car(cdddr usuario))))

;Funcion que recibe el TDA usuario,
;retornando lista de contactos
(define get_lista_contactos(lambda(usuario)
                             (cddddr usuario)))


(provide (all-defined-out))
