//                  14 ВАРИАНТ
//
//    f(n) = ((2^(n-4)) / (sqrt(n)))
//    g(n) = (1,618^n)
//
// Границы интервалов: {(20;50), (100;120), (500, 540)}
// Значения phi: {(Pi/32), (Pi/24), (Pi/18)}

#include <math.h>
#include <stdio.h>

int main() {

    double Fn,      //F(n)
           Gn,      //G(n)
           ATg_FG,
           ATg_GF,
           pi,      // ATg_FG - ATg_GF
           Nbegin,  //Левая граница интервала   ->вводим с клавы
           Nend,    //Правая граница интервала  ->вводим с клавы
           step,    //Шаг изменения аргумента   ->вводим с клавы
           phi,     //Значение угла
           k,       //Коэффициент кратности     ->вводим с клавы
           Delta,   //Оценка «Дельта»
           Theta,   //Оценка «Тетта»
           O_large, //Оценка «О-большое»
           ii;      //Значение аргумента функций трудоемкости (n)

    FILE *stream; //Указатель на файл, в который осуществляется ввод-вывод расчетов
    stream = fopen("Example_TA.TXT", "w+"); // открытие файла для записи

    // Ввод значений границ интервалов, шага изменения аргумента внутри интервала, коэффициента кратности
    printf("Input Nbegin ->");      scanf("%lf", &Nbegin); //Левая граница, ввод значения
    printf("Input Nend ->");        scanf("%lf", &Nend);   //Правая граница, ввод значения
    printf("Input step ->");        scanf("%lf", &step);   //Шаг изменения аргумента
    printf("Input koefficient ->"); scanf("%lf", &k);      //Коэффициент кратности

    phi = M_PI/k; // Определили угол изменения как П/k, (M_PI - встроенная константа языка Си = числу Pi)

    ii = Nbegin; //Аргумент функций равен левой границе интервала

    fprintf(stream, "n,      F(n),      G(n),      ATg_FG,      ATg_GF,      pi,      Delta,      Theta,      O_large \n\n");

    while (ii <= Nend) {
        Fn = (pow(2, (ii-4))) / sqrt(ii);   //Расчет значения функции F(n)
        Gn = pow(1.618, ii);                   //Расчет значения функции G(n)
        ATg_FG = atan(Fn/Gn);
        ATg_GF = atan(Gn/Fn);
        pi = ATg_FG - ATg_GF;
        Delta = phi - pi;       //Оценка «Дельта»
        Theta = fabs(pi) - phi;  //Оценка «Тетта»
        O_large = pi + phi;     //Оценка «О-большое»
        //Запись расчетов в файл
        fprintf(stream, "%-20.10lf %-20.10lf \t %-20.10lf\t %-20.10lf %-20.10lf %-20.10lf %-20.10lf %-20.10lf %-20.10lf\n",
                                 ii, Fn, Gn, ATg_FG, ATg_GF, pi, Delta, Theta, O_large);
        ii = ii + step; //Получение следующего значения аргумента
    }

    fclose(stream); //Закрыли файл
}