#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

extern int asm_main(/*int a1, int a2, int a3, int a4, int a5, int a6, int a7*/);

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
    if (n > 10) {
        n = 10;
    }

    for (int i = 0; i < n; i++) {
        if (Y[i] != 0) {
            printf("%.2lf ", Y[i]);
        }
    }
}

float* allocateMemory(int n) {
    float* arr = (float*)malloc(n * sizeof(float));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return arr;
}

int main(int argc, char* argv[]) {
    int n; // Vector Length
    float* X, * Y;

    printf("Input vector length: ");
    scanf("%d", &n);

    X = allocateMemory(n);
    Y = allocateMemory(n);

    // Initialize
    for (int i = 0; i < n; i++) {
        X[i] = i + 1;
    }

    // C version
    stencil_kernel(X, Y, n);

    // Output: store result in vector Y.
    // Display the result of 1st ten elements of vector Y for all versions of kernel (i.e., C and x86-64).
    printf("C version Output: ");
    printOutput(Y, n);

    // Assembly Version
    free(Y);
    Y = allocateMemory(n);
;   // ans = asm_main();
    printf("x86 - 64 Version Output: ");
    printOutput(Y, n);

    free(X);
    free(Y);

    return 0;
}
