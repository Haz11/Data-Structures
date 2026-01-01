#include <stdio.h>

int main(void) {
    int r, c;
    int a[50][50];
    int i, j, count = 0;

    printf("Enter rows and cols (max 50 50): ");
    if (scanf("%d %d", &r, &c) != 2) {
        printf("Input error!\n");
        return 1;
    }

    if (r <= 0 || c <= 0 || r > 50 || c > 50) {
        printf("Invalid size! Must be between 1 and 50.\n");
        return 1;
    }

    printf("Enter %d numbers:\n", r * c);
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (scanf("%d", &a[i][j]) != 1) {
                printf("Input error at (%d,%d)\n", i, j);
                return 1;
            }
            if (a[i][j] != 0) count++;
        }
    }

    printf("\nSparse (Triplet) form:\n");
    printf("%d %d %d\n", r, c, count);

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (a[i][j] != 0) {
                printf("%d %d %d\n", i, j, a[i][j]);
            }
        }
    }

    return 0;
}
