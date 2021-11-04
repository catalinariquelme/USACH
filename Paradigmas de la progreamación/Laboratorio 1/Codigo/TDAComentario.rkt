
#lang racket

(require "TDADate.rkt")

;TDA Comentario
;   TDA Date
;      Día: number
;      Mes: number
;      Año: number
;   ID: number
;   Contenido: string

;---CONSTRUCTOR ---
;Descripción: Funcion que construye al TDA comentario
;Dominio: Recibe el fecha, id y su contenido
;Recorrido: Retorna un aviso si no corresponde los formatos a fecha y/o id y/o contenido o retorna la lista comentario
(define set_comentario(lambda(fecha id contenido)
                 (if(date? fecha)
                    (if(integer? id)
                       (if(string? contenido)
                          (list fecha id contenido)
                          (raise "El parametro ingresado no corresponde a contenido"))
                       (raise "El parametro ingresado no corresponde a un id"))
                    (raise "El parametro ingresado no corresponde a una fecha"))))

;---PERTENENCIA---
;Funcion que recibe el TDA comentario
;Verifica si cada parametro de la lista corresponde a la representacion
;Retorna un boleano
(define comentario? (lambda(comentario)
                   (if(null? comentario)
                      #f
                      (if(and(list? comentario) (= (length comentario) 3))
                         (if (and (date? (car comentario))
                                  (integer? (cadr comentario))
                                  (string?(caddr comentario))
                                  )
                             #t
                             #f)
                         #f))))
;---SELECTORES---
;Funcion que recibe el TDA comentario,
;retornando la fecha de este
(define get_fecha_comentario(lambda(comentario)
                           (car comentario)))
;Funcion que recibe el TDA comentario,
;retornando el id al cual responde
(define get_id_comentario(lambda(comentario)
                           (car(cdr comentario))))

;Funcion que recibe el TDA comentario,
;retornando contenido de este
(define get_contenido_comentario(lambda(comentario)
                             (car(cddr comentario))))


(provide (all-defined-out))