#include <stdio.h>
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

int main() {
	//matrix input//
	int n;
	printf("enter the arrive size: ");
	scanf("%d", &n);
	
	double** a = (double**)malloc(n * sizeof(double*));
	printf("enter the first matrix: \n");
	int i = 0;
	for(i; i < n; i++){
		a[i] = (double*)malloc(n * sizeof(double));
		int j = 0;
		for(j; j < n; j++){
			printf("%d element of %d string: ", j+1, i+1);
			scanf("%lf", &a[i][j]);
		}
	}
	double** b = (double**)malloc(n * sizeof(double*));
	printf("enter the second matrix: \n");
	int i1 = 0;
	for(i1; i1 < n; i1++){
		b[i1] = (double*)malloc(n * sizeof(double));
		int j1 = 0;
		for(j1; j1 < n; j1++){
			printf("%d element of %d string: ", j1+1, i1+1);
			scanf("%lf", &b[i1][j1]);
		}
	}

 char symbol;
	printf("Choose -, + or *: ");
	scanf(" %c", &symbol);

	double** c = calc(a, b, n, symbol);
	printf("result:\n");
	int k = 0;
	for(k; k < n; k++){
		int l = 0;
		for(l; l < n; l++){
			printf("%.0lf ", c[k][l]);
		}
	printf("\n");
	}

	int i2 = 0;
	for(i2; i2 < n; i2++){
		free(a[i2]);
		free(b[i2]);
		free(c[i2]);
	}
	free(a);
	free(b);
	free(c);
	return 0;
}
