import random

def generar_mapa(filas, columnas, probabilidad_obstaculo=0.1):
    with open("mapa.txt", "w") as f:
        f.write(str(filas) + "\n")
        f.write(str(columnas) + "\n")
        for i in range(filas):
            for j in range(columnas):
                if random.random() < probabilidad_obstaculo:
                    f.write("-1\t")
                else:
                    f.write("0\t")
            f.write("\n")

generar_mapa(20, 20)