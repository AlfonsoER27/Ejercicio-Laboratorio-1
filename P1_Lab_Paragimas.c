#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para generar arreglo
int *generar_arreglo(int n, int min, int max) {
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Error: No se pudo asignar memoria para el arreglo\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % (max - min + 1)) + min;
    }
    return arr;
}

// Función para ordenar un arreglo
void ordenar(int *arreglo, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arreglo[j] > arreglo[j + 1]) {
                int temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
            }
        }
    }
}

// Función de búsqueda secuencial
int busqueda_secuencial(int *arr, int n, int numero) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == numero) {
            return i;
        }
    }
    return -1;
}

void calcular_tiempo_ejecucion() {
    clock_t start_time = clock();

    srand(time(NULL));

    int *arreglo_original = generar_arreglo(10, 1, 100);
    int *arreglo_ordenado = (int *)malloc(10 * sizeof(int));
    if (arreglo_ordenado == NULL) {
        printf("Error: No se pudo asignar memoria para el arreglo\n");
        exit(1);
    }
    for (int i = 0; i < 10; i++) {
        arreglo_ordenado[i] = arreglo_original[i];
    }
    ordenar(arreglo_ordenado, 10);

    // Imprimir los arreglos
    printf("Arreglo original:");
    for (int i = 0; i < 10; i++) {
        printf(" %d", arreglo_original[i]);
    }
    printf("\nArreglo ordenado:");
    for (int i = 0; i < 10; i++) {
        printf(" %d", arreglo_ordenado[i]);
    }
    printf("\n");

    int numero;
    printf("Ingrese el número a buscar: ");
    scanf("%d", &numero);

    int position_original = busqueda_secuencial(arreglo_original, 10, numero);
    int position_ordenado = busqueda_secuencial(arreglo_ordenado, 10, numero);

    // Imprimir los resultados de la búsqueda secuencial
    if (position_original != -1) {
        printf("Para la lista original: El numero %d se encuentra en la posición %d\n", numero, position_original + 1);
    } else {
        printf("Para la lista original: El numero %d no se encuentra en la lista\n", numero);
    }
    if (position_ordenado != -1) {
        printf("Para la lista ordenada: El numero %d se encuentra en la posición %d\n", numero, position_ordenado + 1);
    } else {
        printf("Para la lista ordenada: El numero %d no se encuentra en la lista\n", numero);
    }

    clock_t end_time = clock();
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecución del programa: %f segundos\n", execution_time);
}

int main() {
    calcular_tiempo_ejecucion();
    return 0;
}
