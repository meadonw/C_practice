#include <stdio.h>
#include <math.h>
#include <locale.h>
#define M_PI 3.14159265358979323846

int main() {
    double x, e;
    setlocale(0, "");

    printf("Введите X: ");
    int answer1 = scanf("%lf", &x);

    if (answer1 != 1)
    {
        printf("Ошибка ввода данных.");
        return 0;
    }

    printf("Введите E: ");
    int answer2 = scanf("%lf", &e);

    if (answer2 != 1 || e <= 0)
    {
        printf("Ошибка ввода данных.");
        return 0;
    }

    double original_x = x;

    if (fabs(x) >= 2 * M_PI)
    {
        x = fmod(x, 2 * M_PI);

        if (x < 0)
        {
            x += 2 * M_PI;
        }
    }
    
    double sum = 0.0;
    double elem = x;
    double last_elem = 0.0;
    int n = 1;

    if (fabs(x) < e)
    {
        sum = 0.0;
        elem = x;
    }
    else
        while (fabs(elem) >= e) {
            sum += elem;
            last_elem = elem;

            elem = -elem * x * x / ((n + 1) * (n + 2));

            n += 2;
        }

    double exact_value = sin(x);
    double difference = sum - exact_value;

    printf("\n");
    printf("Исходный X = %.10f\n", original_x);
    printf("Приведеный X = %.10f\n", x);
    printf("E = %.10f\n", e);
    printf("Вычисленная сумма ряда = %.10f\n", sum);
    printf("Точное значение sin(X) = %.10f\n", exact_value);
    printf("Абсолютная величина последнего члена = %.10f\n", fabs(last_elem));
    printf("Разность (сумма - точное значение) = %.10f\n", difference);

    return 0;
}
