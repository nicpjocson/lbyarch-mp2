#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

extern int asm_main(/*int a1, int a2, int a3, int a4, int a5, int a6, int a7*/);
void stencil_kernel(float* X, float* Y, int n);
void printOutput(float* Y, int n);

int main(int argc, char* argv[]) {
	// Input: Scalar variable n (integer) contains the length of the vector
	// Vectors X and Y are both single-precision float.
    int n;
    float ans;
    float* X, * Y;

    printf("Input vector length: ");
    scanf("%d", &n);

    X = (float*)malloc(n * sizeof(float));
    Y = (float*)malloc(n * sizeof(float));

    if (X == NULL || Y == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        X[i] = i + 1;
    }

    // Y[i] = X[i-3] + X[i-2] + X[i-1] + X[i] + X[i+1] + X[i+2] + X[i+3]
    ans = asm_main();
    stencil_kernel(X, Y, n);
    // Output: store result in vector Y.
    // Display the result of 1st ten elements of vector Y for all versions of kernel (i.e., C and x86-64).
    printOutput(Y, n); // C
    return 0;
}

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