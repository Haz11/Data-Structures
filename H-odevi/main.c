#include <stdio.h>

void hanoi(int n, char from, char aux, char to) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }

    hanoi(n - 1, from, to, aux);                 // move n-1 to auxiliary
    printf("Move disk %d from %c to %c\n", n, from, to);  // move biggest disk
    hanoi(n - 1, aux, from, to);                 // move n-1 to destination
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);

    hanoi(n, 'A', 'B', 'C');

    return 0;
}
