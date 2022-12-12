#include <stdlib.h>
#include <stdio.h>

int max(int num[], int n, int *max_length) {
    if (n == 1) {
        return 1;
    }
    int res = 0;
    int maxEnding = 1;
    for (int i = 1; i < n; i++) {
        res = max(num, i, max_length);
        if (num[i - 1] < num[n - 1] && res + 1 > maxEnding) {
            maxEnding = res + 1;
        }
    }
    if (*max_length < maxEnding) {
        *max_length = maxEnding;
    }
    return maxEnding;
}

int increase(int num[], int length) {
    int maximum = 1;
    max(num, length, &maximum);
    return maximum;
}


void displayArray(int num[], int length) {
    for (int i = 0; i < length; i++) {
        printf(" %3d", num[i]);
    }
    printf("\n");
}


int main() {
    int num1[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int length1 = 8;
    printf("Array: ");
    displayArray(num1, length1);
    printf("Length= %d\n", increase(num1, length1));

    int num2[] = {10, 24, 2, 7, 3, 30, 20, 5, 7, 9, 21, 14, 21, 8, 22};
    int length2 = 15;
    printf("Array: ");
    displayArray(num2, length2);
    printf("Length= %d\n", increase(num2, length2));
}
