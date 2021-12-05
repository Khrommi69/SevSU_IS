#include <stdio.h>
#include <math.h>
main()
{
	float a,b,xn,xk,x,dx,z;
	int i;
	//что делает программа
		printf("The program calculates the value of the function z=f(x) in the section from [xn; xk] in increments of dx. \n\n");
		printf("%9c \n", 201);
		printf("%9c", 186); printf("ln(x-sinhx) + arccos(5.1x),          if x<=a \n");
		printf("z=f(x)= "); printf("%c",185); printf("sin^2(2.45x) + 3.81*e^(x^2+x+1),     if a<x<b \n");
		printf("%9c", 186); printf("(1+x^2) / (cosh^2(x^3) + x^(2x+9)),  if x>=b \n");
		printf("%9c \n\n", 200);
	//ввод чисел
		printf("Input a: ");  scanf("%f",&a);
		printf("Input b: ");  scanf("%f",&b);
		printf("Input xn: "); scanf("%f",&xn);
		printf("Input xk: "); scanf("%f",&xk);
		printf("Input dx: "); scanf("%f",&dx);
		printf("\n");
	//проверка а>b?
	if (a>b)
	{
		printf("ERROR: A>B"); return 0;
	}
	//вывод таблицы - 1 строка
		printf("Х");				//printf("%c",218);
		for(i=1;i<=25;i+=1)  
			printf("Н");			//printf("%c",196);
		printf("С");				//printf("%c",194);
		for(i=1;i<=25;i+=1)  
			printf("Н");			//printf("%c",196);
		printf("ё\n");				//printf("%c\n",191);
	//вывод таблицы - 2 строка
		printf("%c", 179);
		printf("            x            "); 
		printf("%c", 179); 
		printf("         z = f(x)        "); 
		printf("%c\n", 179);
	//вывод таблицы - 3 строка
		printf("%c",195);
		for(i=1;i<=25;i+=1) 
			printf("%c",196);
		printf("%c",197);
		for(i=1;i<=25;i+=1)  
			printf("%c",196);
		printf("%c\n",180);
	//вывод значений x и z
	for(x=xn; x<=xk; x+=dx)
	{
		printf("%c", 179); printf("%-25f", x); printf("%c", 179);
		//Вычисление Z
		if (x<=a)
			z = (log(x-sinh(x)) + acos(5.1*x));
				else if (x<b)
					z = (pow(sin(2.45*x),2) + 3.81*exp(pow(x,2)+x+1));
						else if (x>=b)
							z = ((1+pow(x,2)) / (pow(cosh(pow(x,3)),2) + pow(x,(2*x+9))));
		//Вывод Z
		printf("%-25.3f", z); printf("%c\n", 179);
	}
	//конец таблицы
		printf("%c",192);
		for(i=1;i<=25;i+=1)  
			printf("%c",196);
		printf("%c",193);
		for(i=1;i<=25;i+=1)  
			printf("%c",196);
		printf("%c\n",217);
	printf("Enter any key to finish"); scanf("%d",i);
}
