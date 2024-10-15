#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
    double x;
    double y;
} Punto;

double generarNumeroAleatorio(double min, double max) {
    return min + (rand() / (double) RAND_MAX) * (max - min);
}

void generarPuntosAleatorios(Punto* puntos, int cantidad, double min, double max) {
    for (int i = 0; i < cantidad; i++) {
        puntos[i].x = generarNumeroAleatorio(min, max);
        puntos[i].y = generarNumeroAleatorio(min, max);
    }
}

double calcularDistancia(Punto p1, Punto p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void encontrarParMasCercano(Punto* puntos, int cantidad, Punto* p1, Punto* p2, double* minDistancia) {
    *minDistancia = calcularDistancia(puntos[0], puntos[1]);
    *p1 = puntos[0];
    *p2 = puntos[1];

    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = i + 1; j < cantidad; j++) {
            double distancia = calcularDistancia(puntos[i], puntos[j]);
            if (distancia < *minDistancia) {
                *minDistancia = distancia;
                *p1 = puntos[i];
                *p2 = puntos[j];
            }
        }
    }
}

int main() {
    int cantidadPuntos;
    double minRango, maxRango;

    printf("Ingrese la cantidad de puntos a generar: ");
    scanf("%d", &cantidadPuntos);
    
    printf("Ingrese el rango mínimo y máximo para generar los puntos (por ejemplo -10 10): ");
    scanf("%lf %lf", &minRango, &maxRango);

    Punto* puntos = (Punto*)malloc(cantidadPuntos * sizeof(Punto));
    if (puntos == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    srand(time(NULL));

    generarPuntosAleatorios(puntos, cantidadPuntos, minRango, maxRango);

    printf("Puntos generados:\n");
    for (int i = 0; i < cantidadPuntos; i++) {
        printf("(%.2lf, %.2lf)\n", puntos[i].x, puntos[i].y);
    }

    Punto punto1, punto2;
    double minDistancia;
    
    clock_t start = clock();
    encontrarParMasCercano(puntos, cantidadPuntos, &punto1, &punto2, &minDistancia);
    clock_t end = clock();

    printf("\nEl par de puntos más cercano es: (%.2lf, %.2lf) y (%.2lf, %.2lf)\n", punto1.x, punto1.y, punto2.x, punto2.y);
    printf("La distancia mínima es: %.6lf\n", minDistancia);

    double tiempoEjecucion = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecución: %.6f segundos\n", tiempoEjecucion);

    free(puntos);

    return 0;
}
