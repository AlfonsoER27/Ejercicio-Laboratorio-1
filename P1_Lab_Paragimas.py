import random
import time

# Función para generar arreglo
def generar_arreglo(n, min, max):
    return [random.randint(min, max) for _ in range(n)]

# Función para ordenar un arreglo
def ordenar(arreglo):
    return sorted(arreglo)

# Función de búsqueda secuencial
def busqueda_secuencial(arr, numero):
    for i in range(len(arr)):
        if arr[i] == numero:
            return "El numero {} se encuentra en la posición {}".format(numero, i+1) 
    return "El numero: {} no se encuentra en la lista".format(numero)

def calcular_tiempo_ejecucion():
    start_time = time.time()

    arreglo_original = generar_arreglo(10, 1, 100)
    arreglo_ordenado = ordenar(arreglo_original)

    # Función para imprimir los arreglos
    print("Arreglo original:", arreglo_original)
    print("Arreglo ordenado:", arreglo_ordenado)

    numero = int(input("Ingrese el número a buscar: "))
    position_original = busqueda_secuencial(arreglo_original, numero)
    position_ordenado = busqueda_secuencial(arreglo_ordenado, numero)

    # Imprimir los resultados de la busqueda secuencial
    print("Para la lista original:\n", position_original)
    print("Para la lista ordenada:\n", position_ordenado)

    end_time = time.time()
    execution_time = end_time - start_time
    print(f"Tiempo de ejecución del programa: {execution_time} segundos")

calcular_tiempo_ejecucion()
