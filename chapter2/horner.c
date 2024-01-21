#include <stdio.h>

int horner(int a[], int n, int x) {
    int p = 0;
    for (int i = n - 1; i >= 0; i--) {
        p = a[i] + x * p;
    }
    return p;
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a) / sizeof(a[0]);
    int res = horner(a, n, 10);
    printf("%d\n", res);
}
