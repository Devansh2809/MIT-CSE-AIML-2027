#include <stdio.h>


int gcd(int a, int b) {
    int smaller = (a < b) ? a : b;  
    int gcd_result = 1;
    int opcount=0;
    for (int i = smaller; i >= 1; i--) {opcount++;
        if (a % i == 0 && b % i == 0) {
            gcd_result = i;
            break; 
        }
    }
    printf("Opcount=%d\n",opcount);
    return gcd_result;
}

int main() {
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    int result = gcd(num1, num2);
    printf("The GCD of %d and %d is: %d\n", num1, num2, result);

    return 0;
}
