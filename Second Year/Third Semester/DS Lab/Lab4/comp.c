#include <stdio.h>

typedef struct {
    float real;
    float img;
} Complex;

Complex add(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.img = c1.img + c2.img;
    return result;
}

Complex subtract(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real - c2.real;
    result.img = c1.img - c2.img;
    return result;
}
Complex multiply(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real * c2.real - c1.img * c2.img;
    result.img = c1.real * c2.img + c1.img * c2.real;
    return result;
}

int main() {
    Complex c1, c2, result;
   printf("Enter the first complex number as real followed by imaginary without i ");
   scanf("%f %f",&c1.real,&c1.img);
   printf("Enter the second complex number as real followed by imaginary without i ");
   scanf("%f %f",&c2.real,&c2.img);
    result = add(c1, c2);
    printf("Addition: %.2f + %.2fi\n", result.real, result.img);
    result = subtract(c1, c2);
    printf("Subtraction: %.2f + %.2fi\n", result.real, result.img);
    result = multiply(c1, c2);
    printf("Multiplication: %.2f + %.2fi\n", result.real, result.img);

    return 0;
}

