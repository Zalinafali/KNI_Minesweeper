#include <string>
#include <chrono>
#include "board.h"

int main() {
	std::string choice;

	int tab_size;
	do {
		system("CLS");
		std::cout << "Wielkosc tablicy (minimum 2):";
		std::cin >> tab_size;
	} while (tab_size < 2);

	int mines_number;
	do {
		system("CLS");
		std::cout << "Ilosc min (minimum 1):";
		std::cin >> mines_number;
	} while (mines_number < 1);

	system("CLS");
	board game(tab_size, mines_number);
	auto start = std::chrono::system_clock::now();

	while (game.playing()) {
		std::cout << game;
		std::cout << "Co chcesz zrobic? (o - odkryj, f - flaga, w - wyjdz)\n";
		std::cin >> choice;
		if (choice[0] == 'o' || choice[0] == 'O') {
			if (game.uncover()) {
				auto end = std::chrono::system_clock::now();
				std::chrono::duration<double> game_time = end - start;

				game.uncover_all();
				system("CLS");
				std::cout << "Przegrales :c\nTwoj czas: " << floor(game_time.count()) 
					<< "s\n\n" << game;
				system("PAUSE");
				break;
			}
		}
		if (choice[0] == 'f' || choice[0] == 'F')game.flag();
		if (choice[0] == 'w' || choice[0] == 'W')break;
		system("CLS");
	}
	if (!game.playing()) {
		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> game_time = end - start;

		game.uncover_all();
		system("CLS");
		std::cout << "Gratulacje, nie przegrales :D\nTwoj czas: "
			<< floor(game_time.count()) << "s\n\n" << game;
		system("PAUSE");
	}
	return 0;
}