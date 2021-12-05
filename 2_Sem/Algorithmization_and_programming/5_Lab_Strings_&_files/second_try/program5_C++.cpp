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
	cout << "    Программа копирует текст из одного файла    " << endl;
	cout << "    в другой, при этом в конце каждой           " << endl;
	cout << "    строки дописывая количество открытых        " << endl;
	cout << "    и закрытых скобок в тексте.                 " << endl;
	cout << "______________________________________________/ " << endl << endl;
	
	//открытие файла для чтения
	ifstream fin("text_in.txt", ios::in);
	//если не открылся то ошибка
	if (!fin)
	{
		cout << "Ошибка открытия файла для чтения";
		return 1;
	}
	
	//открыть файл для записи
	ofstream fout("text_out.txt", ios::out);
	if (!fout)
	{
		cout << "Ошибка открытия файла для записи";
		return 1;
	}
	
	//указатель в начало файла
	fin.seekg(0,ios::beg);
	
	//подсчёт количества открытых и закрытых скобок
	kolopen = 0; kolclose = 0;
	while (!fin.eof())
	{
		fin >> ch;
		if ((ch == '(') || (ch == '[') || (ch == '{'))
			kolopen++;
		if ((ch == ')') || (ch == ']') || (ch == '}'))
			kolclose++;
	}
	cout << "В программе " << kolopen << " открытых и " << kolclose << " закрытых скобок" << endl;
	
	fin.close();
	fin.open("text_in.txt");
	
	char s1[1024];
	
	//запись в файл текста с добавлением в конец каждой строки кол-ва открытых и закрытых скобок
	while (!fin.eof())
	{
		fin.getline(s1, 1024);
		fout << s1;
		fout << ' ' << kolopen << ' ' << kolclose << endl;
	}
	
 	fin.close();
 	fout.close();
 	cout << endl << endl << "Программа завершена успешно" << endl << "до свидания";
 	return 0;
}
