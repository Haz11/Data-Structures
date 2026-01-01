#include <stdio.h>
#include <ctype.h>
#include <string.h>

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

int main() {
    char infix[200];
    char stack[200];
    int top = -1;

    printf("Enter infix: ");
    fgets(infix, sizeof(infix), stdin);

    printf("Postfix: ");

    for (int i = 0; i < (int)strlen(infix); i++) {
        char ch = infix[i];

        if (ch == ' ' || ch == '\n' || ch == '\t') continue;

        if (isalnum((unsigned char)ch)) {
            printf("%c ", ch);
        }
        else if (ch == '(') {
            stack[++top] = ch;
        }
        else if (ch == ')') {
            while (top >= 0 && stack[top] != '(') {
                printf("%c ", stack[top--]);
            }
            if (top >= 0 && stack[top] == '(') top--; // remove '('
        }
        else if (isOperator(ch)) {
            while (top >= 0 && isOperator(stack[top])) {
                char opTop = stack[top];

                if (precedence(opTop) > precedence(ch) ||
                   (precedence(opTop) == precedence(ch) && ch != '^')) {
                    printf("%c ", stack[top--]);
                } else {
                    break;
                }
            }
            stack[++top] = ch;
        }
        else {
            printf("\nInvalid character: %c\n", ch);
            return 1;
        }
    }

    // pop remaining operators
    while (top >= 0) {
        if (stack[top] != '(') printf("%c ", stack[top]);
        top--;
    }

    printf("\n");
    return 0;
}
