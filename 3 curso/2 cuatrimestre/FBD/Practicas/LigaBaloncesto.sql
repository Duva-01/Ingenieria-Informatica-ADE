-- Ejercicio 1.8 Liga de Baloncesto --
-- David Martinez Diaz GII-ADE --

CREATE TABLE equipos (
    codE char(10) NOT NULL PRIMARY KEY,
    nombreE varchar(20) NOT NULL UNIQUE,
    localidad varchar(20) NOT NULL,
    entrenador varchar(20) NOT NULL,
    fecha_crea DATE);
    
CREATE TABLE jugadores(
    codJ char(10) NOT NULL PRIMARY KEY,
    codE char(10) NOT NULL REFERENCES equipos(codE),
    nombreJ varchar(20) NOT NULL);
    
CREATE TABLE encuentros(
    Elocal char(10) NOT NULL,
    EVisitante char(10) NOT NULL,
    fecha DATE,
    PLocal integer DEFAULT 0 NOT NULL,
    PVisitante integer DEFAULT 0 NOT NULL,
    PRIMARY KEY(ELocal, EVisitante),
    FOREIGN KEY(ELocal) REFERENCES equipos(codE),
    FOREIGN KEY (EVisitante) REFERENCES equipos(codE),
    check(PLocal >= 0),
    check(PVisitante >= 0));
    
CREATE TABLE faltas(
    codJ char(10) NOT NULL REFERENCES jugadores(codJ),
    ELocal char(10) NOT NULL REFERENCES equipos(codE),
    EVisitante char(10) NOT NULL REFERENCES equipos(codE),
    num integer DEFAULT 0 NOT NULL,
    CHECK(num BETWEEN 0 and 5));