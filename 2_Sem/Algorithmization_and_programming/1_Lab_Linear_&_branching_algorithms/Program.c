#include <stdio.h>
#include <math.h>
#include <locale.h>
main()
//Вычисление Z=f(x)
{
	setlocale(0, "");
	double a,b,x,z;
	//ввод a,b,x
	printf("Введите a: "); scanf("%f",&a);
	printf("Введите b: "); scanf("%f",&b);
	printf("Введите x: "); scanf("%f",&x);
	//Вычисление Z
	if (x<=a)
		z = (log(x-sinh(x)) + acos(5.1*x));
			else if (x<b)
				z = (pow(sin(2.45*x),2) + 3.81*exp(pow(x,2)+x+1));
					else if (x>=b)
						z = ((1+pow(x,2)) / (pow(cosh(pow(x,3)),2) + pow(x,(2*x+9))));
	//Вывод Z
	printf("Z = %e",z);
	return 0;
}
