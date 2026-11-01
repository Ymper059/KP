#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define X_MIN       40.0
#define X_MAX       130.0
#define X_LOG_LIMIT 63.0    
#define NORM_LOW    65.0
#define NORM_HIGH   100.0
#define A1 3.0
#define S1 2.0
#define B1 10.0
#define A2 2.0
#define C2 82.5
#define B2 48.0
#define A3 5.0
#define S3 1.0
#define B3 58.0
enum state { STATE_LOW, STATE_NORMAL, STATE_HIGH };
double     calc_quality(double x);
int        read_x(double* x);
enum state check_state(double x);
int main(void) {
    double x;
    double q;
    enum state st;
    system("chcp 1251 > nul");
    printf("Программа мониторинга температуры реактора.\n");
    printf("Вычисляет показатель качества Q по температуре X.\n\n");
    printf("Введите X (%.0f-%.0f): ", X_MIN, X_MAX);
    if (!read_x(&x)) {
        printf("Ошибка: X должен быть в диапазоне (%.0f; %.0f].\n", X_LOG_LIMIT, X_MAX);
        return EXIT_FAILURE;
    }
    q = calc_quality(x);
    printf("Q(%.2f) = %.2f\n", x, q);
    st = check_state(x);
    if (st == STATE_LOW) {
        printf("Состояние: температура ниже нормы.\n");
    }
    else if (st == STATE_NORMAL) {
        printf("Состояние: норма.\n");
    }
    else {
        printf("Состояние: температура выше нормы.\n");
    }
    return EXIT_SUCCESS;
}
double calc_quality(double x) {
    if (x < NORM_LOW) {
        return A1 * log(x - NORM_LOW + S1) + B1;
    }
    else if (x <= NORM_HIGH) {
        return A2 * (x - C2) + B2;
    }
    else {
        return A3 * sqrt(x - NORM_HIGH + S3) + B3;
    }
}
int read_x(double* x) {
    if (scanf("%lf", x) != 1) {
        return 0;
    }
    return *x > X_LOG_LIMIT && *x <= X_MAX;
}
enum state check_state(double x) {
    if (x < NORM_LOW) {
        return STATE_LOW;
    }
    else if (x <= NORM_HIGH) {
        return STATE_NORMAL;
    }
    else {
        return STATE_HIGH;
    }
}