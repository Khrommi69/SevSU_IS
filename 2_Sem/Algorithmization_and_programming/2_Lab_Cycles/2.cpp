#include <iostream>
#include <math.h>
main()
{
	using namespace std;
	float a,b,xn,xk,x,dx,z;
	int i;
	//��� ������ ���������
		cout << "The program calculates the value of the function z=f(x) in the section from [xn; xk] in increments of dx." << endl << endl;
		cout.width(10);
		cout << char(201) << endl;
		cout.width(10);
		cout << (char)186 << "ln(x-sinhx) + arccos(5.1x),          if x<=a \n";
		cout << " z=f(x)= " << char(185) << "sin^2(2.45x) + 3.81*e^(x^2+x+1),     if a<x<b \n";
		cout.width(10);
		cout << char(186) << "(1+x^2) / (cosh^2(x^3) + x^(2x+9)),  if x>=b \n";
		cout.width(10);
		cout << char(200) << endl << endl;
	//���� �����
		cout << "Input a: ";  cin >> a;
		cout << "Input b: ";  cin >> b;
		cout << "Input xn: "; cin >> xn;
		cout << "Input xk: "; cin >> xk;
		cout << "Input dx: "; cin >> dx;
		cout << "\n";
	//�������� �>b?
	if (a>b)
	{
		cout << "ERROR: A>B"; return 0;
	}
	//����� ������� - 1 ������
		cout << "�";					//printf("%c",218);
		for(i=1;i<=25;i++)  
			cout << "�";				//printf("%c",196);
		cout << "�";					//printf("%c",194);
		for(i=1;i<=25;i++)  
			cout << "�";				//printf("%c",196);
		cout << "�\n";					//printf("%c\n",191);
	//����� ������� - 2 ������
		cout << char(179);
		cout << "            x            "; 
		cout << char(179);
		cout << "         z = f(x)        "; 
		cout << char(179) << endl;
	//����� ������� - 3 ������
		cout << char(195);
		for(i=1;i<=25;i+=1) 
			cout << char(196);
		cout << char(197);
		for(i=1;i<=25;i+=1)  
			cout << char(196);
		cout << char(180) << endl;
	//����� �������� x � z
	x=xn;
	while (x<=xk)
	{
		cout << char(179); 
		cout.width(25);
		cout << x; 
		cout << char(179);
		//���������� Z
		if (x<=a)
			z = (log(x-sinh(x)) + acos(5.1*x));
		else if (x<b)
			z = (pow(sin(2.45*x),2) + 3.81*exp(pow(x,2)+x+1));
		else if (x>=b)
			z = ((1+pow(x,2)) / (pow(cosh(pow(x,3)),2) + pow(x,(2*x+9))));
		//����� Z
		cout.width(25);
		cout << z; 
		cout << char(179) << endl;
		x+=dx;
	}
	//����� �������
		cout << char(192);
		for(i=1;i<=25;i+=1)  
			cout << char(196);
		cout << char(193);
		for(i=1;i<=25;i+=1)  
			cout << char(196);
		cout << char(217) << endl;
	cout << "Enter any key to finish"; cin >> i;
}
