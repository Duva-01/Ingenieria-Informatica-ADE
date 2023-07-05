import glob
import sys

from calculadora import Calculadora

from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol
from thrift.server import TServer

import logging

import numpy as np

logging.basicConfig(level=logging.DEBUG)


class CalculadoraHandler:
    def __init__(self):
        self.log = {}

    def ping(self):
        print("me han hecho ping()")

    def suma(self, n1, n2):
        print("sumando " + str(n1) + " con " + str(n2))
        return n1 + n2

    def resta(self, n1, n2):
        print("restando " + str(n1) + " con " + str(n2))
        return n1 - n2
    
    def multiplicacion(self, n1, n2):
        print("multiplicando " + str(n1) + " con " + str(n2))
        return n1 * n2

    def division(self, n1, n2):

        print("dividiendo " + str(n1) + " con " + str(n2))

        if n2 == 0:
            print("No se puede dividir entre 0 se devuelve un 0");
            return 0
        
        return n1 / n2
    
    def operacionCompuesta(self, lista):
        
        lista_operaciones = []

        for operacion in lista:
            
            if(operacion.operador == "+"):
                resultado = operacion.a + operacion.b

            elif operacion.operador == "-":
                resultado = operacion.a - operacion.b

            elif operacion.operador == "x":
                resultado = operacion.a * operacion.b

            elif operacion.operador == "/":

                if operacion.b == 0:
                    resultado = 0
                else:
                    resultado = operacion.a / operacion.b

            lista_operaciones.append(resultado)

        return lista_operaciones
    
    def operacionVectores(self, vec1, vec2, opcion):
    
        vec_resultado = []

        vector1 = np.array(vec1)
        vector2 = np.array(vec2)

        if opcion == 1:
            vec_resultado = np.add(vector1,vector2)

        elif opcion == 2:
            vec_resultado = np.subtract(vector1, vector2)
        
        elif opcion == 3:
            vec_resultado = np.cross(vector1, vector2)

        elif opcion == 4:
            vec_resultado.append(np.dot(vector1, vector2))

        return vec_resultado

    def operacionMatrices(self, matriz1, matriz2, operacion):

        
        if operacion == 1:
            mat_resultado = np.add(matriz1, matriz2)
        elif operacion == 2:
            mat_resultado = np.subtract(matriz1, matriz2)
        elif operacion == 3:
            mat_resultado = np.matmul(matriz1, matriz2)

        return mat_resultado
    
    def exponente(self, n1, exp):
    
        transport = TSocket.TSocket("localhost", 9091)
        transport = TTransport.TBufferedTransport(transport)
        protocol = TBinaryProtocol.TBinaryProtocol(transport)

        server = Calculadora.Client(protocol)
        
        transport.open()
        
        print("Llamando al servidor auxiliar...")
        resultado = server.exponente(n1,exp)

        transport.close()

        return resultado
        

if __name__ == "__main__":
    handler = CalculadoraHandler()
    processor = Calculadora.Processor(handler)
    transport = TSocket.TServerSocket(host="127.0.0.1", port=9090)
    tfactory = TTransport.TBufferedTransportFactory()
    pfactory = TBinaryProtocol.TBinaryProtocolFactory()

    server = TServer.TSimpleServer(processor, transport, tfactory, pfactory)

    print("iniciando servidor...")
    server.serve()
    print("fin")
