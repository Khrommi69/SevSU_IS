#include <stdio.h>
#include <locale.h>

int main()
{
	char ch;
	int kolopen,kolclose;
	setlocale(LC_ALL, "Rus");
	
	printf(" _______________________________________________\n");
	printf("/                                                \n");
	printf("    ��������� �������� ����� �� ������ �����      \n");
	printf("    � ������, ��� ���� � ����� ������              \n");
	printf("    ������ ��������� ���������� ��������            \n");
	printf("    � �������� ������ � ������.                      \n");
	printf("______________________________________________/       \n\n");
	
	//�������� ����� ��� ������
	FILE *fin = fopen("text_in.txt","r");
	//���� �� �������� �� ������
	if (!fin)
	{
		fprintf(stderr,"������ �������� ����� ��� ������");
		return 1;
	}
	
	//������� ���� ��� ������
	FILE *fout = fopen("text_out.txt","w");
	if (!fout)
	{
		fprintf(stderr,"������ �������� ����� ��� ������");
		return 1;
	}
	
	//��������� � ������ �����
	rewind(fin);

	//������� ���������� �������� � �������� ������
	kolopen = 0; kolclose = 0;
	while (!feof(fin))
	{
		fscanf(fin, "%c", &ch);
		if ((ch == '(') || (ch == '[') || (ch == '{'))
			kolopen++;
		if ((ch == ')') || (ch == ']') || (ch == '}'))
			kolclose++;
	}
	printf("� ��������� %d �������� � %d �������� ������\n",kolopen,kolclose);
	
	//������� ������ � ����������� �������� � �������� ������
	char *s1 = (char *)malloc((kolclose+kolopen+5)*sizeof(char));
	sprintf(s1, "  %d %d\n", kolopen,kolclose);
	
	rewind(fin);
	//������ � ���� ������ � ����������� � ����� ������ ������ s1
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
 	printf("\n\n��������� ��������� �������\n�� ��������");
 	return 0;
}
