#lang racket
(require "TDAUsuario.rkt")
(require "TDAPost.rkt")
(require "TDADate.rkt")
(require "TDAComentario.rkt")


;TDA socialNetwork se representa como una lista que dentro contendra los otros TDAs, tales como usuario y post
;La primera lista del social sera una lista que contendra  los TDAs usuarios, la segunda sera una lista que
;contendra los TDA post y el tercero sera una lista que contendra a los usuarios con sesion activa
;solo con el nombre, ya que no se puede volver a ingresar el mismo nombre para otro usuario

;TDA SocialNetwork (stack)
;   TDA Usuario
;      Username: string
;      Password: string
;      TDA Date
;         Día: number
;         Mes: number
;         Año: number
;      Lista id publicaciones: number
;      Lista conctactos: strings
;
;   TDA Publicacion
;      Contenido: string
;      Autor: string
;      ID: number
;      TDA Date
;         Día: number
;         Mes: number
;         Año: number
;      Lista usuarios etiquetados: strings
;
;   Sesión activa
;
;    TDA Comentario
;      TDA Date
;         Día: number
;         Mes: number
;         Año: number
;       ID: number
;       Contenido: string


;---CONSTRUCTOR---
;Descripción: Funcion que construye al TDA social
;Dominio: Recibe usuarios, publicaciones, usuario activo y comentarios
;Recorrido: retorna lista social
(define (set_social usuarios publicaciones usuarioActivo comentarios)
  (if (and (usuarios? usuarios) (publicaciones? publicaciones) (usuarioActivo? usuarioActivo) (comentarios? comentarios))
      (list usuarios publicaciones usuarioActivo comentarios)
      null))

;---PERTENENCIA---
;Funcion que recibe usuarios
;Verifica si cada parametro de la lista corresponde a la representacion
;Retorna un boleano
(define usuarios? (lambda (usuarios)
                    (if (null? usuarios)
                        #t
                        (if (usuario? (car usuarios))
                            (usuarios? (cdr usuarios))
                            #f))))

;Funcion que recibe publicaciones
;Verifica si cada parametro de la lista corresponde a la representacion
;Retorna un boleano
(define publicaciones? (lambda(publicaciones)
                     (if (null? publicaciones)
                         #t
                         (if (publicacion? (car publicaciones))
                             (publicaciones? (cdr publicaciones))
                             #f))))

;Funcion que recibe usuario activo
;Verifica si cada parametro de la lista corresponde a la representacion
;Retorna un boleano
(define usuarioActivo? (lambda (usuarioActivo)
                         (if (null? usuarioActivo)
                             #t
                             (if (usuario? (car usuarioActivo))
                                 #t
                                 #f))))

;Funcion que recibe comentarios
;Verifica si cada parametro de la lista corresponde a la representacion
;Retorna un boleano
(define comentarios? (lambda(comentarios)
                     (if (null? comentarios)
                         #t
                         (if (comentario? (car comentarios))
                             (comentarios? (cdr comentarios))
                             #f))))

;Funcion que recibe social
;Verifica si cada parametro de la lista corresponde a la representacion
;Retorna un boleano
(define social? (lambda (social)
                 (if (and (usuarios? (get_usuarios social)) (publicaciones? (get_publicaciones social)) (usuarioActivo? (get_usuario_activo social)))
                     #t
                     #f)))



;---SELECTORES---

;Funcion que recibe el TDA social
;retornando usuarios de este
(define get_usuarios (lambda (social)
                            (car social)))

;Funcion que recibe el TDA social
;retornando publicaciones de este
(define get_publicaciones (lambda (social)
                            (car(cdr social))))

;Funcion que recibe el TDA social
;retornando usuario activo de este
(define get_usuario_activo (lambda (social)
                            (car(cddr social))))

;Funcion que recibe el TDA social
;retornando comentarios activo de este
(define get_comentarios (lambda (social)
                            (car(cdddr social))))

(provide (all-defined-out))