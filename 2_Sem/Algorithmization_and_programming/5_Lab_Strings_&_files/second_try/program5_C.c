#include <stdio.h>
#include <locale.h>

int main()
{
	char ch;
	int kolopen,kolclose;
	setlocale(LC_ALL, "Rus");
	
	printf(" _______________________________________________\n");
	printf("/                                                \n");
	printf("    Программа копирует текст из одного файла      \n");
	printf("    в другой, при этом в конце каждой              \n");
	printf("    строки дописывая количество открытых            \n");
	printf("    и закрытых скобок в тексте.                      \n");
	printf("______________________________________________/       \n\n");
	
	//открытие файла для чтения
	FILE *fin = fopen("text_in.txt","r");
	//если не открылся то ошибка
	if (!fin)
	{
		fprintf(stderr,"Ошибка открытия файла для чтения");
		return 1;
	}
	
	//открыть файл для записи
	FILE *fout = fopen("text_out.txt","w");
	if (!fout)
	{
		fprintf(stderr,"Ошибка открытия файла для записи");
		return 1;
	}
	
	//указатель в начало файла
	rewind(fin);

	//подсчёт количества открытых и закрытых скобок
	kolopen = 0; kolclose = 0;
	while (!feof(fin))
	{
		fscanf(fin, "%c", &ch);
		if ((ch == '(') || (ch == '[') || (ch == '{'))
			kolopen++;
		if ((ch == ')') || (ch == ']') || (ch == '}'))
			kolclose++;
	}
	printf("В программе %d открытых и %d закрытых скобок\n",kolopen,kolclose);
	
	//создать строку с количеством открытых и закрытых скобок
	char *s1 = (char *)malloc((kolclose+kolopen+5)*sizeof(char));
	sprintf(s1, "  %d %d\n", kolopen,kolclose);
	
	rewind(fin);
	//запись в файл текста с добавлением в конец каждой строки s1
	while (!feof(fin))
	{
		fscanf(fin, "%c", &ch);
		if (ch == '\n')
			fprintf(fout, "%s", s1);
		else
			fprintf(fout, "%c", ch);
	}
	fprintf(fout, "%s", s1);
	
 	fclose(fin);
 	fclose(fout);
 	printf("\n\nПрограмма завершена успешно\nдо свидания");
 	return 0;
}
