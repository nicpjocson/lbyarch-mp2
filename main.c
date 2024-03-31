#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

extern void asm_main(int n, float* X, float* Y);

void stencil_kernel(int n, float* X, float* Y) {
    for (int i = 3; i < n - 3; i++) {
        float sum = 0;
        for (int j = i - 3; j <= i + 3; j++) {
            sum += X[j];
        }
        Y[i - 3] = sum;
    }
    printf("\n");
}

void printOutput(float* Y, int n) {
    int val = n - 6;
    if (val > 10) {
        val = 10;
    }

    for (int i = 0; i < val; i++) {
        printf("%.2f ", Y[i]);
    }
    printf("\n");
}

float* allocateMemory(int n) {
    float* arr = (float*)calloc(n, sizeof(float));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return arr;
}

int main(int argc, char* argv[]) {
    clock_t begin, end;
    int n; // Vector Length
    float* X, * Y;

    do {
        printf("Input vector length: ");
        if (scanf_s("%d", &n) != 1) {
            printf("Error reading input.\n");
            exit(1);
        }
        if (n <= 6) {
            printf("Error: Input must be greater than 6.\n");
        }
    } while (n <= 6);
    X = allocateMemory(n);
    Y = allocateMemory(n);

    for (int i = 0; i < n; i++) {
        X[i] = i + 1.2f; // Initialize X
    }

    // C version
    begin = clock();
    stencil_kernel(n, X, Y);
    end = clock();
    double elapsed = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("C version Output: ");
    printOutput(Y, n);
    printf("\nC Version Execution Time: %.4lf seconds", elapsed);
    
    // Assembly Version
    free(Y);
    Y = allocateMemory(n);

    printf("\n\nx86-64 Version Output: ");
    begin = clock();
;   asm_main(n, X, Y);
    end = clock();
    elapsed = (double)(end - begin) / CLOCKS_PER_SEC;

    printOutput(Y, n);
    printf("\nx86-64Version Execution Time: %.4lf seconds", elapsed);

    free(X);
    free(Y);

    return 0;
}
