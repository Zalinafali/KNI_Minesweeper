#include <chrono>
#include "Game.h"

void Game::game_options() {
	int _tab_size = 0;
	do {
		system("CLS");
		std::cout << "Wielkosc tablicy (minimum 2):";
		while (!(std::cin >> _tab_size)) {
			std::cout << "mordo, zjebales" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (_tab_size < 2);
	tab_size = _tab_size;

	int _mines_number = 0;
	do {
		system("CLS");
		std::cout << "Ilosc min (minimum 1):";
		while (!(std::cin >> _mines_number)) {
			std::cout << "mordo, zjebales" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (_mines_number < 1);
	mines_number = _mines_number;
}

void Game::play_game() {
	if (tab_size < 2 || mines_number < 1) {
		std::cout << "Options error!\n";
		return;
	}

	Board game(tab_size, mines_number);
	auto start = std::chrono::system_clock::now();

	char choice;
	while (game.playing()) {
		std::cout << game;
		std::cout << "Co chcesz zrobic? (o - odkryj, f - flaga, w - wyjdz)\n";
		std::cin >> choice;
		if (choice == 'o' || choice == 'O') {
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
		if (choice == 'f' || choice == 'F')game.flag();
		if (choice == 'w' || choice == 'W')break;
		std::cin.clear();
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
}