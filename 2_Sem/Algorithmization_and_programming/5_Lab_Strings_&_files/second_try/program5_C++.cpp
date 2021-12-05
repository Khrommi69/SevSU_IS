#include <iostream>
#include <fstream>

int main()
{
	char ch;
	int kolopen,kolclose;
	using namespace std;
	setlocale(LC_ALL, "Rus");
	
	cout << " _______________________________________________" << endl;
	cout << "/                                               " << endl;
	cout << "    ��������� �������� ����� �� ������ �����    " << endl;
	cout << "    � ������, ��� ���� � ����� ������           " << endl;
	cout << "    ������ ��������� ���������� ��������        " << endl;
	cout << "    � �������� ������ � ������.                 " << endl;
	cout << "______________________________________________/ " << endl << endl;
	
	//�������� ����� ��� ������
	ifstream fin("text_in.txt", ios::in);
	//���� �� �������� �� ������
	if (!fin)
	{
		cout << "������ �������� ����� ��� ������";
		return 1;
	}
	
	//������� ���� ��� ������
	ofstream fout("text_out.txt", ios::out);
	if (!fout)
	{
		cout << "������ �������� ����� ��� ������";
		return 1;
	}
	
	//��������� � ������ �����
	fin.seekg(0,ios::beg);
	
	//������� ���������� �������� � �������� ������
	kolopen = 0; kolclose = 0;
	while (!fin.eof())
	{
		fin >> ch;
		if ((ch == '(') || (ch == '[') || (ch == '{'))
			kolopen++;
		if ((ch == ')') || (ch == ']') || (ch == '}'))
			kolclose++;
	}
	cout << "� ��������� " << kolopen << " �������� � " << kolclose << " �������� ������" << endl;
	
	fin.close();
	fin.open("text_in.txt");
	
	char s1[1024];
	
	//������ � ���� ������ � ����������� � ����� ������ ������ ���-�� �������� � �������� ������
	while (!fin.eof())
	{
		fin.getline(s1, 1024);
		fout << s1;
		fout << ' ' << kolopen << ' ' << kolclose << endl;
	}
	
 	fin.close();
 	fout.close();
 	cout << endl << endl << "��������� ��������� �������" << endl << "�� ��������";
 	return 0;
}
