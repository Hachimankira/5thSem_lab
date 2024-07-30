#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10

// Production rules and FIRST and FOLLOW sets
char production[MAX][MAX], first[MAX][MAX], follow[MAX][MAX];
int n;  // Number of production rules

// Function prototypes
void findFirst(int, int);
void findFollow(int);
void addToResultSet(char[], char);
bool isNonTerminal(char);

int main() {
    int i, j;
    char result[MAX];

    // Simple grammar
    strcpy(production[0], "S=AB");
    strcpy(production[1], "A=a");
    strcpy(production[2], "A=ε");
    strcpy(production[3], "B=b");
    n = 4;

    printf("Grammar:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", production[i]);
    }

    // Initialize the FIRST and FOLLOW sets
    for (i = 0; i < MAX; i++) {
        first[i][0] = '\0';
        follow[i][0] = '\0';
    }

    // Compute FIRST sets for each non-terminal
    for (i = 0; i < n; i++) {
        int nonTerminal = production[i][0] - 'A';
        findFirst(i, nonTerminal);
    }

    // Initialize FOLLOW(S) with '$'
    addToResultSet(follow['S' - 'A'], '$');

    // Compute FOLLOW sets for each non-terminal
    for (i = 0; i < n; i++) {
        findFollow(i);
    }

    // Print the FIRST sets
    for (i = 0; i < MAX; i++) {
        if (first[i][0] != '\0') {
            printf("FIRST(%c) = { ", 'A' + i);
            for (j = 0; first[i][j] != '\0'; j++) {
                printf("%c ", first[i][j]);
            }
            printf("}\n");
        }
    }

    // Print the FOLLOW sets
    for (i = 0; i < MAX; i++) {
        if (follow[i][0] != '\0') {
            printf("FOLLOW(%c) = { ", 'A' + i);
            for (j = 0; follow[i][j] != '\0'; j++) {
                printf("%c ", follow[i][j]);
            }
            printf("}\n");
        }
    }

    return 0;
}

void findFirst(int prodIndex, int nonTerminal) {
    int i, j;
    char result[MAX];

    // Iterate over each production rule
    for (i = 0; i < n; i++) {
        if (production[i][0] == (char)('A' + nonTerminal)) {
            // If epsilon is found, add it to the result
            if (production[i][2] == 'ε') {
                addToResultSet(first[nonTerminal], 'ε');
            } else {
                // Compute FIRST set of the string following the non-terminal
                for (j = 2; production[i][j] != '\0'; j++) {
                    if (isNonTerminal(production[i][j])) {
                        // If it's a non-terminal, recursively find its FIRST set
                        findFirst(i, production[i][j] - 'A');
                        // If epsilon is in the FIRST set of the non-terminal, continue to the next symbol
                        if (!strchr(first[production[i][j] - 'A'], 'ε')) {
                            break;
                        }
                    } else {
                        // If it's a terminal, add it to the result
                        addToResultSet(first[nonTerminal], production[i][j]);
                        break;
                    }
                }
            }
        }
    }
}

void findFollow(int prodIndex) {
    int i, j, k;
    char result[MAX];

    for (i = 0; i < n; i++) {
        for (j = 2; production[i][j] != '\0'; j++) {
            if (isNonTerminal(production[i][j])) {
                int nonTerminal = production[i][j] - 'A';

                // Check the rest of the string following the non-terminal
                for (k = j + 1; production[i][k] != '\0'; k++) {
                    if (isNonTerminal(production[i][k])) {
                        // Add FIRST of the following non-terminal
                        int nextNonTerminal = production[i][k] - 'A';
                        strcat(follow[nonTerminal], first[nextNonTerminal]);
                        if (!strchr(first[nextNonTerminal], 'ε')) {
                            break;
                        }
                    } else {
                        // Add terminal to FOLLOW set
                        addToResultSet(follow[nonTerminal], production[i][k]);
                        break;
                    }
                }

                // If we reached the end, add FOLLOW of the current non-terminal
                if (production[i][k] == '\0' && production[i][0] != production[i][j]) {
                    strcat(follow[nonTerminal], follow[production[i][0] - 'A']);
                }
            }
        }
    }
}

void addToResultSet(char result[], char c) {
    int i;
    for (i = 0; result[i] != '\0'; i++) {
        if (result[i] == c) {
            return;  // Avoid duplicates
        }
    }
    result[i] = c;
    result[i + 1] = '\0';
}

bool isNonTerminal(char c) {
    return c >= 'A' && c <= 'Z';
}
