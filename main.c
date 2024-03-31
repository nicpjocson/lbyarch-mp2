#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

extern void asm_main(float* X, float* Y, int n);

void stencil_kernel(float* X, float* Y, int n) {
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
    n -= 6;
    if (n > 10) {
        n = 10;
    }

    for (int i = 0; i < n; i++) {
        printf("%.2lf ", Y[i]);
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
    time_t begin, end;
    int n; // Vector Length
    float* X, * Y;

    // TODO: Add minimum vector length > 6
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

    // Initialize
    for (int i = 0; i < n; i++) {
        X[i] = i + 1.0f;
    }

    // C version
    time(&begin);
    stencil_kernel(X, Y, n);
    time(&end);
    time_t elapsed = end - begin;

    // Output: store result in vector Y.
    // Display the result of 1st ten elements of vector Y for all versions of kernel (i.e., C and x86-64).
    printf("C version Output: ");
    printOutput(Y, n);
    printf("\nC Version Execution Time: %lld seconds", elapsed);
    // Assembly Version
    free(Y);
    Y = allocateMemory(n);

    printf("\n\nx86-64 Version Output: ");
    time(&begin);
;   asm_main(X, Y, n);
    time(&end);
    elapsed = end - begin;

    printOutput(Y, n);
    printf("\nx86-64Version Execution Time: %lld seconds", elapsed);

    free(X);
    free(Y);

    return 0;
}
