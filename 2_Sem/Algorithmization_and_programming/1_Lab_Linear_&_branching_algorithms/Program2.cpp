#include <iostream>    //?
#include <math.h>
main()
//Вычисление Z=f(x)
{
	using namespace std;      //?
	float a,b,x,z;
	//ввод a,b,x
	cout<<"Введите a: "; cin>>a;
	cout<<"Введите b: "; cin>>b;
	cout<<"Введите x: "; cin>>x;
	//Вычисление Z
	if (x<=a)
		z = (log(x-sinh(x)) + acos(5.1*x));
			else if (x<b)
				z = (pow(sin(2.45*x),2) + 3.81*exp(pow(x,2)+x+1));
					else if (x>=b)
						z = ((1+pow(x,2)) / (pow(cosh(pow(x,3)),2) + pow(x,(2*x+9))));
	//Вывод Z
	cout.setf(ios::scientific, ios::floatfield);   //?
 	cout<<"Z = "<<z<<endl;
 	return 0;
}
