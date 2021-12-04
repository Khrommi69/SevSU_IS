#include <iostream>
#include <windows.h>

using namespace std;

class Matrix; // �������� ���������� ������

// ����� - ������ �� ����� �����
class Vector {
    int *vector;
    int arrLen;
public:
    Vector();
    Vector(int _arrLen);
    ~Vector();

    void showVector();
    friend void replacingDiagonal(Vector *ob1, Matrix *ob2); // ������������� �-���
};

// ����� - ������� �� ������ double
class Matrix {
    double **matrix;
    int rows, cols;
public:
    Matrix();
    Matrix(int _rows, int _cols);
    ~Matrix();

    void showMatrix();
    friend void replacingDiagonal(Vector *ob1, Matrix *ob2); // ������������� �-���
};

// ����������� �� ��������� ������ Vector
Vector :: Vector() {
    arrLen = 1;
    vector = new int[arrLen]; //��������� ������ ��� ������ ����� ����� �������� arrLen
    vector[0] = 1;
    // ������� ������ �� ������ �������� � ������ "1"
    cout << "����������� Vector �� ���������" << endl << endl;
}

// ���������� � ����������� (����� �������) ������ Vector
Vector :: Vector(int _arrLen) {
    arrLen = _arrLen;
    vector = new int[arrLen]; // �������� ������
    // ��������� ������
    for (int i = 0; i < arrLen; i++) {
        cout << "������� " << i+1 << " ������� �������: ";
        cin >> vector[i];
    }
    cout << "����������� Vector � �����������" << endl << endl;
}

// ���������� ������ Vector
Vector :: ~Vector() {
    delete [] vector; // �������� ������ ���������� �������
    cout << "���������� Vector" << endl;
}

// �������� ������ ������ Vector
void Vector :: showVector() {
    cout << "������:" << endl;
    for (int i = 0; i < arrLen; i++) {
        cout << vector[i] << "\t";
    }
    cout << endl;
}

// ����������� �� ��������� ������ Matrix
Matrix :: Matrix() {
    rows = 1;
    cols = 1;
    matrix = new double* [rows]; //��������� ������ ��� ������ ���������� �� �������
    matrix[0] = new double [cols]; // ��������� ������ ��� ���� ������
    // ������� ������� �� ������ �������� � ������ "1"
    cout << "����������� Matrix �� ���������" << endl << endl;
}

// ���������� � ����������� (���-�� �����, �������� �������) ������ Matrix
Matrix :: Matrix(int _rows, int _cols) {
    rows = _rows;
    cols = _cols;
    // �������� ������
    matrix = new double* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new double [cols];
    }

    // ��������� ������
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "������� [" << i+1 << "][" << j+1 << "] ������� �������: ";
            cin >> matrix[i][j];
        }
    }
    cout << "����������� Matrix � �����������" << endl << endl;
}

// ���������� ������ Matrix
Matrix :: ~Matrix() {
    // �������� ������ ���������� �������
    for (int i = 0; i < rows; i++) {
        delete [] matrix[i];
    }
    delete [] matrix;
    cout << "���������� Matrix" << endl;
}

// �������� ������� ������ Matrix
void Matrix :: showMatrix() {
    cout << "�������:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// ������� ����, �������� ������� ��������� ������� �� ������
void replacingDiagonal(Vector *ob1, Matrix *ob2) {
    if ((ob1->arrLen <= ob2->rows) && (ob1->arrLen <= ob2->cols)) {
        for (int i = 0; i < ob1->arrLen; i++) {
            ob2->matrix[i][i] = ob1->vector[i];
        }
        cout << "������� ����, �������� ������� ��������� ������� �� ������ ���� ���������" << endl << endl;
    }
    else {
        cout << "� ��������� ����� ������� ������, ��� ����� �������� � ���� ������� ��������� �������" << endl
             << "������� �������� ��������� �� ����� �����������" << endl << endl;
    }
}


//======================================MAIN======================================
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("color B0");

    cout << "������� ������ � �������� ���" << endl;
    // ������� ������
    Vector *vectorObj1 = new Vector(4);
    // �������� ������
    vectorObj1->showVector();
    cout << endl << endl;

    cout << "������� ������� � �������� �" << endl;
    // ������� �������
    Matrix *matrixObj1 = new Matrix(5,6);
    // �������� �������
    matrixObj1->showMatrix();
    cout << endl << endl;

    cout << "�������� ������� ��������� ������� �� ������ � �������� �" << endl;
    // �������� ������� ��������� ������� �� ������
    replacingDiagonal(vectorObj1, matrixObj1);
    // �������� �������
    matrixObj1->showMatrix();
    cout << endl << endl;

    // ������� ������� (�������� ������)
    delete vectorObj1;
    delete matrixObj1;

    
    cout << endl << endl;
    cout << "������� ������ � �������� ���" << endl;
    // ������� ������
    Vector *vectorObj2 = new Vector(3);
    // �������� ������
    vectorObj1->showVector();
    cout << endl << endl;

    cout << "������� ������� � �������� �" << endl;
    // ������� �������
    Matrix *matrixObj2 = new Matrix(2,2);
    // �������� �������
    matrixObj1->showMatrix();
    cout << endl << endl;

    cout << "�������� ������� ��������� ������� �� ������ � �������� �" << endl;
    // �������� ������� ��������� ������� �� ������
    replacingDiagonal(vectorObj2, matrixObj2);
    // �������� �������
    matrixObj1->showMatrix();
    cout << endl << endl;

    // ������� ������� (�������� ������)
    delete vectorObj1;
    delete matrixObj1;
    
    system("pause");
    return 0;
}