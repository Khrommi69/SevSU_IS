#include <stdio.h>
#include <locale.h>


//константы и структуры
struct ORDER
{
	char schet_plat[21];     //(счет плательщика)
	char schet_poluch[21];   //(счет получателя)
	int sum;                 //(сумма перевода (грн.))
};


//прототипы функций
int create_file();
int vivod_file();
int sort_file();
int vivodSUM();


int main()
{
	setlocale(LC_ALL, "Rus");
	
	printf(" ___________________________________________________    \n");
	printf("/                                                       \n");
	printf("   Программа работает со структурой состоящей из        \n");
	printf("   счёта плательщика, получателя и суммы перевода.      \n");
	printf("___________________________________________________/  \n\n");
	
	short num;
    while (1)
    {
        printf("Выберете дальнейшее действие:                    \n");
        printf("1 - ввод данных                                  \n");
        printf("2 - вывод данных                                 \n");
        printf("3 - сумма снятая с расчетного счёта плательщика; \n");
        printf("4 - выход из программы                           \n");
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


//запись в файл
int create_file()
{
	FILE *fbin;
	fbin = fopen ("ORDER.dat", "wb");
	if (!fbin)
	{
		printf("\nОшибка открытия файла\n");
		return 1;
	}
	
	struct ORDER elem;
	short i;
	printf("Осуществляется ввод даных");
	while(1)
	{
		printf("\nПродолжаем ввод? (1-да, 2-нет): "); scanf("%i", &i);
		if (i==2) 
		{
			printf("\n");
			fclose(fbin);
			return 0;
		}
		printf("======================================\n");
		printf("Введите счёт плательщика (20символов) \n");
		scanf("%s", &elem.schet_plat);
		printf("Введите счёт получателя (20символов) \n");
		scanf("%s", &elem.schet_poluch);
		printf("Введите перечисляемую сумму (грн.) \n");
		scanf("%d", &elem.sum);
		fwrite(&elem, sizeof(struct ORDER), 1, fbin);
	}
}


int vivod_file()
{
	FILE *fbin = fopen ("ORDER.dat","rb");
	if (!fbin)
	{
		printf("\nОшибка открытия файла\n");
		return 1;
	}
	
	struct ORDER elem;

	printf("Счёт плательщика         Счёт получателя          Сумма перевода\n");
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
	
	//размер файла;
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
		printf("\nОшибка открытия файла\n");
		return 1;
	}
	
	struct ORDER elem;
	
	char schet[21];
	printf("Введите расчетный счет плательщика, для вывода суммы его платежа:\n");
	scanf("%s",&schet); printf("\n");
	
	while (fread(&elem, sizeof(struct ORDER), 1, fbin) != NULL)
		if (strstr(elem.schet_plat, schet))
		{
			printf("Сумма = %i\n", elem.sum);
			fclose(fbin);
			return 0;
		}
	printf("Такого счёта плательщика не найдено :( \n\n");
	fclose(fbin);
	return 1;
}
