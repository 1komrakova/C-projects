#include <stdio.h>
#include <locale.h>
int main(){
//1 задание//
  setlocale(LC_ALL, "Russian");
  system("chcp 1251");
  int x = 1;
  while(x){
	  int N = 2;
	  int i, j;
	  double arr[N][N];
	  for(i = 0; i < N; i++){
	  	for(j = 0; j < N; j++){
			printf("¬ведите %d элемент %d строки: ", j+1, i+1);
			scanf("%lf", &arr[i][j]);
			}
		}
		for(i = 0; i < N; i ++){
			for(j = 0 ; j < N; j++){
				printf("%.0lf ", arr[i][j]);
			}
		printf("\n");
		}
		double sum1 = 0, sum2 = 0;
		for(i = 0; i < N; i++){
			sum1 += arr[i][i];
			sum2 += arr[i][N-1-i];
		}
		printf("Cумма главной диагонали: %.1lf\n —умма побочной диагонали: %.1lf\n", sum1, sum2);
	int a = 0;
	printf("¬ведите 1 чтобы продолжить или 0 чтобы завершить: ");
	scanf("%d", &a);
	if(a != 1) x = 0;
	else x = 1;
	}
//2 задание//
  int y = 1;
  int n = 3;
  while(y){
	int i0, j0, k0;
	int arr1[n][n];
	int squarearr1[n][n];
	
	for(i0 = 0; i0 < n; i0++){
		for(j0 = 0; j0 < n; j0++){
			printf("¬ведите %d элемент %d строки: ", j0+1, i0+1);
			scanf("%d", &arr1[i0][j0]);
		}
	}
	for(i0 = 0; i0 < n; i0++){
		for(j0 = 0; j0 < n; j0++){
			squarearr1[i0][j0] = 0;
			}
	}
    for(i0 = 0; i0 < n; i0++){
  		for(j0 = 0; j0 < n; j0++){
			for(k0 = 0; k0 < n; k0++){
  			squarearr1[i0][j0] += arr1[i0][k0]*arr1[k0][j0];
		  	}
		}
    }
    for(i0 = 0; i0 < n; i0++){
    	for(j0 = 0; j0 < n; j0++){
        printf("%d ", squarearr1[i0][j0]);
    }
    printf("\n");
  	}
	int b = 0;
	printf("¬ведите 1 чтобы продолжить или 0 чтобы завершить программу: ");
	scanf("%d", &b);
	if(b == 1) y = 1;
	else y = 0;
   }
  return 0;
}
