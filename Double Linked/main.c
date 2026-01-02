#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node* createNode(int x) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = x;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

void printForward(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void printBackward(Node *head) {
    if (head == NULL) {
        printf("\n");
        return;
    }

    Node *temp = head;
    while (temp->next != NULL) temp = temp->next; // go to tail

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
void insertEnd(Node **head, int x) {
    Node *n = createNode(x);

    if (*head == NULL) {
        *head = n;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL) temp = temp->next;

    temp->next = n;
    n->prev = temp;
}
void insertAfter(Node **head, int afterValue, int newValue) {
    Node *temp = *head;

    while (temp != NULL && temp->data != afterValue)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value %d not found.\n", afterValue);
        return;
    }

    Node *n = createNode(newValue);

    n->next = temp->next;
    n->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = n;

    temp->next = n;
}
void deleteValue(Node **head, int x) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *temp = *head;

    while (temp != NULL && temp->data != x)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value %d not found.\n", x);
        return;
    }
    if (temp == *head) {
        *head = temp->next;
        if (*head != NULL) (*head)->prev = NULL;
    } else {
        temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
    }

    free(temp);
}
int main() {
    Node *head = NULL;
    int choice, x, a, b;

    while (1) {
        printf("\n1 Insert End\n2 Insert After\n3 Delete Value\n4 Print Forward\n5 Print Backward\n6 Exit\nChoose: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &x);
            insertEnd(&head, x);
        }
        else if (choice == 2) {
            printf("Insert newValue after afterValue (afterValue newValue): ");
            scanf("%d %d", &a, &b);
            insertAfter(&head, a, b);
        }
        else if (choice == 3) {
            printf("Enter value to delete: ");
            scanf("%d", &x);
            deleteValue(&head, x);
        }
        else if (choice == 4) {
            printForward(head);
        }
        else if (choice == 5) {
            printBackward(head);
        }
        else if (choice == 6) {
            break;
        }
        else {
            printf("Wrong choice!\n");
        }
    }

    return 0;
}
