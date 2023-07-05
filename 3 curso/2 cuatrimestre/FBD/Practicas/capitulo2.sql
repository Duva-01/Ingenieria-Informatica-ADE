-- Capitulo 2 --
-- David Martinez Diaz GII-ADE --

DROP TABLE ventas;
DROP TABLE pieza;
DROP TABLE proveedor;
DROP TABLE proyecto;

CREATE TABLE proveedor (
    codProveedor char(3) NOT NULL PRIMARY KEY,
    nombreProveedor varchar(20) NOT NULL UNIQUE,
    status integer DEFAULT 0 NOT NULL,
    ciudadProveedor varchar(20) NOT NULL
);
    
CREATE TABLE pieza(
    codPieza char(3) NOT NULL PRIMARY KEY,
    nombrePieza varchar(10) NOT NULL,
    colorPieza varchar(10) NOT NULL,
    pesoPieza float DEFAULT 0 NOT NULL,
    ciudadPieza varchar(20) NOT NULL
    
);
    
CREATE TABLE proyecto(

    codProyecto char(3) NOT NULL PRIMARY KEY,
    nombreProyecto varchar(10) NOT NULL UNIQUE,
    ciudadProyecto varchar(20) NOT NULL
);
    
CREATE TABLE ventas (

    codVentaProveedor char(3) NOT NULL,
    codVentaPieza char(3) NOT NULL,
    codVentaProyecto char(3) NOT NULL,
    
    PRIMARY KEY(codVentaProveedor, codVentaPieza, codVentaProyecto),
    
    FOREIGN KEY (codVentaProveedor) REFERENCES proveedor(codProveedor),
    FOREIGN KEY (codVentaPieza) REFERENCES pieza(codPieza),
    FOREIGN KEY (codVentaProyecto) REFERENCES proyecto(codProyecto),
    
    cantidad integer,
    fecha DATE

);


    