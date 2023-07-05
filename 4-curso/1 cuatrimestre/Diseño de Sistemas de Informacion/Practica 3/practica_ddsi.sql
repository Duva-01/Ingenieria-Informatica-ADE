drop table suministra;
drop table proveedor;
drop table asigna;
drop table PedidoConforma;
drop table productoalmacena;
drop table almacen;
drop table empleado;
drop table asignaR;
drop table metododetransporte;
drop table ruta;
drop table Cliente;


-- Creamos la tabla de clientes
CREATE TABLE Cliente(
    nombre varchar(20),
    apellidos varchar(40),
    telefono varchar(20),
    dni varchar(9) CONSTRAINT dni_clave_primaria PRIMARY KEY,
    tarjeta varchar(20),
    direccion varchar(60),
    correo varchar(20) CONSTRAINT correo_clave_candidata UNIQUE NOT NULL
    );
DESCRIBE cliente;
-- Insertamos las tuplas de clientes
INSERT INTO cliente VALUES ('juan','Molina Garcia','684848493','28394823G','','Martinez de la rosa 56','juanmg@gmail.com');
INSERT INTO cliente VALUES ('Nestor','Maceta Macetilla','764665788','78943659L','','Puentezuelas 12','nestormm@hotmail.es');
INSERT INTO cliente VALUES ('Lucia','Bonilla Perez','656874677','7852279D','perodista lucena 133','','luciabp@gmail.com');
INSERT INTO cliente VALUES ('Manolo','Ruiz Gomez','638572999','78482227Y','','Martinez de la rosa 2','manolorg@gmail.com');
INSERT INTO cliente VALUES ('Marta','Fuertes Gonzalez','649837468','28846380R','','morata 23','martafg@hotmail.com');

--TODO OK

--Creamos la tabla Almacen
create table Almacen(
    Identificador varchar(10) primary key,
    Nombre varchar(20),
    Direccion varchar(40),
    Tamanio int);
--Insertamos las tuplas de Almacen
insert into Almacen values ('000000000J', 'Almacen1', 'C/ Camino Ronda Nº 6', 1100);
insert into Almacen values ('000000000M', 'Almacen2', 'C/ Recogidas Nº 22', 1400);
insert into Almacen values ('000000000T', 'Almacen3', 'C/ Doctor Oloriz Nº 39', 990);
insert into Almacen values ('000000000S', 'Almacen4', 'C/ Padre Marcelino Nº 2', 1800);
insert into Almacen values ('000000000P', 'Almacen5', 'C/ San Agustin Nº 44', 3300);

--Creamos la tabla ProductoAlmacena
create table ProductoAlmacena(
    Nombre varchar(20),
    Referencia varchar(20) primary key,
    Stock int default 0,
    IdentificadorAlmacen varchar(10),
    foreign key (IdentificadorAlmacen) references Almacen(Identificador));
--Insertamos las tuplas de ProductoAlmacena
insert into ProductoAlmacena values ('Fidget Spinner', '000001X', 0, '000000000J');
insert into ProductoAlmacena values ('Peonza', '000002B', 0, '000000000M');
insert into ProductoAlmacena values ('BleyBlade', '000012Z', 0, '000000000T');
insert into ProductoAlmacena values ('Domino', '000011L', 0, '000000000J');
insert into ProductoAlmacena values ('Parchis', '000031W', 0, '000000000P');

--TODO OK

-- Creamos la tabla de pedido-conforma
CREATE TABLE PedidoConforma(
    cod_pedido varchar(20) CONSTRAINT cod_pedido_clave_primaria PRIMARY KEY,
    refrencia  varchar(20) CONSTRAINT referencia_clave_exerna REFERENCES ProductoAlmacena(referencia),
    cantidad INTEGER CONSTRAINT cantidad_mayor_que_0 CHECK (cantidad > 0),
    precio_total INTEGER CONSTRAINT precio_mayor_que_0 CHECK (precio_total > 0)
    );
DESCRIBE PedidoConforma;
--Insertamos las tuplas de PedidoConforma
insert into PedidoConforma values ('000001X', '000001X', 2, '6');
insert into PedidoConforma values ('000002B', '000002B', 4, '20');
insert into PedidoConforma values ('000012Z', '000012Z', 3, '60');
insert into PedidoConforma values ('000011L', '000011L', 1, '11');
insert into PedidoConforma values ('000031W', '000031W', 10, '100');

-- Creamos la tabla de Ruta
create table Ruta(
    Cod_Ruta varchar2(9),
    origen varchar2(20),
    destino varchar2(20),
    kilometraje int,
    primary key(Cod_Ruta)
);
--Insertamos las tuplas de Ruta
describe Ruta;
insert into Ruta values ('111111111','A','B',100);
insert into Ruta values ('222222222','B','C',150);
insert into Ruta values ('333333333','C','D',200);
insert into Ruta values ('444444444','D','E',250);
insert into Ruta values ('555555555','E','A',300);

-- Creamos la tabla de MetodoDeTransporte
create table MetodoDeTransporte(
    matricula varchar2(7),
    Tipo varchar2(20),
    Marca varchar2(10),
    Asignado int,
    subcontratacion int,
    primary key(matricula)
);
--Insertamos las tuplas de MetodoDeTransporte
describe MetodoDeTransporte;
insert into MetodoDeTransporte values ('1111abc','furgoneta','Toyota',0,0);
insert into MetodoDeTransporte values ('2222abc','coche','seat',0,0);
insert into MetodoDeTransporte values ('3333abc','moto','peugeot',0,0);
insert into MetodoDeTransporte values ('4444abc','furgoneta','Toyota',0,0);
insert into MetodoDeTransporte values ('5555abc','coche','nissan',0,0);

-- Creamos la tabla de AsignaR
create table AsignaR(
    matricula varchar2(7),
    Cod_Ruta varchar2(9),
    primary key(matricula), 
    foreign key(Cod_Ruta) references Ruta(Cod_Ruta), 
    foreign key(matricula) references MetodoDeTransporte(matricula)
);
--Insertamos las tuplas de AsignaR
describe AsignaR;
insert into AsignaR values ('1111abc','111111111');
insert into AsignaR values ('2222abc','222222222');
insert into AsignaR values ('3333abc','333333333');
insert into AsignaR values ('4444abc','444444444');
insert into AsignaR values ('5555abc','555555555');

--TODO OK

-- Creamos la tabla de Asigna
create table Asigna(
    matricula varchar2(7),
    Cod_pedido varchar2(9),
    primary key(matricula),
    foreign key(Cod_pedido) references PedidoConforma(Cod_pedido), 
    foreign key(matricula) references MetodoDeTransporte(matricula)
);
--Insertamos las tuplas de Asigna
describe Asigna;
insert into Asigna values ('1111abc','000001X');
insert into Asigna values ('2222abc','000002B');
insert into Asigna values ('3333abc','000012Z');
insert into Asigna values ('4444abc','000011L');
insert into Asigna values ('5555abc','000031W');

-- Creamos la tabla de Empleado
create table Empleado(
    Nombre varchar(20),
    Apellidos varchar(40),
    Telefono varchar(20),
    DNI varchar(9) primary key,
    CuentaBancaria varchar(20),
    Direccion varchar(60),
    NSegSoc varchar(20) unique not null,
    Puesto varchar(20),
    Turno varchar(20),
    Sueldo varchar(20)
);    
describe Empleado;
--Insertamos las tuplas de Empleado
insert into Empleado values ('Pedro', 'García', '111111111', '00000001X', '0','C/ Santa Amalia', '1', 'Reponedor', 'Mañanas', '1200');
insert into Empleado values ('Paco', 'Pérez', '222222222', '00000002X', '1','C/ Santa Clotilde', '2', 'Directivo', 'Tardes', '1800');
insert into Empleado values ('Manolo', 'Jiménez', '333333333', '00000003X', '2','C/ San Pedro', '3', 'Reponedor', 'Tardes', '2000');
insert into Empleado values ('Manoli', 'Jiménez', '444444444', '00000004X', '3','C/ Santo Tomás', '4', 'Reponedor', 'Mañanas', '1200');
insert into Empleado values ('Andrea', 'Alcántara', '612121212', '00000005X', '4','C/ Santa María', '5', 'Directiva', 'Empleado', '3000');

-- Creamos la tabla de Proveedor
CREATE TABLE Proveedor(
    nombre varchar(20),
    cif varchar(20),
    direccion varchar(20),
    PRIMARY KEY (cif)
);
DESCRIBE Proveedor;
--Insertamos las tuplas de Proveedor
INSERT INTO Proveedor VALUES('Cristal Mesina', 'B67657189', 'C/Azabache 3,Granada');
INSERT INTO Proveedor VALUES('Mesas Cristalinas', 'B13829940','C/Suspiro s/n, Padul');
INSERT INTO Proveedor VALUES('Lesla S.A.','S07948674','Gran Via 1, Granada');
INSERT INTO Proveedor VALUES('GRUNDASA','B07633001','C/Ancha 13, Guadix');
INSERT INTO Proveedor VALUES('Navideña SL','B86910650','Avd Dilar 4, Granada');

-- Creamos la tabla de suministra
CREATE TABLE suministra(
    cif REFERENCES Proveedor(cif),
    referencia REFERENCES ProductoAlmacena (referencia),
    PRIMARY KEY (referencia)
);
--Insertamos las tuplas de suminista
DESCRIBE suministra;
INSERT INTO suministra VALUES('B67657189','000001X');
INSERT INTO suministra VALUES('B13829940','000002B');
INSERT INTO suministra VALUES('S07948674','000012Z');
INSERT INTO suministra VALUES('B07633001','000011L');
INSERT INTO suministra VALUES('B86910650','000031W');

