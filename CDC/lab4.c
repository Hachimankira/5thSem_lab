#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX];
int top = -1;
char input[MAX];
int inputPointer = 0;

// Grammar rules
const char* rules[] = {
    "E+E", 
    "E*E", 
    "(E)", 
    "id"
};

// Function prototypes
void push(char);
void pop();
void shift();
void reduce();
void displayStack();
void displayInput();

int main() {
    printf("Enter the input string (e.g., id+id*id): ");
    scanf("%s", input);

    printf("\nParsing the input string using Shift Reduce Parser:\n");
    while (1) {
        displayStack();
        displayInput();

        if (input[inputPointer] != '\0') {
            shift();
        }

        reduce();

        // If the stack contains only E and input is exhausted
        if (stack[0] == 'E' && top == 0 && input[inputPointer] == '\0') {
            printf("\nInput string successfully parsed.\n");
            break;
        }
    }

    return 0;
}

void push(char symbol) {
    if (top < MAX - 1) {
        stack[++top] = symbol;
    } else {
        printf("Stack overflow\n");
        exit(1);
    }
}

void pop() {
    if (top >= 0) {
        top--;
    } else {
        printf("Stack underflow\n");
        exit(1);
    }
}

void shift() {
    printf("Shift: %c\n", input[inputPointer]);
    push(input[inputPointer]);
    inputPointer++;
}

void reduce() {
    int i;
    for (i = 0; i < sizeof(rules) / sizeof(rules[0]); i++) {
        int len = strlen(rules[i]);

        // Check if the top of the stack matches the rule
        if (top >= len - 1) {
            int match = 1;
            for (int j = 0; j < len; j++) {
                if (stack[top - len + 1 + j] != rules[i][j]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                printf("Reduce: %s -> E\n", rules[i]);
                for (int j = 0; j < len; j++) {
                    pop();
                }
                push('E');
                return;
            }
        }
    }
}

void displayStack() {
    printf("Stack: ");
    for (int i = 0; i <= top; i++) {
        printf("%c", stack[i]);
    }
    printf("\n");
}

void displayInput() {
    printf("Input: %s\n", input + inputPointer);
}
