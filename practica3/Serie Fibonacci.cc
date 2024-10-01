#include <stdio.h>
#include <time.h>


int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    clock_t start, end;
    double tiempo;

    printf("Serie de Fibonacci:\n");



    for (int i = 0; i < 50; i++) {
    		start = clock();
				printf("Elemento %d: %d\n",i ,fibonacci(i));


        end = clock();

				tiempo = ((double)(end - start));
				printf("%.2f ms\n",tiempo );
    }

    end = clock();
}
