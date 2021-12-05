#include <iostream>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x; coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// ����� - ������� �� ������ double
class Matrix {
    double **matrix;
    int rows, cols;
    char ch1, ch2;
public:
    Matrix();
    Matrix(int _rows, int _cols, char _ch1, char _ch2);
    ~Matrix();

    void showMatrix(int level);
    float getElem(int i, int j) {
        float elem = matrix[i][j];
        return elem;
    }
};

// ����������� �� ��������� ������ Matrix
Matrix :: Matrix() {
    cout << "������ �����:";
    cin >> ch1;
    cout << "������ �����:";
    cin >> ch2;
    cout << "������� ���������� ����� �������:";
    cin >> rows;
    cout << "������� ���������� �������� �������:";
    cin >> cols;
    // �������� ������
    matrix = new double* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new double [cols];
    }

    // ��������� ������
    for (int j = 0; j < cols; j++) { //������ �����
        system("cls");
        for (int i = 0; i < rows; i++) { //������ �����
            cout << "������� " << ch1 << j+1 << ":" << ch2 << i+1 << " >> ";
            cin >> matrix[i][j];
        }
    }
}

// ���������� � ����������� (���-�� �����, �������� �������) ������ Matrix
Matrix :: Matrix(int _rows, int _cols, char _ch1, char _ch2) {
    ch1 = _ch1;
    ch2 = _ch2;
    rows = _rows;
    cols = _cols;
    // �������� ������
    matrix = new double* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new double [cols];
    }

    // ��������� ������
    for (int j = 0; j < cols; j++) { //������ �����
        system("cls");
        for (int i = 0; i < rows; i++) { //������ �����
            cout << "������� " << ch1 << j+1 << ":" << ch2 << i+1 << " >> ";
            cin >> matrix[i][j];
        }
    }
}

// ���������� ������ Matrix
Matrix :: ~Matrix() {
    // �������� ������ ���������� �������
    for (int i = 0; i < rows; i++) {
        delete [] matrix[i];
    }
    delete [] matrix;
}

// �������� ������� ������ Matrix
void Matrix :: showMatrix(int level) {
    level = level*10;

    gotoxy(6, 1+level);
    for (int i = 0; i < cols; i++) {
        gotoxy(7+i*7, 1+level);
        cout << ch1 << i+1;
    }

    for (int i = 0; i < rows; i++) {
        gotoxy(2, i+3+level);
        cout << ch2 << i+1;
    }

    for (int i = 0; i < rows; i++) {
        gotoxy(7,i+3+level);
        for (int j = 0; j < cols; j++) {
            gotoxy(7+j*7, i+3+level);
            if (matrix[i][j] != 0)
                cout << matrix[i][j];
        }
        cout << endl;
    }
}

//===========================================MAIN==========================================
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("color B0");

    int sizeA = 0;
    int sizeB = 0;
    int sizeC = 0;
    int sizeD = 0;
    cout << "������� ���������� ��������� I(a) ������ >> "; cin >> sizeA;
    cout << "������� ���������� ��������� II(b) ������ >> "; cin >> sizeB;
    cout << "������� ���������� ��������� III(c) ������ >> "; cin >> sizeC;
    cout << "������� ���������� ��������� VI(d) ������ >> "; cin >> sizeD;
    
    float arrA[sizeA] = {}; // �������� I ������
    float arrB[sizeB] = {};  // ������������� ���� II ������
    float arrBn[sizeB] = {}; // ������������ ��������� b
    float arrC[sizeC] = {};  // ������������� ���� III ������
    float arrCn[sizeC] = {}; // ������������ ��������� c
    float arrD[sizeD] = {};  // ������������� ���� VI ������
    float arrDn[sizeD] = {}; // ������������ ��������� d

    float sumB = 0, sumC = 0, sumD = 0;

    cout << "������� ������ ������� �������� � ���� �������: " << endl;
    for (int i = 0; i < sizeA; i++) {
        cout << "a" << i+1 << ": "; cin >> arrA[i];
    }
    cout << endl; system("pause");

    // �������� ������ (����)
    Matrix *matrixAB = new Matrix(sizeB, sizeA, 'a', 'b');
    Matrix *matrixBC = new Matrix(sizeC, sizeB, 'b', 'c');
    Matrix *matrixCD = new Matrix(sizeD, sizeC, 'c', 'd');
    system("cls");

    //==========================================================================
    // ��������� ������������� ���� II ������
    for (int i = 0; i < sizeB; i++) {
        for (int j = 0; j < sizeA; j++)
            arrB[i] = arrB[i] + (matrixAB->getElem(i,j) * arrA[j]);
    }

    // ����� ������������� ����� II ������
    for (int i = 0; i < sizeB; i++) {
        sumB = sumB + arrB[i];
    }

    // ������������ ��������� II ������
    for (int i = 0; i < sizeB; i++) {
        arrBn[i] = arrB[i] / sumB;
    }

    //==========================================================================
    // ��������� ������������� ���� III ������
    for (int i = 0; i < sizeC; i++) {
        for (int j = 0; j < sizeB; j++)
            arrC[i] = arrC[i] + (matrixBC->getElem(i,j) * arrBn[j]);
    }

    // ����� ������������� ����� III ������
    for (int i = 0; i < sizeC; i++) {
        sumC = sumC + arrC[i];
    }

    // ������������ ��������� III ������
    for (int i = 0; i < sizeC; i++) {
        arrCn[i] = arrC[i] / sumC;
    }

    //==========================================================================
    // ��������� ������������� ���� VI ������
    for (int i = 0; i < sizeD; i++) {
        for (int j = 0; j < sizeC; j++)
            arrD[i] = arrD[i] + (matrixCD->getElem(i,j) * arrCn[j]);
    }

    // ����� ������������� ����� III ������
    for (int i = 0; i < sizeD; i++) {
        sumD = sumD + arrD[i];
    }

    // ������������ ��������� III ������
    for (int i = 0; i < sizeD; i++) {
        arrDn[i] = arrD[i] / sumD;
    }

    //==========================================================================
    int num;
    while(1) {
        system("pause");
        system("cls");
        cout << " 1 - ������� �������� I ������ (�������� ������)" << endl << endl;

        cout << " 2 - ������� ������������� ���� II (b) ������" << endl;
        cout << " 3 - ������� ����� ������������� ����� II (b) ������" << endl;
        cout << " 4 - ������� ������������� �������� II (b) ������" << endl << endl;

        cout << " 5 - ������� ������������� ���� III (c) ������" << endl;
        cout << " 6 - ������� ����� ������������� ����� III (c) ������" << endl;
        cout << " 7 - ������� ������������� �������� III (c) ������" << endl << endl;

        cout << " 8 - ������� ������������� ���� VI (d) ������" << endl;
        cout << " 9 - ������� ����� ������������� ����� VI (d) ������" << endl;
        cout << "10 - ������� ������������� �������� VI (d) ������" << endl << endl;

        cout << "11 - ������� �������� ������� (�������� ������)" << endl << endl;

        cout << "12 - �����" << endl << endl;
        cout << " >> "; cin >> num;
        switch (num) {

            case 1: {
                cout << "a: " << endl << endl;
                for (int i = 0; i < sizeA; i++) {
                    cout << "a" << i+1 << " = " << arrA[i] << endl;
                }
                break;
            }

            case 2: {
                cout << "b: " << endl << endl;
                for (int i = 0; i < sizeB; i++) {
                    cout << "b" << i+1 << " = " << arrB[i] << endl;
                }
                break;
            }

            case 3: {
                cout << "����� ������������� ����� II (b) ������ = " << sumB << endl;
                break;
            }

            case 4: {
                cout << "bn: " << endl << endl;
                for (int i = 0; i < sizeB; i++) {
                    cout << "bn" << i+1 << " = " << arrBn[i] << endl;
                }
                break;
            }
            case 5: {
                cout << "c: " << endl << endl;
                for (int i = 0; i < sizeC; i++) {
                    cout << "c" << i+1 << " = " << arrC[i] << endl;
                }
                break;
            }

            case 6: {
                cout << "����� ������������� ����� III (c) ������ = " << sumC << endl;
                break;
            }

            case 7: {
                cout << "cn: " << endl << endl;
                for (int i = 0; i < sizeC; i++) {
                    cout << "cn" << i+1 << " = " << arrCn[i] << endl;
                }
                break;
            }

            case 8: {
                cout << "d: " << endl << endl;
                for (int i = 0; i < sizeD; i++) {
                    cout << "d" << i+1 << " = " << arrD[i] << endl;
                }
                break;
            }

            case 9: {
                cout << "����� ������������� ����� VI (d) ������ = " << sumD << endl;
                break;
            }

            case 10: {
                cout << "dn: " << endl << endl;
                for (int i = 0; i < sizeD; i++) {
                    cout << "dn" << i+1 << " = " << arrDn[i] << endl;
                }
                break;
            }

            case 11: {
                system("cls");
                matrixAB->showMatrix(0);
                matrixBC->showMatrix(1);
                matrixCD->showMatrix(2);
                break;
            }

            case 12: {
                delete matrixAB;
                delete matrixBC;
                delete matrixCD;
                return 0;
            }
        }
    }
}