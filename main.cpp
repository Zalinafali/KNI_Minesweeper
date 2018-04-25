#include "board.h"
//#include <iostream>
#include <string>
int main() {
	int tab_size;
	std::string wybor;
	std::cout << "Wielkosc tablicy:";
	std::cin >> tab_size;

	int mines_number;
	std::cout << "Ilosc min:";
	std::cin >> mines_number;

	board game(tab_size, mines_number);
	while (game.czy_gramy()) {
		std::cout << game;
		std::cout << "Co chcesz zrobic?\n";
		std::cin >> wybor;
		if (wybor[0] == 'o' || wybor[0] == 'O') {
			std::cout << "\nwybrales o\n";
			if (game.odkryj()) {
				game.odkryj_wszystko();
				std::cout << game;
				system("PAUSE");
				break;
			}
		}
		if (wybor[0] == 'f' || wybor[0] == 'F') {
			std::cout << "\nwybrales f\n";
			game.flaga();
		}
		if (wybor[0] == 'w' || wybor[0] == 'W') {
			std::cout << "\nwybrales w\n";
			break;
		}
		system("PAUSE");
		system("CLS");
	}
	
	return 0;
}