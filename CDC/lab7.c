#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char input[MAX];
int inputPointer = 0;
int tempCount = 0;

// Function prototypes
void parse();
void generateCode(char *operation, char *operand1, char *operand2);
void expression();
void term();
void factor();

int main() {
    printf("Enter the input expression (e.g., id+id*id): ");
    scanf("%s", input);

    printf("\nGenerating assembly-like code for the expression:\n");
    parse();

    return 0;
}

void parse() {
    expression();
    if (input[inputPointer] == '\0') {
        printf("Code generation completed successfully.\n");
    } else {
        printf("Error: Unexpected input '%c'.\n", input[inputPointer]);
    }
}

void expression() {
    term();
    while (input[inputPointer] == '+') {
        char temp[10];
        snprintf(temp, sizeof(temp), "t%d", ++tempCount);
        generateCode("ADD", temp, "id");
        inputPointer++;
        term();
    }
}

void term() {
    factor();
    while (input[inputPointer] == '*') {
        char temp[10];
        snprintf(temp, sizeof(temp), "t%d", ++tempCount);
        generateCode("MUL", temp, "id");
        inputPointer++;
        factor();
    }
}

void factor() {
    if (input[inputPointer] == 'i' && input[inputPointer + 1] == 'd') {
        printf("LOAD id\n");
        inputPointer += 2;
    } else if (input[inputPointer] == '(') {
        inputPointer++;
        expression();
        if (input[inputPointer] == ')') {
            inputPointer++;
        } else {
            printf("Error: Unmatched parenthesis\n");
            exit(1);
        }
    } else {
        printf("Error: Unexpected input '%c'\n", input[inputPointer]);
        exit(1);
    }
}

void generateCode(char *operation, char *operand1, char *operand2) {
    printf("%s %s, %s\n", operation, operand1, operand2);
}
