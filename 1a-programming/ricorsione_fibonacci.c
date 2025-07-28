#include <stdio.h>

int fibonacci(int n);

int main() {
    int m;
    scanf("%d",&m);
    printf("%d-esima cifra della seq. di Fibonacci = %d",m,fibonacci(m));
}

int fibonacci(int n) {
    if (n<=1) {
        printf("%d ",n);
        return n;
    }
    else {
        int x = fibonacci(n-1)+fibonacci(n-2);
        printf("%d ",x);
        return x;
    }
}