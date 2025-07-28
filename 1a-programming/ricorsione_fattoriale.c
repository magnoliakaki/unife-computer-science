#include <stdio.h>

int somma (int n);

int main() {
    int n = 10;
    printf("somma = %d",somma(n));
}

int somma (int n) {
    if (n==1) return 1;
    else {
        int x = n+somma(n-1);
        printf("%d ",x);
        return x;
    }
}