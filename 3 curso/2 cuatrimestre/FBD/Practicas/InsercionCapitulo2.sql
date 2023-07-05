DELETE FROM proveedor;
DELETE FROM proyecto;
DELETE FROM pieza;
DELETE FROM ventas;

-- Proveedores

INSERT INTO proveedor VALUES ('S1', 'Jose Fernandez', '2', 'Madrid');
INSERT INTO proveedor VALUES ('S2', 'Manuel Vidal', '1', 'Londres');
INSERT INTO proveedor VALUES ('S3', 'Luisa Gomez', '3', 'Lisboa');
INSERT INTO proveedor VALUES ('S4', 'Pedro Sanchez', '4', 'Paris');
INSERT INTO proveedor VALUES ('S5', 'Maria Reyes', '5', 'Roma');
INSERT INTO proveedor VALUES ('S6', 'Jose Perez', '6', 'Bruselas');
INSERT INTO proveedor VALUES ('S7', 'Luisa Martin', '7', 'Atenas');

SELECT * FROM proveedor;

-- Piezas

INSERT INTO pieza VALUES ('P1', 'Tuerca', 'Gris', 2.5, 'Madrid');
INSERT INTO pieza VALUES ('P2', 'Tornillo', 'Rojo', 1.25, 'Paris');
INSERT INTO pieza VALUES ('P3', 'Arandela', 'Blanco', 3, 'Londres');
INSERT INTO pieza VALUES ('P4', 'Clavo', 'Gris', 5.5, 'Lisboa');
INSERT INTO pieza VALUES ('P5', 'Alcayata', 'Blanco', 10, 'Roma');

SELECT * FROM pieza;

-- Proyectos

INSERT INTO proyecto VALUES ('J1', 'Proyecto 1', 'Londres');
INSERT INTO proyecto VALUES ('J2', 'Proyecto 2', 'Londres');
INSERT INTO proyecto VALUES ('J3', 'Proyecto 3', 'Paris');
INSERT INTO proyecto VALUES ('J4', 'Proyecto 4', 'Roma');

SELECT * FROM proyecto;

-- por asegurar se borran los datos

-- se insertan los datos
INSERT INTO ventas VALUES ('S1', 'P1', 'J1', 150, TO_DATE('18/09/1997','dd/mm/yyyy')); 
INSERT INTO ventas VALUES ('S1', 'P1', 'J2', 100, TO_DATE('06/05/1996','dd/mm/yyyy')); 
INSERT INTO ventas VALUES ('S1', 'P1', 'J3', 500, TO_DATE('06/05/1996','dd/mm/yyyy')); 
INSERT INTO ventas VALUES ('S1', 'P2', 'J1', 200, TO_DATE('22/07/1995','dd/mm/yyyy')); 
INSERT INTO ventas VALUES ('S2', 'P2', 'J2', 15, TO_DATE('23/11/2004','dd/mm/yyyy')); 
INSERT INTO ventas VALUES ('S4', 'P2', 'J3', 1700, TO_DATE('28/11/2000','dd/mm/yyyy')); 
INSERT INTO ventas VALUES ('S1', 'P3', 'J1', 800, TO_DATE('22/07/1995','dd/mm/yyyy')); 
INSERT INTO ventas VALUES ('S5', 'P3', 'J2', 30, TO_DATE('01/04/2014','dd/mm/yyyy')); 
INSERT INTO ventas VALUES ('S1', 'P4', 'J1', 10, TO_DATE('22/07/1995','dd/mm/yyyy')); 
INSERT INTO ventas VALUES ('S1', 'P4', 'J3', 250, TO_DATE('09/03/1994','dd/mm/yyyy')); 
INSERT INTO ventas VALUES ('S2', 'P5', 'J2', 300, TO_DATE('23/11/2004','dd/mm/yyyy')); 
INSERT INTO ventas VALUES ('S2', 'P2', 'J1', 4500, TO_DATE('15/08/2004','dd/mm/yyyy')); 
INSERT INTO ventas VALUES ('S3', 'P1', 'J1', 90, TO_DATE('09/06/2004','dd/mm/yyyy')); 
INSERT INTO ventas VALUES ('S3', 'P2', 'J1', 190, TO_DATE('12/04/2002','dd/mm/yyyy')); 
INSERT INTO ventas VALUES ('S3', 'P5', 'J3', 20, TO_DATE('28/11/2000','dd/mm/yyyy')); 
INSERT INTO ventas VALUES ('S4', 'P5', 'J1', 15, TO_DATE('12/04/2002','dd/mm/yyyy')); 
INSERT INTO ventas VALUES ('S4', 'P3', 'J1', 100, TO_DATE('12/04/2002','dd/mm/yyyy')); 
INSERT INTO ventas VALUES ('S4', 'P1', 'J3', 1500, TO_DATE('26/01/2003','dd/mm/yyyy')); 
INSERT INTO ventas VALUES ('S1', 'P4', 'J4', 290, TO_DATE('09/03/1994','dd/mm/yyyy')); 
INSERT INTO ventas VALUES ('S1', 'P2', 'J4', 175, TO_DATE('09/03/1994','dd/mm/yyyy')); 
INSERT INTO ventas VALUES ('S5', 'P1', 'J4', 400, TO_DATE('01/04/2014','dd/mm/yyyy')); 
INSERT INTO ventas VALUES ('S5', 'P3', 'J3', 400, TO_DATE('01/04/2014','dd/mm/yyyy'));
INSERT INTO ventas VALUES ('S1', 'P5', 'J1', 340, TO_DATE('06/02/2010','dd/mm/yyyy'));
INSERT INTO ventas VALUES ('S6', 'P1', 'J1', 340, TO_DATE('10/02/2006','dd/mm/yyyy'));
INSERT INTO ventas VALUES ('S6', 'P1', 'J2', 340, TO_DATE('10/02/2006','dd/mm/yyyy'));
INSERT INTO ventas VALUES ('S6', 'P1', 'J3', 340, TO_DATE('10/02/2006','dd/mm/yyyy'));
INSERT INTO ventas VALUES ('S6', 'P1', 'J4', 340, TO_DATE('10/02/2006','dd/mm/yyyy'));
INSERT INTO ventas VALUES ('S7', 'P1', 'J1', 340, TO_DATE('10/02/2006','dd/mm/yyyy'));
INSERT INTO ventas VALUES ('S7', 'P1', 'J2', 340, TO_DATE('10/02/2006','dd/mm/yyyy'));
INSERT INTO ventas VALUES ('S7', 'P1', 'J3', 340, TO_DATE('10/02/2006','dd/mm/yyyy'));
INSERT INTO ventas VALUES ('S7', 'P1', 'J4', 340, TO_DATE('10/02/2006','dd/mm/yyyy'));

-- se comprueba el resultado
select * from ventas;