#lang racket

;TDA Date
;   Dia: number
;   Mes: number
;   Año: number

;Ejemplo:
;(define date1(date 25 10 2021))

(provide date)
(provide date?)
(provide date->dia)
(provide date->mes)
(provide date->ano)

;---CONSTRUCTOR ---
;Descripción: Funcion que construye al TDA usuario
;Dominio: Recibe el nombre y su contrasena
;Recorrido: Retorna un aviso si no corresponde los formatos a usuario y/o contraseña o retorna la lista usuario
(define date(lambda(dia mes ano)
                 (if(number? dia)
                    (if(number? mes)
                       (if(number? ano)
                          (list dia mes ano)
                          (raise "El parametro ingresado no corresponde un numero"))
                       (raise "El parametro ingresado no corresponde a un numero"))
                    (raise "El parametro ingresado no corresponde a un numero"))))


;---PERTENENCIA---
;Funcion que recibe el TDA usuario
;Verifica si cada parametro de la lista corresponde a la representacion
;Retorna un boleano
(define date? (lambda(date)
                   (if(null? date)
                      #f
                      (if(and(list? date) (= (length date) 3))
                         (if (and (number? (car date))
                                  (number? (cadr date))
                                  (number? (caddr date)))
                             #t
                             #f)
                         #f))))

;---SELECTORES---
;Funcion que recibe el TDA date,
;retornando el día de este
(define date->dia(lambda(date)
                           (car date)))
;Funcion que recibe el TDA date,
;retornando el mes de este
(define date->mes(lambda(date)
                           (cadr date)))

;Funcion que recibe el TDA date,
;retornando el añoa de este
(define date->ano(lambda(date)
                             (caddr date)))
