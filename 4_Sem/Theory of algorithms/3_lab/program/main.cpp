#include <iomanip>
#include <iostream>
#include <cmath>
#include <ctime>

#define SIZE 7
#define MAX 85
#define SUM 38
#define SIZE2 pow(2,SIZE)

using namespace std;

int vec[SIZE];
int cnt;

// Заполнить массив случайными числами с ограничением на MAX
void fill() {
    for (int i=0; i<SIZE; i++) {
        vec[i] = rand() % MAX;
    }
}

int find() {
    cnt = 0;
    int tmp;
    cnt += 1;
    for (int i=1; i<SIZE2; i++) {
        tmp = 0;
        cnt += 3;
        for (int j=0; j<SIZE; j++) {
            cnt += 3;
            if ((i>>j) && 1) {
                tmp += vec[j];
                cnt += 3;
            }
            cnt += 2;
        }
        cnt += 1;
        if(tmp == SUM) {
            return i;
        }
        cnt += 2;
    }
    return 0;
}

int main(int argc, char** argv) {
    srand (time(0));
    int counter = 0;
    int tmp = 0;
    while (tmp == 0) {
        counter++;
        fill();
        tmp = find();
        if (tmp == 0 && counter == 1) {
            cout << "Worst elemenary operations: " << cnt << endl;
        }
    }
    cout << "Found sum at " << counter << " iteration: ";
    for (int j=0; j<SIZE; j++) {
        if ((tmp>>j) && 1) {
            cout << vec[j] << endl;
        }
    }
    cout << "Elementary operations: " << cnt << endl;
    return 0;
}