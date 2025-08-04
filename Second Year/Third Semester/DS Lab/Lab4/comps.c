#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float real;
    float img;
} Complex;

void frees(Complex* c) {
    free(c);
}

Complex add(Complex* a, Complex* b) {
    Complex sum;
    //Complex *sum=(Complex*)malloc(sizeof(Complex));
    sum.real=a->real + b->real;
    sum.img=a->img + b->img;
    return sum;
}

Complex subtract(Complex* a, Complex* b) {
    Complex sub;
    sub.real=a->real - b->real;
    sub.img=a->img - b->img;
    return sub;
}

Complex multiply(Complex* a,  Complex* b) {
    Complex mult;
    mult.real = a->real * b->real - a->img * b->img;
    mult.img = a->real * b->img + a->img * b->real;
    return mult;
}

void print(Complex* c) {
    if (c->img >= 0)
        printf("%.2f + %.2fi\n", c->real, c->img);
    else
        printf("%.2f - %.2fi\n", c->real, -c->img);
}

int main() {
  Complex* c1=(Complex*)malloc(sizeof(Complex));
  Complex* c2=(Complex*)malloc(sizeof(Complex));
    printf("Enter the first complex number as real followed by imaginary without i ");
   scanf("%f %f",&c1->real,&c1->img);
   printf("Enter the second complex number as real followed by imaginary without i ");
   scanf("%f %f",&c2->real,&c2->img);
    Complex sum = add(c1, c2);
    Complex difference = subtract(c1, c2);
    Complex product = multiply(c1, c2);
    printf("Sum: ");
    print(&sum);
    printf("Difference: ");
    print(&difference);
    printf("Product: ");
    print(&product);
    frees(c1);
    frees(c2);
    return 0;
}

