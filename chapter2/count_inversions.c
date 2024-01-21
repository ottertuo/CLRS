#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int merge(int a[], int p, int r, int q) {
    int n1 = r - p + 1;
    int n2 = q - r;
    int left[n1];
    int right[n2];
    for (int i = 0; i < n1; i++) {
        left[i] = a[p + i];
    }
    for (int i = 0; i < n2; i++) {
        right[i] = a[r + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = p;
    int count = 0;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            a[k] = left[i];
            i++;
            k++;
        } else {
            a[k] = right[j];
            count += n1 - i;
            j++;
            k++;
        }
    }
    while (i < n1) {
        a[k] = left[i];
        i++;
        k++;
    }
    while (j < n2) {
        a[k] = right[j];
        j++;
        k++;
    }
    return count;
}

int count_inversions(int a[], int p, int q) {
    if (p >= q) {
        return 0;
    }
    int r = p + ((q - p) >> 1);
    int c1 = count_inversions(a, p, r);
    int c2 = count_inversions(a, r + 1, q);
    int c3 = merge(a, p, r, q);
    return c1 + c2 + c3;
}

int naive_count_inversions(int a[], int p, int q) {
    int count = 0;
    for (int i = p; i < q; i++) {
        for (int j = i + 1; j <= q; j++) {
            if (a[i] > a[j]) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    srand(time(0));
    int a[10000] = {0};
    for (int i = 0; i < 10000; i++) {
        a[i] = rand();
    }
    int n = sizeof(a) / sizeof(a[0]);
    printf("%d\n", naive_count_inversions(a, 0, n - 1));
    printf("%d\n", count_inversions(a, 0, n - 1));
}
