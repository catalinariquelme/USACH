/*
Catalina Riquelme Zamora
catalina.riquelme.z@usach.cl
20.642.812-0
*/

/* ---------------Representacion---------------
Tanto user como password seran representadas por listas
USER
    name
    password
    date_user
    [id_post_user]
    [follow]    
    [id_feed]
    [id_comment_user]

POST
    id_post
    content_post
    author_post
    date_post
    like_post
    [id_comment_post]    

COMMENT
    id_comment
    content_comment
    author_comment
    date_comment
    like_comment

Mientras que socialNetowek sera representado como una lista
SOCIALNETWORK
    [USER]
    [POST]
    [COMMENT]
    [ACTIVE_USER]

*/

/* DOMINIOS
---------------USER---------------
Name = str
Password = str
Date_user = list (int)
Id_post_user = list (int)
Follower = list (str)
Id_feed = list (int)
Id_comment_user = list (int)

---------------POST---------------
Id_post = int
Content_post = str
Author_post = str
Date_post = list (int)
Like_post = int
Id_comment_post = list (int)

---------------COMMENT------------
Id_comment = int
Content_comment = str
Author_comment = str
Date_comment = list (int)
Like_comment = int

---------SOCIALNETWORK------------
User = list (User)
Post = list (Post)
Comment = list (Comment)
Active_user = list (User)

---------------DATE---------------
Day = int
Month = int
Year = int
*/

/* PREDICADOS
---------------CONSTRUCTORES---------------
set_user(Name,Password,Date_user,Id_post_user,Follow,Id_feed,Id_comment_user,Generated_user)
set_post(Id_post,Content_post,Author_post,Date_post,Like_post,Id_comment_post,New_post)
set_comment(Id_comment,Content_comment,Author_comment,Date_comment,Like_comment,New_comment)
set_social([Users,Posts,Comments,Active_user], New_social)

------------------SELECTORES---------------
||| [User] |||
get_name([Name|T],Name_s)
get_password([Name|[Password|T]],Password_s)
get_date_user([Name|[Password|[Date_user|T]]],Date_user_s)
get_id_post_user([Name|[Password|[Date_user|[Id_post_user|T]]]],Id_post_user_s)
get_follow([Name|[Password|[Date_user|[Id_post_user|[Follow|T]]]]],Follow_s)
get_id_feed([Name|[Password|[Date_user|[Id_post_user|[Follow|[Id_feed|T]]]]]],Id_feed_s)
get_id_comment_user([Name|[Password|[Date_user|[Id_post_user|[Follow|[Id_feed|[Id_comment_user|T]]]]]]],Id_comment_user_s)

||| [Post] |||
get_id_post([Id_post|T],Id_post_s):
get_content_post([Id_post|[Content_post|T]],Content_post_s)
get_author_post([Id_post|[Content_post|[Author_post|T]]],Author_post_s):
get_date_post([Id_post|[Content_post|[Author_post|[Date_post|T]]]],Date_post_s)
get_like_post([Id_post|[Content_post|[Author_post|[Date_post|[Like_post|T]]]]],Like_post_s)
get_id_comment_post([Id_post|[Content_post|[Author_post|[Date_post|[Like_post|[Id_comment_post|T]]]]]],Id_comment_post_s)

||| [COMMENT] |||
get_id_comment([Id_comment|T],Id_comment_s)
get_content_comment([Id_comment|[Content_comment|T]],Content_comment_s)
get_author_comment([Id_comment|[Content_comment|[Author_comment|T]]],Author_comment_s)
get_date_comment([Id_comment|[Content_comment|[Author_comment|[Date_comment|T]]]],Date_comment_s)
get_like_comment([Id_comment|[Content_comment|[Author_comment|[Date_comment|[Like_comment|T]]]]],Like_comment_s)

||| [OTROS SELECTORES] |||
get_user([[H|T1]|T2], Name, User_found)
get_post([[H|T1]|T2], Id_post, Found_post)
get_comment([[H|T1]|T2], Id_comment, Found_comment)

------------------PERTENENCIA---------------
is_user([Name,Password,Date_user,Id_post_user,Follow])
is_post([Id_post,Content_post,Author_post,Date_post,Like_post,Id_comment_post])
is_comment([Id_comment,Content_comment,Author_comment,Date_comment])
is_integer_list([H|T])
is_string_list([H|T])
is_date([Day,Month,Year])
is_user_list([H|T])
is_list_active_user([H|T])
is_post_list([H|T])
is_comment_list([H|T]) 
is_social([Users, Posts, Comments, Active_user])
name_available([[H|T1]|T2], Name)
is_registered_user([[H|T1]|T2], Name, Password)

-------------------OTROS--------------------
delete(Element, [H|T], [H|T2])
delete_user([H|T], Name, Resultado)
delete_post([H|T], Id_post, Result)
delete_comment([H|T], Id_comment, Result)
new_id([_|L], C)
user_string([Name,Id_post_user,Follow],User_string)
user_string([Name,Password,Date_user,Id_post_user,Follow,Feed,Id_comment_user],User_string)
user_list_string([H|T],Aux,User_list_string)
post_string([Id_post,Content_post,Author_post,Date_post,Like_post,Id_comment_post],Post_string)
post_list_string([H|T],Aux,Post_list_string)
comment_string([Id_comment,Content_comment,Author_comment,Date_comment,Like_comment],Comment_string)
comment_list_string([H|T],Aux,Post_list_string)
user_post([H1|T1], [H|T], User_post)
user_comment([H1|T1], [H|T], User_comment)
active_user_string([[Name,Password,Date_user,Id_post_user,Follow,Feed,Id_comment_user]],Active_user_string)

-------------------REGISTER--------------------
socialNetworkRegister([H|[T1|[T2|[T3|_]]]],Date,Name,Password,Sn2)

--------------------LOGIN--------------------
socialNetworkLogin([H|[T1|[T2|[T3|_]]]],User,Password,Social)

----------------------POST--------------------
socialNetworkPost([H|[T1|[T2|[[T3|_]|_]]]],Date,Text,List_user,Sn2)

--------------------FOLLOW--------------------
socialNetworkFollow([H|[T1|[T2|[T3|_]]]],User,Sn2)

}--------------------SHARE--------------------
socialNetworkShare([H|[T1|[T2|[T3|_]]]], Date, Id_post, User, Sn2)

---------------------TO STRING-------------------
socialNetworkToString([H|[T1|[T2|[[T3|_]|_]]]], Sn_str)

---------------------COMMENT-------------------
comment([H|[T1|[T2|[T3|_]]]],Date,Id_post,Text,Sn2)

----------------------LIKE-------------------
socialNetworkLike([H|[T1|[T2|[T3|_]]]], Date, Id_post, Sn2)

*/

/* Metas
%---------------CONSTRUCTORES---------------
set_user: constructor del usuario
set_post: constructor del post
set_comment: constructor del comentario
set_social: constructor de un socialNetwork

%---------------SELECTORES---------------
% ||| [TDA User] |||
get_name: predicado selector del nombre de usuario
get_password: predicado selector del password
get_date_user: predicado selector fecha
get_id_post_user: predicado selector de la lista de id de posts que ha realizado el usuario
get_follow: predicado selector de la lista de los seguidores de un usuario
get_id_feed: predicado selector de la lista id publicaciones en feed
get_id_comment_user: predicado selector de la lista de id de comment que ha realizado el usuario


% ||| [TDA Post] |||
get_id_post: predicado selector del id del post
get_content_post: predicado selector del contenido del post
get_author_post: predicado selector del autor del post
get_date_post: predicado selector de la fecha del post
get_like_post: predicado selector de los like de un post
get_id_comment_post: predicado selector de los like de un post

% ||| [TDA Comment] |||
get_id_comment: predicado selector del id del comentario
get_content_comment: predicado selector del contenido del comentario
get_author_comment: predicado selector del autor del contenido
get_date_comment: predicado selector fecha del comentario
get_like_comment: predicado selector los like que tiene el comentario

% ||| Otros selectores |||
get_user: predicado que selecciona un usuario por su nombre
get_post: predicado que selecciona un post por su id
get_comment: predicado que selecciona un comentario por su id

%---------------PERTENENCIA---------------
is_user: predicado que verifica si corresponde a un usuario
is_post: predicado que verifica si corresponde a un post
is_comment: predicado que verifica si corresponde a un comentario
is_integer_list: predicado que verifica si corresponde a una lista de enteros
is_string_list: predicado que verifica si corresponde a una lista de strings
is_date: pedicado que verifica si corresponde a una fecha
is_user_list: predicado que verifica si corresponde a una lista con usuarios
is_list_active_user: predicado que verifica si corresponde a una lista con usuarios activos
is_post_list: predicado que verifica si corresponde a una lista de posts
is_comment_list: predicado que verifica si corresponde a una lista de comentarios
is_social: predicado que verifica si corresponde a una red social
name_availabl: predicado que verifica si el nombre consultado se encuentra disponible
is_registered_user: redicado que verifica si el nombre y la contraseña se encuentran registrados en el socialNetwoek

% ||| Otros predicados |||
delete: predicado que elimina un elemento de una determinada lista
delete_user: predicado que elimina un usuario de la lista según el nombre
delete_post: predicado que elimina un post según su id
delete_comment: predicado que elimina un comentario según su id
new_id: predicado que crea un nuevo id
user_string: predicado que convierte un usuario en str
user_list_string: predicado que convierte la lista de usuarios a string
post_string: predicado que convierte un post en str
post_list_string: predicado que convierte la lista de post a string
comment_string: predicado que convierte un comentario en str
comment_list_string: predicado que convierte la lista de un comentario a string
user_post: predicado que obtiene los post que ha realizado un usuario
user_comment: predicado que obtiene los comentarios que ha realizado un usuario
active_user_string: predicado que convierte un usuario activo en string

% ||| Solicitados |||
socialNetworkRegister: predicado que permite consultar el valor que torna Social al ocurrir el registro de un nuevo usuario 
socialNetworkLogin: predicado que permite autenticar a un usuario registrado
socialNetworkPost: predicado que permite a un usuario con sesión iniciada en la red social realizar un nuevo post
socialNetworkFollow: predicado que permite a un usuario con sesión iniciada seguir a otro usuario dentro de la red social
socialNetworkShare: predicado que permite a un usuario compartir contenido de otro usuario en su propio espacio
socialNetworkToString: predicado que permite obtener una representación de un TDA socialNetwork
comment: predicado que permite a un usuario con sesión iniciada en la red social realizar un nuevo comentario
socialNetworkLike: predicado que permite a un usuario con sesión iniciada en la red social dar me gusta a un post

*/

/* Clausulas

% |||SocialNetwork|||
[[["Elizabeth","pass",[30, 11, 2020],[1],[],[],[1]],
                              ["user","pass",[30, 11, 2020],[],[],[],[]]],
                    [[1,"Hola mundo","Elizabeth",[30, 11, 2020],3,[]],
                    [2,"Mi primer post","user",[30, 11, 2020],1,[]]],
                    [[1,"Primer comentario","Elizabeth",[30, 11, 2020],2]],
                        [["Elizabeth","pass",[30, 11, 2020],[1],[],[],[1]]]]

[[["Elizabeth","pass",[30, 11, 2020],[1],[],[],[]],
                              ["user","pass",[30, 11, 2020],[],[],[],[]]],
                    [[1,"Hola mundo","Elizabeth",[30, 11, 2020],3,[]],
                    [2,"Mi primer post","user",[30, 11, 2020],1,[]]],
                    [],[[]]]

% |||Usuarios|||
["Elizabeth","pass",[30, 11, 2020],[1],[],[],[]]
["user","pass",[30, 11, 2020],[],[],[],[]]

*/

/* Reglas y hechos */

%---------------CONSTRUCTORES---------------
/*
Descripción: constructor del usuario
Eantrada: str x str x date x list x variable
Salida: list | bool
*/
set_user(Name,Password,Date_user,Id_post_user,Follow,Id_feed,Id_comment_user,Generated_user):-
    is_user([Name,Password,Date_user,Id_post_user,Follow,Id_feed,Id_comment_user]),
    append([],Generated_user,[Name,Password,Date_user,Id_post_user,Follow,Id_feed,Id_comment_user]).

/*
Descripción: constructor del post
Entrada: int x str x str x date x int x variable
Salida: list | bool
*/
set_post(Id_post,Content_post,Author_post,Date_post,Like_post,Id_comment_post,New_post):-
    is_post([Id_post,Content_post,Author_post,Date_post,Like_post,Id_comment_post]),
    append([],New_post,[Id_post,Content_post,Author_post,Date_post,Like_post,Id_comment_post]).

/*
Descripción: constructor del comentario
Entrada:
Salida: list | bool
*/
set_comment(Id_comment,Content_comment,Author_comment,Date_comment,Like_comment,New_comment):-
    is_comment([Id_comment,Content_comment,Author_comment,Date_comment,Like_comment]),
    append([],New_comment,[Id_comment,Content_comment,Author_comment,Date_comment,Like_comment]).

/*
Descripción: constructor de un socialNetwork
Entrada: user list x post list x comment list x str
Salida: list | bool
*/
set_social([Users,Posts,Comments,Active_user], New_social):-
    is_social([Users,Posts,Comments,Active_user]),
    append([],New_social,[Users,Posts,Comments,Active_user]).

%---------------SELECTORES---------------
% ||| [TDA User] |||
/*
Descripción: selector del nombre de usuario.
Entrada: list x variable
Salida: variable | bool
*/
get_name([Name|T],Name_s):-
    is_user([Name|T]),
    append([],Name_s,Name).

/*
Descipción: selector del password.
Entrada: list x variable
Salida: variable | bool
*/
get_password([Name|[Password|T]],Password_s):-
    is_user([Name|[Password|T]]),
    append([],Password_s,Password).

/*
Descipción: selector fecha.
Entrada: list x variable
Salida: variable | bool
*/
get_date_user([Name|[Password|[Date_user|T]]],Date_user_s):-
    is_user([Name|[Password|[Date_user|T]]]),
    append([],Date_user_s,Date_user).

/*
Descipción: selector de la lista de id de posts que ha realizado el usuario.
Entrada: list x variable
Salida: variable | bool
*/
get_id_post_user([Name|[Password|[Date_user|[Id_post_user|T]]]],Id_post_user_s):-
    is_user([Name|[Password|[Date_user|[Id_post_user|T]]]]),
    append([],Id_post_user_s,Id_post_user).

/*
Descipción: selector de la lista de los seguidores de un usuario.
Entrada: list x variable
Salida: variable | bool
*/
get_follow([Name|[Password|[Date_user|[Id_post_user|[Follow|T]]]]],Follow_s):-
    is_user([Name|[Password|[Date_user|[Id_post_user|[Follow|T]]]]]),
    append([],Follow_s,Follow).

/*
Descipción: selector de la lista id publicaciones en feed.
Entrada: list x variable
Salida: variable | bool
*/
get_id_feed([Name|[Password|[Date_user|[Id_post_user|[Follow|[Id_feed|T]]]]]],Id_feed_s):-
    is_user([Name|[Password|[Date_user|[Id_post_user|[Follow|[Id_feed|T]]]]]]),
    append([],Id_feed_s,Id_feed).

/*
Descipción: selector de la lista de id de comment que ha realizado el usuario.
Entrada: list x variable
Salida: variable | bool
*/
get_id_comment_user([Name|[Password|[Date_user|[Id_post_user|[Follow|[Id_feed|[Id_comment_user|T]]]]]]],Id_comment_user_s):-
    is_user([Name|[Password|[Date_user|[Id_post_user|[Follow|[Id_feed|[Id_comment_user|T]]]]]]]),
    append([],Id_comment_user_s,Id_comment_user).



% ||| [TDA Post] |||
/*
Descripción: selector del id del post
Entrada: list x variable
Salida: variable | bool
*/
get_id_post([Id_post|T],Id_post_s):-
    is_post([Id_post|T]),
    append([],Id_post_s,Id_post).

/*
Descripción: selector del contenido del post
Entrada: list x variable
Salida: variable | bool
*/
get_content_post([Id_post|[Content_post|T]],Content_post_s):-
    is_post([Id_post|[Content_post|T]]),
    append([],Content_post_s,Content_post).

/*
Descripción: selector del autor del post
Entrada: list x variable
Salida: variable | bool
*/
get_author_post([Id_post|[Content_post|[Author_post|T]]],Author_post_s):-
    is_post([Id_post|[Content_post|[Author_post|T]]]),
    append([],Author_post_s,Author_post).

/*
Descripción: selector de la fecha del post
Entrada: list x variable
Salida: variable | bool
*/
get_date_post([Id_post|[Content_post|[Author_post|[Date_post|T]]]],Date_post_s):-
    is_post([Id_post|[Content_post|[Author_post|[Date_post|T]]]]),
    append([],Date_post_s,Date_post).

/*
Descripción: selector de los like de un post
Entrada: list x variable
Salida: variable | bool
*/
get_like_post([Id_post|[Content_post|[Author_post|[Date_post|[Like_post|T]]]]],Like_post_s):-
    is_post([Id_post|[Content_post|[Author_post|[Date_post|[Like_post|T]]]]]),
    append([],Like_post_s,Like_post).

/*
Descripción: selector de los id de los comentarios que tiene un post
Entrada: list x variable
Salida: variable | bool
*/
get_id_comment_post([Id_post|[Content_post|[Author_post|[Date_post|[Like_post|[Id_comment_post|T]]]]]],Id_comment_post_s):-
    is_post([Id_post|[Content_post|[Author_post|[Date_post|[Like_post|[Id_comment_post|T]]]]]]),
    append([],Id_comment_post_s,Id_comment_post).

% ||| [TDA Comment] |||

/*
Descripción: selector del id del comentario
Entrada: list x variable
Salida: variable | bool
*/
get_id_comment([Id_comment|T],Id_comment_s):-
    is_comment([Id_comment|T]),
    append([],Id_comment_s,Id_comment).

/*
Descripción: selector del contenido del comentario
Entrada: list x variable
Salida: variable | bool
*/
get_content_comment([Id_comment|[Content_comment|T]],Content_comment_s):-
    is_comment([Id_comment|[Content_comment|T]]),
    append([],Content_comment_s,Content_comment).

/*
Descripción: selector del autor del contenido
Entrada: list x variable
Salida: variable | bool
*/
get_author_comment([Id_comment|[Content_comment|[Author_comment|T]]],Author_comment_s):-
    is_comment([Id_comment|[Content_comment|[Author_comment|T]]]),
    append([],Author_comment_s,Author_comment).

/*
Descripción: selector fecha del comentario
Entrada: list x variable
Salida: variable | bool
*/
get_date_comment([Id_comment|[Content_comment|[Author_comment|[Date_comment|T]]]],Date_comment_s):-
    is_comment([Id_comment|[Content_comment|[Author_comment|[Date_comment|T]]]]),
    append([],Date_comment_s,Date_comment).

/*
Descripción: selector los like que tiene el comentario
Entrada: list x variable
Salida: variable | bool
*/
get_like_comment([Id_comment|[Content_comment|[Author_comment|[Date_comment|[Like_comment|T]]]]],Like_comment_s):-
    is_comment([Id_comment|[Content_comment|[Author_comment|[Date_comment|[Like_comment|T]]]]]),
    append([],Like_comment_s,Like_comment).

% ||| Otros selectores |||
/*
 Descripción de la relación: predicado que selecciona un usuario por su nombre.
 Entrada: list(usuarios) x str x variable
 Salida: variable (usuario) | bool

*/
get_user([[H|T1]|T2], Name, User_found) :-
	is_user_list([[H|T1]|T2]),
	string(Name),

	(H == Name,
	get_name([H|T1], New_name),
	get_password([H|T1], New_password),
    get_date_user([H|T1], New_date),
	get_id_post_user([H|T1], Id_new_post),
    get_follow([H|T1], New_follow),
    get_id_feed([H|T1], New_id_feed),
    get_id_comment_user([H|T1], Id_new_comment),
        
	set_user(New_name, New_password, New_date,Id_new_post,New_follow,New_id_feed,Id_new_comment,New_user),
	append([], New_user, User_found));

	get_user(T2, Name, User_found).

/*
 Descripción de la relación: predicado que selecciona un post por su id. 
 Entrada: list(post) x integer x variable
 Salida: variable(post) | bool
*/
get_post([[H|T1]|T2], Id_post, Found_post) :-
	is_post_list([[H|T1]|T2]),
	integer(Id_post),

	(H == Id_post,

	get_id_post([H|T1], New_id_post),
	get_content_post([H|T1], New_content),
	get_author_post([H|T1], New_author_post),
	get_date_post([H|T1], New_date_post),
	get_like_post([H|T1], New_like_post),
    get_id_comment_post([H|T1], New_id_comment),

	set_post(New_id_post,New_content, New_author_post, New_date_post, New_like_post,New_id_comment,New_post),
	
	append([], New_post, Found_post));
	get_post(T2,Id_post, Found_post).

/*
 Descripción de la relación: Predicado que selecciona un comentario por su id. 
 Entrada: list(comment) x integer x variable
 Salida: variable(comment) | bool
*/
get_comment([[H|T1]|T2], Id_comment, Found_comment) :-
	is_comment_list([[H|T1]|T2]),
	integer(Id_comment),

	(H == Id_comment,

	get_id_comment([H|T1], New_id_comment),
	get_content_comment([H|T1], New_content),
	get_author_comment([H|T1], New_author_comment),
	get_date_comment([H|T1], New_date_comment),
	get_like_comment([H|T1], New_like_comment),

	set_comment(New_id_comment,New_content, New_author_comment, New_date_comment, New_like_comment,New_comment),
	
	append([], New_comment, Found_comment));
	get_comment(T2,Id_comment, Found_comment).

%---------------PERTENENCIA---------------
/*
 Descripción de la relación: Predicado que verifica si corresponde a un usuario.
 Entrada: list (usuario)
 Salida: bool
*/
is_user([Name,Password,Date_user,Id_post_user,Follow,Feed,Id_comment_user]):-
    string(Name),
    string(Password),
    is_date(Date_user),
    is_integer_list(Id_post_user),
    is_string_list(Follow),
    is_integer_list(Feed),
	is_integer_list(Id_comment_user).

/*
 Descripción de la relación: Predicado que verifica si corresponde a un post.
 Entrada: list (post)
 Salida: bool
*/
is_post([Id_post,Content_post,Author_post,Date_post,Like_post,Id_comment_post]):-
    integer(Id_post),
    string(Content_post),
    string(Author_post),
    is_date(Date_post),
    integer(Like_post),
    is_integer_list(Id_comment_post).

/*
 Descripción de la relación: Predicado que verifica si corresponde a un comentario.
 Entrada: list (comment)
 Salida: bool
*/
is_comment([Id_comment,Content_comment,Author_comment,Date_comment,Like_comment]):-
    integer(Id_comment),
    string(Content_comment),
    string(Author_comment),
    is_date(Date_comment),
    integer(Like_comment).

/*
 Descripción de la relación: Predicado que verifica si corresponde a una lista de enteros.
 Entrada: list
 Salida: bool
*/
is_integer_list([]).
is_integer_list([H|T]):-
    integer(H),
    is_integer_list(T).

/*
 Descripción de la relación: Predicado que verifica si corresponde a una lista de strings.
 Entrada: list
 Salida: bool
*/
is_string_list([H|T]) :-
	string(H),
	is_string_list(T).
is_string_list([]). 

/*
 Descripción de la relación: Predicado que verifica si corresponde a una fecha.
 Entrada: fecha
 Salida: bool
*/
is_date([]).
is_date([Day,Month,Year]):-
    integer(Day),
    integer(Month),
    integer(Year),
    Day > 0,
    Day =< 31,
    Month > 0,
    Month =< 12.

/*
 Descripción de la relación: Predicado que verifica si corresponde a una lista con usuarios.
 Entrada: list (usuarios)
 Salida: bool
*/
is_user_list([]).
is_user_list([H|T]) :-
	is_user(H),
	is_user_list(T).

/*
 Descripción de la relación: Predicado que verifica si corresponde a una lista con usuarios activos.
 Entrada: list (usuarios)
 Salida: bool
*/
is_list_active_user([H|T]) :-
	is_user(H),
	is_list_active_user(T).
is_list_active_user([]).
is_list_active_user([[]]).

/*
 Descripción de la relación: Predicado que verifica si corresponde a una lista de posts.
 Entrada: list (posts)
 Salida: bool
*/
is_post_list([H|T]) :-
	is_post(H),
	is_post_list(T).
is_post_list([]).

/*
 Descripción de la relación: Predicado que verifica si corresponde a una lista de comentarios.
 Entrada: list (posts)
 Salida: bool
*/
is_comment_list([H|T]) :-
	is_comment(H),
	is_comment_list(T).
is_comment_list([]).

/*
 Descripción de la relación: Predicado que verifica si corresponde a una red social.
 Entrada: list(usuarios, post)
 Salida: bool
*/
is_social([Users, Posts, Comments, Active_user]) :-
	is_user_list(Users),
	is_post_list(Posts),
    is_comment_list(Comments),
	is_list_active_user(Active_user).
is_social([]).

/*
 Descripción de la relación: Predicado que verifica si el nombre consultado se encuentra disponible.
 Entrada: list(usuarios) x str
 Salida: bool
*/
name_available([], _).
name_available([[H|T1]|T2], Name):-
    string(Name),
    is_user_list([[H|T1]|T2]),
	H \= Name,
	name_available(T2, Name).
 
/*
 Descripción de la relación: Predicado que verifica si el nombre y la contraseña se encuentran registrados en el socialNetwork
 Entrada: list(usuarios) x str x str
 Ejemplos: 
*/
is_registered_user([[H|T1]|T2], Name, Password) :-
	get_password([H|T1], C_s),
    
	(H == Name,
	C_s == Password);
    is_registered_user(T2, Name, Password).

% ||| Otros predicados |||
/*
 Descripción de la relación: Predicado que elimina un elemento de una determinada lista
 Entrada: list x list x variable
 Salida: variable|bool
*/
delete(Element,[Element|T],T).
delete(Element, [H|T], [H|T2]) :- 
    delete(Element, T, T2).
/*
 Descripción de la relación: Predicado que elimina un usuario de la lista según el nombre.
 Entrada: list(usuarios) x str x variable
 Salida: list(usuarios)|bool
*/
delete_user([H|T], Name, Resultado) :-
    get_user([H|T], Name, User_found),
    delete(User_found, [H|T], Resultado).
delete_user([], _, _).

/*
 Descripción de la relación: Predicado que elimina un post según su id
 Entrada: list x integer x variable
 Salida: variable | bool
*/
delete_post([H|T], Id_post, Result) :-
	is_post_list([H|T]),
	integer(Id_post),
	get_post([H|T], Id_post, Found_post),
	delete(Found_post, [H|T], Result).
delete_post([], _, _).

/*
 Descripción de la relación: Predicado que elimina un comentario según su id
 Entrada: list x integer x variable
 Salida: variable | bool
*/
delete_comment([H|T], Id_comment, Result) :-
	is_post_list([H|T]),
	integer(Id_comment),
	get_comment([H|T], Id_comment, Found_comment),
	delete(Found_comment, [H|T], Result).
delete_comment([], _, _).

/*
 Descripción de la relación: Predicado que crea un nuevo id.
 Entrada: list x variable
 Salida: variable(integer) | bool
*/
new_id([_|L], C) :- 
    new_id(L, C_ant), C is C_ant+1.
new_id([], 1).

/*
 Descripción: Predicado que convierte un usuario en str
 Entrada: list(usuario) x variable 
 Salida: variable|bool
*/
user_string([Name,Password,Date_user,Id_post_user,Follow,Feed,Id_comment_user],User_string):-
    atomics_to_string(Id_post_user,',' ,Id_post_user_string),
    atomics_to_string(Follow,',',Follow_string),
    atomics_to_string(Date_user,',',Date_string),
	atomics_to_string(Feed,',',Feed_string),
    atomics_to_string(Id_comment_user,',' ,Id_comment_user_string),

    string_concat("\n","|| Usuario: ",Str1),
    string_concat(Str1, Name, Str2),
    string_concat(Str2, " || ||Password: ", Str3),
    string_concat(Str3, Password, Str4),
    string_concat(Str4, " || ||Fecha: ", Str5),
    string_concat(Str5, Date_string, Str6),
    string_concat(Str6, " || ||Id Posts: ", Str7),
    string_concat(Str7, Id_post_user_string, Str8),
    string_concat(Str8," || ||Seguidores: ",Str9),
    string_concat(Str9, Follow_string, Str10),
    string_concat(Str10," || ||Feed: ",Str11),
    string_concat(Str11, Feed_string, Str12),
    string_concat(Str12," || ||Id Comments: ",Str13),
    string_concat(Str13, Id_comment_user_string, Str14),
    string_concat(Str14," ||",Str15),
    string_concat(Str15, "\n",User_string).
user_string([], "[]").

/*
 Descripción: Predicado que convierte la lista de usuarios a string
 Entrada: list(usuario) x variable 
 Salida: variable|bool
*/
user_list_string([H|T],Aux,User_list_string):-
    user_string(H,User_string),
    string_concat(User_string,Aux,Result),
    user_list_string(T,Result,User_list_string).
user_list_string([],Aux,Aux).

/*
 Descripción: Predicado que convierte un post en str
 Entrada: list(usuario) x variable 
 Salida: variable|bool
*/
post_string([Id_post,Content_post,Author_post,Date_post,Like_post,Id_comment_post],Post_string):-
    atom_string(Id_post,Id_post_string),
    atom_string(Like_post,Like_post_string),
    atomics_to_string(Id_comment_post,',',Id_comment_post_string),
    atomics_to_string(Date_post,',',Date_post_string),

    string_concat("\n"," ||Id post: ",Str1),
    string_concat(Str1,Id_post_string,Str2),
    string_concat(Str2,"|| ||Contenido: ",Str3),
    string_concat(Str3,Content_post,Str4),
    string_concat(Str4,"|| ||Autor: ",Str5),
    string_concat(Str5,Author_post,Str6),
    string_concat(Str6,"|| ||Fecha: ",Str7),
    string_concat(Str7,Date_post_string,Str8),
    string_concat(Str8,"|| ||Me gusta: ",Str9),
    string_concat(Str9,Like_post_string,Str10),
    string_concat(Str10,"|| ||Id comentarios: ",Str11),
    string_concat(Str11,Id_comment_post_string,Str12),
    string_concat(Str12,"||",Str13),
    string_concat(Str13,"\n",Post_string).
post_string([],"[]").

/*
 Descripción: Predicado que convierte la lista de post a string
 Entrada: list(usuario) x variable 
 Salida: variable|bool
*/
post_list_string([H|T],Aux,Post_list_string):-
    post_string(H,Post_string),
    string_concat(Post_string,Aux,Result),
    post_list_string(T,Result,Post_list_string).
post_list_string([],Aux,Aux).

/*
 Descripción: Predicado que convierte un comentario en str
 Entrada: list(usuario) x variable 
 Salida: variable|bool
*/
comment_string([Id_comment,Content_comment,Author_comment,Date_comment,Like_comment],Comment_string):-
    atom_string(Id_comment,Id_comment_string),
    atom_string(Like_comment,Like_comment_string),
    atomics_to_string(Date_comment,',',Date_comment_string),
    
    string_concat("\n"," ||Id comment: ",Str1),
    string_concat(Str1,Id_comment_string,Str2),
    string_concat(Str2,"|| ||Contenido: ",Str3),
    string_concat(Str3,Content_comment,Str4),
    string_concat(Str4,"|| ||Author: ",Str5),
    string_concat(Str5,Author_comment,Str6),
    string_concat(Str6,"|| ||Me gusta: ",Str7),
    string_concat(Str7,Like_comment_string,Str8),
    string_concat(Str8,"|| ||Fecha: ",Str9),
    string_concat(Str9,Date_comment_string,Str10),
    string_concat(Str10,"||",Str11),
    string_concat(Str11,"\n",Comment_string).
comment_string([],"[]").

/*
 Descripción: Predicado que convierte la lista de un comentario a string
 Entrada: list(usuario) x variable 
 Salida: variable|bool
*/
comment_list_string([H|T],Aux,Post_list_string):-
    comment_string(H,Post_string),
    string_concat(Post_string,Aux,Result),
    comment_list_string(T,Result,Post_list_string).
comment_list_string([],Aux,Aux).

/*
 Descripción de la relación: Predicado que obtiene los post que ha realizado un usuario
 Entrada: list x list) x variable
 Salida: variable | bool
 */
user_post([H1|T1], [H|T], User_post):-
	[H1|T1] \= [],
	get_post([H|T], H1, Aux),
	user_post(T1, [H|T], Found_post), 
	append([Aux], Found_post, User_post).
user_post([], _, []).
    
/*
 Descripción de la relación: Predicado que obtiene los comentarios que ha realizado un usuario
 Entrada: list x list) x variable
 Salida: variable | bool
 */
user_comment([H1|T1], [H|T], User_comment):-
	[H1|T1] \= [],
	get_comment([H|T], H1, Aux),
	user_comment(T1, [H|T], Found_comment), 
	append([Aux], Found_comment, User_comment).
user_comment([], _, []).


/*
 Descripción: Predicado que convierte un usuario activo en string
 Entrada: list(usuario) x variable 
 Salida: variable|bool
*/
active_user_string([[Name,Password,Date_user,Id_post_user,Follow,Feed,Id_comment_user]],Active_user_string):-
    atomics_to_string(Id_post_user,',' ,Id_post_user_string),
    atomics_to_string(Follow,',',Follow_string),
    atomics_to_string(Date_user,',',Date_string),
	atomics_to_string(Feed,',',Feed_string),
    atomics_to_string(Id_comment_user,',' ,Id_comment_user_string),

    string_concat("\n","|| Usuario: ",Str1),
    string_concat(Str1, Name, Str2),
    string_concat(Str2, " || ||Password: ", Str3),
    string_concat(Str3, Password, Str4),
    string_concat(Str4, " || ||Fecha: ", Str5),
    string_concat(Str5, Date_string, Str6),
    string_concat(Str6, " || ||Id Posts: ", Str7),
    string_concat(Str7, Id_post_user_string, Str8),
    string_concat(Str8," || ||Seguidores: ",Str9),
    string_concat(Str9, Follow_string, Str10),
    string_concat(Str10," || ||Feed: ",Str11),
    string_concat(Str11, Feed_string, Str12),
    string_concat(Str12," || ||Id Comments: ",Str13),
    string_concat(Str13, Id_comment_user_string, Str14),
    string_concat(Str14," ||",Str15),
    string_concat(Str15, "\n",Active_user_string).
active_user_string([], "[]").   


%-------------------------REGISTER-------------------------
/*
 Descripción de la relación: Predicado que permite consultar el valor que torna Social al ocurrir el registro de un nuevo usuario 
 Entrada: socialNetwork x str x str x socialNetwork2
 Salida: bool
*/
socialNetworkRegister([H|[T1|[T2|[T3|_]]]],Date,Name,Password,Sn2):-
	/* Predicado en el caso que ya exista un usuario activo */
	(T3 \= [[]], !, fail);
    
    /*Se verifica que corresponda a una socialNetwork*/
    is_social([H|[T1|[T2|[T3|_]]]]),
    /*Se verifica que la fecha sea date*/
    is_date(Date),
    /*Se verifica que el nombre sea un string*/
    string(Name),
    /*Se verifica que password sea un string*/
    string(Password),

    /*Predicado que verifica que usuario no se encuentre registrado*/
    name_available(H,Name),
           
    /*Se crea un nuevo usuario con la fecha, nombre y password ingresada*/
    set_user(Name,Password,Date,[],[],[],[],New_user),
    
    /*Se actualiza la lista de usuarios*/
    append(H,[New_user],New_user_list),
           
    /*Se genera una nuevo social*/
    set_social([New_user_list, T1, T2, [[]]], Sn2).

%-------------------------LOGIN-------------------------
/*
 Descripción: Predicado que permite autenticar a un usuario registrado
 Entrada: socialNetwork X str X str X socialNetwork
 Salida: bool
*/
socialNetworkLogin([H|[T1|[T2|[T3|_]]]],User,Password,Social):-
	/* Predicado en el caso que ya exista un usuario activo */
	(T3 \= [[]], !, fail);
    
    /*Se verifica que corresponda a una socialNetwork*/
    is_social([H|[T1|[T2|[T3|_]]]]),
    /* Se verifica que Nombre sea un string */
    string(User), 
    /* Se verifica que contrasenia sea un string */
    string(Password), 

    /*Predicado que verificará si el usuario se encuentra registrado*/
    is_registered_user(H, User, Password),
	/* Se obtiene el usuario que iniciara sesion */
	get_user(H, User, Active_user),
	/* Se elimina el usuario de la lista de usuarios, para que sólo esté como usuario activo */
	delete_user(H, User, Resultado),
    /*Se genera un nuevo social*/
    set_social([Resultado, T1, T2, [Active_user]], Social).


%-------------------------POST-------------------------
/*
 Descripción: Predicado que permite a un usuario con sesión iniciada en la red social realizar un nuevo post
 Entrada: socialNetwork X date X string X string list x socialNetwork
 Salida: bool
*/
socialNetworkPost([H|[T1|[T2|[[T3|_]|_]]]],Date,Text,User_list,Sn2):-
	/* Se verifica que socialNetwork contenga un usuario activo */
	([T3] == [[]], !, fail);

    /*Se verifica que corresponda a una socialNetwork*/
    is_social([H|[T1|[T2|[[T3|_]|_]]]]),
    /* Se verifica que corresponda a una fecha */
    is_date(Date),
    /* Se verifica que corresponda a un string */
    string(Text),
    /* Se verifica que corresponda a una lista de strings */
    is_string_list(User_list),

    /* Se determina un nuevo Id para el post a crear */
	new_id(T1, Id_post),
       
    /* Se obtiene el nombre del usuario activo */
    get_name(T3, Author_post),
    /* Se obtiene el usuario activo */
    get_user([T3], Author_post, User_found),

    /* Se obtienen los datos del usuario activo */
    get_name(User_found, Name_s),
    get_password(User_found, Password_s),
    get_id_post_user(User_found, Id_post_user_s),
    get_date_user(User_found, Date_s),
    get_follow(User_found,Follow_s),
    get_id_feed(User_found,Feed_s),
    get_id_comment_user(User_found, Id_comment_user_s),

	/* Se actualiza la lista de Id's de los post del usuario activo */
	append(Id_post_user_s, [Id_post], New_id),
           
    /* Se crea un nuevo usuario con los datos actualizados */
    set_user(Name_s, Password_s, Date_s,New_id,Follow_s,Feed_s,Id_comment_user_s,Generated_user),

    /* Se crea un nuevo post */
    set_post(Id_post,Text,Author_post,Date,0,[],New_post),

    /* Se actualiza la lista de usuarios y los posts */
    append(H, [Generated_user], New_user_list),
    append(T1, [New_post], New_post_list),

    /* Se genera una nueva red social */
    set_social([New_user_list,New_post_list, T2,[[]]],Sn2).

%-------------------------FOLLOW-------------------------
/*
 Descripción: Predicado que permite a un usuario con sesión iniciada seguir a otro usuario dentro de la red social
 Entrada: socialNetwork X string X socialNetwork
 Salida: bool
*/
socialNetworkFollow([H|[T1|[T2|[T3|_]]]],User,Sn2):-
	/* Se verifica que socialNetwork contenga un usuario activo */
	([T3] == [[]], !, fail);

    /* Se verifica que corresponda a una socialNetwork*/
    is_social([H|[T1|[T2|[[T3|_]|_]]]]),
    /*Se verifica que sea string*/
    string(User),

    /* Se obtienen los datos del usuario activo */
    get_name(T3, Name_s),
    /*Se obtiene el usuario*/
    get_user([T3],Name_s,Follower),
    
    /*Se verifica que el usuario activo y el usuario a seguir sean diferentes*/
    User \= Name_s,

    /* Se elimina el usuario para actualizar sus datos */
    delete_user(H,Name_s,Result),

    /* Se obtienen los datos del usuario a seguir */
    get_name(Follower, Name_s),
    get_password(Follower, Password_s),
    get_id_post_user(Follower, Id_post_user_s),
    get_date_user(Follower, Date_s),
    get_follow(Follower, Follow_s),
    get_id_feed(Follower,Feed_s),
    get_id_comment_user(Follower, Id_comment_user_s),
    
    /* Se actualiza la lista de seguidores */
    append(Follow_s, [User], New_follow),

    /* Se crea un usuario nuevo con los datos actualizados*/
    set_user(Name_s, Password_s, Date_s,Id_post_user_s,New_follow,Feed_s,Id_comment_user_s,Generated_user),

    /* Se actualiza la lista de usuarios*/
    append(Result,[Generated_user],New_user_list),

    /* Se crea la nueva red social*/
    set_social([New_user_list,T1,T2,[[]]],Sn2).


%--------------------------SHARE-------------------------

/*
 Descripción: Predicado que permite a un usuario compartir contenido de otro usuario en su propio espacio
 Entrada: socialNetwork X date X integer X string list X socialNetwork
 Salida: bool
*/
socialNetworkShare([H|[T1|[T2|[T3|_]]]], Date, Id_post, User, Sn2):-
	/* Se verifica que socialNetwork contenga un usuario activo */
	([T3] == [[]], !, fail);
    /* Se verifica que corresponda a un número*/
    integer(Id_post),

    /*Predicado en que caso que Id_post no exista*/
    (not(get_post(T1, Id_post, _)), !, fail);

    /*Se verifica que corresponda a una socialNetwork*/
    is_social([H|[T1|[T2|[[T3|_]|_]]]]),
    /* Se verifica que corresponda a una fecha */
    is_date(Date),
    /* Se verifica que corresponda a una lista de usuarios */
    string(User),

    /* Se obtiene el usuario activo */
    get_user(H, User, User_found),
    
    /* Se obtiene la información del usuario al que se le comparte el post*/
    get_password(User_found, Password_s),
    get_id_post_user(User_found, Id_post_user_s),
    get_date_user(User_found, Date_s),
    get_follow(User_found,Follow_s),
	get_id_feed(User_found,Id_feed_s),
    get_id_comment_user(User_found, Id_comment_user_s),
    
    /* Se actualiza la lista de feed del usuario */
	append(Id_feed_s, [Id_post], New_feed),
    
    /* Se crea un nuevo usuario con los datos actualizados */
    set_user(User, Password_s, Date_s,Id_post_user_s,Follow_s,New_feed,Id_comment_user_s,Generated_user),

    /* Se actualiza la lista de usuarios y los comentarios */
    append(H, [Generated_user], New_user_list),

    /* Se crea una nueva red social con los datos actualizados*/
    set_social([New_user_list,T1, T2, [[]]],Sn2).


%------------------------TO STRING-----------------------
/*
 Descripción: Predicado que permite obtener una representación de un TDA socialNetwork
 Entrada: socialNetwork X string
 Salida: string
*/
socialNetworkToString([H|[T1|[T2|[[T3|_]|_]]]], Sn_str):-
    /* Se verifica si existe un usuario activo*/
    (T3 == [],

    /* Se transforman los datos de la red social a string*/
    user_list_string(H, "\n", Aux1),
    post_list_string(T1, "\n",Aux2),
    comment_list_string(T2, "\n",Aux3),

    /* Se concatenar la información*/
    string_concat(Aux1, "\n",Str1),
    string_concat(Str1, Aux2, Str2),
    string_concat(Str2, "\n", Str3),
    string_concat(Str3, Aux3, Str4),
    string_concat(Str4, "\n", Sn_str));
    
    /* Se obtiene las listas de los id de las publicaciones y comentarios del usuario activo*/
    get_id_post_user(T3,Id_post),
    get_id_comment_user(T3,Id_comment),
    
    /* Se obtienen las publicaciones y comentarios del usuario activo*/
    user_post(Id_post,T1,User_post),
    user_comment(Id_comment,T2,User_comment),
    
    /* Se transforman los datos de la red social a string*/
    active_user_string([T3], Aux1),
    post_list_string(User_post, "\n",Aux2),
    comment_list_string(User_comment, "\n",Aux3),  
   
    string_concat(Aux1, "\n",Str1),
    string_concat(Str1, Aux2, Str2),
    string_concat(Str2, "\n", Str3),
    string_concat(Str3, Aux3, Str4),
    string_concat(Str4, "\n", Sn_str). 
    
%-------------------------COMMENT------------------------
/*
 Descripción: Predicado que permite a un usuario con sesión iniciada en la red social realizar un nuevo comentario
 Entrada: socialNetwork x date x integer x integer x string x socialNetwork
 Salida: bool
*/
comment([H|[T1|[T2|[T3|_]]]],Date,Id_post,Text,Sn2):-
	/* Se verifica que socialNetwork contenga un usuario activo */
	([T3] == [[]], !, fail);

    /*Se verifica que Id_post sea entero */
    integer(Id_post),

    /*Predicado en que caso que Id_post no exista*/
    (not(get_post(T1, Id_post, _)), !, fail);

    /*Se verifica que corresponda a una socialNetwork*/
    is_social([H|[T1|[T2|[[T3|_]|_]]]]),    
    /* Se verifica que corresponda a una fecha */
    is_date(Date),
    /* Se verifica que corresponda a un string */
    string(Text),

    /*Se crea un nuevo id para el comentario*/
    new_id(T2,Id_comment),

    /*Se obtiene el nombre autor*/
    get_name(T3,Author_comment),

    /*Se obtiene el usuario */
    get_user([T3],Author_comment,User_found),
    
    /* Se elimina el usuario para actualizar sus datos */
    delete_user(H,Author_comment,Result),
    
    /* Se obtienen los datos del usuario activo */
    get_name(User_found, Name_s),
    get_password(User_found, Password_s),
    get_id_post_user(User_found, Id_post_user_s),
    get_date_user(User_found, Date_s),
    get_follow(User_found,Follow_s),
    get_id_feed(User_found,Id_feed_s),
    get_id_comment_user(User_found, Id_comment_user_s),
    
	/* Se actualiza la lista de Ids de los comentarios del usuario activo */
	append(Id_comment_user_s, [Id_comment], New_id),

    /* Se crea un nuevo usuario con los datos actualizados */
    set_user(Name_s, Password_s, Date_s,Id_post_user_s,Follow_s,Id_feed_s,New_id,Generated_user),

    /* Se crea un nuevo comentario */
    set_comment(Id_comment,Text,Author_comment,Date,0,New_comment),

    /* Se actualiza la lista de usuarios y los comentarios */
    append(Result, [Generated_user], New_user_list),
    append(T2, [New_comment], New_comment_list),

    /* Se genera una nueva red social */
    set_social([New_user_list,T1, New_comment_list, [[]]],Sn2).

%--------------------------LIKE--------------------------
/*
 Descripción: Predicado que permite a un usuario con sesión iniciada en la red social dar me gusta a un post
 Entrada: socialNetwork x date x integer x integer x socialNetwork
 Salida: bool
*/
socialNetworkLike([H|[T1|[T2|[T3|_]]]], Date, Id_post, Sn2):-
	/* Se verifica que socialNetwork contenga un usuario activo */
	(T3 == [[]], !, fail);

    /* Se verifica que corresponda a una socialNetwork*/
    is_social([H|[T1|[T2|[[T3|_]|_]]]]),
    /* Se verifica que corresponda a una fecha*/
    is_date(Date),
    /* Se verifica que corresponda a un número*/
    integer(Id_post),

    /* Predicado que verifica que los id existan*/
	(not(get_post(T1, Id_post, _)), !, fail);

    /* Se obtiene el post*/
	get_post(T1, Id_post, Found_post),

	/* Se elimina el post*/
	delete_post(T1, Id_post, Result),

	/* Se obtienen los datos del post a actualizar*/
	get_id_post(Found_post,New_id_post),
	get_content_post(Found_post,New_content),
	get_author_post(Found_post,New_author_post),
	get_date_post(Found_post,New_date_post),
	get_like_post(Found_post,New_like_post),
	get_id_comment_post(Found_post,New_id_comment),

	/* Se aumenta en uno los like de la publicación*/
	Like_increased is New_like_post+1,

	/* Se crea un post actualizado*/
	set_post(New_id_post,New_content, New_author_post, New_date_post, Like_increased,New_id_comment,New_post),

	/* Se actualiza la lista de post */
	append(Result, [New_post], New_post_list),

    /* Se crea la nueva red social*/
    set_social([H,New_post_list,T2,[[]]],Sn2).


%--------------------------SEARCH--------------------------
/*
 Descripción: Predicado que permite a un usuario con sesión iniciada en la red social permite consultar si cierto listado de publicaciones y cierto listado de comentarios contiene algún texto
 Entrada: socialNetwork X string X integer list
 Salida: bool
*/
/*socialNetworkSearch([H|[T1|[T2|[T3|_]]]], Text, Ids_post, Ids_comment):-
	% Se verifica que socialNetwork contenga un usuario activo 
	([T3] == [[]], !, fail);

    % Se verifica que corresponda a una socialNetwork
    is_social([H|[T1|[T2|[[T3|_]|_]]]]),
    % Se verifica que la lista contenga números en ellas
    is_integer_list(Ids_post),
    is_integer_list(Ids_comment),

    % Se verifica que sea lista id post
    is_id_post_list(Ids_post),
    % Se verifica que lista id comment 
    is_id_comment_list(Ids_comment),

*/

/* EJEMPLOS
---------------------------Register------------------------------
                      
socialNetworkRegister([[["user","pass",[30, 11, 2020],[],[],[],[]]]
                      ,[],[],[[]]],
                   [12, 3, 2020], "Elizabeth","123", Sn2).
                   
socialNetworkRegister([[["Elizabeth","123",[12, 3, 2020],[],[],[],[]],
                      ["user","pass",[30, 11, 2020],[],[],[],[]]],
                        [],[],[[]]],
                   [14, 3, 2020], "Maria","pass", Sn2).
                   
(Ejemplo usuario ya registrado, no se puede registrar)                   
socialNetworkRegister([[["Elizabeth","123",[12, 3, 2020],[],[],[],[]],
                      ["user","pass",[30, 11, 2020],[],[],[],[]]],
                        [],[],[[]]],
                   [14, 3, 2020], "Elizabeth","123", Sn2).
                                 
----------------------------Login-------------------------------
socialNetworkLogin([[["Elizabeth","123",[12, 3, 2020],[],[],[],[]],
                      ["user","pass",[30, 11, 2020],[],[],[],[]]],
                     [],[],[[]]],
                   "user", "pass", Sn2).
                   
socialNetworkLogin([[["Elizabeth","123",[12, 3, 2020],[],[],[],[]],
                      ["user","pass",[30, 11, 2020],[],[],[],[]]],
                     [],[],[[]]],
                   "Elizabeth","123", Sn2).
                   
(Ejemplo usuario no registrado)                   
socialNetworkLogin([[["Elizabeth","123",[12, 3, 2020],[],[],[],[]],
                      ["user","pass",[30, 11, 2020],[],[],[],[]]],
                     [],[],[[]]],
                   "Lizzie","123", Sn2).
                   
----------------------------Post------------------------------
socialNetworkPost([[["Elizabeth","pass",[30, 11, 2020],[],[],[],[]],
                              ["user","pass",[30, 11, 2020],[],[],[],[]]]
                            ,[],[],[["user","pass",[30, 11, 2020],[],[],[],[]]]], 
                  [30, 11, 2020],"Hola",[], Sn2).

socialNetworkPost([[["Elizabeth", "pass", [30, 11, 2020],[],[],[],[]],
                     ["user", "pass", [30, 11, 2020], [1],[],[],[]]], 
                  [[1, "Hola", "user", [30, 11, 2020], 0, []]],
                    [], [["Elizabeth","pass",[30, 11, 2020],[],[],[],[]]]], 
                  [30, 11, 2020],"Nuevo post",[], Sn2).
                  
(Ejemplo no hay usuario activo, no se puede hacer post)
socialNetworkPost([[["Elizabeth", "pass", [30, 11, 2020],[],[],[],[]],
                     ["user", "pass", [30, 11, 2020], [1],[],[],[]]], 
                  [[1, "Hola", "user", [30, 11, 2020], 0, []]],
                    [], [[]]], 
                  [30, 11, 2020],"Nuevo post",[], Sn2).
                  
-------------------------Follow------------------------------------
socialNetworkFollow([[["Elizabeth","123",[12, 3, 2020],[],[],[],[]],
                      ["user","pass",[30, 11, 2020],[],[],[],[]]],
                     [],[],["user","pass",[30, 11, 2020],[],[],[],[]]],
                   "Elizabeth", Sn2).

(Ejemplo seguirse a si mismo)
socialNetworkFollow([[["Elizabeth","123",[12, 3, 2020],[],[],[],[]],
                      ["user","pass",[30, 11, 2020],[],[],[],[]]],
                     [],[],["user","pass",[30, 11, 2020],[],[],[],[]]],
                   "user", Sn2).
                
(Ejemplo sin usuario activo)                
socialNetworkFollow([[["Elizabeth","123",[12, 3, 2020],[],[],[],[]],
                      ["user","pass",[30, 11, 2020],[],[],[],[]]],
                     [],[],[[]]],
                   "user", Sn2)
                   
--------------------------Share-----------------------------------
socialNetworkShare([[["Elizabeth", "pass", [30, 11, 2020], [], ["user"], [],[]],
                     ["user", "pass", [30, 11, 2020], [1],["Elizabeth"],[],[]]], 
                  [[1, "Hola", "user", [30, 11, 2020], 0, []]],
                    [], [["user", "pass", [30, 11, 2020], [1], ["Elizabeth"],[],[]]]], 
                  [30, 11, 2020],1,"Elizabeth", Sn2).

(Ejemplo sin usuario activo)
socialNetworkShare([[["Elizabeth", "pass", [30, 11, 2020], [], ["user"], [],[]],
                     ["user", "pass", [30, 11, 2020], [1],["Elizabeth"],[],[]]], 
                  [[1, "Hola", "user", [30, 11, 2020], 0, []]],
                    [], [[]]], 
                  [30, 11, 2020],1,"Elizabeth", Sn2).
                  
(Ejemplo id no válido)
socialNetworkShare([[["Elizabeth", "pass", [30, 11, 2020], [], ["user"], [],[]],
                     ["user", "pass", [30, 11, 2020], [1],["Elizabeth"],[],[]]], 
                  [[1, "Hola", "user", [30, 11, 2020], 0, []]],
                    [], [["user", "pass", [30, 11, 2020], [1], ["Elizabeth"],[],[]]]], 
                  [30, 11, 2020],13,"Elizabeth", Sn2).
                  
--------------------------String----------------------------------
(Ejemplo sin usuario activo)
socialNetworkToString([[["Elizabeth","pass",[30, 11, 2020],[1],[],[],[]],
                              ["user","pass",[30, 11, 2020],[],[],[],[]]],
                    [[1,"Hola mundo","Elizabeth",[30, 11, 2020],3,[]],
                    [2,"Mi primer post","user",[30, 11, 2020],1,[]]],
                    [],[[]]],
                                Sn3), 
write(Sn3).
      
(Ejemplo con usuario activo)
socialNetworkToString([[["Elizabeth","pass",[30, 11, 2020],[1],[],[],[]],
                              ["user","pass",[30, 11, 2020],[],[],[],[]]],
                    [[1,"Hola mundo","Elizabeth",[30, 11, 2020],3,[]],
                    [2,"Mi primer post","user",[30, 11, 2020],1,[]]],
                    [],[["Elizabeth","pass",[30, 11, 2020],[1],[],[],[]]]],
                                Sn3), 
write(Sn3).

(Ejemplo con usuario activo)
socialNetworkToString([[["Elizabeth","pass",[30, 11, 2020],[1],[],[],[1]],
                              ["user","pass",[30, 11, 2020],[],[],[],[]]],
                    [[1,"Hola mundo","Elizabeth",[30, 11, 2020],3,[]],
                    [2,"Mi primer post","user",[30, 11, 2020],1,[]]],
                    [[1,"Primer comentario","Elizabeth",[30, 11, 2020],2]],
                        [["Elizabeth","pass",[30, 11, 2020],[1],[],[],[1]]]],
                                Sn3), 
write(Sn3).
-------------------------Comment-----------------------------------
comment([[["Elizabeth","pass",[30, 11, 2020],[],[],[],[]],
                              ["user","pass",[30, 11, 2020],[],[],[],[]]],
                    [[1,"Hola mundo","user",[30, 11, 2020],0,[]]],
                    [],["user","pass",[30, 11, 2020],[],[],[],[]]], 
                  [30, 11, 2020],1,"uwu", Sn2).

(Ejemplo con id inexistentente dentro de la red social)
comment([[["Elizabeth","pass",[30, 11, 2020],[],[],[],[]],
                              ["user","pass",[30, 11, 2020],[],[],[],[]]],
                    [[1,"Hola mundo","user",[30, 11, 2020],0,[]]],
                    [],[["user","pass",[30, 11, 2020],[],[],[],[]]]], 
                  [30, 11, 2020],13,"uwu", Sn2).

(Ejemplo sin usuario activo)
comment([[["Elizabeth","pass",[30, 11, 2020],[],[],[],[]],
                              ["user","pass",[30, 11, 2020],[],[],[],[]]],
                    [[1,"Hola mundo","user",[30, 11, 2020],0,[]]],
                    [],[[]]], 
                  [30, 11, 2020],1,"uwu", Sn2).
                  
----------------------------Like----------------------------------
socialNetworkLike([[["Elizabeth","pass",[30, 11, 2020],[],[],[],[]],
                              ["user","pass",[30, 11, 2020],[],[],[],[]]],
                    [[1,"Hola mundo","user",[30, 11, 2020],0,[]]],
                    [],["user","pass",[30, 11, 2020],[],[],[],[]]], 
                  [30, 11, 2020],1, Sn2).
                  
socialNetworkLike([[["user", "pass", [30, 11, 2020],[1],[],[],[]],
                     ["Elizabeth", "pass", [30, 11, 2020], [2],[],[],[]]],
                    [[1, "Hola", "user", [30, 11, 2020], 0, []], 
                    [2, "Nuevo post", "Elizabeth", [30, 11, 2020], 0, []]],
                    [], [["user","pass",[30, 11, 2020],[],[],[],[]]]], 
                  [30, 11, 2020],2, Sn2).

(Ejemplo sin usuario activo)
socialNetworkLike([[["user", "pass", [30, 11, 2020],[1],[],[],[]],
                     ["Elizabeth", "pass", [30, 11, 2020],[2],[],[],[]]],
                    [[1, "Hola", "user", [30, 11, 2020], 0, []], 
                    [2, "Nuevo post", "Elizabeth", [30, 11, 2020], 0, []]],
                    [], [[]]], 
                  [30, 11, 2020],2, Sn2).


*/

