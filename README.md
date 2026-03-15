#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <math.h>
int main()
{
  char *locale = setlocale(LC_ALL, "Russian");
  bool con = true;
  while(con){
    double a, b, c, disc;
    printf("Введите коэффициенты уравнения: \n");
    scanf("%lf %lf %lf", &a, &b, &c);
    disc = pow(b,2)-(4*a*c);
    if(disc == 0){
      double x = (-b)/(2*a);
      printf("Корень уравнения: %.2lf \n", x);
    }
    else if(disc < 0){
      printf("Корней не существует\n");
    }
    else{
      double x1, x2;
      x1 = (-b+sqrt(disc))/(2*a);
      x2 = (-b-sqrt(disc))/(2*a);
      printf("Корни уравнения равны: %.2lf, %.2lf \n", x1, x2);
    }
    int answer;
    printf("Если хотите продолжить введите 1 или 0 чтобы завершить програму: \n ");
    scanf("%d", &answer);
    if(answer==1){
    con = true;
    }
    else{
      con = false;
    }
  }
  return 0;
}
