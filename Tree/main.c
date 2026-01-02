#include <stdio.h>

#define MAX 100
#define EMPTY -1

int tree[MAX];

void initTree() {
    for (int i = 0; i < MAX; i++)
        tree[i] = EMPTY;
}

void setRoot(int x) {
    tree[0] = x;
}

void addLeft(int parentIndex, int x) {
    int L = 2 * parentIndex + 1;

    if (parentIndex < 0 || parentIndex >= MAX) {
        printf("Wrong parent index!\n");
        return;
    }
    if (tree[parentIndex] == EMPTY) {
        printf("Parent is empty!\n");
        return;
    }
    if (L >= MAX) {
        printf("Out of range!\n");
        return;
    }

    tree[L] = x;
}

void addRight(int parentIndex, int x) {
    int R = 2 * parentIndex + 2;

    if (parentIndex < 0 || parentIndex >= MAX) {
        printf("Wrong parent index!\n");
        return;
    }
    if (tree[parentIndex] == EMPTY) {
        printf("Parent is empty!\n");
        return;
    }
    if (R >= MAX) {
        printf("Out of range!\n");
        return;
    }

    tree[R] = x;
}

void preorder(int i) {
    if (i >= MAX || tree[i] == EMPTY) return;
    printf("%d ", tree[i]);
    preorder(2*i + 1);
    preorder(2*i + 2);
}

void inorder(int i) {
    if (i >= MAX || tree[i] == EMPTY) return;
    inorder(2*i + 1);
    printf("%d ", tree[i]);
    inorder(2*i + 2);
}

void postorder(int i) {
    if (i >= MAX || tree[i] == EMPTY) return;
    postorder(2*i + 1);
    postorder(2*i + 2);
    printf("%d ", tree[i]);
}

// طباعة الشجرة كـ Levels (عشان تشوف الشكل)
void printLevels(int lastIndex) {
    int level = 0;
    int i = 0;
    int nodes = 1;

    while (i <= lastIndex) {
        printf("Level %d: ", level);

        for (int k = 0; k < nodes && i <= lastIndex; k++, i++) {
            if (tree[i] == EMPTY) printf("- ");
            else printf("%d ", tree[i]);
        }

        printf("\n");
        level++;
        nodes *= 2;
    }
}

int main() {
    int choice, x, p, lastIndex = 0;

    initTree();

    while (1) {
        printf("\n1 Set Root\n2 Add Left\n3 Add Right\n4 Preorder\n5 Inorder\n6 Postorder\n7 Print Levels\n8 Exit\nChoose: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Root value: ");
            scanf("%d", &x);
            setRoot(x);
            lastIndex = 0;
        }
        else if (choice == 2) {
            printf("Parent index and value: ");
            scanf("%d %d", &p, &x);
            addLeft(p, x);

            int L = 2*p + 1;
            if (L > lastIndex && L < MAX) lastIndex = L;
        }
        else if (choice == 3) {
            printf("Parent index and value: ");
            scanf("%d %d", &p, &x);
            addRight(p, x);

            int R = 2*p + 2;
            if (R > lastIndex && R < MAX) lastIndex = R;
        }
        else if (choice == 4) {
            printf("Preorder: ");
            preorder(0);
            printf("\n");
        }
        else if (choice == 5) {
            printf("Inorder: ");
            inorder(0);
            printf("\n");
        }
        else if (choice == 6) {
            printf("Postorder: ");
            postorder(0);
            printf("\n");
        }
        else if (choice == 7) {
            printLevels(lastIndex);
        }
        else if (choice == 8) {
            break;
        }
        else {
            printf("Wrong choice!\n");
        }
    }

    return 0;
}
