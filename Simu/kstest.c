#include <stdio.h>

double dplus(double num[], double d1[], int length, double n) {
    // Compute D+ values
    for (int i = 0; i < length; i++) {
        d1[i] = ((i + 1) / n) - num[i];
    }
    // Find the maximum D+ value
    double d1max = d1[0];
    for (int i = 0; i < length; i++) {
        if (d1max <= d1[i]) {
            d1max = d1[i];
        }
    }
    printf("D+ = %f\n", d1max);
    return d1max;
}

double dminus(double num[], double d2[], int length, double n) {
    // Compute D- values
    for (int i = 0; i < length; i++) {
        d2[i] = (num[i] - (i) / n);
    }
    // Find the maximum D- value
    double d2max = d2[0];
    for (int i = 0; i < length; i++) {
        if (d2max <= d2[i]) {
            d2max = d2[i];
        }
    }
    printf("D- = %f\n", d2max);
    return d2max;
}

void kst(double num[], int length) {
    // Sort the array in ascending order
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (num[i] > num[j]) {
                double temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }

    double d1[length];
    double d2[length];
    double n = (double) length;

    // Calculate D+ and D- values
    double d1max = dplus(num, d1, length, n);
    double d2max = dminus(num, d2, length, n);

    // Determine the maximum of D+ and D-
    double d;
    if (d1max > d2max) {
        d = d1max;
        printf("D = %f\n", d);
    } else {
        d = d2max;
        printf("D = %f\n", d);
    }
}

int main() {
    printf("Kolmogorov Test\n");
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    double num[n];
    printf("Enter Data:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &num[i]);
    }

    // Perform the Kolmogorov-Smirnov test
    kst(num, n);

    return 0;
}
