#include "board.h"

int main() {
	int tab_size;
	std::cout << "Wielkosc tablicy:";
	std::cin >> tab_size;

	int mines_number;
	std::cout << "Ilosc min:";
	std::cin >> mines_number;

	board game(tab_size, mines_number);
	std::cout << game;

}