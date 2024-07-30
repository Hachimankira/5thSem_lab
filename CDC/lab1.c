#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_TOKEN_LEN 100

typedef enum {
    KEYWORD,
    IDENTIFIER,
    NUMBER,
    OPERATOR,
    DELIMITER,
    UNKNOWN
} TokenType;

typedef struct {
    char value[MAX_TOKEN_LEN];
    TokenType type;
} Token;

const char *keywords[] = {
    "int", "float", "return", "if", "else", "while", "for", "do", "void", "char", "double", "long",
    NULL
};

const char *operators[] = {
    "+", "-", "*", "/", "=", "==", "!=", "<", ">", "<=", ">=", "&&", "||", "!", "&", "|", "^", "%",
    NULL
};

const char *delimiters[] = {
    "(", ")", "{", "}", "[", "]", ";", ",", NULL
};

int isKeyword(const char *str);
int isOperator(const char *str);
int isDelimiter(const char *str);
void addToken(Token tokens[], int *tokenCount, const char *value, TokenType type);

int main() {
    char input[] = "int main() { int a = 10; int b = 20; int sum = a+b ; return sum; }";
    Token tokens[100];
    int tokenCount = 0;

    int i = 0;
    while (i < strlen(input)) {
        if (isspace(input[i])) {
            i++;
            continue;
        }

        char buffer[MAX_TOKEN_LEN] = {0};
        int j = 0;

        if (isalpha(input[i])) {
            while (isalnum(input[i])) {
                buffer[j++] = input[i++];
            }
            buffer[j] = '\0';
            if (isKeyword(buffer)) {
                addToken(tokens, &tokenCount, buffer, KEYWORD);
            } else {
                addToken(tokens, &tokenCount, buffer, IDENTIFIER);
            }
        } else if (isdigit(input[i])) {
            while (isdigit(input[i]) || input[i] == '.') {
                buffer[j++] = input[i++];
            }
            buffer[j] = '\0';
            addToken(tokens, &tokenCount, buffer, NUMBER);
        } else if (isOperator((char[]){input[i], '\0'})) {
            buffer[j++] = input[i++];
            buffer[j] = '\0';
            addToken(tokens, &tokenCount, buffer, OPERATOR);
        } else if (isDelimiter((char[]){input[i], '\0'})) {
            buffer[j++] = input[i++];
            buffer[j] = '\0';
            addToken(tokens, &tokenCount, buffer, DELIMITER);
        } else {
            buffer[j++] = input[i++];
            buffer[j] = '\0';
            addToken(tokens, &tokenCount, buffer, UNKNOWN);
        }
    }
    for (i = 0; i < tokenCount; i++) {
        printf("Token: %-10s \n", tokens[i].value);
    }

    return 0;
}

int isKeyword(const char *str) {
    for (int i = 0; keywords[i] != NULL; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int isOperator(const char *str) {
    for (int i = 0; operators[i] != NULL; i++) {
        if (strcmp(str, operators[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int isDelimiter(const char *str) {
    for (int i = 0; delimiters[i] != NULL; i++) {
        if (strcmp(str, delimiters[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void addToken(Token tokens[], int *tokenCount, const char *value, TokenType type) {
    strcpy(tokens[*tokenCount].value, value);
    (*tokenCount)++;
}
