#include <iostream>
#include <windows.h>
#include <cmath>
#include <limits>
#include <fstream>

//ofstream - записать в файл

int main(int argc, char const *argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char ch;
	try {
		char buffer[255]; // для ввода данных пользователем
		std::cout << "File name: ";
		std::cin.getline (buffer, 255);
		std::ofstream fout(buffer); // открыть для записи

		double tC, tF;
		while(1) {
			std::cout << "1 - Преобразовать из температуры в градусах Цельсия в температуру в градусах по Фаренгейту" << std::endl;
			std::cout << "2 - Преобразовать из температуры в градусахпо Фаренгейту в температуру в градусах Цельсия" << std::endl;
			std::cout << " -> ";
			try {
				std::cin >> ch;
				
				if (!std::cin) {
					std::cin.clear();
					throw "Вы ввели чепуху";
				}

				std::cin.ignore(INT_MAX, '\n');

				if ((ch != '1') && (ch != '2')) {
					throw "Вы не ввели 1 или 2";
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
				std::cout << "Введите температуру в градусах Цельсия: ";
				try {
					std::cin >> tC;

					if (!std::cin) {
						std::cin.clear();
						throw "Вы ввели чепуху";
					}

					std::cin.ignore(INT_MAX, '\n');

					tF = 32 + (1.8 * tC);
					std::cout << "Температура в градусах по Фаренгейту = " << tF << std::endl;
					std::cout << std::endl;

					fout.width(13);
					fout.fill('/');
					fout.precision(4);
					fout.setf(std::ios::left | std::ios::fixed);
					fout << tC << " в градусах Цельсия = ";
					fout.width(13);
					fout.fill('/');
					fout.precision(4);
					fout.setf(std::ios::left | std::ios::fixed);
					fout << tF << " в градусах по Фаренгейту;\n";
				}
				catch (const char* str) {
					std::cout << "\aERROR: " << str << std::endl;
				}
				catch (...) {
					std::cout << "\aSOME_ERROR" << std::endl;
				}
			}
			else {
				std::cout << "Введите температуру в градусах по Фаренгейту: ";
				try {
					std::cin >> tF;

					if (!std::cin) {
						std::cin.clear();
						throw "Вы ввели чепуху";
					}

					std::cin.ignore(INT_MAX, '\n');

					tC = tF - 32;
					tC = tC / 1.8;
					std::cout << "Температура в градусах Цельсия = " << tC << std::endl;
					std::cout << std::endl;

					fout.width(13);
					fout.fill('/');
					fout.precision(4);
					fout.setf(std::ios::left | std::ios::fixed);
					fout << tF << " в градусах по Фаренгейту = ";
					fout.width(13);
					fout.fill('/');
					fout.precision(4);
					fout.setf(std::ios::left | std::ios::fixed);
					fout << tC << " в градусах Цельсия;\n";
				}
				catch (const char* str) {
					std::cout << "\aERROR: " << str << std::endl;
				}
				catch (...) {
					std::cout << "\aSOME_ERROR" << std::endl;
				}
			}

			std::cout << "Продолжаем работать с температурой? y/n" << std::endl;
			std::cout << " -> "; 
			std::cin >> ch;
		 	system("cls");
			if(ch == 'n') {
				break;
				fout.close(); // закрыть файл
			}
		}
	}
	catch (...) {
		std::cout << "Ошибка открытия файла!\a";
	}

	float x, y;
	while(1) {
		std::cout << "Вычисляем выражение: y = 10arcsin(10x + 2.2);" << std::endl;
		std::cout << "Введите x, чтобы вычислить y" << std::endl;
		std::cout << "x є [-0.32; -0.12]" << std::endl;
		std::cout << " -> ";
		try {
			std::cin >> x;

			if (!std::cin) {
				std::cin.clear();
				throw "Вы ввели чепуху";
			}

			std::cin.ignore(INT_MAX, '\n');

			if ((x < (-0.32)) || (x > (-0.12))) {
				throw "Число x не пренадлежит диапазону [-0.32; -0.12]";
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
		std::cout << "Продолжаем вычислять y? y/n" << std::endl;
		std::cout << " -> "; 
		std::cin >> ch;
		system("cls");
		if(ch == 'n') {
			break;
		}
	}

	return 0;
}