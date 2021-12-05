#include <iostream>
#include <windows.h>
#include <cmath>

class Matrix {
	double **mainMatrix; // �������� �����������
	double **matrixSravneniy; // ������� �������� ��������� �� ������ ���������� ������

	// ���������� ��������� � ���������� �����������
	int kolKrit, kolAlter; // ������ = kolKrit; ������� = kolAlter;

	//����� ������ 15 ���� ������ � 19 ��������
	char nameKrit[15][20]; // ����� ���������

	char nameAlter[26]; // ����� �����������

	char nameCeli[255]; // ��� ����
public:
	Matrix();
	~Matrix();

	void zapolniaem();
	void reshaem();
};


Matrix :: Matrix() {
	std::cout << "������� ���������� ��������� (kol <= 15): ";
	std::cin >> this->kolKrit;

	std::cout << "������� ���������� ����������� (kol <= 25): ";
	std::cin >> this->kolAlter;

	std::cout << "������ ������� ����������� ������ ������� ������������� \"_\"" << std::endl;
	std::cout << "������� ��� ����: ";
	std::cin >> nameCeli;
	for (int i = 1; i <= kolKrit; i++) {
		std::cout << "������� ��� " << i << " ��������: ";
		std::cin >> nameKrit[i-1];
	}
	char ch = 65;
	for (int i = 1; i <= kolAlter; i++) {
		// ��� ������������:
		nameAlter[i-1] = ch;
		ch++;
	}
	std::cout << std::endl;

	// �������� ������
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
	std::cout << "�� ����� ������� ������������� ��������������" << std::endl;
	std::cout << "��� ���� ���� ->\"" << nameCeli << "\"" << std::endl << std::endl;
	for(int i = 0; i < kolKrit; i++){
		for(int j = 0; j < kolAlter; j++){
			std::cout << "������� [" << nameAlter[j] << "] [" << nameKrit[i] << "] - ";
			std::cin >> mainMatrix[i][j];
		}
	}
	std::cout << std::endl;
	system("pause");
	system("cls");

	std::cout << "� ������ ����� ������� �������� ������� ��������" << std::endl;
	std::cout << "��������� �� ������� ���������� ������" << std::endl << std::endl;
	for(int i = 0; i < kolKrit; i++){
		for(int j = 0; j < kolKrit; j++){
			std::cout << "������� [" << nameKrit[i] << "] [" << j+1 << "] - ";
			std::cin >> matrixSravneniy[i][j];
		}
	}
	std::cout << std::endl;
	system("pause");
	system("cls");
}

void Matrix :: reshaem(){
	double arrVectoraPr[kolKrit]; // ������ ����������� ��� ������� ������� (��������)
    double arrPrioritetov[kolKrit]; // ������ ����������� ��� ������ �������� ���������
    std::cout << "���������� ����������:" << std::endl << std::endl;

    //===================================================================
    //������� ������ ����������� �� ������� �������� ���������
    double tempArr[kolKrit]; //��������� ������ ������� ���-�� ���������
    for (int i = 0; i<kolKrit; i++) {
    	tempArr[i] = 1;
    	for(int j = 0; j<kolKrit; j++) {
    		tempArr[i] = tempArr[i] * matrixSravneniy[i][j];
    	}
    	tempArr[i] = pow(tempArr[i], (1.0/kolKrit));
    } //��������� w1, w2, w3, ...
	double sum = 0.0;
	for (int i = 0; i<kolKrit; i++) {
		sum = sum + tempArr[i];
	} //��������� W
	for (int i = 0; i<kolKrit; i++) {
		arrPrioritetov[i] = tempArr[i] / sum;
	} //������� ������ �����������
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
    		// std::cout << "����������� w[" << i << "] [" << j << "] = " << matrVectoraPr[i][j] << std::endl; //-------->
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
		} //��������� ���������� ���������

		std::cout << "k" << nameAlter[kolichestvoAlternativ] << " = " << sum << std::endl;
	}
	std::cout << std::endl << std::endl;
	system("pause");
}

Matrix :: ~Matrix() {
    // �������� ������ ���������� ��������
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

	//�������� ������� � ������ ������� ���
	Matrix *MAI = new Matrix();
	MAI->zapolniaem();
	MAI->reshaem();
	
	delete MAI;
	return 0;
}