#include <iostream>
#include <windows.h>
#include <iomanip>
#include <cstring>

using namespace std;

//���� ������
struct Node{
    char numAuto[9];   //����� ����
    int pricePenalty;  //��������� ������
    struct Node *next; //��������� �� ����. �������
};

//������
class Penalties {
private:
    Node *begin; //������ �������
    Node *end; //����� �������

public:
    Penalties();                       //1 ����������� - ������� ������� � ������ ��������� ������� ����������� ��������
    Penalties(char num[9], int price); //2 ����������� - �������� ������� � ����� ���������
    Penalties(const Penalties &queue); //3 ����������� - �����������
    ~Penalties ();        //����������

    void addElement(char num[9], int price);    // ���������� �������� � ������
    void DeleteElement();                      // ������� ������� �� �������
    long sumPenalties();                      // ����� �������
    void show();                             // ����������� �������
};


//1 ����������� - ������� ������� � ������ ��������� ������� ����������� ��������
Penalties::Penalties() {
    Node *newE = new Node; //������� ����� ������� � �������� ��� ���� ������
    newE->pricePenalty = 0;
    char num[9] = "--------";
    strcpy(newE->numAuto, num);

    begin = newE;
    end = newE;
    end->next = begin;

    this->DeleteElement();
    cout << endl << "(1 ����������� ��������)" << endl << endl;
}


//2 ����������� - �������� ������� � ����� ���������
Penalties::Penalties(char num[9], int price){
    Node *newE = new Node; //������� ����� ������� � �������� ��� ���� ������
    newE->pricePenalty = price;
    strcpy(newE->numAuto, num);

    begin = newE;
    end = newE;
    end->next = begin;

    cout << endl << "(2 ����������� ��������)" << endl << endl;
}


//3 ����������� - �����������
Penalties::Penalties(const Penalties &queue) {
    //���� ��� ������ � �������� �������
    if (!queue.begin) {
        Node *newE = new Node; //������� ����� ������� � �������� ��� ���� ������
        newE->pricePenalty = 0;
        char num[9] = "--------";
        strcpy(newE->numAuto, num);

        this->begin = newE;
        this->end = newE;
        this->end->next = this->begin;
    }
    else {
        //�������� ������ �������
        Node *newE = new Node; //������� ����� ������� � �������� ��� ���� ������
        newE->pricePenalty = queue.begin->pricePenalty;
        strcpy(newE->numAuto, queue.begin->numAuto);

        this->begin = newE;
        this->end = newE;
        this->end->next = this->begin;

        //���� � ����������� ������� ������ ������ ��������
        if (queue.begin->next != queue.begin) {
            Node *temp = queue.begin->next;
            Node *prev = this->begin;
            while (temp != queue.begin) {
                Node *newE = new Node; //������� ����� ������� � �������� ��� ���� ������
                newE->pricePenalty = temp->pricePenalty;
                strcpy(newE->numAuto, temp->numAuto);

                prev->next = newE;
                this->end = newE;
                newE->next = this->begin;
                temp = temp->next;
                prev = end;
            }
        }
    }
    cout << endl << "(����������� ����������� ��������)" << endl << endl;
}


//����������
Penalties::~Penalties()
{
    Node *temp = begin;
    while(begin != end) // �� ��� ���, ���� �������� ������� �� ����� ����������
    {
        temp = begin;
        begin = begin->next;
        delete temp;
    }
    delete end;

    cout << endl << "���������� ��������" << endl << endl;
}


// ���������� �������� � ������
void Penalties::addElement(char num[9], int price) {
    Node *newE = new Node; //������� ����� ������� � �������� ��� ���� ������
    newE->pricePenalty = price;
    strcpy(newE->numAuto, num);

    if (begin == NULL) {
        begin = newE;
        end = newE;
        end->next = begin;
    }
    else {
        newE->next = begin;
        begin = newE;
        end->next = begin;
    }
}


// ������� ������� �� �������
void Penalties::DeleteElement() {
    if (!begin) {
        cout << "������� ������" << endl;
        return;
    }
    else if (begin->next == begin) { //���� � ������ ���� �������
        delete begin;
        begin = end = NULL;
    }
    else{
        Node *temp = begin;
        while (temp->next != end)
            temp = temp->next;
        delete end;
        end = temp;
        end->next = begin;
    }
}


// ����� �������
long Penalties::sumPenalties() {
    long sum = 0;
    if (!begin) {
        return 0;
    }
    Node *temp = begin;
    while(temp != end) {
        sum += temp->pricePenalty;
        temp = temp->next;
    }
    sum += temp->pricePenalty;
    return sum;
}


// ����������� �������
void Penalties::show()
{
    if(!begin) {
        cout << "������� �����������" << endl << endl;
        return;
    }
    Node *temp = begin;

    cout << "-------------------------------" << endl;
    cout << "|  � ����  | ��������� ������ |" << endl;
    cout << "-------------------------------" << endl;
    while(temp != end)
    {
        cout << "| " << setw(8) << left << temp->numAuto << " | " << setw(16) << left << temp->pricePenalty << " |" << endl;
        cout << "-------------------------------" << endl;
        temp = temp->next;
    }
    cout << "| " << setw(8) << left << temp->numAuto << " | " << setw(16) << left << temp->pricePenalty << " |" << endl;
    cout << "-------------------------------" << endl << endl;
}


//�������� ���������
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int menu;
    char numAuto[9];
    int penalty_price;
    Penalties *queue_1 = new Penalties(), *queue_2 = new Penalties();


    while (1) {
    	system("pause");
    	system("cls");
    	
        cout << endl;
        cout << "1 - �������� ������� � �������" << endl;
        cout << "2 - ������� ������� �� �������" << endl;
        cout << "3 - ������������ �������" << endl;
        cout << "4 - ����� ������� � �������" << endl;
        cout << "5 - ���������� ���� ������� � ������" << endl;
        cout << "6 - ����� �� ���������" << endl;
        cout << " ������� ����� ���� ->";
        cin >> menu; cout << endl;

        switch (menu) {

            case 1 : {
                cout << "C ����� �������� ��������? (1-������ / 2-������) ->"; cin >> menu;
                cout << endl;
                if (menu == 1) {
                    cout << "������� ����� ���� (8 ��������) ->";
                    cin >> numAuto;
                    cout << "������� ����� ������ ->";
                    cin >> penalty_price;
                    cout << endl;
                    queue_1->addElement(numAuto, penalty_price);
                }
                else {
                    cout << "������� ����� ���� (8 ��������) ->";
                    cin >> numAuto;
                    cout << "������� ����� ������ ->";
                    cin >> penalty_price;
                    cout << endl;
                    queue_2->addElement(numAuto, penalty_price);
                }
                break;
            }

            case 2 : {
                cout << "C ����� �������� ��������? (1-������ / 2-������) ->"; cin >> menu;
                cout << endl;
                if (menu == 1) {
                    queue_1->DeleteElement();
                }
                else {
                    queue_2->DeleteElement();
                }
                break;
            }

            case 3 : {
                cout << "C ����� �������� ��������? (1-������ / 2-������) ->"; cin >> menu;
                cout << endl;
                if (menu == 1) {
                    queue_1->show();
                }
                else {
                    queue_2->show();
                }
                break;
            }

            case 4 : {
                cout << "C ����� �������� ��������? (1-������ / 2-������) ->"; cin >> menu;
                cout << endl;
                if (menu == 1) {
                    cout << "C���� ������� � ������ ������� = " <<
                    queue_1->sumPenalties() << endl;
                }
                else {
                    cout << "C���� ������� � ������ ������� = " <<
                    queue_2->sumPenalties() << endl;
                }
                break;
            }

            case 5 : {
                cout << "���� ���� ��������?" << endl << "1 - ������ ������� �������� �� ������" << endl << "2 - ������ ������� �������� � ������" << endl;
                cin >> menu; cout << endl;
                if (menu == 1) {
                    delete queue_2;
                    queue_2 = new Penalties(*queue_1);
                }
                else {
                    delete queue_1;
                    queue_1 = new Penalties(*queue_2);
                }
                break;
            }

            case 6 : {
                cout << endl << "����� �� ���������" << endl << endl;
                return 0;
            }
        }
    }
}
