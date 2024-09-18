//Nombre: Rivero Amezquita Esteban
//Analisis y diseño de algoritmos 3CV6
//Version: 1.0.0 
//Fecha: 17/Septiembre/2024

#include <stdio.h>

// Función para eliminar duplicados en el sitio
int Duplicados(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int k = 1;  // Índice para almacenar el siguiente elemento único

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {  // Comparar con el elemento anterior
            nums[k] = nums[i];
            k++;
        }
    }

    return k;  // Retornar el número de elementos únicos
}

// Función para imprimir el arreglo
void printArray(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main() {
    int nums[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int size = sizeof(nums) / sizeof(nums[0]);

    // Eliminar duplicados
    int k = Duplicados(nums, size);

    // Imprimir los elementos únicos
    printf("Elementos unicos: ");
    printArray(nums, k);

    // Imprimir el resto del arreglo (eliminados y su posición original)
    printf("Resto del arreglo: ");
    for (int i = k; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
