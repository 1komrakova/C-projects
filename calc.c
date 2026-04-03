#include "calc.h"
#include <stdlib.h>

double** calc(double **a, double **b, int n, char symbol){
	double** result = (double**)malloc(n * sizeof(double*));
	int i0 = 0;
	for(i0; i0 < n; i0++){
		result[i0] = (double*)malloc(n * (sizeof(double)));
		int j0 = 0;
		for(j0; j0 < n; j0++){
		int k0 = 0;
		switch(symbol){
			case '+':
				result[i0][j0] = a[i0][j0]+b[i0][j0];
				break;
			case '-':
				result[i0][j0] = a[i0][j0] - b[i0][j0];
				break;
			case '*':
				for(k0; k0 < n; k0++){
				result[i0][j0] += a[i0][k0] * b[k0][j0];
				}
				break;

			}
		}
		}
	return result;
	}
