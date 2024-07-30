#include <stdio.h>
#include <ctype.h>
int main() {
    char a[10];
    int flag = 0, i = 0;  // Initialize flag to 0, and start i from 0
    printf("\nEnter an identifier: ");
    fgets(a, sizeof(a), stdin); // Use fgets instead of gets
    // Remove the newline character if present
    size_t len = strlen(a);
    if (len > 0 && a[len - 1] == '\n') {
        a[len - 1] = '\0';
    }
    // Check if the first character is valid
    if (isalpha(a[0]) || a[0] == '_') {
        flag = 1;  // Assume valid until proven otherwise
        // Check remaining characters
        while (a[i] != '\0') {
            if (!isdigit(a[i]) && !isalpha(a[i]) && a[i] != '_') {
                flag = 0;  // Invalid character found
                break;
            }
            i++;
        }
    } else {
        printf("\nNot a valid identifier");
        return 0; // Exit the program early if the first character is invalid
    }
    // Output result based on the flag
    if (flag == 1) {
        printf("\nValid identifier\n");
    } else {
        printf("\nNot a valid identifier\n");
    }
    return 0;
}
