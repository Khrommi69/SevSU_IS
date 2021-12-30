#include <stdio.h>
#include <windows.h>

int main(int argc, char const *argv[]) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("Привет\n");

	system("pause");
	return 0;
}