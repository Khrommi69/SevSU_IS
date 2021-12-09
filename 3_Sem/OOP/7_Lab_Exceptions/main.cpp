#include <iostream>
#include <windows.h>
#include <cmath>
#include <limits>
#include <fstream>

//ofstream - �������� � ����

int main(int argc, char const *argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char ch;
	try {
		char buffer[255]; // ��� ����� ������ �������������
		std::cout << "File name: ";
		std::cin.getline (buffer, 255);
		std::ofstream fout(buffer); // ������� ��� ������

		double tC, tF;
		while(1) {
			std::cout << "1 - ������������� �� ����������� � �������� ������� � ����������� � �������� �� ����������" << std::endl;
			std::cout << "2 - ������������� �� ����������� � ���������� ���������� � ����������� � �������� �������" << std::endl;
			std::cout << " -> ";
			try {
				std::cin >> ch;
				
				if (!std::cin) {
					std::cin.clear();
					throw "�� ����� ������";
				}

				std::cin.ignore(INT_MAX, '\n');

				if ((ch != '1') && (ch != '2')) {
					throw "�� �� ����� 1 ��� 2";
				}
			}
			catch (const char* str) {
				std::cout << "\aERROR: " << str << std::endl;
				continue;
			}
			catch (...) {
				std::cout << "\aSOME_ERROR" << std::endl;
				continue;
			}

			std::cout << std::endl; 
			if(ch == '1') {
				std::cout << "������� ����������� � �������� �������: ";
				try {
					std::cin >> tC;

					if (!std::cin) {
						std::cin.clear();
						throw "�� ����� ������";
					}

					std::cin.ignore(INT_MAX, '\n');

					tF = 32 + (1.8 * tC);
					std::cout << "����������� � �������� �� ���������� = " << tF << std::endl;
					std::cout << std::endl;

					fout.width(13);
					fout.fill('/');
					fout.precision(4);
					fout.setf(std::ios::left | std::ios::fixed);
					fout << tC << " � �������� ������� = ";
					fout.width(13);
					fout.fill('/');
					fout.precision(4);
					fout.setf(std::ios::left | std::ios::fixed);
					fout << tF << " � �������� �� ����������;\n";
				}
				catch (const char* str) {
					std::cout << "\aERROR: " << str << std::endl;
				}
				catch (...) {
					std::cout << "\aSOME_ERROR" << std::endl;
				}
			}
			else {
				std::cout << "������� ����������� � �������� �� ����������: ";
				try {
					std::cin >> tF;

					if (!std::cin) {
						std::cin.clear();
						throw "�� ����� ������";
					}

					std::cin.ignore(INT_MAX, '\n');

					tC = tF - 32;
					tC = tC / 1.8;
					std::cout << "����������� � �������� ������� = " << tC << std::endl;
					std::cout << std::endl;

					fout.width(13);
					fout.fill('/');
					fout.precision(4);
					fout.setf(std::ios::left | std::ios::fixed);
					fout << tF << " � �������� �� ���������� = ";
					fout.width(13);
					fout.fill('/');
					fout.precision(4);
					fout.setf(std::ios::left | std::ios::fixed);
					fout << tC << " � �������� �������;\n";
				}
				catch (const char* str) {
					std::cout << "\aERROR: " << str << std::endl;
				}
				catch (...) {
					std::cout << "\aSOME_ERROR" << std::endl;
				}
			}

			std::cout << "���������� �������� � ������������? y/n" << std::endl;
			std::cout << " -> "; 
			std::cin >> ch;
		 	system("cls");
			if(ch == 'n') {
				break;
				fout.close(); // ������� ����
			}
		}
	}
	catch (...) {
		std::cout << "������ �������� �����!\a";
	}

	float x, y;
	while(1) {
		std::cout << "��������� ���������: y = 10arcsin(10x + 2.2);" << std::endl;
		std::cout << "������� x, ����� ��������� y" << std::endl;
		std::cout << "x � [-0.32; -0.12]" << std::endl;
		std::cout << " -> ";
		try {
			std::cin >> x;

			if (!std::cin) {
				std::cin.clear();
				throw "�� ����� ������";
			}

			std::cin.ignore(INT_MAX, '\n');

			if ((x < (-0.32)) || (x > (-0.12))) {
				throw "����� x �� ����������� ��������� [-0.32; -0.12]";
			}

			std::cout << std::endl;
			y = (10 * (asin (10*x + 2.2)));
			std::cout << y <<" = 10arcsin(10 * (" << x << ") + 2.2)" << std::endl;
		}
		catch (const char* str) {
			std::cout << "\aERROR: " << str << std::endl;
		}
		catch (...) {
			std::cout << "\aSOME_ERROR" << std::endl;
		}

		std::cout << std::endl;
		std::cout << "���������� ��������� y? y/n" << std::endl;
		std::cout << " -> "; 
		std::cin >> ch;
		system("cls");
		if(ch == 'n') {
			break;
		}
	}

	return 0;
}