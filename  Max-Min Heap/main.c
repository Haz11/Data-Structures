#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;
int isMin = 1;   // 1 = Min Heap , 0 = Max Heap

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

int better(int x, int y) {
    if (isMin) return x < y;   // Min: الأصغر فوق
    else       return x > y;   // Max: الأكبر فوق
}

void insert(int x) {
    int i = size;
    heap[size++] = x;

    while (i > 0) {
        int p = (i - 1) / 2;
        if (better(heap[i], heap[p])) {
            swap(&heap[i], &heap[p]);
            i = p;
        } else {
            break;
        }
    }
}

int extractRoot() {
    if (size == 0) return -1;

    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;

    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int best = i;

        if (left < size && better(heap[left], heap[best]))
            best = left;

        if (right < size && better(heap[right], heap[best]))
            best = right;

        if (best != i) {
            swap(&heap[i], &heap[best]);
            i = best;
        } else {
            break;
        }
    }

    return root;
}

void printHeap() {
    if (size == 0) {
        printf("Heap is empty\n");
        return;
    }
    for (int i = 0; i < size; i++) printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    int t, ch, x;

    printf("1 Min Heap, 2 Max Heap: ");
    scanf("%d", &t);
    if (t == 2) isMin = 0;  // إذا اختار Max

    while (1) {
        printf("\n1 Insert\n2 Extract Root\n3 Print\n4 Exit\nChoose: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Value: ");
            scanf("%d", &x);
            insert(x);
        }
        else if (ch == 2) {
            x = extractRoot();
            if (x == -1) printf("Heap is empty\n");
            else printf("Removed root = %d\n", x);
        }
        else if (ch == 3) {
            printHeap();
        }
        else if (ch == 4) {
            break;
        }
        else {
            printf("Wrong choice\n");
        }
    }

    return 0;
}
