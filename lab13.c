#include <stdio.h>
#include <setjmp.h>

jmp_buf buffer;

void fib_sum(int n, long long a, long long b, long long *sum) {
    if (n <= 0) {
        longjmp(buffer, 1);
    }
    printf("%lld; ", a);
    *sum += a;
    fib_sum(n - 1, b, a + b, sum);
}

int main() {
    int n, ret;
    long long sum;

    printf("enter n: ");
    scanf("%d", &n);

    ret = setjmp(buffer);
    if (ret == 0) {
        sum = 0;
        printf("fibonacci: ");
        fib_sum(n, 1, 1, &sum);
    } else {
        printf("\nsum = %lld\n", sum);
    }

    return 0;
}
