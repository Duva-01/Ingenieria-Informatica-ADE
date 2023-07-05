INSERT INTO equipos  VALUES('REC001', 'Agustinos FC', 'Granada', 'David',TO_DATE('11/05/2022','dd/mm/yyyy'));
INSERT INTO equipos  VALUES('GRA002','Granates FC','Madrid','Juan',TO_DATE('23/04/2022','dd/mm/yyyy'));
INSERT INTO equipos  VALUES('OVI003','Plasencia FC','Plasencia','Salvador',TO_DATE('12/05/2022','dd/mm/yyyy'));
INSERT INTO equipos  VALUES('BAR004','Barcelona FC','Barcelona','Evangelina',TO_DATE('20/04/2022','dd/mm/yyyy'));
                           
DESCRIBE equipos;

SELECT * FROM equipos;

INSERT ALL 
    INTO encuentros (elocal,evisitante,fecha,plocal,pvisitante)  VALUES('BAR004','GRA002',TO_DATE('20/07/2022','dd/mm/yyyy'),10,42)
    INTO encuentros (elocal,evisitante,fecha,plocal,pvisitante)  VALUES('BAR004','OVI003',TO_DATE('11/08/2022','dd/mm/yyyy'),2,33)
    INTO encuentros (elocal,evisitante,fecha,plocal,pvisitante)  VALUES('BAR004','REC001',TO_DATE('06/08/2022','dd/mm/yyyy'),34,33)
    INTO encuentros (elocal,evisitante,fecha,plocal,pvisitante)  VALUES('GRA002','REC001',TO_DATE('23/07/2022','dd/mm/yyyy'),12,56)
    INTO encuentros (elocal,evisitante,fecha,plocal,pvisitante)  VALUES('GRA002','OVI003',TO_DATE('27/06/2022','dd/mm/yyyy'),79,132)
    INTO encuentros (elocal,evisitante,fecha,plocal,pvisitante)  VALUES('REC001','OVI003',TO_DATE('30/06/2022','dd/mm/yyyy'),21,21)
    INTO encuentros (elocal,evisitante,fecha,plocal,pvisitante)  VALUES('REC001','GRA002',TO_DATE('15/08/2022','dd/mm/yyyy'),25,22)
    INTO encuentros (elocal,evisitante,fecha,plocal,pvisitante)  VALUES('REC001','BAR004',TO_DATE('04/09/2022','dd/mm/yyyy'),20,17)
    INTO encuentros (elocal,evisitante,fecha,plocal,pvisitante)  VALUES('OVI003','REC001',TO_DATE('21/09/2022','dd/mm/yyyy'),14,43)
    INTO encuentros (elocal,evisitante,fecha,plocal,pvisitante)  VALUES('OVI003','BAR004',TO_DATE('20/09/2022','dd/mm/yyyy'),87,67)
SELECT * FROM DUAL;

INSERT ALL
    INTO jugadores (codj,code,nombrej)   VALUES('0000','REC001','Ximo')
    INTO jugadores (codj,code,nombrej)   VALUES('0001','REC001','Dario')
    INTO jugadores (codj,code,nombrej)   VALUES('0002','REC001','Alvaro')
    INTO jugadores (codj,code,nombrej)   VALUES('0003','REC001','Duva')
    INTO jugadores (codj,code,nombrej)   VALUES('0004','REC001','Pablo')
    INTO jugadores (codj,code,nombrej)   VALUES('0005','GRA002','Blanes')
    INTO jugadores (codj,code,nombrej)   VALUES('0006','GRA002','Antonio')
    INTO jugadores (codj,code,nombrej)   VALUES('0007','GRA002','Pepe')
    INTO jugadores (codj,code,nombrej)   VALUES('0008','GRA002','Carlos')
    INTO jugadores (codj,code,nombrej)   VALUES('0009','GRA002','Joaquin')
    INTO jugadores (codj,code,nombrej)   VALUES('0010','OVI003','Alba')
    INTO jugadores (codj,code,nombrej)   VALUES('0011','OVI003','Maria')
    INTO jugadores (codj,code,nombrej)   VALUES('0012','OVI003','Cristina')
    INTO jugadores (codj,code,nombrej)   VALUES('0013','OVI003','Marta')
    INTO jugadores (codj,code,nombrej)   VALUES('0014','OVI003','Alejandra')
    INTO jugadores (codj,code,nombrej)   VALUES('0015','BAR004','Teresa')
    INTO jugadores (codj,code,nombrej)   VALUES('0016','BAR004','Daniel')
    INTO jugadores (codj,code,nombrej)   VALUES('0017','BAR004','Pablo')
    INTO jugadores (codj,code,nombrej)   VALUES('0018','BAR004','Tomas')
    INTO jugadores (codj,code,nombrej)   VALUES('0019','BAR004','Fran')
SELECT * FROM DUAL;