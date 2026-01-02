#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int x) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = x;
    n->next = NULL;
    return n;
}

// traversal
void printList(Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

void insertEnd(Node **head, int x) {
    Node *n = createNode(x);

    if (*head == NULL) {
        *head = n;
        n->next = n;   // points to itself
        return;
    }

    Node *temp = *head;
    while (temp->next != *head)
        temp = temp->next;

    temp->next = n;
    n->next = *head;
}

void insertAfter(Node *head, int afterValue, int newValue) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *temp = head;
    do {
        if (temp->data == afterValue) {
            Node *n = createNode(newValue);
            n->next = temp->next;
            temp->next = n;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Value %d not found\n", afterValue);
}

void deleteValue(Node **head, int x) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *curr = *head;
    Node *prev = NULL;

    if (curr->next == curr && curr->data == x) {
        free(curr);
        *head = NULL;
        return;
    }

    do {
        if (curr->data == x) break;
        prev = curr;
        curr = curr->next;
    } while (curr != *head);
    if (curr->data != x) {
        printf("Value %d not found\n", x);
        return;
    }
    if (curr == *head) {
        // find last node
        Node *last = *head;
        while (last->next != *head)
            last = last->next;

        *head = curr->next;
        last->next = *head;
        free(curr);
    }
    else {
        prev->next = curr->next;
        free(curr);
    }
}

int main() {
    Node *head = NULL;
    int choice, x, a, b;

    while (1) {
        printf("\n1 Insert End\n2 Insert After\n3 Delete Value\n4 Print\n5 Exit\nChoose: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &x);
            insertEnd(&head, x);
        }
        else if (choice == 2) {
            printf("afterValue newValue: ");
            scanf("%d %d", &a, &b);
            insertAfter(head, a, b);
        }
        else if (choice == 3) {
            printf("Enter value to delete: ");
            scanf("%d", &x);
            deleteValue(&head, x);
        }
        else if (choice == 4) {
            printList(head);
        }
        else if (choice == 5) {
            break;
        }
        else {
            printf("Wrong choice\n");
        }
    }

    return 0;
}
