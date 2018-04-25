#include <iostream>
#include <ctime>
#include "board.h"
#include <random>

thread_local std::mt19937 gen{ std::random_device{}() };

template<typename T>
T random(T min, T max) {
	return std::uniform_int_distribution<T>{min, max}(gen);
}

board::board(int _size, int _mines) : tab_size(_size), mines_number(_mines) {

	if (mines_number >= (tab_size-1) * (tab_size-1))		// max liczba min
		mines_number = (tab_size-1) * (tab_size-1);

	mines_left = mines_number;		// liczba pozosta³ych min

	tab = Matrix<area> (tab_size, tab_size);

	std::cout << "Inicjalizacja tablicy.\n";
	std::cout << "Tab size:\t" << tab_size << "\n";
	std::cout << "Tab width:\t" << tab.width() << "\n";
	std::cout << "Tab height:\t" << tab.height() << "\n";

	int mines_to_place = mines_number;		// losowe podk³adanie min
	int row, col;
	while (mines_to_place > 0) {

		row = random<int>(0, tab_size - 1);
		col = random<int>(0, tab_size - 1);

		if (tab(row, col).place_mine()) {		// jeœli nie ma miny, pod³ó¿ j¹
			mines_to_place--;
			for (int i = 0; i < 3; i++)	// liczenie min w s¹siedzctwie
				if (row - 1 + i >= 0 && row - 1 + i < tab_size && col - 1 + i >= 0 && col - 1 + i < tab_size)
					tab(row - 1 + i, col - 1 + i).add_mines_nearby();
		}
	}
	std::cout << "Usatwienie i zliczenie min.\n";
}

board::~board() {
	/*for (int i = 0; i < tab_size*tab_size; i++)
		delete &(tab(0,i));*/
	std::cout << "Board destroyed!\n";
}

bool board::czy_gramy()
{
	if (mines_left)return true;
	return false;
}

bool board::odkryj()
{
	int wiersz, kolumna;
	std::cout << "Podaj wiersz:\n";
	std::cin >> wiersz;
	std::cout << "Podaj kolumne:\n";
	std::cin >> kolumna;
	if (tab(wiersz - 1, kolumna - 1).check_flag()) return false;
	if (!tab(wiersz-1, kolumna-1).check_area()) {		// <-- tu stawia³eœ minê przy odkrywaniu, check_area() odkrywa pole jeœli nie by³o odkryte

	}
	return true;

}

void board::odkryj_wszystko()
{
	for(int i = 0; i < tab.width(); i++)
		for (int j = 0; j < tab.height(); j++) {
			tab(i, j).check_area();		// najpierw trzeba odkryæ wszystkie
		}								// potem mo¿na wypisaæ wszystko
	std::cout << (*this);

	/*for (int i = 0; i < tab.width() ;i++) {
		for (int j = 0; j < tab.height();j++) {
			tab(i, j).check_area();
		}
	}*/
}

void board::flaga()
{
	int wiersz, kolumna;
	std::cout << "Podaj wiersz:\n";
	std::cin >> wiersz;
	std::cout << "Podaj kolumne:\n";
	std::cin >> kolumna;
	tab(wiersz-1, kolumna-1).change_flag();
}



std::ostream& operator<<(std::ostream& out, board& source) {
	out << "	";
	for (int i = 0; i < source.tab_size; i++)
		out << i + 1 << " ";
	out << "\n";
	for (int i = 0; i < source.tab_size; i++) {
		out << i + 1 << "	";
		for (int j = 0; j < source.tab_size; j++)
			out << source.tab(i, j) << " ";
		out << "\n";
	}
	return out;
}