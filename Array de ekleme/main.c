#include <stdio.h>

#define MAX 100

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int insertAt(int a[], int n, int index, int value) {
    if (n >= MAX) {
        printf("Array full!\n");
        return n;
    }
    if (index < 0 || index > n) {
        printf("Invalid index!\n");
        return n;
    }

    for (int i = n; i > index; i--) {
        a[i] = a[i - 1];
    }
    a[index] = value;
    return n + 1;
}

int deleteAt(int a[], int n, int index) {
    if (n <= 0) {
        printf("Array empty!\n");
        return n;
    }
    if (index < 0 || index >= n) {
        printf("Invalid index!\n");
        return n;
    }

    for (int i = index; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    return n - 1;
}

int main() {
    int a[MAX];
    int n, choice, index, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n < 0 || n > MAX) {
        printf("Invalid n!\n");
        return 1;
    }

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    while (1) {
        printf("\n1 Print\n2 Insert\n3 Delete\n4 Exit\nChoose: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printArray(a, n);
        }
        else if (choice == 2) {
            printf("Enter index and value: ");
            scanf("%d %d", &index, &value);
            n = insertAt(a, n, index, value);
        }
        else if (choice == 3) {
            printf("Enter index to delete: ");
            scanf("%d", &index);
            n = deleteAt(a, n, index);
        }
        else if (choice == 4) {
            break;
        }
        else {
            printf("Wrong choice!\n");
        }
    }

    return 0;
}
