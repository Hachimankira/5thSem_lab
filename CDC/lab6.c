#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char input[MAX];
int inputPointer = 0;
int tempCount = 0;

// Function prototypes
void parse();
void expression();
void term();
void factor();
char* newTemp();

int main() {
    printf("Enter the input expression (e.g., a+b*c): ");
    scanf("%s", input);

    printf("\nGenerating intermediate code (Three-Address Code) for the expression:\n");
    parse();

    return 0;
}

void parse() {
    expression();
    if (input[inputPointer] == '\0') {
        printf("Intermediate code generation completed successfully.\n");
    } else {
        printf("Error: Unexpected input '%c'.\n", input[inputPointer]);
    }
}

void expression() {
    char* temp;
    term();
    while (input[inputPointer] == '+') {
        inputPointer++;
        temp = newTemp();
        printf("%s = t%d + ", temp, tempCount - 1);
        term();
        printf("t%d\n", tempCount - 1);
    }
}

void term() {
    char* temp;
    factor();
    while (input[inputPointer] == '*') {
        inputPointer++;
        temp = newTemp();
        printf("%s = t%d * ", temp, tempCount - 1);
        factor();
        printf("t%d\n", tempCount - 1);
    }
}

void factor() {
    if (input[inputPointer] >= 'a' && input[inputPointer] <= 'z') {
        printf("LOAD %c\n", input[inputPointer]);
        inputPointer++;
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

char* newTemp() {
    static char temp[10];
    snprintf(temp, sizeof(temp), "t%d", ++tempCount);
    return temp;
}
