-- David Martinez Diaz --

-- Practica Parcial 2 --

-- https://www.wuolah.com/apuntes-fundamentos-de-bases-de-datos/apuntes/grado-en-ingenieria-informatica/ugr-escuela-tecnica-superior-de-ingenierias-informatica-y-de-telecomunicacion/2/examen-practico-extraordinaria-2021-parcialpracticoextraordinaria2021pdf-4391414?page=subject&path=I6 --

-- Ejercicio 1 -- 

CREATE TABLE Articulo (

    codar# integer NOT NULL PRIMARY KEY,
    doi varchar(12) NOT NULL UNIQUE,
    titulo varchar(20) NOT NULL,
    
    ncitas integer DEFAULT 0 NOT NULL
        CHECK (ncitas>=0),
    nreferencias integer DEFAULT 0 NOT NULL
        CHECK (nreferencias>=0)

);

CREATE TABLE Publicado (

    codar# integer NOT NULL PRIMARY KEY REFERENCES Articulo(Codar#), 
    codrev# varchar(20) NOT NULL REFERENCES Revista(codrev#),
    fecha_publi DATE NOT NULL

);

-- Ejercicio 2 --

-- AR --
 
 Pi codAu (Escrito NJ (Publicado ÷ Pi codRev (Sg Tema = 'Base de Datos' (Revista) )));
 
 -- SQL --
 
 SELECT codAu FROM Autor A WHERE NOT EXISTS (
 
    SELECT codRev FROM Revista WHERE Tema='Base de Datos'
    MINUS
    SELECT codRev FROM (publicado NATURAL JOIN escrito) B WHERE A.codau=B.codau and publicado.codar = escrito.codar
 
 );
 
 -- Ejercicio 3 --
 
 -- AR --
 P(publicado) = P1;
 P(publicado) = P2;
 
 (Articulo?(Publicado - ? P1.fecha > P2.fecha (P1xP2)));
 
 -- SQL --
 
 SELECT * FROM articulo WHERE codAr = (SELECT codAR FROM Publicado WHERE fecha = (SELECT max(fecha) FROM Publicado));
 
 
 -- Ejercicio 4 --
 
 CREATE VIEW vistaEj4 (codRev, nombre, editorial, tema, fecha) AS SELECT codRev, to_char(fecha_public, 'yyyy') FROM Publicado Group BY codRev, to_char(fecha_public, 'yyyy') Having coount(codar) > 100;
 
 -- Ejercicio 5 --
 
 DELETE FROM Autor WHERE nombre='R.Martin';
 
 DELETE FROM Escrito WHERE codAu = (SELECT codAU FROM Autor WHERE nombre='R.Martin');

-------------------------------------------------------------------------------
-------------------------------------------------------------------------------

 --- Otro examen ---
 
 CREATE TABLE Copia (
 
    Cop# varchar(10) NOT NULL,
    L# varchar(10) NOT NULL REFERENCES Libro(L#),
    PRIMARY KEY(Cop#, L#)
 
 );
 
 CREATE TABLE Prestado (
 
    Cop# varchar(10) NOT NULL REFERENCES Copia(Cop#),
    L# varchar(10) NOT NULL REFERENCES Copia(L#),
    
    Fecha Date Not NULL UNIQUE   
        CHECK (TO_CHAR(fecha,'yyyy') != '2012'),
        
    DNI varchar(10) NOT NULL UNIQUE References Usuario(DNI),
    
    FOREIGN KEY (cop#, L#) REFERENCES (cop#, L#),
    PRIMARY KEY (Cop#, L#, Fecha)
 
 );
 
 -- Ejercicio 2 --
 
 -- Apartado a --
 -- AR --
 
 Pi NombreU (Usuario NJ (Pi DNI, L# (Prestado) ÷ Pi L# (Libro)));
 
 -- SQL --
 
 SELECT NombreU FROM Usuario A WHERE NOT EXISTS 
 (
    
    SELECT L# FROM LIBRO
    MINUS
    SELECT L# FROM Prestado WHERE A.DNI=Prestado.DNI
    
 );
 
 -- Apartado b --
 
 -- AR --
 
 P(Prestado) = P1;
 P(Prestado) = P2;
 
 Pi Titulo (Libro NJ (Prestado - Sg P1.fecha>P2.fecha(P1xP2)));
 
 -- SQL --
 
 SELECT Titulo FROM Libro WHERE L# In (SELECT L# FROM Prestado WHERE fecha = (SELECT MIN(fecha) FROM Prestado));
 
 
 -- Ejercicio 3 --
 
 CREATE VIEW vista3(DNI, Titulo, Numero) 
 AS 
 SELECT DNI, Titulo, COUNT(*) FROM usuario, libro, prestado WHERE (usuario.DNI=prestado.DNI and prestado.L#=Libro.L#)
 GROUP BY DNI, titulo
 HAVING COUNT(*) > 1
 ORDER BY DNI, Titulo;

-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
 
 -- Examen --
 
 -- Ejercicio 1 --
 
 CREATE TABLE Entrada (
 
    Fecha DATE,
    Hora_Ini Integer CHECK (1 <= Hora_Ini <= 10),
    
    Sala# integer CHECK (0 <= Sala# <= 19),
    Fila varchar(1),
    Columna integer CHECK (1 <= Columna <= 99)
 
    PRIMARY KEY (Fecha,Hora_Ini,Sala#, Fila, Columna),
    FOREIGN KEY (Fecha,Hora_Ini,Sala#) REFERENCES Proyeccion (Fecha,Hora_Ini,Sala#),
    FOREIGN KEY (Sala#,Fila,Columna) REFERENCES Asiento (Sala#,Fila,Columna),
 );
 
 INSERT INTO Entrada VALUES (...);
 
 -- Ejercicio 2 --
 
 -- Apartado a --
 
 -- AR --
 
 (Proyeccion ? (? Fecha, Hora, Sala# (Proyeccion) - ? Fecha, Hora, Sala# (Entrada)));
 
 -- SQL --
 
 SELECT * FROM Proyeccion P WHERE NOT EXISTS ( SELECT * FROM Entrada WHERE P.fecha=Entrada.fecha and P.Hora=Entrada.Hora and P.Sala=Entrada.sala);

 -- Apartado b --
 
 -- AR --
 
 P(Copias) = C1;
 P(Copias) = C2;
 
 ? Titulo (Pelicula ? (? P# - ? P# (? C1.cop!=C2.cop (C1xC2))));

-- SQL --

SELECT * FROM Proyeccion P WHERE NOT EXISTS ( SELECT * FROM Entrada WHERE P.fecha=Entrada.fecha and P.Hora=Entrada.Hora and P.Sala=Entrada.sala);
  
-- Apartado c --

-- AR --

? Titulo (Pelicula ? (? Sala# (Proyeccion) ÷ ? Sala# (Sala)));
 
-- SQL --
 
SELECT Titulo FROM Pelicula P WHERE NOT EXISTS (

    SELECT Sala# FROM Sala
    MINUS
    SELECT Sala# FROM Proyeccion WHERE Proyeccion.P#=P.P#

);

-- Ejercicio 3 --

CREATE VIEW vistaEj3 AS (SELECT Cop#, COUNT(*) FROM Proyeccion GROUP BY Cop# HAVING COUNT(*) > 40 ORDER BY Cop#;
 
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------

-- Otro Examen Simulacro1.jpg --

-- Ejercicio 1 --

CREATE TABLE Tiempos (

    No_corre integer CHECK (0 < No_corre and No_corre <= 9999) References Corredores(No_corre),
    Cod_prue varchar(30),
    No_etapa integer CHECK (0 < No_etapa and No_etapa <= 30),
    Tiempo integer NOT NULL CHECK (0 < Tiempo),
    año integer CHECK(1900 <= año),
    
    PRIMARY KEY(No_corre, Cod_prue, año, No_etapa),
    FOREIGN KEY (Cod_prue, año, No_etapa) References Etapas (Cod_prue, año, No_etapa)
);
 
INSERT INTO Tiempos VALUES (3400, 'Pelele', 1902, 20, 167);

-- Ejercicio 2 --

-- Apartado a --
-- AR --

P(Etapa) = E1;
P(Etapa) = E2;

Pi Cod_pru, año, No_etapa (Etapa - Sg E1.kms>E2.kms(E1xE2);

-- SQL --

SELECT Cod_pru, año, No_etapa FROM Etapa WHERE Km in (SELECT min(km) FROM Etapa);

-- Apartado b --

-- AR --

Pi nom_corre (Corredores NJ( Pi Nom_corre, cod_pru, año, no_etapa (Tiempos) 
/ 
Pi cod_pru, año, no_etapa (Sg No_etapa='Giro de Italia' and año=2015 (Etapas) ));

-- SQL --

SELECT nom_corre FROM Corredores C WHERE NOT EXISTS (

    SELECT cod_pru, año, no_etapa FROM Etapas WHERE (No_etapa='Giro de Italia' and año=2015)
    MINUS 
    SELECT cod_pru, año, no_etapa FROM Tiempos WHERE (C.No_corre=Tiempos.No_corre)

);
 
-- Apartado c --

-- AR --

P(corredores) = C1;
P(corredores) = C2;

Pi Cod_eq (Equipos) - Pi cod_eq (Sg c1.cod_eq=c2.cod_eq and c1.pais != c2.pais (C1xC2);

-- SQL --

SELECT cod_eq FROM Equipos MINUS SELECT Cod_eq FROM Corredores C1, Corredores C2 WHERE (c1.cod_eq=c2.cod_eq and c1.pais != c2.pais);

-- Ejercicio 3 --

CREATE VIEW VistaEj3(Nom_corre, Suma_tiempos) AS SELECT Nom_Corre, SUM(Tiempo) FROM Corredores NATURAL JOIN Tiempos WHERE (Cod_pru='Tour de Francia' and año=2014) GROUP BY No_corre ORDER BY Sum(Tiempo);

-------------------------------------------------------------------------------
-------------------------------------------------------------------------------

-- Examen Parcial 2 Ordinaria 2020 --

-- Ejercicio 1 --

CREATE TABLE Persona (

    DNI_p varchar(10) NOT NULL PRIMARY KEY,
    NSS number(9) NOT NULL UNIQUE,
    nombre varchar(10) NOT NULL,
    apellidos varchar(10) NOT NULL,
    f_nac Date NOT NULL,
    f_def DATE DEFAULT TO_DATE('01/01/3000', 'DD/MM/YYYY') NOT NULL,
    direccion varchar(10) NOT NULL,
    email varchar(10),
    pais varchar(10) DEFAULT 'España' NOT NULL

);
 
CREATE TABLE Visita (

    DNI_p varchar(10) References Persona(DNI_p),
    fecha Date,
    DNI_s varchar(10) References Sanitario(DNI_s),
    pronostico BLOB,
    
    PRIMARY KEY (DNI_p, fecha)
);


-- Ejercicio 2 --

-- Apartado 1 --
-- AR --
 
 P(persona) = P1;
 P(persona) = P2;
 
 Pi nombre, apellidos (Persona - Pi P1.DNI_p, P1.nombre, P1.apellidos (Sg P1.f_nac > P2.f_nac (P1xP2)))
 
-- SQL --

SELECT nombre, apellidos FROM Persona WHERE f_def in (SELECT min(f_def) FROM Persona);

-- Apartado 2 --

-- AR --

Pi DNI_p (Pi DNI_p, DNI_s (Sg fecha>'01/03/2020' Visita) / Pi DNI_s (Sanitario))

-- SQL --

Select DNI_p FROM persona P WHERE NOT EXISTS (
    
    SELECT DNI_s FROM sanitario
    MINUS
    SELECT DNI_s FROM visita WHERE (visita.fecha>TO_DATE('01/03/2020', 'dd/mm/yyyy') and visita.DNI_p=P.DNI_p)
    
);

-- Apartado 3 --

-- AR --

Pi DNI_P (Realiza) - Pi DNI_p (Sg tipo!='PCR' (Test NJ Realiza));

-- SQL --

SELECT DNI_P FROM Realiza WHERE Ref In (SELECT Ref FROM Test WHERE tipo='PCR');

-- Ejercicio C --

CREATE VIEW supercontagiadores (nombre, apellidos. direccion, email) 
AS 
(SELECT DNI1 FROM Contactos WHERE f_def=TO_DATE('01/01/3000', 'dd/mm/yyyy')
GROUP BY (DNI1) HAVING COUNT(*) >= 50);

-- Ejercicio D -- 

ALTER TABLE persona ADD ( grupo_de_riesgo varchar2(2) CHECK (grupo_de_riesgo='SI' OR grupo_de_riesgo='NO'));
UPDATE persona SET grupo_de_riesgo='SI' WHERE (SYSDATE-f_nac)/365 >= 70;

-------------------------------------------------------------------------------
-------------------------------------------------------------------------------

-- Examen Ordinaria 2018 --

-- Ejercicio 1 --

CREATE TABLE Pedido (

    Ped# varchar(8)PRIMARY KEY,
    F_P DATE CHECK( 2010 <= TO_NUMBER(F_P,'yyyy') AND F_P <= F_E),
    F_E DATE CHECK( 2010 <= TO_NUMBER(F_E,'yyyy') AND F_E <= F_R),
    F_R DATE CHECK( 2010 <= TO_NUMBER(F_R,'yyyy') AND F_E <= F_R),
    
    email varchar(10) NOT NULL References Usuario(email),
    Pago# varchar(10) NOT NULL References Met_pago(Pago#)

);

CREATE TABLE Cheque (

    Disponible integer NOT NULL CHECK (Disponible >= 0),
    Cheque# charvar(10) References Met_pago(Pago#) PRIMARY KEY,
    Tarjeta# charvar(10) NOT NULL References Tarjeta(Tarjeta#) CHECK (Tarjeta# != Cheque)

);

-- Ejercicio 2 --
 
-- AR --

Pi Nombre (Usuario NJ Pedido NJ ( Pi Ref#, Ped# (Incluye) / Pi Ref# (Sg Precio < 20 (Articulo))) )

-- SQL --

SELECT nombre FROM Usuario U WHERE NOT EXISTS (

    select ref# from articulo where precio <=20
    minus 
    select ref# from incluye natural join (select * from pedido x where u.email=x.email)

);

-- Ejercicio 3 --

-- AR --

Pi Ped#, Pago# ((Sg Pago#>1000 (Pedido)) NJ Incluye)

-- SQL --

SELECT Ped#, SUM(Pago#) FROM Pedido GROUP BY Ped# HAVING Sum(Pago#) > 1000 Order BY SUM(Pago#);

-- Ejercicio 4 --

-- AR --

P(Pedido) = P1;
P(pedido)) = P2;

(Pedido NJ (Pi Ped# (Pedido)) - (Pi Ped# (Sg P1.F_P > P2.F_P (P1xP2))))

-- SQL --

SELECT * FROM Pedido WHERE F_P in (SELECT min(F_P) FROM Pedido);

-------------------------------------------------------------------------------
-------------------------------------------------------------------------------

-- Examen ExtraOrdinaria 2018 --

-- Ejercicio 1 --

CREATE TABLE Partido (
    Fecha DATE,
    grupo VARCHAR(10),
    FOREIGN KEY(Fecha, grupo) REFERENCES Liga(Fecha, grupo),
    jLocal REFERENCES BOT(email),
    jVisit REFERENCES BOT(email),
    GLocal NUMBER(1) NOT NULL CHECK (GLocal = 0 or GLocal = 1)
    GVisit NUMBER(1) NOT NULL CHECK (GVisit = 0 or GVisit = 1)
    Empate NUMBER(1) NOT NULL CHECK (Empate = 0 or Empate = 1) // CHECK(Empate IN (0, 1)),
    PRIMARY KEY (Fecha, grupo, jLocal, jVisit),
    CHECK(jLocal <> jVisit)
    CHECK (G_Local + G_Visit + Empate = 1)
);

CREATE TABLE Bot (
    email REFERENCES Participante(email) PRIMARY KEY,
    NombreBot VARCHAR(10) NOT NULL UNIQUE,
    cpp BLOB,
    h BLOB
);

-- Ejercicio 2 --

-- AR --

Pi Nombre ((Sg grupo=A1 (Participante) NJ (Pi jLocal, Fecha (Partido))) / Pi Fecha8Sg grupo=A1(Liga)));

-- SQL --

SELECT nombre FROM Participante P WHERE grupo = 'A1' AND NOT EXISTS (

    SELECT fecha FROM Liga WHERE grupo = 'A1'
    MINUS
    SELECT fecha FROM PARTIDO WHERE jLocal = P.email 

);

-- Ejercicio 3 --

SELECT nombre, (3*SUM(GLocal) + SUM(Empate)) FROM (Bots NATURAL JOIN Partido) WHERE Fecha=TO_DATE(“03/06/2018”, “dd/mm/yyyy”)
GROUP BY jLocal
HAVING 3*SUM(GLocal) + SUM(Empate) > 4;

-- Ejercicio 4 --

SELECT jVisit FROM Partido JOIN Bot ON Partido.jLocal = Bot.email AND Bot.nombre = GreedyBot WHERE GVisit = 1 
INTERSECT
SELECT jLocal FROM Partido JOIN Bot ON Partido.jVisitante = Bot.email AND Bot.nombre = GreedyBot WHERE GLocal = 1; 







 
 
 