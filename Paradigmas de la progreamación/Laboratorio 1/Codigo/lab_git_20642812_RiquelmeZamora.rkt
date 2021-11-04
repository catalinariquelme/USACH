#lang racket

(require "TDAUsuario.rkt")
(require "TDAPost.rkt")
(require "TDADate.rkt")
(require "TDASocial.rkt")
(require "Complemento.rkt")
(require "TDAComentario.rkt")

;TDA socialNetwork se representa como una lista que dentro contendra los otros TDAs, tales como usuario y post
;La primera lista de social sera una lista que contendra  los TDAs usuarios, la segunda sera una lista que
;contendra los TDA post y el tercero sera una lista que contendra a los usuarios con sesion activa
;solo con el nombre, ya que no se puede volver a ingresar el mismo nombre para otro usuario

;TDA SocialNetwork
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
;      Like: number
;
;    Sesión activa
;
;    TDA Comentario
;      TDA Date
;         Día: number
;         Mes: number
;         Año: number
;       ID: number
;       Contenido: string

;---CONSTRUCTOR---
;Descripción: Funcion que construye al TDA socialNetwork
;Dominio: no recibe nada
;Recorrido: Retorna una lista que dentro tiene 3 listas las cuales corresponden a la lista para
;los TDA usuario y la lista que contendrá TDA Post
(define socialnetwork(lambda()
                    (list (list ) (list ) (list ) (list ))))

;-----------------------------------Función Register-----------------------------------
;Descripción: función que registra un nuevo usuario en una red social
;Dominio: TDA social x date x string x string (reciabe TDA social, nombre de usuario y su contraseña)
;Recorrido: TDA Social 

(define register (lambda(social fecha user password)                  
                     (cons (registerComplemento(car social) fecha user password) (cdr social))))

;Descripción:función que revisa si el usuario se encuentra previamente registrado
;Dominio: TDA usuarios x date x string x string (recibe el car del social, es decir, la lista de los usuarios, el nombre de usuario y la contraseña)
;Recorrido: TDA Social
;Recursión: lineal
(define registerComplemento(lambda(social fecha user password)
                   (if(null? social)
                      (cons (set_usuario fecha user password '() ) social)
                      (if (equal? (car(car social)) user)
                          social
                          (cons (car social) (registerComplemento (cdr social) fecha user password))))))

;-----------------------------------------------------------------------------------
;-----------------------------------Función Login-----------------------------------
;Descipción: función que permite iniciar sesión a un usuario registrado, y una vez autenticado poder realizar una acción
;Dominio: TDA Social x str x str x function (Recibe TDA Scoial y una funcion (de lo que desea realizar el usuario realizar))
;Recorrido: funcion -> social
(define login(lambda(social user password funcion)
               (if(and(string? user) (string? password))
                 (if(verificarSesion social user password)
                    social
                    (funcion (loginComplemento (get_usuarios social) social user password)))
                 (raise "El parametro ingresado no correspondo al formato"))))


;Descripción: función login en caso de que el usuario no se encuentre registrado
;Dominio: TDA Usuario x TDA Social x str x str
;Recorrido: TDA Social | mensaje no registrado
;Recursión: de cola
(define loginComplemento(lambda(social socialGrande user password)
                   (if(null? social)
                      (raise "No se encuentra registrado")
                      (if(and(equal? (car(car social)) user) (equal? (car(cdr(car social))) password))
                         (list (car socialGrande) (cadr socialGrande) (cons user (caddr socialGrande)))
                         (loginComplemento(cdr social) socialGrande user password)))))


;Descripción: verifica si el usuario ya cuenta con un sesion iniciada dentro social
;Dominio: TDA Social x str x str , el nombre de usuario y contraseña del usuario
;Recorrido: boleano
;Recursión: de cola
(define verificarSesion(lambda(social user password)
                         (if (not(null? (caddr social)))          
                             (if(and(equal? (car (caddr social)) user) (equal? (car(cdr(car(car social)))) password))
                                #t
                                (verificarSesion(list (car social) (cadr social) (cdr(caddr social))) user password))
                             #f)))

;

;----------------------------------------------------------------------------------
;-----------------------------------Función Post-----------------------------------
;Descripción: función que permite dar una ID a las publicaciones
;Dominio: num x TDA social (contador y TDA red social)
;Recorrido: num, número que será el contador
;Recursión de cola
(define mayor(lambda(contador social)
                    (if(null? social)
                       (+ contador 1)
                       (mayor (+ contador 1) (cdr social)))))

;Descripción: función que determina id para publicación
;Dominio: TDA  social
;Recorrido: num
(define ID(lambda(social)
            (mayor 0 social)))

;Descipción: añade a la lista de publicación un post realizado por el usuario
;Dominio: TDA social x date x str x user list
;Recorrido: TDA social modificado con la lista de usuario con sesion iniciada vacio
(define post(lambda(social)
                 (lambda(fecha)
                   (lambda(contenido . listaEtiquetados)
                        (list (car social) (append (list (set_publicacion contenido (get_usuario_activo social) fecha  (ID (cadr social)))) (car(cdr social))) (list ))))))
                         
;------------------------------------------------------------------------------------
;-----------------------------------Función Follow-----------------------------------

;Descripción: función que verfica si el usuario se encuentra en la red (usa recursión)
;Dominio: TDA usuarios x str (usuario a buscar)
;Recorrido: booleano
(define verificarUsuario(lambda(social user)
                     (if(null? social)
                        #f
                        (if(equal?(car (car social)) user)
                           #t
                           (verificarUsuario (cdr social) user)))))

;Descripción: función que permite seguir a otro usuario que se encuentre registrado
;Dominio: TDA social x date x user (usuario a seguir)
;Recorrido: si el usuario no se encuentra reguitrado, retorna mensaje avisando, en caso contrario el retorna social modificado
(define follow (lambda(social)
                     (lambda(fecha)
                       (lambda(user)
                         (if (verificarUsuario (car social) user)
                             (followComplemento (car social) user)
                             (raise "No se encuentra el usuario que desea seguir"))))))

;Descripción: función que modifica los valores de usuario respecto a la lista de seguidos
;Dominio: TDA usuarios x string (user)
;Recorrido: retorna la lista usuario modificada en el usuario correspondiente
(define followComplemento(lambda(social  user)
                           (if(null? social)
                              (list )
                              (if(equal? (car social) user)
                                 (cons (list (car (car social))
                                             (car(cdr (car social)))
                                             (car(cddr (car social)))
                                             (cdddr (car social))
                                             (append (cdddr (car social)) etiquetados)
                                             (cdr(cdddr (car social)))
                                             )
                                       (followComplemento (cdr social)  user))
                                 
                                 (cons (list (car(car social))
                                             (cdr (car social))
                                             (cddr (car social))
                                             (cdddr (car social))
                                             (cdr(cdddr (car social)))
                                             )
                                       (followComplemento (cdr social) user))))))

;-------------------------------------------------------------------------------------
;-----------------------------------Función Comment-----------------------------------

;Descripción: añade un comentario a la lista de comentarios realizados
;Dominio: TDA social x date x num (id de la publicación que responde) x str
;Recorrido: TDA social modificado con la lista de comentarios
(define comment (lambda(social)
                     (lambda(fecha)
                       (lambda(id)
                         (if(verificarID (car(cdr social)) id)
                            (list (car social) (append (list (set_comentario  fecha  id respuesta)) (car(cdddr social))))
                            (raise "No se encuentra el post con ese id que se desea responder")))))))
    
;---------------------------------------------------------------------------------------------------
;-----------------------------------Función like----------------------------------------------------
;Descripción: función que verfica si el id de la publicación se encuentra en la red (usa recursión)
;Dominio: TDA publicaciones x num (id)
;Recorrido: booleano
(define verificarID(lambda(social id)
                     (if(null? social)
                        #f
                        (if(equal?(get_id_publicacion(car social)) id)
                           #t
                           (verificarID (cdr social) id)))))

;Descripción: función que aumenta en uno el valor de los like (publicaciones)
;Dominio: TDA publicacion x num (id) 
;Recorrido: si no se encuentra el id de la publicación, retorna mensaje avisando, en caso contrario el retorna social modificado
(define like (lambda(social)
                     (lambda(id)
                       (if (verificarID (car(cdr social)) id)
                           (likeComplemento (car(cdr social)) id)
                           (raise "No se encuntra un post con esa ID")))))

;Descripción: función que modifica los valores de publicacion respecto a los like
;Dominio: TDA social x id
;Recorrido: retorna la lista publicación modificada con el valor like aumentado en 1
(define likeComplemento(lambda(social id)
                           (if(null? social)
                              (list )
                              (if(equal? (get_id_publicacion(car social)) id)
                                 (cons (list (get_contenido_publicacion(car social))
                                             (get_autor_publicacion(car social))
                                             (get_id_publicacion(car social))
                                             (get_fecha_publicacion(car social))
                                             (get_etiquetados_publicacion(car social))
                                             (+(get_like_publicacion(car social))1)
                                             )
                                       (likeComplemento (cdr social)  id))

                                 (cons (list (get_contenido_publicacion(car social))
                                             (get_autor_publicacion(car social))
                                             (get_id_publicacion(car social))
                                             (get_fecha_publicacion(car social))
                                             (get_etiquetados_publicacion(car social))
                                             (get_like_publicacion(car social))
                                             )
                                       (likeComplemento (cdr social) id))))))

;---------------------------------------------------------------------------------------------------
;-----------------------------------Función socialnetwork->string-----------------------------------

;Descripción: función que cancatena información con finde mostarla de froma legible
;Dominio: TDA social
;Recorrido: social concatenado para mostrar 
(define socialnetwork->string(lambda(social)
                       (if (null? (caddr social))
                           (string-append (stringListaUsuarios (car social)) "\n" (stringListaPosts (car(cdr social))) "\n")
                           (string-append (stringListaUsuarios (car social)) "\n " (stringListaPosts (car(cdr social))) "\n" 
                           "Usuarios con sesion iniciada: " (car(caddr social))))))

;Descripción: función que recibe la lista de usuarios que concatena la información de cada uno para mostrar de forma legible
;Dominio: TDA usuario
;Recorrido: concatenación de los usuarios
;Recursion: lineal
(define stringListaUsuarios (lambda(social)
                              (if(null? social)
                                 " "
                                 (string-append "Usuario: " (car(car social))
                                                "  Contrasena: " (car(cdr(car social))) "\n"
                                                (stringListaUsuarios (cdr social))))))

;Descripción: función que recibe la lista de publicaciones que concatena la informacion de cada uno de los datos del post para mostrar de forma legible
;Dominio: TDA publicación
;Recorrido: concatenación de las preguntas
;Recursion: lineal
(define stringListaPosts(lambda(social)
                              (if(null? social)
                                 " "
                                 (string-append "Publicacion: " (get_contenido_publicacion (car social))
                                                "  Autor: " (car(get_autor_publicacion (car social)))
                                                "  Id: " (number->string (car(get_id_publicacion(car social))))
                                                "  Like: " (number->string (get_like_publicacion (car social)))
                                                "  Etiquetas: " (string-join (car (get_etiquetados_publicacion (car social))))
                                                "\n" "\n"
                                                (stringListaPosts (cdr social))))))

;-------------------------------------------------------------------------------------

;-------------------------------------------------------------------------------------

;//////////////////////////////////////////EJEMPLOS//////////////////////////////////////////
;Para definir socialNetwork se llama a la función socialnetwork
;(define socialVacio (socialnetwork))

;---Función register
;(define social1 (register socialVacio (date 25 3 2020) "user0" "pass0"))
;(define social2 (register socialVacio (date 25 3 2020) "user007" "pass007"))
;(define social (register (register (register socialVacio (date 25 10 2021) "user1" "pass1") (date 25 10 2021) "user2" "pass2") (date 25 10 2021) "user3" "pass3"))
;(display(socialnetwork->string (register (register (register social (date 25 10 2021) "user1" "pass1") (date 25 10 2021) "user2" "pass2") (date 25 10 2021) "user3" "pass3")))

;---Función login + follow
;(define social4 (((login social "user1" "pass1" follow) (date 27 10 2021)) "user2"))
;(define social5 (((login social "user1" "pass1" follow) (date 27 10 2021)) "user3"))
;(define social6 (((login social "user2" "pass2" follow) (date 27 10 2021)) "user3"))
;(display(socialnetwork->string (((login social "user1" "pass1" follow) (date 27 10 2021)) "user2")))

;---Función login + post
;(define social7 (((login social "user3" "pass3" post) (date 28 10 2021)) "7th post"))
;(define social8 (((login social "user3" "pass3" post) (date 28 10 2021)) "8th post"))
;(define social9 (((login social "user3" "pass3" post) (date 28 10 2021)) "9th post" "user1"))
;(define social10 (((login social "user1" "pass1" post) (date 28 10 2021)) "10th post "user2" "user3"))
;(display(socialnetwork->string(((login social "user3" "pass3" post) (date 28 10 2021)) "7th post")))

;---Función login + like
;(define social11 (((login social "user3" "pass3" like) (date 29 10 2021)) 3))
;(define social12 (((login social "user1" "pass1" like) (date 29 10 2021)) 0))
;(define social13 (((login social "user2" "pass2" like) (date 29 10 2021)) 1))
;(display(socialnetwork->string(((login social "user1" "pass1" like) (date 29 10 2021)) 5)))

;---Función login + comment

;(define social14 ((((login social "user1" "pass1" comment) (date 29 10 2021)) 3) "11th comment"))
;(define social15 ((((login social "user3" "pass3" comment) (date 29 10 2021)) 0) "12th comment"))
;(define social16 ((((login social "user3" "pass3" comment) (date 29 10 2021)) 0) "13th comment"))


