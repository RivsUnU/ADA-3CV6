#include <stdio.h>
#include <time.h>

int knapsack(int W, int wt[], int val[], int n) {
    if (n == 0 || W == 0) return 0;
    if (wt[n-1] > W) return knapsack(W, wt, val, n-1);
    else {
        int include = val[n-1] + knapsack(W - wt[n-1], wt, val, n-1);
        int exclude = knapsack(W, wt, val, n-1);
        return (include > exclude) ? include : exclude;
    }
}

int main() {
    int val[20] = {10, 40, 30, 50, 35, 60, 20, 70, 80, 90, 55, 25, 65, 85, 15, 75, 95, 45, 35, 50};
    int wt[20] = {15, 10, 5, 8, 12, 25, 10, 20, 18, 22, 30, 5, 14, 27, 10, 12, 28, 6, 7, 24};
    int n = 20;

    clock_t start, end;
    double time_taken;

    start = clock();
    int maxProfitW50 = knapsack(50, wt, val, n);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Maxima Ganancia for W=50: %d, Time: %f seconds\n", maxProfitW50, time_taken);

    start = clock();
    int maxProfitW80 = knapsack(80, wt, val, n);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Maxima Ganancia for W=80: %d, Time: %f seconds\n", maxProfitW80, time_taken);

    return 0;
}
