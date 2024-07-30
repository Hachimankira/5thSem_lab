#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10

char production[MAX][MAX], first[MAX][MAX];
int n; 

void findFirst(int, int);
void addToResultSet(char[], char);

int main() {
    int i, j;
    char result[MAX];

    strcpy(production[0], "S=AB");
    strcpy(production[1], "A=a");
    strcpy(production[2], "A=ε");
    strcpy(production[3], "B=b");
    n = 4;

    printf("Grammar:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", production[i]);
    }

    for (i = 0; i < n; i++) {
        first[i][0] = '\0';
    }

    for (i = 0; i < n; i++) {
        int nonTerminal = production[i][0] - 'A';
        findFirst(i, nonTerminal);
    }

    for (i = 0; i < n; i++) {
        if (first[i][0] != '\0') {
            printf("FIRST(%c) = { ", production[i][0]);
            for (j = 0; first[i][j] != '\0'; j++) {
                printf("%c ", first[i][j]);
            }
            printf("}\n");
        }
    }

    return 0;
}

void findFirst(int prodIndex, int nonTerminal) {
    int i, j;
    char result[MAX];

    for (i = 0; i < n; i++) {
        if (production[i][0] == (char)('A' + nonTerminal)) {
            if (production[i][2] == 'ε') {
                addToResultSet(first[nonTerminal], 'ε');
            } else {
                for (j = 2; production[i][j] != '\0'; j++) {
                    if (production[i][j] >= 'A' && production[i][j] <= 'Z') {
                        findFirst(i, production[i][j] - 'A');
                        if (!strchr(first[production[i][j] - 'A'], 'ε')) {
                            break;
                        }
                    } else {
                        addToResultSet(first[nonTerminal], production[i][j]);
                        break;
                    }
                }
            }
        }
    }
}

void addToResultSet(char result[], char c) {
    int i;
    for (i = 0; result[i] != '\0'; i++) {
        if (result[i] == c) {
            return; 
        }
    }
    result[i] = c;
    result[i + 1] = '\0';
}
