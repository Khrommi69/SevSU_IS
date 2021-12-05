#include <stdio.h>
#include <locale.h>

//��������� �������
void vvodArray(int **A, int n, int m);
void vivodArray(int **A, int n, int m);
void kolvoSum(int **A, int n, int m);
void localMax(int **A, int n, int m);

//�������� ���������
main()
{
    setlocale(LC_ALL, "Rus");
    //���������� ����������
    int num;
    int **A,n,m;

    //����
    printf(" ___________________________________________________      \n");
    printf("/                                                         \n");
    printf("   ��������� �������� � �������� ��������� �����          \n");
    printf("___________________________________________________/    \n\n");
    while (1)
    {
        printf("�������� ���������� ��������: \n");
        printf("1 - ������� ������ \n");
        printf("2 - ���������� ���������� � ����� �������� ������������� ��������� \n");
        printf("3 - ���������� ���������� ��������� ���������� \n");
        printf("4 - ������� ������ �� ����� \n");
        printf("5 - ����� �� ��������� \n");
        printf(" ->  "); scanf("%d",&num); printf("\n");
        switch (num)
        {
            case 1:
            {
                printf("������� ���������� ����� � �������� ������� \n");
                printf("������: "); scanf("%d",&n); printf("�������: "); scanf("%d",&m);
                //��������� ������ ��� ������
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
    printf("������� �������� �������:\n");
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
    printf("������: \n");
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
	printf("���������� �������� ��������� ������� = %d\n",kol);
	printf("���� �������� ������������� ��������� ������� = %d\n\n",sum);
}

//------------------------------------------------------------------------------
void localMax(int **A, int n, int m)
{
	int i,j, kol=0;
	//������ ��������������� ������ ��� ���� ����� �� ���������
	//������ ������� ����� �� ��������, ���� ��� ��������� ��������
	n+=2;
	m+=2;
	//��������� ������
    int **A2 = (int **)malloc(n*sizeof(int *));
    for (i=0; i<n; i++)
        A2[i] = (int *)malloc(m*sizeof(int));
    //���������� ���������������� �������
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
		{
			//���� ��������� �����
			if ((i==0) || (j==0) || (i==(n-1)) || (j==(m-1)))
				A2[i][j] = -9999999999;
			else
				A2[i][j]=A[i-1][j-1];
		}		
	//����� ��������� ����������
	for(i=1; i<(n-1); i++)
		for(j=1; j<(m-1); j++)
		{
			if ((A2[i][j] > A2[i+1][j]) && (A2[i][j] > A2[i-1][j]) && (A2[i][j] > A2[i][j+1]) && (A2[i][j] > A2[i][j-1]))
			{
				printf("������� %d �������� ��������� ����������;\n", (A2[i][j]));
				kol++;
			}
		}	
	printf("� ������� %d ��������� ����������\n\n", kol);
}
