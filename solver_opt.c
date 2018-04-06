/*
 * Tema 2 ASC
 * 2018 Spring
 * Catalin Olaru / Vlad Spoiala
 */
#include "utils.h"

/*
 * Add your optimized implementation here
 */
double *my_solver(int N, double *A)
{
	int l, c, i;
	double *result = malloc(sizeof(double) * 2 * N * N);


	for (l = 0; l < N; ++l) {

		double *orig_pa = &A[2 * l * N];
		for (c = l; c < N; ++c) {
			double *pa = orig_pa;
			double *pb = &A[2 * c * N];
			register double real_sum = 0;
			register double imag_sum = 0;
			for (i = 0; i < N; ++i) {

				double a1 = *pa;
				double a2 = *pb;
				pa++;
				pb++;
				double a3 = *pa;
				double a4 = *pb;

				real_sum += a1 * a2 - a3 * a4;
				imag_sum += a1 * a3 + a2 * a4;
				pa++;
				pb++;
			}
			result[2 * (l * N + c)] = real_sum;
			result[2 * (l * N + c) + 1] = imag_sum;
			result[2 * (c * N + l)] = real_sum;
			result[2 * (c * N + l) + 1] = imag_sum;
		}

	}

	return result;
}