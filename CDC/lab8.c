#include <stdio.h>
int main() {
    // Implicit Conversion
    int intVar = 10;
    float floatVar = 5.5;
    double doubleVar = 12.34;
    // Implicit conversion: int to float
    float result1 = intVar + floatVar; // intVar is implicitly converted to float
    printf("Implicit Conversion Result (int to float): %.2f\n", result1);
    // Implicit conversion: int to double
    double result2 = intVar + doubleVar; // intVar is implicitly converted to double
    printf("Implicit Conversion Result (int to double): %.2f\n", result2);
    // Explicit Conversion (Type Casting)
    float floatVar2 = 9.99;
    int intVar2;
    // Explicit conversion: float to int
    intVar2 = (int)floatVar2; // floatVar2 is explicitly cast to int
    printf("Explicit Conversion Result (float to int): %d\n", intVar2);
    // Explicit conversion: double to float
    float floatVar3;
    double doubleVar2 = 123.456;
    floatVar3 = (float)doubleVar2; // doubleVar2 is explicitly cast to float
    printf("Explicit Conversion Result (double to float): %.2f\n", floatVar3);
    // Example of conversion in calculations
    int num1 = 10;
    double num2 = 20.5;
    // Result is of type double due to implicit conversion of num1 to double
    double result3 = num1 / num2; 
    printf("Calculation Result with implicit conversion: %.2f\n", result3);
    // Result is explicitly cast to int
    int result4 = (int)(num1 / num2);
    printf("Calculation Result with explicit conversion to int: %d\n", result4);
    return 0;
}
