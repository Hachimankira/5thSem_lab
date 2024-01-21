#include <stdio.h>
#include <string.h>
int min(int a, int b, int c) {
    return (a < b) ? (a < c ? a : c) : (b < c ? b : c);
}
int editDistance(char *str1, char *str2, int m, int n) {
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i][j - 1],  // Insert
                                   dp[i - 1][j],  // Remove
                                   dp[i - 1][j - 1]); // Replace
        }
    }
    return dp[m][n];
}
int main() {
    char str1[100], str2[100];
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);
    int m = strlen(str1), n = strlen(str2);
    printf("Minimum Edit Distance: %d\n", editDistance(str1, str2, m, n));
    return 0;
}