#include <random>
#include "board.h"
//#include <iostream>
#include <string>
int main() {
	int tab_size;
	std::string choise;
	std::cout << "Wielkosc tablicy:";
	std::cin >> tab_size;
	int mines_number;
	std::cout << "Ilosc min:";
	std::cin >> mines_number;
	system("CLS");
	board game(tab_size, mines_number);
	while (game.playing()) {
		std::cout << game;
		std::cout << "Co chcesz zrobic? (o - odkryj, f - flaga, w - wyjdz)\n";
		std::cin >> choise;
		if (choise[0] == 'o' || choise[0] == 'O') {
			if (game.uncover()) {
				game.uncover_all();
				system("CLS");
				std::cout << game;
				system("PAUSE");
				break;
			}
		}
		if (choise[0] == 'f' || choise[0] == 'F')game.flag();
		if (choise[0] == 'w' || choise[0] == 'W')break;
		system("PAUSE");
		system("CLS");
	}
	return 0;
}