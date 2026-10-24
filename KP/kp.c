#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>
double Q(double X) {
    if (X < 65) {
        return 3 * log(X - 65 + 2) + 10;
    }
    else if (X <= 100) {
        return 2 * (X - 82.5) + 48;
    }
    else {
        return 5 * sqrt(X - 100 + 1) + 58;
    }
}
int main() {
    setlocale(LC_ALL, "RUS");
    double X;
    printf("¬ведите X: ");
    scanf("%lf", &X);
    printf("Q(%.2f) = %.2f\n", X, Q(X));
    return 0;
}