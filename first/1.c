#include <stdio.h>
#include <math.h>

int main() {
    double x, e;

    printf("Введите X: ");
    int answer1 = scanf("%lf", &x);

    printf("Введите E: ");
    int answer2 = scanf("%lf", &e);

    if (answer1 != 1 || answer2 != 1 || e <= 0)
    {
        printf("Ошибка ввода данных.");
        return 0;
    }

    double exact_value = sin(x);
    double sum = 0.0;
    int sign = 1;
    int degree = 1;          
    double x_to_the_power = x;
    double factorial = 1.0;
    
    double elem = sign * x_to_the_power / factorial;

    if (fabs(x) < e)
    {
        sum = 0.0;
        elem = x;
    }
    else
        while (fabs(elem) >= e) {
            sum += elem;

            sign = -sign;
            degree += 2;
            x_to_the_power *= x * x;

            factorial *= (degree - 1) * degree;  // Умножаем на недостающие множители

            elem = sign * x_to_the_power / factorial;

            if (degree > 100) 
            {
                printf("Предупреждение: достигнуто максимальное количество итераций.\n");
                break;
            }
        }

    printf("\n");
    printf("X = %.6f\n", x);
    printf("E = %.6f\n", e);
    printf("Сумма ряда = %.10f\n", sum);
    printf("Точное значение sin(x) = %.10f\n", exact_value);
    printf("Абсолютная величина последнего члена = %.10e\n", fabs(elem));
    printf("Разность (сумма - точное значение) = %.10f\n", sum - exact_value);
    return 0;
}
