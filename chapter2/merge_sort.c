#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int a[], int p, int r, int q) {
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
    while (i < n1 && j < n2) {
        if (left[i] < right[j]) {
            a[k] = left[i];
            i++;
        } else {
            a[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        a[k] = left[i];
        k++;
        i++;
    }
    while (j < n2) {
        a[k] = right[j];
        k++;
        j++;
    }
}

void merge_sort(int a[], int p, int q) {
    if (p >= q) {
        return;
    }
    int r = p + ((q - p) >> 1);
    merge_sort(a, p, r);
    merge_sort(a, r + 1, q);
    merge(a, p, r, q);
}

int main() {
    srand(time(0));
    int a[1000000] = {0};
    for (int i = 0; i < 1000000; i++) {
        a[i] = rand() % 1000000 + 1;
    }
    int n = sizeof(a) / sizeof(a[0]);
    merge_sort(a, 0, n - 1);
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[n - 1]);
}
