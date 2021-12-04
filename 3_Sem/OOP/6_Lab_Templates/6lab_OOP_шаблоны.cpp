// ��������� �������� �������-������, �������������� i-� � j-� ������ � �������, ����������������� 
// �� ���������� ������ �� ��������� �� ���� ������� ������ (�� ����� ����: int, char � ��.).

#include <iostream>
#include <windows.h>
#include <ctime>

// ������ class ����� ������ typename

// ����� - ������� �� ����� ������
template <class T>
class Matrix {
private:
	int numRows;
	int numColumns;
	T **matrix;
public:
    Matrix();
    Matrix(int _numRows, int _numColumns);
    ~Matrix();

    void showMatrix();
    void swapStrings();
};

// ����������� �� ��������� ������ Matrix
template <typename T>
Matrix<T> :: Matrix() {
    numRows = 5;
    numColumns = 5;
    //��������� ������ ��� ������ ���������� �� �������
    matrix = new T* [numRows];
    // ��������� ������ ��� �������
    for (int i = 0; i < numRows; i++) {
        matrix[i] = new T [numColumns];
    }

    // ��������� ������
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            matrix[i][j] = rand();
        }
    }
}

// ����������� �� ��������� ������ Matrix
// ������������� ������������ ��� ���� DOUBLE
template <>
Matrix<double> :: Matrix() {
    numRows = 5;
    numColumns = 5;
    //��������� ������ ��� ������ ���������� �� �������
    matrix = new double* [numRows];
    // ��������� ������ ��� �������
    for (int i = 0; i < numRows; i++) {
        matrix[i] = new double [numColumns];
    }

    // ��������� ������
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            matrix[i][j] = rand() * 1.0 / rand();
        }
    }
}

// ����������� �� ��������� ������ Matrix
// ������������� ������������ ��� ���� CHAR
template <>
Matrix<char> :: Matrix() {
    numRows = 5;
    numColumns = 5;
    //��������� ������ ��� ������ ���������� �� �������
    matrix = new char* [numRows];
    // ��������� ������ ��� �������
    for (int i = 0; i < numRows; i++) {
        matrix[i] = new char [numColumns];
    }

    // ��������� ������
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            matrix[i][j] = rand() % 64 + 192; //��������� ���������� �������
        }
    }
}

// ���������� � ����������� (���-�� �����, �������� �������) ������ Matrix
template <class T>
Matrix<T> :: Matrix(int _numRows, int _numColumns) {
    numRows = _numRows;
    numColumns = _numColumns;
    // �������� ������
    matrix = new T* [numRows];
    for (int i = 0; i < numRows; i++) {
        matrix[i] = new T [numColumns];
    }

    // ��������� ������ �������
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            std::cout << "������� [" << i+1 << "][" << j+1 << "] ������� �������: ";
            std::cin >> matrix[i][j];
        }
    }
    std::cout << std::endl;
}

// ���������� ������ Matrix
template <class T>
Matrix<T> :: ~Matrix() {
    // �������� ������ ���������� �������
    for (int i = 0; i < numRows; i++) {
        delete [] matrix[i];
    }
    delete [] matrix;
}

// �������� ������� ������ Matrix
template <class T>
void Matrix<T> :: showMatrix() {
    std::cout << "�������:" << std::endl;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            std::cout.setf(std::ios::left);
            std::cout.width(15);
            std::cout << matrix[i][j];
        }
        std::cout << std::endl << std::endl;
    }
}

// ������� ������ �������� ������ � ������� �������
template <typename T>
void Matrix<T> :: swapStrings() {
    if (this->numRows <= 1) {
        std::cout << "� ������� ���� ����� ��� ������ ���\a" << std::endl;
        system("pause");
        system("cls");
        return;
    }
    int numStr1, numStr2;
    std::cout << "� ������� " << this->numRows << " �����. ����� ������ ������?" << std::endl;
    std::cout << "������� ������ �������� �����: " << std::endl;
    std::cout << "-> ";
    std::cin >> numStr1;
    std::cout << "-> ";
    std::cin >> numStr2;
    if ((numStr1 > this->numRows) || (numStr2 > this->numRows)){
        std::cout << "������: �� ����� ������� ������� ������ �����!\a" << std::endl;
        system("pause");
        system("cls");
        return;
    }

    T temp;
    for(int i = 0; i < this->numColumns; i++) {
        temp = this->matrix[numStr1 - 1][i];
        this->matrix[numStr1 - 1][i] = this->matrix[numStr2 - 1][i];
        this->matrix[numStr2 - 1][i] = temp;
    }
}

int main(int argc, char const *argv[])
{
	system("color B0");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    srand((unsigned int)time(NULL));

    char ch;
    while(1){
        std::cout << "�������� ������� � ���������� ���� int: " << std::endl;
        Matrix<int> *obj1 = new Matrix<int>();
        obj1->showMatrix();
        obj1->swapStrings();
        std::cout << "���������� ������� � ���������� ���� int: " << std::endl;
        obj1->showMatrix();
        std::cout << std::endl;
        system("pause");
        delete obj1;
        system("cls");

        std::cout << "�������� ������� � ���������� ���� double: " << std::endl;
        Matrix<double> *obj2 = new Matrix<double>();
        obj2->showMatrix();
        obj2->swapStrings();
        std::cout << "���������� ������� � ���������� ���� double: " << std::endl;
        obj2->showMatrix();
        std::cout << std::endl;
        system("pause");
        delete obj2;
        system("cls");

        std::cout << "�������� ������� � ���������� ���� char: " << std::endl;
        Matrix<char> *obj3 = new Matrix<char>();
        obj3->showMatrix();
        obj3->swapStrings();
        std::cout << "���������� ������� � ���������� ���� char: " << std::endl;
        obj3->showMatrix();
        std::cout << std::endl;
        system("pause");
        delete obj3;
        system("cls");

        std::cout << "�����? (y/n) >> ";
        std::cin >> ch;
        if (ch == 'y') break;
        system("cls");
    }

	return 0;
}