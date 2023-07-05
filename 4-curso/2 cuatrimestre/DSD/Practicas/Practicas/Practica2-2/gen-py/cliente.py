
from numpy import double
from calculadora.ttypes import Operacion
from calculadora import Calculadora

from thrift import Thrift
from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol

import numpy as np

transport = TSocket.TSocket("localhost", 9090)
transport = TTransport.TBufferedTransport(transport)
protocol = TBinaryProtocol.TBinaryProtocol(transport)

client = Calculadora.Client(protocol)

transport.open()

def OperacionBasica():
    
    operaciones_validas = ['+', '-', 'x', '/']

    operacion = Operacion(2, "_", 3)
    continuar = -1;

    while continuar != 0:

        operacion_str = input("Ingrese la operación en formato <a> <operador> <b>: ")
        operacion.a, operacion.operador, operacion.b = operacion_str.split()

    
        # Verificar que a y b sean números válidos
        try:
            operacion.a = double(operacion.a)
            operacion.b = double(operacion.b)
        except ValueError:
            print("a y b deben ser números válidos. Inténtalo de nuevo.")
            continue

        # Verificar que el operador sea válido
        if operacion.operador not in operaciones_validas:
            print("El operador no es válido. Inténtalo de nuevo.")
            continue
        else:
            continuar = 0

    return operacion



print("-- Hacemos ping al server -- \n")
client.ping()

print("\n -- Calculadora - David Martinez Diaz -- \n")

print("\n -- Posibles acciones a realizar: --")
print(" 1. Operacion basica:")
print(" 2. Operacion compleja:")
print(" 3. Operacion vectores:")
print(" 4. Operacion matrices:")
print(" 5. Exponente (Servidor llama a Servidor): ")


numero = -1

while (numero < 0 or numero > 5):
    numero = int(input("Por favor, ingrese una opcion: "))

    if (numero < 0 or numero > 5):
        print("Opcion no valida, ingrese una opcion valida.")

opcion = -1

if numero == 1:

    print("\n -- OPERACION BASICA -- \n")
    operacion = OperacionBasica()

    if operacion.operador == "+":
        resultado = client.suma(operacion.a, operacion.b)
        
    elif operacion.operador == "-":
        resultado = client.resta(operacion.a, operacion.b)

    elif operacion.operador == "x":
        resultado = client.multiplicacion(operacion.a, operacion.b)

    elif operacion.operador == "/":
        resultado = client.division(operacion.a, operacion.b)

    print("El resultado de la operacion " + str(operacion.a) + operacion.operador + str(operacion.b) + " es: " + str(resultado))

elif numero == 2:

    print("\n -- OPERACION COMPLEJA -- \n")

    continuar = -1
    lista_operaciones = []
    while(continuar != 2):

        operacion = OperacionBasica()
        lista_operaciones.append(operacion)

        print("1. Aniadir Operacion")
        print("2. Terminar")
        continuar = int(input("--> "))

    
    resultado = client.operacionCompuesta(lista_operaciones)

    print("\n -- RESULTADOS -- \n")

    pos = 0;
    for operacion in lista_operaciones:
        print("El resultado de la operacion " + str(operacion.a) + operacion.operador + str(operacion.b) + " es: " + str(resultado[pos]))
        pos = pos + 1

elif numero == 3:


    print("\n -- OPERACION VECTORES -- \n")

    print("Formato para introducir vectores: num1, num2, num3")

    # Declaracion de los vectores

    vector_str = input("Introduzca el vector 1 (separado por comas): ")
    vector_list = vector_str.split(",")
    vector1 = [double(num) for num in vector_list]

    vector_str = input("Introduzca el vector 2 (separado por comas): ")
    vector_list = vector_str.split(",")
    vector2 = [double(num) for num in vector_list]

    print("Operacion a realizar: ")
    print("1. Sumar")
    print("2. Restar")
    print("3. Multiplicacion Vectorial")
    print("4. Multiplicacion Escalar")

    opcion_vector = -1;

    while (opcion_vector < 0 or opcion_vector > 4):

        opcion_vector = int(input("--> "))

        if (numero < 0 or numero > 4):
            print("Opcion no valida, ingrese una opcion valida.")
    
    resultado = client.operacionVectores(vector1, vector2, opcion_vector)

    if opcion_vector == 1:
        print("El resultado de " + str(vector1) + " + " + str(vector2) + " = " + str(resultado))

    elif opcion_vector == 2:
        print("El resultado de " + str(vector1) + " - " + str(vector2) + " = " + str(resultado))

    elif opcion_vector == 3:
        print("El resultado de " + str(vector1) + " * " + str(vector2) + " = " + str(resultado))

    elif opcion_vector == 4:
        print("El resultado de " + str(vector1) + " x " + str(vector2) + " = " + str(resultado))  

elif numero == 4:

    # Pedir las matrices al usuario
    filas = int(input("Ingrese el número de filas: "))
    columnas = int(input("Ingrese el número de columnas: "))

    matrix1 = np.zeros((filas, columnas))
    matrix2 = np.zeros((filas, columnas))

    print("Ingrese la primera matriz:")
    for i in range(filas):
        for j in range(columnas):
            matrix1[i][j] = int(input())

    print("Ingrese la segunda matriz:")
    for i in range(filas):
        for j in range(columnas):
            matrix2[i][j] = int(input())

    print("Operacion a realizar: ")
    print("1. Sumar")
    print("2. Restar")
    print("3. Multiplicacion")

    opcion_matriz = -1;

    while (opcion_matriz < 0 or opcion_matriz > 3):

        opcion_matriz = int(input("--> "))

        if (numero < 0 or numero > 3):
            print("Opcion no valida, ingrese una opcion valida.")

    resultado = client.operacionMatrices(matrix1, matrix2, opcion_matriz)

    if opcion_matriz == 1:
        operador = "+"
    elif opcion_matriz == 2:
        operador = "-"
    elif opcion_matriz == 3:
        operador = "x"

    print("-- RESULTADO --")

    print(str(matrix1))
    print(operador)
    print(str(matrix2))
    print("=")
    print(np.matrix(resultado))

elif numero == 5:
    
    print("\n -- OPERACION EXPONENTE (SERVIDOR a SERVIDOR) -- \n")


    # Pedir la base y el exponente al usuario
    base = float(input("Ingrese la base: "))
    exponente = float(input("Ingrese el exponente: "))

    resultado = client.exponente(base,exponente)

    print("\n El resultado de " + str(base) + "^" + str(exponente) + " = " + str(resultado))


transport.close()
