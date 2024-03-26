#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

extern int asm_main(/*int a1, int a2, int a3, int a4, int a5, int a6, int a7*/);

int main(int argc, char* argv[]) {
	// Input: Scalar variable n (integer) contains the length of the vector
	// Vectors X and Y are both single-precision float.
	int vectorLength;
	int ans;
	printf("Input vector length: ");
	scanf("%d", &vectorLength);

	//int a1, a2, a3, a4, a5, a6, a7, x;

	// Y[i] = X[i-3] + X[i-2] + X[i-1] + X[i] + X[i+1] + X[i+2] + X[i+3]
	ans = asm_main();

	// Output: store result in vector Y.
	// Display the result of 1st ten elements of vector Y for all versions of kernel (i.e., C and x86-64).
	printf("%d + %d + %d + %d + %d + %d + %d = %d\n", a1, a2, a3, a4, a5, a6, a7, x);
	return 0;
}