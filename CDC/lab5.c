#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char stack[30];
int top = -1;
// Push character onto stack
void push(char c) {
    if (top < 29) {
        top++;
        stack[top] = c;
    } else {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
}
// Pop character from stack
char pop() {
    if (top != -1) {
        char c = stack[top];
        top--;
        return c;
    }
    return 'x'; // Return 'x' if stack is empty
}
// Print current stack status
void printstat() {
    printf("\n\t\t\t $");
    for (int i = 0; i <= top; i++) {
        printf("%c", stack[i]);
    }
}
int main() {
    char s1[20];
    int l;
    printf("\n\n\t\t LR PARSING");
    printf("\n\t\t ENTER THE EXPRESSION: ");
    scanf("%s", s1);
    l = strlen(s1);
    printf("\n\t\t ");
    for (int i = 0; i < l; i++) {
        if (s1[i] == 'i' && s1[i + 1] == 'd') {
            s1[i] = ' ';
            s1[i + 1] = 'E';
            printstat();
            printf(" id");
            push('E');
            printstat();
            i++; // Skip next character
        } else if (s1[i] == '+' || s1[i] == '-' || s1[i] == '*' || s1[i] == '/' || s1[i] == 'd') {
            push(s1[i]);
            printstat();
        }
    }
    // Print stack status
    printstat();
    // Reduction process
    while (top != -1) {
        char ch1 = pop();
        if (ch1 == 'x') {
            printf("\n\t\t\t $");
            break;
        }
        if (ch1 == '+' || ch1 == '/' || ch1 == '*' || ch1 == '-') {
            char ch3 = pop();
            if (ch3 != 'E') {
                printf("error\n");
                exit(EXIT_FAILURE);
            } else {
                push('E');
                printstat();
            }
        }
    }

    return 0;
}
