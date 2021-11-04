#lang racket

;TDA Publicacion
;   Contenido: String
;   Autor: String
;   ID: number
;   TDA Date
;      Día: number
;      Mes: number
;      Año: number
;   Lista usuarios: Strings
;   Like: number

(require "TDADate.rkt")


;---CONSTRUCTOR---
;Descripción: Funcion que construye al TDA post
;Dominio: Recibe el fecha, contenido a publicar y usuarios etiquetadps
;Recorrido: Retorna un aviso si no corresponde los formatos a fecha y/o contenido y/o usuarios o retorna la lista usuario
(define set_publicacion(lambda (contenido autor fecha id . listUser)
                  (if (date? fecha)
                      (if (string? contenido)
                          (if (integer? id)
                              (if(list? listUser)
                                 (list contenido autor fecha id (list listUser) 0)
                                 (raise "No corresponde a usuarios"))
                              (raise "No corresponde a un id"))
                          (raise "No corresponde a un post"))
                      (raise "No corresponde a una fecha"))))

;---PERTENENCIA---
;Funcion que recibe el TDA publicacion
;Verifica si cada parametro de la lista corresponde a la representacion
;Retorna un boleano
(define publicacion? (lambda(publicacion)
                   (if(null? publicacion)
                      #f
                      (if(and(list? publicacion) (= (length publicacion) 5))
                         (if (and (string? (car publicacion))
                                  (string? (cadr publicacion))
                                  (integer? (caddr publicacion))
                                  (date? (cadddr publicacion))
                                  (list? (car(cddddr publicacion)))
                                  (list? (car(cdr(cddddr publicacion))))
                                  (integer? (car (cddr(cddddr publicacion))))
                                         )
                             
                             #t
                             #f)
                         #f))))

;---SELECTORES---
;Funcion que recibe el TDA publicacion
;retornando el contenido de este
(define get_contenido_publicacion(lambda(publicacion)
                           (car publicacion)))

;Funcion que recibe el TDA publicacion
;retornando el autor de este
(define get_autor_publicacion(lambda(publicacion)
                           (cadr publicacion)))

;Funcion que recibe el TDA publicacion
;retornando el id de este
(define get_id_publicacion(lambda(publicacion)
                             (caddr publicacion)))

;Funcion que recibe el TDA publicacion
;retornando la fecha de este
(define get_fecha_publicacion(lambda(publicacion)
                             (car (cdddr publicacion))))

;Funcion que recibe el TDA publicacion
;retornando los etiquetados este
(define get_etiquetados_publicacion(lambda(publicacion)
                             (car(car (cddddr publicacion)))))

;Funcion que recibe el TDA publicacion
;retornando los etiqeutados este
(define get_like_publicacion(lambda(publicacion)
                             (cadr (cddddr publicacion))))

(define (pregunta->string pregunta)
  (if (null? pregunta)
      null
      (string-append  ;"   Autor: " (get_autor_publicacion)                          
                     ;"  " "Fecha: (" (string-join (map number->string (get_fecha_publicacion)) " ") ")"                           
                     ;"  " "ID pregunta: " (number->string (get_id_publicacion)) 
                     ;"  " "Like: " (number->string (get_like_publicacion)) 
                     ;"  " "Etiquetas: " (string-join(get_etiquetados_publicacion pregunta)) "\n" "\n"
                     "   " (get_contenido_publicacion) "\n" "\n" "\n" "\n")              
      )
  )


(provide (all-defined-out))