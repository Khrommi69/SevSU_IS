#include <iostream>
#include <windows.h>
#include <cmath>

class Matrix {
	double **mainMatrix; // критерии альтернатив
	double **matrixSravneniy; // матрица попарных сравнений на основе экспертных оценок

	// количество критериев и количество альтернатив
	int kolKrit, kolAlter; // строки = kolKrit; столбцы = kolAlter;

	//можно ввести 15 имен длиной в 19 символов
	char nameKrit[15][20]; // имена критериев

	char nameAlter[26]; // имена альтернатив

	char nameCeli[255]; // имя цели
public:
	Matrix();
	~Matrix();

	void zapolniaem();
	void reshaem();
};


Matrix :: Matrix() {
	std::cout << "Введите количество критериев (kol <= 15): ";
	std::cin >> this->kolKrit;

	std::cout << "Введите количество альтернатив (kol <= 25): ";
	std::cin >> this->kolAlter;

	std::cout << "Вместо пробела используйте символ нижнего подчеркивания \"_\"" << std::endl;
	std::cout << "Введите имя ЦЕЛИ: ";
	std::cin >> nameCeli;
	for (int i = 1; i <= kolKrit; i++) {
		std::cout << "Введите имя " << i << " критерия: ";
		std::cin >> nameKrit[i-1];
	}
	char ch = 65;
	for (int i = 1; i <= kolAlter; i++) {
		// имя альтернативы:
		nameAlter[i-1] = ch;
		ch++;
	}
	std::cout << std::endl;

	// выделяем память
    mainMatrix = new double* [kolKrit];
    for (int i = 0; i < kolKrit; i++) {
        mainMatrix[i] = new double [kolAlter];
    }
    matrixSravneniy = new double* [kolKrit];
    for (int i = 0; i < kolKrit; i++) {
        matrixSravneniy[i] = new double [kolKrit];
    }
    system("pause");
	system("cls");
}


void Matrix :: zapolniaem(){
	std::cout << "ЩА будем вводить сравнительные характеристики" << std::endl;
	std::cout << "для этой цели ->\"" << nameCeli << "\"" << std::endl << std::endl;
	for(int i = 0; i < kolKrit; i++){
		for(int j = 0; j < kolAlter; j++){
			std::cout << "Введите [" << nameAlter[j] << "] [" << nameKrit[i] << "] - ";
			std::cin >> mainMatrix[i][j];
		}
	}
	std::cout << std::endl;
	system("pause");
	system("cls");

	std::cout << "А теперь будем вводить элементы матрицы попарных" << std::endl;
	std::cout << "сравнений на освнове экспертных оценок" << std::endl << std::endl;
	for(int i = 0; i < kolKrit; i++){
		for(int j = 0; j < kolKrit; j++){
			std::cout << "Введите [" << nameKrit[i] << "] [" << j+1 << "] - ";
			std::cin >> matrixSravneniy[i][j];
		}
	}
	std::cout << std::endl;
	system("pause");
	system("cls");
}

void Matrix :: reshaem(){
	double arrVectoraPr[kolKrit]; // вектор приоритетов для главной матрицы (меняется)
    double arrPrioritetov[kolKrit]; // вектор приоритетов для матриы попарных сравнений
    std::cout << "Глобальные приоритеты:" << std::endl << std::endl;

    //===================================================================
    //сделаем синтез приоритетов из матрицы попарных сравнений
    double tempArr[kolKrit]; //временный массив размера кол-ва критериев
    for (int i = 0; i<kolKrit; i++) {
    	tempArr[i] = 1;
    	for(int j = 0; j<kolKrit; j++) {
    		tempArr[i] = tempArr[i] * matrixSravneniy[i][j];
    	}
    	tempArr[i] = pow(tempArr[i], (1.0/kolKrit));
    } //вычислили w1, w2, w3, ...
	double sum = 0.0;
	for (int i = 0; i<kolKrit; i++) {
		sum = sum + tempArr[i];
	} //вычислили W
	for (int i = 0; i<kolKrit; i++) {
		arrPrioritetov[i] = tempArr[i] / sum;
	} //сделали синтез приоритетов
    //===================================================================

	double matrVectoraPr[kolKrit][kolAlter];
	for(int i = 0; i<kolKrit; i++) {
		tempArr[i] = 0.0;
		for(int j = 0; j<kolAlter; j++) {
			double tempChislitel = mainMatrix[i][j];
			matrVectoraPr[i][j] = 1.0;
			for(int j2 = 0; j2<kolAlter; j2++) {
				matrVectoraPr[i][j] = matrVectoraPr[i][j] * (tempChislitel / mainMatrix[i][j2]);
			}
			matrVectoraPr[i][j] = pow(matrVectoraPr[i][j], 1.0/kolAlter);
    		// std::cout << "вычисленный w[" << i << "] [" << j << "] = " << matrVectoraPr[i][j] << std::endl; //-------->
			tempArr[i] = tempArr[i] + matrVectoraPr[i][j];
		}
	}
    //===================================================================
	for(int kolichestvoAlternativ = 0; kolichestvoAlternativ < kolAlter; kolichestvoAlternativ++) {
		sum = 0.0;

		for(int i = 0; i < kolKrit; i++){
			arrVectoraPr[i] = (matrVectoraPr[i][kolichestvoAlternativ] / tempArr[i]);
		}

		for (int i = 0; i<kolKrit; i++) {
			sum = sum + (arrVectoraPr[i] * arrPrioritetov[i]);
		} //вычислили глобальный приоритет

		std::cout << "k" << nameAlter[kolichestvoAlternativ] << " = " << sum << std::endl;
	}
	std::cout << std::endl << std::endl;
	system("pause");
}

Matrix :: ~Matrix() {
    // очистить память выделенную матрицам
    for (int i = 0; i < kolKrit; i++) {
        delete [] mainMatrix[i];
    }
    delete [] mainMatrix;

    for (int i = 0; i < kolKrit; i++) {
        delete [] matrixSravneniy[i];
    }
    delete [] matrixSravneniy;
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color B0");

	//создадим объедок с нашими данными МАИ
	Matrix *MAI = new Matrix();
	MAI->zapolniaem();
	MAI->reshaem();
	
	delete MAI;
	return 0;
}