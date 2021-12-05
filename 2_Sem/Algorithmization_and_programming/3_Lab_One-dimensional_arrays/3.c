#include <stdio.h>

//---------------------основна€ программа---------------------
int main()
{
	//объ€вление переменных
	float *a;             //указатель на массив
	unsigned int num;     //дл€ "меню"
	int n;                //кол-во элементов массива
	int i,j,m;            //счЄтчики
	float temp;          //переменна€
	
	//меню
	printf(" ___________________________________________________      \n");
	printf("/                                                         \n");
	printf("  The program works with an array of real numbers         \n");
	printf("___________________________________________________/    \n\n");
	while (1)
	{
		printf("Choose the next action\n");
		printf("1 - creating an array\n");
		printf("2 - move array elements with the value '0' to the beginning of the array\n");
		printf("3 - sort the array in ascending order\n");
		printf("4 - show the array\n");
		printf("5 - delete array\n");
		printf("6 - exit the program\n");
		printf(" -> "); scanf("%d",&num); printf("\n");
		switch (num)
		{
			case 1:
			{
				printf("Input the number of array elements: "); scanf("%i",&n);
				//выделение пам€ти
				a = (float*)malloc(n*sizeof(float));
				printf("Input %i array elements:\n", n);
				for (i=0; i<n; i++)
					scanf("%f", &a[i]);
				printf("\n");
				break;
			}
			case 2:
			{
				j=0;
				for(i=0; i<n; i++)
					if (a[i] == 0)
					{
						temp = a[j];
						a[j] = 0;
						a[i] = temp;
						j++;
					}
				printf("All zeros are sent to the beginning of the array");
				printf("\n\n");
				break;
			} 
			case 3:
			{
				//сортировка методом пр€мого обмена
				for(i = 0; i < n-1; i++)
					for(j = n-1; j > i; j--)
						if(a[j-1] > a[j])
						{
							temp = a[j-1];
							a[j-1] = a[j]; 
							a[j] = temp;
						}
				printf("Sorting was successful");
				printf("\n\n");
				break;
			}
			case 4: 
			{
				printf("Current array:\n");
				for (i=0; i<n; i++)
					printf("%f  ", a[i]);
				printf("\n");
				break;
			}
			case 5: 
			{
				free(a);
				printf("The array was deleted\n");
				printf("\n");
				break;
			}
			case 6: return;
		}
	}
}
