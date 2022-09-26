#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>


#define VECTOR_SIZE 4096

using namespace std;

int vector [VECTOR_SIZE];

double harmonic (int n) {
    double result = 0.0;
    for (int i=1; i<=n; i++) {
        result += (double) 1.0/i;
    }
    return result;
}

void create_array (int n) {
    srand (time (0));
    for (int i=1; i<=n; i++)
        vector[i-1] = rand() % 950;
}

int main (int argc, char** argv) {
    setlocale (LC_ALL, "Russian");
    int n;

    cout << "Введите количество элементов: ";
    cin >> n;

    cout << "Гармоническое: " << harmonic(n) << endl;

    double avarage = 0.0;
    for (int k=0; k<1000000; k++) {
        create_array(n);
        int min = vector[0];
        int cnt = 1;
        for (int i=1; i<n; i++) {
            if (vector[i] < min) {
                min = vector[i];
                cnt++;
            }
        }
        avarage += cnt;
    }
    cout << "Среднее практическое значение: " << avarage/1000000.0 << endl;
    return 0;
}