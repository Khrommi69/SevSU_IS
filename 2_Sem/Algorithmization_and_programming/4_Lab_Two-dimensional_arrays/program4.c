#include <stdio.h>
#include <locale.h>

//прототипы функций
void vvodArray(int **A, int n, int m);
void vivodArray(int **A, int n, int m);
void kolvoSum(int **A, int n, int m);
void localMax(int **A, int n, int m);

//основная программа
main()
{
    setlocale(LC_ALL, "Rus");
    //объявление переменных
    int num;
    int **A,n,m;

    //меню
    printf(" ___________________________________________________      \n");
    printf("/                                                         \n");
    printf("   Программа работает с массивом двумерных чисел          \n");
    printf("___________________________________________________/    \n\n");
    while (1)
    {
        printf("Выберете дальнейшее действие: \n");
        printf("1 - создать массив \n");
        printf("2 - подсчитать количество и сумму нечётных отрицательных элементов \n");
        printf("3 - подсчитать количество локальных максимумов \n");
        printf("4 - вывести массив на экран \n");
        printf("5 - выход из программы \n");
        printf(" ->  "); scanf("%d",&num); printf("\n");
        switch (num)
        {
            case 1:
            {
                printf("Введите количество строк и столбцов матрицы \n");
                printf("строки: "); scanf("%d",&n); printf("столбцы: "); scanf("%d",&m);
                //выделение памяти под массив
                A = (int **)malloc(n*sizeof(int *));
                int i;
                for (i=0; i<n; i++)
                    A[i] = (int *)malloc(m*sizeof(int));
                vvodArray(A,n,m);
                break;
            }
			case 2:
			{
				kolvoSum(A,n,m);
				break;
			}
			case 3:
			{
				localMax(A,n,m);
				break;
			}
            case 4:
            {
                vivodArray(A,n,m);
                break;
            }
            case 5:
            {
                int i;
                for(i=0; i<n; i++)
                    free(A[i]);
                free(A);
                return;
            }
        }
    }
}


//------------------------------------------------------------------------------
void vvodArray(int **A, int n, int m)
{
    int i,j;
    printf("Вводите элементы массива:\n");
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
        {
			printf("a[%d;%d] = ",(i+1),(j+1));
            scanf("%d",&A[i][j]);
        }
    printf("\n");
}

//------------------------------------------------------------------------------
void vivodArray(int **A, int n, int m)
{
    int i,j;
    printf("Массив: \n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
            printf("%d\t",A[i][j]);
        printf("\n");
    }
    printf("\n");
}

//------------------------------------------------------------------------------
void kolvoSum(int **A, int n, int m)
{
	int i,j;
	int kol=0,sum=0;
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
			if (((A[i][j]) < 0) && (((A[i][j]) % 2) != 0))
			{
				kol++;
				sum+=(A[i][j]);
			}
	printf("Количество нечётных элементов массива = %d\n",kol);
	printf("Сума нечётных отрицательных элементов массива = %d\n\n",sum);
}

//------------------------------------------------------------------------------
void localMax(int **A, int n, int m)
{
	int i,j, kol=0;
	//создаём вспомогательный массив для того чтобы на граничных
	//точках массива прога не вылетала, если там локальный максимум
	n+=2;
	m+=2;
	//выделение памяти
    int **A2 = (int **)malloc(n*sizeof(int *));
    for (i=0; i<n; i++)
        A2[i] = (int *)malloc(m*sizeof(int));
    //заполнение вспомогательного массива
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
		{
			//если граничная точка
			if ((i==0) || (j==0) || (i==(n-1)) || (j==(m-1)))
				A2[i][j] = -9999999999;
			else
				A2[i][j]=A[i-1][j-1];
		}		
	//поиск локальных максимумов
	for(i=1; i<(n-1); i++)
		for(j=1; j<(m-1); j++)
		{
			if ((A2[i][j] > A2[i+1][j]) && (A2[i][j] > A2[i-1][j]) && (A2[i][j] > A2[i][j+1]) && (A2[i][j] > A2[i][j-1]))
			{
				printf("Элемент %d является локальным максимумом;\n", (A2[i][j]));
				kol++;
			}
		}	
	printf("В матрице %d локальных максимумов\n\n", kol);
}
