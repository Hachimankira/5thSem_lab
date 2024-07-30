#include <stdio.h>
#include <string.h>
int main() {
    char com[30];
    int i;
    int isComment = 0;  // Flag to determine if the input is a comment
    printf("\nEnter comment: ");
    fgets(com, sizeof(com), stdin);
    // Remove newline character if fgets reads it
    size_t len = strlen(com);
    if (len > 0 && com[len - 1] == '\n') {
        com[len - 1] = '\0';
    }
    // Check for single-line comment
    if (com[0] == '/' && com[1] == '/') {
        printf("\nIt is a single-line comment");
        isComment = 1;
    }
    // Check for multi-line comment
    else if (com[0] == '/' && com[1] == '*') {
        for (i = 2; i < len - 1; i++) {
            if (com[i] == '*' && com[i + 1] == '/') {
                printf("\nIt is a multi-line comment");
                isComment = 1;
                break;
            }
        }
        if (isComment == 0) {
            printf("\nIt is not a multi-line comment");
        }
    } else {
        printf("\nIt is not a comment");
    }
    return 0;
}
