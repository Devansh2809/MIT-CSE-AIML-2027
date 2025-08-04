#include <stdio.h>
int isPrime(int n, int *opCount) {
if (n <= 1) return 0;
for (int i = 2; i * i <= n; i++) {
(*opCount)++;
if (n % i == 0) {
return 0;
}
}
return 1;
}
int main() {
int gcd = 1, n1, n2, i = 2, opCount = 0;
printf("Enter Num 1 and 2: ");
scanf("%d %d", &n1,&n2);
int a = n1;
int b = n2;
while (a != 1 && b != 1) {
opCount++;
if (a % i == 0 && b % i == 0) {
gcd *= i;
a /= i;
b /= i;
} else if (isPrime(i, &opCount)) {
i++;
} else {
i++;
}
if (i > (a < b ? a : b)) {
break;
}
}
printf("The GCD of %d and %d is: %d\nOperation Count: %d\n", n1, n2, gcd, opCount);
return 0;
}
