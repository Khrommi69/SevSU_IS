#include <iostream>    //?
#include <math.h>
main()
//���������� Z=f(x)
{
	using namespace std;      //?
	float a,b,x,z;
	//���� a,b,x
	cout<<"������� a: "; cin>>a;
	cout<<"������� b: "; cin>>b;
	cout<<"������� x: "; cin>>x;
	//���������� Z
	if (x<=a)
		z = (log(x-sinh(x)) + acos(5.1*x));
			else if (x<b)
				z = (pow(sin(2.45*x),2) + 3.81*exp(pow(x,2)+x+1));
					else if (x>=b)
						z = ((1+pow(x,2)) / (pow(cosh(pow(x,3)),2) + pow(x,(2*x+9))));
	//����� Z
	cout.setf(ios::scientific, ios::floatfield);   //?
 	cout<<"Z = "<<z<<endl;
 	return 0;
}
