#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fusionar_arreglos_ordenados(int* nums1, int m, int* nums2, int n, int* fusionado) {
    int i = 0, j = 0, k = 0;

    while (i < m && j < n) {
        if (nums1[i] < nums2[j]) {
            fusionado[k++] = nums1[i++];
        } else {
            fusionado[k++] = nums2[j++];
        }
    }

    while (i < m) {
        fusionado[k++] = nums1[i++];
    }

    while (j < n) {
        fusionado[k++] = nums2[j++];
    }
}

double encontrar_mediana(int* fusionado, int longitud_total) {
    if (longitud_total % 2 == 0) {
        return (fusionado[longitud_total / 2 - 1] + fusionado[longitud_total / 2]) / 2.0;
    } else {
        return fusionado[longitud_total / 2];
    }
}

double encontrar_mediana_de_arreglos_ordenados(int* nums1, int m, int* nums2, int n) {
    int* fusionado = (int*)malloc((m + n) * sizeof(int));


    fusionar_arreglos_ordenados(nums1, m, nums2, n, fusionado);

    double mediana = encontrar_mediana(fusionado, m + n);


    printf("Arreglo fusionado: ");
    for (int i = 0; i < m + n; i++) {
        printf("%d ", fusionado[i]);
    }
    printf("\n");

    printf("Mediana: %.5f\n", mediana);

    free(fusionado);

    return mediana;

}

int main() {
    int nums1[] = {1, 3, 5, 6, 8, 9};
    int nums2[] = {2, 10, 11, 12, 15};
    int max_valor1, max_valor2,size_1,size_2;
    double tiempo;
    clock_t start, end;

    start = clock();

      size_1 = sizeof(nums1);
      size_2 = sizeof(nums2);
        max_valor1 = size_1 / 4;
        max_valor2 = size_2 / 4;

    printf("Tamanio Arreglos \n 1.:%d\n 2.:%d\n",size_1,size_2);
        printf("Elementos dentro del arreglos \n 1.:%d\n 2.:%d\n\n",max_valor1,max_valor2);


    encontrar_mediana_de_arreglos_ordenados(nums1, max_valor1, nums2, max_valor2);

      end = clock();
      tiempo = ((double)(end - start));

          printf("Tiempo de ejecucion: %.2fms\n",tiempo );
    return 0;
}
