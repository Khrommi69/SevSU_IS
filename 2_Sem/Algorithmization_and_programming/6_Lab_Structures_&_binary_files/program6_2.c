#include <stdio.h>
#include <locale.h>


//��������� � ���������
struct ORDER
{
	char schet_plat[21];     //(���� �����������)
	char schet_poluch[21];   //(���� ����������)
	int sum;                 //(����� �������� (���.))
};


//��������� �������
int create_file();
int vivod_file();
int sort_file();
int vivodSUM();


int main()
{
	setlocale(LC_ALL, "Rus");
	
	printf(" ___________________________________________________    \n");
	printf("/                                                       \n");
	printf("   ��������� �������� �� ���������� ��������� ��        \n");
	printf("   ����� �����������, ���������� � ����� ��������.      \n");
	printf("___________________________________________________/  \n\n");
	
	short num;
    while (1)
    {
        printf("�������� ���������� ��������:                    \n");
        printf("1 - ���� ������                                  \n");
        printf("2 - ����� ������                                 \n");
        printf("3 - ����� ������ � ���������� ����� �����������; \n");
        printf("4 - ����� �� ���������                           \n");
        printf(" ->  "); scanf("%d",&num);               printf("\n");
        switch (num)
        {
        	case 1:
        	{
        		create_file();
        		sort_file();
        		break;
			}
			case 2:
			{
				vivod_file();
				break;
			}
			case 3:
			{
				vivodSUM();
				break;
			}
			case 4:
			{
				return 0;
			}
		}
	}
}


//������ � ����
int create_file()
{
	FILE *fbin;
	fbin = fopen ("ORDER.dat", "wb");
	if (!fbin)
	{
		printf("\n������ �������� �����\n");
		return 1;
	}
	
	struct ORDER elem;
	short i;
	printf("�������������� ���� �����");
	while(1)
	{
		printf("\n���������� ����? (1-��, 2-���): "); scanf("%i", &i);
		if (i==2) 
		{
			printf("\n");
			fclose(fbin);
			return 0;
		}
		printf("======================================\n");
		printf("������� ���� ����������� (20��������) \n");
		scanf("%s", &elem.schet_plat);
		printf("������� ���� ���������� (20��������) \n");
		scanf("%s", &elem.schet_poluch);
		printf("������� ������������� ����� (���.) \n");
		scanf("%d", &elem.sum);
		fwrite(&elem, sizeof(struct ORDER), 1, fbin);
	}
}


int vivod_file()
{
	FILE *fbin = fopen ("ORDER.dat","rb");
	if (!fbin)
	{
		printf("\n������ �������� �����\n");
		return 1;
	}
	
	struct ORDER elem;

	printf("���� �����������         ���� ����������          ����� ��������\n");
	while (fread(&elem, sizeof(struct ORDER), 1, fbin) != NULL)
		printf("%-25s%-25s%i\n", elem.schet_plat, elem.schet_poluch, elem.sum);
	
	printf("\n");
	fclose(fbin);
	return 0;
}


int sort_file()
{
	FILE *fbin = fopen("ORDER.dat", "r+b");
	
	struct ORDER elem1, elem2;
	
	//������ �����;
	fseek(fbin, 0, SEEK_END);
	int lenFILE = ftell(fbin);
	
	int c = lenFILE / sizeof(struct ORDER);
	int i,j;
	for (j = (c-1); j>0; j--)
		for (i=0; i<j; i++)
		{
			fseek (fbin, i*sizeof(struct ORDER), SEEK_SET);
			fread(&elem1, sizeof(struct ORDER), 1, fbin);
			fread(&elem2, sizeof(struct ORDER), 1, fbin);
			if (strcmp(elem1.schet_plat, elem2.schet_plat) > 0)
			{
				fseek (fbin, i*sizeof(struct ORDER), SEEK_SET);
				fwrite(&elem2, sizeof(struct ORDER), 1, fbin);
				fwrite(&elem1, sizeof(struct ORDER), 1, fbin);
			}
		}
	fclose(fbin);
}


int vivodSUM()
{
	FILE *fbin = fopen ("ORDER.dat","rb");
	if (!fbin)
	{
		printf("\n������ �������� �����\n");
		return 1;
	}
	
	struct ORDER elem;
	
	char schet[21];
	printf("������� ��������� ���� �����������, ��� ������ ����� ��� �������:\n");
	scanf("%s",&schet); printf("\n");
	
	while (fread(&elem, sizeof(struct ORDER), 1, fbin) != NULL)
		if (strstr(elem.schet_plat, schet))
		{
			printf("����� = %i\n", elem.sum);
			fclose(fbin);
			return 0;
		}
	printf("������ ����� ����������� �� ������� :( \n\n");
	fclose(fbin);
	return 1;
}
