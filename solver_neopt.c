/*
 * Tema 2 ASC
 * 2018 Spring
 * Catalin Olaru / Vlad Spoiala
 */
#include "utils.h"

/*
 * Add your unoptimized implementation here
 */

void print_my2_matrix(double *aux, int N)
{
	int i, j;

	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			if (j == N - 1)
				printf("%f+%f*i", aux[2 * (i * N + j)], aux[2 * (i * N + j) + 1]);
			else
				printf("%f+%f*i, ", aux[2 * (i * N + j)], aux[2 * (i * N + j) + 1]);
		}
		printf(";\n");
	}
}

double *my_solver(int N, double *A)
{
	int l, c, i;
//	print_my2_matrix(A, N);
	double *result = calloc(2 * N * N, sizeof(double));
	for (l = 0; l < N; ++l) {
		for (c = l; c < N; ++c) {
//			result[2 * (l * N + c)] = 0;
//			result[2 * (l * N + c) + 1] = 0;
//			result[2 * (c * N + l)] = 0;
//			result[2 * (c * N + l) + 1] = 0;

			for (i = 0; i < N; ++i) {
				result[2 * (l * N + c)] +=
					A[2 * (l * N + i)] * A[2 * (c * N + i)]
						- A[2 * (l * N + i) + 1] * A[2 * (c * N + i) + 1];

				result[2 * (l * N + c) + 1] +=
					A[2 * (l * N + i)] * A[2 * (c * N + i) + 1]
						+ A[2 * (c * N + i)] * A[2 * (l * N + i) + 1];
			}
		}

	}

//	printf("\n");
//
//	print_my2_matrix(result, N);

	return result;
}
