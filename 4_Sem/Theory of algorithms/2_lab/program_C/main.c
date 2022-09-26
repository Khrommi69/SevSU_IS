#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip.h>
#include <time.h>

int vector[10];
// Cоздание массива из 10 псевдослучайных целых чисел величиной от 0 до 100
// массив записывается в файл Example_TA2.TXT, на экран выводим максимальное целое

harmonic (size_t N)
{
    double ret = 0;
    for (size_t i = 1; i <= N; i++)
    ret += 1 / static_cast<double>(i);
    return ret;
}


void create_array(int Nmax) {
    int i;
    FILE *stream;
    //Nmax = 10; соответствует размерности массива
    stream = fopen("Example_TA2.TXT", "w+");
    randomize();
    cout << "Maximal integer "; cout<<RAND_MAX;
    printf("\n%d%s\n", Nmax, " random numbers from 0 to 100");
    for(i=0; i<Nmax; i++){
        vector[i]= rand() % 100;
        printf("%d\n", vector[i]);
        fprintf(stream,"%d\n", vector[i]);
    }
    fclose(stream);
}

void main() {
    int i,
    N,
    min, // значение минимума
    cnt; //счетчик операций переприсваивания
    double result;
    cout << "Input amount of numbers"; cin>>N;
    result = harmonic(N);
    // harmonic(N) – функция подсчета n-го гармонического числа
    сout << result;
    create_array(N);
    //генерация массива псевдослучайных чисел
    min = vector[0];
     cnt = 1;
     for (i=1;i<N;i++){
        if(vector[i]<min) {
            min = vector[i];
            cnt++;
        }
     }
    printf("%s%d%s%d\n", "Minimal ", min, " Num oper ", cnt);
}