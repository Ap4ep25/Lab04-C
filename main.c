#include <stdio.h>
#include <math.h>

int main() {
    double mas[100];
    double a, x, d, h, xmin, xmax, maxv, minv;
    int c, s, i;

    do{

        printf("Для выхода из программы, введите 0\n");
        printf("Формула 1: Рассчет G, введите 1\n");
        printf("Формула 2: Рассчет F, введите 2\n");
        printf("Формула 3: Рассчет Y, введите 3\n");
        scanf("%d", &c);

        if (c == 0) {
            printf("До свидания!");
            return 0;
        }

        if ((c < 0) || (c > 3)) {
            printf("Неверно введено значение, введите его заного!\n");
            scanf("%d", &c);
        } else

            printf("Введите минимальное значение х: ");
        scanf("%lf", &xmin);
            printf("Введите максимальное значение x: ");
        scanf("%lf", &xmax);

        if (xmin >= xmax) {
            printf("Максимальное значение х должно быть больше минимального\n");
            printf("Введите еще раз х: ");
            scanf("%lf", &xmax);
        }
        printf("Введите колличество шагов: ");
        scanf("%d", &s);

        while (s <= 0) {
            printf("Число шагов не может быть меньше или равно 0\n");
            printf("Введите число шагов еще раз: ");
            scanf("%d", &s);
        }
        if (s > 100){
            printf("Ошибка с массивом");
            return 0;
        }
        h = (xmax - xmin) / (s - 1);


        switch (c) {
            case 1: {
                printf("Введите а: ");
                scanf("%lf", &a);
                for (x = xmin, i = 0; x <= xmax & i <= s; x+=h, i++) {
                    d = (10 * pow(a, 2) + 11 * a * x + 3 * pow(x, 2));
                    if (d == (10e-6)) {
                        printf("Введите другие значения \n");
                        break;
                    }
                    mas[i] = (5 * (-2 * pow(a, 2) + a * x + 3 * pow(x, 2))/d);
                    printf("x = %lf\t", x );
                    printf("G=%lf\n", mas[i]);

                }
                break;
                case 2: {
                    printf("Введите а: ");
                    scanf("%lf", &a);
                    for (x = xmin, i = 0; x < xmax; x+=h, i++) {
                        mas[i] = sin(10 * pow(a, 2) - 7 * a * x + pow(x ,2));
                        printf("x = %0.18lf\t", x );
                        printf("F= %0.18lf\n", mas[i]);
                    }
                    break;
                    case 3: {
                        printf("Введите а: ");
                        scanf("%lf", &a);
                        for (x = xmin, i = 0; x < xmax; x+=h, i++) {
                            mas[i] = atan(45 * pow(a, 2) + 79 * a * x + 30 * pow(x, 2));
                            printf("x = %lf\t", x );
                            printf("%lf\n", mas[i]);
                        }
                        break;

                    }
                }
            }
        }
        for (i = 0, minv = mas[0], maxv = mas[0]; i <= s; i++){
            if(mas[i] > maxv)
                maxv = mas[i];
            if (mas[i] < minv)
                minv = mas[i];
        }
        printf("Макс. значение: %0.18lf\n", maxv);
        printf("Мин. значение: %0.18lf\n", minv);
    } while (c != 0);
    return 0;
}