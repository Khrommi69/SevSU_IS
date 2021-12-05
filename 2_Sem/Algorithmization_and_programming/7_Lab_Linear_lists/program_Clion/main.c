#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>


typedef struct Raspisanie  //����������
{
	int n;       //����� ������
	char so[19], //������� �����������
	     sp[18], //������� ��������
	     vo[6],  //����� �����������
	     vp[6];  //����� ��������
	int price;   //��������� ������
	struct Raspisanie *next;
}Rasp;


//��������� �������
void goodbye();
void showRasp(const Rasp *head);
void addNewElement(Rasp **head);
void deleteFirstElement(Rasp **head);
void deleteElement(Rasp **head);
void saveRasp(char* filename, Rasp *temp);
void downloadRasp(char* filename, Rasp **head);


//========================�������_���������========================
int main()
{
    SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������

    char *fileName = "Raspisanie.txt"; //��� �����
    Rasp *head = NULL;
    int choice;

    //��������� ������ �� ����� � ���� �� ���� ���������� ���.
    downloadRasp(fileName, &head);
    if (head)
    {
        printf("����e���� ����������:\n\n");
        showRasp(head);
    }

	while (1)
    {
		printf("\n�������� ���������� ��������:   \n");
		printf(" 1 - �������� ������� � ������;  \n");
		printf(" 2 - ��������� ������� �� ������; \n");
		printf(" 3 - �������� ������;             \n");
		printf(" 4 - ������� ������ ������� (my); \n");
		printf(" 5 - ��������� � �����;           \n");

		printf(" -> ");
		scanf("%i", &choice);
		printf("\n");

		switch(choice)
		{
		    case 1:
            {
                addNewElement(&head);
                break;
            }
			case 2:
            {
                deleteElement(&head);
                break;
            }
			case 3:
            {
                showRasp(head);
                break;
            }
			case 4:
            {
                deleteFirstElement(&head);
                break;
            }
			case 5:
            {
                saveRasp(fileName, head);
                goodbye();
                return 0;
            }
			default:
				printf("�� ����� �������� ������\n");
				break;
		}
	}
}


//============�������� � ������ ����� �������============
void addNewElement(Rasp **head)
{
    int nomerPoezda;
    printf("������� ����� ������:\n");
    scanf("%i", &nomerPoezda);
    while ((getchar()) != '\n');

    char stanciaOtpr[21];
    printf("������� ������� �����������:\n");
    gets(stanciaOtpr);

    char stanciaPrib[21];
    printf("������� ������� ��������:\n");
    gets(stanciaPrib);

    char timeOtpr[21];
    printf("������� ����� �����������:\n");
    gets(timeOtpr);

    char timePrib[21];
    printf("������� ����� ��������:\n");
    gets(timePrib);

    int Price;
    printf("������� ��������� ������:\n");
    scanf("%i", &Price);

    Rasp *newE = (Rasp*)malloc(sizeof(Rasp));

    newE->n = nomerPoezda;
    strcpy(newE->so, stanciaOtpr);
    strcpy(newE->sp, stanciaPrib);
    strcpy(newE->vo, timeOtpr);
    strcpy(newE->vp, timePrib);
    newE->price = Price;
    newE->next = NULL;

    if (*head == NULL)
        *head = newE;
    else
    {
        Rasp *p = *head;
        while(p->next != NULL)
            p = p->next;
        p->next = newE;
    }
}


//========================��������_������========================
void showRasp(const Rasp *head)
{
    if(!head)
        printf("������ �����������\n");
    printf("----------------------------------------------------------------------------------------------------------\n");
    printf("| � ������ | ������� �����������   | ������� ����������    | ����� ����������� | ����� �������� | ����   |\n");
    printf("----------------------------------------------------------------------------------------------------------\n");
    while(head)
    {
        printf("| %-8i | %-21s | %-21s | %-17s | %-14s | %-6i |\n",
                head->n, head->so, head->sp, head->vo, head->vp, head->price);
        printf("----------------------------------------------------------------------------------------------------------\n");
        head = head->next;
    }
}


//==============������� ������ ������� ������================
void deleteFirstElement(Rasp **head)
{
    if (*head == NULL)
    {
        printf("������ ���, ������� ������\n");
        return;
    }
    else if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        Rasp *p = *head;
        *head = (*head)->next;
        free(p);
    }
    printf("������ ������� ������� �����\n");
}


//===========������� ������� � ������ �� ������ ������==========
void deleteElement(Rasp **head)
{
    Rasp *head2 = *head; //�������� head
    //���� ��� ������
    if (!head2)
    {
        printf("������ �����������\n");
        return;
    }

    int search;
    printf("������� ����� ���������� ������:");
    scanf("%i", &search);

    //���� ������� � ���� ������� ������
    if (head2->n == search)
    {
        if ((*head)->next == NULL)
        {
            free(*head);
            *head = NULL;
        }
        else
        {
            Rasp *p = *head;
            *head = (*head)->next;
            free(p);
        }
        printf("������� ������ � ��������� ������� �����\n");
        return;
    }

    //���� ������� � ���� �������
    Rasp *temp = head2;
    while ((temp->next->n != search) && (temp->next != NULL))
        temp = temp->next;

    //���� �� ����� �����
    if (temp->next == NULL)
    {
        printf("����������� ����� �����������\n");
        return;
    }

    //���� ��������� ������� ������
    if (temp->next == NULL)
    {
        Rasp *p = temp->next;
        temp->next = NULL;
        free(p);
    }
    else //���� ������� �� ������ � �� ���������
    {
        Rasp *p = temp->next;
        temp->next = temp->next->next;
        free(p);
    }
    printf("������� ������ � ��������� ������� �����\n");
}


//========================��������� ������========================
void saveRasp(char* filename, Rasp *temp)
{
    FILE *fout = fopen(filename, "w");
    if (!fout)
    {
        printf("���� � ����������� �� ������ :(\n");
        return;
    }
    while (temp)
    {
        fprintf(fout, "%i\n", temp->n);
        fprintf(fout, "%s\n", temp->so);
        fprintf(fout, "%s\n", temp->sp);
//        fwrite(temp->so, sizeof(char), 21, fout);
//        fwrite(temp->sp, sizeof(char), 21, fout);
        fprintf(fout, "%s\n", temp->vo);
        fprintf(fout, "%s\n", temp->vp);
        fprintf(fout, "%i\n", temp->price);
        temp=temp->next;
    }
    printf("������ ������� ���������\n\n");
    fclose(fout);
}


//========================��������� ������========================
void downloadRasp(char* filename, Rasp **head)
{
    FILE *fin = fopen(filename, "r");
    if (!fin)
    {
        printf("���� � ����������� �� ������� �������� :(\n");
        return;
    }

    int nomerPoezda;
    while (fscanf(fin, "%i", &nomerPoezda) == 1)
    {
        char stanciaOtpr[21];
        fscanf(fin, "%s", &stanciaOtpr);

        char stanciaPrib[21];
        fscanf(fin, "%s", &stanciaPrib);

        char timeOtpr[6];
        fscanf(fin, "%s", &timeOtpr);

        char timePrib[6];
        fscanf(fin, "%s", &timePrib);

        int Price;
        fscanf(fin, "%i", &Price);

        Rasp *newE = (Rasp*)malloc(sizeof(Rasp));

        newE->n = nomerPoezda;
        strcpy(newE->so, stanciaOtpr);
        strcpy(newE->sp, stanciaPrib);
        strcpy(newE->vo, timeOtpr);
        strcpy(newE->vp, timePrib);
        newE->price = Price;
        newE->next = NULL;

        if (*head == NULL)
            *head = newE;
        else {
            Rasp *p = *head;
            while (p->next != NULL)
                p = p->next;
            p->next = newE;
        }
    }
    printf("������ ������� ���������\n");
    fclose(fin);
}


//========================��������========================
void goodbye()
{
	printf("================================= \n ");
	printf(" ��������� �������� ���� ������   \n");
	printf("================================= \n");
}