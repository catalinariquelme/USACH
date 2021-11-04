#lang racket
(require "TDAUsuario.rkt")
(require "TDAPost.rkt")
(require "TDASocial.rkt")

;Función que encripta desencripta los mensajes e información en el caso que encuentre como primera letra un @
; significará que esta encriptado y que debe ser removido para obtner la información bruta, en el caso contrario
; que no encuentre un @ significará que se deseea encriptar la información
; no supe como implementarlo
(define (decryptUsuarios usuarios)
  (if (null? usuarios)
      null
      (if (equal? "@" (string-ref (get_usuario (car usuarios)) 0))
          (cons (decryptUsuarios (car usuarios)) (decryptUsuarios (cdr usuarios)))
          (decryptUsuarios (cdr usuarios)))))

(provide (all-defined-out))