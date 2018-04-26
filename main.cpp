#include <random>
#include "board.h"
//#include <iostream>
#include <string>
int main() {
	int tab_size;
	std::string choice;
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
		std::cin >> choice;
		if (choice[0] == 'o' || choice[0] == 'O') {
			if (game.uncover()) {
				game.uncover_all();
				system("CLS");
				std::cout << "Przegrales :c\n";
				std::cout << game;
				system("PAUSE");
				break;
			}
		}
		if (choice[0] == 'f' || choice[0] == 'F')game.flag();
		if (choice[0] == 'w' || choice[0] == 'W')break;
		system("CLS");
	}
	if (!game.playing()) {
		game.uncover_all();
		system("CLS");
		std::cout << "Gratulacje, nie przegrales :D\n";
		std::cout << game;
		system("PAUSE");
	}
	return 0;
}